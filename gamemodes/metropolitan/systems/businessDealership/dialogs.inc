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

        if ( DS:IsPlayerIsOwner(playerid) )
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