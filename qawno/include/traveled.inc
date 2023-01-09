/************************* FORWARDS ***************************/
forward GetPositionAll();
forward Corrida(vehicleid);

/********************** VARI�VEIS ****************************/
static Float:VehicleX[MAX_VEHICLES];
static Float:VehicleY[MAX_VEHICLES];
static Float:VehicleZ[MAX_VEHICLES];
static Float:Percorreu[MAX_VEHICLES];
static Timer[MAX_VEHICLES];
static ID[MAX_PLAYERS];
/************************************************************/
public OnGameModeInit()
{
    SetTimer("GetPositionAll", 5000, false);
    #if defined ModeInit
        return ModeInit();
    #else
        return true;
    #endif
}

#if !defined PLAYER_STATE
	#define PLAYER_STATE: _:
#endif
public OnPlayerStateChange(playerid, PLAYER_STATE:newstate, PLAYER_STATE:oldstate)
{
    if(newstate == PLAYER_STATE_DRIVER)
    {
        ID[playerid] = GetPlayerVehicleID(playerid);
        Timer[ID[playerid]] = SetTimerEx("Corrida", 5000, true, "i", ID[playerid]);
    }
    if(oldstate == PLAYER_STATE_DRIVER)
    {
        KillTimer(Timer[ID[playerid]]);
    }
    #if defined StateChange
        return StateChange(playerid, newstate, oldstate);
    #else
        return true;
    #endif
}

public OnPlayerConnect(playerid)
{
    if ( ID[playerid] != 0 ){
        KillTimer(Timer[ID[playerid]]);
        ID[playerid] = 0;
    }
    #if defined OnConnect
        return OnConnect(playerid);
    #else
        return true;
    #endif
}

public GetPositionAll()
{
    for(new v; v < MAX_VEHICLES; v++)
    {
        if(GetVehicleModel(v) != 0) GetVehiclePos(v, VehicleX[v], VehicleY[v], VehicleZ[v]);
    }
    return 1;
}

public Corrida(vehicleid)
{
	Percorreu[vehicleid] += GetVehicleDistanceFromPoint(vehicleid, VehicleX[vehicleid], VehicleY[vehicleid], VehicleZ[vehicleid]);
	GetVehiclePos(vehicleid, VehicleX[vehicleid], VehicleY[vehicleid], VehicleZ[vehicleid]);
	return 1;
}

/********************************** STOCKS ***************************************/
stock Float:GetDistanceTraveled(vehicleid)
{
     Corrida(vehicleid);
     return Percorreu[vehicleid];
}

stock SetVehicleDistanceTravaled(vehicleid, Float:km)
{
    Percorreu[vehicleid] = km;
    return true;
}

stock SetVehiclePosEx(vehicleid, Float:X, Float:Y, Float:Z)
{
    SetVehiclePos(vehicleid, X, Y, Z);
  	VehicleX[vehicleid] = X;
	VehicleY[vehicleid] = Y;
	VehicleZ[vehicleid] = Z;
	return 1;
}

stock CreateVehicleEx(modelid, Float:x, Float:y, Float:z, Float:angle, color1, color2, respawn_delay, addsirene=0)
{
    new nID = CreateVehicle(modelid, Float:x, Float:y, Float:z, Float:angle, color1, color2, respawn_delay, bool:addsirene);
    GetVehiclePos(nID,VehicleX[nID], VehicleY[nID], VehicleZ[nID]);
    return nID;
}

stock DestroyVehicleEx(vehicleid)
{
    if ( !IsValidVehicle(vehicleid) )return INVALID_VEHICLE_ID;

    VehicleX[vehicleid] = 0.0;
    VehicleY[vehicleid] = 0.0;
    VehicleZ[vehicleid] = 0.0;
    Percorreu[vehicleid] = 0;
    return DestroyVehicle(vehicleid);
}

/********** HOOKS **************/
#if defined _ALS_CreateVehicle
    #undef CreateVehicle
#else
    #define _ALS_CreateVehicle
#endif
#define CreateVehicle CreateVehicleEx


#if defined _ALS_DestroyVehicle
    #undef DestroyVehicle
#else
    #define _ALS_DestroyVehicle
#endif
#define DestroyVehicle DestroyVehicleEx


#if defined _ALS_OnGameModeInit
    #undef OnGameModeInit
#else
    #define _ALS_OnGameModeInit
#endif

#if defined ModeInit
    forward ModeInit();
#endif
#define OnGameModeInit ModeInit


#if defined _ALS_OnPlayerStateChange
    #undef OnPlayerStateChange
#else
    #define _ALS_OnPlayerStateChange
#endif

#if defined StateChange
    forward StateChange(playerid, newstate, oldstate);
#endif
#define OnPlayerStateChange StateChange


#if defined _ALS_OnPlayerConnect
    #undef OnPlayerConnect
#else
    #define _ALS_OnPlayerConnect
#endif

#if defined OnConnect
    forward OnConnect(playerid);
#endif
#define OnPlayerConnect OnConnect


#if defined _ALS_SetVehiclePos
    #undef SetVehiclePos
#else
    #define _ALS_SetVehiclePos
#endif 

#define SetVehiclePos SetVehiclePosEx