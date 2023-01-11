// ============================== [ ENUM / VAR ] ==============================

static enum E_VEHICLE_DATA
{
    bool:StartingEngine,
    Float:Fuel
}
new static
    Vehicle[MAX_VEHICLES][E_VEHICLE_DATA],
    PlayerText:PTD_Speedometer[MAX_PLAYERS][14] = { INVALID_PLAYER_TEXT_DRAW, ...},
    TimerSpeedometer[MAX_PLAYERS] = { -1, ...}
;


static enum E_ENGINE_TYPE
{
	ENGINE_TYPE_NULL = 0,
    ENGINE_TYPE_GASOLINE = 1,
    ENGINE_TYPE_ALCOHOL,
    ENGINE_TYPE_DIESEL
}

static enum E_VEHICLE_INFO_DATA
{
    E_ENGINE_TYPE:ENGINE_TYPE,
    FUEL_CAPACITY
}
new const static VehicleData[][E_VEHICLE_INFO_DATA] =
{
	{ ENGINE_TYPE_GASOLINE, 80 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_DIESEL, 300 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_DIESEL, 300 },
	{ ENGINE_TYPE_DIESEL, 300 },
	{ ENGINE_TYPE_DIESEL, 300 },
	{ ENGINE_TYPE_GASOLINE, 90 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 70 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_DIESEL, 150 },
	{ ENGINE_TYPE_DIESEL, 150 },
	{ ENGINE_TYPE_GASOLINE, 70 },
	{ ENGINE_TYPE_DIESEL, 300 },
	{ ENGINE_TYPE_ALCOHOL, 500 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 80 },
	{ ENGINE_TYPE_DIESEL, 400 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_DIESEL, 100 },
	{ ENGINE_TYPE_DIESEL, 150 },
	{ ENGINE_TYPE_GASOLINE, 70 },
	{ ENGINE_TYPE_DIESEL, 90 },
	{ ENGINE_TYPE_DIESEL, 150 },
	{ ENGINE_TYPE_DIESEL, 200 },
	{ ENGINE_TYPE_DIESEL, 150 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_NULL, 0 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_DIESEL, 100 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_DIESEL, 70 },
	{ ENGINE_TYPE_NULL, 0 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_DIESEL, 200 },
	{ ENGINE_TYPE_GASOLINE, 80 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_DIESEL, 80 },
	{ ENGINE_TYPE_ALCOHOL, 150 },
	{ ENGINE_TYPE_GASOLINE, 30 },
	{ ENGINE_TYPE_NULL, 0 },
	{ ENGINE_TYPE_NULL, 0 },
	{ ENGINE_TYPE_GASOLINE, 80 },
	{ ENGINE_TYPE_DIESEL, 80 },
	{ ENGINE_TYPE_DIESEL, 80 },
	{ ENGINE_TYPE_DIESEL, 80 },
	{ ENGINE_TYPE_DIESEL, 150 },
	{ ENGINE_TYPE_DIESEL, 150 },
	{ ENGINE_TYPE_GASOLINE, 30 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_ALCOHOL, 100 },
	{ ENGINE_TYPE_GASOLINE, 30 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_NULL, 0 },
	{ ENGINE_TYPE_NULL, 0 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 30 },
	{ ENGINE_TYPE_ALCOHOL, 150 },
	{ ENGINE_TYPE_GASOLINE, 80 },
	{ ENGINE_TYPE_GASOLINE, 20 },
	{ ENGINE_TYPE_DIESEL, 80 },
	{ ENGINE_TYPE_DIESEL, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_ALCOHOL, 100 },
	{ ENGINE_TYPE_GASOLINE, 70 },
	{ ENGINE_TYPE_DIESEL, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_NULL, 0 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_DIESEL, 100 },
	{ ENGINE_TYPE_DIESEL, 60 },
	{ ENGINE_TYPE_DIESEL, 150 },
	{ ENGINE_TYPE_ALCOHOL, 200 },
	{ ENGINE_TYPE_ALCOHOL, 200 },
	{ ENGINE_TYPE_GASOLINE, 80 },
	{ ENGINE_TYPE_GASOLINE, 80 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_DIESEL, 80 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 80 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_ALCOHOL, 200 },
	{ ENGINE_TYPE_DIESEL, 100 },
	{ ENGINE_TYPE_DIESEL, 100 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_NULL, 0 },
	{ ENGINE_TYPE_GASOLINE, 70 },
	{ ENGINE_TYPE_GASOLINE, 70 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 80 },
	{ ENGINE_TYPE_GASOLINE, 70 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_DIESEL, 100 },
	{ ENGINE_TYPE_NULL, 0 },
	{ ENGINE_TYPE_NULL, 0 },
	{ ENGINE_TYPE_ALCOHOL, 150 },
	{ ENGINE_TYPE_ALCOHOL, 100 },
	{ ENGINE_TYPE_ALCOHOL, 100 },
	{ ENGINE_TYPE_DIESEL, 300 },
	{ ENGINE_TYPE_DIESEL, 300 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_ALCOHOL, 400 },
	{ ENGINE_TYPE_ALCOHOL, 400 },
	{ ENGINE_TYPE_GASOLINE, 40 },
	{ ENGINE_TYPE_GASOLINE, 40 },
	{ ENGINE_TYPE_GASOLINE, 30 },
	{ ENGINE_TYPE_DIESEL, 200 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_DIESEL, 100 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_DIESEL, 60 },
	{ ENGINE_TYPE_DIESEL, 60 },
	{ ENGINE_TYPE_DIESEL, 100 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_NULL, 0 },
	{ ENGINE_TYPE_NULL, 0 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_DIESEL, 150 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_ALCOHOL, 250 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_ALCOHOL, 500 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 80 },
	{ ENGINE_TYPE_GASOLINE, 80 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_ALCOHOL, 250 },
	{ ENGINE_TYPE_NULL, 0 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_NULL, 0 },
	{ ENGINE_TYPE_NULL, 0 },
	{ ENGINE_TYPE_GASOLINE, 30 },
	{ ENGINE_TYPE_GASOLINE, 30 },
	{ ENGINE_TYPE_DIESEL, 150 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_ALCOHOL, 500 },
	{ ENGINE_TYPE_DIESEL, 200 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 30 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_NULL, 0 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 30 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_DIESEL, 100 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_NULL, 0 },
	{ ENGINE_TYPE_NULL, 0 },
	{ ENGINE_TYPE_ALCOHOL, 300 },
	{ ENGINE_TYPE_ALCOHOL, 150 },
	{ ENGINE_TYPE_NULL, 0 },
	{ ENGINE_TYPE_DIESEL, 100 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 100 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 70 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_GASOLINE, 60 },
	{ ENGINE_TYPE_NULL, 0 },
	{ ENGINE_TYPE_NULL, 0 },
	{ ENGINE_TYPE_NULL, 0 },
	{ ENGINE_TYPE_DIESEL, 100 },
	{ ENGINE_TYPE_NULL, 0 },
	{ ENGINE_TYPE_NULL, 0 }
};

