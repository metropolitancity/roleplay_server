#define MAX_PROPERTY        (20)
enum E_PROPERTY_DATA
{
    ID,
    Name[32],
    Float:EntranceX,
    Float:EntranceY,
    Float:EntranceZ,
    Float:EntranceA,
    Float:ExitX,
    Float:ExitY,
    Float:ExitZ,
    Float:ExitA,
    Interior,
    MapIcon
}
new Property[MAX_PROPERTY][E_PROPERTY_DATA], Iterator:Property<MAX_PROPERTY>;

#include <systems/property/callbacks>
#include <systems/property/functions>