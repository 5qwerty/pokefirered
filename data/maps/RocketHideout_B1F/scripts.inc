RocketHideout_B1F_MapScripts::
# 4 "data/maps/RocketHideout_B1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, RocketHideout_B1F_OnTransition
	.byte 0


RocketHideout_B1F_OnTransition::
# 8 "data/maps/RocketHideout_B1F/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_ROCKET_HIDEOUT_B1F
	end


RocketHideout_B1F_EventScript_LiftKey::
# 13 "data/maps/RocketHideout_B1F/scripts.pory"
	lock
# 14 "data/maps/RocketHideout_B1F/scripts.pory"
	faceplayer
# 15 "data/maps/RocketHideout_B1F/scripts.pory"
	setflag FLAG_CAN_USE_ROCKET_HIDEOUT_LIFT
# 16 "data/maps/RocketHideout_B1F/scripts.pory"
	removeobject 1
# 17 "data/maps/RocketHideout_B1F/scripts.pory"
	giveitem ITEM_LIFT_KEY
# 18 "data/maps/RocketHideout_B1F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
# 19 "data/maps/RocketHideout_B1F/scripts.pory"
	release
	end


# 23 "data/maps/RocketHideout_B1F/scripts.pory"

# 24 "data/maps/RocketHideout_B1F/scripts.pory"

# 25 "data/maps/RocketHideout_B1F/scripts.pory"
RocketHideout_B1F_EventScript_Grunt1::
# 26 "data/maps/RocketHideout_B1F/scripts.pory"
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_8, RocketHideout_B1F_Text_Grunt1Intro, RocketHideout_B1F_Text_Grunt1Defeat
# 27 "data/maps/RocketHideout_B1F/scripts.pory"
	msgbox RocketHideout_B1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
# 28 "data/maps/RocketHideout_B1F/scripts.pory"
	end
# 29 "data/maps/RocketHideout_B1F/scripts.pory"

# 30 "data/maps/RocketHideout_B1F/scripts.pory"
RocketHideout_B1F_EventScript_Grunt2::
# 31 "data/maps/RocketHideout_B1F/scripts.pory"
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_9, RocketHideout_B1F_Text_Grunt2Intro, RocketHideout_B1F_Text_Grunt2Defeat
# 32 "data/maps/RocketHideout_B1F/scripts.pory"
	msgbox RocketHideout_B1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
# 33 "data/maps/RocketHideout_B1F/scripts.pory"
	end
# 34 "data/maps/RocketHideout_B1F/scripts.pory"

# 35 "data/maps/RocketHideout_B1F/scripts.pory"
RocketHideout_B1F_EventScript_Grunt3::
# 36 "data/maps/RocketHideout_B1F/scripts.pory"
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_10, RocketHideout_B1F_Text_Grunt3Intro, RocketHideout_B1F_Text_Grunt3Defeat
# 37 "data/maps/RocketHideout_B1F/scripts.pory"
	msgbox RocketHideout_B1F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
# 38 "data/maps/RocketHideout_B1F/scripts.pory"
	end
# 39 "data/maps/RocketHideout_B1F/scripts.pory"

# 40 "data/maps/RocketHideout_B1F/scripts.pory"
RocketHideout_B1F_EventScript_Grunt4::
# 41 "data/maps/RocketHideout_B1F/scripts.pory"
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_11, RocketHideout_B1F_Text_Grunt4Intro, RocketHideout_B1F_Text_Grunt4Defeat
# 42 "data/maps/RocketHideout_B1F/scripts.pory"
	msgbox RocketHideout_B1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
# 43 "data/maps/RocketHideout_B1F/scripts.pory"
	end
# 44 "data/maps/RocketHideout_B1F/scripts.pory"

# 45 "data/maps/RocketHideout_B1F/scripts.pory"
RocketHideout_B1F_EventScript_Grunt5::
# 46 "data/maps/RocketHideout_B1F/scripts.pory"
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_12, RocketHideout_B1F_Text_Grunt5Intro, RocketHideout_B1F_Text_Grunt5Defeat
# 47 "data/maps/RocketHideout_B1F/scripts.pory"
	msgbox RocketHideout_B1F_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
# 48 "data/maps/RocketHideout_B1F/scripts.pory"
	end
