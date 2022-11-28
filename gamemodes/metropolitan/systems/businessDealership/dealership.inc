#define MAX_VEHICLES_PER_PAGE       10
#define INVALID_DEALERSHIP_ID       -1

enum
{
    BDS_TYPE_LUXURIOUS,
    BDS_TYPE_POPULAR,
    BDS_TYPE_OLD
}

enum E_BDS_VEHICLES_INFO
{
    ID[40],
    Model,
    Price,
    Color1,
    Color2
}

enum E_BDS_OWNER
{
    ID,
    Name[MAX_PLAYER_NAME]
}

enum E_BUSINESS_DEALERSHIP
{
    ID,
    Name[32],
    Owner[E_BDS_OWNER],
    Price,
    Float:X,
    Float:Y,
    Float:Z,
    Float:vSpawnX,
    Float:vSpawnY,
    Float:vSpawnZ,
    Float:vSpawnA,
    Pickup[2],
    Text3D:Label[2],
    MapIcon,
}
new BusinessDealership[MAX_BUSINESS_DEALERSHIPS][E_BUSINESS_DEALERSHIP], Iterator:BusinessDealership<MAX_BUSINESS_DEALERSHIPS>;

new Iterator:BDS_VehiclesPage[MAX_PLAYERS]<MAX_VEHICLES_PER_PAGE>,
    BDS_VehiclesInf[MAX_PLAYERS][MAX_VEHICLES_PER_PAGE][E_BDS_VEHICLES_INFO],
    DS:SELECTED_SLOT[MAX_PLAYERS] = { -1, ... },
    DS:SELECTED_VEHICLE[MAX_PLAYERS] = { INVALID_VEHICLE_ID, ... }
;

new PlayerText:PTD_Dealership[MAX_PLAYERS][13] = { INVALID_PLAYER_TEXT_DRAW, ...},
    PlayerText:PTD_DealershipVehicles[MAX_PLAYERS][MAX_VEHICLES_PER_PAGE][2]
;

// ================ includes
#include "businessDealership/callbacks"
#include "businessDealership/functions"
#include "businessDealership/commands"
#include "businessDealership/dialogs"