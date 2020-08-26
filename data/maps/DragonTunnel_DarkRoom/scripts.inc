DragonTunnel_DarkRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, DragonTunnel_DarkRoom_SetHoleWarp
	.byte 0

DragonTunnel_DarkRoom_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_DRAGON_TUNNEL_2D, 255, 0, 0
	end
