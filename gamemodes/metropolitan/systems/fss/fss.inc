// ===================== variáveis e definições
#define MAX_FSS         (3)
static bool:FSS_CREATED[MAX_PLAYERS][MAX_FSS];
static PlayerText:PTD_FSS[MAX_PLAYERS][MAX_FSS][4];
static FSS_Time[MAX_PLAYERS] = { -1, ...};


// ===================== callbacks
#include <YSI_Coding\y_hooks>
hook OnPlayerConnect(playerid)
{
    if ( FSS_Time[playerid] != -1 )
    {
        KillTimer(FSS_Time[playerid]);
        FSS_Time[playerid] = -1;
    }

    for(new i; i < MAX_FSS; i++)
    {
        FSS_CREATED[playerid][i] = false;
        PTD_FSS[playerid][i][0] = INVALID_PLAYER_TEXT_DRAW;
        PTD_FSS[playerid][i][0] = INVALID_PLAYER_TEXT_DRAW;
        PTD_FSS[playerid][i][1] = INVALID_PLAYER_TEXT_DRAW;
        PTD_FSS[playerid][i][2] = INVALID_PLAYER_TEXT_DRAW;
        PTD_FSS[playerid][i][3] = INVALID_PLAYER_TEXT_DRAW;
    }

    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerSave(playerid, uid)
{
    FSS:Destroy(playerid, Player[playerid][FSS_Hunger]);
    FSS:Destroy(playerid, Player[playerid][FSS_Thirst]);
    FSS:Destroy(playerid, Player[playerid][FSS_Sleep]);
    
    if ( FSS_Time[playerid] != -1 ) {
        KillTimer(FSS_Time[playerid]);
        FSS_Time[playerid] = -1;
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerSpawn(playerid)
{
    if ( GetPVarInt(playerid, "ShowedFSS") )return Y_HOOKS_CONTINUE_RETURN_1;
    SetPVarInt(playerid, "ShowedFSS", 1);

    FSS_Time[playerid] = SetTimerEx("OnUpdateFssValue", 30000, true, "i", playerid);

    Player[playerid][FSS_Hunger] = FSS:Create(playerid, "hud:radar_burgerShot", 92.0, 344.0, 0xFFF68FFF);
    FSS:SetValue(playerid, Player[playerid][FSS_Hunger], Player[playerid][Hunger]);

    Player[playerid][FSS_Thirst] = FSS:Create(playerid, "hud:radar_diner",      92.0, 375.0, 0x00CED1FF);
    FSS:SetValue(playerid, Player[playerid][FSS_Thirst], Player[playerid][Thirst]);
    
    Player[playerid][FSS_Sleep]  = FSS:Create(playerid, "hud:radar_ZERO",       92.0, 408.0, 0xFF6A6AFF);
    FSS:SetValue(playerid, Player[playerid][FSS_Sleep], Player[playerid][Sleep]);

    FSS:ShowAll(playerid);
    return Y_HOOKS_CONTINUE_RETURN_1;
}

forward OnUpdateFssValue(playerid);
public OnUpdateFssValue(playerid)
{
    Player[playerid][Hunger] = Player[playerid][Hunger] > 100.0 ? 100.0 : Player[playerid][Hunger];
    Player[playerid][Thirst] = Player[playerid][Thirst] > 100.0 ? 100.0 : Player[playerid][Thirst];
    Player[playerid][Sleep]  = Player[playerid][Sleep]  > 100.0 ? 100.0 : Player[playerid][Sleep];


    Player[playerid][Hunger] -= 0.325; // fome 
    Player[playerid][Thirst] -= 0.450; // sede 
    Player[playerid][Sleep]  -= 0.253; // sono

    if ( Player[playerid][Hunger] == 0.0 ) {
        Player[playerid][Hunger] = 0.0;
        NT:Send(playerid, NT_TYPE_ERROR, "Você desmaiou de fome.");
    }


    if ( Player[playerid][Sleep] == 0.0 ) {
        Player[playerid][Sleep] = 0.0;
        NT:Send(playerid, NT_TYPE_ERROR, "Você desmaiou de sono.");
    }

    if ( Player[playerid][Thirst] == 0.0 ) {
        Player[playerid][Thirst] = 0.0;
        NT:Send(playerid, NT_TYPE_ERROR, "Você desmaiou de sede.");
    }

    FSS:SetValue(playerid, Player[playerid][FSS_Hunger], Player[playerid][Hunger]);
    FSS:SetValue(playerid, Player[playerid][FSS_Thirst], Player[playerid][Thirst]);
    FSS:SetValue(playerid, Player[playerid][FSS_Sleep], Player[playerid][Sleep]);
    return 1;
}


// ===================== funções
FSS:IsValid(playerid, index)
{
    if ( index < 0 || index >= MAX_FSS)return 0;
    return FSS_CREATED[playerid][index];
}

FSS:Create(playerid, const sprite[], Float:x, Float:y, color = 0x00BBFFFF)
{
    for(new i; i < MAX_FSS; ++i)
    {
        if ( FSS_CREATED[playerid][i] )continue;
        FSS_CREATED[playerid][i] = true;
        PTD_FSS[playerid][i][0] = CreatePlayerTextDraw(playerid, x, y, "LD_SPAC:white");
        PlayerTextDrawLetterSize(playerid, PTD_FSS[playerid][i][0], 0.000000, 0.000000);
        PlayerTextDrawTextSize(playerid, PTD_FSS[playerid][i][0], 15.0, 15.0);
        PlayerTextDrawAlignment(playerid, PTD_FSS[playerid][i][0], 1);
        PlayerTextDrawColor(playerid, PTD_FSS[playerid][i][0], 150);
        PlayerTextDrawSetShadow(playerid, PTD_FSS[playerid][i][0], 0);
        PlayerTextDrawSetOutline(playerid, PTD_FSS[playerid][i][0], 0);
        PlayerTextDrawBackgroundColor(playerid, PTD_FSS[playerid][i][0], 255);
        PlayerTextDrawFont(playerid, PTD_FSS[playerid][i][0], 4);
        PlayerTextDrawSetProportional(playerid, PTD_FSS[playerid][i][0], 0);
        PlayerTextDrawSetShadow(playerid, PTD_FSS[playerid][i][0], 0);

        PTD_FSS[playerid][i][1] = CreatePlayerTextDraw(playerid, x+2.0, y+2.0, sprite);
        PlayerTextDrawLetterSize(playerid, PTD_FSS[playerid][i][1], 0.000000, 0.000000);
        PlayerTextDrawTextSize(playerid, PTD_FSS[playerid][i][1], 10.000000, 10.000000);
        PlayerTextDrawAlignment(playerid, PTD_FSS[playerid][i][1], 1);
        PlayerTextDrawColor(playerid, PTD_FSS[playerid][i][1], -1);
        PlayerTextDrawSetShadow(playerid, PTD_FSS[playerid][i][1], 0);
        PlayerTextDrawSetOutline(playerid, PTD_FSS[playerid][i][1], 0);
        PlayerTextDrawBackgroundColor(playerid, PTD_FSS[playerid][i][1], 255);
        PlayerTextDrawFont(playerid, PTD_FSS[playerid][i][1], 4);
        PlayerTextDrawSetProportional(playerid, PTD_FSS[playerid][i][1], 0);
        PlayerTextDrawSetShadow(playerid, PTD_FSS[playerid][i][1], 0);

        PTD_FSS[playerid][i][2] = CreatePlayerTextDraw(playerid, x, y + 15.0, "LD_SPAC:white");
        PlayerTextDrawLetterSize(playerid, PTD_FSS[playerid][i][2], 0.000000, 0.000000);
        PlayerTextDrawTextSize(playerid, PTD_FSS[playerid][i][2], 15.0, 3.0);
        PlayerTextDrawAlignment(playerid, PTD_FSS[playerid][i][2], 1);
        PlayerTextDrawColor(playerid, PTD_FSS[playerid][i][2], 180);
        PlayerTextDrawSetShadow(playerid, PTD_FSS[playerid][i][2], 0);
        PlayerTextDrawSetOutline(playerid, PTD_FSS[playerid][i][2], 0);
        PlayerTextDrawBackgroundColor(playerid, PTD_FSS[playerid][i][2], 255);
        PlayerTextDrawFont(playerid, PTD_FSS[playerid][i][2], 4);
        PlayerTextDrawSetProportional(playerid, PTD_FSS[playerid][i][2], 0);
        PlayerTextDrawSetShadow(playerid, PTD_FSS[playerid][i][2], 0);

        PTD_FSS[playerid][i][3] = CreatePlayerTextDraw(playerid, x, y + 15.0, "LD_SPAC:white");
        PlayerTextDrawLetterSize(playerid, PTD_FSS[playerid][i][3], 0.000000, 0.000000);
        PlayerTextDrawTextSize(playerid, PTD_FSS[playerid][i][3], 0.0, 3.0);
        PlayerTextDrawAlignment(playerid, PTD_FSS[playerid][i][3], 1);
        PlayerTextDrawColor(playerid, PTD_FSS[playerid][i][3], color);
        PlayerTextDrawSetShadow(playerid, PTD_FSS[playerid][i][3], 0);
        PlayerTextDrawSetOutline(playerid, PTD_FSS[playerid][i][3], 0);
        PlayerTextDrawBackgroundColor(playerid, PTD_FSS[playerid][i][3], 255);
        PlayerTextDrawFont(playerid, PTD_FSS[playerid][i][3], 4);
        PlayerTextDrawSetProportional(playerid, PTD_FSS[playerid][i][3], 0);
        PlayerTextDrawSetShadow(playerid, PTD_FSS[playerid][i][3], 0);
        return i;
    }
    return -1;
}

FSS:Destroy(playerid, index)
{
    if ( !FSS:IsValid(playerid, index) )return 0;
    FSS_CREATED[playerid][index] = false;
    PlayerTextDrawDestroy(playerid, PTD_FSS[playerid][index][0]);
    PlayerTextDrawDestroy(playerid, PTD_FSS[playerid][index][1]);
    PlayerTextDrawDestroy(playerid, PTD_FSS[playerid][index][2]);
    PlayerTextDrawDestroy(playerid, PTD_FSS[playerid][index][3]);
    PTD_FSS[playerid][index][0] = INVALID_PLAYER_TEXT_DRAW;
    PTD_FSS[playerid][index][1] = INVALID_PLAYER_TEXT_DRAW;
    PTD_FSS[playerid][index][2] = INVALID_PLAYER_TEXT_DRAW;
    PTD_FSS[playerid][index][3] = INVALID_PLAYER_TEXT_DRAW;
    return 1;
}

FSS:ShowAll(playerid)
{
    for(new i; i < MAX_FSS; i++) {
        FSS:Show(playerid, i);
    }
    return 1;
}

FSS:Show(playerid, index)
{
    if ( !FSS:IsValid(playerid, index) )return 0;
    PlayerTextDrawShow(playerid, PTD_FSS[playerid][index][0]);
    PlayerTextDrawShow(playerid, PTD_FSS[playerid][index][1]);
    PlayerTextDrawShow(playerid, PTD_FSS[playerid][index][2]);
    PlayerTextDrawShow(playerid, PTD_FSS[playerid][index][3]);
    return 1;
}

FSS:SetValue(playerid, index, Float:value)
{
    if ( !FSS:IsValid(playerid, index) )return 0;
    
    value = value < 0.0 ? 0.0 : value;
    value = value > 100.0 ? 100.0 : value;

    PlayerTextDrawTextSize(playerid, PTD_FSS[playerid][index][3], ((15.0 / 100) * value), 3.0);
    PlayerTextDrawShow(playerid, PTD_FSS[playerid][index][3]);
    return 1;
}