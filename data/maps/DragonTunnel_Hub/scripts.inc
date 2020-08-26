DragonTunnel_Hub_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DragonTunnel_Hub_OnTransition
	.byte 0

DragonTunnel_Hub_OnTransition:
	setrespawn HEAL_LOCATION_DRAGON_TUNNEL
	end


DragonTunnel_Hub_EventScript_ReceivePrimeape:: @ 827004D
	msgbox DragonTunnel_Hub_Text_ThanksPleaseTakePokemon, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, SPECIES_PRIMEAPE
	givemon SPECIES_PRIMEAPE, 28, ITEM_NONE
	compare VAR_RESULT, 0
	goto_if_eq DragonTunnel_Hub_EventScript_ReceiveCastformParty
	goto Common_EventScript_NoMoreRoomForPokemon
	end

DragonTunnel_Hub_EventScript_ReceiveCastformParty:: @ 8270085
	call Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq DragonTunnel_Hub_EventScript_ExplainCastform
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto DragonTunnel_Hub_EventScript_ExplainCastform
	end

DragonTunnel_Hub_EventScript_ExplainCastform:: @ 82700EA
	msgbox DragonTunnel_Hub_Text_PokemonChangesWithWeather, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_PRIMEAPE
	release
	end

DragonTunnel_Hub_Text_ThanksPleaseTakePokemon: @ 8270650
	.string "Here, take this.$"

DragonTunnel_Hub_Text_PokemonChangesWithWeather: @ 82706FE
	.string "Treat it with care.$"