enum E_VEHICLE_OWNER_DATA
{
    ID,
    Name[MAX_PLAYER_NAME]
}

enum E_VEHICLE_DATA
{
    ID[MAX_UUID_LEN],
    Owner[E_VEHICLE_OWNER_DATA],
    Float:Fuel
}
new Vehicle[MAX_VEHICLES][E_VEHICLE_DATA];


#include <systems/vehicles/functions>
#include <systems/vehicles/callbacks>
#include <systems/vehicles/dialogs>
#include <systems/vehicles/commands>