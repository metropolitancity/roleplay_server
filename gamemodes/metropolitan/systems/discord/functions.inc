stock DC:ShowIntegration(playerid)
{
    if ( GetPVarInt(playerid, "DC:ShowIntegration") )return 0;
    SetPVarInt(playerid, "DC:ShowIntegration", 1);

    PTD_DiscordIntegration[playerid][0] = CreatePlayerTextDraw(playerid, 228.455337, 175.999969, "LD_SPAC:white");
    PlayerTextDrawLetterSize(playerid, PTD_DiscordIntegration[playerid][0], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PTD_DiscordIntegration[playerid][0], 172.000000, 60.000000);
    PlayerTextDrawAlignment(playerid, PTD_DiscordIntegration[playerid][0], 1);
    PlayerTextDrawColor(playerid, PTD_DiscordIntegration[playerid][0], 303174399);
    PlayerTextDrawSetShadow(playerid, PTD_DiscordIntegration[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, PTD_DiscordIntegration[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_DiscordIntegration[playerid][0], 255);
    PlayerTextDrawFont(playerid, PTD_DiscordIntegration[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, PTD_DiscordIntegration[playerid][0], 0);
    PlayerTextDrawSetShadow(playerid, PTD_DiscordIntegration[playerid][0], 0);

    PTD_DiscordIntegration[playerid][1] = CreatePlayerTextDraw(playerid, 284.846282, 177.817047, "Integração Discord");
    PlayerTextDrawLetterSize(playerid, PTD_DiscordIntegration[playerid][1], 0.235080, 0.894166);
    PlayerTextDrawAlignment(playerid, PTD_DiscordIntegration[playerid][1], 2);
    PlayerTextDrawColor(playerid, PTD_DiscordIntegration[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, PTD_DiscordIntegration[playerid][1], 1);
    PlayerTextDrawSetOutline(playerid, PTD_DiscordIntegration[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_DiscordIntegration[playerid][1], 255);
    PlayerTextDrawFont(playerid, PTD_DiscordIntegration[playerid][1], 2);
    PlayerTextDrawSetProportional(playerid, PTD_DiscordIntegration[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, PTD_DiscordIntegration[playerid][1], 1);

    PTD_DiscordIntegration[playerid][2] = CreatePlayerTextDraw(playerid, 251.962280, 201.733474, "LD_SPAC:white");
    PlayerTextDrawLetterSize(playerid, PTD_DiscordIntegration[playerid][2], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PTD_DiscordIntegration[playerid][2], 124.000000, 15.000000);
    PlayerTextDrawAlignment(playerid, PTD_DiscordIntegration[playerid][2], 1);
    PlayerTextDrawColor(playerid, PTD_DiscordIntegration[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, PTD_DiscordIntegration[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, PTD_DiscordIntegration[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_DiscordIntegration[playerid][2], 255);
    PlayerTextDrawFont(playerid, PTD_DiscordIntegration[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, PTD_DiscordIntegration[playerid][2], 0);
    PlayerTextDrawSetShadow(playerid, PTD_DiscordIntegration[playerid][2], 0);

    PTD_DiscordIntegration[playerid][3] = CreatePlayerTextDraw(playerid, 252.362304, 202.033493, "LD_SPAC:white");
    PlayerTextDrawLetterSize(playerid, PTD_DiscordIntegration[playerid][3], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PTD_DiscordIntegration[playerid][3], 123.300079, 14.300001);
    PlayerTextDrawAlignment(playerid, PTD_DiscordIntegration[playerid][3], 1);
    PlayerTextDrawColor(playerid, PTD_DiscordIntegration[playerid][3], 303174399);
    PlayerTextDrawSetShadow(playerid, PTD_DiscordIntegration[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, PTD_DiscordIntegration[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_DiscordIntegration[playerid][3], 255);
    PlayerTextDrawFont(playerid, PTD_DiscordIntegration[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, PTD_DiscordIntegration[playerid][3], 0);
    PlayerTextDrawSetShadow(playerid, PTD_DiscordIntegration[playerid][3], 0);
    PlayerTextDrawSetSelectable(playerid, PTD_DiscordIntegration[playerid][3], false);

    PTD_DiscordIntegration[playerid][4] = CreatePlayerTextDraw(playerid, 258.352722, 195.466690, "Discord ID");
    PlayerTextDrawLetterSize(playerid, PTD_DiscordIntegration[playerid][4], 0.302547, 0.917500);
    PlayerTextDrawTextSize(playerid, PTD_DiscordIntegration[playerid][4], 308.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, PTD_DiscordIntegration[playerid][4], 1);
    PlayerTextDrawColor(playerid, PTD_DiscordIntegration[playerid][4], -1);
    PlayerTextDrawUseBox(playerid, PTD_DiscordIntegration[playerid][4], 1);
    PlayerTextDrawBoxColor(playerid, PTD_DiscordIntegration[playerid][4], 303174399);
    PlayerTextDrawSetShadow(playerid, PTD_DiscordIntegration[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, PTD_DiscordIntegration[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_DiscordIntegration[playerid][4], 255);
    PlayerTextDrawFont(playerid, PTD_DiscordIntegration[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, PTD_DiscordIntegration[playerid][4], 1);
    PlayerTextDrawSetShadow(playerid, PTD_DiscordIntegration[playerid][4], 0);

    PTD_DiscordIntegration[playerid][5] = CreatePlayerTextDraw(playerid, 313.978179, 205.449935, "...");
    PlayerTextDrawLetterSize(playerid, PTD_DiscordIntegration[playerid][5], 0.215402, 0.911666);
    PlayerTextDrawTextSize(playerid, PTD_DiscordIntegration[playerid][5], 10.000000, 116.000000);
    PlayerTextDrawAlignment(playerid, PTD_DiscordIntegration[playerid][5], 2);
    PlayerTextDrawColor(playerid, PTD_DiscordIntegration[playerid][5], -1);
    PlayerTextDrawUseBox(playerid, PTD_DiscordIntegration[playerid][5], 1);
    PlayerTextDrawBoxColor(playerid, PTD_DiscordIntegration[playerid][5], 0);
    PlayerTextDrawSetShadow(playerid, PTD_DiscordIntegration[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, PTD_DiscordIntegration[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_DiscordIntegration[playerid][5], 255);
    PlayerTextDrawFont(playerid, PTD_DiscordIntegration[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, PTD_DiscordIntegration[playerid][5], 1);
    PlayerTextDrawSetShadow(playerid, PTD_DiscordIntegration[playerid][5], 0);
    PlayerTextDrawSetSelectable(playerid, PTD_DiscordIntegration[playerid][5], true);

    PTD_DiscordIntegration[playerid][6] = CreatePlayerTextDraw(playerid, 347.159851, 224.999893, "Confirmar");
    PlayerTextDrawLetterSize(playerid, PTD_DiscordIntegration[playerid][6], 0.318008, 0.969999);
    PlayerTextDrawTextSize(playerid, PTD_DiscordIntegration[playerid][6], 397.000000, 10.000000);
    PlayerTextDrawAlignment(playerid, PTD_DiscordIntegration[playerid][6], 1);
    PlayerTextDrawColor(playerid, PTD_DiscordIntegration[playerid][6], -1);
    PlayerTextDrawUseBox(playerid, PTD_DiscordIntegration[playerid][6], 1);
    PlayerTextDrawBoxColor(playerid, PTD_DiscordIntegration[playerid][6], 0);
    PlayerTextDrawSetShadow(playerid, PTD_DiscordIntegration[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, PTD_DiscordIntegration[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_DiscordIntegration[playerid][6], 255);
    PlayerTextDrawFont(playerid, PTD_DiscordIntegration[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, PTD_DiscordIntegration[playerid][6], 1);
    PlayerTextDrawSetShadow(playerid, PTD_DiscordIntegration[playerid][6], 0);
    PlayerTextDrawSetSelectable(playerid, PTD_DiscordIntegration[playerid][6], true);
    
    for(new i; i < sizeof(PTD_DiscordIntegration[]); i++) {
        if ( IsValidPlayerTextDraw(playerid, PTD_DiscordIntegration[playerid][i]) ) {
            PlayerTextDrawShow(playerid, PTD_DiscordIntegration[playerid][i]);
        }
    }
    SelectTextDraw(playerid, COLOR_ORANGE);

    return 1;
}

stock DC:HideIntegration(playerid)
{
    if ( !GetPVarInt(playerid, "DC:ShowIntegration") )return 0;
    DeletePVar(playerid, "DC:ShowIntegration");

    for(new i; i < sizeof(PTD_DiscordIntegration[]); i++) {
        if ( IsValidPlayerTextDraw(playerid, PTD_DiscordIntegration[playerid][i]) ) {
            PlayerTextDrawDestroy(playerid, PTD_DiscordIntegration[playerid][i]);
            PTD_DiscordIntegration[playerid][i] = INVALID_PLAYER_TEXT_DRAW;
        }
    }
    return 1;
}