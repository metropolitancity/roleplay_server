stock NT:Send(playerid, E_NOTIFICATION_TYPE:type, const message[], va_args<>)
{
    nt_init:
    for(new i; i < MAX_PLAYER_NOTIFICATION; i++)
    {
        if ( Notification[playerid][i][Showed] )continue;
        Notification[playerid][i][Showed] = true;
        
        new color, str_type[32], f_message[100];
        switch(type)
        {
            case NT_TYPE_ERROR:   color = 0xFF6347FF, format(str_type, sizeof(str_type), "ld_chat:thumbdn");
            case NT_TYPE_INFO:    color = 0xEEDC82FF, format(str_type, sizeof(str_type), "ld_chat:badchat");
            case NT_TYPE_SUCCESS: color = 0x6495EDFF, format(str_type, sizeof(str_type), "ld_chat:thumbup");
        }

        PTD_Notification[playerid][i][0] = CreatePlayerTextDraw(playerid, NotificationPosition[i][0], NotificationPosition[i][1], "LD_SPAC:white");
        PlayerTextDrawLetterSize(playerid, PTD_Notification[playerid][i][0], 0.000000, 0.000000);
        PlayerTextDrawTextSize(playerid, PTD_Notification[playerid][i][0], 144.430000, 40.000000);
        PlayerTextDrawAlignment(playerid, PTD_Notification[playerid][i][0], 1);
        PlayerTextDrawColor(playerid, PTD_Notification[playerid][i][0], 303174399);
        PlayerTextDrawSetShadow(playerid, PTD_Notification[playerid][i][0], 0);
        PlayerTextDrawSetOutline(playerid, PTD_Notification[playerid][i][0], 0);
        PlayerTextDrawBackgroundColor(playerid, PTD_Notification[playerid][i][0], 255);
        PlayerTextDrawFont(playerid, PTD_Notification[playerid][i][0], 4);
        PlayerTextDrawSetProportional(playerid, PTD_Notification[playerid][i][0], 0);
        PlayerTextDrawSetShadow(playerid, PTD_Notification[playerid][i][0], 0);

        PTD_Notification[playerid][i][1] = CreatePlayerTextDraw(playerid, NotificationPosition[i][0] + 2.0, NotificationPosition[i][1] + 13.0, str_type);
        PlayerTextDrawLetterSize(playerid, PTD_Notification[playerid][i][1], 0.000000, 0.000000);
        PlayerTextDrawTextSize(playerid, PTD_Notification[playerid][i][1], 10.000000, 10.000000);
        PlayerTextDrawAlignment(playerid, PTD_Notification[playerid][i][1], 1);
        PlayerTextDrawColor(playerid, PTD_Notification[playerid][i][1], -1);
        PlayerTextDrawSetShadow(playerid, PTD_Notification[playerid][i][1], 0);
        PlayerTextDrawSetOutline(playerid, PTD_Notification[playerid][i][1], 0);
        PlayerTextDrawBackgroundColor(playerid, PTD_Notification[playerid][i][1], 255);
        PlayerTextDrawFont(playerid, PTD_Notification[playerid][i][1], 4);
        PlayerTextDrawSetProportional(playerid, PTD_Notification[playerid][i][1], 0);
        PlayerTextDrawSetShadow(playerid, PTD_Notification[playerid][i][1], 0);

        va_format(f_message, sizeof(f_message), message, va_start<3>);
        PTD_Notification[playerid][i][2] = CreatePlayerTextDraw(playerid, NotificationPosition[i][0] + 15.0, NotificationPosition[i][1] + 13.0, f_message);
        PlayerTextDrawLetterSize(playerid, PTD_Notification[playerid][i][2], 0.196204, 1.002497);
        PlayerTextDrawTextSize(playerid, PTD_Notification[playerid][i][2], 630.840454, 0.000000);
        PlayerTextDrawAlignment(playerid, PTD_Notification[playerid][i][2], 1);
        PlayerTextDrawColor(playerid, PTD_Notification[playerid][i][2], -1);
        PlayerTextDrawUseBox(playerid, PTD_Notification[playerid][i][2], 1);
        PlayerTextDrawBoxColor(playerid, PTD_Notification[playerid][i][2], 0);
        PlayerTextDrawSetShadow(playerid, PTD_Notification[playerid][i][2], 1);
        PlayerTextDrawSetOutline(playerid, PTD_Notification[playerid][i][2], 0);
        PlayerTextDrawBackgroundColor(playerid, PTD_Notification[playerid][i][2], 0);
        PlayerTextDrawFont(playerid, PTD_Notification[playerid][i][2], 1);
        PlayerTextDrawSetProportional(playerid, PTD_Notification[playerid][i][2], 1);
        PlayerTextDrawSetShadow(playerid, PTD_Notification[playerid][i][2], 1);

        PTD_Notification[playerid][i][3] = CreatePlayerTextDraw(playerid, NotificationPosition[i][0], NotificationPosition[i][1] + 40.0, "LD_SPAC:white");
        PlayerTextDrawLetterSize(playerid, PTD_Notification[playerid][i][3], 0.000000, 0.000000);
        PlayerTextDrawTextSize(playerid, PTD_Notification[playerid][i][3], 144.430000, -1.4000000);
        PlayerTextDrawAlignment(playerid, PTD_Notification[playerid][i][3], 1);
        PlayerTextDrawColor(playerid, PTD_Notification[playerid][i][3], color);
        PlayerTextDrawSetShadow(playerid, PTD_Notification[playerid][i][3], 0);
        PlayerTextDrawSetOutline(playerid, PTD_Notification[playerid][i][3], 0);
        PlayerTextDrawBackgroundColor(playerid, PTD_Notification[playerid][i][3], 255);
        PlayerTextDrawFont(playerid, PTD_Notification[playerid][i][3], 4);
        PlayerTextDrawSetProportional(playerid, PTD_Notification[playerid][i][3], 0);
        PlayerTextDrawSetShadow(playerid, PTD_Notification[playerid][i][3], 0);

        for(new t; t < sizeof(PTD_Notification[][]); t++) {
            PlayerTextDrawShow(playerid, PTD_Notification[playerid][i][t]);
        }

        new len = strlen(message), seconds = len < 20 ? 3500 : floatround(len * 250);
        Notification[playerid][i][Timer] = SetTimerEx("NT_Destroy", seconds, false, "ii", playerid, i);
        return 1;
    }
    
    new nt_id = -1, Float:dist = 1000.0;
    for(new i; i < MAX_PLAYER_NOTIFICATION; i++){
        if ( Notification[playerid][i][TD_Value] < dist ) {
            nt_id = i;
            dist = Notification[playerid][i][TD_Value];
        }
    }

    if ( nt_id != -1 )
    {
        KillTimer(Notification[playerid][nt_id][Timer]);
        NT:Destroy(playerid, nt_id);
        goto nt_init;
    }
    return 0;
}

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