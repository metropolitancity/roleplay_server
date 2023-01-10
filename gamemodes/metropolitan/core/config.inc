#include <YSI_Coding\y_hooks>

#define SERVER_NAME     "Metropolitan Roleplay"
#define SERVER_SITE     "https://metropolitanrolelplay.com"
#define SERVER_STAGE    "[ALPHA]"
#define SERVER_VERSION  "v1.0.0"
#define SERVER_MESSAGE_TAG          "[MP{FFFFFF}:{00BBFF}RP]"

hook OnGameModeInit()
{
    print("Configurando informações do servidor...");
    SendRconCommand("hostname %s %s", SERVER_NAME, SERVER_STAGE);
    SendRconCommand("language Português Brasil");
    SendRconCommand("gamemodetext RP %s", SERVER_VERSION);
    ManualVehicleEngineAndLights();
    DisableInteriorEnterExits();
    UsePlayerPedAnims();
    ShowPlayerMarkers(PLAYER_MARKERS_MODE_OFF);
    ShowNameTags(false);
    print(" ");
    return Y_HOOKS_CONTINUE_RETURN_1;
}