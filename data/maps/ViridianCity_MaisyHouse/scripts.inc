ViridianCity_MaisyHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_MaisyHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ViridianCity_MaisyHouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

ViridianCity_MaisyHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 0, MaisyHouse_EventScript_ReadyDaisy
	call_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 1, MaisyHouse_EventScript_ReadyDaisy2
	call_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 2, MaisyHouse_EventScript_ReadyDaisy2
	return

ViridianCity_MaisyHouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 0, MaisyHouse_EventScript_GiveItems
	.2byte 0


MaisyHouse_EventScript_ReadyDaisy::
	setflag FLAG_HIDE_POKEDEX
	setflag FLAG_HIDE_TOWN_MAP
	setobjectxyperm 1, 4, 6
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return


MaisyHouse_EventScript_ReadyDaisy2::
	setobjectxyperm 1, 4, 4
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_DOWN
	return


MaisyHouse_EventScript_GiveItems::
	lockall
	textcolor NPC_TEXT_COLOR_FEMALE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	applymovement 1, MaisyHouse_Movement_DaisyMove1
	waitmovement 0
	msgbox MaisyHouse_Text_TheseTwo
	closemessage
	applymovement 1, MaisyHouse_Movement_RightFaceDown
	waitmovement 0
	addobject 2
	clearflag FLAG_HIDE_TOWN_MAP
	applymovement 1, MaisyHouse_Movement_RightFaceDown
	waitmovement 0
	addobject 3
	clearflag FLAG_HIDE_POKEDEX
	applymovement 1, MaisyHouse_Movement_BackToStart
	waitmovement 0
	msgbox MaisyHouse_Text_Take
	closemessage
	addvar VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 1
	releaseall
	end


MaisyHouse_Movement_DaisyMove1:
	walk_up
	walk_up
	walk_up
	face_down
	step_end

MaisyHouse_Movement_RightFaceDown:
	walk_right
	face_down
	delay_16
	step_end

MaisyHouse_Movement_BackToStart:
	walk_left
	walk_left
	walk_down
	step_end

MaisyHouse_EventScript_TownMap::
	lock
	msgbox MaisyHouse_Text_TakeMap, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MaisyHouse_EventScript_TownMap2
	release
	end


MaisyHouse_EventScript_TownMap2::
	removeobject VAR_LAST_TALKED
	giveitem_msg MaisyHouse_Text_ReceivedMap, ITEM_TOWN_MAP, 1, MUS_OBTAIN_KEY_ITEM
	addvar VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 1
	call_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 3, MaisyHouse_EventScript_MaisyToPlayer
	goto_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 3, MaisyHouse_EventScript_GotBoth
	release
	end


MaisyHouse_EventScript_PokeDex::
	lock
	msgbox MaisyHouse_Text_TakeDex, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MaisyHouse_EventScript_PokeDex2
	release
	end


MaisyHouse_EventScript_PokeDex2::
	removeobject VAR_LAST_TALKED
	message MaisyHouse_Text_ReceivedDex
	waitmessage
	playfanfare MUS_OBTAIN_KEY_ITEM
	waitfanfare
	closemessage
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_SYS_NATIONAL_DEX
	addvar VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 1
	goto_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 3, MaisyHouse_EventScript_MaisyToPlayer
	return


MaisyHouse_EventScript_MaisyToPlayer::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 5, MaisyHouse_EventScript_MaisyUpRight
	call_if_eq VAR_TEMP_0, 6, MaisyHouse_EventScript_MaisyUpRight2
	call_if_eq VAR_TEMP_0, 7, MaisyHouse_EventScript_MaisyUpRight3
	goto MaisyHouse_EventScript_GotBoth
	return


MaisyHouse_EventScript_MaisyUpRight::
	applymovement 1, MaisyHouse_Movement_DaisyUpRight
	waitmovement 0
	return


MaisyHouse_EventScript_MaisyUpRight2::
	applymovement 1, MaisyHouse_Movement_DaisyUpRight2
	waitmovement 0
	return


MaisyHouse_EventScript_MaisyUpRight3::
	applymovement 1, MaisyHouse_Movement_DaisyUpRight3
	waitmovement 0
	return


MaisyHouse_Movement_DaisyUpRight:
	walk_up
	step_end

MaisyHouse_Movement_DaisyUpRight2:
	walk_up
	walk_right
	step_end

MaisyHouse_Movement_DaisyUpRight3:
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

MaisyHouse_EventScript_GotBoth::
	call_if_le VAR_TEMP_0, 6, MaisyHouse_EventScript_LeftTwo
	call_if_ge VAR_TEMP_0, 7, MaisyHouse_EventScript_RightOne
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox MaisyHouse_Text_GiveBalls
	giveitem ITEM_POKE_BALL, 5
	msgbox MaisyHouse_Text_GoOn
	release
	end


MaisyHouse_EventScript_LeftTwo::
	applymovement 1, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	return


MaisyHouse_EventScript_RightOne::
	applymovement 1, Common_Movement_FaceDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	return


MaisyHouse_EventScript_Maisy::
	lock
	goto_if_le VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 2, MaisyHouse_EventScript_MaisyTake
	goto_if_ge VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 3, MaisyHouse_EventScript_MaisyNormal
	return


MaisyHouse_EventScript_MaisyTake::
	msgbox MaisyHouse_Text_Take, MSGBOX_NPC
	return


MaisyHouse_EventScript_MaisyNormal::
	msgbox MaisyHouse_Text_MaisyNormal, MSGBOX_NPC
	return


MaisyHouse_Text_TheseTwo::
	.string "MAISY: In anticipation of you\n"
	.string "starting your journey as a POKéMON\l"
	.string "TRAINER, grandpa ordered...\p"
	.string "Ah! A TOWN MAP and a POKéDEX!\p"
	.string "I'll just set them down over here!$"

MaisyHouse_Text_Take::
	.string "MAISY: Alrighty!\n"
	.string "Go ahead and take them!$"

MaisyHouse_Text_TakeMap::
	.string "The TOWN MAP can be used to view\n"
	.string "the map of the entire region.\p"
	.string "Take the TOWN MAP?$"

MaisyHouse_Text_TakeDex::
	.string "The POKéDEX automatically records\n"
	.string "data on any POKéMON when they are\l"
	.string "caught.\p"
	.string "Take the POKéDEX?$"

MaisyHouse_Text_ReceivedMap::
	.string "{PLAYER} received the TOWN MAP!$"

MaisyHouse_Text_ReceivedDex::
	.string "{PLAYER} received the POKéDEX!$"

MaisyHouse_Text_GiveBalls::
	.string "MAISY: Oh! I almost forgot these!$"

MaisyHouse_Text_GoOn::
	.string "MAISY: That should be everything!\n"
	.string "Good luck on your adventure,\l"
	.string "{PLAYER}!\p"
	.string "I know that {RIVAL} left on his\n"
	.string "adventure as well, but grandpa and\l"
	.string "I wanted to give these to you.\p"
	.string "You helped grandpa out with so many\n"
	.string "things, while {RIVAL} did nothing\l"
	.string "but mock everyone.\p"
	.string "I hope he learns his lesson some\n"
	.string "day, or he might get into some\l"
	.string "serious trouble.\p"
	.string "Either way, I'm rooting for you,\n"
	.string "{PLAYER}!$"

MaisyHouse_Text_MaisyNormal::
	.string "MAISY: I'm cheering for you,\n"
	.string "{PLAYER}!$"
