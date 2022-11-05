DS:ShowDealerShip(playerid, ds_index)
{
    if ( GetPVarInt(playerid, "DS:ShowDealerShip") )return 0;
    SetPVarInt(playerid, "DS:ShowDealerShip", 1);
    
    SetPlayerVirtualWorld(playerid, playerid);
    TogglePlayerControllable(playerid, false);

    PTD_Dealership[playerid][0] = CreatePlayerTextDraw(playerid, 7.313206, 145.666687, "LD_SPAC:white");
    PlayerTextDrawLetterSize(playerid, PTD_Dealership[playerid][0], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PTD_Dealership[playerid][0], 146.400177, 217.000000);
    PlayerTextDrawAlignment(playerid, PTD_Dealership[playerid][0], 1);
    PlayerTextDrawColor(playerid, PTD_Dealership[playerid][0], 0x121212FF);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Dealership[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Dealership[playerid][0], 255);
    PlayerTextDrawFont(playerid, PTD_Dealership[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, PTD_Dealership[playerid][0], 0);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][0], 0);

    PTD_Dealership[playerid][1] = CreatePlayerTextDraw(playerid, 7.487450, 145.499893, "LD_SPAC:white");
    PlayerTextDrawLetterSize(playerid, PTD_Dealership[playerid][1], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PTD_Dealership[playerid][1], 146.280441, 14.980029);
    PlayerTextDrawAlignment(playerid, PTD_Dealership[playerid][1], 1);
    PlayerTextDrawColor(playerid, PTD_Dealership[playerid][1], 0xBA55D3FF);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Dealership[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Dealership[playerid][1], 255);
    PlayerTextDrawFont(playerid, PTD_Dealership[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, PTD_Dealership[playerid][1], 0);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][1], 0);

    PTD_Dealership[playerid][2] = CreatePlayerTextDraw(playerid, 80.546775, 146.383300, ret_utf8decode(BusinessDealership[ds_index][Name]));
    PlayerTextDrawLetterSize(playerid, PTD_Dealership[playerid][2], 0.230395, 1.389999);
    PlayerTextDrawAlignment(playerid, PTD_Dealership[playerid][2], 2);
    PlayerTextDrawColor(playerid, PTD_Dealership[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Dealership[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Dealership[playerid][2], 255);
    PlayerTextDrawFont(playerid, PTD_Dealership[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, PTD_Dealership[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][2], 0);

    PTD_Dealership[playerid][3] = CreatePlayerTextDraw(playerid, 25.985479, 164.266723, "Luxuoso");
    PlayerTextDrawLetterSize(playerid, PTD_Dealership[playerid][3], 0.181200, 0.952499);
    PlayerTextDrawTextSize(playerid, PTD_Dealership[playerid][3], 60.0, 8.5);
    PlayerTextDrawAlignment(playerid, PTD_Dealership[playerid][3], 1);
    PlayerTextDrawColor(playerid, PTD_Dealership[playerid][3], -1);
    PlayerTextDrawSetOutline(playerid, PTD_Dealership[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Dealership[playerid][3], 255);
    PlayerTextDrawFont(playerid, PTD_Dealership[playerid][3], 2);
    PlayerTextDrawSetProportional(playerid, PTD_Dealership[playerid][3], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][3], 0);
    PlayerTextDrawSetSelectable(playerid, PTD_Dealership[playerid][3], true);

    PTD_Dealership[playerid][4] = CreatePlayerTextDraw(playerid, 67.185470, 164.266723, "popular");
    PlayerTextDrawLetterSize(playerid, PTD_Dealership[playerid][4], 0.181200, 0.952499);
    PlayerTextDrawTextSize(playerid, PTD_Dealership[playerid][4], 105.0, 8.5);
    PlayerTextDrawAlignment(playerid, PTD_Dealership[playerid][4], 1);
    PlayerTextDrawColor(playerid, PTD_Dealership[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Dealership[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Dealership[playerid][4], 255);
    PlayerTextDrawFont(playerid, PTD_Dealership[playerid][4], 2);
    PlayerTextDrawSetProportional(playerid, PTD_Dealership[playerid][4], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][4], 0);
    PlayerTextDrawSetSelectable(playerid, PTD_Dealership[playerid][4], true);

    PTD_Dealership[playerid][5] = CreatePlayerTextDraw(playerid, 107.916915, 164.350021, "usados");
    PlayerTextDrawLetterSize(playerid, PTD_Dealership[playerid][5], 0.181200, 0.952499);
    PlayerTextDrawTextSize(playerid, PTD_Dealership[playerid][5], 140.0, 8.5);
    PlayerTextDrawAlignment(playerid, PTD_Dealership[playerid][5], 1);
    PlayerTextDrawColor(playerid, PTD_Dealership[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Dealership[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Dealership[playerid][5], 255);
    PlayerTextDrawFont(playerid, PTD_Dealership[playerid][5], 2);
    PlayerTextDrawSetProportional(playerid, PTD_Dealership[playerid][5], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][5], 0);
    PlayerTextDrawSetSelectable(playerid, PTD_Dealership[playerid][5], true);

    PTD_Dealership[playerid][6] = CreatePlayerTextDraw(playerid, 14.978088, 348.083435, "1");
    PlayerTextDrawLetterSize(playerid, PTD_Dealership[playerid][6], 0.288023, 1.080833);
    PlayerTextDrawAlignment(playerid, PTD_Dealership[playerid][6], 1);
    PlayerTextDrawColor(playerid, PTD_Dealership[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Dealership[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Dealership[playerid][6], 255);
    PlayerTextDrawFont(playerid, PTD_Dealership[playerid][6], 3);
    PlayerTextDrawSetProportional(playerid, PTD_Dealership[playerid][6], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][6], 0);
    PlayerTextDrawSetSelectable(playerid, PTD_Dealership[playerid][6], true);

    for(new i; i < sizeof(PTD_Dealership[]); i++)
    {
        if ( IsValidPlayerTextDraw(playerid, PTD_Dealership[playerid][i]) ){
            PlayerTextDrawShow(playerid, PTD_Dealership[playerid][i]);
        }
    }
    SelectTextDraw(playerid, COLOR_ORANGE);

    SetPlayerCameraPos(playerid, 551.2551, -1298.5815, 19.1398);
    SetPlayerCameraLookAt(playerid, 552.2607, -1298.6003, 18.9232);
    return 1;
}

DS:HideDealerShip(playerid)
{
    if ( !GetPVarInt(playerid, "DS:ShowDealerShip") )return 0;
    DeletePVar(playerid, "DS:ShowDealerShip");
    SetPlayerVirtualWorld(playerid, 0);
    TogglePlayerControllable(playerid, true);
    SetCameraBehindPlayer(playerid);
    for(new i; i < sizeof(PTD_Dealership[]); i++){
        if ( IsValidPlayerTextDraw(playerid, PTD_Dealership[playerid][i]) ){
            PlayerTextDrawDestroy(playerid, PTD_Dealership[playerid][i]);
            PTD_Dealership[playerid][i] = INVALID_PLAYER_TEXT_DRAW;
        }
    }
    return 1;
}

DS:ShowVehicles(playerid, ds_index, page=0)
{
    new query[1024];
    mysql_format(
        SQL_Connection,
        query,
        sizeof(query),
        "SELECT * FROM "TABLE_BDS_VEHICLES" WHERE `dealership`='%d' ORDER BY created_at LIMIT %d OFFSET %d;",
        BusinessDealership[ds_index][ID],
        MAX_VEHICLES_PER_PAGE,
        (page * MAX_VEHICLES_PER_PAGE)
    );
    new Cache:cache = mysql_query(SQL_Connection, query, true);

    new num_rows = cache_num_rows();
    if ( num_rows )
    {
        Iter_Init(BDS_VehiclesPage[playerid]);

        new str[128], line, vname[MAX_VEHICLE_NAME], Float:bX = 95.0, Float:bY = 158.0;
        for(new i; i < num_rows; i++)
        {
            cache_get_value_name_int(i, "id", BDS_VehiclesInf[playerid][i][ID]);
            cache_get_value_name_int(i, "price_sell", BDS_VehiclesInf[playerid][i][PriceSell]);
            cache_get_value_name_int(i, "model", BDS_VehiclesInf[playerid][i][Model]);

            PTD_DealershipVehicles[playerid][i][0] = CreatePlayerTextDraw(playerid, bX, bY, "LD_SPAC:white");
            PlayerTextDrawLetterSize(playerid, PTD_DealershipVehicles[playerid][i][0], 0.000000, 0.000000);
            PlayerTextDrawTextSize(playerid, PTD_DealershipVehicles[playerid][i][0], 85.000000, 78.000000);
            PlayerTextDrawAlignment(playerid, PTD_DealershipVehicles[playerid][i][0], 1);
            PlayerTextDrawColor(playerid, PTD_DealershipVehicles[playerid][i][0], 0x202020FF);
            PlayerTextDrawSetShadow(playerid, PTD_DealershipVehicles[playerid][i][0], 0);
            PlayerTextDrawSetOutline(playerid, PTD_DealershipVehicles[playerid][i][0], 0);
            PlayerTextDrawBackgroundColor(playerid, PTD_DealershipVehicles[playerid][i][0], 255);
            PlayerTextDrawFont(playerid, PTD_DealershipVehicles[playerid][i][0], 4);
            PlayerTextDrawSetProportional(playerid, PTD_DealershipVehicles[playerid][i][0], 0);
            PlayerTextDrawSetShadow(playerid, PTD_DealershipVehicles[playerid][i][0], 0);
            PlayerTextDrawSetSelectable(playerid, PTD_DealershipVehicles[playerid][i][0], true);

            GetVehicleModelName(BDS_VehiclesInf[playerid][i][Model], vname);
            PTD_DealershipVehicles[playerid][i][1] = CreatePlayerTextDraw(playerid, bX + 42.5, bY + 3.0, vname);
            PlayerTextDrawLetterSize(playerid, PTD_DealershipVehicles[playerid][i][1], 0.2, 1.2);
            PlayerTextDrawTextSize(playerid, PTD_DealershipVehicles[playerid][i][1], 0.000000, 81.149948);
            PlayerTextDrawAlignment(playerid, PTD_DealershipVehicles[playerid][i][1], 2);
            PlayerTextDrawColor(playerid, PTD_DealershipVehicles[playerid][i][1], -1);
            PlayerTextDrawUseBox(playerid, PTD_DealershipVehicles[playerid][i][1], 1);
            PlayerTextDrawBoxColor(playerid, PTD_DealershipVehicles[playerid][i][1], 0);
            PlayerTextDrawSetShadow(playerid, PTD_DealershipVehicles[playerid][i][1], 0);
            PlayerTextDrawSetOutline(playerid, PTD_DealershipVehicles[playerid][i][1], 0);
            PlayerTextDrawBackgroundColor(playerid, PTD_DealershipVehicles[playerid][i][1], 255);
            PlayerTextDrawFont(playerid, PTD_DealershipVehicles[playerid][i][1], 2);
            PlayerTextDrawSetProportional(playerid, PTD_DealershipVehicles[playerid][i][1], 1);
            PlayerTextDrawSetShadow(playerid, PTD_DealershipVehicles[playerid][i][1], 0);

            PTD_DealershipVehicles[playerid][i][2] = CreatePlayerTextDraw(playerid, bX-8.4, bY-5.4, "");
            PlayerTextDrawLetterSize(playerid, PTD_DealershipVehicles[playerid][i][2], 0.000000, 0.000000);
            PlayerTextDrawTextSize(playerid, PTD_DealershipVehicles[playerid][i][2], 90.000000, 90.000000);
            PlayerTextDrawAlignment(playerid, PTD_DealershipVehicles[playerid][i][2], 1);
            PlayerTextDrawColor(playerid, PTD_DealershipVehicles[playerid][i][2], -1);
            PlayerTextDrawSetShadow(playerid, PTD_DealershipVehicles[playerid][i][2], 0);
            PlayerTextDrawSetOutline(playerid, PTD_DealershipVehicles[playerid][i][2], 0);
            PlayerTextDrawBackgroundColor(playerid, PTD_DealershipVehicles[playerid][i][2], 0);
            PlayerTextDrawFont(playerid, PTD_DealershipVehicles[playerid][i][2], 5);
            PlayerTextDrawSetProportional(playerid, PTD_DealershipVehicles[playerid][i][2], 0);
            PlayerTextDrawSetShadow(playerid, PTD_DealershipVehicles[playerid][i][2], 0);
            PlayerTextDrawSetPreviewModel(playerid, PTD_DealershipVehicles[playerid][i][2], BDS_VehiclesInf[playerid][i][Model]);
            PlayerTextDrawSetPreviewRot(playerid, PTD_DealershipVehicles[playerid][i][2], 0.000000, 0.000000, 36.000000, 1.000000);
            PlayerTextDrawSetPreviewVehCol(playerid, PTD_DealershipVehicles[playerid][i][2], 1, 1);

            format(str, sizeof(str), "valor: ~g~%s", RealStr(BDS_VehiclesInf[playerid][i][PriceSell]));
            PTD_DealershipVehicles[playerid][i][3] = CreatePlayerTextDraw(playerid, bX + 2.6, bY + 67.4, str);
            PlayerTextDrawLetterSize(playerid, PTD_DealershipVehicles[playerid][i][3], 0.134353, 0.951664);
            PlayerTextDrawTextSize(playerid, PTD_DealershipVehicles[playerid][i][3], bX + 83.1, 0.000000);
            PlayerTextDrawAlignment(playerid, PTD_DealershipVehicles[playerid][i][3], 1);
            PlayerTextDrawColor(playerid, PTD_DealershipVehicles[playerid][i][3], -1);
            PlayerTextDrawUseBox(playerid, PTD_DealershipVehicles[playerid][i][3], 1);
            PlayerTextDrawBoxColor(playerid, PTD_DealershipVehicles[playerid][i][3], 0);
            PlayerTextDrawSetShadow(playerid, PTD_DealershipVehicles[playerid][i][3], 0);
            PlayerTextDrawSetOutline(playerid, PTD_DealershipVehicles[playerid][i][3], 0);
            PlayerTextDrawBackgroundColor(playerid, PTD_DealershipVehicles[playerid][i][3], 255);
            PlayerTextDrawFont(playerid, PTD_DealershipVehicles[playerid][i][3], 2);
            PlayerTextDrawSetProportional(playerid, PTD_DealershipVehicles[playerid][i][3], 1);
            PlayerTextDrawSetShadow(playerid, PTD_DealershipVehicles[playerid][i][3], 0);

            bX += 100.0;
            ++line;
            if ( line == 5 ) {
                line = 0;
                bX = 95.8;
                bY += 85.0;
            }

            Iter_Add(BDS_VehiclesPage[playerid], i);

            PlayerTextDrawShow(playerid, PTD_DealershipVehicles[playerid][i][0]);
            PlayerTextDrawShow(playerid, PTD_DealershipVehicles[playerid][i][1]);
            PlayerTextDrawShow(playerid, PTD_DealershipVehicles[playerid][i][2]);
            PlayerTextDrawShow(playerid, PTD_DealershipVehicles[playerid][i][3]);
        }
    }
    cache_delete(cache);
    return 1;
}

DS:HideVehicles(playerid)
{
    if ( !GetPVarInt(playerid, "DS:ShowDealerShip") )return 0;
    new reset[E_BDS_VEHICLES_INFO];
    
    foreach(new i: BDS_VehiclesPage[playerid])
    {
        BDS_VehiclesInf[playerid][i] = reset;
        for(new t; t < sizeof(PTD_DealershipVehicles[][]); t++){
            if ( IsValidPlayerTextDraw(playerid, PTD_DealershipVehicles[playerid][i][t]) ) {
                PlayerTextDrawDestroy(playerid, PTD_DealershipVehicles[playerid][i][t]);
                PTD_DealershipVehicles[playerid][i][t] = INVALID_PLAYER_TEXT_DRAW;
            }
        }
    }
    Iter_Clear(BDS_VehiclesPage[playerid]);
    return 1;
}

DS:GetVehicles(ds_index)
{
    new Cache:tmp = MYSQL_INVALID_CACHE;
    if ( cache_is_any_active() )
    {
        tmp = cache_save();
    }

    new query[128], count = 0;
    mysql_format(SQL_Connection, query, sizeof(query), "SELECT count(*) as quantity FROM "TABLE_BDS_VEHICLES" WHERE `dealership`='%d';", BusinessDealership[ds_index][ID]);
    new Cache:cache = mysql_query(SQL_Connection, query, true);
    if ( cache_num_rows() ) {
        cache_get_value_name_int(0, "quantity", count);
    }
    cache_delete(cache);

    if ( tmp == MYSQL_INVALID_CACHE ) {
        cache_set_active(tmp);
    }
    return count;
}

DS:GetId(playerid, Float:range=1.0)
{
    foreach(new i: BusinessDealership)
    {
        if (IsPlayerInRangeOfPoint(playerid, range, BusinessDealership[i][X], BusinessDealership[i][Y], BusinessDealership[i][Z])) {
            return i;
        }
    }
    return -1;
}