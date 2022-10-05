flags:createvehicle(MODERATOR)
alias:createvehicle("criarveiculo", "cv")
cmd:createvehicle(playerid, params[])
{
    new model;
    if ( sscanf(params, "d", model) )
    {
        NT:Send(playerid, NT_TYPE_ERROR, "Use /cv [modelo]");
        return 0;
    }

    if ( model < 400 || model > 611 )
    {
        NT:Send(playerid, NT_TYPE_ERROR, "Modelo de veículo inválido.");
        return 0;
    }

    new vname[32], Float:x, Float:y, Float:z, Float:a;
    GetPlayerPos(playerid, x, y, z);
    GetPlayerFacingAngle(playerid, a);

    // pegar a frente do jogador.
    x += (4.0 * floatsin(-a, degrees));
    y += (4.0 * floatcos(-a, degrees));
    
    if ( Player[playerid][vAdmin] ){
        DestroyVehicle(Player[playerid][vAdmin]);
    }
    
    new vehicleid = CreateVehicle(model, x, y, z, a, 0, 0, -1);
    Player[playerid][vAdmin] = vehicleid;

    GetVehicleName(vehicleid, vname);
    NT:Send(playerid, NT_TYPE_SUCCESS, "Veiculo ~b~%s~w~ criado com sucesso!", vname);
    return 1;
}

flags:destroyvehicle(MODERATOR)
alias:destroyvehicle("dv", "destruirveiculo")
cmd:destroyvehicle(playerid)
{
    if ( !IsValidVehicle(Player[playerid][vAdmin]) )
    {
        NT:Send(playerid, NT_TYPE_ERROR, "Não há veiculo admin criado por você.");
        return 0;
    }

    new vname[32];
    GetVehicleName(Player[playerid][vAdmin], vname);
    DestroyVehicle(Player[playerid][vAdmin]);
    Player[playerid][vAdmin] = INVALID_VEHICLE_ID;
    NT:Send(playerid, NT_TYPE_SUCCESS, "Seu veiculo ~r~%s~w~ foi deletado.", vname);
    return 1;
}

flags:setaradmin(ADMINISTRATOR)
cmd:setaradmin(playerid, params[])
{
    new id, level;
    if ( sscanf(params, "ud", id, level) )
    {
        NT:Send(playerid, NT_TYPE_ERROR, "Use /setaradmin [id] [level]");
        return 0;
    }

    if ( !Player:Logged(id) )
    {
        NT:Send(playerid, NT_TYPE_ERROR, "Jogador não esta conectado.");
        return 0;
    }

    if ( level != HELPER && level != MODERATOR && level != ADMINISTRATOR && level != CEO )
    {
        NT:Send(playerid, NT_TYPE_ERROR, "Level inválido.");
        return 0;
    }


    if ( Player[id][Admin] == CEO && !IsPlayerAdmin(playerid) )
    {
        NT:Send(playerid, NT_TYPE_ERROR, "Você não pode setar o level desse jogador.");
        return 0;
    }

    new admname[32], query[128];
    Player:GetAdminLevelName(level, admname);
    
    Player:SetAdmin(id, level);
    CleanChat(id);
    if ( Player[id][Admin] <= level ){
        SendClientMessagef(id, COLOR_GOLD, "[Administração] {"COLOR_WHITE_EMBED"}Você foi promovido a {"COLOR_GOLD_EMBED"}%s{"COLOR_WHITE_EMBED"}.", admname);
    }else{
        SendClientMessagef(id, COLOR_RED, "[Administração] {"COLOR_WHITE_EMBED"}Você foi rebaixado a {"COLOR_RED_EMBED"}%s{"COLOR_WHITE_EMBED"}.", admname);
    }

    // salvar no banco de dados.
    mysql_format(SQL_Connection, query, sizeof(query), "UPDATE "TABLE_USERS" SET `admin`='%d' WHERE `id`='%d';", level, Player[id][ID]);
    mysql_tquery(SQL_Connection, query);


    NT:Send(playerid, NT_TYPE_INFO, "%s agora é %s.", Player[id][Name], admname);
    return 1;
}

cmd:staff(playerid)
{
    if ( Player[playerid][Admin] < HELPER )
    {
        return 0;
    }

    Player[playerid][StaffWorking] = !Player[playerid][StaffWorking];
    switch(Player[playerid][StaffWorking])
    {
        case 0:
        {
            NT:Send(playerid, NT_TYPE_SUCCESS, "Modo administrador: ~r~~h~Offline");
            SetPlayerSkin(playerid, Player[playerid][Skin]);
            return 1;
        }
        case 1:
        {
            NT:Send(playerid, NT_TYPE_SUCCESS, "Modo administrador: ~g~~h~Online");
            SetPlayerSkin(playerid, 217);
            return 1;
        }
    }
    return 1;
}