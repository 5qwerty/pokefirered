RocketHideout_B4F_MapScripts::
	.byte 0


TestScript::
# 13 "data/maps/RocketHideout_B4F/scripts.pory"
	setvar VAR_MAP_SCENE_CELADON_CITY_ROCKET, 2
	return


RocketHideout_B4F_EventScript_TriggerLeft::
# 17 "data/maps/RocketHideout_B4F/scripts.pory"
	setvar VAR_TEMP_1, 0
# 18 "data/maps/RocketHideout_B4F/scripts.pory"
	goto RocketHideout_B4F_EventScript_RocketScene
	return


RocketHideout_B4F_EventScript_TriggerMiddle::
# 22 "data/maps/RocketHideout_B4F/scripts.pory"
	setvar VAR_TEMP_1, 1
# 23 "data/maps/RocketHideout_B4F/scripts.pory"
	goto RocketHideout_B4F_EventScript_RocketScene
	return


RocketHideout_B4F_EventScript_TriggerRight::
# 27 "data/maps/RocketHideout_B4F/scripts.pory"
	setvar VAR_TEMP_1, 2
# 28 "data/maps/RocketHideout_B4F/scripts.pory"
	goto RocketHideout_B4F_EventScript_RocketScene
	return


RocketHideout_B4F_EventScript_RocketScene::
# 32 "data/maps/RocketHideout_B4F/scripts.pory"
	lock
# 33 "data/maps/RocketHideout_B4F/scripts.pory"
	special SpawnCameraObject
# 34 "data/maps/RocketHideout_B4F/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, RocketHideout_B4F_Movement_ToScene
# 35 "data/maps/RocketHideout_B4F/scripts.pory"
	waitmovement 0
# 36 "data/maps/RocketHideout_B4F/scripts.pory"
	playse SE_PIN
# 37 "data/maps/RocketHideout_B4F/scripts.pory"
	applymovement 4, Common_Movement_ExclamDown
# 38 "data/maps/RocketHideout_B4F/scripts.pory"
	waitmovement 0
# 39 "data/maps/RocketHideout_B4F/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 40 "data/maps/RocketHideout_B4F/scripts.pory"
	msgbox RocketHideout_B4F_Text_Airika1
# 41 "data/maps/RocketHideout_B4F/scripts.pory"
	closemessage
# 42 "data/maps/RocketHideout_B4F/scripts.pory"
	applymovement 4, Common_Movement_FaceLeft
# 43 "data/maps/RocketHideout_B4F/scripts.pory"
	waitmovement 0
# 44 "data/maps/RocketHideout_B4F/scripts.pory"
	msgbox RocketHideout_B4F_Text_Airika2
# 45 "data/maps/RocketHideout_B4F/scripts.pory"
	closemessage
# 46 "data/maps/RocketHideout_B4F/scripts.pory"
	applymovement 5, Common_Movement_WalkInPlaceDown
# 47 "data/maps/RocketHideout_B4F/scripts.pory"
	waitmovement 0
# 48 "data/maps/RocketHideout_B4F/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 49 "data/maps/RocketHideout_B4F/scripts.pory"
	msgbox RocketHideout_B4F_Text_Celio1
# 50 "data/maps/RocketHideout_B4F/scripts.pory"
	closemessage
# 51 "data/maps/RocketHideout_B4F/scripts.pory"
	applymovement 4, Common_Movement_FaceDown
# 52 "data/maps/RocketHideout_B4F/scripts.pory"
	applymovement 5, RocketHideout_B4F_Movement_Celio1
# 53 "data/maps/RocketHideout_B4F/scripts.pory"
	waitmovement 0
# 54 "data/maps/RocketHideout_B4F/scripts.pory"
	delay 30
# 55 "data/maps/RocketHideout_B4F/scripts.pory"
	playmoncry SPECIES_ZUBAT, CRY_MODE_NORMAL
# 56 "data/maps/RocketHideout_B4F/scripts.pory"
	waitmoncry
# 57 "data/maps/RocketHideout_B4F/scripts.pory"
	delay 30
# 58 "data/maps/RocketHideout_B4F/scripts.pory"
	playmoncry SPECIES_ZUBAT, CRY_MODE_FAINT
# 59 "data/maps/RocketHideout_B4F/scripts.pory"
	waitmoncry
# 60 "data/maps/RocketHideout_B4F/scripts.pory"
	delay 30
# 61 "data/maps/RocketHideout_B4F/scripts.pory"
	playmoncry SPECIES_CROBAT, CRY_MODE_NORMAL
