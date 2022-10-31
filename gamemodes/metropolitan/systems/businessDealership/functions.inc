DS:ShowDealerShip(playerid, ds_index)
{
    if ( GetPVarInt(playerid, "DS:ShowDealerShip") )return 0;
    SetPVarInt(playerid, "DS:ShowDealerShip", 1);

    PTD_Dealership[playerid][0] = CreatePlayerTextDraw(playerid, 86.024925, 124.083343, "LD_SPAC:white");
    PlayerTextDrawLetterSize(playerid, PTD_Dealership[playerid][0], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PTD_Dealership[playerid][0], 502.000000, 302.460266);
    PlayerTextDrawAlignment(playerid, PTD_Dealership[playerid][0], 1);
    PlayerTextDrawColor(playerid, PTD_Dealership[playerid][0], 0x101010FF);
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

    PTD_Dealership[playerid][2] = CreatePlayerTextDraw(playerid, 91.146972, 124.533302, ret_utf8decode(BusinessDealership[ds_index][Name]));
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

    new str[20];
    format(str, sizeof(str), "%d/%d", GetPVarInt(playerid, "DS:PAGE") + 1, 1 + (DS:GetVehicles(ds_index) / MAX_VEHICLES_PER_PAGE) );
    PTD_Dealership[playerid][7] = CreatePlayerTextDraw(playerid, 319.048522, 411.083374, str);
    PlayerTextDrawLetterSize(playerid, PTD_Dealership[playerid][7], 0.334874, 1.127498);
    PlayerTextDrawAlignment(playerid, PTD_Dealership[playerid][7], 1);
    PlayerTextDrawColor(playerid, PTD_Dealership[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Dealership[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Dealership[playerid][7], 255);
    PlayerTextDrawFont(playerid, PTD_Dealership[playerid][7], 2);
    PlayerTextDrawSetProportional(playerid, PTD_Dealership[playerid][7], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][7], 0);

    PTD_Dealership[playerid][8] = CreatePlayerTextDraw(playerid, 350.190673, 412.983337, "ld_beat:right");
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

    for(new i; i < sizeof(PTD_Dealership[]); i++)
    {
        if ( IsValidPlayerTextDraw(playerid, PTD_Dealership[playerid][i]) ){
            PlayerTextDrawShow(playerid, PTD_Dealership[playerid][i]);
        }
    }
    
    DS:ShowVehicles(playerid, ds_index);
    SelectTextDraw(playerid, COLOR_ORANGE);
    return 1;
}

DS:HideDealerShip(playerid)
{
    if ( !GetPVarInt(playerid, "DS:ShowDealerShip") )return 0;
    DS:HideVehicles(playerid);
    DS:SELECTED_SLOT[playerid] = -1;

    DeletePVar(playerid, "DS:ShowDealerShip");
    DeletePVar(playerid, "DS:PAGE");

    CancelSelectTextDraw(playerid);
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

        new str[128], line, model, price_sell, vname[MAX_VEHICLE_NAME], Float:bX = 95.0, Float:bY = 158.0;
        for(new i; i < num_rows; i++)
        {
            cache_get_value_name_int(i, "price_sell", price_sell);
            cache_get_value_name_int(i, "model", model);

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

            GetVehicleModelName(model, vname);
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
            PlayerTextDrawSetPreviewModel(playerid, PTD_DealershipVehicles[playerid][i][2], model);
            PlayerTextDrawSetPreviewRot(playerid, PTD_DealershipVehicles[playerid][i][2], 0.000000, 0.000000, 36.000000, 1.000000);
            PlayerTextDrawSetPreviewVehCol(playerid, PTD_DealershipVehicles[playerid][i][2], 1, 1);

            format(str, sizeof(str), "valor: ~g~%s", RealStr(price_sell));
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

    foreach(new i: BDS_VehiclesPage[playerid])
    {
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