ViridianCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

ViridianCity_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setworldmapflag FLAG_WORLD_MAP_VIRIDIAN_CITY
	call_if_lt VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 3, ViridianCity_EventScript_SetOldManBlockingRoad
	call_if_ge VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 3, ViridianCity_EventScript_SetOldManNormal
	return


ViridianCity_EventScript_SetOldManBlockingRoad::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_OLD_MAN_LYING_DOWN
	setobjectxyperm 2, 14, 10
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_DOWN
	return


ViridianCity_EventScript_SetOldManNormal::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_OLD_MAN_1
	setobjectxyperm 2, 20, 9
	setobjectxyperm 3, 21, 9
	setobjectxyperm 4, 17, 13
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype 3, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype 4, MOVEMENT_TYPE_WANDER_AROUND
	return


ViridianCity_EventScript_MartTrigger::
	clearflag FLAG_HIDE_DAISY_VIRIDIAN
	textcolor NPC_TEXT_COLOR_FEMALE
	opendoor 38, 6
	waitdooranim
	addobject 1
	applymovement 1, ViridianCity_Movement_WalkDown
	applymovement OBJ_EVENT_ID_PLAYER, ViridianCity_Movement_PlayerDown
	waitmovement 0
	closedoor 38, 6
	waitdooranim
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	applymovement 1, Common_Movement_ExclamDown
	waitmovement 0
	msgbox ViridianCity_Text_HiPlayer
	closemessage
	applymovement 1, ViridianCity_Movement_DaisyToHouse
	applymovement OBJ_EVENT_ID_PLAYER, ViridianCity_Movement_PlayerToHouse
	waitmovement 0
	opendoor 41, 6
	waitdooranim
	applymovement 1, ViridianCity_Movement_DaisyEnterHouse
	applymovement OBJ_EVENT_ID_PLAYER, ViridianCity_Movement_PlayerEnterHouse
	waitmovement 0
	closedoor 41, 6
	waitdooranim
	setflag FLAG_HIDE_DAISY_VIRIDIAN
	warp MAP_VIRIDIAN_CITY_MAISY_HOUSE, 4, 7
	waitstate
	releaseall
	return


ViridianCity_Movement_WalkDown:
	walk_down
	step_end

ViridianCity_Movement_PlayerDown:
	face_up
	walk_down
	step_end

ViridianCity_Movement_DaisyToHouse:
	walk_right
	walk_right
	walk_right
	step_end

ViridianCity_Movement_PlayerToHouse:
	walk_up
	walk_right
	walk_right
	step_end

ViridianCity_Movement_DaisyEnterHouse:
	walk_up
	set_invisible
	step_end

ViridianCity_Movement_PlayerEnterHouse:
	walk_right
	walk_up
	set_invisible
	step_end

ViridianCity_EventScript_MaisyTrigger::
	clearflag FLAG_HIDE_DAISY_VIRIDIAN
	textcolor NPC_TEXT_COLOR_FEMALE
	opendoor 38, 6
	waitdooranim
	addobject 1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	applymovement 1, ViridianCity_Movement_WalkDown
	waitmovement 0
	closedoor 38, 6
	waitdooranim
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamRight
	waitmovement 0
	msgbox ViridianCity_Text_HiPlayer
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, ViridianCity_Movement_PlayerToHouse2
	applymovement 1, ViridianCity_Movement_DaisyToHouse
	waitmovement 0
	opendoor 41, 6
	waitdooranim
	applymovement 1, ViridianCity_Movement_DaisyEnterHouse
	applymovement OBJ_EVENT_ID_PLAYER, ViridianCity_Movement_PlayerEnterHouse2
	waitmovement 0
	closedoor 41, 6
	waitdooranim
	setflag FLAG_HIDE_DAISY_VIRIDIAN
	warp MAP_VIRIDIAN_CITY_MAISY_HOUSE, 4, 7
	waitstate
	releaseall
	return


ViridianCity_Movement_PlayerToHouse2:
	walk_right
	face_left
	step_end

ViridianCity_Movement_PlayerEnterHouse2:
	walk_left
	walk_up
	set_invisible
	step_end

ViridianCity_EventScript_CitySign::
	msgbox ViridianCity_Text_CitySign, MSGBOX_SIGN
	return


ViridianCity_EventScript_MaisyHouseSign::
	msgbox ViridianCity_Text_MaisyHouseSign, MSGBOX_SIGN
	return


ViridianCity_EventScript_OldMan::
	goto_if_le VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 2, ViridianCity_EventScript_OldManTalk1
	goto_if_ge VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 3, ViridianCity_EventScript_OldManTalk2
	return


ViridianCity_EventScript_OldWoman::
	goto_if_le VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 2, ViridianCity_EventScript_OldWomanTalk1
	goto_if_ge VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 3, ViridianCity_EventScript_OldWomanTalk2
	return


ViridianCity_EventScript_Child::
	goto_if_le VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 2, ViridianCity_EventScript_ChildTalk1
	goto_if_ge VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 3, ViridianCity_EventScript_ChildTalk2
	return


ViridianCity_EventScript_OldManTalk1::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox ViridianCity_Text_OldManTalk1, MSGBOX_NPC
	return


ViridianCity_EventScript_OldManTalk2::
	msgbox ViridianCity_Text_OldManTalk2, MSGBOX_NPC
	return


ViridianCity_EventScript_OldWomanTalk1::
	lock
	msgbox ViridianCity_Text_OldWomanTalk1, MSGBOX_DEFAULT
	closemessage
	release
	end


ViridianCity_EventScript_OldWomanTalk2::
	msgbox ViridianCity_Text_OldWomanTalk2, MSGBOX_NPC
	return


ViridianCity_EventScript_ChildTalk1::
	lock
	msgbox ViridianCity_Text_ChildTalk1, MSGBOX_DEFAULT
	closemessage
	release
	end


ViridianCity_EventScript_ChildTalk2::
	msgbox ViridianCity_Text_ChildTalk2, MSGBOX_NPC
	return


ViridianCity_Text_HiPlayer::
	.string "MAISY: {PLAYER}!\n"
	.string "What a neat coincidence!\p"
	.string "I was just picking up grandpa's\n"
	.string "PARCEL from the POKé MART here.\p"
	.string "He got some stuff for you too, so\n"
	.string "why don't you come with me?$"

ViridianCity_Text_CitySign::
	.string "FILL$"

ViridianCity_Text_MaisyHouseSign::
	.string "MAISY'S HOUSE$"

ViridianCity_Text_OldManTalk1::
	.string "It looks like he's out cold.$"

ViridianCity_Text_OldManTalk2::
	.string "FILL$"

ViridianCity_Text_OldWomanTalk1::
	.string "Dad, you can't just pass out drunk\non the street!$"

ViridianCity_Text_OldWomanTalk2::
	.string "FILL$"

ViridianCity_Text_ChildTalk1::
	.string "Grandpa! Are you dead?$"

ViridianCity_Text_ChildTalk2::
	.string "FILL$"