# 62 "data/maps/RocketHideout_B4F/scripts.pory"
	waitmoncry
# 63 "data/maps/RocketHideout_B4F/scripts.pory"
	applymovement 5, RocketHideout_B4F_Movement_Celio2
# 64 "data/maps/RocketHideout_B4F/scripts.pory"
	waitmovement 0
# 65 "data/maps/RocketHideout_B4F/scripts.pory"
	msgbox RocketHideout_B4F_Text_Celio2
# 66 "data/maps/RocketHideout_B4F/scripts.pory"
	closemessage
# 67 "data/maps/RocketHideout_B4F/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 68 "data/maps/RocketHideout_B4F/scripts.pory"
	message RocketHideout_B4F_Text_ReceiveZubot
# 69 "data/maps/RocketHideout_B4F/scripts.pory"
	waitmessage
# 70 "data/maps/RocketHideout_B4F/scripts.pory"
	playfanfare MUS_OBTAIN_KEY_ITEM
# 71 "data/maps/RocketHideout_B4F/scripts.pory"
	waitfanfare
# 72 "data/maps/RocketHideout_B4F/scripts.pory"
	delay 30
# 73 "data/maps/RocketHideout_B4F/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 74 "data/maps/RocketHideout_B4F/scripts.pory"
	msgbox RocketHideout_B4F_Text_Airika3
# 75 "data/maps/RocketHideout_B4F/scripts.pory"
	closemessage
# 76 "data/maps/RocketHideout_B4F/scripts.pory"
	applymovement 5, RocketHideout_B4F_Movement_Celio3
# 77 "data/maps/RocketHideout_B4F/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, RocketHideout_B4F_Movement_ToPlayer
# 78 "data/maps/RocketHideout_B4F/scripts.pory"
	applymovement 4, RocketHideout_B4F_Movement_Airika1
# 79 "data/maps/RocketHideout_B4F/scripts.pory"
	waitmovement 0
# 80 "data/maps/RocketHideout_B4F/scripts.pory"
	special RemoveCameraObject
# 81 "data/maps/RocketHideout_B4F/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, RocketHideout_B4F_EventScript_AirikaWalk_Left
# 82 "data/maps/RocketHideout_B4F/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, RocketHideout_B4F_EventScript_AirikaWalk_Middle
# 83 "data/maps/RocketHideout_B4F/scripts.pory"
	msgbox RocketHideout_B4F_Text_Airika4
# 84 "data/maps/RocketHideout_B4F/scripts.pory"
	waitmessage
# 85 "data/maps/RocketHideout_B4F/scripts.pory"
	playbgm MUS_ENCOUNTER_ROCKET, 0
# 86 "data/maps/RocketHideout_B4F/scripts.pory"
	waitbuttonpress
# 87 "data/maps/RocketHideout_B4F/scripts.pory"
	trainerbattle_no_intro TRAINER_BOSS_GIOVANNI, RocketHideout_B4F_Text_AirikaDefeat
# 88 "data/maps/RocketHideout_B4F/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 89 "data/maps/RocketHideout_B4F/scripts.pory"
	msgbox RocketHideout_B4F_Text_Airika5
# 90 "data/maps/RocketHideout_B4F/scripts.pory"
	closemessage
# 91 "data/maps/RocketHideout_B4F/scripts.pory"
	applymovement 4, Common_Movement_FaceUp
# 92 "data/maps/RocketHideout_B4F/scripts.pory"
	waitmovement 0
# 93 "data/maps/RocketHideout_B4F/scripts.pory"
	msgbox RocketHideout_B4F_Text_Airika6
# 94 "data/maps/RocketHideout_B4F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 95 "data/maps/RocketHideout_B4F/scripts.pory"
	closemessage
# 96 "data/maps/RocketHideout_B4F/scripts.pory"
	removeobject 4
# 97 "data/maps/RocketHideout_B4F/scripts.pory"
	removeobject 5
# 98 "data/maps/RocketHideout_B4F/scripts.pory"
	removeobject 6
# 99 "data/maps/RocketHideout_B4F/scripts.pory"
	removeobject 7
# 100 "data/maps/RocketHideout_B4F/scripts.pory"
	addobject 1
# 101 "data/maps/RocketHideout_B4F/scripts.pory"
	clearflag FLAG_HIDE_SILPH_SCOPE
# 102 "data/maps/RocketHideout_B4F/scripts.pory"
	setflag FLAG_HIDE_CELADON_ROCKETS
