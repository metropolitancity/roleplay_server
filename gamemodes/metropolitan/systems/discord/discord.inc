// ============= forward

// ============= Textdraws
new PlayerText:PTD_DiscordIntegration[MAX_PLAYERS][7] = { INVALID_PLAYER_TEXT_DRAW, ... };


new InputDiscordID[MAX_PLAYERS][32];

// ============= Sistema
#include <systems/discord/callbacks>
#include <systems/discord/dialogs>
#include <systems/discord/functions>