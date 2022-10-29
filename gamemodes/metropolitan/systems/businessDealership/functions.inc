DS:ShowDealerShip(playerid, const name[])
{
    if ( GetPVarInt(playerid, "DS:ShowDealerShip") )return 0;
    SetPVarInt(playerid, "DS:ShowDealerShip", 1);

    PTD_Dealership[playerid][0] = CreatePlayerTextDraw(playerid, 86.024925, 124.083343, "LD_SPAC:white");
    PlayerTextDrawLetterSize(playerid, PTD_Dealership[playerid][0], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PTD_Dealership[playerid][0], 502.000000, 302.460266);
    PlayerTextDrawAlignment(playerid, PTD_Dealership[playerid][0], 1);
    PlayerTextDrawColor(playerid, PTD_Dealership[playerid][0], 303174382);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Dealership[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Dealership[playerid][0], 255);
    PlayerTextDrawFont(playerid, PTD_Dealership[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, PTD_Dealership[playerid][0], 0);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][0], 0);

    PTD_Dealership[playerid][1] = CreatePlayerTextDraw(playerid, 86.024948, 124.199935, "LD_SPAC:white");
    PlayerTextDrawLetterSize(playerid, PTD_Dealership[playerid][1], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PTD_Dealership[playerid][1], 502.249206, 17.449998);
    PlayerTextDrawAlignment(playerid, PTD_Dealership[playerid][1], 1);
    PlayerTextDrawColor(playerid, PTD_Dealership[playerid][1], 1768516095);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Dealership[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Dealership[playerid][1], 255);
    PlayerTextDrawFont(playerid, PTD_Dealership[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, PTD_Dealership[playerid][1], 0);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][1], 0);

    PTD_Dealership[playerid][2] = CreatePlayerTextDraw(playerid, 91.146972, 124.533302, ret_utf8decode(name));
    PlayerTextDrawLetterSize(playerid, PTD_Dealership[playerid][2], 0.332531, 1.553333);
    PlayerTextDrawAlignment(playerid, PTD_Dealership[playerid][2], 1);
    PlayerTextDrawColor(playerid, PTD_Dealership[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Dealership[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Dealership[playerid][2], 255);
    PlayerTextDrawFont(playerid, PTD_Dealership[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, PTD_Dealership[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][2], 0);

    PTD_Dealership[playerid][3] = CreatePlayerTextDraw(playerid, 570.176147, 124.866760, "X");
    PlayerTextDrawLetterSize(playerid, PTD_Dealership[playerid][3], 0.400000, 1.600000);
    PlayerTextDrawTextSize(playerid, PTD_Dealership[playerid][3], 579.000000, 10.000000);
    PlayerTextDrawAlignment(playerid, PTD_Dealership[playerid][3], 1);
    PlayerTextDrawColor(playerid, PTD_Dealership[playerid][3], -1523963137);
    PlayerTextDrawUseBox(playerid, PTD_Dealership[playerid][3], 1);
    PlayerTextDrawBoxColor(playerid, PTD_Dealership[playerid][3], 0);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Dealership[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Dealership[playerid][3], 255);
    PlayerTextDrawFont(playerid, PTD_Dealership[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, PTD_Dealership[playerid][3], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][3], 0);
    PlayerTextDrawSetSelectable(playerid, PTD_Dealership[playerid][3], true);

    PTD_Dealership[playerid][4] = CreatePlayerTextDraw(playerid, 103.997070, 412.349945, "comprar");
    PlayerTextDrawLetterSize(playerid, PTD_Dealership[playerid][4], 0.288022, 0.940832);
    PlayerTextDrawTextSize(playerid, PTD_Dealership[playerid][4], 158.0, 10.0);
    PlayerTextDrawAlignment(playerid, PTD_Dealership[playerid][4], 1);
    PlayerTextDrawColor(playerid, PTD_Dealership[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Dealership[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Dealership[playerid][4], 255);
    PlayerTextDrawFont(playerid, PTD_Dealership[playerid][4], 2);
    PlayerTextDrawSetProportional(playerid, PTD_Dealership[playerid][4], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][4], 0);
    PlayerTextDrawSetSelectable(playerid, PTD_Dealership[playerid][4], true);

    PTD_Dealership[playerid][5] = CreatePlayerTextDraw(playerid, 170.597183, 412.349945, "informacoes");
    PlayerTextDrawLetterSize(playerid, PTD_Dealership[playerid][5], 0.288022, 0.940832);
    PlayerTextDrawTextSize(playerid, PTD_Dealership[playerid][5], 250.0, 10.0);
    PlayerTextDrawAlignment(playerid, PTD_Dealership[playerid][5], 1);
    PlayerTextDrawColor(playerid, PTD_Dealership[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Dealership[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Dealership[playerid][5], 255);
    PlayerTextDrawFont(playerid, PTD_Dealership[playerid][5], 2);
    PlayerTextDrawSetProportional(playerid, PTD_Dealership[playerid][5], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][5], 0);
    PlayerTextDrawSetSelectable(playerid, PTD_Dealership[playerid][5], true);

    PTD_Dealership[playerid][6] = CreatePlayerTextDraw(playerid, 301.790954, 412.983337, "ld_beat:left");
    PlayerTextDrawLetterSize(playerid, PTD_Dealership[playerid][6], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PTD_Dealership[playerid][6], 11.000000, 9.000000);
    PlayerTextDrawAlignment(playerid, PTD_Dealership[playerid][6], 1);
    PlayerTextDrawColor(playerid, PTD_Dealership[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Dealership[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Dealership[playerid][6], 255);
    PlayerTextDrawFont(playerid, PTD_Dealership[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, PTD_Dealership[playerid][6], 0);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][6], 0);
    PlayerTextDrawSetSelectable(playerid, PTD_Dealership[playerid][6], true);

    PTD_Dealership[playerid][7] = CreatePlayerTextDraw(playerid, 319.048522, 411.083374, "1/1");
    PlayerTextDrawLetterSize(playerid, PTD_Dealership[playerid][7], 0.334874, 1.127498);
    PlayerTextDrawAlignment(playerid, PTD_Dealership[playerid][7], 1);
    PlayerTextDrawColor(playerid, PTD_Dealership[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Dealership[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Dealership[playerid][7], 255);
    PlayerTextDrawFont(playerid, PTD_Dealership[playerid][7], 2);
    PlayerTextDrawSetProportional(playerid, PTD_Dealership[playerid][7], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][7], 0);

    PTD_Dealership[playerid][8] = CreatePlayerTextDraw(playerid, 343.190673, 412.983337, "ld_beat:right");
    PlayerTextDrawLetterSize(playerid, PTD_Dealership[playerid][8], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PTD_Dealership[playerid][8], 11.000000, 9.000000);
    PlayerTextDrawAlignment(playerid, PTD_Dealership[playerid][8], 1);
    PlayerTextDrawColor(playerid, PTD_Dealership[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Dealership[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Dealership[playerid][8], 255);
    PlayerTextDrawFont(playerid, PTD_Dealership[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, PTD_Dealership[playerid][8], 0);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][8], 0);
    PlayerTextDrawSetSelectable(playerid, PTD_Dealership[playerid][8], true);
    
    /*
    PTD_Dealership[playerid][4] = CreatePlayerTextDraw(playerid, 95.863876, 157.916671, "LD_SPAC:white");
    PlayerTextDrawLetterSize(playerid, PTD_Dealership[playerid][4], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PTD_Dealership[playerid][4], 85.000000, 78.000000);
    PlayerTextDrawAlignment(playerid, PTD_Dealership[playerid][4], 1);
    PlayerTextDrawColor(playerid, PTD_Dealership[playerid][4], 303174399);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Dealership[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Dealership[playerid][4], 255);
    PlayerTextDrawFont(playerid, PTD_Dealership[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, PTD_Dealership[playerid][4], 0);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][4], 0);
    PlayerTextDrawSetSelectable(playerid, PTD_Dealership[playerid][4], true);

    PTD_Dealership[playerid][5] = CreatePlayerTextDraw(playerid, 138.393676, 160.833343, "Sultan");
    PlayerTextDrawLetterSize(playerid, PTD_Dealership[playerid][5], 0.316603, 1.332499);
    PlayerTextDrawTextSize(playerid, PTD_Dealership[playerid][5], 0.000000, 81.149948);
    PlayerTextDrawAlignment(playerid, PTD_Dealership[playerid][5], 2);
    PlayerTextDrawColor(playerid, PTD_Dealership[playerid][5], -1);
    PlayerTextDrawUseBox(playerid, PTD_Dealership[playerid][5], 1);
    PlayerTextDrawBoxColor(playerid, PTD_Dealership[playerid][5], 0);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Dealership[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Dealership[playerid][5], 255);
    PlayerTextDrawFont(playerid, PTD_Dealership[playerid][5], 2);
    PlayerTextDrawSetProportional(playerid, PTD_Dealership[playerid][5], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][5], 0);

    PTD_Dealership[playerid][6] = CreatePlayerTextDraw(playerid, 87.430465, 152.516372, "");
    PlayerTextDrawLetterSize(playerid, PTD_Dealership[playerid][6], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PTD_Dealership[playerid][6], 90.000000, 90.000000);
    PlayerTextDrawAlignment(playerid, PTD_Dealership[playerid][6], 1);
    PlayerTextDrawColor(playerid, PTD_Dealership[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Dealership[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Dealership[playerid][6], 0);
    PlayerTextDrawFont(playerid, PTD_Dealership[playerid][6], 5);
    PlayerTextDrawSetProportional(playerid, PTD_Dealership[playerid][6], 0);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][6], 0);
    PlayerTextDrawSetPreviewModel(playerid, PTD_Dealership[playerid][6], 560);
    PlayerTextDrawSetPreviewRot(playerid, PTD_Dealership[playerid][6], 0.000000, 0.000000, 36.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, PTD_Dealership[playerid][6], 1, 1);

    PTD_Dealership[playerid][7] = CreatePlayerTextDraw(playerid, 98.406326, 225.316848, "valor: ~g~$600.000");
    PlayerTextDrawLetterSize(playerid, PTD_Dealership[playerid][7], 0.134353, 0.951664);
    PlayerTextDrawTextSize(playerid, PTD_Dealership[playerid][7], 178.900054, 0.000000);
    PlayerTextDrawAlignment(playerid, PTD_Dealership[playerid][7], 1);
    PlayerTextDrawColor(playerid, PTD_Dealership[playerid][7], -1);
    PlayerTextDrawUseBox(playerid, PTD_Dealership[playerid][7], 1);
    PlayerTextDrawBoxColor(playerid, PTD_Dealership[playerid][7], 0);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Dealership[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Dealership[playerid][7], 255);
    PlayerTextDrawFont(playerid, PTD_Dealership[playerid][7], 2);
    PlayerTextDrawSetProportional(playerid, PTD_Dealership[playerid][7], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][7], 0);*/

    for(new i; i < sizeof(PTD_Dealership[]); i++)
    {
        if ( IsValidPlayerTextDraw(playerid, PTD_Dealership[playerid][i]) ){
            PlayerTextDrawShow(playerid, PTD_Dealership[playerid][i]);
        }
    }
    SelectTextDraw(playerid, COLOR_ORANGE);
    return 1;
}

DS:HideDealerShip(playerid)
{
    if ( !GetPVarInt(playerid, "DS:ShowDealerShip") )return 0;
    DeletePVar(playerid, "DS:ShowDealerShip");
    CancelSelectTextDraw(playerid);
    for(new i; i < sizeof(PTD_Dealership[]); i++){
        if ( IsValidPlayerTextDraw(playerid, PTD_Dealership[playerid][i]) ){
            PlayerTextDrawDestroy(playerid, PTD_Dealership[playerid][i]);
            PTD_Dealership[playerid][i] = INVALID_PLAYER_TEXT_DRAW;
        }
    }
    return 1;
}