stock NT:Send(playerid, E_NOTIFICATION_TYPE:type, const message[], va_args<>)
{
    if ( !IsPlayerConnected(playerid) )return 0;

    new len = strlen(message), seconds = len < 20 ? 3500 : floatround(len * 150);
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
        PlayerTextDrawAlignment(playerid, PTD_Notification[playerid][i][0], TEXT_DRAW_ALIGN_LEFT);
        PlayerTextDrawColour(playerid, PTD_Notification[playerid][i][0], 303174399);
        PlayerTextDrawSetShadow(playerid, PTD_Notification[playerid][i][0], 0);
        PlayerTextDrawSetOutline(playerid, PTD_Notification[playerid][i][0], 0);
        PlayerTextDrawBackgroundColour(playerid, PTD_Notification[playerid][i][0], 255);
        PlayerTextDrawFont(playerid, PTD_Notification[playerid][i][0], TEXT_DRAW_FONT_SPRITE_DRAW);
        PlayerTextDrawSetProportional(playerid, PTD_Notification[playerid][i][0], false);
        PlayerTextDrawSetShadow(playerid, PTD_Notification[playerid][i][0], 0);

        PTD_Notification[playerid][i][1] = CreatePlayerTextDraw(playerid, NotificationPosition[i][0] + 2.0, NotificationPosition[i][1] + 13.0, str_type);
        PlayerTextDrawLetterSize(playerid, PTD_Notification[playerid][i][1], 0.000000, 0.000000);
        PlayerTextDrawTextSize(playerid, PTD_Notification[playerid][i][1], 10.000000, 10.000000);
        PlayerTextDrawAlignment(playerid, PTD_Notification[playerid][i][1], TEXT_DRAW_ALIGN_LEFT);
        PlayerTextDrawColour(playerid, PTD_Notification[playerid][i][1], -1);
        PlayerTextDrawSetShadow(playerid, PTD_Notification[playerid][i][1], 0);
        PlayerTextDrawSetOutline(playerid, PTD_Notification[playerid][i][1], 0);
        PlayerTextDrawBackgroundColour(playerid, PTD_Notification[playerid][i][1], 255);
        PlayerTextDrawFont(playerid, PTD_Notification[playerid][i][1], TEXT_DRAW_FONT_SPRITE_DRAW);
        PlayerTextDrawSetProportional(playerid, PTD_Notification[playerid][i][1], false);
        PlayerTextDrawSetShadow(playerid, PTD_Notification[playerid][i][1], 0);

        va_format(f_message, sizeof(f_message), message, va_start<3>);
        PTD_Notification[playerid][i][2] = CreatePlayerTextDraw(playerid, NotificationPosition[i][0] + 15.0, NotificationPosition[i][1] + ( len > 40 ? 10.0 : 13.0 ), f_message);
        PlayerTextDrawLetterSize(playerid, PTD_Notification[playerid][i][2], 0.196204, 1.002497);
        PlayerTextDrawTextSize(playerid, PTD_Notification[playerid][i][2], 150.000000, 0.000000);
        PlayerTextDrawAlignment(playerid, PTD_Notification[playerid][i][2], TEXT_DRAW_ALIGN_LEFT);
        PlayerTextDrawColour(playerid, PTD_Notification[playerid][i][2], -1);
        PlayerTextDrawUseBox(playerid, PTD_Notification[playerid][i][2], true);
        PlayerTextDrawBoxColour(playerid, PTD_Notification[playerid][i][2], 0);
        PlayerTextDrawSetShadow(playerid, PTD_Notification[playerid][i][2], 1);
        PlayerTextDrawSetOutline(playerid, PTD_Notification[playerid][i][2], 0);
        PlayerTextDrawBackgroundColour(playerid, PTD_Notification[playerid][i][2], 0);
        PlayerTextDrawFont(playerid, PTD_Notification[playerid][i][2], TEXT_DRAW_FONT_1);
        PlayerTextDrawSetProportional(playerid, PTD_Notification[playerid][i][2], true);
        PlayerTextDrawSetShadow(playerid, PTD_Notification[playerid][i][2], 1);

        PTD_Notification[playerid][i][3] = CreatePlayerTextDraw(playerid, NotificationPosition[i][0], NotificationPosition[i][1] + 40.0, "LD_SPAC:white");
        PlayerTextDrawLetterSize(playerid, PTD_Notification[playerid][i][3], 0.000000, 0.000000);
        PlayerTextDrawTextSize(playerid, PTD_Notification[playerid][i][3], 144.430000, -1.4000000);
        PlayerTextDrawAlignment(playerid, PTD_Notification[playerid][i][3], TEXT_DRAW_ALIGN_LEFT);
        PlayerTextDrawColour(playerid, PTD_Notification[playerid][i][3], color);
        PlayerTextDrawSetShadow(playerid, PTD_Notification[playerid][i][3], 0);
        PlayerTextDrawSetOutline(playerid, PTD_Notification[playerid][i][3], 0);
        PlayerTextDrawBackgroundColour(playerid, PTD_Notification[playerid][i][3], 255);
        PlayerTextDrawFont(playerid, PTD_Notification[playerid][i][3], TEXT_DRAW_FONT_SPRITE_DRAW);
        PlayerTextDrawSetProportional(playerid, PTD_Notification[playerid][i][3], false);
        PlayerTextDrawSetShadow(playerid, PTD_Notification[playerid][i][3], 0);

        for(new t; t < sizeof(PTD_Notification[][]); t++)
        {
            if ( IsValidPlayerTextDraw(playerid, PTD_Notification[playerid][i][t])) {
                PlayerTextDrawShow(playerid, PTD_Notification[playerid][i][t]);
            }
        }
        Notification[playerid][i][Timer] = SetTimerEx("NT_Destroy", seconds, false, "ii", playerid, i);
        return 1;
    }
    return 0;
}