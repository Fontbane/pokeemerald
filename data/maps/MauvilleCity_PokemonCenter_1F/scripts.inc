MauvilleCity_PokemonCenter_1F_MapScripts:: @ 8210E5B
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

MauvilleCity_PokemonCenter_1F_OnTransition: @ 8210E66
	setrespawn HEAL_LOCATION_MAUVILLE_CITY
	call Common_EventScript_UpdateBrineyLocation
	goto MauvilleCity_PokemonCenter_1F_EventScript_SetMauvilleOldManGfx
	end

MauvilleCity_PokemonCenter_1F_EventScript_SetMauvilleOldManGfx:: @ 8210E74
	special ScrSpecial_SetMauvilleOldManObjEventGfx
	end

@ VAR_0x800B is the Nurse's object event id
MauvilleCity_PokemonCenter_1F_EventScript_Nurse:: @ 8210E78
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_Woman1:: @ 8210E86
	msgbox MauvilleCity_PokemonCenter_1F_Text_ManOverThereSaysWeirdThings, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_EventScript_Woman2:: @ 8210E8F
	msgbox MauvilleCity_PokemonCenter_1F_Text_MyDataUpdatedFromRecordCorner, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_EventScript_Youngster:: @ 8210E98
	msgbox MauvilleCity_PokemonCenter_1F_Text_RecordCornerSoundsFun, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_EventScript_GeodudeTrader:: @ 8203C11
	faceplayer
	setvar VAR_0x8008, INGAME_TRADE_GEODUDE
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox MauvilleCity_PokemonCenter_1F_Text_GeodudeWantToTrade, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_DeclineAlolaTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	compare VAR_0x8004, 255
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_DeclineAlolaTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	compare VAR_RESULT, VAR_0x8009
	goto_if_ne MauvilleCity_PokemonCenter_1F_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname 0, VAR_0x8009
	msgbox MauvilleCity_PokemonCenter_1F_GeodudeThankYou, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_SandshrewTrader:: @ 8203C11
	faceplayer
	setvar VAR_0x8008, INGAME_TRADE_SANDSHREW
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox MauvilleCity_PokemonCenter_1F_Text_SandshrewWantToTrade, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_DeclineAlolaTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	compare VAR_0x8004, 255
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_DeclineAlolaTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	compare VAR_RESULT, VAR_0x8009
	goto_if_ne MauvilleCity_PokemonCenter_1F_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname 0, VAR_0x8009
	msgbox MauvilleCity_PokemonCenter_1F_SandshrewThankYou, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_VulpixTrader:: @ 8203C11
	faceplayer
	setvar VAR_0x8008, INGAME_TRADE_VULPIX
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox MauvilleCity_PokemonCenter_1F_Text_VulpixWantToTrade, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_DeclineAlolaTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	compare VAR_0x8004, 255
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_DeclineAlolaTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	compare VAR_RESULT, VAR_0x8009
	goto_if_ne MauvilleCity_PokemonCenter_1F_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname 0, VAR_0x8009
	msgbox MauvilleCity_PokemonCenter_1F_VulpixThankYou, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_GrimerTrader:: @ 8203C11
	faceplayer
	setvar VAR_0x8008, INGAME_TRADE_GRIMER
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox MauvilleCity_PokemonCenter_1F_Text_GrimerWantToTrade, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_DeclineAlolaTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	compare VAR_0x8004, 255
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_DeclineAlolaTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	compare VAR_RESULT, VAR_0x8009
	goto_if_ne MauvilleCity_PokemonCenter_1F_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname 0, VAR_0x8009
	lock
	msgbox MauvilleCity_PokemonCenter_1F_GrimerThankYou, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DarumakaTrader:: @ 8203C11
	faceplayer
	setvar VAR_0x8008, INGAME_TRADE_DARUMAKA
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox MauvilleCity_PokemonCenter_1F_Text_DarumakaWantToTrade, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_DeclineAlolaTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	compare VAR_0x8004, 255
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_DeclineAlolaTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	compare VAR_RESULT, VAR_0x8009
	goto_if_ne MauvilleCity_PokemonCenter_1F_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname 0, VAR_0x8009
	msgbox MauvilleCity_PokemonCenter_1F_DarumakaThankYou, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineAlolaTrade:: @ 8203C93
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatsAlright, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_NotRequestedMon:: @ 8203C9D
	bufferspeciesname 0, VAR_0x8009
	msgbox MauvilleCity_PokemonCenter_1F_Text_NotWhatIWanted, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_Text_ManOverThereSaysWeirdThings: @ 8210EA1
	.string "That man over there, he says weird\n"
	.string "things!\p"
	.string "He's funny in a weird way.\n"
	.string "I doubt I'll forget about him!$"