# 103 "data/maps/RocketHideout_B4F/scripts.pory"
	addvar VAR_MAP_SCENE_CELADON_CITY_ROCKET, 1
# 104 "data/maps/RocketHideout_B4F/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 105 "data/maps/RocketHideout_B4F/scripts.pory"
	applymovement 11, Common_Movement_WalkInPlaceUp
# 106 "data/maps/RocketHideout_B4F/scripts.pory"
	waitmovement 0
# 107 "data/maps/RocketHideout_B4F/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 108 "data/maps/RocketHideout_B4F/scripts.pory"
	msgbox RocketHideout_B4F_Text_GoodRocket1
# 109 "data/maps/RocketHideout_B4F/scripts.pory"
	closemessage
# 110 "data/maps/RocketHideout_B4F/scripts.pory"
	delay 30
# 111 "data/maps/RocketHideout_B4F/scripts.pory"
	playmoncry SPECIES_LOTAD, CRY_MODE_FAINT
# 112 "data/maps/RocketHideout_B4F/scripts.pory"
	waitmoncry
# 113 "data/maps/RocketHideout_B4F/scripts.pory"
	delay 30
# 114 "data/maps/RocketHideout_B4F/scripts.pory"
	msgbox RocketHideout_B4F_Text_GoodRocket2
# 115 "data/maps/RocketHideout_B4F/scripts.pory"
	closemessage
# 116 "data/maps/RocketHideout_B4F/scripts.pory"
	applymovement 11, RocketHideout_B4F_Movement_GoodRocket1
# 117 "data/maps/RocketHideout_B4F/scripts.pory"
	waitmovement 0
# 118 "data/maps/RocketHideout_B4F/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, RocketHideout_B4F_EventScript_GRWalk_Left1
# 119 "data/maps/RocketHideout_B4F/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, RocketHideout_B4F_EventScript_GRWalk_Middle1
# 120 "data/maps/RocketHideout_B4F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 121 "data/maps/RocketHideout_B4F/scripts.pory"
	waitmovement 0
# 122 "data/maps/RocketHideout_B4F/scripts.pory"
	msgbox RocketHideout_B4F_Text_GoodRocket3
# 123 "data/maps/RocketHideout_B4F/scripts.pory"
	closemessage
# 124 "data/maps/RocketHideout_B4F/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, RocketHideout_B4F_EventScript_GRWalk_LeftMiddle
# 125 "data/maps/RocketHideout_B4F/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, RocketHideout_B4F_EventScript_GRWalk_LeftMiddle
# 126 "data/maps/RocketHideout_B4F/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RocketHideout_B4F_EventScript_GRWalk_Right
# 127 "data/maps/RocketHideout_B4F/scripts.pory"
	removeobject 11
# 128 "data/maps/RocketHideout_B4F/scripts.pory"
	release
	return


RocketHideout_B4F_EventScript_GRWalk_Left1::
# 144 "data/maps/RocketHideout_B4F/scripts.pory"
	applymovement 11, Common_Movement_WalkLeft
# 145 "data/maps/RocketHideout_B4F/scripts.pory"
	waitmovement 0
# 146 "data/maps/RocketHideout_B4F/scripts.pory"
	applymovement 11, Common_Movement_WalkLeft
# 147 "data/maps/RocketHideout_B4F/scripts.pory"
	waitmovement 0
	return


RocketHideout_B4F_EventScript_GRWalk_Middle1::
# 152 "data/maps/RocketHideout_B4F/scripts.pory"
	applymovement 11, Common_Movement_WalkLeft
# 153 "data/maps/RocketHideout_B4F/scripts.pory"
	waitmovement 0
	return


RocketHideout_B4F_EventScript_GRWalk_LeftMiddle::
# 158 "data/maps/RocketHideout_B4F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 159 "data/maps/RocketHideout_B4F/scripts.pory"
	applymovement 11, RocketHideout_B4F_Movement_GoodRocketGoDown
# 160 "data/maps/RocketHideout_B4F/scripts.pory"
	waitmovement 0
	return


RocketHideout_B4F_EventScript_GRWalk_Right::
# 165 "data/maps/RocketHideout_B4F/scripts.pory"
	applymovement 11, Common_Movement_WalkLeft
# 166 "data/maps/RocketHideout_B4F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
# 167 "data/maps/RocketHideout_B4F/scripts.pory"
	waitmovement 0
