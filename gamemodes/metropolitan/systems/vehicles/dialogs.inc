Dialog:PANEL_VEHICLE(playerid, response, listitem, inputtext[])
{
    if ( response )
    {
        switch(listitem)
        {
            case 0: callcmd::motor(playerid);
            case 1: callcmd::farol(playerid);
        }
        return 1;
    }
    return 0;
}