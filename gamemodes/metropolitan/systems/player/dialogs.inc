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


Dialog:PLAYER_GPS(playerid, response, listitem, inputtext[])
{
    if ( response )
    {
        switch(listitem)
        {
            case 0: // locais públicos
            {
                new str[1024 * 2];
                strcat(str, "Local\tDistancia\n");
                foreach(new i: Property) {
                    format(str, sizeof(str), "%s{"COLOR_RED_EMBED"}» {C1C1C1}%s\t{"COLOR_RED_EMBED"}%.2f\n", str, Property[i][Name], GetPlayerDistanceFromPoint(playerid, Property[i][EntranceX], Property[i][EntranceY], Property[i][EntranceZ]));
                }
                Dialog_Show(playerid, PLAYER_GPS_PROPERTYS, DIALOG_STYLE_TABLIST_HEADERS, "GPS » Locais Públicos", str, "Marcar", "Voltar");
                return 1;
            }
        }
        return 1;
    }
    return 0;
}

Dialog:PLAYER_GPS_PROPERTYS(playerid, response, listitem, inputtext[])
{
    if ( response )
    {
        Player:MarkCP(playerid, Property[listitem][EntranceX], Property[listitem][EntranceY], Property[listitem][EntranceZ], 1.0);
        NT:Send(playerid, NT_TYPE_SUCCESS, "~b~~h~~h~~h~%s ~w~marcado no seu radar.", Property[listitem][Name]);
        return 1;
    }
    return 0;
}