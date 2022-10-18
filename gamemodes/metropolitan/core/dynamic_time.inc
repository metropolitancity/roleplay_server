#include <YSI_Coding\y_hooks>

// =============== VARIAVEIS
new TimerDynamicTime[MAX_PLAYERS] = { -1, ...};


// =============== CALLBACKS
hook OnPlayerConnect(playerid)
{
    if ( TimerDynamicTime[playerid] == -1 ) {
        TimerDynamicTime[playerid] = SetTimerEx("OnUpdateDynamicTime", 1000, true, "i", playerid);
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if ( TimerDynamicTime[playerid] != -1){
        KillTimer(TimerDynamicTime[playerid]);
        TimerDynamicTime[playerid] = -1;
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

forward OnUpdateDynamicTime(playerid);
public OnUpdateDynamicTime(playerid)
{
    new hour, minutes;
    gettime(hour, minutes);
    hour += 4;
    SetPlayerTime(playerid, hour, minutes);
    return 1;
}