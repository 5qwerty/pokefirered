VermilionCity_MapScripts::
# 5 "data/maps/VermilionCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 8 "data/maps/VermilionCity/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VermilionCity_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

VermilionCity_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 6 "data/maps/VermilionCity/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_VERMILION_CITY
	return

VermilionCity_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 9 "data/maps/VermilionCity/scripts.pory"
	map_script_2 VAR_MAP_SCENE_SS_ANNE_STATE, 3, VermilionCity_EventScript_LeaveSSAnne
	.2byte 0


VermilionCity_EventScript_LeaveSSAnne::
# 14 "data/maps/VermilionCity/scripts.pory"
	lockall
# 15 "data/maps/VermilionCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, VermilionCity_Movement_ExitSSAnne
# 16 "data/maps/VermilionCity/scripts.pory"
	waitmovement 0
# 17 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_MAP_SCENE_SS_ANNE_STATE, 0
# 18 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 0
# 19 "data/maps/VermilionCity/scripts.pory"
	releaseall
	end


# 23 "data/maps/VermilionCity/scripts.pory"
VermilionCity_Movement_ExitSSAnne:
# 24 "data/maps/VermilionCity/scripts.pory"
	walk_up
# 24 "data/maps/VermilionCity/scripts.pory"
	walk_up
	step_end

VermilionCity_EventScript_Sergei::
# 28 "data/maps/VermilionCity/scripts.pory"
	lock
# 29 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 30 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 1, Vermilion_EventScript_SergeiGave
# 31 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 2, Vermilion_EventScript_SergeiReceive
# 32 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_VERMILION_CITY, 3, Vermilion_EventScript_SergeiFixing
# 33 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SergeiIntro, MSGBOX_NPC
# 34 "data/maps/VermilionCity/scripts.pory"
	giveitem_msg VermilionCity_Text_SSTicket, ITEM_SS_TICKET, 1, MUS_OBTAIN_KEY_ITEM
# 35 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SergeiBye, MSGBOX_NPC
# 36 "data/maps/VermilionCity/scripts.pory"
	addvar VAR_MAP_SCENE_VERMILION_CITY, 1
# 37 "data/maps/VermilionCity/scripts.pory"
	release
	end


Vermilion_EventScript_SergeiGave::
# 42 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SergeiBye, MSGBOX_NPC
# 43 "data/maps/VermilionCity/scripts.pory"
	release
	end


Vermilion_EventScript_SergeiReceive::
# 48 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SergeiReceive, MSGBOX_NPC
# 49 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_PlayerGives
# 50 "data/maps/VermilionCity/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 51 "data/maps/VermilionCity/scripts.pory"
	waitfanfare
# 52 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 53 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SergeiFix, MSGBOX_NPC
# 54 "data/maps/VermilionCity/scripts.pory"
	applymovement 2, VermilionCity_Movement_SergeiFix
# 55 "data/maps/VermilionCity/scripts.pory"
	waitmovement 0
# 56 "data/maps/VermilionCity/scripts.pory"
	release
	end


Vermilion_EventScript_SergeiFixing::
# 61 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_MustWait, MSGBOX_NPC
# 62 "data/maps/VermilionCity/scripts.pory"
	applymovement 2, Common_Movement_FaceUp
# 63 "data/maps/VermilionCity/scripts.pory"
	waitmovement 0
# 64 "data/maps/VermilionCity/scripts.pory"
	release
	end


# 96 "data/maps/VermilionCity/scripts.pory"
VermilionCity_Movement_SergeiFix:
# 97 "data/maps/VermilionCity/scripts.pory"
	walk_right
# 97 "data/maps/VermilionCity/scripts.pory"
	walk_right
# 98 "data/maps/VermilionCity/scripts.pory"
	walk_up
	step_end

VermilionCity_EventScript_CheckTicket::
# 102 "data/maps/VermilionCity/scripts.pory"
	lockall
# 103 "data/maps/VermilionCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 104 "data/maps/VermilionCity/scripts.pory"
	applymovement 1, Common_Movement_WalkInPlaceFasterLeft
# 105 "data/maps/VermilionCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 106 "data/maps/VermilionCity/scripts.pory"
	waitmovement 0
# 107 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_SS_ANNE_STATE, 0, VermilionCity_EventScript_SSAnneHere
# 108 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SSAnneNotHere
# 109 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 110 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_WalkUpPier
	end


VermilionCity_EventScript_ExitedTicketCheck::
# 115 "data/maps/VermilionCity/scripts.pory"
	lockall
# 116 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 0
# 117 "data/maps/VermilionCity/scripts.pory"
	releaseall
	end


VermilionCity_EventScript_SSAnneHere::
# 123 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DoYouHaveATicket
# 124 "data/maps/VermilionCity/scripts.pory"
	checkitem ITEM_SS_TICKET
# 125 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_EventScript_DontHaveSSTicket
# 127 "data/maps/VermilionCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 128 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_FlashedSSTicket
# 129 "data/maps/VermilionCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 130 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_FlashedSSTicket2
# 131 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 1
# 132 "data/maps/VermilionCity/scripts.pory"
	releaseall
	return


VermilionCity_EventScript_DontHaveSSTicket::
# 136 "data/maps/VermilionCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 137 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DontHaveNeededSSTicket
# 138 "data/maps/VermilionCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 139 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DontHaveNeededSSTicket2
# 140 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_WalkUpPier
	end


VermilionCity_EventScript_WalkUpPier::
# 145 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 146 "data/maps/VermilionCity/scripts.pory"
	applymovement 1, Common_Movement_FaceOriginalDirection
