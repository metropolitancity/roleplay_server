#define MAX_PLAYER_EMAIL        (64)
#define MAX_PLAYER_PASSWORD     (BCRYPT_HASH_LENGTH)
#define BCRYPT_COST             (12)

// notification type
enum E_NOTIFICATION_TYPE
{
    NT_TYPE_ERROR = 1,
    NT_TYPE_INFO,
    NT_TYPE_SUCCESS,
}

// coordenadas
enum E_COORDINATE_3D
{
    Float:X,
    Float:Y,
    Float:Z,
    Float:A
}

// leveis administrativos
enum ( <<=1 )
{
    HELPER = 1,
    MODERATOR,
    ADMINISTRATOR,
    CEO
}

// "namespace"
#define Player:           Player_
#define NT:               NT_