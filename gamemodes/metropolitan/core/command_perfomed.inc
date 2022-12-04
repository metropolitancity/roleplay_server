public OnPlayerCommandReceived(playerid, cmd[], params[], flags)
{
    if ( !IsPlayerAdmin(playerid) )
    {
        if ( (flags & CEO) && (!Player:GetAdminWorking(playerid) || Player:GetAdmin(playerid) < CEO) ){
            return Player:SendError(playerid, "O comando ~r~~h~~h~~h~/%s~w~ não existe em nosso servidor.", cmd), 0;
        }
        if ( (flags & ADMINISTRATOR) && (!Player:GetAdminWorking(playerid) || Player:GetAdmin(playerid) < ADMINISTRATOR) ){
            return Player:SendError(playerid, "O comando ~r~~h~~h~~h~/%s~w~ não existe em nosso servidor.", cmd), 0;
        }

        if ( (flags & MODERATOR) && (!Player:GetAdminWorking(playerid) || Player:GetAdmin(playerid) < MODERATOR) ){
            return Player:SendError(playerid, "O comando ~r~~h~~h~~h~/%s~w~ não existe em nosso servidor.", cmd), 0;
        }

        if ( (flags & HELPER) && (!Player:GetAdminWorking(playerid) || Player:GetAdmin(playerid) < HELPER) ){
            return Player:SendError(playerid, "O comando ~r~~h~~h~~h~/%s~w~ não existe em nosso servidor.", cmd), 0;
        }
    }

    return 1;
}

public OnPlayerCommandPerformed(playerid, cmd[], params[], result, flags)
{
    if ( result == -1 )
    {
        Player:SendError(playerid, "O comando ~r~~h~~h~~h~/%s~w~ não existe em nosso servidor.", cmd);
        return 0;
    }
    return 1;
}