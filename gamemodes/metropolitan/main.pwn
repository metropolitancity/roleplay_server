#include <a_samp>
#include <omp>
#include <a_mysql>
#include <bcrypt>
#include <sampvoice>
#include <Pawn.CMD>
#include <sscanf2>
#include <discord-connector>
#include <YSI_Coding\y_va>
#include <YSI_Data\y_iterate>
#include <easyDialog>
#include <vSync>
#include <traveled>
#include <strlib>

main()
{
    print("[MP:RP] Servidor iniciado com sucesso!");
    return 1;
}

public OnPlayerConnect(playerid)
{
    RemoveBuildingForPlayer(playerid, 5043, 1843.3672, -1856.3203, 13.8750, 0.25);
    RemoveBuildingForPlayer(playerid, 5340, 2644.8594, -2039.2344, 14.0391, 0.25);
    RemoveBuildingForPlayer(playerid, 5422, 2071.4766, -1831.4219, 14.5625, 0.25);
    RemoveBuildingForPlayer(playerid, 5856, 1024.9844, -1029.3516, 33.1953, 0.25);
    RemoveBuildingForPlayer(playerid, 5779, 1041.3516, -1025.9297, 32.6719, 0.25);
    RemoveBuildingForPlayer(playerid, 6400, 488.2813, -1734.6953, 12.3906, 0.25);
    return 1;
}

public OnGameModeInit()
{
    print("[MP:RP] Iniciando sistemas do servidor...\n");
    CreateObject(3037, 2071.50684, -1830.89465, 14.70334,   0.00000, 0.00000, 0.00000);
    CreateObject(3037, 2643.77441, -2039.66772, 13.78058,   0.00000, 0.00000, 89.78100);
    CreateObject(3037, 1027.07141, -1029.33240, 33.08183,   0.00000, 0.00000, 90.11984);
    CreateObject(3037, 1043.37390, -1025.85596, 32.59005,   0.00000, 0.00000, 90.24004);
    CreateObject(3037, 488.16010, -1734.92285, 13.42850,   90.00000, 0.00000, 81.48000);
    CreateObject(3037, 1843.32043, -1853.94971, 13.28123,   0.00000, 0.00000, 0.00000);
    return 1;
}

// core
#include <core/def>
#include <core/fixers>
#include <core/database>
#include <core/config>
#include <core/colors>
#include <core/function>
#include <core/command_perfomed>
#include <core/dynamic_time>

// voice
#include <voice/voice>


// Sistemas
#include <headers/player>

//
#include <systems/player/player>
#include <systems/vehicles/vehicles>
#include <systems/notifications/nt>
//#include <systems/discord/discord>
#include <systems/fss/fss>