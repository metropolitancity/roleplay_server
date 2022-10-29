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
                DS:ShowDealerShip(playerid, BusinessDealership[i][Name]);
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
            SelectTextDraw(playerid, COLOR_ORANGE);
            return Y_HOOKS_BREAK_RETURN_1;
        }
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
    if ( !GetPVarInt(playerid, "DS:ShowDealerShip") )return Y_HOOKS_CONTINUE_RETURN_1;

    if ( playertextid == PTD_Dealership[playerid][3] ) { // fechar
        DS:HideDealerShip(playerid);
        return Y_HOOKS_BREAK_RETURN_1;
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}