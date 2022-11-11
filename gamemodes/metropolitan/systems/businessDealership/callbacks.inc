#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    mysql_query_file(SQL_Connection, "tables/"TABLE_BUSINESS_DEALERSHIP".sql", false);
    mysql_query_file(SQL_Connection, "tables/"TABLE_BDS_VEHICLES".sql", false);

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
            if ( BusinessDealership[i][Owner][ID] ) {
                cache_get_value_name(i, "user_name", BusinessDealership[i][Owner][Name], MAX_PLAYER_NAME);
            }
            cache_get_value_name_float(i, "x", BusinessDealership[i][X]);
            cache_get_value_name_float(i, "y", BusinessDealership[i][Y]);
            cache_get_value_name_float(i, "z", BusinessDealership[i][Z]);

            BusinessDealership[i][Pickup] = CreateDynamicPickup(
                19197, 
                23,
                BusinessDealership[i][X],
                BusinessDealership[i][Y],
                BusinessDealership[i][Z] - 1.1
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
                "{"COLOR_RED_EMBED"}%s{FFFFFF}\nPreço: {"COLOR_GREEN_EMBED"}%s{FFFFFF}\nEstoque: {c1c1c1}0",
                ret_utf8decode(BusinessDealership[i][Name]),
                RealStr(BusinessDealership[i][Price], "¢")
            );
            BusinessDealership[i][Label] = CreateDynamic3DTextLabel(
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

            Iter_Add(BusinessDealership, i);
        }
        printf("[MP:RP] Foram carregados %d empresas do tipo concessionária.", Iter_Count(BusinessDealership));
        print(" ");
        
    }
    cache_delete(cache);
    CreateDynamicObject(13646, 560.73425, -1299.06799, 16.0,   0.00000, 0.00000, 0.00000, .streamdistance=50.0);
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

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if ( PRESSED(KEY_YES) && !GetPVarInt(playerid, "DS:ShowDealerShip") )
    {
        foreach(new i: BusinessDealership)
        {
            if ( IsPlayerInRangeOfPoint(playerid, 1.0, BusinessDealership[i][X], BusinessDealership[i][Y], BusinessDealership[i][Z]) )
            {
                CleanChat(playerid);
                SendClientMessagef(playerid, COLOR_RED, "[Concessionária] {FFFFFF}Bem vindo a %s", ret_utf8decode(BusinessDealership[i][Name]));
                DS:ShowDealerShip(playerid, i);
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
            DS:HideVehicles(playerid);
            DS:HideDealerShip(playerid);
            DeletePVar(playerid, "DS:OFFSET");
            DeletePVar(playerid, "DS:TYPE");
            if ( IsValidVehicle(DS:SELECTED_VEHICLE[playerid]) ) {
                DestroyVehicle(DS:SELECTED_VEHICLE[playerid]);
                DS:SELECTED_VEHICLE[playerid] = INVALID_VEHICLE_ID;
            }
            return Y_HOOKS_BREAK_RETURN_1;
        }
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
    if ( !GetPVarInt(playerid, "DS:ShowDealerShip") )return Y_HOOKS_CONTINUE_RETURN_1;
    
    // tab veiculos luxuoso
    if ( playertextid == PTD_Dealership[playerid][3] )
    {
        new ds_index = DS:GetId(playerid, 2.0);
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
        new ds_index = DS:GetId(playerid, 2.0);
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
        new ds_index = DS:GetId(playerid, 2.0);
        
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
        new ds_index = DS:GetId(playerid, 2.0);
        DS:ShowVehicles(playerid, ds_index, GetPVarInt(playerid, "DS:TYPE"), GetPVarInt(playerid, "DS:OFFSET"));
        return Y_HOOKS_BREAK_RETURN_1;
    }

    // próxima página
    else if ( playertextid == PTD_Dealership[playerid][9] )
    {
        new ds_index = DS:GetId(playerid, 2.0);
        new vehicles = DS:GetCountVehicles(ds_index, GetPVarInt(playerid, "DS:TYPE"));
        
        if ( (GetPVarInt(playerid, "DS:OFFSET") + MAX_VEHICLES_PER_PAGE) > vehicles )return Y_HOOKS_BREAK_RETURN_0;
        
        DS:HideVehicles(playerid);
        SetPVarInt(playerid, "DS:OFFSET", GetPVarInt(playerid, "DS:OFFSET") + MAX_VEHICLES_PER_PAGE);
        DS:ShowVehicles(playerid, ds_index, GetPVarInt(playerid, "DS:TYPE"), GetPVarInt(playerid, "DS:OFFSET"));
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