# 168 "data/maps/RocketHideout_B4F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 169 "data/maps/RocketHideout_B4F/scripts.pory"
	applymovement 11, RocketHideout_B4F_Movement_GoodRocketGoDown
# 170 "data/maps/RocketHideout_B4F/scripts.pory"
	waitmovement 0
	return


RocketHideout_B4F_EventScript_AirikaWalk_Left::
# 175 "data/maps/RocketHideout_B4F/scripts.pory"
	applymovement 4, RocketHideout_B4F_Movement_AirikaLeft
# 176 "data/maps/RocketHideout_B4F/scripts.pory"
	waitmovement 0
# 177 "data/maps/RocketHideout_B4F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 178 "data/maps/RocketHideout_B4F/scripts.pory"
	waitmovement 0
	return


RocketHideout_B4F_EventScript_AirikaWalk_Middle::
# 183 "data/maps/RocketHideout_B4F/scripts.pory"
	applymovement 4, RocketHideout_B4F_Movement_AirikaMiddle
# 184 "data/maps/RocketHideout_B4F/scripts.pory"
	waitmovement 0
# 185 "data/maps/RocketHideout_B4F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 186 "data/maps/RocketHideout_B4F/scripts.pory"
	waitmovement 0
	return


# 190 "data/maps/RocketHideout_B4F/scripts.pory"
RocketHideout_B4F_Movement_AirikaLeft:
# 191 "data/maps/RocketHideout_B4F/scripts.pory"
	walk_down
# 192 "data/maps/RocketHideout_B4F/scripts.pory"
	walk_left
	step_end

# 195 "data/maps/RocketHideout_B4F/scripts.pory"
RocketHideout_B4F_Movement_AirikaMiddle:
# 196 "data/maps/RocketHideout_B4F/scripts.pory"
	walk_down
# 197 "data/maps/RocketHideout_B4F/scripts.pory"
	face_left
	step_end

# 200 "data/maps/RocketHideout_B4F/scripts.pory"
RocketHideout_B4F_Movement_ToScene:
# 201 "data/maps/RocketHideout_B4F/scripts.pory"
	walk_up
# 201 "data/maps/RocketHideout_B4F/scripts.pory"
	walk_up
# 201 "data/maps/RocketHideout_B4F/scripts.pory"
	walk_up
# 201 "data/maps/RocketHideout_B4F/scripts.pory"
	walk_up
	step_end

# 204 "data/maps/RocketHideout_B4F/scripts.pory"
RocketHideout_B4F_Movement_ToPlayer:
# 205 "data/maps/RocketHideout_B4F/scripts.pory"
	walk_down
# 205 "data/maps/RocketHideout_B4F/scripts.pory"
	walk_down
# 205 "data/maps/RocketHideout_B4F/scripts.pory"
	walk_down
# 205 "data/maps/RocketHideout_B4F/scripts.pory"
	walk_down
	step_end

# 247 "data/maps/RocketHideout_B4F/scripts.pory"
RocketHideout_B4F_Movement_Celio1:
# 248 "data/maps/RocketHideout_B4F/scripts.pory"
	walk_down
# 249 "data/maps/RocketHideout_B4F/scripts.pory"
	walk_right
# 250 "data/maps/RocketHideout_B4F/scripts.pory"
	walk_down
# 250 "data/maps/RocketHideout_B4F/scripts.pory"
	walk_down
# 250 "data/maps/RocketHideout_B4F/scripts.pory"
	walk_down
# 250 "data/maps/RocketHideout_B4F/scripts.pory"
	walk_down
# 251 "data/maps/RocketHideout_B4F/scripts.pory"
	walk_right
# 251 "data/maps/RocketHideout_B4F/scripts.pory"
	walk_right
# 251 "data/maps/RocketHideout_B4F/scripts.pory"
	walk_right
# 252 "data/maps/RocketHideout_B4F/scripts.pory"
	walk_down
# 253 "data/maps/RocketHideout_B4F/scripts.pory"
	face_right
	step_end

# 256 "data/maps/RocketHideout_B4F/scripts.pory"
RocketHideout_B4F_Movement_Celio2:
# 257 "data/maps/RocketHideout_B4F/scripts.pory"
	walk_up
# 257 "data/maps/RocketHideout_B4F/scripts.pory"
	walk_up
	step_end

# 260 "data/maps/RocketHideout_B4F/scripts.pory"
RocketHideout_B4F_Movement_Celio3:
# 261 "data/maps/RocketHideout_B4F/scripts.pory"
	walk_right
