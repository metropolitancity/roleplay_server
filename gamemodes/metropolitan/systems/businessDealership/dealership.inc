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
    Pickup,
    Text3D:Label,
    MapIcon,
}
new BusinessDealership[MAX_BUSINESS_DEALERSHIPS][E_BUSINESS_DEALERSHIP], Iterator:BusinessDealership<MAX_BUSINESS_DEALERSHIPS>;


// ================ includes
#include "systems/businessDealership/callbacks"