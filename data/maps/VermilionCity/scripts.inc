VermilionCity_MapScripts::
# 4 "data/maps/VermilionCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 8 "data/maps/VermilionCity/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VermilionCity_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

VermilionCity_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 5 "data/maps/VermilionCity/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_VERMILION_CITY
# 6 "data/maps/VermilionCity/scripts.pory"
	call_if_set FLAG_TALKED_TO_OAKS_AIDE_IN_VERMILION, VermilionCity_EventScript_HideOaksAide
	return

VermilionCity_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 9 "data/maps/VermilionCity/scripts.pory"
	map_script_2 VAR_MAP_SCENE_VERMILION_CITY, 2, VermilionCity_EventScript_ExitSSAnne
	.2byte 0


VermilionCity_EventScript_Sergei::
# 14 "data/maps/VermilionCity/scripts.pory"
	lock
# 15 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 16 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 1, Vermilion_EventScript_SergeiGave
# 17 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 2, Vermilion_EventScript_SergeiReceive
# 18 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_VERMILION_CITY, 3, Vermilion_EventScript_SergeiFixing
# 19 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SergeiIntro, MSGBOX_NPC
# 20 "data/maps/VermilionCity/scripts.pory"
	giveitem_msg VermilionCity_Text_SSTicket, ITEM_SS_TICKET, 1, MUS_OBTAIN_KEY_ITEM
# 21 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SergeiBye, MSGBOX_NPC
# 22 "data/maps/VermilionCity/scripts.pory"
	addvar VAR_MAP_SCENE_VERMILION_CITY, 1
# 23 "data/maps/VermilionCity/scripts.pory"
	release
	end


Vermilion_EventScript_SergeiGave::
# 28 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SergeiBye, MSGBOX_NPC
# 29 "data/maps/VermilionCity/scripts.pory"
	release
	end


Vermilion_EventScript_SergeiReceive::
# 34 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SergeiReceive, MSGBOX_NPC
# 35 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_PlayerGives
# 36 "data/maps/VermilionCity/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 37 "data/maps/VermilionCity/scripts.pory"
	waitfanfare
# 38 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 39 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SergeiFix, MSGBOX_NPC
# 40 "data/maps/VermilionCity/scripts.pory"
	applymovement 2, VermilionCity_Movement_SergeiFix
# 41 "data/maps/VermilionCity/scripts.pory"
	waitmovement 0
# 42 "data/maps/VermilionCity/scripts.pory"
	release
	end


Vermilion_EventScript_SergeiFixing::
# 47 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_MustWait, MSGBOX_NPC
# 48 "data/maps/VermilionCity/scripts.pory"
	applymovement 2, Common_Movement_FaceUp
# 49 "data/maps/VermilionCity/scripts.pory"
	waitmovement 0
# 50 "data/maps/VermilionCity/scripts.pory"
	release
	end


# 82 "data/maps/VermilionCity/scripts.pory"
VermilionCity_Movement_SergeiFix:
# 83 "data/maps/VermilionCity/scripts.pory"
	walk_right
# 83 "data/maps/VermilionCity/scripts.pory"
	walk_right
# 84 "data/maps/VermilionCity/scripts.pory"
	walk_up
	step_end

# 87 "data/maps/VermilionCity/scripts.pory"

# 88 "data/maps/VermilionCity/scripts.pory"
.equ LOCALID_FERRY_SAILOR, 6
# 89 "data/maps/VermilionCity/scripts.pory"

# 90 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ExitSSAnne::
# 91 "data/maps/VermilionCity/scripts.pory"
	lockall
# 92 "data/maps/VermilionCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, VermilionCity_Movement_ExitSSAnne
# 93 "data/maps/VermilionCity/scripts.pory"
	waitmovement 0
# 94 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_MAP_SCENE_VERMILION_CITY, 3
# 95 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 96 "data/maps/VermilionCity/scripts.pory"
	end
# 97 "data/maps/VermilionCity/scripts.pory"