// ============================== [ FUNCTIONS ] ==============================
SetVehicleFuel(vehicleid, Float:fuel)
{
    if ( !IsValidVehicle(vehicleid) ) return 0;
    Vehicle[vehicleid][Fuel] = fuel;
    return 1;
}

stock Float:GetVehicleFuel(vehicleid){
    if ( !IsValidVehicle(vehicleid) )return 0.0;
    return Vehicle[vehicleid][Fuel];
}

stock ShowPlayerSpeedometer(playerid)
{
    if ( GetPVarInt(playerid, "ShowPlayerSpeedometer") )return 0;
    SetPVarInt(playerid, "ShowPlayerSpeedometer", 1);
    
    TimerSpeedometer[playerid] = SetTimerEx("OnSpeedometerUpdate", 300, true, "i", playerid);

    PTD_Speedometer[playerid][0] = CreatePlayerTextDraw(playerid, 116.205986, 376.866912, "LD_SPAC:white");
    PlayerTextDrawLetterSize(playerid, PTD_Speedometer[playerid][0], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PTD_Speedometer[playerid][0], 88.000000, 20.000000);
    PlayerTextDrawAlignment(playerid, PTD_Speedometer[playerid][0], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, PTD_Speedometer[playerid][0], 303174399);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Speedometer[playerid][0], 0);
    PlayerTextDrawBackgroundColour(playerid, PTD_Speedometer[playerid][0], 255);
    PlayerTextDrawFont(playerid, PTD_Speedometer[playerid][0], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, PTD_Speedometer[playerid][0], false);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][0], 0);

    PTD_Speedometer[playerid][1] = CreatePlayerTextDraw(playerid, 118.000000, 390.000000, "LD_SPAC:white");
    PlayerTextDrawLetterSize(playerid, PTD_Speedometer[playerid][1], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PTD_Speedometer[playerid][1], 50.000000, 4.000000);
    PlayerTextDrawAlignment(playerid, PTD_Speedometer[playerid][1], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, PTD_Speedometer[playerid][1], 255);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Speedometer[playerid][1], 0);
    PlayerTextDrawBackgroundColour(playerid, PTD_Speedometer[playerid][1], 255);
    PlayerTextDrawFont(playerid, PTD_Speedometer[playerid][1], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, PTD_Speedometer[playerid][1], false);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][1], 0);

    PTD_Speedometer[playerid][2] = CreatePlayerTextDraw(playerid, 118.000000, 390.000000, "LD_SPAC:white");
    PlayerTextDrawLetterSize(playerid, PTD_Speedometer[playerid][2], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PTD_Speedometer[playerid][2], 0.000000, 4.000000);
    PlayerTextDrawAlignment(playerid, PTD_Speedometer[playerid][2], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, PTD_Speedometer[playerid][2], 0x5F9EA0FF);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Speedometer[playerid][2], 0);
    PlayerTextDrawBackgroundColour(playerid, PTD_Speedometer[playerid][2], 255);
    PlayerTextDrawFont(playerid, PTD_Speedometer[playerid][2], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, PTD_Speedometer[playerid][2], false);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][2], 0);

    PTD_Speedometer[playerid][3] = CreatePlayerTextDraw(playerid, 140.000000, 379.216979, "000");// velocimetro
    PlayerTextDrawLetterSize(playerid, PTD_Speedometer[playerid][3], 0.182117, 0.952498);
    PlayerTextDrawTextSize(playerid, PTD_Speedometer[playerid][3], 29.117103, 0.000000);
    PlayerTextDrawAlignment(playerid, PTD_Speedometer[playerid][3], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, PTD_Speedometer[playerid][3], -1);
    PlayerTextDrawUseBox(playerid, PTD_Speedometer[playerid][3], true);
    PlayerTextDrawBoxColour(playerid, PTD_Speedometer[playerid][3], 0);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Speedometer[playerid][3], 0);
    PlayerTextDrawBackgroundColour(playerid, PTD_Speedometer[playerid][3], 255);
    PlayerTextDrawFont(playerid, PTD_Speedometer[playerid][3], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, PTD_Speedometer[playerid][3], true);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][3], 0);

    PTD_Speedometer[playerid][4] = CreatePlayerTextDraw(playerid, 143.647094, 379.150146, "KM");
    PlayerTextDrawLetterSize(playerid, PTD_Speedometer[playerid][4], 0.231528, 0.981666);
    PlayerTextDrawAlignment(playerid, PTD_Speedometer[playerid][4], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, PTD_Speedometer[playerid][4], 1347440895);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Speedometer[playerid][4], 0);
    PlayerTextDrawBackgroundColour(playerid, PTD_Speedometer[playerid][4], 255);
    PlayerTextDrawFont(playerid, PTD_Speedometer[playerid][4], TEXT_DRAW_FONT_2);
    PlayerTextDrawSetProportional(playerid, PTD_Speedometer[playerid][4], true);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][4], 0);

    PTD_Speedometer[playerid][5] = CreatePlayerTextDraw(playerid, 156.827346, 380.850250, "h");
    PlayerTextDrawLetterSize(playerid, PTD_Speedometer[playerid][5], 0.196704, 0.713333);
    PlayerTextDrawAlignment(playerid, PTD_Speedometer[playerid][5], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, PTD_Speedometer[playerid][5], 1347440895);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Speedometer[playerid][5], 0);
    PlayerTextDrawBackgroundColour(playerid, PTD_Speedometer[playerid][5], 255);
    PlayerTextDrawFont(playerid, PTD_Speedometer[playerid][5], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, PTD_Speedometer[playerid][5], false);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][5], 0);

    PTD_Speedometer[playerid][6] = CreatePlayerTextDraw(playerid, 186.846832, 385.033691, "");
    PlayerTextDrawLetterSize(playerid, PTD_Speedometer[playerid][6], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PTD_Speedometer[playerid][6], 10.000000, 10.000000);
    PlayerTextDrawAlignment(playerid, PTD_Speedometer[playerid][6], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, PTD_Speedometer[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Speedometer[playerid][6], 0);
    PlayerTextDrawBackgroundColour(playerid, PTD_Speedometer[playerid][6], 0);
    PlayerTextDrawFont(playerid, PTD_Speedometer[playerid][6], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, PTD_Speedometer[playerid][6], false);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][6], 0);
    PlayerTextDrawSetPreviewModel(playerid, PTD_Speedometer[playerid][6], 1676);
    PlayerTextDrawSetPreviewRot(playerid, PTD_Speedometer[playerid][6], 0.000000, 0.000000, 0.000000, 1.000000);

    PTD_Speedometer[playerid][7] = CreatePlayerTextDraw(playerid, 197.287628, 394.399902, "LD_SPAC:white");
    PlayerTextDrawLetterSize(playerid, PTD_Speedometer[playerid][7], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PTD_Speedometer[playerid][7], 3.000000, -15.000000);
    PlayerTextDrawAlignment(playerid, PTD_Speedometer[playerid][7], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, PTD_Speedometer[playerid][7], 255);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Speedometer[playerid][7], 0);
    PlayerTextDrawBackgroundColour(playerid, PTD_Speedometer[playerid][7], 255);
    PlayerTextDrawFont(playerid, PTD_Speedometer[playerid][7], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, PTD_Speedometer[playerid][7], false);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][7], 0);

    PTD_Speedometer[playerid][8] = CreatePlayerTextDraw(playerid, 197.387634, 394.399902, "LD_SPAC:white");
    PlayerTextDrawLetterSize(playerid, PTD_Speedometer[playerid][8], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PTD_Speedometer[playerid][8], 3.000000, 0.00000);
    PlayerTextDrawAlignment(playerid, PTD_Speedometer[playerid][8], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, PTD_Speedometer[playerid][8], 0xFFA500FF);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Speedometer[playerid][8], 0);
    PlayerTextDrawBackgroundColour(playerid, PTD_Speedometer[playerid][8], 255);
    PlayerTextDrawFont(playerid, PTD_Speedometer[playerid][8], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, PTD_Speedometer[playerid][8], false);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][8], 0);

    PTD_Speedometer[playerid][9] = CreatePlayerTextDraw(playerid, 171.853118, 390.566711, "ld_pool:ball");
    PlayerTextDrawLetterSize(playerid, PTD_Speedometer[playerid][9], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PTD_Speedometer[playerid][9], 8.000000, 8.000000);
    PlayerTextDrawAlignment(playerid, PTD_Speedometer[playerid][9], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, PTD_Speedometer[playerid][9], 808464639);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Speedometer[playerid][9], 0);
    PlayerTextDrawBackgroundColour(playerid, PTD_Speedometer[playerid][9], 255);
    PlayerTextDrawFont(playerid, PTD_Speedometer[playerid][9], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, PTD_Speedometer[playerid][9], false);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][9], 0);

    PTD_Speedometer[playerid][10] = CreatePlayerTextDraw(playerid, 174.628295, 390.300323, "!");
    PlayerTextDrawLetterSize(playerid, PTD_Speedometer[playerid][10], 0.220704, 0.910832);
    PlayerTextDrawAlignment(playerid, PTD_Speedometer[playerid][10], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, PTD_Speedometer[playerid][10], -65281);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Speedometer[playerid][10], 0);
    PlayerTextDrawBackgroundColour(playerid, PTD_Speedometer[playerid][10], 255);
    PlayerTextDrawFont(playerid, PTD_Speedometer[playerid][10], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, PTD_Speedometer[playerid][10], true);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][10], 0);

    PTD_Speedometer[playerid][11] = CreatePlayerTextDraw(playerid, 116.205986, 401.666778, "ld_dual:white");
    PlayerTextDrawLetterSize(playerid, PTD_Speedometer[playerid][11], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PTD_Speedometer[playerid][11], 88.000000, 20.000000);
    PlayerTextDrawAlignment(playerid, PTD_Speedometer[playerid][11], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, PTD_Speedometer[playerid][11], 303174399);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Speedometer[playerid][11], 0);
    PlayerTextDrawBackgroundColour(playerid, PTD_Speedometer[playerid][11], 255);
    PlayerTextDrawFont(playerid, PTD_Speedometer[playerid][11], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, PTD_Speedometer[playerid][11], false);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][11], 0);

    PTD_Speedometer[playerid][12] = CreatePlayerTextDraw(playerid, 148.988449, 406.633300, "0000000"); // quilometragem
    PlayerTextDrawLetterSize(playerid, PTD_Speedometer[playerid][12], 0.200822, 0.711665);
    PlayerTextDrawAlignment(playerid, PTD_Speedometer[playerid][12], TEXT_DRAW_ALIGN_CENTER);
    PlayerTextDrawColour(playerid, PTD_Speedometer[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Speedometer[playerid][12], 0);
    PlayerTextDrawBackgroundColour(playerid, PTD_Speedometer[playerid][12], 255);
    PlayerTextDrawFont(playerid, PTD_Speedometer[playerid][12], TEXT_DRAW_FONT_2);
    PlayerTextDrawSetProportional(playerid, PTD_Speedometer[playerid][12], true);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][12], 0);

    PTD_Speedometer[playerid][13] = CreatePlayerTextDraw(playerid, 169.905990, 405.116851, "KM");
    PlayerTextDrawLetterSize(playerid, PTD_Speedometer[playerid][13], 0.231528, 0.981666);
    PlayerTextDrawAlignment(playerid, PTD_Speedometer[playerid][13], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, PTD_Speedometer[playerid][13], 1347440895);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Speedometer[playerid][13], 0);
    PlayerTextDrawBackgroundColour(playerid, PTD_Speedometer[playerid][13], 255);
    PlayerTextDrawFont(playerid, PTD_Speedometer[playerid][13], TEXT_DRAW_FONT_2);
    PlayerTextDrawSetProportional(playerid, PTD_Speedometer[playerid][13], true);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][13], 0);
    /*
    PTD_Speedometer[playerid][14] = CreatePlayerTextDraw(playerid, 166.941024, 412.600250, "012L");
    PlayerTextDrawLetterSize(playerid, PTD_Speedometer[playerid][14], 0.137881, 0.748332);
    PlayerTextDrawAlignment(playerid, PTD_Speedometer[playerid][14], 3);
    PlayerTextDrawColour(playerid, PTD_Speedometer[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Speedometer[playerid][14], 0);
    PlayerTextDrawBackgroundColour(playerid, PTD_Speedometer[playerid][14], 255);
    PlayerTextDrawFont(playerid, PTD_Speedometer[playerid][14], 2);
    PlayerTextDrawSetProportional(playerid, PTD_Speedometer[playerid][14], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][14], 0);
    PTD_Speedometer[playerid][15] = CreatePlayerTextDraw(playerid, 169.905990, 412.716735, "consumo km");
    PlayerTextDrawLetterSize(playerid, PTD_Speedometer[playerid][15], 0.111529, 0.785833);
    PlayerTextDrawAlignment(playerid, PTD_Speedometer[playerid][15], 1);
    PlayerTextDrawColour(playerid, PTD_Speedometer[playerid][15], 1347440895);
    PlayerTextDrawSetShadow(playerid, PTD_Speedometer[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Speedometer[playerid][15], 0);
    PlayerTextDrawBackgroundColour(playerid, PTD_Speedometer[playerid][15], 255);
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

stock HidePlayerSpeedometer(playerid)
{
    if ( !GetPVarInt(playerid, "ShowPlayerSpeedometer") )return 0;
    DeletePVar(playerid, "ShowPlayerSpeedometer");
    
    KillTimer(TimerSpeedometer[playerid]);
    TimerSpeedometer[playerid] = -1;

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

stock GetVehicleMaxFuel(modelid)
{
    if ( !IsValidVehicleModel(modelid) )return 0;
    return VehicleData[modelid - 400][FUEL_CAPACITY];
}

stock IsValidVehicleModel(modelid) {
    return !(modelid < 400 || modelid > 611);
}

// ============================== [ CALLBACKS ] ==============================
#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    SetTimer("OnVehicleUpdateFuel", 1000, true);
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerStateChange(playerid, PLAYER_STATE:newstate, PLAYER_STATE:oldstate)
{
    if ( newstate == PLAYER_STATE_DRIVER )
    {
        if ( IsPlayerInAnyVehicle(playerid) ) {
            ShowPlayerSpeedometer(playerid);
        }
    }
    else if ( oldstate == PLAYER_STATE_DRIVER ){
        HidePlayerSpeedometer(playerid);
    }
}

hook OnPlayerKeyStateChange(playerid, KEY:newkeys, KEY:oldkeys)
{
    if ( IsPlayerInAnyVehicle(playerid) )
    {
        new vehicleid = GetPlayerVehicleID(playerid);
        if ( PRESSED(KEY_YES) )
        {
            if ( !Vehicle[vehicleid][StartingEngine] && !GetVehicleParams(vehicleid, VEHICLE_TYPE_ENGINE))
            {
                Vehicle[vehicleid][StartingEngine] = true;
                NT:Send(playerid, NT_TYPE_INFO, "Ligando motor...");
                SetTimerEx("OnVehicleStaringEngine", 2000, false, "i", vehicleid);
            }else{
                NT:Send(playerid, NT_TYPE_INFO, "Motor ~r~desligado");
                SetVehicleParams(vehicleid, VEHICLE_TYPE_ENGINE, false);
            }
        }
        else if ( PRESSED(KEY_NO) ) {
            new bool:status = !GetVehicleParams(vehicleid, VEHICLE_TYPE_LIGHTS);
            if ( status )NT:Send(playerid, NT_TYPE_INFO, "Faról ~g~ligado");
            else NT:Send(playerid, NT_TYPE_INFO, "Faról ~r~desligado");
            SetVehicleParams(vehicleid, VEHICLE_TYPE_LIGHTS, status);
        }
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnVehicleStaringEngine(vehicleid)
{
    if ( !IsValidVehicle(vehicleid) )return 0;
    Vehicle[vehicleid][StartingEngine] = false;
    new Float:health;
    GetVehicleHealth(vehicleid, health);

    if ( GetVehicleFuel(vehicleid) <= 0.0000 || health <= 300 ) {
        NT:Send(GetVehicleDriver(vehicleid), NT_TYPE_ERROR, "O motor falhou.");
        return Y_HOOKS_CONTINUE_RETURN_1;
    }

    NT:Send(GetVehicleDriver(vehicleid), NT_TYPE_INFO, "Motor ~g~ligado");
    SetVehicleParams(vehicleid, VEHICLE_TYPE_ENGINE, true);   
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnVehicleUpdateFuel()
{
    foreach(new vehicleid: Vehicle)
    {
        if ( IsValidVehicle(vehicleid) )
        {
            if ( GetVehicleParams(vehicleid, VEHICLE_TYPE_ENGINE) || GetVehicleFuel(vehicleid) > 0.0000 )
            {
                new speed = GetVehicleSpeed(vehicleid);
                SetVehicleFuel(vehicleid, GetVehicleFuel(vehicleid) - (0.005 + (speed * 0.000238)) );

                if ( GetVehicleFuel(vehicleid) <= 0.0000 ) {
                    SetVehicleFuel(vehicleid, 0.0000);
                    SetVehicleParams(vehicleid, VEHICLE_TYPE_ENGINE, false);
                    NT:Send(GetVehicleDriver(vehicleid), NT_TYPE_ERROR, "Motor parou de funcionar.");

                }
            }
            return 1;
        }
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnSpeedometerUpdate(playerid)
{
    new str[128];
    new vehicleid = GetPlayerVehicleID(playerid), modelid = GetVehicleModel(vehicleid), speed = GetVehicleSpeed(vehicleid), max_speed = GetVehicleMaxSpeed(modelid);

    //
    format(str, sizeof(str), "%03d", speed);
    PlayerTextDrawSetString(playerid, PTD_Speedometer[playerid][3], str);
    
    // 
    PlayerTextDrawTextSize(playerid, PTD_Speedometer[playerid][2], (50.0 / max_speed) * speed, 4.000000);
    PlayerTextDrawShow(playerid, PTD_Speedometer[playerid][2]);

    format(str, sizeof(str), "%07d", floatround(GetDistanceTraveled(vehicleid) / 1000, floatround_floor));
    PlayerTextDrawSetString(playerid, PTD_Speedometer[playerid][12], str);

    PlayerTextDrawTextSize(playerid, PTD_Speedometer[playerid][8], 3.000000,  (-15.0 / GetVehicleMaxFuel(modelid) ) * GetVehicleFuel(vehicleid));
    PlayerTextDrawShow(playerid, PTD_Speedometer[playerid][8]);
    return 1;
}