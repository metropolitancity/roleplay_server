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
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerLogged(playerid)
{
    new query[300];
    mysql_format(SQL_Connection,
        query,
        sizeof(query),
        "SELECT v.*, u.name as user_name FROM "TABLE_USERS_VEHICLES" as v LEFT JOIN "TABLE_USERS" as u ON u.id = v.id WHERE `user_id`='%d' AND `in_garage_ds`=0;",
        Player[playerid][ID]
    );
    mysql_tquery(SQL_Connection, query, "OnVehicleLoad", "i", playerid);
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if ( Iter_Count(VehiclesPlayer[playerid]) )
    {
        new reset[E_PLAYER_VEHICLE_DATA], query[512], Float:health, Float:x, Float:y, Float:z, Float:a,
            VEHICLE_TYRE_STATUS:tires, VEHICLE_PANEL_STATUS:panels, VEHICLE_LIGHT_STATUS:lights, VEHICLE_DOOR_STATUS:doors;
        foreach(new vehicleid: VehiclesPlayer[playerid])
        {
            if ( !IsValidVehicle(vehicleid) )continue;

            GetVehicleHealth(vehicleid, health);
            GetVehicleDamageStatus(vehicleid, panels, doors, lights, tires);
            GetVehiclePos(vehicleid, x, y, z);
            GetVehicleZAngle(vehicleid, a);

            mysql_format(SQL_Connection,
                query,
                sizeof(query),
                "UPDATE "TABLE_USERS_VEHICLES" SET `health`='%.3f',`km`='%f',`fuel`='%.3f',`spawn_x`='%.3f',`spawn_y`='%.3f',`spawn_z`='%.3f',`spawn_a`='%.3f',`interior`='%d',`world`='%d',`damage_tires`='%d',`damage_panels`='%d',`damage_lights`='%d',`damage_doors`='%d' WHERE `id`='%s';",
                health,
                GetDistanceTraveled(vehicleid),
                GetVehicleFuel(vehicleid),
                x, y, z, a,
                GetVehicleInterior(vehicleid),
                GetVehicleVirtualWorld(vehicleid),
                tires,
                panels,
                lights,
                doors,
                pVehicle[vehicleid][ID]
            );
            mysql_tquery(SQL_Connection, query, "OnVehicleSave", "i", pVehicle[vehicleid][ID]);

            DestroyVehicle(vehicleid);
            pVehicle[vehicleid] = reset;

            Iter_Remove(pVehicle, vehicleid);
            Iter_Remove(VehiclesPlayer[playerid], vehicleid);
        }
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnVehicleLoad(playerid)
{
    new num_rows = cache_num_rows();
    if ( num_rows )
    {
        Iter_Init(VehiclesPlayer[playerid]);
        for(new i; i < num_rows; i++) {
           CreatePlayerVehicle(playerid, i);
        }
        printf("%s carregou %d veiculos", Player[playerid][Name], Iter_Count(pVehicle));
        return 1;
    }
    return 0;
}

stock CreatePlayerVehicle(playerid, index=0)
{
    new model, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:spawn_a, interiorid, worldid, color1, color2, Float:km, Float:fuel;
    cache_get_value_name_int(index, "model", model);
    cache_get_value_name_float(index, "spawn_x", spawn_x);
    cache_get_value_name_float(index, "spawn_y", spawn_y);
    cache_get_value_name_float(index, "spawn_z", spawn_z);
    cache_get_value_name_float(index, "spawn_a", spawn_a);
    cache_get_value_name_int(index, "interior", interiorid);
    cache_get_value_name_int(index, "world", worldid);
    cache_get_value_name_int(index, "color1", color1);
    cache_get_value_name_int(index, "color2", color2);

    cache_get_value_name_float(index, "fuel", fuel);
    cache_get_value_name_float(index, "km", km);

    // criar veiculo
    new vehicleid = CreateVehicle(model, spawn_x, spawn_y, spawn_z, spawn_a, color1, color2, -1, 0);

    cache_get_value_name(index, "id", pVehicle[vehicleid][ID], 40);
    cache_get_value_name_int(index, "user_id", pVehicle[vehicleid][Owner][ID]);
    cache_get_value_name(index, "user_name", pVehicle[vehicleid][Owner][Name]);

    SetVehicleDistanceTravaled(vehicleid, km);
    SetVehicleFuel(vehicleid, fuel);

    Iter_Add(pVehicle, vehicleid);
    Iter_Add(VehiclesPlayer[playerid], vehicleid);
    return vehicleid;
}

stock GetVehicleDataId(vehicleid, vehicle_data_id[])
{
    if ( !IsValidVehicle(vehicleid) || !Iter_Contains(pVehicle, vehicleid) )return 0;
    format(vehicle_data_id, 40, pVehicle[vehicleid][ID]);
    return 1;
}

stock GetPlayerVehiclesCount(playerid)
{
    new Cache:tmp = MYSQL_INVALID_CACHE;
    if ( cache_is_any_active() )
    {
        tmp = cache_save();
    }
    new query[128];
    mysql_format(SQL_Connection, query, sizeof(query), "SELECT id FROM "TABLE_USERS_VEHICLES" WHERE `user_id`='%d';", Player[playerid][ID]);
    new Cache:c = mysql_query(SQL_Connection, query, true), rows = cache_num_rows();
    cache_delete(c);

    if ( tmp != MYSQL_INVALID_CACHE )
    {
        cache_set_active(tmp);
    }
    return rows;
}