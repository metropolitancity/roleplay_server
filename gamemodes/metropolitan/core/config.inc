#include <YSI_Coding\y_hooks>

#define SERVER_NAME     "Metropolitan Roleplay"
#define SERVER_STAGE    "[ALPHA]"
#define SERVER_VERSION  "v1.0.0"


hook OnGameModeInit()
{
    print("Configurando informações do servidor...");
    SendRconCommandf("hostname %s %s", SERVER_NAME, SERVER_STAGE);
    SendRconCommandf("language Português Brasil");
    SendRconCommandf("gamemodetext Roleplay | %s", SERVER_VERSION);
    ManualVehicleEngineAndLights();
    DisableInteriorEnterExits();
    UsePlayerPedAnims();
    print(" ");
    return Y_HOOKS_CONTINUE_RETURN_1;
}