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

    PTD_Dealership[playerid][5] = CreatePlayerTextDraw(playerid, 107.916915, 164.350021, "antigos");
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

    PTD_Dealership[playerid][6] = CreatePlayerTextDraw(playerid, 148.00000, 190.00000, "LD_SPAC:white");
    PlayerTextDrawLetterSize(playerid, PTD_Dealership[playerid][6], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PTD_Dealership[playerid][6], 5.3, 158.600000);
    PlayerTextDrawAlignment(playerid, PTD_Dealership[playerid][6], 1);
    PlayerTextDrawColor(playerid, PTD_Dealership[playerid][6], 0x000000FF);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Dealership[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Dealership[playerid][6], 255);
    PlayerTextDrawFont(playerid, PTD_Dealership[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, PTD_Dealership[playerid][6], 0);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][6], 0);

    PTD_Dealership[playerid][7] = CreatePlayerTextDraw(playerid, 148.00000, 190.00000, "LD_SPAC:white");
    PlayerTextDrawLetterSize(playerid, PTD_Dealership[playerid][7], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PTD_Dealership[playerid][7], 5.3, 0.000000);
    PlayerTextDrawAlignment(playerid, PTD_Dealership[playerid][7], 1);
    PlayerTextDrawColor(playerid, PTD_Dealership[playerid][7], 0x505050FF);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Dealership[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Dealership[playerid][7], 255);
    PlayerTextDrawFont(playerid, PTD_Dealership[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, PTD_Dealership[playerid][7], 0);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][7], 0);

    PTD_Dealership[playerid][8] = CreatePlayerTextDraw(playerid, 148.395751, 179.250091, "ld_beat:up");
    PlayerTextDrawLetterSize(playerid, PTD_Dealership[playerid][8], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PTD_Dealership[playerid][8], 5.699996, 10.800001);
    PlayerTextDrawAlignment(playerid, PTD_Dealership[playerid][8], 1);
    PlayerTextDrawColor(playerid, PTD_Dealership[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Dealership[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Dealership[playerid][8], 255);
    PlayerTextDrawFont(playerid, PTD_Dealership[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, PTD_Dealership[playerid][8], 0);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][8], 0);
    PlayerTextDrawSetSelectable(playerid, PTD_Dealership[playerid][8], true);

    PTD_Dealership[playerid][9] = CreatePlayerTextDraw(playerid, 148.345748, 351.300384, "ld_beat:down");
    PlayerTextDrawLetterSize(playerid, PTD_Dealership[playerid][9], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PTD_Dealership[playerid][9], 5.899999, 10.800001);
    PlayerTextDrawAlignment(playerid, PTD_Dealership[playerid][9], 1);
    PlayerTextDrawColor(playerid, PTD_Dealership[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Dealership[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Dealership[playerid][9], 255);
    PlayerTextDrawFont(playerid, PTD_Dealership[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, PTD_Dealership[playerid][9], 0);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][9], 0);
    PlayerTextDrawSetSelectable(playerid, PTD_Dealership[playerid][9], true);
    
    PTD_Dealership[playerid][10] = CreatePlayerTextDraw(playerid, 7.781875, 366.166595, "LD_SPAC:white");
    PlayerTextDrawLetterSize(playerid, PTD_Dealership[playerid][10], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PTD_Dealership[playerid][10], 55.949985, 23.000000);
    PlayerTextDrawAlignment(playerid, PTD_Dealership[playerid][10], 1);
    PlayerTextDrawColor(playerid, PTD_Dealership[playerid][10], 303174399);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Dealership[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Dealership[playerid][10], 255);
    PlayerTextDrawFont(playerid, PTD_Dealership[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, PTD_Dealership[playerid][10], 0);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][10], 0);

    PTD_Dealership[playerid][11] = CreatePlayerTextDraw(playerid, 9.824370, 378.866943, "box");
    PlayerTextDrawLetterSize(playerid, PTD_Dealership[playerid][11], 0.000000, 0.903394);
    PlayerTextDrawTextSize(playerid, PTD_Dealership[playerid][11], 62.169818, 0.000000);
    PlayerTextDrawAlignment(playerid, PTD_Dealership[playerid][11], 1);
    PlayerTextDrawColor(playerid, PTD_Dealership[playerid][11], -1);
    PlayerTextDrawUseBox(playerid, PTD_Dealership[playerid][11], 1);
    PlayerTextDrawBoxColor(playerid, PTD_Dealership[playerid][11], 150);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Dealership[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Dealership[playerid][11], 255);
    PlayerTextDrawFont(playerid, PTD_Dealership[playerid][11], 1);
    PlayerTextDrawSetProportional(playerid, PTD_Dealership[playerid][11], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][11], 0);

    PTD_Dealership[playerid][12] = CreatePlayerTextDraw(playerid, 10.761383, 371.016601, "COMPRAR");
    PlayerTextDrawLetterSize(playerid, PTD_Dealership[playerid][12], 0.261317, 1.319999);
    PlayerTextDrawTextSize(playerid, PTD_Dealership[playerid][12], 60.0, 10.0);
    PlayerTextDrawAlignment(playerid, PTD_Dealership[playerid][12], 1);
    PlayerTextDrawColor(playerid, PTD_Dealership[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, PTD_Dealership[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, PTD_Dealership[playerid][12], 255);
    PlayerTextDrawFont(playerid, PTD_Dealership[playerid][12], 2);
    PlayerTextDrawSetProportional(playerid, PTD_Dealership[playerid][12], 1);
    PlayerTextDrawSetShadow(playerid, PTD_Dealership[playerid][12], 0);
    PlayerTextDrawSetSelectable(playerid, PTD_Dealership[playerid][12], true);

    for(new i; i < sizeof(PTD_Dealership[]); i++)
    {
        if ( IsValidPlayerTextDraw(playerid, PTD_Dealership[playerid][i]) ){
            PlayerTextDrawShow(playerid, PTD_Dealership[playerid][i]);
        }
    }

    DS:ShowVehicles(playerid, ds_index);
    SelectTextDraw(playerid, COLOR_ORANGE);

    SetPlayerCameraPos(playerid, 551.2551, -1298.5815, 19.1398);
    SetPlayerCameraLookAt(playerid, 552.2607, -1298.6003, 18.9232);
    return 1;
}

DS:HideDealerShip(playerid)
{
    if ( !GetPVarInt(playerid, "DS:ShowDealerShip") )return 0;

    DS:HideVehicles(playerid);

    SetPlayerVirtualWorld(playerid, 0);
    TogglePlayerControllable(playerid, true);
    SetCameraBehindPlayer(playerid);

    
    DeletePVar(playerid, "DS:OFFSET");
    DeletePVar(playerid, "DS:TYPE");
    DeletePVar(playerid, "DS:ShowDealerShip");

    DS:SELECTED_SLOT[playerid] = -1;
    if ( IsValidVehicle(DS:SELECTED_VEHICLE[playerid]) ) {
        DestroyVehicle(DS:SELECTED_VEHICLE[playerid]);
        DS:SELECTED_VEHICLE[playerid] = INVALID_VEHICLE_ID;
    }

    for(new i; i < sizeof(PTD_Dealership[]); i++){
        if ( IsValidPlayerTextDraw(playerid, PTD_Dealership[playerid][i]) ){
            PlayerTextDrawDestroy(playerid, PTD_Dealership[playerid][i]);
            PTD_Dealership[playerid][i] = INVALID_PLAYER_TEXT_DRAW;
        }
    }
    return 1;
}

DS:ShowVehicles(playerid, ds_index, type=BDS_TYPE_LUXURIOUS, offset=0)
{
    PlayerTextDrawHide(playerid, PTD_Dealership[playerid][6]);
    PlayerTextDrawHide(playerid, PTD_Dealership[playerid][7]);
    PlayerTextDrawHide(playerid, PTD_Dealership[playerid][8]);
    PlayerTextDrawHide(playerid, PTD_Dealership[playerid][9]);

    new query[1024];
    mysql_format(
        SQL_Connection,
        query,
        sizeof(query),
        "SELECT * FROM "TABLE_BDS_VEHICLES" WHERE `dealership`='%d' AND `type`='%d' ORDER BY created_at LIMIT %d OFFSET %d;",
        BusinessDealership[ds_index][ID],
        type,
        MAX_VEHICLES_PER_PAGE,
        offset
    );
    new Cache:cache = mysql_query(SQL_Connection, query, true);
    switch(type)
    {
        case BDS_TYPE_LUXURIOUS:
        {
            PlayerTextDrawColor(playerid, PTD_Dealership[playerid][3], COLOR_ORANGE);
            PlayerTextDrawShow(playerid, PTD_Dealership[playerid][3]);

            PlayerTextDrawColor(playerid, PTD_Dealership[playerid][4], -1);
            PlayerTextDrawShow(playerid, PTD_Dealership[playerid][4]);

            PlayerTextDrawColor(playerid, PTD_Dealership[playerid][5], -1);
            PlayerTextDrawShow(playerid, PTD_Dealership[playerid][5]);
        }

        case BDS_TYPE_POPULAR:
        {
            PlayerTextDrawColor(playerid, PTD_Dealership[playerid][3], -1);
            PlayerTextDrawShow(playerid, PTD_Dealership[playerid][3]);

            PlayerTextDrawColor(playerid, PTD_Dealership[playerid][4], COLOR_ORANGE);
            PlayerTextDrawShow(playerid, PTD_Dealership[playerid][4]);

            PlayerTextDrawColor(playerid, PTD_Dealership[playerid][5], -1);
            PlayerTextDrawShow(playerid, PTD_Dealership[playerid][5]);
        }

        case BDS_TYPE_OLD:
        {
            PlayerTextDrawColor(playerid, PTD_Dealership[playerid][3], -1);
            PlayerTextDrawShow(playerid, PTD_Dealership[playerid][3]);

            PlayerTextDrawColor(playerid, PTD_Dealership[playerid][4], -1);
            PlayerTextDrawShow(playerid, PTD_Dealership[playerid][4]);

            PlayerTextDrawColor(playerid, PTD_Dealership[playerid][5], COLOR_ORANGE);
            PlayerTextDrawShow(playerid, PTD_Dealership[playerid][5]);
        }
    }

    new num_rows = cache_num_rows();
    if ( num_rows )
    {
        Iter_Init(BDS_VehiclesPage[playerid]);
        
        new vehicles = DS:GetCountVehicles(ds_index, type);
        if ( vehicles > MAX_VEHICLES_PER_PAGE )
        {
            new size_parts = floatround(float(vehicles) / float(MAX_VEHICLES_PER_PAGE), floatround_ceil);
            new pages = floatround(float(offset) / float(MAX_VEHICLES_PER_PAGE), floatround_ceil);
            new Float:size = 158.6 / size_parts;
            new Float:posY = 190.0 + (size * pages);
            PlayerTextDrawSetPos(playerid, PTD_Dealership[playerid][7], 148.3, posY);
            PlayerTextDrawTextSize(playerid, PTD_Dealership[playerid][7], 5.3, size);
            PlayerTextDrawShow(playerid, PTD_Dealership[playerid][7]);
        }

        new vname[MAX_VEHICLE_NAME], Float:bX = 12.0, Float:bY = 180.0;
        for(new i; i < num_rows; i++)
        {
            cache_get_value_name(i, "id", BDS_VehiclesInf[playerid][i][ID], 40);
            cache_get_value_name_int(i, "price", BDS_VehiclesInf[playerid][i][Price]);
            cache_get_value_name_int(i, "model", BDS_VehiclesInf[playerid][i][Model]);
            cache_get_value_name_int(i, "color1", BDS_VehiclesInf[playerid][i][Color1]);
            cache_get_value_name_int(i, "color2", BDS_VehiclesInf[playerid][i][Color2]);
            
            GetVehicleModelName(BDS_VehiclesInf[playerid][i][Model], vname);

            PTD_DealershipVehicles[playerid][i][0] = CreatePlayerTextDraw(playerid, bX, bY, vname);
            PlayerTextDrawLetterSize(playerid, PTD_DealershipVehicles[playerid][i][0], 0.16, 0.9);
            PlayerTextDrawTextSize(playerid, PTD_DealershipVehicles[playerid][i][0], bX + 87.8, 9.500000);
            PlayerTextDrawAlignment(playerid, PTD_DealershipVehicles[playerid][i][0], 1);
            PlayerTextDrawColor(playerid, PTD_DealershipVehicles[playerid][i][0], -1);
            PlayerTextDrawUseBox(playerid, PTD_DealershipVehicles[playerid][i][0], 0);
            PlayerTextDrawBoxColor(playerid, PTD_DealershipVehicles[playerid][i][0], 255);
            PlayerTextDrawSetOutline(playerid, PTD_DealershipVehicles[playerid][i][0], 0);
            PlayerTextDrawBackgroundColor(playerid, PTD_DealershipVehicles[playerid][i][0], 255);
            PlayerTextDrawFont(playerid, PTD_DealershipVehicles[playerid][i][0], 2);
            PlayerTextDrawSetProportional(playerid, PTD_DealershipVehicles[playerid][i][0], 1);
            PlayerTextDrawSetShadow(playerid, PTD_DealershipVehicles[playerid][i][0], 0);
            PlayerTextDrawSetSelectable(playerid, PTD_DealershipVehicles[playerid][i][0], true);

            PTD_DealershipVehicles[playerid][i][1] = CreatePlayerTextDraw(playerid, bX + 135.0, bY, RealStr(BDS_VehiclesInf[playerid][i][Price]));
            PlayerTextDrawLetterSize(playerid, PTD_DealershipVehicles[playerid][i][1], 0.198535, 1.040000);
            PlayerTextDrawAlignment(playerid, PTD_DealershipVehicles[playerid][i][1], 3);
            PlayerTextDrawColor(playerid, PTD_DealershipVehicles[playerid][i][1], COLOR_GREEN);
            PlayerTextDrawSetOutline(playerid, PTD_DealershipVehicles[playerid][i][1], 0);
            PlayerTextDrawBackgroundColor(playerid, PTD_DealershipVehicles[playerid][i][1], 255);
            PlayerTextDrawFont(playerid, PTD_DealershipVehicles[playerid][i][1], 2);
            PlayerTextDrawSetProportional(playerid, PTD_DealershipVehicles[playerid][i][1], 1);
            PlayerTextDrawSetShadow(playerid, PTD_DealershipVehicles[playerid][i][1], 0);
            PlayerTextDrawSetSelectable(playerid, PTD_DealershipVehicles[playerid][i][1], false);

            bY += 15.0;

            Iter_Add(BDS_VehiclesPage[playerid], i);

            PlayerTextDrawShow(playerid, PTD_DealershipVehicles[playerid][i][0]);
            PlayerTextDrawShow(playerid, PTD_DealershipVehicles[playerid][i][1]);
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

DS:GetId(playerid, Float:range=1.0)
{
    foreach(new i: BusinessDealership)
    {
        if (IsPlayerInRangeOfPoint(playerid, range, BusinessDealership[i][X], BusinessDealership[i][Y], BusinessDealership[i][Z])) {
            return i;
        }
    }
    return INVALID_DEALERSHIP_ID;
}

DS:GetCountVehicles(ds_index, type)
{
    new Cache:tmp = MYSQL_INVALID_CACHE;
    if ( cache_is_any_active() ) {
        tmp = cache_save();
    }

    new query[128], count;
    mysql_format(SQL_Connection, query, sizeof(query), "SELECT count(id) as num FROM "TABLE_BDS_VEHICLES" WHERE `dealership`='%d' AND `type`='%d';", BusinessDealership[ds_index][ID], type);
    new Cache:cache = mysql_query(SQL_Connection, query, true);
    
    if ( cache_num_rows() ) {
        cache_get_value_name_int(0, "num", count);
    }
    cache_delete(cache);

    if ( tmp != MYSQL_INVALID_CACHE ) {
        cache_set_active(tmp);
    }
    return count;
}

DS:GetVehiclesInStock(ds_id)
{
    if ( !Iter_Contains(BusinessDealership, ds_id) )return 0;

    new Cache:tmp = MYSQL_INVALID_CACHE;
    if ( cache_is_any_active() )
    {
        tmp = cache_save();
    }

    new query[255];
    mysql_format(SQL_Connection, query, sizeof(query), "SELECT id FROM "TABLE_BDS_VEHICLES" WHERE `dealership`='%d';", BusinessDealership[ds_id][ID]);
    new Cache:cache = mysql_query(SQL_Connection, query, true), rows = cache_num_rows();
    cache_delete(cache);

    if ( tmp != MYSQL_INVALID_CACHE )
    {
        cache_set_active(tmp);
    }
    return rows;
}

DS:IsPlayerOwner(playerid)
{
    new Cache:tmp = MYSQL_INVALID_CACHE;
    if ( cache_is_any_active() )
    {
        tmp = cache_save();
    }

    new query[128];
    mysql_format(SQL_Connection, query, sizeof(query), "SELECT id FROM "TABLE_BUSINESS_DEALERSHIP" WHERE `user_id`='%d';", Player[playerid][ID]);
    new Cache:c = mysql_query(SQL_Connection, query, true), rows = cache_num_rows();
    cache_delete(c);

    if ( tmp != MYSQL_INVALID_CACHE )
    {
        cache_set_active(tmp);
    }
    return rows;
}