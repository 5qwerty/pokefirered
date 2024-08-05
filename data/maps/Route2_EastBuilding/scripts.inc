Route2_EastBuilding_MapScripts::
# 4 "data/maps/Route2_EastBuilding/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route2_EastBuilding_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Route2_EastBuilding_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 5 "data/maps/Route2_EastBuilding/scripts.pory"
	map_script_2 VAR_MAP_SCENE_ROUTE2, 0, Route2_EastBuilding_RivalBattle
	.2byte 0


Route2_EastBuilding_RivalBattle::
# 10 "data/maps/Route2_EastBuilding/scripts.pory"
	lockall
# 11 "data/maps/Route2_EastBuilding/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 12 "data/maps/Route2_EastBuilding/scripts.pory"
	playbgm MUS_ENCOUNTER_RIVAL, FALSE
# 13 "data/maps/Route2_EastBuilding/scripts.pory"
	delay 30
# 14 "data/maps/Route2_EastBuilding/scripts.pory"
	playse SE_PIN
# 15 "data/maps/Route2_EastBuilding/scripts.pory"
	applymovement 1, Common_Movement_ExclamUp
# 16 "data/maps/Route2_EastBuilding/scripts.pory"
	waitmovement 0
# 17 "data/maps/Route2_EastBuilding/scripts.pory"
	msgbox Route2_EastBuilding_Text_RivalHi
# 18 "data/maps/Route2_EastBuilding/scripts.pory"
	closemessage
# 19 "data/maps/Route2_EastBuilding/scripts.pory"
	applymovement 1, Route2_EastBuilding_Movement_RivalWalkUp
# 20 "data/maps/Route2_EastBuilding/scripts.pory"
	waitmovement 0
# 21 "data/maps/Route2_EastBuilding/scripts.pory"
	msgbox Route2_EastBuilding_Text_RivalHi2
# 22 "data/maps/Route2_EastBuilding/scripts.pory"
	closemessage
# 23 "data/maps/Route2_EastBuilding/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_ROUTE2, Route2_EastBuilding_Text_RivalLose
# 24 "data/maps/Route2_EastBuilding/scripts.pory"
	msgbox Route2_EastBuilding_Text_RivalBye
# 25 "data/maps/Route2_EastBuilding/scripts.pory"
	closemessage
# 26 "data/maps/Route2_EastBuilding/scripts.pory"
	playbgm MUS_RIVAL_EXIT, FALSE
# 27 "data/maps/Route2_EastBuilding/scripts.pory"
	applymovement 1, Route2_EastBuilding_Movement_RivalLeave
# 28 "data/maps/Route2_EastBuilding/scripts.pory"
	waitmovement 0
# 29 "data/maps/Route2_EastBuilding/scripts.pory"
	delay 30
# 30 "data/maps/Route2_EastBuilding/scripts.pory"
	removeobject 1
# 31 "data/maps/Route2_EastBuilding/scripts.pory"
	playse SE_EXIT
# 32 "data/maps/Route2_EastBuilding/scripts.pory"
	waitse
# 33 "data/maps/Route2_EastBuilding/scripts.pory"
	fadedefaultbgm
# 34 "data/maps/Route2_EastBuilding/scripts.pory"
	addvar VAR_MAP_SCENE_ROUTE2, 1
# 35 "data/maps/Route2_EastBuilding/scripts.pory"
	releaseall
	end


# 55 "data/maps/Route2_EastBuilding/scripts.pory"
Route2_EastBuilding_Movement_RivalWalkUp:
# 56 "data/maps/Route2_EastBuilding/scripts.pory"
	walk_up
# 56 "data/maps/Route2_EastBuilding/scripts.pory"
	walk_up
	step_end

# 59 "data/maps/Route2_EastBuilding/scripts.pory"
Route2_EastBuilding_Movement_RivalLeave:
# 60 "data/maps/Route2_EastBuilding/scripts.pory"
	walk_down
# 60 "data/maps/Route2_EastBuilding/scripts.pory"
	walk_down
# 60 "data/maps/Route2_EastBuilding/scripts.pory"
	walk_down
# 60 "data/maps/Route2_EastBuilding/scripts.pory"
	walk_down
# 60 "data/maps/Route2_EastBuilding/scripts.pory"
	walk_down
# 60 "data/maps/Route2_EastBuilding/scripts.pory"
	walk_down
# 60 "data/maps/Route2_EastBuilding/scripts.pory"
	walk_down
	step_end

Route2_EastBuilding_Text_RivalHi::
# 39 "data/maps/Route2_EastBuilding/scripts.pory"
	.string "{RIVAL}: Oh!\n"
	.string "If it isn't the nerd!$"

Route2_EastBuilding_Text_RivalHi2::
# 43 "data/maps/Route2_EastBuilding/scripts.pory"
	.string "{RIVAL}: You actually managed to\n"
	.string "get a BADGE?\p"
	.string "Hahahaha!\n"
	.string "You probably lucked out!\p"
	.string "Let's see if you against me can\n"
	.string "without gramps' help!$"

Route2_EastBuilding_Text_RivalLose::
# 47 "data/maps/Route2_EastBuilding/scripts.pory"
	.string "{RIVAL}: WHAT?\n"
	.string "How can one be so lucky?!$"

Route2_EastBuilding_Text_RivalBye::
# 51 "data/maps/Route2_EastBuilding/scripts.pory"
	.string "{RIVAL}: Tchh...\n"
	.string "Whatever...\p"
	.string "Don't think you're better than me\n"
	.string "just 'cause of one lousy battle.\p"
	.string "Sniff ya later, idiot!$"
