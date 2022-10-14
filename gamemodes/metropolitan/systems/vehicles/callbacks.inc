#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    mysql_query_file(SQL_Connection, "tables/"TABLE_USERS_VEHICLES".sql", false);
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnVehicleCreated(vehicleid)
{
    if ( !Iter_Contains(Vehicle, vehicleid) ) {
        Iter_Add(Vehicle, vehicleid);
    }
    TimerUpdateFuel[vehicleid] = SetTimerEx("OnVehicleUpdateFuel", 5000, true, "i", vehicleid);
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnVehicleDestroy(vehicleid)
{
    if ( Iter_Contains(Vehicle, vehicleid)) {
        Iter_Remove(Vehicle, vehicleid);
    }
    KillTimer(TimerUpdateFuel[vehicleid]);
    TimerUpdateFuel[vehicleid] = INVALID_TIMER_ID;
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if ( PRESSED(KEY_YES) && IsPlayerInAnyVehicle(playerid) )
    {
        callcmd::motor(playerid);
        return Y_HOOKS_CONTINUE_RETURN_1;
    }
    else if ( PRESSED(KEY_NO) && IsPlayerInAnyVehicle(playerid) )
    {
        callcmd::farol(playerid);
        return Y_HOOKS_CONTINUE_RETURN_1;
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerStateChange(playerid, newstate, oldstate)
{
    if ( newstate == PLAYER_STATE_DRIVER || newstate == PLAYER_STATE_PASSENGER)
    {
        PlayAudioStreamForPlayer(playerid, "");
        CleanChat(playerid);
        Vehicle:ShowPlayerSpeedometer(playerid);
        return Y_HOOKS_CONTINUE_RETURN_1;
    }
    else if ( newstate == PLAYER_STATE_ONFOOT )
    {
        Vehicle:HidePlayerSpeedometer(playerid);
        return Y_HOOKS_CONTINUE_RETURN_1;
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
    if ( TimerSpeedometer[playerid] ) {
        KillTimer(TimerSpeedometer[playerid]);
        TimerSpeedometer[playerid] = 0;
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

public OnPlayerSave(playerid)
{
    
    if ( PlayerLoadedVehicles[playerid] )
    {
        new count = 0, query[1024 * 2], Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:spawn_a, panels, doors, lights, tires, Float:vHealth;
        
        foreach(new vehicleid: pVehicles[playerid])
        {
            ++count;
            GetVehiclePos(vehicleid, spawn_x, spawn_y, spawn_z);
            GetVehicleZAngle(vehicleid, spawn_a);
            GetVehicleHealth(vehicleid, vHealth);
            GetVehicleDamageStatus(vehicleid, panels, doors, lights, tires);

            mysql_format(SQL_Connection, query, sizeof(query),
                "%sUPDATE "TABLE_USERS_VEHICLES" SET `spawn_x`='%f',`spawn_y`='%f',`spawn_z`='%f',`spawn_a`='%f',`interior`='%d',`world`='%d',`km`='%f',`fuel`='%f',`health`='%f',`damage_panels`='%d',`damage_doors`='%d',`damage_lights`='%d',`damage_tires`='%d' WHERE `id`='%s';",
                query,
                spawn_x, spawn_y, spawn_z, spawn_a,
                GetVehicleInterior(vehicleid),
                GetVehicleVirtualWorld(vehicleid),
                GetDistanceTraveled(vehicleid),
                Vehicle:GetFuel(vehicleid),
                vHealth,
                panels,
                doors,
                lights,
                tires,
                Vehicle[vehicleid][ID]
            );

            Iter_SafeRemove(pVehicles[playerid], vehicleid, vehicleid);
            DestroyVehicle(vehicleid);
        }
        if ( count ) mysql_tquery(SQL_Connection, query);
    }
    PlayerLoadedVehicles[playerid] = false;
    return 1;
}

hook OnPlayerSpawn(playerid)
{
    if ( PlayerLoadedVehicles[playerid] ) return Y_HOOKS_CONTINUE_RETURN_1;
    PlayerLoadedVehicles[playerid] = true;

    new query[255];
    mysql_format(SQL_Connection, query, sizeof(query), "SELECT v.*, u.name as user_name FROM "TABLE_USERS_VEHICLES" as v LEFT JOIN "TABLE_USERS" as u ON u.id = v.user_id WHERE `user_id`='%d';", Player[playerid][ID]);
    mysql_tquery(SQL_Connection, query, "OnPlayerLoadVehicle", "i", playerid);
    return Y_HOOKS_CONTINUE_RETURN_1;
}

public OnVehicleUpdateFuel(vehicleid)
{
    if ( IsValidVehicle(vehicleid) )
    {
        if ( GetVehicleParams(vehicleid, VEHICLE_TYPE_ENGINE) || Vehicle:GetFuel(vehicleid) > 0.0 )
        {
            new speed = GetVehicleSpeed(vehicleid);
            Vehicle:SetFuel(vehicleid, Vehicle:GetFuel(vehicleid) - (0.05 + (speed * 0.00238)) );

            if ( Vehicle:GetFuel(vehicleid) <= 0.0 ) {
                SetVehicleParams(vehicleid, VEHICLE_TYPE_ENGINE, false);
                NT:Send(GetVehicleDriver(vehicleid), NT_TYPE_ERROR, "Veiculo sem combustível.");

            }
        }
        return 1;
    }
    KillTimer(TimerUpdateFuel[vehicleid]);
    TimerUpdateFuel[vehicleid] = INVALID_TIMER_ID;
    return 0;
}

public OnPlayerLoadVehicle(playerid)
{
    new num_rows = cache_num_rows();
    Iter_Init(pVehicles[playerid]);
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
            
            SetVehicleDistanceTravaled(vehicleid, Vehicle[vehicleid][KM]);
            Iter_Add(pVehicles[playerid], vehicleid);
        }
        printf("%s carregou %d veiculos", Player[playerid][Name], Iter_Count(pVehicles[playerid]));
        return 1;
    }
    return 0;
}

public OnSpeedometerUpdate(playerid)
{
    new str[128];
    new vehicleid = GetPlayerVehicleID(playerid), modelid = GetVehicleModel(vehicleid), speed = GetVehicleSpeed(vehicleid), max_speed = GetVehicleMaxSpeed(modelid);

    //
    format(str, sizeof(str), "%03d", speed);
    PlayerTextDrawSetString(playerid, PTD_Speedometer[playerid][3], str);
    
    // 
    PlayerTextDrawTextSize(playerid, PTD_Speedometer[playerid][2], (50.0 / max_speed) * speed, 4.000000);
    PlayerTextDrawShow(playerid, PTD_Speedometer[playerid][2]);

    format(str, sizeof(str), "%07d", floatround(GetDistanceTraveled(vehicleid) / 1000, floatround_floor));
    PlayerTextDrawSetString(playerid, PTD_Speedometer[playerid][12], str);

    PlayerTextDrawTextSize(playerid, PTD_Speedometer[playerid][8], 3.000000,  (-15.0 / Vehicle:GetMaxFuel(modelid) ) * Vehicle:GetFuel(vehicleid));
    PlayerTextDrawShow(playerid, PTD_Speedometer[playerid][8]);
    return 1;
}
