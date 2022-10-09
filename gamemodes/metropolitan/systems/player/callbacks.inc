#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    mysql_query_file(SQL_Connection, "tables/"TABLE_USERS".sql", false);
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerConnect(playerid)
{
    TogglePlayerSpectating(playerid, true);
    GetPlayerName(playerid, Player[playerid][Name], MAX_PLAYER_NAME);
    if ( !Player[playerid][Login] )
    {
        Player[playerid][Login] = true;

        new query[128];
        mysql_format(SQL_Connection, query, sizeof(query), "SELECT id FROM "TABLE_USERS" WHERE `name`='%e';", Player[playerid][Name]);
        mysql_tquery(SQL_Connection, query, "OnPlayerCheckAccount", "i", playerid);
        return Y_HOOKS_CONTINUE_RETURN_1;
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if ( Player[playerid][Logged] )
    {
        new query[1024];

        GetPlayerHealth(playerid, Player[playerid][Health]);
        GetPlayerArmour(playerid, Player[playerid][Armour]);
        GetPlayerPos(playerid, Player[playerid][Spawn][X], Player[playerid][Spawn][Y], Player[playerid][Spawn][Z]);
        GetPlayerFacingAngle(playerid, Player[playerid][Spawn][A]);

        mysql_format(SQL_Connection, query, sizeof(query),
            "UPDATE "TABLE_USERS" SET `health`='%.2f',`armour`='%.2f',`spawn_x`='%.2f',`spawn_y`='%.2f',`spawn_z`='%.2f',`spawn_a`='%.2f',`interior`='%d',`world`='%d' WHERE `id`='%d';",
            Player[playerid][Health], Player[playerid][Armour],
            Player[playerid][Spawn][X],
            Player[playerid][Spawn][Y],
            Player[playerid][Spawn][Z],
            Player[playerid][Spawn][A],
            GetPlayerInterior(playerid),
            GetPlayerVirtualWorld(playerid),
            Player[playerid][ID]
        );
        mysql_tquery(SQL_Connection, query);

        printf("[MP:RP] Salvando conta do jogador %s.", Player[playerid][Name]);
        if ( funcidx("OnPlayerSave") != -1 )
        {
            CallLocalFunction("OnPlayerSave", "i", playerid);
        }

        // destruir veiculo admin, caso haja algum criado pelo jogador
        if ( IsValidVehicle(Player[playerid][vAdmin]) )
        {
            DestroyVehicle(Player[playerid][vAdmin]);
            Player[playerid][vAdmin] = INVALID_VEHICLE_ID;
        }
    }
    new reset[E_PLAYER_DATA];
    Player[playerid] = reset;
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerRequestClass(playerid)
{
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerRequestSpawn(playerid)
{
    if ( Player[playerid][Logged] )return Y_HOOKS_CONTINUE_RETURN_1;
    return Y_HOOKS_BREAK_RETURN_0;
}

hook OnPlayerText(playerid, text[])
{
    return Y_HOOKS_BREAK_RETURN_0;
}

hook OnPlayerClickTextDraw(playerid, Text:clickedid)
{
    if ( Player[playerid][Login] ) return Y_HOOKS_CONTINUE_RETURN_1;

    if ( clickedid == INVALID_TEXT_DRAW )
    {
        Player:HideRegister(playerid);
        SendClientMessage(playerid, COLOR_DARK, "Você foi desconectado do servidor por não efetuar o registro.");
        return Y_HOOKS_CONTINUE_RETURN_1, Kick(playerid);
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
    if ( Dialog_IsOpened(playerid) ) return Y_HOOKS_CONTINUE_RETURN_1;

    // ================================================== [ REGISTRO ] ================================================== //

    if ( playertextid == PTD_Register[playerid][13] ) // email
    {
        Dialog_Show(playerid, PLAYER_REGISTER_EMAIL, DIALOG_STYLE_INPUT, "{"COLOR_BLUE_EMBED"}EMAIL", "{ffffff}Digite seu email válido para cadastrar em sua conta.", "Confirmar", "Fechar");
        return Y_HOOKS_BREAK_RETURN_1;
    }
    else if ( playertextid == PTD_Register[playerid][16] ) // senha
    {
        Dialog_Show(playerid, PLAYER_REGISTER_PASSWORD, DIALOG_STYLE_PASSWORD, "{"COLOR_BLUE_EMBED"}SENHA", "{ffffff}Digite sua senha abaixo", "Confirmar", "Fechar");
        return Y_HOOKS_BREAK_RETURN_1;
    }

    else if ( playertextid == PTD_Register[playerid][20] ) // criar conta
    {
        if ( !IsValidEmail(Player[playerid][Email]) ) {
            NT:Send(playerid, NT_TYPE_ERROR, "Você precisa digitar um email válido!");
            return Y_HOOKS_BREAK_RETURN_1;
        }

        if ( !IsValidName(Player[playerid][Name]) ) {
            NT:Send(playerid, NT_TYPE_ERROR, "Você precisa digitar um nome válido, com Nome e Sobrenome.~n~Exemplo: Nome_Sobrenome");
            return Y_HOOKS_BREAK_RETURN_1;
        }

        if ( strlen(Player[playerid][Password]) > 8 ) {
            NT:Send(playerid, NT_TYPE_ERROR, "Você precisa digitar uma senha de pelo menos 8 caracteres.");
            return Y_HOOKS_BREAK_RETURN_0;
        }

        if ( GetPVarInt(playerid, "locked") > gettime()) {
            return Y_HOOKS_BREAK_RETURN_0;
        }

        SetPVarInt(playerid, "locked", gettime() + 2);
        NT:Send(playerid, NT_TYPE_INFO, "Estamos criando sua conta, aguarde...");
        bcrypt_hash(Player[playerid][Password], BCRYPT_COST, "OnPasswordHashed", "d", playerid);
        return Y_HOOKS_BREAK_RETURN_1;
    }


    // ================================================== [ LOGIN ] ================================================== //
    
    else if ( playertextid == PTD_Login[playerid][13] ) // senha
    {
        Dialog_Show(playerid, LOGIN_PASSWORD, DIALOG_STYLE_PASSWORD, "{"COLOR_DARK_EMBED"}SENHA", "{"COLOR_WHITE_EMBED"}Digite sua senha abaixo.", "Confirmar", "Fechar");
        return Y_HOOKS_BREAK_RETURN_1;
    }

    else if ( playertextid == PTD_Login[playerid][17] ) // conectar
    {
        if ( !IsValidName(Player[playerid][Name]) )
        {
            NT:Send(playerid, NT_TYPE_ERROR, "Nome inválido.");
            return Y_HOOKS_BREAK_RETURN_0;
        }

        if ( isnull(Player[playerid][Password]) )
        {
            NT:Send(playerid, NT_TYPE_ERROR, "Senha inválida.");
            return Y_HOOKS_BREAK_RETURN_0;
        }
        new query[255];
        mysql_format(SQL_Connection, query, sizeof(query), "SELECT password FROM "TABLE_USERS" WHERE `name`='%e';", Player[playerid][Name]);
        new Cache:cache = mysql_query(SQL_Connection, query, true), pass_hash[BCRYPT_HASH_LENGTH];
        if ( cache_num_rows() )
        {
            cache_get_value_name(0, "password", pass_hash);
        }
        cache_delete(cache);
        bcrypt_check(Player[playerid][Password], pass_hash, "OnPasswordVerify", "d", playerid);
        return Y_HOOKS_BREAK_RETURN_1;
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

public OnPlayerCheckAccount(playerid)
{
    CleanChat(playerid);

    SendClientMessage(playerid, 0xFFBB00FF, "» Bem vindo ao servidor Metropolitan Roleplay.");
    SelectTextDraw(playerid, 0xFFBB00FF);
    switch(cache_num_rows())
    {
        case 0: // registrar
        {
            Player:ShowRegister(playerid);
            return Y_HOOKS_CONTINUE_RETURN_1;
        }
        case 1: // login
        {
            Player:ShowLogin(playerid);
            return Y_HOOKS_CONTINUE_RETURN_1;
        }
    }
    return Y_HOOKS_BREAK_RETURN_0;
}

public OnPasswordHashed(playerid)
{
    new hash[BCRYPT_HASH_LENGTH], query[512];
	bcrypt_get_hash(hash);
    mysql_format(SQL_Connection, query, sizeof(query), "INSERT INTO "TABLE_USERS" (`name`,`email`,`password`)VALUES('%s','%e','%e');", Player[playerid][Name], Player[playerid][Email], hash);
    mysql_tquery(SQL_Connection, query, "OnPlayerRegister", "i", playerid);
    return Y_HOOKS_BREAK_RETURN_1;
}

public OnPasswordVerify(playerid)
{
    switch(_:bcrypt_is_equal())
    {
        case 1:
        {
            new query[255];
            mysql_format(SQL_Connection, query, sizeof(query), "SELECT *, DATE_FORMAT(`updated_at`, '%%d/%%m/%%Y - %%T') as last_login FROM "TABLE_USERS" WHERE `name`='%e';", Player[playerid][Name]);
            mysql_tquery(SQL_Connection, query, "OnPlayerAttempAuth", "i", playerid);
            return 1;
        }
    }
    NT:Send(playerid, NT_TYPE_ERROR, "Senha errada!");
    return 0;
}

public OnPlayerRegister(playerid)
{
    new id = cache_insert_id();
    if ( id == 0 )
    {
        NT:Send(playerid, NT_TYPE_ERROR, "Não foi possível criar sua conta, por favor tente mais tarde.");
        return Y_HOOKS_BREAK_RETURN_1;
    }
    
    Player:HideRegister(playerid);
    Player:ShowLogin(playerid);

    NT:Send(playerid, NT_TYPE_SUCCESS, "Conta criada com sucesso!");
    return Y_HOOKS_CONTINUE_RETURN_1;
}

public OnPlayerAttempAuth(playerid)
{
    if ( !cache_num_rows() )
    {
        NT:Send(playerid, NT_TYPE_ERROR, "Conta não encontrada.");
        return Y_HOOKS_BREAK_RETURN_0;
    }
    Player[playerid][Logged] = true;

    CancelSelectTextDraw(playerid);
    Player:HideLogin(playerid);
    

    // pegar informações do banco de dados.
    cache_get_value_name_int(0, "id", Player[playerid][ID]);
    cache_get_value_name(0, "name", Player[playerid][Name], MAX_PLAYER_NAME);
    cache_get_value_name(0, "email", Player[playerid][Email], MAX_PLAYER_EMAIL);
    cache_get_value_name(0, "password", Player[playerid][Password], MAX_PLAYER_PASSWORD);
    cache_get_value_name_float(0, "spawn_x", Player[playerid][Spawn][X]);
    cache_get_value_name_float(0, "spawn_y", Player[playerid][Spawn][Y]);
    cache_get_value_name_float(0, "spawn_z", Player[playerid][Spawn][Z]);
    cache_get_value_name_float(0, "spawn_a", Player[playerid][Spawn][A]);
    cache_get_value_name_int(0, "interior", Player[playerid][Interior]);
    cache_get_value_name_int(0, "world", Player[playerid][World]);
    cache_get_value_name_float(0, "health", Player[playerid][Health]);
    cache_get_value_name_float(0, "armour", Player[playerid][Armour]);
    cache_get_value_name_int(0, "admin", Player[playerid][Admin]);
    cache_get_value_name(0, "last_login", Player[playerid][LastLogin], 30);

    // tirar o jogador de modo spectador.
    TogglePlayerSpectating(playerid, false);
    // setar informações
    SetSpawnInfo(playerid, NO_TEAM, Player[playerid][Skin], Player[playerid][Spawn][X], Player[playerid][Spawn][Y], Player[playerid][Spawn][Z], Player[playerid][Spawn][A], 0, 0, 0, 0, 0, 0);
    SetPlayerInterior(playerid, Player[playerid][Interior]);
    SetPlayerVirtualWorld(playerid, Player[playerid][World]);
    SetPlayerHealth(playerid, Player[playerid][Health]);
    SetPlayerArmour(playerid, Player[playerid][Armour]);
    Player[playerid][vAdmin] = INVALID_VEHICLE_ID;

    // spawnar o jogador.
    SpawnPlayer(playerid); 
    // mensagem de sucesso!
    
    CleanChat(playerid);
    SendClientMessagef(playerid, COLOR_BLUE, ""SERVER_MESSAGE_TAG" {"COLOR_WHITE_EMBED"}Bem vindo, %s, seu último login foi em {"COLOR_RED_EMBED"}%s{"COLOR_WHITE_EMBED"}.", Player[playerid][Name], Player[playerid][LastLogin]);
    return Y_HOOKS_BREAK_RETURN_1;
}