# 98 "data/maps/VermilionCity/scripts.pory"
VermilionCity_Movement_ExitSSAnne::
# 99 "data/maps/VermilionCity/scripts.pory"
	walk_up
# 100 "data/maps/VermilionCity/scripts.pory"
	walk_up
# 101 "data/maps/VermilionCity/scripts.pory"
	step_end
# 102 "data/maps/VermilionCity/scripts.pory"

# 103 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HideOaksAide::
# 104 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_HIDE_VERMILION_CITY_OAKS_AIDE
# 105 "data/maps/VermilionCity/scripts.pory"
	return
# 106 "data/maps/VermilionCity/scripts.pory"

# 107 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_Woman::
# 108 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_GrimerMultipliesInSludge, MSGBOX_NPC
# 109 "data/maps/VermilionCity/scripts.pory"
	end
# 110 "data/maps/VermilionCity/scripts.pory"

# 111 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_OldMan1::
# 112 "data/maps/VermilionCity/scripts.pory"
	lock
# 113 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 114 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_OldMan1SSAnneLeft
# 115 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DidYouSeeSSAnneInHarbor
# 116 "data/maps/VermilionCity/scripts.pory"
	release
# 117 "data/maps/VermilionCity/scripts.pory"
	end
# 118 "data/maps/VermilionCity/scripts.pory"

# 119 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_OldMan1SSAnneLeft::
# 120 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SSAnneHasDepartedForYear
# 121 "data/maps/VermilionCity/scripts.pory"
	release
# 122 "data/maps/VermilionCity/scripts.pory"
	end
# 123 "data/maps/VermilionCity/scripts.pory"

# 124 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_FerrySailor::
# 125 "data/maps/VermilionCity/scripts.pory"
	lock
# 126 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 127 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_CheckSeagallopPresent
# 128 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_WelcomeToTheSSAnne
# 129 "data/maps/VermilionCity/scripts.pory"
	release
# 130 "data/maps/VermilionCity/scripts.pory"
	end
# 131 "data/maps/VermilionCity/scripts.pory"

# 132 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckHasMysticTicket::
# 133 "data/maps/VermilionCity/scripts.pory"
	goto_if_unset FLAG_ENABLE_SHIP_NAVEL_ROCK, EventScript_SetResultFalse
# 134 "data/maps/VermilionCity/scripts.pory"
	checkitem ITEM_MYSTIC_TICKET
# 135 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, EventScript_SetResultFalse
# 136 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetResultTrue
# 137 "data/maps/VermilionCity/scripts.pory"
	end
# 138 "data/maps/VermilionCity/scripts.pory"

# 139 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckHasAuroraTicket::
# 140 "data/maps/VermilionCity/scripts.pory"
	goto_if_unset FLAG_ENABLE_SHIP_BIRTH_ISLAND, EventScript_SetResultFalse
# 141 "data/maps/VermilionCity/scripts.pory"
	checkitem ITEM_AURORA_TICKET
# 142 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, EventScript_SetResultFalse
# 143 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetResultTrue
# 144 "data/maps/VermilionCity/scripts.pory"
	end
# 145 "data/maps/VermilionCity/scripts.pory"

# 146 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckSeagallopPresent::
# 147 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 148 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5, VermilionCity_EventScript_ChooseSeagallopDestRainbowPass
# 149 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 1, VermilionCity_EventScript_ChooseSeagallopDestTriPass
# 150 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_TheShipSetSail
# 151 "data/maps/VermilionCity/scripts.pory"
	release
# 152 "data/maps/VermilionCity/scripts.pory"
	end
# 153 "data/maps/VermilionCity/scripts.pory"

# 154 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ChooseSeagallopDestRainbowPass::
# 155 "data/maps/VermilionCity/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 156 "data/maps/VermilionCity/scripts.pory"
	special QuestLog_CutRecording
# 157 "data/maps/VermilionCity/scripts.pory"
	call VermilionCity_EventScript_CheckHasMysticTicket
