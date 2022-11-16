// ================ DEFINICOES

// ================ VARIAVEIS
static enum E_PLAYER_VEHICLE_OWNER_DATA
{
    ID,
    Name[MAX_PLAYER_NAME]
}

static enum E_PLAYER_VEHICLE_DATA
{
    ID[40],
    Owner[E_PLAYER_VEHICLE_OWNER_DATA],
    Float:SpawnX,
    Float:SpawnY,
    Float:SpawnZ,
    Float:SpawnA,
    Interior,
    World,
}
new pVehicle[MAX_VEHICLES][E_PLAYER_VEHICLE_DATA];

new Iterator:pVehicle<MAX_VEHICLES>, Iterator:VehiclesPlayer[MAX_PLAYERS]<MAX_VEHICLES>;

// ================ HOOKS
#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    mysql_query_file(SQL_Connection, "tables/users_vehicles.sql", false);
    return Y_HOOKS_BREAK_RETURN_0;
}

hook OnPlayerLogged(playerid)
{
    new query[300];
    mysql_format(SQL_Connection,
        query,
        sizeof(query),
        "SELECT v.*, u.name as user_name FROM "TABLE_USERS_VEHICLES" as v LEFT JOIN "TABLE_USERS" as u ON u.id = v.id WHERE `user_id`='%d' AND `in_ds`='0';",
        Player[playerid][ID]
    );
    mysql_tquery(SQL_Connection, query, "OnVehicleLoad", "i", playerid);
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnVehicleLoad(playerid)
{
    new num_rows = cache_num_rows();
    if ( num_rows )
    {
        new model, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:spawn_a, interiorid, worldid, color1, color2, Float:km, Float:fuel;
        for(new i; i < num_rows; i++)
        {
            cache_get_value_name_int(i, "model", model);
            cache_get_value_name_float(i, "spawn_x", spawn_x);
            cache_get_value_name_float(i, "spawn_y", spawn_y);
            cache_get_value_name_float(i, "spawn_z", spawn_z);
            cache_get_value_name_float(i, "spawn_a", spawn_a);
            cache_get_value_name_int(i, "interior", interiorid);
            cache_get_value_name_int(i, "world", worldid);
            cache_get_value_name_int(i, "color1", color1);
            cache_get_value_name_int(i, "color2", color2);

            cache_get_value_name_float(i, "fuel", fuel);
            cache_get_value_name_float(i, "km", km);

            // criar veiculo
            new vehicleid = CreateVehicle(model, spawn_x, spawn_y, spawn_z, spawn_a, color1, color2, -1, 0);

            cache_get_value_name(i, "id", pVehicle[vehicleid][ID]);
            cache_get_value_name_int(i, "user_id", pVehicle[vehicleid][Owner][ID]);
            cache_get_value_name(i, "user_name", pVehicle[vehicleid][Owner][Name]);

            SetVehicleDistanceTravaled(vehicleid, km);
            Iter_Add(pVehicle, vehicleid);
        }
        printf("%s carregou %d veiculos", Player[playerid][Name], Iter_Count(pVehicle));
        return 1;
    }
    return 0;
}