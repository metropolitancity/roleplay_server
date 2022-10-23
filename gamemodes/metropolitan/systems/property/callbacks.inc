#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    mysql_query_file(SQL_Connection, "tables/"TABLE_PROPERTY".sql", false);

    new Cache:cache = mysql_query(SQL_Connection, "SELECT * FROM "TABLE_PROPERTY" WHERE 1;", true);
    new rows = cache_num_rows();

    if ( rows )
    {
        new str[144];
        for(new i; i < rows; i++)
        {
            cache_get_value_name_int(i, "id", Property[i][ID]);
            cache_get_value_name(i, "name", Property[i][Name], 32);
            format(Property[i][Name], 32, ret_utf8decode(Property[i][Name]));

            cache_get_value_name_float(i, "entrance_x", Property[i][EntranceX]);
            cache_get_value_name_float(i, "entrance_y", Property[i][EntranceY]);
            cache_get_value_name_float(i, "entrance_z", Property[i][EntranceZ]);
            cache_get_value_name_float(i, "entrance_a", Property[i][EntranceA]);

            cache_get_value_name_float(i, "exit_x", Property[i][ExitX]);
            cache_get_value_name_float(i, "exit_y", Property[i][ExitY]);
            cache_get_value_name_float(i, "exit_z", Property[i][ExitZ]);
            cache_get_value_name_float(i, "exit_a", Property[i][ExitA]);

            cache_get_value_name_int(i, "interior", Property[i][Interior]);
            cache_get_value_name_int(i, "mapicon", Property[i][MapIcon]);

            CreateDynamicPickup(19197, 23, Property[i][EntranceX], Property[i][EntranceY], Property[i][EntranceZ] - 1.13, .worldid=0, .interiorid=0, .streamdistance=DISTANCE_RENDER_PICKUP);
            CreateDynamicPickup(19197, 23, Property[i][ExitX], Property[i][ExitY], Property[i][ExitZ] - 1.13, .worldid=i, .interiorid=Property[i][Interior], .streamdistance=DISTANCE_RENDER_PICKUP);

            format(str, sizeof(str), "%s\n{FFFFFF}Aperte {"COLOR_RED_EMBED"}F{FFFFFF} para entrar.", Property[i][Name]);
            CreateDynamic3DTextLabel(str, COLOR_RED, Property[i][EntranceX], Property[i][EntranceY], Property[i][EntranceZ], DISTANCE_RENDER_LABEL, .worldid=0, .interiorid=0, .streamdistance=DISTANCE_RENDER_LABEL);

            CreateDynamicMapIcon(Property[i][EntranceX], Property[i][EntranceY], Property[i][EntranceZ], Property[i][MapIcon], 0xFFFFFFFF, .worldid=0, .interiorid=0, .streamdistance=DISTANCE_RENDER_MAPICON);
            
            Iter_Add(Property, i);
        }
        printf("[MP:RP] Foram carregados %d propriedades públicas.", Iter_Count(Property));
    }
    cache_delete(cache);

    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if ( PRESSED(KEY_SECONDARY_ATTACK) )
    {
        foreach(new i: Property)
        {
            if ( IsPlayerInRangeOfPoint(playerid, 1.0, Property[i][EntranceX], Property[i][EntranceY], Property[i][EntranceZ]) ) 
            {
                SetPlayerPos(playerid, Property[i][ExitX], Property[i][ExitY], Property[i][ExitZ]);
                SetPlayerFacingAngle(playerid, Property[i][ExitA]);
                SetPlayerInterior(playerid, Property[i][Interior]);
                SetPlayerVirtualWorld(playerid, i);
                SetCameraBehindPlayer(playerid);
                return Y_HOOKS_BREAK_RETURN_1;
            }
            else if ( IsPlayerInRangeOfPoint(playerid, 1.0, Property[i][ExitX], Property[i][ExitY], Property[i][ExitZ]) ) 
            {
                SetPlayerPos(playerid, Property[i][EntranceX], Property[i][EntranceY], Property[i][EntranceZ]);
                SetPlayerFacingAngle(playerid, Property[i][EntranceA]);
                SetPlayerInterior(playerid, 0);
                SetPlayerVirtualWorld(playerid, 0);
                SetCameraBehindPlayer(playerid);
                return Y_HOOKS_BREAK_RETURN_1;
            }
        }
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}