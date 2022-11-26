#include <a_samp>

#pragma dynamic 600000

#define MOVE_SPEED              100.0
#define ACCEL_RATE              0.03


#define CAMERA_MODE_NONE    	0
#define CAMERA_MODE_FLY     	1


#define MOVE_FORWARD    		1
#define MOVE_BACK       		2
#define MOVE_LEFT       		3
#define MOVE_RIGHT      		4
#define MOVE_FORWARD_LEFT       5
#define MOVE_FORWARD_RIGHT      6
#define MOVE_BACK_LEFT          7
#define MOVE_BACK_RIGHT         8

// Enumeration for storing data about the player
enum noclipenum
{
	cameramode,
	flyobject,
	mode,
	lrold,
	udold,
	lastmove,
	Float:accelmul
}
new noclipdata[MAX_PLAYERS][noclipenum];

//--------------------------------------------------
public OnFilterScriptInit()
{
	print("[FS] Carregando Flymode...");
	return 1;
}

public OnFilterScriptExit()
{
	for(new i; i < MAX_PLAYERS; i++) {
		if(noclipdata[i][cameramode] == CAMERA_MODE_FLY) CancelFlyMode(i);
    }
	return 1;
}

public OnPlayerConnect(playerid)
{
	noclipdata[playerid][cameramode] 	= CAMERA_MODE_NONE;
	noclipdata[playerid][lrold]	   	 	= 0;
	noclipdata[playerid][udold]   		= 0;
	noclipdata[playerid][mode]   		= 0;
	noclipdata[playerid][lastmove]   	= 0;
	noclipdata[playerid][accelmul]   	= 0.0;
	return 1;
}

public OnPlayerUpdate(playerid)
{
	if(noclipdata[playerid][cameramode] == CAMERA_MODE_FLY)
	{
		new keys,ud,lr;
		GetPlayerKeys(playerid,keys,ud,lr);

		if(noclipdata[playerid][mode] && (GetTickCount() - noclipdata[playerid][lastmove] > 100))
		{
		    // If the last move was > 100ms ago, process moving the object the players camera is attached to
		    MoveCamera(playerid);
		}

		// Is the players current key state different than their last keystate?
		if(noclipdata[playerid][udold] != ud || noclipdata[playerid][lrold] != lr)
		{
			if((noclipdata[playerid][udold] != 0 || noclipdata[playerid][lrold] != 0) && ud == 0 && lr == 0)
			{   // All keys have been released, stop the object the camera is attached to and reset the acceleration multiplier
				StopPlayerObject(playerid, noclipdata[playerid][flyobject]);
				noclipdata[playerid][mode]      = 0;
				noclipdata[playerid][accelmul]  = 0.0;
			}
			else
			{   // Indicates a new key has been pressed

			    // Get the direction the player wants to move as indicated by the keys
				noclipdata[playerid][mode] = GetMoveDirectionFromKeys(ud, lr);

				// Process moving the object the players camera is attached to
				MoveCamera(playerid);
			}
		}
		noclipdata[playerid][udold] = ud; noclipdata[playerid][lrold] = lr; // Store current keys pressed for comparison next update
        return 0;
	}
    return 1;
}

stock GetMoveDirectionFromKeys(ud, lr)
{
	new direction = 0;
	
    if(lr < 0)
	{
		if(ud < 0) 		direction = MOVE_FORWARD_LEFT; 	// Up & Left key pressed
		else if(ud > 0) direction = MOVE_BACK_LEFT; 	// Back & Left key pressed
		else            direction = MOVE_LEFT;          // Left key pressed
	}
	else if(lr > 0) 	// Right pressed
	{
		if(ud < 0)      direction = MOVE_FORWARD_RIGHT;  // Up & Right key pressed
		else if(ud > 0) direction = MOVE_BACK_RIGHT;     // Back & Right key pressed
		else			direction = MOVE_RIGHT;          // Right key pressed
	}
	else if(ud < 0) 	direction = MOVE_FORWARD; 	// Up key pressed
	else if(ud > 0) 	direction = MOVE_BACK;		// Down key pressed
	
	return direction;
}

