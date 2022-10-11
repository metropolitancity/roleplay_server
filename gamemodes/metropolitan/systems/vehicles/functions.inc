stock Vehicle:ShowPlayerSpeedometer(playerid)
{
    if ( GetPVarInt(playerid, "ShowPlayerSpeedometer") )return 0;
    SetPVarInt(playerid, "ShowPlayerSpeedometer", 1);
    
    TimerSpeedometer[playerid] = SetTimerEx("OnSpeedometerUpdate", 300, true, "i", playerid);

    PTD_Speedometer[playerid][0] = CreatePlayerTextDraw(playerid, 116.205986, 376.866912, "LD_SPAC:white");
    PlayerTextDrawLetterSize(playerid, PTD_Speedometer[playerid][0], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PTD_Speedometer[playerid][0], 88.000000, 20.000000);
    PlayerTextDrawAlignment(playerid, PTD_Speedometer[playerid][0], 1);
    PlayerTextDrawColor(playerid, PTD_Speedometer[playerid][0], 303174399);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Speedometer[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Speedometer[playerid][0], 255);
    PlayerTextDrawFont(playerid, PTD_Speedometer[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, PTD_Speedometer[playerid][0], 0);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][0], 0);

    PTD_Speedometer[playerid][1] = CreatePlayerTextDraw(playerid, 118.000000, 390.000000, "LD_SPAC:white");
    PlayerTextDrawLetterSize(playerid, PTD_Speedometer[playerid][1], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PTD_Speedometer[playerid][1], 50.000000, 4.000000);
    PlayerTextDrawAlignment(playerid, PTD_Speedometer[playerid][1], 1);
    PlayerTextDrawColor(playerid, PTD_Speedometer[playerid][1], 255);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Speedometer[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Speedometer[playerid][1], 255);
    PlayerTextDrawFont(playerid, PTD_Speedometer[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, PTD_Speedometer[playerid][1], 0);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][1], 0);

    PTD_Speedometer[playerid][2] = CreatePlayerTextDraw(playerid, 118.000000, 390.000000, "LD_SPAC:white");
    PlayerTextDrawLetterSize(playerid, PTD_Speedometer[playerid][2], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PTD_Speedometer[playerid][2], 0.000000, 4.000000);
    PlayerTextDrawAlignment(playerid, PTD_Speedometer[playerid][2], 1);
    PlayerTextDrawColor(playerid, PTD_Speedometer[playerid][2], 0x5F9EA0FF);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Speedometer[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Speedometer[playerid][2], 255);
    PlayerTextDrawFont(playerid, PTD_Speedometer[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, PTD_Speedometer[playerid][2], 0);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][2], 0);

    PTD_Speedometer[playerid][3] = CreatePlayerTextDraw(playerid, 140.000000, 379.216979, "000");// velocimetro
    PlayerTextDrawLetterSize(playerid, PTD_Speedometer[playerid][3], 0.182117, 0.952498);
    PlayerTextDrawTextSize(playerid, PTD_Speedometer[playerid][3], 29.117103, 0.000000);
    PlayerTextDrawAlignment(playerid, PTD_Speedometer[playerid][3], 3);
    PlayerTextDrawColor(playerid, PTD_Speedometer[playerid][3], -1);
    PlayerTextDrawUseBox(playerid, PTD_Speedometer[playerid][3], 1);
    PlayerTextDrawBoxColor(playerid, PTD_Speedometer[playerid][3], 0);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Speedometer[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Speedometer[playerid][3], 255);
    PlayerTextDrawFont(playerid, PTD_Speedometer[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, PTD_Speedometer[playerid][3], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][3], 0);

    PTD_Speedometer[playerid][4] = CreatePlayerTextDraw(playerid, 143.647094, 379.150146, "KM");
    PlayerTextDrawLetterSize(playerid, PTD_Speedometer[playerid][4], 0.231528, 0.981666);
    PlayerTextDrawAlignment(playerid, PTD_Speedometer[playerid][4], 1);
    PlayerTextDrawColor(playerid, PTD_Speedometer[playerid][4], 1347440895);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Speedometer[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Speedometer[playerid][4], 255);
    PlayerTextDrawFont(playerid, PTD_Speedometer[playerid][4], 2);
    PlayerTextDrawSetProportional(playerid, PTD_Speedometer[playerid][4], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][4], 0);

    PTD_Speedometer[playerid][5] = CreatePlayerTextDraw(playerid, 156.827346, 380.850250, "h");
    PlayerTextDrawLetterSize(playerid, PTD_Speedometer[playerid][5], 0.196704, 0.713333);
    PlayerTextDrawAlignment(playerid, PTD_Speedometer[playerid][5], 1);
    PlayerTextDrawColor(playerid, PTD_Speedometer[playerid][5], 1347440895);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Speedometer[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Speedometer[playerid][5], 255);
    PlayerTextDrawFont(playerid, PTD_Speedometer[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, PTD_Speedometer[playerid][5], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][5], 0);

    PTD_Speedometer[playerid][6] = CreatePlayerTextDraw(playerid, 186.846832, 385.033691, "");
    PlayerTextDrawLetterSize(playerid, PTD_Speedometer[playerid][6], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PTD_Speedometer[playerid][6], 10.000000, 10.000000);
    PlayerTextDrawAlignment(playerid, PTD_Speedometer[playerid][6], 1);
    PlayerTextDrawColor(playerid, PTD_Speedometer[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Speedometer[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Speedometer[playerid][6], 0);
    PlayerTextDrawFont(playerid, PTD_Speedometer[playerid][6], 5);
    PlayerTextDrawSetProportional(playerid, PTD_Speedometer[playerid][6], 0);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][6], 0);
    PlayerTextDrawSetPreviewModel(playerid, PTD_Speedometer[playerid][6], 1676);
    PlayerTextDrawSetPreviewRot(playerid, PTD_Speedometer[playerid][6], 0.000000, 0.000000, 0.000000, 1.000000);

    PTD_Speedometer[playerid][7] = CreatePlayerTextDraw(playerid, 197.287628, 394.399902, "LD_SPAC:white");
    PlayerTextDrawLetterSize(playerid, PTD_Speedometer[playerid][7], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PTD_Speedometer[playerid][7], 3.000000, -15.000000);
    PlayerTextDrawAlignment(playerid, PTD_Speedometer[playerid][7], 1);
    PlayerTextDrawColor(playerid, PTD_Speedometer[playerid][7], 255);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Speedometer[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Speedometer[playerid][7], 255);
    PlayerTextDrawFont(playerid, PTD_Speedometer[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, PTD_Speedometer[playerid][7], 0);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][7], 0);

    PTD_Speedometer[playerid][8] = CreatePlayerTextDraw(playerid, 197.387634, 394.399902, "LD_SPAC:white");
    PlayerTextDrawLetterSize(playerid, PTD_Speedometer[playerid][8], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PTD_Speedometer[playerid][8], 3.000000, 0.00000);
    PlayerTextDrawAlignment(playerid, PTD_Speedometer[playerid][8], 1);
    PlayerTextDrawColor(playerid, PTD_Speedometer[playerid][8], 0xFFA500FF);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Speedometer[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Speedometer[playerid][8], 255);
    PlayerTextDrawFont(playerid, PTD_Speedometer[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, PTD_Speedometer[playerid][8], 0);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][8], 0);

    PTD_Speedometer[playerid][9] = CreatePlayerTextDraw(playerid, 171.853118, 390.566711, "ld_pool:ball");
    PlayerTextDrawLetterSize(playerid, PTD_Speedometer[playerid][9], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PTD_Speedometer[playerid][9], 8.000000, 8.000000);
    PlayerTextDrawAlignment(playerid, PTD_Speedometer[playerid][9], 1);
    PlayerTextDrawColor(playerid, PTD_Speedometer[playerid][9], 808464639);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Speedometer[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Speedometer[playerid][9], 255);
    PlayerTextDrawFont(playerid, PTD_Speedometer[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, PTD_Speedometer[playerid][9], 0);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][9], 0);

    PTD_Speedometer[playerid][10] = CreatePlayerTextDraw(playerid, 174.628295, 390.300323, "!");
    PlayerTextDrawLetterSize(playerid, PTD_Speedometer[playerid][10], 0.220704, 0.910832);
    PlayerTextDrawAlignment(playerid, PTD_Speedometer[playerid][10], 1);
    PlayerTextDrawColor(playerid, PTD_Speedometer[playerid][10], -65281);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Speedometer[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Speedometer[playerid][10], 255);
    PlayerTextDrawFont(playerid, PTD_Speedometer[playerid][10], 1);
    PlayerTextDrawSetProportional(playerid, PTD_Speedometer[playerid][10], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][10], 0);

    PTD_Speedometer[playerid][11] = CreatePlayerTextDraw(playerid, 116.205986, 401.666778, "ld_dual:white");
    PlayerTextDrawLetterSize(playerid, PTD_Speedometer[playerid][11], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PTD_Speedometer[playerid][11], 88.000000, 20.000000);
    PlayerTextDrawAlignment(playerid, PTD_Speedometer[playerid][11], 1);
    PlayerTextDrawColor(playerid, PTD_Speedometer[playerid][11], 303174399);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Speedometer[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Speedometer[playerid][11], 255);
    PlayerTextDrawFont(playerid, PTD_Speedometer[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, PTD_Speedometer[playerid][11], 0);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][11], 0);

    PTD_Speedometer[playerid][12] = CreatePlayerTextDraw(playerid, 148.988449, 406.633300, "0000000"); // quilometragem
    PlayerTextDrawLetterSize(playerid, PTD_Speedometer[playerid][12], 0.200822, 0.711665);
    PlayerTextDrawAlignment(playerid, PTD_Speedometer[playerid][12], 2);
    PlayerTextDrawColor(playerid, PTD_Speedometer[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Speedometer[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Speedometer[playerid][12], 255);
    PlayerTextDrawFont(playerid, PTD_Speedometer[playerid][12], 2);
    PlayerTextDrawSetProportional(playerid, PTD_Speedometer[playerid][12], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][12], 0);

    PTD_Speedometer[playerid][13] = CreatePlayerTextDraw(playerid, 169.905990, 405.116851, "KM");
    PlayerTextDrawLetterSize(playerid, PTD_Speedometer[playerid][13], 0.231528, 0.981666);
    PlayerTextDrawAlignment(playerid, PTD_Speedometer[playerid][13], 1);
    PlayerTextDrawColor(playerid, PTD_Speedometer[playerid][13], 1347440895);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Speedometer[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Speedometer[playerid][13], 255);
    PlayerTextDrawFont(playerid, PTD_Speedometer[playerid][13], 2);
    PlayerTextDrawSetProportional(playerid, PTD_Speedometer[playerid][13], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][13], 0);
    /*
    PTD_Speedometer[playerid][14] = CreatePlayerTextDraw(playerid, 166.941024, 412.600250, "012L");
    PlayerTextDrawLetterSize(playerid, PTD_Speedometer[playerid][14], 0.137881, 0.748332);
    PlayerTextDrawAlignment(playerid, PTD_Speedometer[playerid][14], 3);
    PlayerTextDrawColor(playerid, PTD_Speedometer[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Speedometer[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Speedometer[playerid][14], 255);
    PlayerTextDrawFont(playerid, PTD_Speedometer[playerid][14], 2);
    PlayerTextDrawSetProportional(playerid, PTD_Speedometer[playerid][14], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][14], 0);

    PTD_Speedometer[playerid][15] = CreatePlayerTextDraw(playerid, 169.905990, 412.716735, "consumo km");
    PlayerTextDrawLetterSize(playerid, PTD_Speedometer[playerid][15], 0.111529, 0.785833);
    PlayerTextDrawAlignment(playerid, PTD_Speedometer[playerid][15], 1);
    PlayerTextDrawColor(playerid, PTD_Speedometer[playerid][15], 1347440895);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Speedometer[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Speedometer[playerid][15], 255);
    PlayerTextDrawFont(playerid, PTD_Speedometer[playerid][15], 2);
    PlayerTextDrawSetProportional(playerid, PTD_Speedometer[playerid][15], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][15], 0);*/

    for(new i; i < sizeof(PTD_Speedometer[]); i++)
    {
        if ( PTD_Speedometer[playerid][i] != INVALID_PLAYER_TEXT_DRAW )
        {
            PlayerTextDrawShow(playerid, PTD_Speedometer[playerid][i]);
        }
    }

    return 1;
}

