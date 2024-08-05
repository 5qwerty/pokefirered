ViridianCity_MaisyHouse_MapScripts::
# 6 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_MaisyHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 11 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ViridianCity_MaisyHouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

ViridianCity_MaisyHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 7 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	call_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 0, MaisyHouse_EventScript_ReadyDaisy
# 8 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	call_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 1, MaisyHouse_EventScript_ReadyDaisy2
# 9 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	call_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 2, MaisyHouse_EventScript_ReadyDaisy2
	return

ViridianCity_MaisyHouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 12 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	map_script_2 VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 0, MaisyHouse_EventScript_GiveItems
	.2byte 0


MaisyHouse_EventScript_ReadyDaisy::
# 17 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	setflag FLAG_HIDE_POKEDEX
# 18 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	setflag FLAG_HIDE_TOWN_MAP
# 19 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	setobjectxyperm 1, 4, 6
# 20 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return


MaisyHouse_EventScript_ReadyDaisy2::
# 24 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	setobjectxyperm 1, 4, 4
# 25 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_DOWN
	return


MaisyHouse_EventScript_GiveItems::
# 29 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	lockall
# 30 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 31 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
# 32 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	applymovement 1, MaisyHouse_Movement_DaisyMove1
# 33 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	waitmovement 0
# 34 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	msgbox MaisyHouse_Text_TheseTwo
# 35 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	closemessage
# 36 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	applymovement 1, MaisyHouse_Movement_RightFaceDown
# 37 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	waitmovement 0
# 38 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	addobject 2
# 39 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	clearflag FLAG_HIDE_TOWN_MAP
# 40 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	applymovement 1, MaisyHouse_Movement_RightFaceDown
# 41 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	waitmovement 0
# 42 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	addobject 3
# 43 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	clearflag FLAG_HIDE_POKEDEX
# 44 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	applymovement 1, MaisyHouse_Movement_BackToStart
# 45 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	waitmovement 0
# 46 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	msgbox MaisyHouse_Text_Take
# 47 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	closemessage
# 48 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	addvar VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 1
# 49 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	releaseall
	end


# 53 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
MaisyHouse_Movement_DaisyMove1:
# 54 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	walk_up
# 54 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	walk_up
# 54 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	walk_up
# 55 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	face_down
# 56 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	step_end

# 59 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
MaisyHouse_Movement_RightFaceDown:
# 60 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	walk_right
# 61 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	face_down
# 62 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	delay_16
# 63 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	step_end

# 66 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
MaisyHouse_Movement_BackToStart:
# 67 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	walk_left
# 67 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	walk_left
# 68 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	walk_down
# 69 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	step_end

MaisyHouse_EventScript_TownMap::
# 81 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	lock
# 82 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	msgbox MaisyHouse_Text_TakeMap, MSGBOX_YESNO
# 83 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	goto_if_eq VAR_RESULT, YES, MaisyHouse_EventScript_TownMap2
# 84 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	release
	end


MaisyHouse_EventScript_TownMap2::
# 89 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	removeobject VAR_LAST_TALKED
# 90 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	giveitem_msg MaisyHouse_Text_ReceivedMap, ITEM_TOWN_MAP, 1, MUS_OBTAIN_KEY_ITEM
# 91 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	addvar VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 1
# 92 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	call_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 3, MaisyHouse_EventScript_MaisyToPlayer
# 93 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 3, MaisyHouse_EventScript_GotBoth
# 94 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	release
	end


MaisyHouse_EventScript_PokeDex::
# 99 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	lock
# 100 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	msgbox MaisyHouse_Text_TakeDex, MSGBOX_YESNO
# 101 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	goto_if_eq VAR_RESULT, YES, MaisyHouse_EventScript_PokeDex2
# 102 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	release
	end


MaisyHouse_EventScript_PokeDex2::
# 107 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	removeobject VAR_LAST_TALKED
# 109 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	message MaisyHouse_Text_ReceivedDex
# 110 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	waitmessage
# 111 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	playfanfare MUS_OBTAIN_KEY_ITEM
# 112 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	waitfanfare
# 113 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	closemessage
# 114 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 115 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	setflag FLAG_SYS_NATIONAL_DEX
# 116 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	addvar VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 1
# 117 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 3, MaisyHouse_EventScript_MaisyToPlayer
	return


MaisyHouse_EventScript_MaisyToPlayer::
# 121 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 122 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	call_if_eq VAR_TEMP_0, 5, MaisyHouse_EventScript_MaisyUpRight
# 123 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	call_if_eq VAR_TEMP_0, 6, MaisyHouse_EventScript_MaisyUpRight2
# 124 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	call_if_eq VAR_TEMP_0, 7, MaisyHouse_EventScript_MaisyUpRight3
# 125 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	goto MaisyHouse_EventScript_GotBoth
	return


