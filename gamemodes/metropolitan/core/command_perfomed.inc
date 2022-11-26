public OnPlayerCommandReceived(playerid, cmd[], params[], flags)
{
    if ( !IsPlayerAdmin(playerid) )
    {
        if ( (flags & CEO) && (!Player:GetAdminWorking(playerid) || Player:GetAdmin(playerid) < CEO) ){
            return NT:Send(playerid, NT_TYPE_ERROR, "(~b~~h~~h~~h~/%s~w~) comando não existe.", cmd), 0;
        }
        if ( (flags & ADMINISTRATOR) && (!Player:GetAdminWorking(playerid) || Player:GetAdmin(playerid) < ADMINISTRATOR) ){
            return NT:Send(playerid, NT_TYPE_ERROR, "(~b~~h~~h~~h~/%s~w~) comando não existe.", cmd), 0;
        }

        if ( (flags & MODERATOR) && (!Player:GetAdminWorking(playerid) || Player:GetAdmin(playerid) < MODERATOR) ){
            return NT:Send(playerid, NT_TYPE_ERROR, "(~b~~h~~h~~h~/%s~w~) comando não existe.", cmd), 0;
        }

        if ( (flags & HELPER) && (!Player:GetAdminWorking(playerid) || Player:GetAdmin(playerid) < HELPER) ){
            return NT:Send(playerid, NT_TYPE_ERROR, "(~b~~h~~h~~h~/%s~w~) comando não existe.", cmd), 0;
        }
    }

    return 1;
}

public OnPlayerCommandPerformed(playerid, cmd[], params[], result, flags)
{
    if ( result == -1 )
    {
        NT:Send(playerid, NT_TYPE_ERROR, "(~b~~h~~h~~h~/%s~w~) comando não existe.", cmd);
        return 0;
    }
    return 1;
}