# 158 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasMysticTicket
# 159 "data/maps/VermilionCity/scripts.pory"
	call VermilionCity_EventScript_CheckHasAuroraTicket
# 160 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasAuroraTicket
# 161 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 162 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopRainbowPass
# 163 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 164 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SeviiDestinationsPage1
# 165 "data/maps/VermilionCity/scripts.pory"
	end
# 166 "data/maps/VermilionCity/scripts.pory"

# 167 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HasMysticTicket::
# 168 "data/maps/VermilionCity/scripts.pory"
	call VermilionCity_EventScript_CheckHasAuroraTicket
# 169 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasMysticAndAuroraTickets
# 170 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_MYSTIC_TICKET, VermilionCity_EventScript_ShowMysticTicket
# 171 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopFerry
# 172 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 173 "data/maps/VermilionCity/scripts.pory"
	multichoice 17, 6, MULTICHOICE_SEVII_NAVEL, FALSE
# 174 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 175 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SeviiDestinationsPage1
# 176 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToNavelRock
# 177 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_CancelSail
# 178 "data/maps/VermilionCity/scripts.pory"
	case 127, EventScript_CancelSail
# 179 "data/maps/VermilionCity/scripts.pory"
	end
# 180 "data/maps/VermilionCity/scripts.pory"

# 181 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ShowMysticTicket::
# 182 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_SHOWN_MYSTIC_TICKET
# 183 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_OhMysticTicketTakeYouToNavelRock
# 184 "data/maps/VermilionCity/scripts.pory"
	return
# 185 "data/maps/VermilionCity/scripts.pory"

# 186 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HasAuroraTicket::
# 187 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_AURORA_TICKET, VermilionCity_EventScript_ShowAuroraTicket
# 188 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopFerry
# 189 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 190 "data/maps/VermilionCity/scripts.pory"
	multichoice 13, 6, MULTICHOICE_SEVII_BIRTH, FALSE
# 191 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 192 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SeviiDestinationsPage1
# 193 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToBirthIsland
# 194 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_CancelSail
# 195 "data/maps/VermilionCity/scripts.pory"
	case 127, EventScript_CancelSail
# 196 "data/maps/VermilionCity/scripts.pory"
	end
# 197 "data/maps/VermilionCity/scripts.pory"

# 198 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ShowAuroraTicket::
# 199 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_SHOWN_AURORA_TICKET
# 200 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_OhAuroraTicketTakeYouToBirthIsland
# 201 "data/maps/VermilionCity/scripts.pory"
	return
# 202 "data/maps/VermilionCity/scripts.pory"

# 203 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HasMysticAndAuroraTickets::
# 204 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_MYSTIC_TICKET, VermilionCity_EventScript_ShowMysticTicket
# 205 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_AURORA_TICKET, VermilionCity_EventScript_ShowAuroraTicket
# 206 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopFerry
# 207 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 208 "data/maps/VermilionCity/scripts.pory"
	multichoice 13, 5, MULTICHOICE_SEVII_NAVEL_BIRTH, FALSE
# 209 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 210 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SeviiDestinationsPage1
# 211 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToNavelRock
# 212 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_SailToBirthIsland
# 213 "data/maps/VermilionCity/scripts.pory"
	case 3, EventScript_CancelSail
# 214 "data/maps/VermilionCity/scripts.pory"
	case 127, EventScript_CancelSail
# 215 "data/maps/VermilionCity/scripts.pory"
	end
# 216 "data/maps/VermilionCity/scripts.pory"

# 217 "data/maps/VermilionCity/scripts.pory"
EventScript_SailToNavelRock::
# 218 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Seagallop10Departing
# 219 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 220 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8006, SEAGALLOP_NAVEL_ROCK
# 221 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetSail
# 222 "data/maps/VermilionCity/scripts.pory"
	end
# 223 "data/maps/VermilionCity/scripts.pory"

# 224 "data/maps/VermilionCity/scripts.pory"
EventScript_SailToBirthIsland::
# 225 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Seagallop12Departing
# 226 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 227 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8006, SEAGALLOP_BIRTH_ISLAND
# 228 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetSail
# 229 "data/maps/VermilionCity/scripts.pory"
	end
