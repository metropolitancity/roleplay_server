hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if ( PRESSED(KEY_NO) && IsPlayerInAnyVehicle(playerid) )
    {
        Dialog_Show(playerid, PANEL_VEHICLE, DIALOG_STYLE_LIST, "PAINEL DO VEICULO", "Motor\nFárol", "Selecionar", "Fechar");
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}