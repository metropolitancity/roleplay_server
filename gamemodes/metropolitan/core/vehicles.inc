// ============================== [ ENUM / VAR ] ==============================

static enum E_VEHICLE_DATA
{
    bool:StartingEngine,
    Float:Fuel
}
new Vehicle[MAX_VEHICLES][E_VEHICLE_DATA];

// ============================== [ FUNCTIONS ] ==============================
SetVehicleFuel(vehicleid, Float:fuel)
{
    if ( !IsValidVehicle(vehicleid) ) return 0;
    Vehicle[vehicleid][Fuel] = fuel;
    return 1;
}

stock Float:GetVehicleFuel(vehicleid){
    if ( !IsValidVehicle(vehicleid) )return 0.0;
    return Vehicle[vehicleid][Fuel];
}

// ============================== [ CALLBACKS ] ==============================
#include <YSI_Coding\y_hooks>

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if ( IsPlayerInAnyVehicle(playerid) )
    {
        new vehicleid = GetPlayerVehicleID(playerid);
        if ( PRESSED(KEY_YES) )
        {
            if ( !Vehicle[vehicleid][StartingEngine] && !GetVehicleParams(vehicleid, VEHICLE_TYPE_ENGINE))
            {
                new Float:health;
                GetVehicleHealth(vehicleid, health);

                if ( health <= 300 ){
                    NT:Send(playerid, NT_TYPE_ERROR, "Veiculo danificado.");
                    return Y_HOOKS_CONTINUE_RETURN_1;
                }

                Vehicle[vehicleid][StartingEngine] = true;
                SetTimerEx("OnVehicleStaringEngine", 2000, false, "i", vehicleid);
            }else{
                SetVehicleParams(vehicleid, VEHICLE_TYPE_ENGINE, false);
            }
        }
        else if ( PRESSED(KEY_NO) ){
            SetVehicleParams(vehicleid, VEHICLE_TYPE_LIGHTS, !GetVehicleParams(vehicleid, VEHICLE_TYPE_LIGHTS));
        }
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

forward OnVehicleStaringEngine(vehicleid);
public OnVehicleStaringEngine(vehicleid)
{
    if ( !IsValidVehicle(vehicleid) )return 0;
    Vehicle[vehicleid][StartingEngine] = false;
    SetVehicleParams(vehicleid, VEHICLE_TYPE_ENGINE, true);   
    return 1;
}