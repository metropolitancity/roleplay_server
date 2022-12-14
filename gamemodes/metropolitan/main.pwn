#include <open.mp>
#include <a_mysql>
#include <bcrypt>
#include <sampvoice>
#include <Pawn.CMD>
#include <sscanf2>
#include <streamer>
#include <discord-connector>
#include <YSI_Coding\y_va>
#include <YSI_Data\y_iterate>
#include <easyDialog>
#include <vSync>
#include <traveled>
#include <strlib>
//#include <cef>

main()
{
    bcrypt_set_thread_limit(2);
    print("[MP:RP] Servidor iniciado com sucesso!");
    return 1;
}
 
// core
#include <core/fixers>
#include <core/def>
#include <core/database>
#include <core/config>
#include <core/colors>
#include <core/function>
#include <core/command_perfomed>
#include <core/dynamic_time>
#include <core/vehicles>


// voice
#include <voice/voice>

// Sistemas
#include <headers/player>
#include <headers/property>

// systems
#include <logo/logo>
#include <player/player>
#include <notifications/nt>
#include <discord/discord>
#include <fss/fss>
#include <property/property>
