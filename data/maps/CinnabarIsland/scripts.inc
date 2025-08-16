CinnabarIsland_MapScripts::
# 4 "data/maps/CinnabarIsland/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, CinnabarIsland_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 7 "data/maps/CinnabarIsland/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, CinnabarIsland_MapScripts_MAP_SCRIPT_ON_LOAD
# 11 "data/maps/CinnabarIsland/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CinnabarIsland_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

CinnabarIsland_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 5 "data/maps/CinnabarIsland/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_CINNABAR_ISLAND
	return

CinnabarIsland_MapScripts_MAP_SCRIPT_ON_LOAD:
# 8 "data/maps/CinnabarIsland/scripts.pory"
	call_if_eq VAR_MAP_SCENE_SS_ANNE_STATE, 1, CinnabarIsland_EventScript_BlockWater
# 9 "data/maps/CinnabarIsland/scripts.pory"
	call_if_eq VAR_MAP_SCENE_SS_ANNE_STATE, 2, CinnabarIsland_EventScript_BlockWater
	return

CinnabarIsland_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 12 "data/maps/CinnabarIsland/scripts.pory"
	map_script_2 VAR_MAP_SCENE_SS_ANNE_STATE, 1, CinnabarIsland_EventScript_PlayerLeaveShip
	.2byte 0


CinnabarIsland_EventScript_BlockWater::
# 17 "data/maps/CinnabarIsland/scripts.pory"
	setmetatile 5, 17, 0x12B, 1
# 18 "data/maps/CinnabarIsland/scripts.pory"
	setmetatile 6, 17, 0x12B, 1
# 19 "data/maps/CinnabarIsland/scripts.pory"
	setmetatile 7, 17, 0x12B, 1
# 20 "data/maps/CinnabarIsland/scripts.pory"
	setmetatile 8, 17, 0x12B, 1
# 21 "data/maps/CinnabarIsland/scripts.pory"
	setmetatile 9, 17, 0x12B, 1
# 22 "data/maps/CinnabarIsland/scripts.pory"
	setmetatile 10, 17, 0x12B, 1
# 23 "data/maps/CinnabarIsland/scripts.pory"
	setmetatile 11, 17, 0x12B, 1
# 24 "data/maps/CinnabarIsland/scripts.pory"
	setmetatile 12, 17, 0x12C, 1
# 25 "data/maps/CinnabarIsland/scripts.pory"
	setmetatile 5, 16, 0x12B, 1
# 26 "data/maps/CinnabarIsland/scripts.pory"
	setmetatile 6, 16, 0x12B, 1
# 27 "data/maps/CinnabarIsland/scripts.pory"
	setmetatile 7, 16, 0x12B, 1
# 28 "data/maps/CinnabarIsland/scripts.pory"
	setmetatile 8, 16, 0x12B, 1
# 29 "data/maps/CinnabarIsland/scripts.pory"
	setmetatile 9, 16, 0x12B, 1
# 30 "data/maps/CinnabarIsland/scripts.pory"
	setmetatile 10, 16, 0x12B, 1
# 31 "data/maps/CinnabarIsland/scripts.pory"
	setmetatile 11, 16, 0x12B, 1
# 32 "data/maps/CinnabarIsland/scripts.pory"
	setmetatile 12, 16, 0x12C, 1
# 33 "data/maps/CinnabarIsland/scripts.pory"
	setmetatile 8, 15, 0x301, 0
# 34 "data/maps/CinnabarIsland/scripts.pory"
	setmetatile 9, 15, 0x302, 0
# 35 "data/maps/CinnabarIsland/scripts.pory"
	setmetatile 10, 15, 0x303, 0
	end


CinnabarIsland_EventScript_PlayerLeaveShip::
# 40 "data/maps/CinnabarIsland/scripts.pory"
	lockall
# 41 "data/maps/CinnabarIsland/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, CinnabarIsland_Movement_PlayerLeaveShip
# 42 "data/maps/CinnabarIsland/scripts.pory"
	waitmovement 0
# 43 "data/maps/CinnabarIsland/scripts.pory"
	setvar VAR_MAP_SCENE_SS_ANNE_STATE, 2
# 44 "data/maps/CinnabarIsland/scripts.pory"
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 0
# 45 "data/maps/CinnabarIsland/scripts.pory"
	releaseall
	end


# 49 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_Movement_PlayerLeaveShip:
# 50 "data/maps/CinnabarIsland/scripts.pory"
	walk_up
# 50 "data/maps/CinnabarIsland/scripts.pory"
	walk_up
# 50 "data/maps/CinnabarIsland/scripts.pory"
	walk_up
# 50 "data/maps/CinnabarIsland/scripts.pory"
	walk_up
	step_end

CinnabarIsland_EventScript_CheckTicket::
# 54 "data/maps/CinnabarIsland/scripts.pory"
	lockall
# 55 "data/maps/CinnabarIsland/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 56 "data/maps/CinnabarIsland/scripts.pory"
	applymovement 2, Common_Movement_WalkInPlaceFasterLeft
# 57 "data/maps/CinnabarIsland/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 58 "data/maps/CinnabarIsland/scripts.pory"
	waitmovement 0
# 59 "data/maps/CinnabarIsland/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_SS_ANNE_STATE, 2, CinnabarIsland_EventScript_SSAnneHere
# 60 "data/maps/CinnabarIsland/scripts.pory"
	msgbox CinnabarIsland_Text_SSAnneNotHere
# 61 "data/maps/CinnabarIsland/scripts.pory"
	closemessage
# 62 "data/maps/CinnabarIsland/scripts.pory"
	goto VermilionCity_EventScript_WalkUpPier
	end