stock Vehicle:HidePlayerSpeedometer(playerid)
{
    if ( !GetPVarInt(playerid, "ShowPlayerSpeedometer") )return 0;
    DeletePVar(playerid, "ShowPlayerSpeedometer");
    
    KillTimer(TimerSpeedometer[playerid]);
    TimerSpeedometer[playerid] = 0;

    for(new i; i < sizeof(PTD_Speedometer[]); i++)
    {
        if ( IsValidPlayerTextDraw(playerid, PTD_Speedometer[playerid][i]) )
        {
            PlayerTextDrawDestroy(playerid, PTD_Speedometer[playerid][i]);
            PTD_Speedometer[playerid][i] = INVALID_PLAYER_TEXT_DRAW;
        }
    }
    return 1;
}

stock Float:Vehicle:GetFuel(vehicleid)
{
    if ( !IsValidVehicle(vehicleid) )return 0.0;
    return Vehicle[vehicleid][Fuel];
}

stock Vehicle:SetFuel(vehicleid, Float:fuel)
{
    if ( !IsValidVehicle(vehicleid) )return 0;
    Vehicle[vehicleid][Fuel] = fuel;
    return 1;
}

stock Vehicle:GetMaxFuel(model)
{
    if ( !Vehicle:IsValidModel(model) )return -1;
    return VehicleData[model - 400][FUEL_CAPACITY];
}

stock Vehicle:IsValidModel(model)
{
    return !(model < 400 || model > 611);
}