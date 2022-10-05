stock Player:ShowRegister(playerid)
{
    if ( GetPVarInt(playerid, "Player_ShowRegister") )return 0;
    
    SetPVarInt(playerid, "Player_ShowRegister", 1);

    PTD_Register[playerid][0] = CreatePlayerTextDraw(playerid, -1.000000, -1.000000, "box");
    PlayerTextDrawLetterSize(playerid, PTD_Register[playerid][0], 0.000000, 50.948745);
    PlayerTextDrawTextSize(playerid, PTD_Register[playerid][0], 650.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, PTD_Register[playerid][0], 1);
    PlayerTextDrawColor(playerid, PTD_Register[playerid][0], 0x121212FF);
    PlayerTextDrawUseBox(playerid, PTD_Register[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, PTD_Register[playerid][0], 0x121212FF);
    PlayerTextDrawSetShadow(playerid, PTD_Register[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Register[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Register[playerid][0], 255);
    PlayerTextDrawFont(playerid, PTD_Register[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, PTD_Register[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Register[playerid][0], 0);

    PTD_Register[playerid][1] = CreatePlayerTextDraw(playerid, 233.777435, 86.166656, "box");
    PlayerTextDrawLetterSize(playerid, PTD_Register[playerid][1], 0.000000, 28.975105);
    PlayerTextDrawTextSize(playerid, PTD_Register[playerid][1], 395.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, PTD_Register[playerid][1], 1);
    PlayerTextDrawColor(playerid, PTD_Register[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, PTD_Register[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, PTD_Register[playerid][1], -156);
    PlayerTextDrawSetShadow(playerid, PTD_Register[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Register[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Register[playerid][1], 255);
    PlayerTextDrawFont(playerid, PTD_Register[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, PTD_Register[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Register[playerid][1], 0);

    PTD_Register[playerid][2] = CreatePlayerTextDraw(playerid, 233.977447, 86.666648, "box");
    PlayerTextDrawLetterSize(playerid, PTD_Register[playerid][2], 0.000000, 28.895118);
    PlayerTextDrawTextSize(playerid, PTD_Register[playerid][2], 394.890014, 0.000000);
    PlayerTextDrawAlignment(playerid, PTD_Register[playerid][2], 1);
    PlayerTextDrawColor(playerid, PTD_Register[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, PTD_Register[playerid][2], 1);
    PlayerTextDrawBoxColor(playerid, PTD_Register[playerid][2], 0x161616FF);
    PlayerTextDrawSetShadow(playerid, PTD_Register[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Register[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Register[playerid][2], 255);
    PlayerTextDrawFont(playerid, PTD_Register[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, PTD_Register[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Register[playerid][2], 0);

    PTD_Register[playerid][3] = CreatePlayerTextDraw(playerid, 270.322113, 93.166648, "M");
    PlayerTextDrawLetterSize(playerid, PTD_Register[playerid][3], 1.014698, 6.354166);
    PlayerTextDrawAlignment(playerid, PTD_Register[playerid][3], 1);
    PlayerTextDrawColor(playerid, PTD_Register[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, PTD_Register[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Register[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Register[playerid][3], 255);
    PlayerTextDrawFont(playerid, PTD_Register[playerid][3], 2);
    PlayerTextDrawSetProportional(playerid, PTD_Register[playerid][3], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Register[playerid][3], 0);

    PTD_Register[playerid][4] = CreatePlayerTextDraw(playerid, 299.370422, 131.716781, "etroplitan");
    PlayerTextDrawLetterSize(playerid, PTD_Register[playerid][4], 0.259911, 1.319998);
    PlayerTextDrawAlignment(playerid, PTD_Register[playerid][4], 1);
    PlayerTextDrawColor(playerid, PTD_Register[playerid][4], 1077952767);
    PlayerTextDrawSetShadow(playerid, PTD_Register[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Register[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Register[playerid][4], 255);
    PlayerTextDrawFont(playerid, PTD_Register[playerid][4], 2);
    PlayerTextDrawSetProportional(playerid, PTD_Register[playerid][4], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Register[playerid][4], 0);

    PTD_Register[playerid][5] = CreatePlayerTextDraw(playerid, 364.644653, 118.649932, "City");
    PlayerTextDrawLetterSize(playerid, PTD_Register[playerid][5], 0.400000, 1.600000);
    PlayerTextDrawAlignment(playerid, PTD_Register[playerid][5], 3);
    PlayerTextDrawColor(playerid, PTD_Register[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, PTD_Register[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Register[playerid][5], 1);
    PlayerTextDrawBackgroundColor(playerid, PTD_Register[playerid][5], 255);
    PlayerTextDrawFont(playerid, PTD_Register[playerid][5], 2);
    PlayerTextDrawSetProportional(playerid, PTD_Register[playerid][5], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Register[playerid][5], 0);

    PTD_Register[playerid][6] = CreatePlayerTextDraw(playerid, 271.559326, 145.683120, "LD_SPAC:white");
    PlayerTextDrawLetterSize(playerid, PTD_Register[playerid][6], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PTD_Register[playerid][6], 92.199935, 12.900012);
    PlayerTextDrawAlignment(playerid, PTD_Register[playerid][6], 1);
    PlayerTextDrawColor(playerid, PTD_Register[playerid][6], 14548991);
    PlayerTextDrawSetShadow(playerid, PTD_Register[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Register[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Register[playerid][6], 255);
    PlayerTextDrawFont(playerid, PTD_Register[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, PTD_Register[playerid][6], 0);
    PlayerTextDrawSetShadow(playerid, PTD_Register[playerid][6], 0);

    PTD_Register[playerid][7] = CreatePlayerTextDraw(playerid, 287.043457, 147.149749, "roleplay");
    PlayerTextDrawLetterSize(playerid, PTD_Register[playerid][7], 0.286000, 1.000000);
    PlayerTextDrawAlignment(playerid, PTD_Register[playerid][7], 1);
    PlayerTextDrawColor(playerid, PTD_Register[playerid][7], 303174399);
    PlayerTextDrawSetShadow(playerid, PTD_Register[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Register[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Register[playerid][7], 255);
    PlayerTextDrawFont(playerid, PTD_Register[playerid][7], 2);
    PlayerTextDrawSetProportional(playerid, PTD_Register[playerid][7], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Register[playerid][7], 0);

    PTD_Register[playerid][8] = CreatePlayerTextDraw(playerid, 241.488510, 180.416839, "usuario");
    PlayerTextDrawLetterSize(playerid, PTD_Register[playerid][8], 0.193042, 0.929166);
    PlayerTextDrawAlignment(playerid, PTD_Register[playerid][8], 1);
    PlayerTextDrawColor(playerid, PTD_Register[playerid][8], 1077952767);
    PlayerTextDrawSetShadow(playerid, PTD_Register[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Register[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Register[playerid][8], 255);
    PlayerTextDrawFont(playerid, PTD_Register[playerid][8], 2);
    PlayerTextDrawSetProportional(playerid, PTD_Register[playerid][8], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Register[playerid][8], 0);

    PTD_Register[playerid][9] = CreatePlayerTextDraw(playerid, 241.610961, 189.483337, "LD_SPAC:white");
    PlayerTextDrawLetterSize(playerid, PTD_Register[playerid][9], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PTD_Register[playerid][9], 143.750167, 12.900003);
    PlayerTextDrawAlignment(playerid, PTD_Register[playerid][9], 1);
    PlayerTextDrawColor(playerid, PTD_Register[playerid][9], 538976511);
    PlayerTextDrawSetShadow(playerid, PTD_Register[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Register[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Register[playerid][9], 255);
    PlayerTextDrawFont(playerid, PTD_Register[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, PTD_Register[playerid][9], 0);
    PlayerTextDrawSetShadow(playerid, PTD_Register[playerid][9], 0);

    PTD_Register[playerid][10] = CreatePlayerTextDraw(playerid, 312.983673, 190.700042, Player[playerid][Name]);
    PlayerTextDrawLetterSize(playerid, PTD_Register[playerid][10], 0.164801, 0.993332);
    PlayerTextDrawTextSize(playerid, PTD_Register[playerid][10], 10.000000, 141.000000);
    PlayerTextDrawAlignment(playerid, PTD_Register[playerid][10], 2);
    PlayerTextDrawColor(playerid, PTD_Register[playerid][10], 1347440895);
    PlayerTextDrawUseBox(playerid, PTD_Register[playerid][10], 1);
    PlayerTextDrawBoxColor(playerid, PTD_Register[playerid][10], 0);
    PlayerTextDrawSetShadow(playerid, PTD_Register[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Register[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Register[playerid][10], 255);
    PlayerTextDrawFont(playerid, PTD_Register[playerid][10], 2);
    PlayerTextDrawSetProportional(playerid, PTD_Register[playerid][10], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Register[playerid][10], 0);
    PlayerTextDrawSetSelectable(playerid, PTD_Register[playerid][10], false);

    PTD_Register[playerid][11] = CreatePlayerTextDraw(playerid, 241.488510, 208.616989, "email");
    PlayerTextDrawLetterSize(playerid, PTD_Register[playerid][11], 0.193042, 0.929166);
    PlayerTextDrawAlignment(playerid, PTD_Register[playerid][11], 1);
    PlayerTextDrawColor(playerid, PTD_Register[playerid][11], 1077952767);
    PlayerTextDrawSetShadow(playerid, PTD_Register[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Register[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Register[playerid][11], 255);
    PlayerTextDrawFont(playerid, PTD_Register[playerid][11], 2);
    PlayerTextDrawSetProportional(playerid, PTD_Register[playerid][11], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Register[playerid][11], 0);

    PTD_Register[playerid][12] = CreatePlayerTextDraw(playerid, 241.610961, 217.434265, "LD_SPAC:white");
    PlayerTextDrawLetterSize(playerid, PTD_Register[playerid][12], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PTD_Register[playerid][12], 143.750167, 12.900003);
    PlayerTextDrawAlignment(playerid, PTD_Register[playerid][12], 1);
    PlayerTextDrawColor(playerid, PTD_Register[playerid][12], 538976511);
    PlayerTextDrawSetShadow(playerid, PTD_Register[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Register[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Register[playerid][12], 255);
    PlayerTextDrawFont(playerid, PTD_Register[playerid][12], 4);
    PlayerTextDrawSetProportional(playerid, PTD_Register[playerid][12], 0);
    PlayerTextDrawSetShadow(playerid, PTD_Register[playerid][12], 0);

    PTD_Register[playerid][13] = CreatePlayerTextDraw(playerid, 313.452209, 218.900360, "digite seu email");
    PlayerTextDrawLetterSize(playerid, PTD_Register[playerid][13], 0.164801, 0.993332);
    PlayerTextDrawTextSize(playerid, PTD_Register[playerid][13], 10.000000, 141.000000);
    PlayerTextDrawAlignment(playerid, PTD_Register[playerid][13], 2);
    PlayerTextDrawColor(playerid, PTD_Register[playerid][13], 1347440895);
    PlayerTextDrawUseBox(playerid, PTD_Register[playerid][13], 1);
    PlayerTextDrawBoxColor(playerid, PTD_Register[playerid][13], 0);
    PlayerTextDrawSetShadow(playerid, PTD_Register[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Register[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Register[playerid][13], 255);
    PlayerTextDrawFont(playerid, PTD_Register[playerid][13], 2);
    PlayerTextDrawSetProportional(playerid, PTD_Register[playerid][13], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Register[playerid][13], 0);
    PlayerTextDrawSetSelectable(playerid, PTD_Register[playerid][13], true);

    PTD_Register[playerid][14] = CreatePlayerTextDraw(playerid, 241.488510, 236.217605, "senha");
    PlayerTextDrawLetterSize(playerid, PTD_Register[playerid][14], 0.193042, 0.929166);
    PlayerTextDrawAlignment(playerid, PTD_Register[playerid][14], 1);
    PlayerTextDrawColor(playerid, PTD_Register[playerid][14], 1077952767);
    PlayerTextDrawSetShadow(playerid, PTD_Register[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Register[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Register[playerid][14], 255);
    PlayerTextDrawFont(playerid, PTD_Register[playerid][14], 2);
    PlayerTextDrawSetProportional(playerid, PTD_Register[playerid][14], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Register[playerid][14], 0);

    PTD_Register[playerid][15] = CreatePlayerTextDraw(playerid, 241.610961, 245.233978, "LD_SPAC:white");
    PlayerTextDrawLetterSize(playerid, PTD_Register[playerid][15], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PTD_Register[playerid][15], 143.750167, 12.900003);
    PlayerTextDrawAlignment(playerid, PTD_Register[playerid][15], 1);
    PlayerTextDrawColor(playerid, PTD_Register[playerid][15], 538976511);
    PlayerTextDrawSetShadow(playerid, PTD_Register[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Register[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Register[playerid][15], 255);
    PlayerTextDrawFont(playerid, PTD_Register[playerid][15], 4);
    PlayerTextDrawSetProportional(playerid, PTD_Register[playerid][15], 0);
    PlayerTextDrawSetShadow(playerid, PTD_Register[playerid][15], 0);

    PTD_Register[playerid][16] = CreatePlayerTextDraw(playerid, 313.452209, 246.700378, "digite uma senha");
    PlayerTextDrawLetterSize(playerid, PTD_Register[playerid][16], 0.164801, 0.993332);
    PlayerTextDrawTextSize(playerid, PTD_Register[playerid][16], 10.000000, 141.000000);
    PlayerTextDrawAlignment(playerid, PTD_Register[playerid][16], 2);
    PlayerTextDrawColor(playerid, PTD_Register[playerid][16], 1347440895);
    PlayerTextDrawUseBox(playerid, PTD_Register[playerid][16], 1);
    PlayerTextDrawBoxColor(playerid, PTD_Register[playerid][16], 0);
    PlayerTextDrawSetShadow(playerid, PTD_Register[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Register[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Register[playerid][16], 255);
    PlayerTextDrawFont(playerid, PTD_Register[playerid][16], 2);
    PlayerTextDrawSetProportional(playerid, PTD_Register[playerid][16], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Register[playerid][16], 0);
    PlayerTextDrawSetSelectable(playerid, PTD_Register[playerid][16], true);

    PTD_Register[playerid][17] = CreatePlayerTextDraw(playerid, 241.573913, 283.049621, "LD_SPAC:white");
    PlayerTextDrawLetterSize(playerid, PTD_Register[playerid][17], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PTD_Register[playerid][17], 143.710708, 18.630014);
    PlayerTextDrawAlignment(playerid, PTD_Register[playerid][17], 1);
    PlayerTextDrawColor(playerid, PTD_Register[playerid][17], 14548991);
    PlayerTextDrawSetShadow(playerid, PTD_Register[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Register[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Register[playerid][17], 255);
    PlayerTextDrawFont(playerid, PTD_Register[playerid][17], 4);
    PlayerTextDrawSetProportional(playerid, PTD_Register[playerid][17], 0);
    PlayerTextDrawSetShadow(playerid, PTD_Register[playerid][17], 0);

    PTD_Register[playerid][18] = CreatePlayerTextDraw(playerid, 243.347793, 303.849517, "box");
    PlayerTextDrawLetterSize(playerid, PTD_Register[playerid][18], 0.000000, -1.573006);
    PlayerTextDrawTextSize(playerid, PTD_Register[playerid][18], 383.288604, 0.000000);
    PlayerTextDrawAlignment(playerid, PTD_Register[playerid][18], 1);
    PlayerTextDrawColor(playerid, PTD_Register[playerid][18], -1);
    PlayerTextDrawUseBox(playerid, PTD_Register[playerid][18], 1);
    PlayerTextDrawBoxColor(playerid, PTD_Register[playerid][18], 150);
    PlayerTextDrawSetShadow(playerid, PTD_Register[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Register[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Register[playerid][18], 255);
    PlayerTextDrawFont(playerid, PTD_Register[playerid][18], 1);
    PlayerTextDrawSetProportional(playerid, PTD_Register[playerid][18], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Register[playerid][18], 0);

    PTD_Register[playerid][19] = CreatePlayerTextDraw(playerid, 243.347793, 303.849517, "box");
    PlayerTextDrawLetterSize(playerid, PTD_Register[playerid][19], 0.000000, -2.583019);
    PlayerTextDrawTextSize(playerid, PTD_Register[playerid][19], 383.288604, 0.000000);
    PlayerTextDrawAlignment(playerid, PTD_Register[playerid][19], 1);
    PlayerTextDrawColor(playerid, PTD_Register[playerid][19], -1);
    PlayerTextDrawUseBox(playerid, PTD_Register[playerid][19], 1);
    PlayerTextDrawBoxColor(playerid, PTD_Register[playerid][19], 150);
    PlayerTextDrawSetShadow(playerid, PTD_Register[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Register[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Register[playerid][19], 255);
    PlayerTextDrawFont(playerid, PTD_Register[playerid][19], 1);
    PlayerTextDrawSetProportional(playerid, PTD_Register[playerid][19], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Register[playerid][19], 0);

    PTD_Register[playerid][20] = CreatePlayerTextDraw(playerid, 314.063201, 285.383422, "REGISTRAR");
    PlayerTextDrawLetterSize(playerid, PTD_Register[playerid][20], 0.333000, 1.200000);
    PlayerTextDrawTextSize(playerid, PTD_Register[playerid][20], 10.000000,  140.00000);
    PlayerTextDrawAlignment(playerid, PTD_Register[playerid][20], 2);
    PlayerTextDrawColor(playerid, PTD_Register[playerid][20], -1);
    PlayerTextDrawUseBox(playerid, PTD_Register[playerid][20], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Register[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Register[playerid][20], 255);
    PlayerTextDrawFont(playerid, PTD_Register[playerid][20], 2);
    PlayerTextDrawSetProportional(playerid, PTD_Register[playerid][20], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Register[playerid][20], 1);
    PlayerTextDrawSetSelectable(playerid, PTD_Register[playerid][20], true);

    PTD_Register[playerid][21] = CreatePlayerTextDraw(playerid, 396.066589, 84.483451, SERVER_VERSION);
    PlayerTextDrawLetterSize(playerid, PTD_Register[playerid][21], 0.161054, 1.016666);
    PlayerTextDrawAlignment(playerid, PTD_Register[playerid][21], 3);
    PlayerTextDrawColor(playerid, PTD_Register[playerid][21], 1077952767);
    PlayerTextDrawSetOutline(playerid, PTD_Register[playerid][21], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Register[playerid][21], 255);
    PlayerTextDrawFont(playerid, PTD_Register[playerid][21], 1);
    PlayerTextDrawSetProportional(playerid, PTD_Register[playerid][21], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Register[playerid][21], 0);

    for(new i; i < sizeof(PTD_Register[]); i++) {
        PlayerTextDrawShow(playerid, PTD_Register[playerid][i]);
    }
    return 1;
}

stock Player:HideRegister(playerid)
{
    if ( !GetPVarInt(playerid, "Player_ShowRegister") )return 0;
    DeletePVar(playerid, "Player_ShowRegister");

    for(new i; i < sizeof(PTD_Register[]); i++){
        if ( IsValidPlayerTextDraw(playerid, PTD_Register[playerid][i]) ){
            PlayerTextDrawDestroy(playerid, PTD_Register[playerid][i]);
            PTD_Register[playerid][i] = INVALID_PLAYER_TEXT_DRAW;
        }
    }
    return 1;
}

stock Player:ShowLogin(playerid)
{
    if ( GetPVarInt(playerid, "Player_ShowPlayerLogin") )return 0;
    SetPVarInt(playerid, "Player_ShowPlayerLogin", 1);
    PTD_Login[playerid][0] = CreatePlayerTextDraw(playerid, -1.000000, -1.000000, "box");
    PlayerTextDrawLetterSize(playerid, PTD_Login[playerid][0], 0.000000, 50.948745);
    PlayerTextDrawTextSize(playerid, PTD_Login[playerid][0], 650.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, PTD_Login[playerid][0], 1);
    PlayerTextDrawColor(playerid, PTD_Login[playerid][0], 0x121212FF);
    PlayerTextDrawUseBox(playerid, PTD_Login[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, PTD_Login[playerid][0], 0x121212FF);
    PlayerTextDrawSetShadow(playerid, PTD_Login[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Login[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Login[playerid][0], 255);
    PlayerTextDrawFont(playerid, PTD_Login[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, PTD_Login[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Login[playerid][0], 0);

    PTD_Login[playerid][1] = CreatePlayerTextDraw(playerid, 233.777435, 86.166656, "box");
    PlayerTextDrawLetterSize(playerid, PTD_Login[playerid][1], 0.000000, 28.900000);
    PlayerTextDrawTextSize(playerid, PTD_Login[playerid][1], 395.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, PTD_Login[playerid][1], 1);
    PlayerTextDrawColor(playerid, PTD_Login[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, PTD_Login[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, PTD_Login[playerid][1], -156);
    PlayerTextDrawSetShadow(playerid, PTD_Login[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Login[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Login[playerid][1], 255);
    PlayerTextDrawFont(playerid, PTD_Login[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, PTD_Login[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Login[playerid][1], 0);

    PTD_Login[playerid][2] = CreatePlayerTextDraw(playerid, 233.977447, 86.666648, "box");
    PlayerTextDrawLetterSize(playerid, PTD_Login[playerid][2], 0.000000, 28.700000);
    PlayerTextDrawTextSize(playerid, PTD_Login[playerid][2], 394.890014, 0.000000);
    PlayerTextDrawAlignment(playerid, PTD_Login[playerid][2], 1);
    PlayerTextDrawColor(playerid, PTD_Login[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, PTD_Login[playerid][2], 1);
    PlayerTextDrawBoxColor(playerid, PTD_Login[playerid][2], 303174399);
    PlayerTextDrawSetShadow(playerid, PTD_Login[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Login[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Login[playerid][2], 255);
    PlayerTextDrawFont(playerid, PTD_Login[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, PTD_Login[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Login[playerid][2], 0);

    PTD_Login[playerid][3] = CreatePlayerTextDraw(playerid, 270.322113, 93.166648, "M");
    PlayerTextDrawLetterSize(playerid, PTD_Login[playerid][3], 1.014698, 6.354166);
    PlayerTextDrawAlignment(playerid, PTD_Login[playerid][3], 1);
    PlayerTextDrawColor(playerid, PTD_Login[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, PTD_Login[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Login[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Login[playerid][3], 255);
    PlayerTextDrawFont(playerid, PTD_Login[playerid][3], 2);
    PlayerTextDrawSetProportional(playerid, PTD_Login[playerid][3], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Login[playerid][3], 0);

    PTD_Login[playerid][4] = CreatePlayerTextDraw(playerid, 299.370422, 131.716781, "etroplitan");
    PlayerTextDrawLetterSize(playerid, PTD_Login[playerid][4], 0.259911, 1.319998);
    PlayerTextDrawAlignment(playerid, PTD_Login[playerid][4], 1);
    PlayerTextDrawColor(playerid, PTD_Login[playerid][4], 1077952767);
    PlayerTextDrawSetShadow(playerid, PTD_Login[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Login[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Login[playerid][4], 255);
    PlayerTextDrawFont(playerid, PTD_Login[playerid][4], 2);
    PlayerTextDrawSetProportional(playerid, PTD_Login[playerid][4], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Login[playerid][4], 0);

    PTD_Login[playerid][5] = CreatePlayerTextDraw(playerid, 364.644653, 118.649932, "City");
    PlayerTextDrawLetterSize(playerid, PTD_Login[playerid][5], 0.400000, 1.600000);
    PlayerTextDrawAlignment(playerid, PTD_Login[playerid][5], 3);
    PlayerTextDrawColor(playerid, PTD_Login[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, PTD_Login[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Login[playerid][5], 1);
    PlayerTextDrawBackgroundColor(playerid, PTD_Login[playerid][5], 255);
    PlayerTextDrawFont(playerid, PTD_Login[playerid][5], 2);
    PlayerTextDrawSetProportional(playerid, PTD_Login[playerid][5], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Login[playerid][5], 0);

    PTD_Login[playerid][6] = CreatePlayerTextDraw(playerid, 271.559326, 145.683120, "LD_SPAC:white");
    PlayerTextDrawLetterSize(playerid, PTD_Login[playerid][6], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PTD_Login[playerid][6], 92.199935, 12.900012);
    PlayerTextDrawAlignment(playerid, PTD_Login[playerid][6], 1);
    PlayerTextDrawColor(playerid, PTD_Login[playerid][6], 14548991);
    PlayerTextDrawSetShadow(playerid, PTD_Login[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Login[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Login[playerid][6], 255);
    PlayerTextDrawFont(playerid, PTD_Login[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, PTD_Login[playerid][6], 0);
    PlayerTextDrawSetShadow(playerid, PTD_Login[playerid][6], 0);

    PTD_Login[playerid][7] = CreatePlayerTextDraw(playerid, 287.043457, 147.149749, "roleplay");
    PlayerTextDrawLetterSize(playerid, PTD_Login[playerid][7], 0.286000, 1.000000);
    PlayerTextDrawAlignment(playerid, PTD_Login[playerid][7], 1);
    PlayerTextDrawColor(playerid, PTD_Login[playerid][7], 303174399);
    PlayerTextDrawSetShadow(playerid, PTD_Login[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Login[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Login[playerid][7], 255);
    PlayerTextDrawFont(playerid, PTD_Login[playerid][7], 2);
    PlayerTextDrawSetProportional(playerid, PTD_Login[playerid][7], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Login[playerid][7], 0);

    PTD_Login[playerid][8] = CreatePlayerTextDraw(playerid, 241.488510, 180.416839, "usuario");
    PlayerTextDrawLetterSize(playerid, PTD_Login[playerid][8], 0.193039, 0.929166);
    PlayerTextDrawAlignment(playerid, PTD_Login[playerid][8], 1);
    PlayerTextDrawColor(playerid, PTD_Login[playerid][8], 1077952767);
    PlayerTextDrawSetShadow(playerid, PTD_Login[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Login[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Login[playerid][8], 255);
    PlayerTextDrawFont(playerid, PTD_Login[playerid][8], 2);
    PlayerTextDrawSetProportional(playerid, PTD_Login[playerid][8], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Login[playerid][8], 0);

    PTD_Login[playerid][9] = CreatePlayerTextDraw(playerid, 241.610961, 189.483337, "LD_SPAC:white");
    PlayerTextDrawLetterSize(playerid, PTD_Login[playerid][9], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PTD_Login[playerid][9], 143.750167, 12.900003);
    PlayerTextDrawAlignment(playerid, PTD_Login[playerid][9], 1);
    PlayerTextDrawColor(playerid, PTD_Login[playerid][9], 538976511);
    PlayerTextDrawSetShadow(playerid, PTD_Login[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Login[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Login[playerid][9], 255);
    PlayerTextDrawFont(playerid, PTD_Login[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, PTD_Login[playerid][9], 0);
    PlayerTextDrawSetShadow(playerid, PTD_Login[playerid][9], 0);

    PTD_Login[playerid][10] = CreatePlayerTextDraw(playerid, 312.983673, 190.700042, Player[playerid][Name]);
    PlayerTextDrawLetterSize(playerid, PTD_Login[playerid][10], 0.164801, 0.993332);
    PlayerTextDrawTextSize(playerid, PTD_Login[playerid][10], 0.000000, 141.000000);
    PlayerTextDrawAlignment(playerid, PTD_Login[playerid][10], 2);
    PlayerTextDrawColor(playerid, PTD_Login[playerid][10], 1347440895);
    PlayerTextDrawUseBox(playerid, PTD_Login[playerid][10], 1);
    PlayerTextDrawBoxColor(playerid, PTD_Login[playerid][10], 0);
    PlayerTextDrawSetShadow(playerid, PTD_Login[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Login[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Login[playerid][10], 255);
    PlayerTextDrawFont(playerid, PTD_Login[playerid][10], 2);
    PlayerTextDrawSetProportional(playerid, PTD_Login[playerid][10], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Login[playerid][10], 0);
    PlayerTextDrawSetSelectable(playerid, PTD_Login[playerid][10], false);

    PTD_Login[playerid][11] = CreatePlayerTextDraw(playerid, 241.488510, 209.817504, "senha");
    PlayerTextDrawLetterSize(playerid, PTD_Login[playerid][11], 0.193039, 0.929166);
    PlayerTextDrawAlignment(playerid, PTD_Login[playerid][11], 1);
    PlayerTextDrawColor(playerid, PTD_Login[playerid][11], 1077952767);
    PlayerTextDrawSetShadow(playerid, PTD_Login[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Login[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Login[playerid][11], 255);
    PlayerTextDrawFont(playerid, PTD_Login[playerid][11], 2);
    PlayerTextDrawSetProportional(playerid, PTD_Login[playerid][11], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Login[playerid][11], 0);

    PTD_Login[playerid][12] = CreatePlayerTextDraw(playerid, 241.610961, 218.833877, "LD_SPAC:white");
    PlayerTextDrawLetterSize(playerid, PTD_Login[playerid][12], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PTD_Login[playerid][12], 143.750167, 12.900003);
    PlayerTextDrawAlignment(playerid, PTD_Login[playerid][12], 1);
    PlayerTextDrawColor(playerid, PTD_Login[playerid][12], 538976511);
    PlayerTextDrawSetShadow(playerid, PTD_Login[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Login[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Login[playerid][12], 255);
    PlayerTextDrawFont(playerid, PTD_Login[playerid][12], 4);
    PlayerTextDrawSetProportional(playerid, PTD_Login[playerid][12], 0);
    PlayerTextDrawSetShadow(playerid, PTD_Login[playerid][12], 0);

    PTD_Login[playerid][13] = CreatePlayerTextDraw(playerid, 313.452209, 220.300277, "digite uma senha");
    PlayerTextDrawLetterSize(playerid, PTD_Login[playerid][13], 0.164801, 0.993332);
    PlayerTextDrawTextSize(playerid, PTD_Login[playerid][13], 8.000000, 141.000000);
    PlayerTextDrawAlignment(playerid, PTD_Login[playerid][13], 2);
    PlayerTextDrawColor(playerid, PTD_Login[playerid][13], 1347440895);
    PlayerTextDrawUseBox(playerid, PTD_Login[playerid][13], 1);
    PlayerTextDrawBoxColor(playerid, PTD_Login[playerid][13], 0);
    PlayerTextDrawSetShadow(playerid, PTD_Login[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Login[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Login[playerid][13], 255);
    PlayerTextDrawFont(playerid, PTD_Login[playerid][13], 2);
    PlayerTextDrawSetProportional(playerid, PTD_Login[playerid][13], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Login[playerid][13], 0);
    PlayerTextDrawSetSelectable(playerid, PTD_Login[playerid][13], true);

    PTD_Login[playerid][14] = CreatePlayerTextDraw(playerid, 241.573913, 256.650024, "LD_SPAC:white");
    PlayerTextDrawLetterSize(playerid, PTD_Login[playerid][14], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PTD_Login[playerid][14], 143.710708, 18.630014);
    PlayerTextDrawAlignment(playerid, PTD_Login[playerid][14], 1);
    PlayerTextDrawColor(playerid, PTD_Login[playerid][14], 14548991);
    PlayerTextDrawSetShadow(playerid, PTD_Login[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Login[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Login[playerid][14], 255);
    PlayerTextDrawFont(playerid, PTD_Login[playerid][14], 4);
    PlayerTextDrawSetProportional(playerid, PTD_Login[playerid][14], 0);
    PlayerTextDrawSetShadow(playerid, PTD_Login[playerid][14], 0);

    PTD_Login[playerid][15] = CreatePlayerTextDraw(playerid, 243.347793, 277.449920, "box");
    PlayerTextDrawLetterSize(playerid, PTD_Login[playerid][15], 0.000000, -1.573006);
    PlayerTextDrawTextSize(playerid, PTD_Login[playerid][15], 383.288604, 0.000000);
    PlayerTextDrawAlignment(playerid, PTD_Login[playerid][15], 1);
    PlayerTextDrawColor(playerid, PTD_Login[playerid][15], -1);
    PlayerTextDrawUseBox(playerid, PTD_Login[playerid][15], 1);
    PlayerTextDrawBoxColor(playerid, PTD_Login[playerid][15], 150);
    PlayerTextDrawSetShadow(playerid, PTD_Login[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Login[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Login[playerid][15], 255);
    PlayerTextDrawFont(playerid, PTD_Login[playerid][15], 1);
    PlayerTextDrawSetProportional(playerid, PTD_Login[playerid][15], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Login[playerid][15], 0);

    PTD_Login[playerid][16] = CreatePlayerTextDraw(playerid, 243.347793, 277.449920, "box");
    PlayerTextDrawLetterSize(playerid, PTD_Login[playerid][16], 0.000000, -2.583019);
    PlayerTextDrawTextSize(playerid, PTD_Login[playerid][16], 383.288604, 0.000000);
    PlayerTextDrawAlignment(playerid, PTD_Login[playerid][16], 1);
    PlayerTextDrawColor(playerid, PTD_Login[playerid][16], -1);
    PlayerTextDrawUseBox(playerid, PTD_Login[playerid][16], 1);
    PlayerTextDrawBoxColor(playerid, PTD_Login[playerid][16], 150);
    PlayerTextDrawSetShadow(playerid, PTD_Login[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Login[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Login[playerid][16], 255);
    PlayerTextDrawFont(playerid, PTD_Login[playerid][16], 1);
    PlayerTextDrawSetProportional(playerid, PTD_Login[playerid][16], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Login[playerid][16], 0);

    PTD_Login[playerid][17] = CreatePlayerTextDraw(playerid, 314.00000, 258.900000, "conectar");
    PlayerTextDrawLetterSize(playerid, PTD_Login[playerid][17], 0.333000, 1.200000);
    PlayerTextDrawTextSize(playerid, PTD_Login[playerid][17], 10.000000,  140.00000);
    PlayerTextDrawAlignment(playerid, PTD_Login[playerid][17], 2);
    PlayerTextDrawColor(playerid, PTD_Login[playerid][17], -1);
    PlayerTextDrawSetOutline(playerid, PTD_Login[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Login[playerid][17], 255);
    PlayerTextDrawFont(playerid, PTD_Login[playerid][17], 2);
    PlayerTextDrawSetProportional(playerid, PTD_Login[playerid][17], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Login[playerid][17], 1);
    PlayerTextDrawSetSelectable(playerid, PTD_Login[playerid][17], true);

    PTD_Login[playerid][18] = CreatePlayerTextDraw(playerid, 396.066589, 84.483451, SERVER_VERSION);
    PlayerTextDrawLetterSize(playerid, PTD_Login[playerid][18], 0.161054, 1.016666);
    PlayerTextDrawAlignment(playerid, PTD_Login[playerid][18], 3);
    PlayerTextDrawColor(playerid, PTD_Login[playerid][18], 1077952767);
    PlayerTextDrawSetShadow(playerid, PTD_Login[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Login[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Login[playerid][18], 255);
    PlayerTextDrawFont(playerid, PTD_Login[playerid][18], 1);
    PlayerTextDrawSetProportional(playerid, PTD_Login[playerid][18], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Login[playerid][18], 0);

    for(new i; i < sizeof(PTD_Login[]); i++) {
        PlayerTextDrawShow(playerid, PTD_Login[playerid][i]);
    }
    return 1;
}

stock Player:HideLogin(playerid)
{
    if ( !GetPVarInt(playerid, "Player_ShowPlayerLogin") )return 0;
    DeletePVar(playerid, "Player_ShowPlayerLogin");
    for(new i; i < sizeof(PTD_Login[]); i++)
    {
        if ( IsValidPlayerTextDraw(playerid, PTD_Login[playerid][i]) )
        {
            PlayerTextDrawDestroy(playerid, PTD_Login[playerid][i]);
            PTD_Login[playerid][i] = INVALID_PLAYER_TEXT_DRAW;
        }
    }
    return 1;
}

stock Player:GetAdmin(playerid)
{
    return Player[playerid][Admin];
}

stock Player:SetAdmin(playerid, level)
{
    if ( !Player[playerid][Logged] )return 0;
    switch(level)
    {
        case CEO: Player[playerid][Admin] = CEO;
        case ADMINISTRATOR: Player[playerid][Admin] = ADMINISTRATOR;
        case MODERATOR: Player[playerid][Admin] = MODERATOR;
        case HELPER: Player[playerid][Admin] = HELPER;
        default: return 0;
    }
    return 1;
}

stock Player:GetAdminLevelName(level, name[])
{
    switch(level)
    {
        case CEO: format(name, 32, "CEO");
        case ADMINISTRATOR: format(name, 32, "Administrador");
        case MODERATOR: format(name, 32, "Moderador");
        case HELPER: format(name, 32, "Helper");
    }
    return 1;
}

stock Player:GetAdminWorking(playerid)
{
    return Player[playerid][StaffWorking];
}

stock Player:Logged(playerid)
{
    return Player[playerid][Logged];
}