# 262 "data/maps/RocketHideout_B4F/scripts.pory"
	face_left
	step_end

# 265 "data/maps/RocketHideout_B4F/scripts.pory"
RocketHideout_B4F_Movement_Airika1:
# 266 "data/maps/RocketHideout_B4F/scripts.pory"
	walk_down
# 266 "data/maps/RocketHideout_B4F/scripts.pory"
	walk_down
# 267 "data/maps/RocketHideout_B4F/scripts.pory"
	walk_left
# 267 "data/maps/RocketHideout_B4F/scripts.pory"
	walk_left
# 268 "data/maps/RocketHideout_B4F/scripts.pory"
	walk_down
	step_end

# 271 "data/maps/RocketHideout_B4F/scripts.pory"
RocketHideout_B4F_Movement_GoodRocket1:
# 272 "data/maps/RocketHideout_B4F/scripts.pory"
	walk_left
# 272 "data/maps/RocketHideout_B4F/scripts.pory"
	walk_left
# 272 "data/maps/RocketHideout_B4F/scripts.pory"
	walk_left
	step_end

# 275 "data/maps/RocketHideout_B4F/scripts.pory"
RocketHideout_B4F_Movement_GoodRocketGoDown:
# 276 "data/maps/RocketHideout_B4F/scripts.pory"
	walk_down
# 276 "data/maps/RocketHideout_B4F/scripts.pory"
	walk_down
# 276 "data/maps/RocketHideout_B4F/scripts.pory"
	walk_down
# 276 "data/maps/RocketHideout_B4F/scripts.pory"
	walk_down
# 276 "data/maps/RocketHideout_B4F/scripts.pory"
	walk_down
# 276 "data/maps/RocketHideout_B4F/scripts.pory"
	walk_down
	step_end

# 285 "data/maps/RocketHideout_B4F/scripts.pory"

# 286 "data/maps/RocketHideout_B4F/scripts.pory"
.equ LOCALID_GIOVANNI,    1
# 287 "data/maps/RocketHideout_B4F/scripts.pory"
.equ LOCALID_SILPH_SCOPE, 2
# 288 "data/maps/RocketHideout_B4F/scripts.pory"
.equ VOUCHER,    1
# 289 "data/maps/RocketHideout_B4F/scripts.pory"

# 290 "data/maps/RocketHideout_B4F/scripts.pory"
.equ NUM_DOOR_GRUNTS_DEFEATED, VAR_TEMP_1
# 291 "data/maps/RocketHideout_B4F/scripts.pory"

# 292 "data/maps/RocketHideout_B4F/scripts.pory"
RocketHideout_B4F_EventScript_Giovanni::
# 293 "data/maps/RocketHideout_B4F/scripts.pory"
	lock
# 294 "data/maps/RocketHideout_B4F/scripts.pory"
	faceplayer
# 295 "data/maps/RocketHideout_B4F/scripts.pory"
	famechecker FAMECHECKER_GIOVANNI, 0
# 296 "data/maps/RocketHideout_B4F/scripts.pory"
	message RocketHideout_B4F_Text_GiovanniIntro
# 297 "data/maps/RocketHideout_B4F/scripts.pory"
	waitmessage
# 298 "data/maps/RocketHideout_B4F/scripts.pory"
	playbgm MUS_ENCOUNTER_ROCKET, 0
# 299 "data/maps/RocketHideout_B4F/scripts.pory"
	waitbuttonpress
# 300 "data/maps/RocketHideout_B4F/scripts.pory"
	trainerbattle_no_intro TRAINER_BOSS_GIOVANNI, RocketHideout_B4F_Text_GiovanniDefeat
# 301 "data/maps/RocketHideout_B4F/scripts.pory"
	msgbox RocketHideout_B4F_Text_GiovanniPostBattle
# 302 "data/maps/RocketHideout_B4F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 303 "data/maps/RocketHideout_B4F/scripts.pory"
	closemessage
# 304 "data/maps/RocketHideout_B4F/scripts.pory"
	removeobject LOCALID_GIOVANNI
# 305 "data/maps/RocketHideout_B4F/scripts.pory"
	addobject LOCALID_SILPH_SCOPE
# 306 "data/maps/RocketHideout_B4F/scripts.pory"
	clearflag FLAG_HIDE_SILPH_SCOPE
# 307 "data/maps/RocketHideout_B4F/scripts.pory"
	setflag FLAG_HIDE_CELADON_ROCKETS
