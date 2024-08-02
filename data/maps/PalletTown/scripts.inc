PalletTown_MapScripts::
# 4 "data/maps/PalletTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

PalletTown_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 5 "data/maps/PalletTown/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_PALLET_TOWN
	return


PalletTown_EventScript_AideTriggerLeft::
# 11 "data/maps/PalletTown/scripts.pory"
	lockall
# 12 "data/maps/PalletTown/scripts.pory"
	setvar VAR_TEMP_1, 0
# 13 "data/maps/PalletTown/scripts.pory"
	goto PalletTown_EventScript_AideIntro
	end


PalletTown_EventScript_AideTriggerRight::
# 18 "data/maps/PalletTown/scripts.pory"
	lockall
# 19 "data/maps/PalletTown/scripts.pory"
	setvar VAR_TEMP_1, 1
# 20 "data/maps/PalletTown/scripts.pory"
	goto PalletTown_EventScript_AideIntro
	end


PalletTown_EventScript_AideIntro::
# 25 "data/maps/PalletTown/scripts.pory"
	playse SE_PIN
# 26 "data/maps/PalletTown/scripts.pory"
	applymovement 1, Common_Movement_ExclamDown
# 27 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 28 "data/maps/PalletTown/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 29 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_AideTalk
# 30 "data/maps/PalletTown/scripts.pory"
	closemessage
# 31 "data/maps/PalletTown/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, PalletTown_EventScript_PlayerWalkingToAideLeft
# 32 "data/maps/PalletTown/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, PalletTown_EventScript_PlayerWalkingToAideRight
# 33 "data/maps/PalletTown/scripts.pory"
	applymovement 1, PalletTown_Movement_AideToLab
# 34 "data/maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Movement_PlayerToLab
# 35 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 36 "data/maps/PalletTown/scripts.pory"
	opendoor 19, 7
# 37 "data/maps/PalletTown/scripts.pory"
	waitdooranim
# 38 "data/maps/PalletTown/scripts.pory"
	applymovement 1, PalletTown_Movement_AideEnterLab
# 39 "data/maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Movement_PlayerEnterLab
# 40 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 41 "data/maps/PalletTown/scripts.pory"
	closedoor 19, 7
# 42 "data/maps/PalletTown/scripts.pory"
	waitdooranim
# 43 "data/maps/PalletTown/scripts.pory"
	setflag FLAG_0x200
# 44 "data/maps/PalletTown/scripts.pory"
	setvar VAR_0x4029, 1
# 45 "data/maps/PalletTown/scripts.pory"
	setflag FLAG_BADGE01_GET
# 46 "data/maps/PalletTown/scripts.pory"
	setflag FLAG_BADGE02_GET
# 47 "data/maps/PalletTown/scripts.pory"
	setflag FLAG_BADGE03_GET
# 48 "data/maps/PalletTown/scripts.pory"
	setflag FLAG_BADGE04_GET
# 49 "data/maps/PalletTown/scripts.pory"
	setflag FLAG_BADGE05_GET
# 50 "data/maps/PalletTown/scripts.pory"
	setflag FLAG_BADGE06_GET
# 51 "data/maps/PalletTown/scripts.pory"
	setflag FLAG_BADGE07_GET
# 52 "data/maps/PalletTown/scripts.pory"
	setflag FLAG_BADGE08_GET
# 54 "data/maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1
# 55 "data/maps/PalletTown/scripts.pory"
	giveitem ITEM_BICYCLE
# 56 "data/maps/PalletTown/scripts.pory"
	setflag FLAG_GOT_BICYCLE
# 57 "data/maps/PalletTown/scripts.pory"
	setflag FLAG_HIDE_GIO_RUINS
# 59 "data/maps/PalletTown/scripts.pory"
	setflag FLAG_HIDE_DAISY_VIRIDIAN
# 60 "data/maps/PalletTown/scripts.pory"
	setflag FLAG_HIDE_GIO_OBSIDIAN
# 62 "data/maps/PalletTown/scripts.pory"
	warp MAP_PALLET_TOWN_PROFESSOR_OAKS_LAB, 6, 12
# 63 "data/maps/PalletTown/scripts.pory"
	waitstate
# 64 "data/maps/PalletTown/scripts.pory"
	releaseall
	return


PalletTown_EventScript_PlayerWalkingToAideLeft::
# 72 "data/maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Movement_PlayerWalkToAideLeft
# 73 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
	return


