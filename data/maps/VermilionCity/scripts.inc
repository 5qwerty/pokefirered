VermilionCity_MapScripts::
# 5 "data/maps/VermilionCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

VermilionCity_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 6 "data/maps/VermilionCity/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_VERMILION_CITY
	return


VermilionCity_EventScript_Sergei::
# 11 "data/maps/VermilionCity/scripts.pory"
	lock
# 12 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 13 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 1, Vermilion_EventScript_SergeiGave
# 14 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 2, Vermilion_EventScript_SergeiReceive
# 15 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_VERMILION_CITY, 3, Vermilion_EventScript_SergeiFixing
# 16 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SergeiIntro, MSGBOX_NPC
# 17 "data/maps/VermilionCity/scripts.pory"
	giveitem_msg VermilionCity_Text_SSTicket, ITEM_SS_TICKET, 1, MUS_OBTAIN_KEY_ITEM
# 18 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SergeiBye, MSGBOX_NPC
# 19 "data/maps/VermilionCity/scripts.pory"
	addvar VAR_MAP_SCENE_VERMILION_CITY, 1
# 20 "data/maps/VermilionCity/scripts.pory"
	release
	end


Vermilion_EventScript_SergeiGave::
# 25 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SergeiBye, MSGBOX_NPC
# 26 "data/maps/VermilionCity/scripts.pory"
	release
	end


Vermilion_EventScript_SergeiReceive::
# 31 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SergeiReceive, MSGBOX_NPC
# 32 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_PlayerGives
# 33 "data/maps/VermilionCity/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 34 "data/maps/VermilionCity/scripts.pory"
	waitfanfare
# 35 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 36 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SergeiFix, MSGBOX_NPC
# 37 "data/maps/VermilionCity/scripts.pory"
	applymovement 2, VermilionCity_Movement_SergeiFix
# 38 "data/maps/VermilionCity/scripts.pory"
	waitmovement 0
# 39 "data/maps/VermilionCity/scripts.pory"
	release
	end


Vermilion_EventScript_SergeiFixing::
# 44 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_MustWait, MSGBOX_NPC
# 45 "data/maps/VermilionCity/scripts.pory"
	applymovement 2, Common_Movement_FaceUp
# 46 "data/maps/VermilionCity/scripts.pory"
	waitmovement 0
# 47 "data/maps/VermilionCity/scripts.pory"
	release
	end


# 79 "data/maps/VermilionCity/scripts.pory"
VermilionCity_Movement_SergeiFix:
# 80 "data/maps/VermilionCity/scripts.pory"
	walk_right
# 80 "data/maps/VermilionCity/scripts.pory"
	walk_right
# 81 "data/maps/VermilionCity/scripts.pory"
	walk_up
	step_end

VermilionCity_EventScript_CheckTicket::
# 85 "data/maps/VermilionCity/scripts.pory"
	lockall
# 86 "data/maps/VermilionCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 87 "data/maps/VermilionCity/scripts.pory"
	applymovement 1, Common_Movement_WalkInPlaceFasterLeft
# 88 "data/maps/VermilionCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 89 "data/maps/VermilionCity/scripts.pory"
	waitmovement 0
# 90 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DoYouHaveATicket
# 91 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_SS_ANNE_STATE, 0, VermilionCity_EventScript_SSAnneHere
# 92 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SSAnneNotHere
# 93 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 94 "data/maps/VermilionCity/scripts.pory"
	releaseall
	end


VermilionCity_EventScript_ExitedTicketCheck::
# 99 "data/maps/VermilionCity/scripts.pory"
	lockall
# 100 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 0
# 101 "data/maps/VermilionCity/scripts.pory"
	releaseall
	end


VermilionCity_EventScript_SSAnneHere::
# 107 "data/maps/VermilionCity/scripts.pory"
	checkitem ITEM_SS_TICKET
# 108 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_EventScript_DontHaveSSTicket
# 110 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_FlashedSSTicket
# 111 "data/maps/VermilionCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 112 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_FlashedSSTicket2
# 113 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 1
# 114 "data/maps/VermilionCity/scripts.pory"
	releaseall
	return


VermilionCity_EventScript_DontHaveSSTicket::
# 118 "data/maps/VermilionCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 119 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DontHaveNeededSSTicket
# 120 "data/maps/VermilionCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 121 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DontHaveNeededSSTicket2
# 122 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_WalkUpPier
	end


VermilionCity_EventScript_WalkUpPier::
# 127 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 128 "data/maps/VermilionCity/scripts.pory"
	applymovement 1, Common_Movement_FaceOriginalDirection
# 129 "data/maps/VermilionCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
# 130 "data/maps/VermilionCity/scripts.pory"
	waitmovement 0
