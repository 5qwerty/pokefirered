ObsidianCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ObsidianCity_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_LOAD, ObsidianCity_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

ObsidianCity_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setworldmapflag FLAG_WORLD_MAP_OBSIDIAN_CITY
	call_if_eq VAR_MAP_SCENE_OBSIDIAN_CITY_EVENTS, 1, ObsidianCity_EventScript_MoveGio
	return

ObsidianCity_MapScripts_MAP_SCRIPT_ON_LOAD:
	call_if_ge VAR_MAP_SCENE_OBSIDIAN_CITY_EVENTS, 1, ObsidianCity_EventScript_OpenHole
	return


ObsidianCity_EventScript_OpenHole::
	setmetatile 17, 28, 0x0A9, 0
	return


ObsidianCity_EventScript_MoveGio::
	setobjectxyperm 6, 21, 22
	setobjectmovementtype 6, MOVEMENT_TYPE_FACE_DOWN
	setobjectxyperm 1, 20, 26
	setobjectxyperm 2, 20, 27
	setobjectxyperm 4, 20, 28
	setobjectxyperm 3, 20, 29
	return


ObsidianCity_EventScript_GymTrigger::
	lockall
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamDown
	waitmovement 0
	setvar 0x8004, 2
	setvar 0x8005, 2
	setvar 0x8006, 20
	setvar 0x8007, 4
	special ShakeScreen
	delay 80
	opendoor 6, 5
	waitdooranim
	addobject 6
	clearflag FLAG_HIDE_GIO_OBSIDIAN
	applymovement 6, Common_Movement_WalkDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
	waitmovement 0
	closedoor 6, 5
	waitdooranim
	textcolor NPC_TEXT_COLOR_MALE
	msgbox ObsidianCity_Text_WhatInTarnation
	closemessage
	delay 30
	applymovement 6, Common_Movement_FaceLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox ObsidianCity_Text_YouHeardToo
	closemessage
	playse SE_PIN
	applymovement 6, Common_Movement_ExclamDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamDown
	waitmovement 0
	setvar 0x8004, 3
	setvar 0x8005, 3
	setvar 0x8006, 30
	setvar 0x8007, 4
	special ShakeScreen
	delay 120
	msgbox ObsidianCity_Text_IGo
	closemessage
	applymovement 6, ObsidianCity_Movement_Leave
	waitmovement 0
	removeobject 6
	setvar VAR_MAP_SCENE_OBSIDIAN_CITY_EVENTS, 1
	setobjectxyperm 6, 21, 22
	setobjectmovementtype 6, MOVEMENT_TYPE_FACE_DOWN
	setmetatile 17, 28, 0x0A9, 0
	addobject 6
	clearflag FLAG_HIDE_GIO_OBSIDIAN
	setobjectxyperm 1, 21, 23
	setobjectxyperm 2, 21, 24
	setobjectxyperm 3, 21, 25
	setobjectxyperm 4, 21, 26
	releaseall
	end


ObsidianCity_Movement_Leave:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

