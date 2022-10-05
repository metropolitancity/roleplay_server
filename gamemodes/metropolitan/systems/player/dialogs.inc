Dialog:PLAYER_REGISTER_EMAIL(playerid, response, listitem, inputtext[])
{
    if ( response )
    {
        if ( isnull(inputtext) )
        {
            NT:Send(playerid, NT_TYPE_ERROR, "Erro", "Você precisa digitar um email válido.");
            return 0;
        }

        format(Player[playerid][Email], MAX_PLAYER_EMAIL, inputtext);
        PlayerTextDrawSetString(playerid, PTD_Register[playerid][13], inputtext);
        return 1;
    }
    return 0;
}

Dialog:PLAYER_REGISTER_PASSWORD(playerid, response, listitem, inputtext[])
{
    if ( response )
    {
        if ( isnull(inputtext) )
        {
            NT:Send(playerid, NT_TYPE_ERROR, "Você precisa digitar uma senha de no minimo 8 caracteres.");
            return 0;
        }

        format(Player[playerid][Password], MAX_PLAYER_PASSWORD, inputtext);
        new password[MAX_PLAYER_PASSWORD];
        for(new i; i < strlen(inputtext); i++){
            password[i] = ']';
        }
        PlayerTextDrawSetString(playerid, PTD_Register[playerid][16], password);
        return 1;
    }
    return 0;
}


// LOGIN
Dialog:LOGIN_PASSWORD(playerid, response, listitem, inputtext[])
{
    if ( response )
    {
        if ( isnull(inputtext) )
        {
            NT:Send(playerid, NT_TYPE_ERROR, "Digite uma senha!");
            return 0;
        }

        format(Player[playerid][Password], MAX_PLAYER_PASSWORD, inputtext);
        new password[MAX_PLAYER_PASSWORD];
        for(new i; i < strlen(inputtext); i++){
            password[i] = ']';
        }
        PlayerTextDrawSetString(playerid, PTD_Login[playerid][13], password);
        return 1;
    }
    return 0;
}