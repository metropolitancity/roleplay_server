#include <a_samp>
#include <omp>
#include <a_mysql>
#include <bcrypt>
#include <sampvoice>
#include <Pawn.CMD>
#include <sscanf2>
#include <YSI_Coding\y_va>
#include <YSI_Data\y_iterate>
#include <easyDialog>
#include <vSync>


main()
{
    print("[MP:RP] Servidor iniciado com sucesso!");
    return 1;
}

public OnGameModeInit()
{
    print("[MP:RP] Iniciando sistemas do servidor...\n");
    return 1;
}

// core
#include <core/def>
#include <core/database>
#include <core/config>
#include <core/colors>
#include <core/function>
#include <core/command_perfomed>

// voice
#include <voice/voice>


// systems
#include <systems/player/player>
#include <systems/notifications/nt>
