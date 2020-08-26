DragonTunnel_3F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, DragonTunnel_3F_SetHoleWarp
	.byte 0

DragonTunnel_3F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_DRAGON_TUNNEL_ICE_ROOM, 255, 0, 0
	end