CinnabarIsland_EventScript_ExitedTicketCheck::
# 67 "data/maps/CinnabarIsland/scripts.pory"
	lockall
# 68 "data/maps/CinnabarIsland/scripts.pory"
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 0
# 69 "data/maps/CinnabarIsland/scripts.pory"
	releaseall
	end


CinnabarIsland_EventScript_SSAnneHere::
# 75 "data/maps/CinnabarIsland/scripts.pory"
	msgbox CinnabarIsland_Text_DoYouHaveATicket
# 76 "data/maps/CinnabarIsland/scripts.pory"
	checkitem ITEM_SS_TICKET
# 77 "data/maps/CinnabarIsland/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, CinnabarIsland_EventScript_DontHaveSSTicket
# 78 "data/maps/CinnabarIsland/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 79 "data/maps/CinnabarIsland/scripts.pory"
	msgbox CinnabarIsland_Text_FlashedSSTicket
# 80 "data/maps/CinnabarIsland/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 81 "data/maps/CinnabarIsland/scripts.pory"
	msgbox CinnabarIsland_Text_FlashedSSTicket2
# 82 "data/maps/CinnabarIsland/scripts.pory"
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 1
# 83 "data/maps/CinnabarIsland/scripts.pory"
	releaseall
	return


CinnabarIsland_EventScript_DontHaveSSTicket::
# 87 "data/maps/CinnabarIsland/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 88 "data/maps/CinnabarIsland/scripts.pory"
	msgbox CinnabarIsland_Text_DontHaveNeededSSTicket
# 89 "data/maps/CinnabarIsland/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 90 "data/maps/CinnabarIsland/scripts.pory"
	msgbox CinnabarIsland_Text_DontHaveNeededSSTicket2
# 91 "data/maps/CinnabarIsland/scripts.pory"
	goto CinnabarIsland_EventScript_WalkUpPier
	end


CinnabarIsland_EventScript_WalkUpPier::
# 96 "data/maps/CinnabarIsland/scripts.pory"
	closemessage
# 97 "data/maps/CinnabarIsland/scripts.pory"
	applymovement 2, Common_Movement_FaceOriginalDirection
# 98 "data/maps/CinnabarIsland/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
# 99 "data/maps/CinnabarIsland/scripts.pory"
	waitmovement 0
# 100 "data/maps/CinnabarIsland/scripts.pory"
	releaseall
	end


CinnabarIsland_EventScript_FerrySailor::
# 109 "data/maps/CinnabarIsland/scripts.pory"
	lock
# 110 "data/maps/CinnabarIsland/scripts.pory"
	faceplayer
# 111 "data/maps/CinnabarIsland/scripts.pory"
	msgbox CinnabarIsland_Text_WelcomeToTheSSAnne
# 112 "data/maps/CinnabarIsland/scripts.pory"
	release
	end


# 145 "data/maps/CinnabarIsland/scripts.pory"

# 146 "data/maps/CinnabarIsland/scripts.pory"

# 147 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_EventScript_IslandSign::
# 148 "data/maps/CinnabarIsland/scripts.pory"
	msgbox CinnabarIsland_Text_IslandSign, MSGBOX_SIGN
# 149 "data/maps/CinnabarIsland/scripts.pory"
	end
# 150 "data/maps/CinnabarIsland/scripts.pory"

# 151 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_EventScript_PokemonLabSign::
# 152 "data/maps/CinnabarIsland/scripts.pory"
	msgbox CinnabarIsland_Text_PokemonLab, MSGBOX_SIGN
# 153 "data/maps/CinnabarIsland/scripts.pory"
	end
# 154 "data/maps/CinnabarIsland/scripts.pory"

# 155 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_EventScript_GymSign::
# 156 "data/maps/CinnabarIsland/scripts.pory"
	lockall
# 157 "data/maps/CinnabarIsland/scripts.pory"
	famechecker FAMECHECKER_BLAINE, 0
# 158 "data/maps/CinnabarIsland/scripts.pory"
	msgbox CinnabarIsland_Text_GymSign
# 159 "data/maps/CinnabarIsland/scripts.pory"
	releaseall
# 160 "data/maps/CinnabarIsland/scripts.pory"
	end

CinnabarIsland_Text_SSAnneNotHere::
# 104 "data/maps/CinnabarIsland/scripts.pory"
	.string "As you can see, the boat ain't\n"
	.string "here right now.$"

CinnabarIsland_Text_DoYouHaveATicket::
# 116 "data/maps/CinnabarIsland/scripts.pory"
	.string "This is the dock for the S.S. ANNE.\p"
	.string "You got a ticket or something?$"

CinnabarIsland_Text_WelcomeToTheSSAnne::
# 121 "data/maps/CinnabarIsland/scripts.pory"
	.string "Err, hey.\n"
	.string "This is the dock for the S.S. ANNE.$"

CinnabarIsland_Text_FlashedSSTicket::
# 125 "data/maps/CinnabarIsland/scripts.pory"
	.string "{PLAYER} flashed the S.S. TICKET!$"

CinnabarIsland_Text_FlashedSSTicket2::
# 129 "data/maps/CinnabarIsland/scripts.pory"
	.string "Nyeh...\n"
	.string "Alright, come on in...$"

CinnabarIsland_Text_DontHaveNeededSSTicket::
# 134 "data/maps/CinnabarIsland/scripts.pory"
	.string "{PLAYER} doesn't have the needed\n"
	.string "S.S. TICKET.$"

CinnabarIsland_Text_DontHaveNeededSSTicket2::
# 139 "data/maps/CinnabarIsland/scripts.pory"
	.string "Get outta here!\p"
	.string "Don't you know you need a ticket?$"
