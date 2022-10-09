#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    mysql_query_file(SQL_Connection, "tables/"TABLE_USERS_VEHICLES".sql", false);
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if ( PRESSED(KEY_NO) && IsPlayerInAnyVehicle(playerid) )
    {
        Dialog_Show(playerid, PANEL_VEHICLE, DIALOG_STYLE_LIST, "PAINEL DO VEICULO", "Motor\nFárol", "Selecionar", "Fechar");
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerConnect(playerid)
{
    PlayerLoadedVehicles[playerid] = false;
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    PlayerLoadedVehicles[playerid] = false;
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerSpawn(playerid)
{
    if ( PlayerLoadedVehicles[playerid] )return Y_HOOKS_CONTINUE_RETURN_1;
    PlayerLoadedVehicles[playerid] = true;

    new query[255];
    mysql_format(SQL_Connection, query, sizeof(query), "SELECT v.*, u.name as user_name FROM "TABLE_USERS_VEHICLES" as v LEFT JOIN "TABLE_USERS" as u ON u.id = v.user_id WHERE `user_id`='%d';", Player[playerid][ID]);
    mysql_tquery(SQL_Connection, query, "OnPlayerLoadVehicle", "i", playerid);
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerStateChange(playerid, newstate, oldstate)
{
    if ( newstate == PLAYER_STATE_DRIVER )
    {
        new vehicleid = GetPlayerVehicleID(playerid);
        NT:Send(playerid, NT_TYPE_INFO, "Esse veiculo pertence a %s", Vehicle[vehicleid][Owner][Name]);
        return Y_HOOKS_CONTINUE_RETURN_1;
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

public OnPlayerLoadVehicle(playerid)
{
    new num_rows = cache_num_rows();
    if ( num_rows )
    {
        new model, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:spawn_a, interiorid, worldid, color1, color2;
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

            // criar veiculo
            new vehicleid = CreateVehicle(model, spawn_x, spawn_y, spawn_z, spawn_a, color1, color2, -1, 0);

            cache_get_value_name(i, "id", Vehicle[vehicleid][ID]);
            cache_get_value_name_int(i, "user_id", Vehicle[vehicleid][Owner][ID]);
            cache_get_value_name(i, "user_name", Vehicle[vehicleid][Owner][Name]);
            cache_get_value_name_float(i, "fuel", Vehicle[vehicleid][Fuel]);
            cache_get_value_name_float(i, "km", Vehicle[vehicleid][KM]);
        }
        return 1;
    }
    return 0;
}