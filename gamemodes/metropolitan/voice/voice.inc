#include <YSI_Coding\y_hooks>

new SV_GSTREAM:gstream = SV_NULL;
new SV_LSTREAM:lstream[MAX_PLAYERS] = { SV_NULL, ... };

#define VK_KEY_B           (0x42)
#define VK_KEY_Z           (0x5A)
#define VK_KEY_I           (0x49)

public OnPlayerActivationKeyPress(playerid, keyid)
{
    if ( Player:Logged(playerid) )
    {
        if (keyid == VK_KEY_B && lstream[playerid] )
        {
            Player:UpdateLabel(playerid, COLOR_BLUE);    
            SvAttachSpeakerToStream(lstream[playerid], playerid);
        }
        
        if (keyid == VK_KEY_Z && gstream && Player:GetAdmin(playerid) >= HELPER)
        {
            Player:UpdateLabel(playerid, COLOR_BLUE);
            SvAttachSpeakerToStream(gstream, playerid);
        }
    }
}

public OnPlayerActivationKeyRelease(playerid, keyid)
{
    // voip local
    if (keyid == VK_KEY_B && lstream[playerid]) {
        Player:UpdateLabel(playerid, 0xFFFFFFFF);
        SvDetachSpeakerFromStream(lstream[playerid], playerid);
    }

    // voip admin global
    if (keyid == VK_KEY_Z && gstream && Player:GetAdmin(playerid) >= HELPER) {
        Player:UpdateLabel(playerid, 0xFFFFFFFF);
        SvDetachSpeakerFromStream(gstream, playerid);
    }
}


hook OnPlayerConnect(playerid)
{
    lstream[playerid] = SV_NULL;
    
    if (SvGetVersion(playerid) == SV_NULL)
    {
        NT:Send(playerid, NT_TYPE_ERROR, "Não foi encontrado o plugin sampvoice em seu GTA!");
        //Player:Kick(playerid);
        //return Y_HOOKS_BREAK_RETURN_0;
    }
    
    else if (SvHasMicro(playerid) == SV_FALSE)
    {
        NT:Send(playerid, NT_TYPE_ERROR, "Não foi encontrado um microfone configurado!");
        //Player:Kick(playerid);
        //return Y_HOOKS_BREAK_RETURN_0;
    }

    else if ((lstream[playerid] = SvCreateDLStreamAtPlayer(40.0, SV_INFINITY, playerid, 0xff0000ff, "Local")))
    {
        if (gstream) SvAttachListenerToStream(gstream, playerid);
        SvAddKey(playerid, VK_KEY_B);
        SvAddKey(playerid, VK_KEY_Z);
        SvAddKey(playerid, VK_KEY_I);
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    // Removing the player's local stream after disconnecting
    if (lstream[playerid])
    {
        SvDeleteStream(lstream[playerid]);
        lstream[playerid] = SV_NULL;
    }
    if ( gstream ) SvDetachSpeakerFromStream(gstream, playerid);
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnGameModeInit()
{
    gstream = SvCreateGStream(0xffff0000, "Global");
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnGameModeExit()
{
    if (gstream) SvDeleteStream(gstream);
    gstream = SV_NULL;
    return Y_HOOKS_CONTINUE_RETURN_1;
}