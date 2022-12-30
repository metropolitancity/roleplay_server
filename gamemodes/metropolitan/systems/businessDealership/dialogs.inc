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

    new modelid = strval(inputtext);
    if ( !IsValidVehicleModel(modelid) ) {
        DS:ShowMenuImportVehicles(playerid, page);
        return 0;
    }

    SetPVarInt(playerid, "IMPORT_VEHICLE_MODELID", modelid);

    new vname[MAX_VEHICLE_NAME];
    GetVehicleModelName(modelid, vname);
    Dialog_Show(playerid, IMPORT_VEHICLES_QUANTITY, DIALOG_STYLE_INPUT, "IMPORTAR VEICULO {c1c1c1}»{ffffff} QUANTIDADE", "{ffffff}Digite a quantidade de {"COLOR_RED_EMBED"}%s{ffffff} que queira importar.\nQuantidade Disponível: {"COLOR_BLUE_EMBED"}%d{"COLOR_WHITE_EMBED"}.", "Próximo", "Voltar", vname, DS:GetVehicleImportQuantity(modelid));
    return 1;
}

Dialog:IMPORT_VEHICLES_QUANTITY(playerid, response, listitem, inputtext[])
{
    new modelid = GetPVarInt(playerid, "IMPORT_VEHICLE_MODELID");
    if ( response )
    {
        if ( !IsNumeric(inputtext) )
        {
            DeletePVar(playerid, "IMPORT_VEHICLE_MODELID");

            new vname[MAX_VEHICLE_NAME];
            GetVehicleModelName(modelid, vname);
            Dialog_Show(playerid, IMPORT_VEHICLES_QUANTITY, DIALOG_STYLE_INPUT, "IMPORTAR VEICULO {c1c1c1}»{ffffff} QUANTIDADE", "{ffffff}Digite a quantidade de {"COLOR_RED_EMBED"}%s's{ffffff} que queira importar.\nQuantidade Disponível: {"COLOR_BLUE_EMBED"}%d{"COLOR_WHITE_EMBED"}.", "Próximo", "Voltar", vname, DS:GetVehicleImportQuantity(modelid));
            return 0;
        }

        new quantity = strval(inputtext);

        if ( quantity > DS:GetVehicleImportQuantity(modelid) )
        {
            DeletePVar(playerid, "IMPORT_VEHICLE_MODELID");
            NT:Send(playerid, NT_TYPE_ERROR, "Não há essa quantidade disponível no momento, tente mais tarde.");
            return 0;
        }

        SetPVarInt(playerid, "IMPORT_VEHICLE_QUANTITY", quantity);
        Dialog_Show(playerid, IMPORT_VEHICLE_QUANTITY, DIALOG_STYLE_INPUT, "IMPORTAR VEICULO {c1c1c1}»{FFFFFF} QUANTIDADE", "{ffffff}Digite o id da cor do veículo.\n\n\tPara saber as cores dos veiculos acesse nosso discord em {"COLOR_ORANGE_EMBED"}https://discord.gg/mprp{"COLOR_WHITE_EMBED"}.", "Próximo", "Voltar");
        return 1;
    }
    DS:ShowMenuImportVehicles(playerid, 0);
    return 0;
}

Dialog:IMPORT_VEHICLE_QUANTITY(playerid, response, listitem, inputtext[])
{
    if ( response )
    {
        if ( !IsNumeric(inputtext) )
        {
            NT:Send(playerid, NT_TYPE_ERROR, "Digite uma cor válida.");
            return 0;
        }

        new query[1024], modelid = GetPVarInt(playerid, "IMPORT_VEHICLE_MODELID"), quantity = GetPVarInt(playerid, "IMPORT_VEHICLE_QUANTITY"), color = strval(inputtext);
        
        DeletePVar(playerid, "IMPORT_VEHICLE_MODELID");
        DeletePVar(playerid, "IMPORT_VEHICLE_QUANTITY");

        for(new i; i < quantity; i++)
        {
            mysql_format(SQL_Connection, query, sizeof(query), "INSERT INTO "TABLE_BDS_VEHICLES"(dealership,model,price,color1,color2,type)VALUES('%d','%d','%d','%d','%d','%d');",
                DS:GetOwnerRowId(playerid),
                modelid,
                DS:GetVehicleImportPrice(modelid),
                color, color, 0
            );
            mysql_tquery(SQL_Connection, query);
            
        }
        
        CleanChat(playerid);
        SendClientMessage(playerid, COLOR_BLUE, "Compra realizada.");
        return 1;
    }
    return 0;
}