# 230 "data/maps/VermilionCity/scripts.pory"

# 231 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ChooseSeagallopDestTriPass::
# 232 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopTriPass
# 233 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 234 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 235 "data/maps/VermilionCity/scripts.pory"
	multichoice 19, 5, MULTICHOICE_SEAGALLOP_123, FALSE
# 236 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 237 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SailToOneIsland2
# 238 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToTwoIsland2
# 239 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_SailToThreeIsland2
# 240 "data/maps/VermilionCity/scripts.pory"
	case 3, EventScript_CancelSail
# 241 "data/maps/VermilionCity/scripts.pory"
	case 127, EventScript_CancelSail
# 242 "data/maps/VermilionCity/scripts.pory"
	end
# 243 "data/maps/VermilionCity/scripts.pory"

# 244 "data/maps/VermilionCity/scripts.pory"
@ Unreachable
# 245 "data/maps/VermilionCity/scripts.pory"
Vermilion_EventScript_Unused::
# 246 "data/maps/VermilionCity/scripts.pory"
	release
# 247 "data/maps/VermilionCity/scripts.pory"
	end
# 248 "data/maps/VermilionCity/scripts.pory"

# 249 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckTicketLeft::
# 250 "data/maps/VermilionCity/scripts.pory"
	lockall
# 251 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_CheckTicket
# 252 "data/maps/VermilionCity/scripts.pory"
	end
# 253 "data/maps/VermilionCity/scripts.pory"

# 254 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckTicketRight::
# 255 "data/maps/VermilionCity/scripts.pory"
	lockall
# 256 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_CheckTicket
# 257 "data/maps/VermilionCity/scripts.pory"
	end
# 258 "data/maps/VermilionCity/scripts.pory"

# 259 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ExitedTicketCheck::
# 260 "data/maps/VermilionCity/scripts.pory"
	lockall
# 261 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 0
# 262 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 263 "data/maps/VermilionCity/scripts.pory"
	end
# 264 "data/maps/VermilionCity/scripts.pory"

# 265 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckTicket::
# 266 "data/maps/VermilionCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 267 "data/maps/VermilionCity/scripts.pory"
	applymovement LOCALID_FERRY_SAILOR, Common_Movement_WalkInPlaceFasterLeft
# 268 "data/maps/VermilionCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 269 "data/maps/VermilionCity/scripts.pory"
	waitmovement 0
# 270 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_CheckSeagallopPresentTrigger
# 271 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DoYouHaveATicket
# 272 "data/maps/VermilionCity/scripts.pory"
	goto_if_unset FLAG_GOT_SS_TICKET, VermilionCity_EventScript_DontHaveSSTicket
# 273 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_FlashedSSTicket
# 274 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 1
# 275 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 276 "data/maps/VermilionCity/scripts.pory"
	end
# 277 "data/maps/VermilionCity/scripts.pory"

# 278 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_DontHaveSSTicket::
# 279 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DontHaveNeededSSTicket
# 280 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 281 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_WalkUpPier
# 282 "data/maps/VermilionCity/scripts.pory"
	end
# 283 "data/maps/VermilionCity/scripts.pory"

# 284 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckSeagallopPresentTrigger::
# 285 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 286 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5, VermilionCity_EventScript_ChooseSeagallopDestRainbowPass
# 287 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 1, VermilionCity_EventScript_ChooseSeagallopDestTriPass
# 288 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_TheShipSetSail
# 289 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 290 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_WalkUpPier
# 291 "data/maps/VermilionCity/scripts.pory"
	end
# 292 "data/maps/VermilionCity/scripts.pory"

# 293 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_Sailor::
# 294 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SSAnneVisitsOnceAYear, MSGBOX_NPC
# 295 "data/maps/VermilionCity/scripts.pory"
	end
# 296 "data/maps/VermilionCity/scripts.pory"

