DragonTunnel_1R_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, DragonTunnel_1R_SetHoleWarp
	.byte 0

DragonTunnel_1R_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_DRAGON_TUNNEL_2R, 255, 0, 0
	end
