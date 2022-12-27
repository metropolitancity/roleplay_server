#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    mysql_query_file(SQL_Connection, "tables/"TABLE_IMPORT_VEHICLES".sql", false);
    mysql_query_file(SQL_Connection, "tables/"TABLE_BUSINESS_DEALERSHIP".sql", false);
    mysql_query_file(SQL_Connection, "tables/"TABLE_BDS_VEHICLES".sql", false);

    print("[MP:RP] Carregando concessionárias.");
    new Cache:cache = mysql_query(SQL_Connection, "SELECT d.*, u.name as user_name FROM "TABLE_BUSINESS_DEALERSHIP" as d LEFT JOIN "TABLE_USERS" as u ON d.user_id = u.id WHERE 1;", true);
    new num_rows = cache_num_rows();
    
    if ( num_rows )
    {
        new str[512];
        for(new i; i < num_rows; i++)
        {
            cache_get_value_name_int(i, "id", BusinessDealership[i][ID]);
            cache_get_value_name(i, "name", BusinessDealership[i][Name], 32);
            cache_get_value_name_int(i, "price", BusinessDealership[i][Price]);
            cache_get_value_name_int(i, "user_id", BusinessDealership[i][Owner][ID]);
            format(BusinessDealership[i][Owner][Name], MAX_PLAYER_NAME, "Ninguém");
            if ( BusinessDealership[i][Owner][ID] ) {
                cache_get_value_name(i, "user_name", BusinessDealership[i][Owner][Name], MAX_PLAYER_NAME);
            }
            cache_get_value_name_float(i, "x", BusinessDealership[i][X]);
            cache_get_value_name_float(i, "y", BusinessDealership[i][Y]);
            cache_get_value_name_float(i, "z", BusinessDealership[i][Z]);

            cache_get_value_name_float(i, "vspawn_x", BusinessDealership[i][vSpawnX]);
            cache_get_value_name_float(i, "vspawn_y", BusinessDealership[i][vSpawnY]);
            cache_get_value_name_float(i, "vspawn_z", BusinessDealership[i][vSpawnZ]);
            cache_get_value_name_float(i, "vspawn_a", BusinessDealership[i][vSpawnA]);
            
            Iter_Add(BusinessDealership, i);

            BusinessDealership[i][Pickup][0] = CreateDynamicPickup(
                19197, 
                23,
                BusinessDealership[i][X],
                BusinessDealership[i][Y],
                BusinessDealership[i][Z] - 1.1
            );

            BusinessDealership[i][Pickup][1] = CreateDynamicPickup(
                19134, 
                23,
                BusinessDealership[i][vSpawnX],
                BusinessDealership[i][vSpawnY],
                BusinessDealership[i][vSpawnZ]
            );

            BusinessDealership[i][MapIcon] = CreateDynamicMapIcon(
                BusinessDealership[i][X],
                BusinessDealership[i][Y],
                BusinessDealership[i][Z],
                55,
                -1,
                .worldid=0,
                .interiorid=0,
                .streamdistance=DISTANCE_RENDER_MAPICON
            );


            format(
                str,
                sizeof(str),
                "{"COLOR_RED_EMBED"}%s{FFFFFF}\nProprietário: {c1c1c1}%s{"COLOR_WHITE_EMBED"}\nPreço: {"COLOR_ORANGE_EMBED"}%s{FFFFFF}\nEstoque: {c1c1c1}%d",
                ret_utf8decode(BusinessDealership[i][Name]),
                BusinessDealership[i][Owner][Name],
                RealStr(BusinessDealership[i][Price], "¢"),
                DS:GetVehiclesInStock(i)
            );
            BusinessDealership[i][Label][0] = CreateDynamic3DTextLabel(
                str,
                -1,
                BusinessDealership[i][X],
                BusinessDealership[i][Y],
                BusinessDealership[i][Z],
                DISTANCE_RENDER_LABEL,
                .worldid=0,
                .interiorid=0,
                .streamdistance=DISTANCE_RENDER_LABEL
            );

            format(str, sizeof(str), "%s\n{"COLOR_WHITE_EMBED"}Garagem", ret_utf8decode(BusinessDealership[i][Name]));
            BusinessDealership[i][Label][1] = CreateDynamic3DTextLabel(
                str,
                COLOR_RED,
                BusinessDealership[i][vSpawnX],
                BusinessDealership[i][vSpawnY],
                BusinessDealership[i][vSpawnZ],
                DISTANCE_RENDER_LABEL,
                .worldid=0,
                .interiorid=0,
                .streamdistance=DISTANCE_RENDER_LABEL
            );
        }
        printf("[MP:RP] Foram carregados %d empresas do tipo concessionária.", Iter_Count(BusinessDealership));
        print(" ");
        
    }
    cache_delete(cache);
    CreateDynamicObject(13646, 560.73425, -1299.06799, 16.0,   0.00000, 0.00000, 0.00000, .streamdistance=50.0);

    // comprar veiculos para concessionária.
    CP_BUY_VEHICLE_DS = CreateDynamicCP(-1573.3845, 79.5847, 3.5547, 1.0, .worldid=0, .interiorid=0, .streamdistance=50.0);
    CreateDynamic3DTextLabel("Importação de veículos.", COLOR_WHITE, -1573.3845, 79.5847, 3.5547, 20.0, .streamdistance=30.0, .interiorid=0, .worldid=0);
    CreateDynamicMapIcon(-1573.3845, 79.5847, 3.5547, 55, COLOR_WHITE, .worldid=0, .interiorid=0);
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerConnect(playerid)
{
    for(new i; i < MAX_VEHICLES_PER_PAGE; i++){
        for(new t; t < sizeof(PTD_DealershipVehicles[][]); t++){
            PTD_DealershipVehicles[playerid][i][t] = INVALID_PLAYER_TEXT_DRAW;
        }
    }
    DS:SELECTED_SLOT[playerid] = -1;
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if ( IsValidVehicle(DS:SELECTED_VEHICLE[playerid]) ) {
        DestroyVehicle(DS:SELECTED_VEHICLE[playerid]);
        DS:SELECTED_VEHICLE[playerid] = INVALID_VEHICLE_ID;
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerEnterDynamicCP(playerid, STREAMER_TAG_CP:checkpointid)
{
    if ( checkpointid == CP_BUY_VEHICLE_DS )
    {
        if ( !DS:IsPlayerOwner(playerid) )
        {
            Player:SendError(playerid, "Você não é proprietário de uma concessionária.");
            return Y_HOOKS_BREAK_RETURN_0;
        }
        DS:ShowMenuImportVehicles(playerid, 1);
        return Y_HOOKS_BREAK_RETURN_0;
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if ( IsPlayerInAnyVehicle(playerid) ) return Y_HOOKS_CONTINUE_RETURN_1;

    if ( PRESSED(KEY_YES) && !GetPVarInt(playerid, "DS:ShowDealerShip") )
    {
        foreach(new i: BusinessDealership)
        {
            if ( IsPlayerInRangeOfPoint(playerid, 1.0, BusinessDealership[i][X], BusinessDealership[i][Y], BusinessDealership[i][Z]) )
            {
                DS:ShowDealerShip(playerid, i);
                return Y_HOOKS_BREAK_RETURN_1;
            }

            else if ( IsPlayerInRangeOfPoint(playerid, 1.0, BusinessDealership[i][vSpawnX], BusinessDealership[i][vSpawnY], BusinessDealership[i][vSpawnZ]) )
            {
                if ( GetPVarInt(playerid, "DS_GETTING_VEHICLE") > gettime() ) return Y_HOOKS_BREAK_RETURN_0;
                SetPVarInt(playerid, "DS_GETTING_VEHICLE", gettime() + 3);

                new query[1024];
                mysql_format(SQL_Connection, query, sizeof(query),
                    "SELECT v.*, u.name as user_name FROM "TABLE_USERS_VEHICLES" as v LEFT JOIN "TABLE_USERS" as u ON v.user_id = u.id WHERE `user_id`='%d' AND `in_garage_ds`=1;",
                    Player[playerid][ID]
                );
                mysql_tquery(SQL_Connection, query, "OnLoadPlayerVehicle", "i", playerid);
                return Y_HOOKS_BREAK_RETURN_1;
            }
        }
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerClickTextDraw(playerid, Text:clickedid)
{
    if ( clickedid == INVALID_TEXT_DRAW )
    {
        if ( GetPVarInt(playerid, "DS:ShowDealerShip") ) {
            DS:HideDealerShip(playerid);
            return Y_HOOKS_BREAK_RETURN_1;
        }
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
    if ( !GetPVarInt(playerid, "DS:ShowDealerShip") )return Y_HOOKS_CONTINUE_RETURN_1;
    
    new ds_index = DS:GetId(playerid, 2.0);
    if ( ds_index == INVALID_DEALERSHIP_ID )
    {
        DS:HideDealerShip(playerid);
        NT:Send(playerid, NT_TYPE_ERROR, "Você não esta em uma concessionária.");
        return Y_HOOKS_BREAK_RETURN_0;
    }

    // tab veiculos luxuoso
    if ( playertextid == PTD_Dealership[playerid][3] )
    {
        DeletePVar(playerid, "DS:OFFSET");
        if ( ds_index == -1 )return Y_HOOKS_BREAK_RETURN_0;
        DS:SELECTED_SLOT[playerid] = -1;
        DS:HideVehicles(playerid);
        DS:ShowVehicles(playerid, ds_index, BDS_TYPE_LUXURIOUS);
        SetPVarInt(playerid, "DS:TYPE", BDS_TYPE_LUXURIOUS);
        return Y_HOOKS_BREAK_RETURN_1;
    }
    
    // tab veiculos popular
    else if ( playertextid == PTD_Dealership[playerid][4] )
    {
        DeletePVar(playerid, "DS:OFFSET");

        if ( ds_index == -1 )return Y_HOOKS_BREAK_RETURN_0;

        DS:SELECTED_SLOT[playerid] = -1;
        DS:HideVehicles(playerid);
        DS:ShowVehicles(playerid, ds_index, BDS_TYPE_POPULAR);
        SetPVarInt(playerid, "DS:TYPE", BDS_TYPE_POPULAR);
        return Y_HOOKS_BREAK_RETURN_1;
    }

    // tab veiculos antigos
    else if ( playertextid == PTD_Dealership[playerid][5] )
    {
        DeletePVar(playerid, "DS:OFFSET");
        
        if ( ds_index == -1 )return Y_HOOKS_BREAK_RETURN_0;

        DS:SELECTED_SLOT[playerid] = -1;
        DS:HideVehicles(playerid);
        DS:ShowVehicles(playerid, ds_index, BDS_TYPE_OLD);
        SetPVarInt(playerid, "DS:TYPE", BDS_TYPE_OLD);
        return Y_HOOKS_BREAK_RETURN_1;
    }

    // página anterior
    else if ( playertextid == PTD_Dealership[playerid][8] )
    {
        if ( !GetPVarInt(playerid, "DS:OFFSET") )return Y_HOOKS_BREAK_RETURN_0;

        DS:HideVehicles(playerid);
        SetPVarInt(playerid, "DS:OFFSET", GetPVarInt(playerid, "DS:OFFSET") - MAX_VEHICLES_PER_PAGE);
        DS:ShowVehicles(playerid, ds_index, GetPVarInt(playerid, "DS:TYPE"), GetPVarInt(playerid, "DS:OFFSET"));
        return Y_HOOKS_BREAK_RETURN_1;
    }

    // próxima página
    else if ( playertextid == PTD_Dealership[playerid][9] )
    {
        new vehicles = DS:GetCountVehicles(ds_index, GetPVarInt(playerid, "DS:TYPE"));
        
        if ( (GetPVarInt(playerid, "DS:OFFSET") + MAX_VEHICLES_PER_PAGE) > vehicles )return Y_HOOKS_BREAK_RETURN_0;
        
        DS:HideVehicles(playerid);
        SetPVarInt(playerid, "DS:OFFSET", GetPVarInt(playerid, "DS:OFFSET") + MAX_VEHICLES_PER_PAGE);
        DS:ShowVehicles(playerid, ds_index, GetPVarInt(playerid, "DS:TYPE"), GetPVarInt(playerid, "DS:OFFSET"));
        return Y_HOOKS_BREAK_RETURN_1;
    }

    // comprar veiculo
    else if ( playertextid == PTD_Dealership[playerid][12] )
    {
        new index = DS:SELECTED_SLOT[playerid], ds_id = DS:GetId(playerid, 2.0);

        if ( index == -1 )return Y_HOOKS_BREAK_RETURN_0;

        if ( BDS_VehiclesInf[playerid][index][Price] > GetPlayerMoney(playerid) )
        {
            Player:SendError(playerid, "Você não tem dinheiro suficiente.");
            return Y_HOOKS_BREAK_RETURN_0;
        }

        if ( !BusinessDealership[ds_id][Owner][ID] )
        {
            Player:SendError(playerid, "Essa concessionária não tem um proprietário.");
            return Y_HOOKS_BREAK_RETURN_0;
        }

        new _query[128];
        mysql_format(SQL_Connection, _query, sizeof(_query), "SELECT * FROM "TABLE_USERS_VEHICLES" WHERE `user_id`='%d' AND `in_garage_ds`=1;", Player[playerid][ID]);
        new Cache:c = mysql_query(SQL_Connection, _query, true);

        if ( cache_num_rows() )
        {
            cache_delete(c);
            Player:SendError(playerid, "Você já tem um veículo na garagem da concessionária.");
            return Y_HOOKS_BREAK_RETURN_0;
        }
        cache_delete(c);

        if ( GetPlayerVehiclesCount(playerid) >= 2)
        {
            Player:SendError(playerid, "Você não pode comprar mais veículos.");
            return Y_HOOKS_BREAK_RETURN_0;
        }

        CancelSelectTextDraw(playerid);
        DS:HideDealerShip(playerid);

        new query[1024];
        mysql_format(SQL_Connection, query, sizeof(query),
            "INSERT INTO "TABLE_USERS_VEHICLES" \
            (id,user_id,model,spawn_x,spawn_y,spawn_z,spawn_a,interior,world,color1,color2,fuel,km,health)\
            VALUES(uuid(),'%d','%d','%.2f','%.2f','%.2f','%.2f','%d','%d','%d','%d','20.0','0','1000.0');",
            Player[playerid][ID],
            BDS_VehiclesInf[playerid][index][Model],
            BusinessDealership[ds_id][vSpawnX],
            BusinessDealership[ds_id][vSpawnY],
            BusinessDealership[ds_id][vSpawnZ],
            BusinessDealership[ds_id][vSpawnA],
            0,
            0,
            BDS_VehiclesInf[playerid][index][Color1],
            BDS_VehiclesInf[playerid][index][Color2]
        );
        mysql_tquery(SQL_Connection, query, "OnPlayerBuyingVehicle", "iis", playerid, BDS_VehiclesInf[playerid][index][Price], BDS_VehiclesInf[playerid][index][ID]);
        return Y_HOOKS_BREAK_RETURN_1;
    }

    foreach(new i: BDS_VehiclesPage[playerid])
    {
        if ( playertextid == PTD_DealershipVehicles[playerid][i][0] )
        {
            new index = DS:SELECTED_SLOT[playerid];
            if ( index == -1 ) {  
                DS:SELECTED_SLOT[playerid] = i;
                PlayerTextDrawColor(playerid, PTD_DealershipVehicles[playerid][i][0], COLOR_ORANGE);
                PlayerTextDrawShow(playerid, PTD_DealershipVehicles[playerid][i][0]);
            } else {
                DS:SELECTED_SLOT[playerid] = i;
                PlayerTextDrawColor(playerid, PTD_DealershipVehicles[playerid][index][0], -1);
                PlayerTextDrawShow(playerid, PTD_DealershipVehicles[playerid][index][0]);

                PlayerTextDrawColor(playerid, PTD_DealershipVehicles[playerid][i][0], COLOR_ORANGE);
                PlayerTextDrawShow(playerid, PTD_DealershipVehicles[playerid][i][0]);
            }

            if ( IsValidVehicle(DS:SELECTED_VEHICLE[playerid]) ) {
                DestroyVehicle(DS:SELECTED_VEHICLE[playerid]);
            }

            DS:SELECTED_VEHICLE[playerid] = CreateVehicle(BDS_VehiclesInf[playerid][i][Model], 560.2028, -1298.9869, 18.4452, 65.9999, BDS_VehiclesInf[playerid][i][Color1], BDS_VehiclesInf[playerid][i][Color2], -1);
            SetVehicleVirtualWorld(DS:SELECTED_VEHICLE[playerid], playerid);
            return Y_HOOKS_BREAK_RETURN_1;
        }
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}


forward OnPlayerBuyingVehicle(playerid, price, vID[]);
public OnPlayerBuyingVehicle(playerid, price, vID[])
{
    if ( cache_affected_rows() )
    {
        GivePlayerMoney(playerid, -price);

        new query[300];
        mysql_format(SQL_Connection, query, sizeof(query), "UPDATE "TABLE_USERS" SET `money`='%d' WHERE `id`='%d';", GetPlayerMoney(playerid), Player[playerid][ID]);
        mysql_tquery(SQL_Connection, query);
        
        mysql_format(SQL_Connection, query, sizeof(query), "DELETE FROM "TABLE_BDS_VEHICLES" WHERE `id`='%s';", vID);
        mysql_tquery(SQL_Connection, query);

        NT:Send(playerid, NT_TYPE_SUCCESS, "Veiculo comprado com sucesso!");
        
        CleanChat(playerid);
        SendClientMessagef(playerid, COLOR_ORANGE, "[!] {"COLOR_WHITE_EMBED"}Seu veiculo está na garagem da concessionária.");
        return 1;
    }
    NT:Send(playerid, NT_TYPE_ERROR, "Não foi possível comprar seu veiculo.");
    return 0;
}


forward OnLoadPlayerVehicle(playerid);
public OnLoadPlayerVehicle(playerid)
{
    if ( GetPVarInt(playerid, "DS_GARAGE_LOAD_VEHICLE") > gettime() )return 0;
    SetPVarInt(playerid, "DS_GARAGE_LOAD_VEHICLE", gettime() + 5);

    if ( cache_num_rows() )
    {    
        new vname[MAX_VEHICLE_NAME];
        new vehicleid = CreatePlayerVehicle(playerid);
        GetVehicleName(vehicleid, vname);
        NT:Send(playerid, NT_TYPE_SUCCESS, "Veiculo ~b~%s~w~ carregado.", vname);

        new query[255], vehicleDataID[40];
        GetVehicleDataId(vehicleid, vehicleDataID);

        mysql_format(SQL_Connection, query, sizeof(query), "UPDATE "TABLE_USERS_VEHICLES" SET `in_garage_ds`=0 WHERE `id`='%e';", vehicleDataID);
        mysql_tquery(SQL_Connection, query);

        return 1;
    }
    NT:Send(playerid, NT_TYPE_ERROR, "Não há veiculos seus na garagem.");
    return 0;
}

forward OnPlayerBuyBusinessDealership(playerid, ds_index);
public OnPlayerBuyBusinessDealership(playerid, ds_index)
{
    if ( cache_affected_rows() )
    {
        if ( Player:GetCoins(playerid) < BusinessDealership[ds_index][Price] )
        {
            NT:Send(playerid, NT_TYPE_ERROR, "Você não tem coins suficiente.");
            return 0;
        }

        // re-render label

        new str[255];
        
        BusinessDealership[ds_index][Owner][ID] = Player[playerid][ID];
        format(BusinessDealership[ds_index][Owner][Name], MAX_PLAYER_NAME, Player[playerid][Name]);

        format(
            str,
            sizeof(str),
            "{"COLOR_RED_EMBED"}%s{FFFFFF}\nProprietário: {c1c1c1}%s{"COLOR_WHITE_EMBED"}\nPreço: {"COLOR_ORANGE_EMBED"}%s{FFFFFF}\nEstoque: {c1c1c1}%d",
            ret_utf8decode(BusinessDealership[ds_index][Name]),
            BusinessDealership[ds_index][Owner][Name],
            RealStr(BusinessDealership[ds_index][Price], "¢"),
            DS:GetVehiclesInStock(ds_index)
        );
        UpdateDynamic3DTextLabelText(BusinessDealership[ds_index][Label][0], COLOR_WHITE, str);
        Player:SetCoins(playerid, Player:GetCoins(playerid) - BusinessDealership[ds_index][Price]);
        NT:Send(playerid, NT_TYPE_SUCCESS, "Concessionária adquirida com ~g~~h~~h~sucesso!");
        return 1;
    }
    NT:Send(playerid, NT_TYPE_ERROR, "Não foi possível comprar a concessionária.");
    return 0;
}

forward OnPlayerSellBusinessDealership(playerid, ds_index);
public OnPlayerSellBusinessDealership(playerid, ds_index)
{
    if ( cache_affected_rows() )
    {
        new str[255];
        
        BusinessDealership[ds_index][Owner][ID] = 0;
        format(BusinessDealership[ds_index][Owner][Name], MAX_PLAYER_NAME, "Ninguém");

        format(
            str,
            sizeof(str),
            "{"COLOR_RED_EMBED"}%s{FFFFFF}\nProprietário: {c1c1c1}%s{"COLOR_WHITE_EMBED"}\nPreço: {"COLOR_ORANGE_EMBED"}%s{FFFFFF}\nEstoque: {c1c1c1}%d",
            ret_utf8decode(BusinessDealership[ds_index][Name]),
            BusinessDealership[ds_index][Owner][Name],
            RealStr(BusinessDealership[ds_index][Price], "¢"),
            DS:GetVehiclesInStock(ds_index)
        );
        UpdateDynamic3DTextLabelText(BusinessDealership[ds_index][Label][0], COLOR_WHITE, str);

        new price = floatround(BusinessDealership[ds_index][Price] / 2);
        Player:SetCoins(playerid, Player:GetCoins(playerid) + price);
        
        NT:Send(playerid, NT_TYPE_SUCCESS, "Concessionária vendida com sucesso!");
        CleanChat(playerid, 50);
        SendClientMessagef(playerid, COLOR_BLUE, "» {"COLOR_WHITE_EMBED"}Você recebeu {"COLOR_ORANGE_EMBED"}¢%d{"COLOR_WHITE_EMBED"} pela venda de sua conessionária.", price);
        return 1;
    }
    NT:Send(playerid, NT_TYPE_ERROR, "Não foi possível vender sua concessionária.");
    return 0;
}

forward OnMenuBuyVehicle(playerid);
public OnMenuBuyVehicle(playerid)
{
    new rows = cache_num_rows();
    if ( rows )
    {
        new str[1024],
            caption[64],
            number_vehicles = DS:CountVehiclesImports(),
            actual_page = GetPVarInt(playerid, "IMPORT_VEHICLES_PAGE"),
            number_pages = floatround(float(number_vehicles) / float(MAX_IMPORT_VEHICLES_PER_PAGE), floatround_ceil),
            vname[MAX_VEHICLE_NAME],
            model,
            price,
            quantity
        ;

        format(caption, sizeof(caption), "IMPORTAR VEICULOS [%d/%d]", actual_page, number_pages);

        format(str, sizeof(str), "Modelo\tNome\tPreço\tQuantidade\n");

        for(new i; i < rows; i++){
            cache_get_value_name_int(i, "model", model);
            cache_get_value_name_int(i, "price", price);
            cache_get_value_name_int(i, "quantity", quantity);
            GetVehicleModelName(model, vname);
            format(str, sizeof(str), "%s%d\t{"COLOR_BLUE_EMBED"}%s\t{"COLOR_GREEN_EMBED"}%s\t{"COLOR_RED_EMBED"}%d\n", str, model, vname, RealStr(price), quantity);
        }

        if ( actual_page != 1 ) {
            strcat(str, "{"COLOR_RED_EMBED"}<<\n");
        }

        if ( number_pages > 1 && number_pages != actual_page) {
            strcat(str, "{"COLOR_RED_EMBED"}>>");
        }
        
        Dialog_Show(playerid, IMPORT_VEHICLES, DIALOG_STYLE_TABLIST_HEADERS, caption, str, "Comprar", "Fechar");
        return 1;
    }
    NT:Send(playerid, NT_TYPE_ERROR, "Não há veiculo em estoque para comprar.");
    return 0;
}