ObsidianCity_EventScript_TriggerLeft::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	msgbox ObsidianCity_Text_OuttaTheWay
	closemessage
	delay 60
	applymovement 1, ObsidianCity_Movement_Rocket1First
	applymovement 2, ObsidianCity_Movement_Rocket2First
	applymovement 3, ObsidianCity_Movement_Rocket3First
	applymovement 4, ObsidianCity_Movement_Rocket4First
	waitmovement 0
	applymovement 6, ObsidianCity_Movement_GioOuttaWay
	applymovement 1, ObsidianCity_Movement_Rocket1Second
	applymovement 2, ObsidianCity_Movement_Rocket2Second
	applymovement 3, ObsidianCity_Movement_Rocket3Second
	applymovement 4, ObsidianCity_Movement_Rocket4Second
	waitmovement 0
	applymovement 6, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, ObsidianCity_Movement_PlayerLookRocketLeft
	applymovement 1, ObsidianCity_Movement_Rocket1Third
	applymovement 2, ObsidianCity_Movement_Rocket2Third
	applymovement 3, ObsidianCity_Movement_Rocket3Third
	applymovement 4, ObsidianCity_Movement_Rocket4Third
	waitmovement 0
	msgbox ObsidianCity_Text_RightThing
	closemessage
	applymovement 4, ObsidianCity_Movement_Rocket4Fourth
	waitmovement 0
	delay 30
	removeobject 1
	removeobject 2
	removeobject 3
	removeobject 4
	removeobject 5
	applymovement 6, ObsidianCity_Movement_GioToPlayerLeftMid
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	msgbox ObsidianCity_Text_SeeThat
	closemessage
	applymovement 6, ObsidianCity_Movement_GioToRuinsLeftMid
	waitmovement 0
	removeobject 6
	setvar VAR_MAP_SCENE_OBSIDIAN_CITY_EVENTS, 2
	releaseall
	end


ObsidianCity_EventScript_TriggerMid::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	msgbox ObsidianCity_Text_OuttaTheWay
	closemessage
	delay 60
	applymovement 1, ObsidianCity_Movement_Rocket1First
	applymovement 2, ObsidianCity_Movement_Rocket2First
	applymovement 3, ObsidianCity_Movement_Rocket3First
	applymovement 4, ObsidianCity_Movement_Rocket4First
	waitmovement 0
	applymovement 6, ObsidianCity_Movement_GioOuttaWay
	applymovement 1, ObsidianCity_Movement_Rocket1Second
	applymovement 2, ObsidianCity_Movement_Rocket2Second
	applymovement 3, ObsidianCity_Movement_Rocket3Second
	applymovement 4, ObsidianCity_Movement_Rocket4Second
	waitmovement 0
	applymovement 6, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, ObsidianCity_Movement_PlayerLookRocketMid
	applymovement 1, ObsidianCity_Movement_Rocket1Third
	applymovement 2, ObsidianCity_Movement_Rocket2Third
	applymovement 3, ObsidianCity_Movement_Rocket3Third
	applymovement 4, ObsidianCity_Movement_Rocket4Third
	waitmovement 0
	msgbox ObsidianCity_Text_RightThing
	closemessage
	applymovement 4, ObsidianCity_Movement_Rocket4Fourth
	waitmovement 0
	delay 30
	removeobject 1
	removeobject 2
	removeobject 3
	removeobject 4
	removeobject 5
	applymovement 6, ObsidianCity_Movement_GioToPlayerLeftMid
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	msgbox ObsidianCity_Text_SeeThat
	closemessage
	applymovement 6, ObsidianCity_Movement_GioToRuinsLeftMid
	waitmovement 0
	removeobject 6
	setvar VAR_MAP_SCENE_OBSIDIAN_CITY_EVENTS, 2
	releaseall
	end


ObsidianCity_EventScript_TriggerRight::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	msgbox ObsidianCity_Text_OuttaTheWay
	closemessage
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	applymovement 1, ObsidianCity_Movement_Rocket1First
	applymovement 2, ObsidianCity_Movement_Rocket2First
	applymovement 3, ObsidianCity_Movement_Rocket3First
	applymovement 4, ObsidianCity_Movement_Rocket4First
	waitmovement 0
	applymovement 6, ObsidianCity_Movement_GioOuttaWay
	applymovement 1, ObsidianCity_Movement_Rocket1Second
	applymovement 2, ObsidianCity_Movement_Rocket2Second
	applymovement 3, ObsidianCity_Movement_Rocket3Second
	applymovement 4, ObsidianCity_Movement_Rocket4Second
	waitmovement 0
	applymovement 6, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, ObsidianCity_Movement_PlayerLookRocketRight
	applymovement 1, ObsidianCity_Movement_Rocket1Third
	applymovement 2, ObsidianCity_Movement_Rocket2Third
	applymovement 3, ObsidianCity_Movement_Rocket3Third
	applymovement 4, ObsidianCity_Movement_Rocket4Third
	waitmovement 0
	delay 30
	msgbox ObsidianCity_Text_RightThing
	closemessage
	applymovement 4, ObsidianCity_Movement_Rocket4Fourth
	waitmovement 0
	delay 30
	removeobject 1
	removeobject 2
	removeobject 3
	removeobject 4
	removeobject 5
	applymovement 6, ObsidianCity_Movement_GioToPlayerRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	msgbox ObsidianCity_Text_SeeThat
	closemessage
	applymovement 6, ObsidianCity_Movement_GioToRuinsRight
	waitmovement 0
	removeobject 6
	setvar VAR_MAP_SCENE_OBSIDIAN_CITY_EVENTS, 2
	releaseall
	end


