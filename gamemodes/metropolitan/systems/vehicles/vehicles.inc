// forwards
forward OnPlayerLoadVehicle(playerid);
forward OnSpeedometerUpdate(playerid);

enum E_VEHICLE_OWNER_DATA
{
    ID,
    Name[MAX_PLAYER_NAME]
}

enum E_VEHICLE_DATA
{
    ID[MAX_UUID_LEN],
    Owner[E_VEHICLE_OWNER_DATA],
    Float:Fuel,
    Float:KM
}
new Vehicle[MAX_VEHICLES][E_VEHICLE_DATA], Iterator:pVehicles[MAX_PLAYERS]<MAX_VEHICLES>;

new bool:PlayerLoadedVehicles[MAX_PLAYERS], TimerSpeedometer[MAX_PLAYERS];

// textdraws
new PlayerText:PTD_Speedometer[MAX_PLAYERS][16];

#include <systems/vehicles/functions>
#include <systems/vehicles/callbacks>
#include <systems/vehicles/dialogs>
#include <systems/vehicles/commands>