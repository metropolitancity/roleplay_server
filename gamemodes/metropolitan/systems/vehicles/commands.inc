cmd:motor(playerid)
{
    if ( !IsPlayerInAnyVehicle(playerid) || GetPlayerState(playerid) != PLAYER_STATE_DRIVER )
    {
        return 0;
    }

    new vehicleid = GetPlayerVehicleID(playerid), engine = GetVehicleParams(vehicleid, VEHICLE_TYPE_ENGINE);
    switch(engine)
    {
        case 0:
        {
            SetVehicleParams(vehicleid, VEHICLE_TYPE_ENGINE, true);
            NT:Send(playerid, NT_TYPE_SUCCESS, "motor ligado.");
            return 1;
        }
        case 1:
        {
            SetVehicleParams(vehicleid, VEHICLE_TYPE_ENGINE, false);
            NT:Send(playerid, NT_TYPE_ERROR, "motor desligado.");
            return 1;
        }
    }
    return 1;
}

cmd:farol(playerid)
{
    if ( !IsPlayerInAnyVehicle(playerid) || GetPlayerState(playerid) != PLAYER_STATE_DRIVER )
    {
        return 0;
    }

    new vehicleid = GetPlayerVehicleID(playerid), lights = GetVehicleParams(vehicleid, VEHICLE_TYPE_LIGHTS);
    switch(lights)
    {
        case 0:
        {
            SetVehicleParams(vehicleid, VEHICLE_TYPE_LIGHTS, true);
            NT:Send(playerid, NT_TYPE_SUCCESS, "luzes ligada.");
            return 1;
        }
        case 1:
        {
            SetVehicleParams(vehicleid, VEHICLE_TYPE_LIGHTS, false);
            NT:Send(playerid, NT_TYPE_ERROR, "luzes desligada.");
            return 1;
        }
    }
    return 1;
}