# 147 "data/maps/VermilionCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
# 148 "data/maps/VermilionCity/scripts.pory"
	waitmovement 0
# 149 "data/maps/VermilionCity/scripts.pory"
	releaseall
	end


VermilionCity_EventScript_FerrySailor::
# 158 "data/maps/VermilionCity/scripts.pory"
	lock
# 159 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 160 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_WelcomeToTheSSAnne
# 161 "data/maps/VermilionCity/scripts.pory"
	release
	end


VermilionCity_EventScript_CitySign::
# 166 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_CitySign, MSGBOX_SIGN
# 167 "data/maps/VermilionCity/scripts.pory"
	clearflag FLAG_HIDE_VERMILION_SS_ANNE
	end


VermilionCity_EventScript_PokemonFanClubSign::
# 173 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_PokemonFanClubSign, MSGBOX_SIGN
	end


VermilionCity_EventScript_GymSign::
# 178 "data/maps/VermilionCity/scripts.pory"
	lockall
# 180 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_GymSign
# 181 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_HIDE_VERMILION_SS_ANNE
# 182 "data/maps/VermilionCity/scripts.pory"
	releaseall
	end


VermilionCity_EventScript_HarborSign::
# 187 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_VermilionHarbor, MSGBOX_SIGN
	end


VermilionCity_Text_SergeiIntro::
# 68 "data/maps/VermilionCity/scripts.pory"
	.string "???: Good day, comrade!\n"
	.string "Ah, you are {PLAYER}!\p"
	.string "I hear much from PROF. SOAK about\n"
	.string "you.\p"
	.string "Me? My name SERGEI, I used to be\n"
	.string "COMRADE in old country.\p"
	.string "As you see, my GYM wall is not so\n"
	.string "good, it needs the fix.\p"
	.string "Can you do me favour and take S.S.\n"
	.string "TICKET and go CINNABAR ISLAND to\l"
	.string "pick up material?$"

VermilionCity_Text_SSTicket::
# 72 "data/maps/VermilionCity/scripts.pory"
	.string "{PLAYER} received the S.S. TICKET\n"
	.string "from CDE SERGEI!$"

VermilionCity_Text_SergeiBye::
# 76 "data/maps/VermilionCity/scripts.pory"
	.string "SERGEI: OK! You go now!\n"
	.string "I stay here to watch over GYM.$"

VermilionCity_Text_SergeiReceive::
# 80 "data/maps/VermilionCity/scripts.pory"
	.string "SERGEI: Ah! {PLAYER}!\n"
	.string "You have returned with material?$"

VermilionCity_Text_PlayerGives::
# 84 "data/maps/VermilionCity/scripts.pory"
	.string "{PLAYER} gave the PARCEL to\n"
	.string "CDE SERGEI.$"

VermilionCity_Text_SergeiFix::
# 88 "data/maps/VermilionCity/scripts.pory"
	.string "SERGEI: Much thanks, comrade.\n"
	.string "I am go to fix wall now.$"

VermilionCity_Text_MustWait::
# 92 "data/maps/VermilionCity/scripts.pory"
	.string "SERGEI: Be patient, my friend.\n"
	.string "Fixing wall take time.$"

VermilionCity_Text_SSAnneNotHere::
# 153 "data/maps/VermilionCity/scripts.pory"
	.string "Apologies, the S.S. ANNE ain't\n"
	.string "here right now.$"

VermilionCity_Text_CitySign::
# 191 "data/maps/VermilionCity/scripts.pory"
	.string "VERMILION CITY\n"
	.string "The Port of Exquisite Sunsets$"

VermilionCity_Text_PokemonFanClubSign::
# 196 "data/maps/VermilionCity/scripts.pory"
	.string "POKéMON FAN CLUB\n"
	.string "All POKéMON fans welcome!$"

VermilionCity_Text_GymSign::
# 201 "data/maps/VermilionCity/scripts.pory"
	.string "VERMILION CITY POKéMON GYM\n"
	.string "LEADER: SERGEI\l"
	.string "The Surging Comrade!$"

VermilionCity_Text_VermilionHarbor::
# 207 "data/maps/VermilionCity/scripts.pory"
	.string "VERMILION HARBOR$"

VermilionCity_Text_WelcomeToTheSSAnne::
# 211 "data/maps/VermilionCity/scripts.pory"
	.string "Welcome to the S.S. ANNE!$"

VermilionCity_Text_DoYouHaveATicket::
# 215 "data/maps/VermilionCity/scripts.pory"
	.string "Welcome to the S.S. ANNE!\p"
	.string "Excuse me, do you have a ticket?$"

VermilionCity_Text_FlashedSSTicket::
# 220 "data/maps/VermilionCity/scripts.pory"
	.string "{PLAYER} flashed the S.S. TICKET!$"

VermilionCity_Text_FlashedSSTicket2::
# 224 "data/maps/VermilionCity/scripts.pory"
	.string "Great!\n"
	.string "Welcome to the S.S. ANNE!$"

VermilionCity_Text_DontHaveNeededSSTicket::
# 229 "data/maps/VermilionCity/scripts.pory"
	.string "{PLAYER} doesn't have the needed\n"
	.string "S.S. TICKET.$"

VermilionCity_Text_DontHaveNeededSSTicket2::
# 234 "data/maps/VermilionCity/scripts.pory"
	.string "Apologies!\p"
	.string "You need a ticket to get aboard.$"
