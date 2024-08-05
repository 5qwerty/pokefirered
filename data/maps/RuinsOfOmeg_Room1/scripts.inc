RuinsOfOmeg_Room1_MapScripts::
# 10 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, RuinsOfOmeg_Room1_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 15 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RuinsOfOmeg_Room1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

RuinsOfOmeg_Room1_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 11 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	call_if_eq VAR_MAP_SCENE_OBSIDIAN_CITY_EVENTS, 2, RuinsOfOmeg_Room1_MoveNPCs
# 12 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	call_if_eq VAR_MAP_SCENE_OBSIDIAN_CITY_EVENTS, 3, RuinsOfOmeg_Room1_MoveNPCs
# 13 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	call_if_ge VAR_MAP_SCENE_OBSIDIAN_CITY_EVENTS, 4, RuinsOfOmeg_Room1_MoveSciGuy
	return

RuinsOfOmeg_Room1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 16 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	map_script_2 VAR_MAP_SCENE_OBSIDIAN_CITY_EVENTS, 2, RuinsOfOmeg_Room1_EnterScript
	.2byte 0


RuinsOfOmeg_Room1_MoveSciGuy::
# 21 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	setobjectxyperm 1, 22, 38
# 22 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_DOWN
	return


RuinsOfOmeg_Room1_MoveNPCs::
# 26 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	setobjectxyperm 3, 5, 39
# 27 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	setobjectxyperm 5, 5, 40
# 28 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	setobjectxyperm 4, 6, 40
# 29 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	setobjectxyperm 6, 6, 39
# 30 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	setobjectxyperm 1, 13, 39
# 31 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	setobjectmovementtype 3, MOVEMENT_TYPE_FACE_RIGHT
# 32 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_RIGHT
# 33 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_RIGHT
# 34 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	setobjectmovementtype 6, MOVEMENT_TYPE_FACE_RIGHT
# 35 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_LEFT
	return


RuinsOfOmeg_Room1_EnterScript::
# 39 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	lockall
# 40 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	applymovement 2, Common_Movement_WalkInPlaceRight
# 41 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	waitmovement 0
# 42 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 43 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	msgbox RuinsOfOmeg_Room1_Text_EveryoneSafe
# 44 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	closemessage
# 45 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	applymovement 1, Common_Movement_WalkInPlaceLeft
# 46 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	waitmovement 0
# 47 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	msgbox RuinsOfOmeg_Room1_Text_Explosion
# 48 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	closemessage
# 49 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	playse SE_PIN
# 50 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	applymovement 2, Common_Movement_ExclamRight
# 51 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	waitmovement 0
# 52 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	msgbox RuinsOfOmeg_Room1_Text_WhyBomb
# 53 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	closemessage
# 54 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	applymovement 1, Common_Movement_WalkInPlaceLeft
# 55 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	waitmovement 0
# 56 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	msgbox RuinsOfOmeg_Room1_Text_Corpse
# 57 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	closemessage
# 58 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	applymovement 2, Common_Movement_WalkInPlaceRight
# 59 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	waitmovement 0
# 60 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	msgbox RuinsOfOmeg_Room1_Text_ContactCinnabar
# 61 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	closemessage
# 62 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	applymovement 2, Common_Movement_WalkRight
# 63 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	waitmovement 0
# 64 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	applymovement 1, Common_Movement_FaceDown
# 65 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	applymovement 2, Common_Movement_WalkDown
# 66 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	waitmovement 0
# 67 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	applymovement 2, RuinsOfOmeg_Room1_Movement_Gio
# 68 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RuinsOfOmeg_Room1_Movement_Player
# 69 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	waitmovement 0
# 70 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	msgbox RuinsOfOmeg_Room1_Text_Tragedy
# 71 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	closemessage
# 72 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	applymovement 2, Common_Movement_FaceDown
# 73 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	waitmovement 0
# 74 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	delay 30
# 75 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	removeobject 2
# 76 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	playse SE_EXIT
# 77 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	waitse
# 78 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	delay 30
# 79 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	playbgm MUS_RIVAL_EXIT, 0
# 80 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	applymovement 6, RuinsOfOmeg_Room1_Movement_Rival1
# 81 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	waitmovement 0
# 82 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	msgbox RuinsOfOmeg_Room1_Text_RivalTalk
# 83 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	closemessage
# 84 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	applymovement 6, Common_Movement_FaceDown
# 85 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	waitmovement 0
# 86 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	delay 30
# 87 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	removeobject 6
# 88 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	playse SE_EXIT
# 89 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	waitse
# 90 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	addvar VAR_MAP_SCENE_OBSIDIAN_CITY_EVENTS, 1
# 91 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	clearflag FLAG_HIDE_GIO_GYM
# 92 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	fadedefaultbgm
# 93 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	releaseall
	end


# 125 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
RuinsOfOmeg_Room1_Movement_Gio:
# 126 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	walk_down
# 127 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	face_right
	step_end

# 130 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
RuinsOfOmeg_Room1_Movement_Player:
# 131 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	walk_right
# 132 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	face_left
	step_end

# 135 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
RuinsOfOmeg_Room1_Movement_Rival1:
# 136 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	walk_right
# 136 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	walk_right
# 136 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	walk_right
# 136 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	walk_right
# 136 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	walk_right
# 136 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	walk_right
# 137 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	walk_down
# 137 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	walk_down
# 138 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	face_right
	step_end

RuinsOfOmeg_Room1_Text_EveryoneSafe::
# 97 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	.string "GEOFFREY: Looks like ev'rybody's\n"
	.string "safe and accounted for.\p"
	.string "Now tell me, what on earth took\n"
	.string "place in here?$"

RuinsOfOmeg_Room1_Text_Explosion::
# 101 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	.string "Sir, we've confirmed that two\n"
	.string "explosions took place.\p"
	.string "The first allowed the criminals to\n"
	.string "enter the chamber containing the\l"
	.string "UNOWN.\p"
	.string "The second was lethal and killed\n"
	.string "all of the UNOWN in the chamber.$"

RuinsOfOmeg_Room1_Text_WhyBomb::
# 105 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	.string "GEOFFREY: Kill'n the UNOWN?!\n"
	.string "What purpose does that serve?\p"
	.string "Unless...\n"
	.string "They're after that old myth?\p"
	.string "Tell me, is there anything left in\n"
	.string "that chamber?$"

RuinsOfOmeg_Room1_Text_Corpse::
# 109 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	.string "It appears that the remains of the\n"
	.string "UNOWN have been taken by them.$"

RuinsOfOmeg_Room1_Text_ContactCinnabar::
# 113 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	.string "GEOFFREY: Contact CINNABAR ISLAND\n"
	.string "right this moment!\p"
	.string "Besides that, there's ain't much\n"
	.string "we can do.\p"
	.string "I'm headin' back to the GYM for now.$"

RuinsOfOmeg_Room1_Text_Tragedy::
# 117 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	.string "GEOFFREY: What a needless tragedy.\n"
	.string "Who were those people?\p"
	.string "An'way, I see that fire in yer\n"
	.string "eyes, so you better come down to\l"
	.string "the GYM, ya hear?$"

RuinsOfOmeg_Room1_Text_RivalTalk::
# 121 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	.string "{RIVAL}: Taking the corpses of the\n"
	.string "POKéMON? There is a point in that?\p"
	.string "I wonder what use they have...\n"
	.string "Hehehe...\p"
	.string "Sniff ya later, dork!$"
