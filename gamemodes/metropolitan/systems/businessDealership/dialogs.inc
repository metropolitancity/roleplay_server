Dialog:BUY_DEALERSHIP(playerid, response, listitem, inputtext[])
{
    new ds_id = GetPVarInt(playerid, "IN_DEALERSHIP");
    DeletePVar(playerid, "IN_DEALERSHIP");

    if ( response )
    {
        if (  ds_id != DS:GetId(playerid, 2.0) )
        {
            NT:Send(playerid, NT_TYPE_ERROR, "Você não está na mesma concessionária.");
            return 0;
        }

        if ( DS:IsPlayerOwner(playerid) )
        {
            NT:Send(playerid, NT_TYPE_ERROR, "Você já é dono de uma concessionária.");
            return 0;
        }

        if ( Player:GetCoins(playerid) < BusinessDealership[ds_id][Price] )
        {
            NT:Send(playerid, NT_TYPE_ERROR, "Você não tem coins suficiente.");
            return 0;
        }

        new query[255];
        mysql_format(SQL_Connection,
            query,
            sizeof(query),
            "UPDATE "TABLE_BUSINESS_DEALERSHIP" SET `user_id`='%d' WHERE `id`='%d';",
            Player[playerid][ID],
            BusinessDealership[ds_id][ID]
        );
        mysql_tquery(SQL_Connection, query, "OnPlayerBuyBusinessDealership", "ii", playerid, ds_id);
        return 1;
    }
    return 0;
}

Dialog:SELL_DEALERSHIP(playerid, response, listitem, inputtext[])
{
    new ds_id = GetPVarInt(playerid, "IN_DEALERSHIP");
    DeletePVar(playerid, "IN_DEALERSHIP");

    if ( response )
    {
        if ( BusinessDealership[ds_id][Owner][ID] != Player[playerid][ID] )
        {
            NT:Send(playerid, NT_TYPE_ERROR, "Você não é proprietário desta concessionária.");
            return 0;
        }

        NT:Send(playerid, NT_TYPE_INFO, "Processando a venda, por favor aguarde...");

        new query[255];
        mysql_format(SQL_Connection,
            query,
            sizeof(query),
            "UPDATE "TABLE_BUSINESS_DEALERSHIP" SET `user_id`=NULL WHERE `id`='%d';",
            BusinessDealership[ds_id][ID]
        );
        mysql_tquery(SQL_Connection, query, "OnPlayerSellBusinessDealership", "ii", playerid, ds_id);
        return 1;
    }
    return 1;
}

Dialog:IMPORT_VEHICLES(playerid, response, listitem, inputtext[])
{
    new page = GetPVarInt(playerid, "IMPORT_VEHICLES_PAGE");
    DeletePVar(playerid, "IMPORT_VEHICLES_PAGE");

    if ( !response )return 0;

    if ( page == 1 && !strcmp(inputtext, "<<", true) )
    {
        DS:ShowMenuImportVehicles(playerid, 1);
        return 0;
    }

    if ( page == DS:CountVehiclesImports() && !strcmp(inputtext, ">>", true) )
    {
        DS:ShowMenuImportVehicles(playerid, page);
        return 0;
    }

    if ( !strcmp(inputtext, "<<", true) ) {
        --page;
    }

    else if ( !strcmp(inputtext, ">>", true) ) {
        ++page;
    }

    DS:ShowMenuImportVehicles(playerid, page);
    return 1;
}