#include <YSI_Coding\y_hooks>

new SV_GSTREAM:gstream = SV_NULL;
new SV_LSTREAM:lstream[MAX_PLAYERS] = { SV_NULL, ... };

#define VK_KEY_B           (0x42)
#define VK_KEY_Z           (0x5A)
#define VK_KEY_I              (0x49)

public OnPlayerActivationKeyPress(playerid, keyid)
{
    if (keyid == VK_KEY_B && lstream[playerid]) SvAttachSpeakerToStream(lstream[playerid], playerid);
    if (keyid == VK_KEY_Z && gstream) SvAttachSpeakerToStream(gstream, playerid);

    #if defined VC_OnPlayerActivationKeyPress
        return VC_OnPlayerActivationKeyPress(playerid, keyid);
    #else
        return 1;
    #endif
}

public OnPlayerActivationKeyRelease(playerid, keyid)
{
    if (keyid == VK_KEY_B && lstream[playerid]) SvDetachSpeakerFromStream(lstream[playerid], playerid);
    if (keyid == VK_KEY_Z && gstream) SvDetachSpeakerFromStream(gstream, playerid);
    if ( keyid == VK_KEY_I)
    {
        SendClientMessage(playerid, COLOR_YELLOW, "Caramba não é que a tecla I funciona.");
    }
}


hook OnPlayerConnect(playerid)
{
    // Checking for plugin availability
    if (SvGetVersion(playerid) == SV_NULL)
    {
        SendClientMessage(playerid, -1, "Could not find plugin sampvoice.");
    }
    // Checking for a microphone
    else if (SvHasMicro(playerid) == SV_FALSE)
    {
        SendClientMessage(playerid, -1, "The microphone could not be found.");
    }
    // Create a local stream with an audibility distance of 40.0, an unlimited number of listeners
    // and the name 'Local' (the name 'Local' will be displayed in red in the players' speakerlist)
    else if ((lstream[playerid] = SvCreateDLStreamAtPlayer(40.0, SV_INFINITY, playerid, 0xff0000ff, "Local")))
    {
        SendClientMessage(playerid, -1, "Press Z to talk to global chat and B to talk to local chat.");

        // Attach the player to the global stream as a listener
        if (gstream) SvAttachListenerToStream(gstream, playerid);

        // Assign microphone activation keys to the player
        SvAddKey(playerid, VK_KEY_B);
        SvAddKey(playerid, VK_KEY_Z);
        SvAddKey(playerid, VK_KEY_I);
    }
}

hook OnPlayerDisconnect(playerid, reason)
{
    // Removing the player's local stream after disconnecting
    if (lstream[playerid])
    {
        SvDeleteStream(lstream[playerid]);
        lstream[playerid] = SV_NULL;
    }
}

hook OnGameModeInit()
{
    gstream = SvCreateGStream(0xffff0000, "Global");
}

hook OnGameModeExit()
{
    if (gstream) SvDeleteStream(gstream);
}