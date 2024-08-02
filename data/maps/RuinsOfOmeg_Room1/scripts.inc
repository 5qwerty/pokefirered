RuinsOfOmeg_Room1_MapScripts::
# 10 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, RuinsOfOmeg_Room1_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 14 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RuinsOfOmeg_Room1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

RuinsOfOmeg_Room1_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 11 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	call_if_eq VAR_MAP_SCENE_OBSIDIAN_CITY_EVENTS, 2, RuinsOfOmeg_Room1_MoveNPCs
# 12 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	call_if_ge VAR_MAP_SCENE_OBSIDIAN_CITY_EVENTS, 3, RuinsOfOmeg_Room1_MoveSciGuy
	return

RuinsOfOmeg_Room1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 15 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	map_script_2 VAR_MAP_SCENE_OBSIDIAN_CITY_EVENTS, 2, RuinsOfOmeg_Room1_EnterScript
	.2byte 0


RuinsOfOmeg_Room1_MoveSciGuy::
# 20 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	setobjectxyperm 1, 22, 38
# 21 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_DOWN
	return


RuinsOfOmeg_Room1_MoveNPCs::
# 25 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	setobjectxyperm 3, 5, 39
# 26 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	setobjectxyperm 5, 5, 40
# 27 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	setobjectxyperm 4, 6, 40
# 28 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	setobjectxyperm 6, 6, 39
# 29 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	setobjectxyperm 1, 13, 39
# 30 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	setobjectmovementtype 3, MOVEMENT_TYPE_FACE_RIGHT
# 31 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_RIGHT
# 32 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_RIGHT
# 33 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	setobjectmovementtype 6, MOVEMENT_TYPE_FACE_RIGHT
# 34 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_LEFT
	return


RuinsOfOmeg_Room1_EnterScript::
# 38 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	lockall
# 39 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	applymovement 2, Common_Movement_WalkInPlaceRight
# 40 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	waitmovement 0
# 41 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 42 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	msgbox RuinsOfOmeg_Room1_EveryoneSafe
# 43 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	closemessage
# 44 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	applymovement 1, Common_Movement_WalkInPlaceLeft
# 45 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	waitmovement 0
# 46 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	msgbox RuinsOfOmeg_Room1_Explosion
# 47 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	closemessage
# 48 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	playse SE_PIN
# 49 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	applymovement 2, Common_Movement_ExclamRight
# 50 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	waitmovement 0
# 51 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	msgbox RuinsOfOmeg_Room1_WhyBomb
# 52 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	closemessage
# 53 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	applymovement 1, Common_Movement_WalkInPlaceLeft
# 54 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	waitmovement 0
# 55 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	msgbox RuinsOfOmeg_Room1_Corpse
# 56 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	closemessage
# 57 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	applymovement 2, Common_Movement_WalkInPlaceRight
# 58 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	waitmovement 0
# 59 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	msgbox RuinsOfOmeg_Room1_ContactCinnabar
# 60 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	closemessage
# 61 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	applymovement 2, Common_Movement_WalkRight
# 62 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	waitmovement 0
# 63 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	applymovement 1, Common_Movement_FaceDown
# 64 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	applymovement 2, Common_Movement_WalkDown
# 65 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	waitmovement 0
# 66 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	applymovement 2, RuinsOfOmeg_Room1_Movement_Gio
# 67 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RuinsOfOmeg_Room1_Movement_Player
# 68 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	waitmovement 0
# 69 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	msgbox RuinsOfOmeg_Room1_Tragedy
# 70 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	closemessage
# 71 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	applymovement 2, Common_Movement_FaceDown
# 72 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	waitmovement 0
# 73 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	playse SE_EXIT
# 74 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	waitse
# 75 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	removeobject 2
# 76 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	playbgm MUS_RIVAL_EXIT, 0
# 77 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	applymovement 6, RuinsOfOmeg_Room1_Movement_Rival1
# 78 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	waitmovement 0
# 79 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	msgbox RuinsOfOmeg_Room1_RivalTalk
# 80 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	closemessage
# 81 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	applymovement 6, Common_Movement_FaceDown
# 82 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	waitmovement 0
# 83 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	playse SE_EXIT
# 84 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	waitse
# 85 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	removeobject 6
# 86 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	addvar VAR_MAP_SCENE_OBSIDIAN_CITY_EVENTS, 1
# 87 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	clearflag FLAG_HIDE_GIO_GYM
# 88 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	fadedefaultbgm
# 89 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	releaseall
	end


# 121 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
RuinsOfOmeg_Room1_Movement_Gio:
# 122 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	walk_down
# 123 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	face_right
	step_end

# 126 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
RuinsOfOmeg_Room1_Movement_Player:
# 127 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	walk_right
# 128 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	face_left
	step_end

# 131 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
RuinsOfOmeg_Room1_Movement_Rival1:
# 132 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	walk_right
# 132 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	walk_right
# 132 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	walk_right
# 132 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	walk_right
# 132 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	walk_right
# 132 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	walk_right
# 133 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	walk_down
# 133 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	walk_down
# 134 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	face_right
	step_end

RuinsOfOmeg_Room1_EveryoneSafe::
# 93 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	.string "GEOFFREY: Looks like ev'rybody's\n"
	.string "safe and accounted for.\p"
	.string "Now tell me, what on earth took\n"
	.string "place in here?$"

RuinsOfOmeg_Room1_Explosion::
# 97 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	.string "Sir, we've confirmed that two\n"
	.string "explosions took place.\p"
	.string "The first allowed the criminals to\n"
	.string "enter the chamber containing the\l"
	.string "UNOWN.\p"
	.string "The second was lethal and killed\n"
	.string "all of the UNOWN in the chamber.$"

RuinsOfOmeg_Room1_WhyBomb::
# 101 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	.string "GEOFFREY: Kill'n the UNOWN?!\n"
	.string "What purpose does that serve?\p"
	.string "Unless...\n"
	.string "They're after that old myth?\p"
	.string "Tell me, is there anything left in\n"
	.string "that chamber?$"

RuinsOfOmeg_Room1_Corpse::
# 105 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	.string "It appears that the remains of the\n"
	.string "UNOWN have been taken by them.$"

RuinsOfOmeg_Room1_ContactCinnabar::
# 109 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	.string "GEOFFREY: Contact CINNABAR ISLAND\n"
	.string "right this moment!\p"
	.string "Besides that, there's ain't much\n"
	.string "we can do.\p"
	.string "I'm headin' back to the GYM for now.$"

RuinsOfOmeg_Room1_Tragedy::
# 113 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	.string "GEOFFREY: What a needless tragedy.\n"
	.string "Who were those people?\p"
	.string "An'way, I see that fire in yer\n"
	.string "eyes, so you better come down to\l"
	.string "the GYM, ya hear?$"

RuinsOfOmeg_Room1_RivalTalk::
# 117 "data/maps/RuinsOfOmeg_Room1/scripts.pory"
	.string "{RIVAL}: Taking the corpses of the\n"
	.string "POKéMON? There is a point in that?\p"
	.string "I wonder what use they have...\n"
	.string "Hehehe...\p"
	.string "Sniff ya later, dork!$"
