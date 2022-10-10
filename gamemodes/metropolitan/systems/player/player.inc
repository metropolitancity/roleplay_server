enum E_PLAYER_DATA
{
    ID,
    Name[MAX_PLAYER_NAME],
    Email[MAX_PLAYER_EMAIL],
    Password[MAX_PLAYER_PASSWORD],
    Float:Spawn[E_COORDINATE_3D],
    Interior,
    World,
    Skin,
    bool:StaffWorking,
    Admin,
    vAdmin,
    Float:Health,
    Float:Armour,
    bool:Login,
    bool:Logged,
    LastLogin[30],
}
new Player[MAX_PLAYERS][E_PLAYER_DATA];


// textdraw de registro
new PlayerText:PTD_Register[MAX_PLAYERS][22], PlayerText:PTD_Login[MAX_PLAYERS][19];

// forward
forward OnPlayerCheckAccount(playerid);
forward OnPasswordHashed(playerid);
forward OnPasswordVerify(playerid);
forward OnPlayerRegister(playerid);
forward OnPlayerAttempAuth(playerid);
forward OnPlayerSave(playerid);


// arquivos do sistema
#include <systems/player/callbacks>
#include <systems/player/functions>
#include <systems/player/dialogs>
#include <systems/player/commands>