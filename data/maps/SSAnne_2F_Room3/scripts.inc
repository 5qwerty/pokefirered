SSAnne_2F_Room3_MapScripts::
	.byte 0


SSAnne_2F_Room3_EventScript_Bed::
# 6 "data/maps/SSAnne_2F_Room3/scripts.pory"
	lock
# 7 "data/maps/SSAnne_2F_Room3/scripts.pory"
	msgbox SSAnne_2F_Room3_Text_Bed, MSGBOX_YESNO
# 8 "data/maps/SSAnne_2F_Room3/scripts.pory"
	goto_if_eq VAR_RESULT, 1, SSAnne_2F_Room3_EventScript_BedYes
# 9 "data/maps/SSAnne_2F_Room3/scripts.pory"
	msgbox SSAnne_2F_Room3_Text_BedNo
# 10 "data/maps/SSAnne_2F_Room3/scripts.pory"
	closemessage
# 11 "data/maps/SSAnne_2F_Room3/scripts.pory"
	release
	end


SSAnne_2F_Room3_EventScript_BedYes::
# 16 "data/maps/SSAnne_2F_Room3/scripts.pory"
	msgbox SSAnne_2F_Room3_Text_BedYes
# 17 "data/maps/SSAnne_2F_Room3/scripts.pory"
	closemessage
# 18 "data/maps/SSAnne_2F_Room3/scripts.pory"
	call EventScript_OutOfCenterPartyHeal
# 19 "data/maps/SSAnne_2F_Room3/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_SS_ANNE_STATE, 0, SSAnne_2F_Room3_EventScript_ArriveCinnabar
# 20 "data/maps/SSAnne_2F_Room3/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_SS_ANNE_STATE, 2, SSAnne_2F_Room3_EventScript_ArriveVermilion
# 21 "data/maps/SSAnne_2F_Room3/scripts.pory"
	release
	end


SSAnne_2F_Room3_EventScript_ArriveCinnabar::
# 26 "data/maps/SSAnne_2F_Room3/scripts.pory"
	delay 50
# 27 "data/maps/SSAnne_2F_Room3/scripts.pory"
	playse SE_DING_DONG
# 28 "data/maps/SSAnne_2F_Room3/scripts.pory"
	waitse
# 29 "data/maps/SSAnne_2F_Room3/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 30 "data/maps/SSAnne_2F_Room3/scripts.pory"
	msgbox SSAnne_2F_Room3_Text_ArriveCinnabar
# 31 "data/maps/SSAnne_2F_Room3/scripts.pory"
	waitmessage
# 32 "data/maps/SSAnne_2F_Room3/scripts.pory"
	setvar VAR_MAP_SCENE_SS_ANNE_STATE, 1
# 33 "data/maps/SSAnne_2F_Room3/scripts.pory"
	setrespawn SPAWN_CINNABAR_ISLAND
# 34 "data/maps/SSAnne_2F_Room3/scripts.pory"
	setflag FLAG_HIDE_VERMILION_SS_ANNE
# 35 "data/maps/SSAnne_2F_Room3/scripts.pory"
	clearflag FLAG_HIDE_CINNABAR_SS_ANNE
# 36 "data/maps/SSAnne_2F_Room3/scripts.pory"
	release
	end


SSAnne_2F_Room3_EventScript_ArriveVermilion::
# 41 "data/maps/SSAnne_2F_Room3/scripts.pory"
	delay 50
# 42 "data/maps/SSAnne_2F_Room3/scripts.pory"
	playse SE_DING_DONG
# 43 "data/maps/SSAnne_2F_Room3/scripts.pory"
	waitse
# 44 "data/maps/SSAnne_2F_Room3/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 45 "data/maps/SSAnne_2F_Room3/scripts.pory"
	msgbox SSAnne_2F_Room3_Text_ArriveVermilion
# 46 "data/maps/SSAnne_2F_Room3/scripts.pory"
	waitmessage
# 47 "data/maps/SSAnne_2F_Room3/scripts.pory"
	setvar VAR_MAP_SCENE_SS_ANNE_STATE, 3
# 48 "data/maps/SSAnne_2F_Room3/scripts.pory"
	setrespawn SPAWN_VERMILION_CITY
# 49 "data/maps/SSAnne_2F_Room3/scripts.pory"
	setflag FLAG_HIDE_CINNABAR_SS_ANNE
# 50 "data/maps/SSAnne_2F_Room3/scripts.pory"
	clearflag FLAG_HIDE_VERMILION_SS_ANNE
# 51 "data/maps/SSAnne_2F_Room3/scripts.pory"
	release
	end


SSAnne_2F_Room3_Text_ArriveCinnabar::
# 55 "data/maps/SSAnne_2F_Room3/scripts.pory"
	.string "Attention!\n"
	.string "This is your CAPTAIN speaking.\p"
	.string "We have arrived at CINNABAR ISLAND!\n"
	.string "Please enjoy your visit.$"

SSAnne_2F_Room3_Text_ArriveVermilion::
# 59 "data/maps/SSAnne_2F_Room3/scripts.pory"
	.string "Attention!\n"
	.string "This is your CAPTAIN speaking.\p"
	.string "We have arrived at VERMILION CITY!\n"
	.string "Please enjoy your visit.$"

SSAnne_2F_Room3_Text_Bed::
# 63 "data/maps/SSAnne_2F_Room3/scripts.pory"
	.string "A comfy bed!\n"
	.string "Take a nap?$"

SSAnne_2F_Room3_Text_BedNo::
# 67 "data/maps/SSAnne_2F_Room3/scripts.pory"
	.string "Nah!\n"
	.string "Maybe later!$"

SSAnne_2F_Room3_Text_BedYes::
# 71 "data/maps/SSAnne_2F_Room3/scripts.pory"
	.string "Oh yeah!\n"
	.string "Time to hit the sack!$"
