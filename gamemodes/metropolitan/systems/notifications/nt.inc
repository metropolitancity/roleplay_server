#define MAX_PLAYER_NOTIFICATION     4

enum E_NT_DATA
{
    bool:Showed,
    Float:TD_Value,
    Timer
}
new Notification[MAX_PLAYERS][MAX_PLAYER_NOTIFICATION][E_NT_DATA];

new const Float:NotificationPosition[MAX_PLAYER_NOTIFICATION][] =
{
    {10.000000, 280.000000},
    {10.000000, 230.000000},
    {10.000000, 180.000000},
    {10.000000, 130.000000}
};
new PlayerText:PTD_Notification[MAX_PLAYERS][MAX_PLAYER_NOTIFICATION][4];

// forward
forward NT:Destroy(playerid, nt_id);

// arquivos do sistema
#include <systems/notifications/functions>
#include <systems/notifications/callbacks>