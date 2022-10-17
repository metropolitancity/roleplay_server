Dialog:INPUT_DISCORD_ID(playerid, response, listitem, inputtext[])
{
    if ( response )
    {
        if ( !IsNumeric(inputtext) )
        {
            NT:Send(playerid, NT_TYPE_ERROR, "Digite um ID Discord válido.");
            return 0;
        }
        format(InputDiscordID[playerid], 32, inputtext);
        PlayerTextDrawSetString(playerid, PTD_DiscordIntegration[playerid][5], inputtext);
        return 1;
    }
    return 0;
}