# 131 "data/maps/VermilionCity/scripts.pory"
	releaseall
	end


VermilionCity_EventScript_FerrySailor::
# 140 "data/maps/VermilionCity/scripts.pory"
	lock
# 141 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 142 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_WelcomeToTheSSAnne
# 143 "data/maps/VermilionCity/scripts.pory"
	release
	end


VermilionCity_EventScript_CitySign::
# 148 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_CitySign, MSGBOX_SIGN
# 149 "data/maps/VermilionCity/scripts.pory"
	clearflag FLAG_HIDE_SS_ANNE
	end


VermilionCity_EventScript_PokemonFanClubSign::
# 155 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_PokemonFanClubSign, MSGBOX_SIGN
	end


VermilionCity_EventScript_GymSign::
# 160 "data/maps/VermilionCity/scripts.pory"
	lockall
# 162 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_GymSign
# 163 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_HIDE_SS_ANNE
# 164 "data/maps/VermilionCity/scripts.pory"
	releaseall
	end


VermilionCity_EventScript_HarborSign::
# 169 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_VermilionHarbor, MSGBOX_SIGN
	end


VermilionCity_Text_SergeiIntro::
# 51 "data/maps/VermilionCity/scripts.pory"
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
# 55 "data/maps/VermilionCity/scripts.pory"
	.string "{PLAYER} received the S.S. TICKET\n"
	.string "from CDE SERGEI!$"

VermilionCity_Text_SergeiBye::
# 59 "data/maps/VermilionCity/scripts.pory"
	.string "SERGEI: OK! You go now!\n"
	.string "I stay here to watch over GYM.$"

VermilionCity_Text_SergeiReceive::
# 63 "data/maps/VermilionCity/scripts.pory"
	.string "SERGEI: Ah! {PLAYER}!\n"
	.string "You have returned with material?$"

VermilionCity_Text_PlayerGives::
# 67 "data/maps/VermilionCity/scripts.pory"
	.string "{PLAYER} gave the PARCEL to\n"
	.string "CDE SERGEI.$"

VermilionCity_Text_SergeiFix::
# 71 "data/maps/VermilionCity/scripts.pory"
	.string "SERGEI: Much thanks, comrade.\n"
	.string "I am go to fix wall now.$"

VermilionCity_Text_MustWait::
# 75 "data/maps/VermilionCity/scripts.pory"
	.string "SERGEI: Be patient, my friend.\n"
	.string "Fixing wall take time.$"

VermilionCity_Text_SSAnneNotHere::
# 135 "data/maps/VermilionCity/scripts.pory"
	.string "Apologies, the S.S. ANNE ain't\n"
	.string "here right now.$"

VermilionCity_Text_CitySign::
# 173 "data/maps/VermilionCity/scripts.pory"
	.string "VERMILION CITY\n"
	.string "The Port of Exquisite Sunsets$"

VermilionCity_Text_PokemonFanClubSign::
# 178 "data/maps/VermilionCity/scripts.pory"
	.string "POKéMON FAN CLUB\n"
	.string "All POKéMON fans welcome!$"

VermilionCity_Text_GymSign::
# 183 "data/maps/VermilionCity/scripts.pory"
	.string "VERMILION CITY POKéMON GYM\n"
	.string "LEADER: SERGEI\l"
	.string "The Surging Comrade!$"

VermilionCity_Text_VermilionHarbor::
# 189 "data/maps/VermilionCity/scripts.pory"
	.string "VERMILION HARBOR$"

VermilionCity_Text_WelcomeToTheSSAnne::
# 193 "data/maps/VermilionCity/scripts.pory"
	.string "Welcome to the S.S. ANNE!$"

VermilionCity_Text_DoYouHaveATicket::
# 197 "data/maps/VermilionCity/scripts.pory"
	.string "Welcome to the S.S. ANNE!\p"
	.string "Excuse me, do you have a ticket?$"

VermilionCity_Text_FlashedSSTicket::
# 202 "data/maps/VermilionCity/scripts.pory"
	.string "{PLAYER} flashed the S.S. TICKET!$"

VermilionCity_Text_FlashedSSTicket2::
# 206 "data/maps/VermilionCity/scripts.pory"
	.string "Great!\n"
	.string "Welcome to the S.S. ANNE!$"

VermilionCity_Text_DontHaveNeededSSTicket::
# 211 "data/maps/VermilionCity/scripts.pory"
	.string "{PLAYER} doesn't have the needed\n"
	.string "S.S. TICKET.$"

VermilionCity_Text_DontHaveNeededSSTicket2::
# 216 "data/maps/VermilionCity/scripts.pory"
	.string "Apologies!\p"
	.string "You need a ticket to get aboard.$"