# 297 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_OaksAide::
# 298 "data/maps/VermilionCity/scripts.pory"
	lock
# 299 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 300 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_TALKED_TO_OAKS_AIDE_IN_VERMILION
# 301 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Route2AideHasPackageForYou
# 302 "data/maps/VermilionCity/scripts.pory"
	release
# 303 "data/maps/VermilionCity/scripts.pory"
	end
# 304 "data/maps/VermilionCity/scripts.pory"

# 305 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_OldMan2::
# 306 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_BuildingOnThisLand, MSGBOX_NPC
# 307 "data/maps/VermilionCity/scripts.pory"
	end
# 308 "data/maps/VermilionCity/scripts.pory"

# 309 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_Machop::
# 310 "data/maps/VermilionCity/scripts.pory"
	lock
# 311 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 312 "data/maps/VermilionCity/scripts.pory"
	waitse
# 313 "data/maps/VermilionCity/scripts.pory"
	playmoncry SPECIES_MACHOP, CRY_MODE_NORMAL
# 314 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Machop
# 315 "data/maps/VermilionCity/scripts.pory"
	waitmoncry
# 316 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_MachopStompingLandFlat
# 317 "data/maps/VermilionCity/scripts.pory"
	release
# 318 "data/maps/VermilionCity/scripts.pory"
	end
# 319 "data/maps/VermilionCity/scripts.pory"

# 320 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CitySign::
# 321 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_CitySign, MSGBOX_SIGN
# 322 "data/maps/VermilionCity/scripts.pory"
	end
# 323 "data/maps/VermilionCity/scripts.pory"

# 324 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_SnorlaxNotice::
# 325 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SnorlaxBlockingRoute12, MSGBOX_SIGN
# 326 "data/maps/VermilionCity/scripts.pory"
	end
# 327 "data/maps/VermilionCity/scripts.pory"

# 328 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_PokemonFanClubSign::
# 329 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_PokemonFanClubSign, MSGBOX_SIGN
# 330 "data/maps/VermilionCity/scripts.pory"
	end
# 331 "data/maps/VermilionCity/scripts.pory"

# 332 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_GymSign::
# 333 "data/maps/VermilionCity/scripts.pory"
	lockall
# 334 "data/maps/VermilionCity/scripts.pory"
	famechecker FAMECHECKER_LTSURGE, 0
# 335 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_GymSign
# 336 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 337 "data/maps/VermilionCity/scripts.pory"
	end
# 338 "data/maps/VermilionCity/scripts.pory"

# 339 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HarborSign::
# 340 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_VermilionHarbor, MSGBOX_SIGN
# 341 "data/maps/VermilionCity/scripts.pory"
	end

VermilionCity_Text_SergeiIntro::
# 54 "data/maps/VermilionCity/scripts.pory"
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
# 58 "data/maps/VermilionCity/scripts.pory"
	.string "{PLAYER} received the S.S. TICKET\n"
	.string "from CDE SERGEI!$"

VermilionCity_Text_SergeiBye::
# 62 "data/maps/VermilionCity/scripts.pory"
	.string "SERGEI: OK! You go now!\n"
	.string "I stay here to watch over GYM.$"

VermilionCity_Text_SergeiReceive::
# 66 "data/maps/VermilionCity/scripts.pory"
	.string "SERGEI: Ah! {PLAYER}!\n"
	.string "You have returned with material?$"

VermilionCity_Text_PlayerGives::
# 70 "data/maps/VermilionCity/scripts.pory"
	.string "{PLAYER} gave the PARCEL to\n"
	.string "CDE SERGEI.$"

VermilionCity_Text_SergeiFix::
# 74 "data/maps/VermilionCity/scripts.pory"
	.string "SERGEI: Much thanks, comrade.\n"
	.string "I am go to fix wall now.$"

VermilionCity_Text_MustWait::
# 78 "data/maps/VermilionCity/scripts.pory"
	.string "SERGEI: Be patient, my friend.\n"
	.string "Fixing wall take time.$"
