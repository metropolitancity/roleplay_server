public NT:Destroy(playerid, nt_id)
{
    if ( !Notification[playerid][nt_id][Showed] ) return 0;
    Notification[playerid][nt_id][Showed] = false;
    for(new i; i < sizeof(PTD_Notification[][]); i++)
    {
        if ( IsValidPlayerTextDraw(playerid, PTD_Notification[playerid][nt_id][i]) )
        {
            PlayerTextDrawDestroy(playerid, PTD_Notification[playerid][nt_id][i]);
            PTD_Notification[playerid][nt_id][i] = INVALID_PLAYER_TEXT_DRAW;
        }
    }
    return 1;
}