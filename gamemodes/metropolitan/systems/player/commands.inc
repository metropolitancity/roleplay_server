#include <systems/player/commands_admin>


cmd:gps(playerid)
{
    Dialog_Show(playerid, PLAYER_GPS, DIALOG_STYLE_TABLIST, "GPS", "{"COLOR_RED_EMBED"}»{"COLOR_WHITE_EMBED"} Locais Públicos", "Selecionar", "Fechar");
    return 1;
}