# 308 "data/maps/RocketHideout_B4F/scripts.pory"
	famechecker FAMECHECKER_GIOVANNI, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
# 309 "data/maps/RocketHideout_B4F/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 310 "data/maps/RocketHideout_B4F/scripts.pory"
	release
# 311 "data/maps/RocketHideout_B4F/scripts.pory"
	end
# 312 "data/maps/RocketHideout_B4F/scripts.pory"

# 313 "data/maps/RocketHideout_B4F/scripts.pory"
RocketHideout_B4F_EventScript_SilphScope::
# 314 "data/maps/RocketHideout_B4F/scripts.pory"
	lock
# 315 "data/maps/RocketHideout_B4F/scripts.pory"
	faceplayer
# 316 "data/maps/RocketHideout_B4F/scripts.pory"
	removeobject VOUCHER
# 317 "data/maps/RocketHideout_B4F/scripts.pory"
	giveitem ITEM_BIKE_VOUCHER
# 318 "data/maps/RocketHideout_B4F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
# 319 "data/maps/RocketHideout_B4F/scripts.pory"
	release
# 320 "data/maps/RocketHideout_B4F/scripts.pory"
	end

RocketHideout_B4F_Text_GoodRocket1::
# 131 "data/maps/RocketHideout_B4F/scripts.pory"
	.string "???: Oh you poor thing...\n"
	.string "You're barely breathing...$"

RocketHideout_B4F_Text_GoodRocket2::
# 135 "data/maps/RocketHideout_B4F/scripts.pory"
	.string "???: So you've become a ROBOT\n"
	.string "POKéMON as well...\p"
	.string "Don't worry, I'll take extra good\n"
	.string "care of you!$"

RocketHideout_B4F_Text_GoodRocket3::
# 139 "data/maps/RocketHideout_B4F/scripts.pory"
	.string "???: I can't take it anymore.\n"
	.string "I quitting TEAM ROBOT!\p"
	.string "What they've done to the UNOWN,\n"
	.string "what they've done to this LOTAD...\p"
	.string "None of this is right!$"

RocketHideout_B4F_Text_Airika1::
# 208 "data/maps/RocketHideout_B4F/scripts.pory"
	.string "AIRIKA: Oh, it appears as though we\n"
	.string "have a little mouse among us.$"

RocketHideout_B4F_Text_Airika2::
# 212 "data/maps/RocketHideout_B4F/scripts.pory"
	.string "AIRIKA: DR. C! Is my prototype\n"
	.string "complete?$"

RocketHideout_B4F_Text_Celio1::
# 216 "data/maps/RocketHideout_B4F/scripts.pory"
	.string "DR. C: Ah, yes, lady AIRIKA.\n"
	.string "It will be, just after this one\l"
	.string "final adjustment.$"

RocketHideout_B4F_Text_Celio2::
# 222 "data/maps/RocketHideout_B4F/scripts.pory"
	.string "DR. C: Hyuk hyuk hyuk...\n"
	.string "Here you go, lady AIRIKA...$"

RocketHideout_B4F_Text_Airika3::
# 227 "data/maps/RocketHideout_B4F/scripts.pory"
	.string "AIRIKA: Ah, dear ZUBAT, so you've\n"
	.string "become a ZUBOT...\p"
	.string "Time to see how strong you are!$"

RocketHideout_B4F_Text_AirikaDefeat::
# 231 "data/maps/RocketHideout_B4F/scripts.pory"
	.string "Not strong enough?\n"
	.string "I'll have DR. C do some more\l"
	.string "modifications.$"

RocketHideout_B4F_Text_Airika4::
# 235 "data/maps/RocketHideout_B4F/scripts.pory"
	.string "AIRIKA: Are you ready, child?\n"
	.string "Feel the power of a ROBOT POKéMON!$"

RocketHideout_B4F_Text_Airika5::
# 239 "data/maps/RocketHideout_B4F/scripts.pory"
	.string "AIRIKA: You really think you've won,\n"
	.string "child?\p"
	.string "This is just the beginning.$"

RocketHideout_B4F_Text_Airika6::
# 243 "data/maps/RocketHideout_B4F/scripts.pory"
	.string "AIRIKA: Gentlemen, grab your things\n"
	.string "and let's go.\p"
	.string "There's more work to be done.$"

RocketHideout_B4F_Text_ReceiveZubot::
# 279 "data/maps/RocketHideout_B4F/scripts.pory"
	.string "AIRIKA received the ZUBOT\n"
	.string "from DR. C!$"