MauvilleCity_PokemonCenter_1F_Text_MyDataUpdatedFromRecordCorner: @ 8210F06
	.string "When I accessed the RECORD CORNER,\n"
	.string "the data for what's hot in DEWFORD\l"
	.string "got updated.\p"
	.string "Now that bit of data is the same\n"
	.string "as my friend's!$"

MauvilleCity_PokemonCenter_1F_Text_RecordCornerSoundsFun: @ 8210F8A
	.string "A RECORD CORNER opened upstairs in\n"
	.string "the POKéMON CENTER.\p"
	.string "I don't know what it's about, but it\n"
	.string "sounds fun. I'll go check it out!$"

MauvilleCity_PokemonCenter_1F_Text_GeodudeWantToTrade:
	.string "Hoenn!\p"
	.string "I want a Geodude that was\n"
	.string "caught around here.\p"
	.string "In exchange, I'll give you an exotic\n"
	.string "Geodude from my region!\p"
	.string "Would you like to trade?$"

MauvilleCity_PokemonCenter_1F_Text_SandshrewWantToTrade:
	.string "I want a Sandshrew that was\n"
	.string "caught from around here.\p"
	.string "I'll trade you for a really\n"
	.string "cool Sandshrew from my region!\p"
	.string "Would you like to trade?$"

MauvilleCity_PokemonCenter_1F_Text_VulpixWantToTrade:
	.string "I'm looking for, how you say...\p"
	.string "A Vulpix.\p"
	.string "I have plenty of Vulpix from home\n"
	.string "that I could give you in exchange.\p"
	.string "Would you like to trade?$"

MauvilleCity_PokemonCenter_1F_Text_GrimerWantToTrade:
	.string "I hear Grimer is ridiculously rare\n"
	.string "in the Hoenn region, in Fiery Path.\p"
	.string "If you manage to find one, I have\n"
	.string "a slick Grimer from Hau'oli City.\p"
	.string "Would you like to trade?$"

MauvilleCity_PokemonCenter_1F_Text_DarumakaWantToTrade:
	.string "Darumaka is my favourite!\p"
	.string "My Darumaka is really cool, but\n"
	.string "I hear local Darumaka are real hot.\p"
	.string "I'll trade you my cool Darumaka\n"
	.string "for your hot Darumaka!\p"
	.string "Wanna trade?$"

MauvilleCity_PokemonCenter_1F_Text_ThatsAlright:
	.string "That's alright, I'm in no rush.$"

MauvilleCity_PokemonCenter_1F_Text_NotWhatIWanted:
	.string "Ah, that's not quite the Pokémon\n"
	.string "I was looking for.$"

MauvilleCity_PokemonCenter_1F_GeodudeThankYou: @ 8203D87
	.string "Oh, so this is a Geodude from\n"
	.string "the Hoenn region? Interesting.\p"
	.string "It's sort of like my Geodude,\n"
	.string "and yet it's subtly different.\p"
	.string "Thank you!$"

MauvilleCity_PokemonCenter_1F_SandshrewThankYou: @ 8203D87
	.string "Huh, this Sandshrew isn't quite\n"
	.string "as cool as my old one.\p"
	.string "Though I think I still like it.\n"
	.string "It feels more grounded.\p"
	.string "Thank you!$"
	
MauvilleCity_PokemonCenter_1F_VulpixThankYou: @ 8203D87
	.string "Ah, so this is what they call\n"
	.string "a Vulpix.\p"
	.string "It's more wispy than the\n"
	.string "ones we have back home.\p"
	.string "Thank you!$"

MauvilleCity_PokemonCenter_1F_GrimerThankYou: @ 8203D87
	.string "Take good care of my Grimer.\p"
	.string "It likes to eat garbage, so I'm\n"
	.string "certain it would get along with you.\p"
	.string "Thank you!$"
	
MauvilleCity_PokemonCenter_1F_DarumakaThankYou: @ 8203D87
	.string "Ah, finally, a Unova Darumaka!\p"
	.string "Its droppings will keep me warm\n"
	.string "in the cold Crown Tundra weather!\p"
	.string "Thanks a tonne!$"
