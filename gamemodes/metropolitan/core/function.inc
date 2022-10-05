stock IsValidName(const name[])
{
    if ( strlen(name) > MAX_PLAYER_NAME )return 0;

    if ( name[0] < 'A' || name[0] > 'Z' )return 0;

    new underlines = 0;
    for(new i, len = strlen(name); i < len; i++){
        if ( name[i] == '_' && (name[i + 1] < 'A' || name[i + 1] > 'Z') )return 0;
        if ( name[i] == '_') ++underlines;
    }

    if ( underlines > 1 )return 0;
    return 1;
}

stock IsValidEmail(const email[])
{
    if (
        strfind(email, "@gmail.com") == -1 &&
        strfind(email, "@hotmail.com") == -1 &&
        strfind(email, "@bol.com.br") == -1 &&
        strfind(email, "@outlook.com") == -1
    )return 0;

    return 1;
}

stock CleanChat(playerid=INVALID_PLAYER_ID, lines=20)
{
    if ( playerid == INVALID_PLAYER_ID ) {
        for(new i; i < lines; i++){
            SendClientMessageToAll(0x000000FF, " ");
        }
    }else{
        for(new i; i < lines; i++){
            SendClientMessage(playerid, 0x000000FF, " ");
        }
    }
    return 1;
}