MaisyHouse_EventScript_MaisyUpRight::
# 129 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	applymovement 1, MaisyHouse_Movement_DaisyUpRight
# 130 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	waitmovement 0
	return


MaisyHouse_EventScript_MaisyUpRight2::
# 135 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	applymovement 1, MaisyHouse_Movement_DaisyUpRight2
# 136 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	waitmovement 0
	return


MaisyHouse_EventScript_MaisyUpRight3::
# 141 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	applymovement 1, MaisyHouse_Movement_DaisyUpRight3
# 142 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	waitmovement 0
	return


# 146 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
MaisyHouse_Movement_DaisyUpRight:
# 147 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	walk_up
# 148 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	step_end

# 151 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
MaisyHouse_Movement_DaisyUpRight2:
# 152 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	walk_up
# 153 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	walk_right
# 154 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	step_end

# 157 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
MaisyHouse_Movement_DaisyUpRight3:
# 158 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	walk_up
# 159 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	walk_right
# 159 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	walk_right
# 159 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	walk_right
# 160 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	step_end

MaisyHouse_EventScript_GotBoth::
# 164 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	call_if_le VAR_TEMP_0, 6, MaisyHouse_EventScript_LeftTwo
# 165 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	call_if_ge VAR_TEMP_0, 7, MaisyHouse_EventScript_RightOne
# 166 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 167 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	msgbox MaisyHouse_Text_GiveBalls
# 168 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	giveitem ITEM_POKE_BALL, 5
# 169 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	msgbox MaisyHouse_Text_GoOn
# 170 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	release
	end


MaisyHouse_EventScript_LeftTwo::
# 175 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	applymovement 1, Common_Movement_FaceRight
# 176 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 177 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	waitmovement 0
	return


MaisyHouse_EventScript_RightOne::
# 182 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	applymovement 1, Common_Movement_FaceDown
# 183 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 184 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	waitmovement 0
	return


MaisyHouse_EventScript_Maisy::
# 214 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	lock
# 215 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	goto_if_le VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 2, MaisyHouse_EventScript_MaisyTake
# 216 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 3, MaisyHouse_EventScript_MaisyNormal
	return


MaisyHouse_EventScript_MaisyTake::
# 220 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	msgbox MaisyHouse_Text_Take, MSGBOX_NPC
	return


MaisyHouse_EventScript_MaisyNormal::
# 225 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	msgbox MaisyHouse_Text_MaisyNormal, MSGBOX_NPC
	return


MaisyHouse_Text_TheseTwo::
# 72 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	.string "MAISY: In anticipation of you\n"
	.string "starting your journey as a POKéMON\l"
	.string "TRAINER, grandpa ordered...\p"
	.string "Ah! A TOWN MAP and a POKéDEX!\p"
	.string "I'll just set them down over here!$"

MaisyHouse_Text_Take::
# 76 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	.string "MAISY: Alrighty!\n"
	.string "Go ahead and take them!$"

MaisyHouse_Text_TakeMap::
# 188 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	.string "The TOWN MAP can be used to view\n"
	.string "the map of the entire region.\p"
	.string "Take the TOWN MAP?$"

MaisyHouse_Text_TakeDex::
# 192 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	.string "The POKéDEX automatically records\n"
	.string "data on any POKéMON when they are\l"
	.string "caught.\p"
	.string "Take the POKéDEX?$"

MaisyHouse_Text_ReceivedMap::
# 196 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	.string "{PLAYER} received the TOWN MAP!$"

MaisyHouse_Text_ReceivedDex::
# 200 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	.string "{PLAYER} received the POKéDEX!$"

MaisyHouse_Text_GiveBalls::
# 204 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	.string "MAISY: Oh! I almost forgot these!$"

MaisyHouse_Text_GoOn::
# 208 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	.string "MAISY: That should be everything!\n"
	.string "Good luck on your adventure,\l"
	.string "{PLAYER}!\p"
	.string "I know that {RIVAL} left on his\n"
	.string "adventure as well, but grandpa and\l"
	.string "I wanted to give these to you.\p"
	.string "You helped grandpa out with so many\n"
	.string "things, while {RIVAL} did nothing but\l"
	.string "mock everyone.\p"
	.string "I hope he learns his lesson some\n"
	.string "day, or he might get into some\l"
	.string "serious trouble.\p"
	.string "Either way, I'm rooting for you,\n"
	.string "{PLAYER}!$"

MaisyHouse_Text_MaisyNormal::
# 228 "data/maps/ViridianCity_MaisyHouse/scripts.pory"
	.string "MAISY: I'm cheering for you,\n"
	.string "{PLAYER}!$"