ObsidianCity_Movement_Rocket1First:
	step_end

ObsidianCity_Movement_Rocket2First:
	step_end

ObsidianCity_Movement_Rocket3First:
	step_end

ObsidianCity_Movement_Rocket4First:
	step_end

ObsidianCity_Movement_GioOuttaWay:
	walk_fast_up
	face_down
	delay_1
	face_right
	step_end

ObsidianCity_Movement_Rocket1Second:
	walk_fast_up
	walk_fast_right
	walk_fast_up
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

ObsidianCity_Movement_Rocket2Second:
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_up
	walk_fast_right
	walk_fast_up
	walk_fast_up
	step_end

ObsidianCity_Movement_Rocket3Second:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_up
	walk_fast_right
	walk_fast_up
	step_end

ObsidianCity_Movement_Rocket4Second:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_up
	walk_fast_right
	step_end

ObsidianCity_Movement_Rocket1Third:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_up
	walk_fast_left
	walk_fast_left
	step_end

ObsidianCity_Movement_Rocket2Third:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_up
	walk_fast_left
	step_end

ObsidianCity_Movement_Rocket3Third:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_up
	step_end

ObsidianCity_Movement_Rocket4Third:
	walk_fast_up
	walk_fast_up
	walk_up
	walk_up
	walk_slow_up
	walk_slow_up
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	delay_16
	face_up
	step_end

ObsidianCity_Movement_Rocket4Fourth:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	step_end

ObsidianCity_Movement_PlayerLookRocketLeft:
	walk_in_place_right
	walk_in_place_up
	step_end

ObsidianCity_Movement_PlayerLookRocketMid:
	walk_fast_left
	walk_in_place_fast_right
	walk_in_place_up
	step_end

ObsidianCity_Movement_PlayerLookRocketRight:
	walk_in_place_left
	walk_in_place_up
	step_end

ObsidianCity_Movement_GioToPlayerLeftMid:
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

ObsidianCity_Movement_GioToPlayerRight:
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

ObsidianCity_Movement_GioToRuinsLeftMid:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

ObsidianCity_Movement_GioToRuinsRight:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

ObsidianCity_Text_WhatInTarnation::
	.string "GEOFFREY: What in tarnation was that?$"

ObsidianCity_Text_YouHeardToo::
	.string "Didja hear that too, kid?\nYou musta heard it!$"

ObsidianCity_Text_IGo::
	.string "GEOFFREY: Gosh dangit!\nSomethin's def'nitely up!\pI'll bet it's at that place!\nThe RUINS OF OMEG!$"

ObsidianCity_Text_OuttaTheWay::
	.string "???: Get out of the way!$"

ObsidianCity_Text_RightThing::
	.string "???: Killing all those UNOWN...\nWas that really the right thing?$"

ObsidianCity_Text_SeeThat::
	.string "GEOFFREY: Yeowch!\nThose people were so dang fast!\pI didn't quite catch what that\nlast person said.\pBut they musta been behind that\nquake earlier!\p...\pOh gosh! I should hurry to the\nRUINS!$"
