#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    mysql_query_file(SQL_Connection, "tables/"TABLE_USERS_VEHICLES".sql", false);
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if ( PRESSED(KEY_NO) && IsPlayerInAnyVehicle(playerid) )
    {
        Dialog_Show(playerid, PANEL_VEHICLE, DIALOG_STYLE_LIST, "PAINEL DO VEICULO", "Motor\nFárol", "Selecionar", "Fechar");
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnVehicleCreated(vehicleid)
{
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnVehicleDestroy(vehicleid)
{
    return Y_HOOKS_CONTINUE_RETURN_1;
}