#include <YSI_Coding\y_hooks>

new Text:TD_Logo[4];

hook OnGameModeInit()
{
    TD_Logo[0] = TextDrawCreate(278.160491, 2.166652, "M");
    TextDrawLetterSize(TD_Logo[0], 0.480585, 2.684999);
    TextDrawAlignment(TD_Logo[0], 1);
    TextDrawColor(TD_Logo[0], 1077952767);
    TextDrawSetShadow(TD_Logo[0], 0);
    TextDrawSetOutline(TD_Logo[0], 1);
    TextDrawBackgroundColor(TD_Logo[0], -1378294017);
    TextDrawFont(TD_Logo[0], 2);
    TextDrawSetProportional(TD_Logo[0], 1);
    TextDrawSetShadow(TD_Logo[0], 0);

    TD_Logo[1] = TextDrawCreate(293.853363, 13.016663, "etropolitan");
    TextDrawLetterSize(TD_Logo[1], 0.276779, 1.203333);
    TextDrawAlignment(TD_Logo[1], 1);
    TextDrawColor(TD_Logo[1], -1);
    TextDrawSetShadow(TD_Logo[1], 0);
    TextDrawSetOutline(TD_Logo[1], 1);
    TextDrawBackgroundColor(TD_Logo[1], -1378294017);
    TextDrawFont(TD_Logo[1], 3);
    TextDrawSetProportional(TD_Logo[1], 1);
    TextDrawSetShadow(TD_Logo[1], 0);

    TD_Logo[2] = TextDrawCreate(319.062438, 3.333310, "Roleplay");
    TextDrawLetterSize(TD_Logo[2], 0.250073, 0.818332);
    TextDrawAlignment(TD_Logo[2], 2);
    TextDrawColor(TD_Logo[2], -1);
    TextDrawSetShadow(TD_Logo[2], 1);
    TextDrawSetOutline(TD_Logo[2], 0);
    TextDrawBackgroundColor(TD_Logo[2], 255);
    TextDrawFont(TD_Logo[2], 1);
    TextDrawSetProportional(TD_Logo[2], 1);
    TextDrawSetShadow(TD_Logo[2], 1);

    TD_Logo[3] = TextDrawCreate(318.711669, 25.166648, "]]]");
    TextDrawLetterSize(TD_Logo[3], 0.218213, 1.057500);
    TextDrawAlignment(TD_Logo[3], 2);
    TextDrawColor(TD_Logo[3], 1616929023);
    TextDrawSetShadow(TD_Logo[3], 0);
    TextDrawSetOutline(TD_Logo[3], 0);
    TextDrawBackgroundColor(TD_Logo[3], 255);
    TextDrawFont(TD_Logo[3], 2);
    TextDrawSetProportional(TD_Logo[3], 1);
    TextDrawSetShadow(TD_Logo[3], 0);

    return Y_HOOKS_CONTINUE_RETURN_1;
}

ShowServerLogo(playerid)
{
    TextDrawShowForPlayer(playerid, TD_Logo[0]);
    TextDrawShowForPlayer(playerid, TD_Logo[1]);
    TextDrawShowForPlayer(playerid, TD_Logo[2]);
    TextDrawShowForPlayer(playerid, TD_Logo[3]);
    return 1;
}

HideServerLogo(playerid)
{
    TextDrawHideForPlayer(playerid, TD_Logo[0]);
    TextDrawHideForPlayer(playerid, TD_Logo[1]);
    TextDrawHideForPlayer(playerid, TD_Logo[2]);
    TextDrawHideForPlayer(playerid, TD_Logo[3]);
    return 1;
}