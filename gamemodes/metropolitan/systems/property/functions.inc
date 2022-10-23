IsPlayerInPropertyEntrance(playerid)
{
    foreach(new i: Property)
    {
        if ( IsPlayerInRangeOfPoint(playerid, 2.0, Property[i][EntranceX], Property[i][EntranceY], Property[i][EntranceZ]) )
        {
            return true;
        }
    }
    return false;
}

