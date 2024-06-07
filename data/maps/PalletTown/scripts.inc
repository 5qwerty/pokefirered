PalletTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

PalletTown_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setworldmapflag FLAG_WORLD_MAP_PALLET_TOWN
	return


PalletTown_EventScript_AideTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 0
	goto PalletTown_EventScript_AideIntro
	end


PalletTown_EventScript_AideTriggerRight::
	lockall
	setvar VAR_TEMP_1, 1
	goto PalletTown_EventScript_AideIntro
	end


PalletTown_EventScript_AideIntro::
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamDown
	waitmovement 0
	textcolor NPC_TEXT_COLOR_MALE
	msgbox PalletTown_Text_AideTalk
	closemessage
	call_if_eq VAR_TEMP_1, 0, PalletTown_EventScript_PlayerWalkingToAideLeft
	call_if_eq VAR_TEMP_1, 1, PalletTown_EventScript_PlayerWalkingToAideRight
	applymovement 1, PalletTown_Movement_AideToLab
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Movement_PlayerToLab
	waitmovement 0
	opendoor 19, 7
	waitdooranim
	applymovement 1, PalletTown_Movement_AideEnterLab
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Movement_PlayerEnterLab
	waitmovement 0
	closedoor 19, 7
	waitdooranim
	setflag FLAG_0x200
	setvar VAR_0x4029, 1
	setflag FLAG_BADGE01_GET
	setflag FLAG_BADGE02_GET
	setflag FLAG_BADGE03_GET
	setflag FLAG_BADGE04_GET
	setflag FLAG_BADGE05_GET
	setflag FLAG_BADGE06_GET
	setflag FLAG_BADGE07_GET
	setflag FLAG_BADGE08_GET
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1
	giveitem ITEM_BICYCLE
	setflag FLAG_GOT_BICYCLE
	setflag FLAG_HIDE_DAISY_VIRIDIAN
	setflag FLAG_HIDE_GIO_OBSIDIAN
	warp MAP_PALLET_TOWN_PROFESSOR_OAKS_LAB, 6, 12
	waitstate
	releaseall
	return


PalletTown_EventScript_PlayerWalkingToAideLeft::
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Movement_PlayerWalkToAideLeft
	waitmovement 0
	return


PalletTown_EventScript_PlayerWalkingToAideRight::
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Movement_PlayerWalkToAideRight
	waitmovement 0
	return


PalletTown_Movement_PlayerWalkToAideLeft:
	walk_up
	walk_up
	step_end

PalletTown_Movement_PlayerWalkToAideRight:
	walk_up
	walk_left
	walk_up
	step_end

PalletTown_Movement_AideToLab:
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

PalletTown_Movement_PlayerToLab:
	walk_up
	walk_left
	walk_left
	step_end

PalletTown_Movement_AideEnterLab:
	walk_up
	set_invisible
	step_end

PalletTown_Movement_PlayerEnterLab:
	walk_left
	walk_up
	set_invisible
	step_end

PalletTown_EventScript_SoaksLabSign::
	msgbox PalletTown_Text_SoakLab, MSGBOX_SIGN
	end


PalletTown_EventScript_PlayersHouseSign::
	msgbox PalletTown_Text_PlayersHouse, MSGBOX_SIGN
	end


PalletTown_EventScript_RivalsHouseSign::
	msgbox PalletTown_Text_RivalsHouse, MSGBOX_SIGN
	end


PalletTown_EventScript_TownSign::
	msgbox PalletTown_Text_TownSign, MSGBOX_SIGN
	end


PalletTown_EventScript_Lass::
	msgbox PalletTown_Text_Lass, MSGBOX_NPC
	return


PalletTown_EventScript_FatMan::
	msgbox PalletTown_Text_FatMan, MSGBOX_NPC
	return


PalletTown_EventScript_Fisher::
	msgbox PalletTown_Text_Fisher, MSGBOX_NPC
	return


PalletTown_Text_AideTalk::
	.string "Ah! {PLAYER}!\n"
	.string "Please quickly come inside with me!\p"
	.string "PROF. SOAK is already waiting for you\n"
	.string "with {RIVAL}!$"

PalletTown_Text_SoakLab::
	.string "PROFESSOR SOAK'S RESEARCH LAB$"

PalletTown_Text_PlayersHouse::
	.string "{PLAYER}'S HOUSE$"

PalletTown_Text_RivalsHouse::
	.string "{RIVAL}'S HOUSE$"

PalletTown_Text_TownSign::
	.string "PALLET TOWN\n"
	.string "Splashes of your journey await!$"

PalletTown_Text_Lass::
	.string "FILL THIS IN$"

PalletTown_Text_FatMan::
	.string "Technology is amazing!\p"
	.string "You can now compress POKéMON into\n"
	.string "tiny particles of data and send\l"
	.string "them to your PC!$"

PalletTown_Text_Fisher::
	.string "FILL THIS IN$"
