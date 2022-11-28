cmd:comprarconce(playerid)
{
    new ds_id = DS:GetId(playerid, 1.5);
    if ( ds_id == INVALID_DEALERSHIP_ID )
    {
        NT:Send(playerid, NT_TYPE_ERROR, "Você não está próximo a uma concessionária.");
        return 0;
    }

    SetPVarInt(playerid, "IN_DEALERSHIP", ds_id);
    Dialog_Show(playerid, BUY_DEALERSHIP, DIALOG_STYLE_MSGBOX,
        ret_utf8decode(BusinessDealership[ds_id][Name]),
        "{"COLOR_WHITE_EMBED"}Você deseja comprar essa concessionária por {"COLOR_ORANGE_EMBED"}¢%d{"COLOR_WHITE_EMBED"}",
        "Comprar", "Fechar",
        BusinessDealership[ds_id][Price]
    );
    return 1;
}