PalletTown_EventScript_PlayerWalkingToAideRight::
# 78 "data/maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Movement_PlayerWalkToAideRight
# 79 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
	return


# 83 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_PlayerWalkToAideLeft:
# 84 "data/maps/PalletTown/scripts.pory"
	walk_up
# 84 "data/maps/PalletTown/scripts.pory"
	walk_up
# 85 "data/maps/PalletTown/scripts.pory"
	step_end

# 88 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_PlayerWalkToAideRight:
# 89 "data/maps/PalletTown/scripts.pory"
	walk_up
# 90 "data/maps/PalletTown/scripts.pory"
	walk_left
# 91 "data/maps/PalletTown/scripts.pory"
	walk_up
# 92 "data/maps/PalletTown/scripts.pory"
	step_end

# 95 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_AideToLab:
# 96 "data/maps/PalletTown/scripts.pory"
	walk_left
# 96 "data/maps/PalletTown/scripts.pory"
	walk_left
# 96 "data/maps/PalletTown/scripts.pory"
	walk_left
# 97 "data/maps/PalletTown/scripts.pory"
	walk_in_place_faster_up
# 98 "data/maps/PalletTown/scripts.pory"
	step_end

# 101 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_PlayerToLab:
# 102 "data/maps/PalletTown/scripts.pory"
	walk_up
# 103 "data/maps/PalletTown/scripts.pory"
	walk_left
# 103 "data/maps/PalletTown/scripts.pory"
	walk_left
# 104 "data/maps/PalletTown/scripts.pory"
	step_end

# 107 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_AideEnterLab:
# 108 "data/maps/PalletTown/scripts.pory"
	walk_up
# 109 "data/maps/PalletTown/scripts.pory"
	set_invisible
# 110 "data/maps/PalletTown/scripts.pory"
	step_end

# 113 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_PlayerEnterLab:
# 114 "data/maps/PalletTown/scripts.pory"
	walk_left
# 115 "data/maps/PalletTown/scripts.pory"
	walk_up
# 116 "data/maps/PalletTown/scripts.pory"
	set_invisible
# 117 "data/maps/PalletTown/scripts.pory"
	step_end

PalletTown_EventScript_SoaksLabSign::
# 121 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_SoakLab, MSGBOX_SIGN
	end


PalletTown_EventScript_PlayersHouseSign::
# 126 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_PlayersHouse, MSGBOX_SIGN
	end


PalletTown_EventScript_RivalsHouseSign::
# 131 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_RivalsHouse, MSGBOX_SIGN
	end


PalletTown_EventScript_TownSign::
# 136 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_TownSign, MSGBOX_SIGN
	end


PalletTown_EventScript_Lass::
# 157 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_Lass, MSGBOX_NPC
	return


PalletTown_EventScript_FatMan::
# 161 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_FatMan, MSGBOX_NPC
	return


PalletTown_EventScript_Fisher::
# 165 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_Fisher, MSGBOX_NPC
	return


PalletTown_Text_AideTalk::
# 67 "data/maps/PalletTown/scripts.pory"
	.string "Ah! {PLAYER}!\n"
	.string "Please quickly come inside with me!\p"
	.string "PROF. SOAK is already waiting for you\n"
	.string "with {RIVAL}!$"

PalletTown_Text_SoakLab::
# 140 "data/maps/PalletTown/scripts.pory"
	.string "PROFESSOR SOAK'S RESEARCH LAB$"

PalletTown_Text_PlayersHouse::
# 144 "data/maps/PalletTown/scripts.pory"
	.string "{PLAYER}'S HOUSE$"

PalletTown_Text_RivalsHouse::
# 148 "data/maps/PalletTown/scripts.pory"
	.string "{RIVAL}'S HOUSE$"

PalletTown_Text_TownSign::
# 152 "data/maps/PalletTown/scripts.pory"
	.string "PALLET TOWN\n"
	.string "Splashes of your journey await!$"

PalletTown_Text_Lass::
# 168 "data/maps/PalletTown/scripts.pory"
	.string "FILL THIS IN$"

PalletTown_Text_FatMan::
# 172 "data/maps/PalletTown/scripts.pory"
	.string "Technology is amazing!\p"
	.string "You can now compress POKéMON into\n"
	.string "tiny particles of data and send\l"
	.string "them to your PC!$"

PalletTown_Text_Fisher::
# 176 "data/maps/PalletTown/scripts.pory"
	.string "FILL THIS IN$"
