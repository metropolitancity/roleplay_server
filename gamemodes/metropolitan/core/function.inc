stock IsValidName(const name[])
{
    if ( strlen(name) > MAX_PLAYER_NAME )return 0;

    if ( name[0] < 'A' || name[0] > 'Z' )return 0;

    new underlines = 0;
    for(new i, len = strlen(name); i < len; i++){
        if ( name[i] == '_' && (name[i + 1] < 'A' || name[i + 1] > 'Z') )return 0;
        if ( name[i] == '_') ++underlines;
    }

    if ( underlines != 1 )return 0;

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

stock Player:Kick(playerid, ms=100)
{
    if ( !IsPlayerConnected(playerid) )return 0;
    ms = ms <= 0 ? 1 : ms;
    SetTimerEx("OnPlayerKick", ms, false, "i", playerid);
    return 1;
}

stock randomstring(strReturn[], strLen = sizeof(strReturn) ) // by RyDeR | link = http://forum.sa-mp.com/showthread.php?t=276913
{
	new 
		strDest[128];

	while(strLen--)
		strDest[strLen] = random(2) ? (random(26) + (random(3) ? 'A' : 'a')) : (random(10) + '0');

    format(strReturn, strLen, strDest);
}

forward OnPlayerKick(playerid);
public OnPlayerKick(playerid)
{
    if ( !IsPlayerConnected(playerid) )return 0;
    return Kick(playerid), 1;
}