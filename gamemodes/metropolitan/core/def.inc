//forward
forward OnPlayerSave(playerid);

#define MAX_PLAYER_EMAIL        (64)
#define MAX_PLAYER_PASSWORD     (BCRYPT_HASH_LENGTH)
#define BCRYPT_COST             (12)


#define MAX_BUSINESS_DEALERSHIPS    (5)

#define DISTANCE_RENDER_MAPICON         ( 100.0 )
#define DISTANCE_RENDER_LABEL           ( 10.0 )
#define DISTANCE_RENDER_PICKUP          ( 30.0 )


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

// genero
enum
{
    GENDER_MALE = 1,
    GENDER_FEMALE
}

// leveis administrativos
enum ( <<=1 )
{
    HELPER = 1,
    MODERATOR,
    ADMINISTRATOR,
    CEO
}

#define MAX_UUID_LEN        64

// macro key
#define PRESSED(%0) (((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))


//
#define INVALID_TIMER_ID        ( -1 )

// "namespace"
#define Player:           Player_
#define Vehicle:          Vehicle_
#define NT:               NT_
#define DC:               DC_
#define FSS:              Fss_