stock MoveCamera(playerid)
{
	new Float:FV[3], Float:CP[3];
	GetPlayerCameraPos(playerid, CP[0], CP[1], CP[2]);          // 	Cameras position in space
    GetPlayerCameraFrontVector(playerid, FV[0], FV[1], FV[2]);  //  Where the camera is looking at

	// Increases the acceleration multiplier the longer the key is held
	if(noclipdata[playerid][accelmul] <= 1) noclipdata[playerid][accelmul] += ACCEL_RATE;

	// Determine the speed to move the camera based on the acceleration multiplier
	new Float:speed = MOVE_SPEED * noclipdata[playerid][accelmul];

	// Calculate the cameras next position based on their current position and the direction their camera is facing
	new Float:x, Float:y, Float:z;
	GetNextCameraPosition(noclipdata[playerid][mode], CP, FV, x, y, z);
	MovePlayerObject(playerid, noclipdata[playerid][flyobject], x, y, z, speed);

	// Store the last time the camera was moved as now
	noclipdata[playerid][lastmove] = GetTickCount();
	return 1;
}

stock GetNextCameraPosition(move_mode, const Float:CP[3], const Float:FV[3], &Float:x, &Float:y, &Float:z)
{
    #define OFFSET_X (FV[0] * 6000.0)
	#define OFFSET_Y (FV[1] * 6000.0)
	#define OFFSET_Z (FV[2] * 6000.0)
	switch(move_mode)
	{
		case MOVE_FORWARD:
		{
			x = CP[0]+OFFSET_X;
			y = CP[1]+OFFSET_Y;
			z = CP[2]+OFFSET_Z;
		}
		case MOVE_BACK:
		{
			x = CP[0]-OFFSET_X;
			y = CP[1]-OFFSET_Y;
			z = CP[2]-OFFSET_Z;
		}
		case MOVE_LEFT:
		{
			x = CP[0]-OFFSET_Y;
			y = CP[1]+OFFSET_X;
			z = CP[2];
		}
		case MOVE_RIGHT:
		{
			x = CP[0]+OFFSET_Y;
			y = CP[1]-OFFSET_X;
			z = CP[2];
		}
		case MOVE_BACK_LEFT:
		{
			x = CP[0]+(-OFFSET_X - OFFSET_Y);
 			y = CP[1]+(-OFFSET_Y + OFFSET_X);
		 	z = CP[2]-OFFSET_Z;
		}
		case MOVE_BACK_RIGHT:
		{
			x = CP[0]+(-OFFSET_X + OFFSET_Y);
 			y = CP[1]+(-OFFSET_Y - OFFSET_X);
		 	z = CP[2]-OFFSET_Z;
		}
		case MOVE_FORWARD_LEFT:
		{
			x = CP[0]+(OFFSET_X  - OFFSET_Y);
			y = CP[1]+(OFFSET_Y  + OFFSET_X);
			z = CP[2]+OFFSET_Z;
		}
		case MOVE_FORWARD_RIGHT:
		{
			x = CP[0]+(OFFSET_X  + OFFSET_Y);
			y = CP[1]+(OFFSET_Y  - OFFSET_X);
			z = CP[2]+OFFSET_Z;
		}
	}
}

forward CancelFlyMode(playerid);
public CancelFlyMode(playerid)
{
	DeletePVar(playerid, "FlyMode");
	CancelEdit(playerid);
	TogglePlayerSpectating(playerid, false);

	new Float:x, Float:y, Float:z;
	GetPlayerObjectPos(playerid, noclipdata[playerid][flyobject], x, y, z);
	SetPlayerPos(playerid, x, y, z);
	
	DestroyPlayerObject(playerid, noclipdata[playerid][flyobject]);
	noclipdata[playerid][cameramode] = CAMERA_MODE_NONE;
	return 1;
}

forward FlyMode(playerid);
public FlyMode(playerid)
{
	new Float:x, Float:y, Float:z;
	GetPlayerPos(playerid, x, y, z);
	noclipdata[playerid][flyobject] = CreatePlayerObject(playerid, 19300, x, y, z, 0.0, 0.0, 0.0);

	// Place the player in spectating mode so objects will be streamed based on camera location
	TogglePlayerSpectating(playerid, true);
	// Attach the players camera to the created object
	AttachCameraToPlayerObject(playerid, noclipdata[playerid][flyobject]);

	SetPVarInt(playerid, "FlyMode", 1);
	noclipdata[playerid][cameramode] = CAMERA_MODE_FLY;
	return 1;
}

public OnRconCommand(cmd[])
{
	return 0;
}