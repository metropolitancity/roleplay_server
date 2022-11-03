#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    mysql_query_file(SQL_Connection, "tables/"TABLE_USERS".sql", false);
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerConnect(playerid)
{
    ShowServerLogo(playerid);
    SetPlayerColor(playerid, 0xFFFFFFFF);
    TogglePlayerSpectating(playerid, true);
    GetPlayerName(playerid, Player[playerid][Name], MAX_PLAYER_NAME);

    if ( !IsValidName(Player[playerid][Name]) ) {
        NT:Send(playerid, NT_TYPE_ERROR, "Nome inválido / Anti-RP.");
        NT:Send(playerid, NT_TYPE_ERROR, "Use: Nome_Sobrenome para definir o nome do personagem.");
        CleanChat();
        Player:Kick(playerid, 200);
        return Y_HOOKS_BREAK_RETURN_1;
    }
    
    // camuflar jogador.
    new pname[MAX_PLAYER_NAME];
    format(pname, MAX_PLAYER_NAME, "player_%03d", playerid);
    SetPlayerName(playerid, pname);

    if ( !Player[playerid][Login] )
    {
        Player[playerid][Login] = true;

        new query[128];
        mysql_format(SQL_Connection, query, sizeof(query), "SELECT id FROM "TABLE_USERS" WHERE `name`='%e' OR `id`='%d';", Player[playerid][Name], Player[playerid][Name]);
        mysql_tquery(SQL_Connection, query, "OnPlayerCheckAccount", "i", playerid);
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    HideServerLogo(playerid);
    if ( Player:Logged(playerid) )
    {
        printf("[MP:RP] Salvando conta do jogador %s.", Player[playerid][Name]);

        new query[1024];

        GetPlayerHealth(playerid, Player[playerid][Health]);
        GetPlayerArmour(playerid, Player[playerid][Armour]);
        GetPlayerPos(playerid, Player[playerid][Spawn][X], Player[playerid][Spawn][Y], Player[playerid][Spawn][Z]);
        GetPlayerFacingAngle(playerid, Player[playerid][Spawn][A]);

        mysql_format(SQL_Connection, query, sizeof(query),
            "UPDATE "TABLE_USERS" SET `health`='%.2f',`armour`='%.2f',`spawn_x`='%.2f',`spawn_y`='%.2f',`spawn_z`='%.2f',`spawn_a`='%.2f',`interior`='%d',`world`='%d',`hunger`='%.3f',`thirst`='%.3f',`sleep`='%.3f' WHERE `id`='%d';",
            Player[playerid][Health], Player[playerid][Armour],
            Player[playerid][Spawn][X],
            Player[playerid][Spawn][Y],
            Player[playerid][Spawn][Z],
            Player[playerid][Spawn][A],
            GetPlayerInterior(playerid),
            GetPlayerVirtualWorld(playerid),
            Player[playerid][Hunger],
            Player[playerid][Thirst],
            Player[playerid][Sleep],
            Player[playerid][ID]
        );
        mysql_tquery(SQL_Connection, query);

        if ( funcidx("OnPlayerSave") != -1 ) {
            OnPlayerSave(playerid);
        }

        // destruir veiculo admin, caso haja algum criado pelo jogador
        if ( IsValidVehicle(Player[playerid][vAdmin]) ) {
            DestroyVehicle(Player[playerid][vAdmin]);
            Player[playerid][vAdmin] = INVALID_VEHICLE_ID;
        }
        SetPlayerName(playerid, Player[playerid][Name]);
    }

    new reset[E_PLAYER_DATA];
    Player[playerid] = reset;
    return Y_HOOKS_CONTINUE_RETURN_1;
}

public OnPlayerSave(playerid)
{
    return 1;
}

hook OnPlayerRequestClass(playerid)
{
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerRequestSpawn(playerid)
{
    if ( Player:Logged(playerid) )return Y_HOOKS_BREAK_RETURN_1;
    return Y_HOOKS_BREAK_RETURN_0;
}

hook OnPlayerSpawn(playerid)
{
    if ( !Player[playerid][Spawned] )
    {
        Player[playerid][Spawned] = true;
        Player:CreateLabel(playerid);
        if ( funcidx("OnPlayerLogged") != -1 ) {
            CallLocalFunction("OnPlayerLogged", "i", playerid);
        }
        // cef_create_browser(playerid, 0, "https://google.com", false, true);
        return Y_HOOKS_CONTINUE_RETURN_1;
    }
    SetPlayerSkin(playerid, GetPlayerSkin(playerid));
    return Y_HOOKS_CONTINUE_RETURN_1;
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
        return Y_HOOKS_CONTINUE_RETURN_1, Player:Kick(playerid);
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
            CleanChat(playerid);
            SendClientMessage(playerid, COLOR_RED, "* {"COLOR_WHITE_EMBED"}Você precisa digitar um email válido!");
            return Y_HOOKS_BREAK_RETURN_1;
        }

        if ( !IsValidName(Player[playerid][Name]) ) {
            CleanChat(playerid);
            SendClientMessage(playerid, COLOR_RED, "* {"COLOR_WHITE_EMBED"}Você precisa digitar um nome válido, com Nome e Sobrenome.");
            SendClientMessage(playerid, COLOR_RED, "* {"COLOR_WHITE_EMBED"}Exemplo: Guilherme_Domingues.");
            return Y_HOOKS_BREAK_RETURN_1;
        }

        if ( strlen(Player[playerid][Password]) > 8 ) {
            CleanChat(playerid);
            SendClientMessage(playerid, COLOR_RED, "* {"COLOR_WHITE_EMBED"}Você precisa digitar uma senha de pelo menos 8 caracteres.");
            return Y_HOOKS_BREAK_RETURN_0;
        }

        if ( GetPVarInt(playerid, "locked") > gettime()) {
            return Y_HOOKS_BREAK_RETURN_0;
        }

        SetPVarInt(playerid, "locked", gettime() + 2);
        CleanChat(playerid);
        SendClientMessage(playerid, COLOR_BLUE, "» {"COLOR_WHITE_EMBED"}aguarde...");
        bcrypt_hash(Player[playerid][Password], BCRYPT_COST, "OnPasswordHashed", "i", playerid);
        return Y_HOOKS_BREAK_RETURN_1;
    }

    else if ( playertextid == PTD_Gender[playerid][3] ) // anterior
    {
        new select = GetPVarInt(playerid, "SkinSelected");
        --select;

        if ( select < 0 )select = sizeof(SkinsSelect) - 1;

        SetPVarInt(playerid, "SkinSelected", select);
        PlayerTextDrawSetPreviewModel(playerid, PTD_Gender[playerid][5], SkinsSelect[select][0]);
        PlayerTextDrawShow(playerid, PTD_Gender[playerid][5]);
        va_PlayerTextDrawSetString(playerid, PTD_Gender[playerid][6], "Sexo: %s", SkinsSelect[select][1] == GENDER_MALE ? ("~b~~h~~h~Masculino") : ("~r~~h~~h~Feminino"));        
        return Y_HOOKS_BREAK_RETURN_1;
    }
    else if ( playertextid == PTD_Gender[playerid][4] ) // próximo
    {
        new select = GetPVarInt(playerid, "SkinSelected");
        ++select;
        if ( select > sizeof(SkinsSelect) - 1 )select = 0;

        SetPVarInt(playerid, "SkinSelected", select);
        PlayerTextDrawSetPreviewModel(playerid, PTD_Gender[playerid][5], SkinsSelect[select][0]);
        PlayerTextDrawShow(playerid, PTD_Gender[playerid][5]);
        va_PlayerTextDrawSetString(playerid, PTD_Gender[playerid][6], "Sexo: %s", SkinsSelect[select][1] == GENDER_MALE ? ("~b~~h~~h~Masculino") : ("~r~~h~~h~Feminino"));        
        return Y_HOOKS_BREAK_RETURN_1;
    }

    else if ( playertextid == PTD_Gender[playerid][7] ) // continua
    {
        new query[512], select = GetPVarInt(playerid, "SkinSelected");
        DeletePVar(playerid, "SkinSelected");

        mysql_format(SQL_Connection, query, sizeof(query), "INSERT INTO "TABLE_USERS" (`name`,`email`,`password`,`spawn_x`,`spawn_y`,`spawn_z`,`spawn_a`,`interior`,`world`,`skin`,`gender`)VALUES('%s','%e','%e','1676.2700','1459.1677','10.7745','97.8218','0','0','%d','%d');", Player[playerid][Name], Player[playerid][Email], Player[playerid][Password], SkinsSelect[select][0], SkinsSelect[select][1]);
        mysql_tquery(SQL_Connection, query, "OnPlayerRegister", "i", playerid);
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
            SendClientMessage(playerid, COLOR_RED, "* {"COLOR_WHITE_EMBED"}Nome anti-rp, você precisa escolher um Nome_Sobrenome.");
            return Y_HOOKS_BREAK_RETURN_0;
        }

        if ( isnull(Player[playerid][Password]) )
        {
            SendClientMessage(playerid, COLOR_RED, "* {"COLOR_WHITE_EMBED"}Senha inválida, você precisa digitar uma senha.");
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

hook OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ)
{
    if ( Player:GetAdminWorking(playerid) )
    {
        if ( Player:GetAdmin(playerid) >= MODERATOR )
        {
            if ( IsPlayerInAnyVehicle(playerid) ) {
                new vehicleid = GetPlayerVehicleID(playerid);
                SetVehiclePos(vehicleid, fX, fY, fZ);
                LinkVehicleToInterior(vehicleid, 0);
                SetVehicleVirtualWorld(vehicleid, 0);
            } else {
                SetPlayerPos(playerid, fX, fY, fZ);
            }
            
            SetPlayerInterior(playerid, 0);
            SetPlayerVirtualWorld(playerid, 0);
            SetCameraBehindPlayer(playerid);
            NT:Send(playerid, NT_TYPE_INFO, "Você foi teleportado até o ponto marcado.");
            return Y_HOOKS_BREAK_RETURN_1;
        }
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ)
{
    if ( hittype == BULLET_HIT_TYPE_PLAYER )
    {
        if ( Player:GetAdmin(hitid) >= HELPER && Player:GetAdminWorking(hitid) )
        {
            CleanChat(playerid); // limpar chat
            Player:GiveWarningKick(playerid, 1);

            SendClientMessagef(playerid, COLOR_RED, "%02d/03 Você não pode disparar contra um anjo.", Player:GetWarningKick(playerid));
            if ( Player:GetWarningKick(playerid) >= 3 )
            {
                SendClientMessagef(playerid, COLOR_RED, "Você foi kickado do servidor por acumular muitos avisos.");
                Player:Kick(playerid);
            }
            return Y_HOOKS_CONTINUE_RETURN_0;
        }
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
    new hash[BCRYPT_HASH_LENGTH];
	bcrypt_get_hash(hash);
    
    CleanChat(playerid);
    SendClientMessage(playerid, COLOR_BLUE, "» {"COLOR_WHITE_EMBED"}Agora escolha a skin do seu personagem.");

    format(Player[playerid][Password], MAX_PLAYER_PASSWORD, hash);
    Player:HideRegister(playerid);
    Player:ShowGender(playerid);
    return Y_HOOKS_BREAK_RETURN_1;
}

public OnPasswordVerify(playerid)
{
    switch(_:bcrypt_is_equal())
    {
        case 1:
        {
            new query[255];
            mysql_format(SQL_Connection, query, sizeof(query), "SELECT *, DATE_FORMAT(`updated_at`, '%%d/%%m/%%Y - %%T') as last_login FROM "TABLE_USERS" WHERE `name`='%e' OR `id`='%d' LIMIT 1;", Player[playerid][Name], Player[playerid][Name]);
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
    
    Player:HideGender(playerid);
    Player:ShowLogin(playerid);

    CleanChat(playerid);
    SendClientMessage(playerid, COLOR_BLUE, "» {"COLOR_WHITE_EMBED"}Conta criada com sucesso!");
    return Y_HOOKS_CONTINUE_RETURN_1;
}

public OnPlayerAttempAuth(playerid)
{
    if ( !cache_num_rows() )
    {
        NT:Send(playerid, NT_TYPE_ERROR, "Conta não encontrada.");
        return Y_HOOKS_BREAK_RETURN_0;
    }

    CancelSelectTextDraw(playerid);
    Player:HideLogin(playerid);
    
    // pegar informações do banco de dados.
    cache_get_value_name_int(0, "id", Player[playerid][ID]);
    cache_get_value_name(0, "name", Player[playerid][Name], MAX_PLAYER_NAME);
    cache_get_value_name(0, "email", Player[playerid][Email], MAX_PLAYER_EMAIL);
    cache_get_value_name(0, "password", Player[playerid][Password], MAX_PLAYER_PASSWORD);
    cache_get_value_name_int(0, "skin", Player[playerid][Skin]);
    cache_get_value_name_int(0, "gender", Player[playerid][Gender]);
    cache_get_value_name_float(0, "spawn_x", Player[playerid][Spawn][X]);
    cache_get_value_name_float(0, "spawn_y", Player[playerid][Spawn][Y]);
    cache_get_value_name_float(0, "spawn_z", Player[playerid][Spawn][Z]);
    cache_get_value_name_float(0, "spawn_a", Player[playerid][Spawn][A]);
    cache_get_value_name_int(0, "interior", Player[playerid][Interior]);
    cache_get_value_name_int(0, "world", Player[playerid][World]);
    cache_get_value_name_float(0, "health", Player[playerid][Health]);
    cache_get_value_name_float(0, "armour", Player[playerid][Armour]);
    cache_get_value_name_int(0, "admin", Player[playerid][Admin]);
    cache_get_value_name_int(0, "discord", Player[playerid][Discord]);
    cache_get_value_name(0, "discord_id", Player[playerid][DiscordID], 32);
    cache_get_value_name(0, "last_login", Player[playerid][LastLogin], 30);
    cache_get_value_name_float(0, "hunger", Player[playerid][Hunger]);
    cache_get_value_name_float(0, "thirst", Player[playerid][Thirst]);
    cache_get_value_name_float(0, "sleep", Player[playerid][Sleep]);

    /*
        Desativado
    if ( !Player[playerid][Discord] )
    {
        if ( !isnull(Player[playerid][DiscordID]) )
        {
            CleanChat(playerid);
            SendClientMessage(playerid, COLOR_RED, "Já foi enviado uma mensagem no privado do seu discord, verifique para prosseguir com a integração.");
            Player:Kick(playerid);
            return Y_HOOKS_BREAK_RETURN_1;
        }

        NT:Send(playerid, NT_TYPE_ERROR, "Você precisa adicionar seu discord para jogador em nosso servidor.");
        DC:ShowIntegration(playerid);
        return Y_HOOKS_BREAK_RETURN_1;
    }*/

    // tirar o jogador de modo spectador.
    TogglePlayerSpectating(playerid, false);
    
    // setar informações
    SetSpawnInfo(playerid, NO_TEAM, Player[playerid][Skin], Player[playerid][Spawn][X], Player[playerid][Spawn][Y], Player[playerid][Spawn][Z], Player[playerid][Spawn][A], 0, 0, 0, 0, 0, 0);
    SetPlayerInterior(playerid, Player[playerid][Interior]);
    SetPlayerVirtualWorld(playerid, Player[playerid][World]);
    SetPlayerHealth(playerid, Player[playerid][Health]);
    SetPlayerArmour(playerid, Player[playerid][Armour]);
    Player[playerid][vAdmin] = INVALID_VEHICLE_ID;

    new pName[MAX_PLAYER_NAME];
    format(pName, MAX_PLAYER_NAME, "%03d", Player[playerid][ID]);
    SetPlayerName(playerid, pName);
    
    // spawnar o jogador.
    SpawnPlayer(playerid);

    // mensagem de sucesso!
    CleanChat(playerid);
    SendClientMessagef(playerid, COLOR_BLUE, ""SERVER_MESSAGE_TAG" {"COLOR_WHITE_EMBED"}Bem vindo, %s, seu último login foi em {"COLOR_RED_EMBED"}%s{"COLOR_WHITE_EMBED"}.", Player[playerid][Name], Player[playerid][LastLogin]);
    
    Player[playerid][Logged] = true;
    return Y_HOOKS_BREAK_RETURN_1;
}