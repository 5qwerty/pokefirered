ObsidianCity_MapScripts::
# 9 "data/maps/ObsidianCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, ObsidianCity_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 14 "data/maps/ObsidianCity/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, ObsidianCity_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

ObsidianCity_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 10 "data/maps/ObsidianCity/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_OBSIDIAN_CITY
# 11 "data/maps/ObsidianCity/scripts.pory"
	call_if_eq VAR_MAP_SCENE_OBSIDIAN_CITY_EVENTS, 1, ObsidianCity_EventScript_MoveGio
# 12 "data/maps/ObsidianCity/scripts.pory"
	call_if_eq VAR_MAP_SCENE_OBSIDIAN_CITY_EVENTS, 3, ObsidianCity_EventScript_UpVar
	return

ObsidianCity_MapScripts_MAP_SCRIPT_ON_LOAD:
# 15 "data/maps/ObsidianCity/scripts.pory"
	call_if_ge VAR_MAP_SCENE_OBSIDIAN_CITY_EVENTS, 1, ObsidianCity_EventScript_OpenHole
	return


ObsidianCity_EventScript_OpenHole::
# 20 "data/maps/ObsidianCity/scripts.pory"
	setmetatile 17, 28, 0x0A9, 0
	return


ObsidianCity_EventScript_UpVar::
# 24 "data/maps/ObsidianCity/scripts.pory"
	addvar VAR_MAP_SCENE_OBSIDIAN_CITY_EVENTS, 1
	return


ObsidianCity_EventScript_MoveGio::
# 28 "data/maps/ObsidianCity/scripts.pory"
	setobjectxyperm 6, 21, 22
# 29 "data/maps/ObsidianCity/scripts.pory"
	setobjectmovementtype 6, MOVEMENT_TYPE_FACE_DOWN
# 30 "data/maps/ObsidianCity/scripts.pory"
	setobjectxyperm 1, 21, 23
# 31 "data/maps/ObsidianCity/scripts.pory"
	setobjectxyperm 2, 21, 24
# 32 "data/maps/ObsidianCity/scripts.pory"
	setobjectxyperm 3, 21, 25
# 33 "data/maps/ObsidianCity/scripts.pory"
	setobjectxyperm 4, 21, 26
	return


ObsidianCity_EventScript_GymTrigger::
# 37 "data/maps/ObsidianCity/scripts.pory"
	lockall
# 38 "data/maps/ObsidianCity/scripts.pory"
	playse SE_PIN
# 39 "data/maps/ObsidianCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamDown
# 40 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 41 "data/maps/ObsidianCity/scripts.pory"
	setvar 0x8004, 2
# 42 "data/maps/ObsidianCity/scripts.pory"
	setvar 0x8005, 2
# 43 "data/maps/ObsidianCity/scripts.pory"
	setvar 0x8006, 20
# 44 "data/maps/ObsidianCity/scripts.pory"
	setvar 0x8007, 4
# 45 "data/maps/ObsidianCity/scripts.pory"
	special ShakeScreen
# 46 "data/maps/ObsidianCity/scripts.pory"
	delay 80
# 47 "data/maps/ObsidianCity/scripts.pory"
	opendoor 6, 5
# 48 "data/maps/ObsidianCity/scripts.pory"
	waitdooranim
# 49 "data/maps/ObsidianCity/scripts.pory"
	addobject 6
# 50 "data/maps/ObsidianCity/scripts.pory"
	clearflag FLAG_HIDE_GIO_OBSIDIAN
# 51 "data/maps/ObsidianCity/scripts.pory"
	applymovement 6, Common_Movement_WalkDown
# 52 "data/maps/ObsidianCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
# 53 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 54 "data/maps/ObsidianCity/scripts.pory"
	closedoor 6, 5
# 55 "data/maps/ObsidianCity/scripts.pory"
	waitdooranim
# 56 "data/maps/ObsidianCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 57 "data/maps/ObsidianCity/scripts.pory"
	msgbox ObsidianCity_Text_WhatInTarnation
# 58 "data/maps/ObsidianCity/scripts.pory"
	closemessage
# 59 "data/maps/ObsidianCity/scripts.pory"
	delay 30
# 60 "data/maps/ObsidianCity/scripts.pory"
	applymovement 6, Common_Movement_FaceLeft
# 61 "data/maps/ObsidianCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 62 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 63 "data/maps/ObsidianCity/scripts.pory"
	msgbox ObsidianCity_Text_YouHeardToo
# 64 "data/maps/ObsidianCity/scripts.pory"
	closemessage
# 65 "data/maps/ObsidianCity/scripts.pory"
	playse SE_PIN
# 66 "data/maps/ObsidianCity/scripts.pory"
	applymovement 6, Common_Movement_ExclamDown
# 67 "data/maps/ObsidianCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamDown
# 68 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 69 "data/maps/ObsidianCity/scripts.pory"
	setvar 0x8004, 3
# 70 "data/maps/ObsidianCity/scripts.pory"
	setvar 0x8005, 3
# 71 "data/maps/ObsidianCity/scripts.pory"
	setvar 0x8006, 30
# 72 "data/maps/ObsidianCity/scripts.pory"
	setvar 0x8007, 4
# 73 "data/maps/ObsidianCity/scripts.pory"
	special ShakeScreen
# 74 "data/maps/ObsidianCity/scripts.pory"
	delay 120
# 75 "data/maps/ObsidianCity/scripts.pory"
	msgbox ObsidianCity_Text_IGo
# 76 "data/maps/ObsidianCity/scripts.pory"
	closemessage
# 77 "data/maps/ObsidianCity/scripts.pory"
	applymovement 6, ObsidianCity_Movement_Leave
# 78 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 79 "data/maps/ObsidianCity/scripts.pory"
	removeobject 6
# 80 "data/maps/ObsidianCity/scripts.pory"
	setvar VAR_MAP_SCENE_OBSIDIAN_CITY_EVENTS, 1
# 81 "data/maps/ObsidianCity/scripts.pory"
	setobjectxyperm 6, 21, 22
# 82 "data/maps/ObsidianCity/scripts.pory"
	setobjectmovementtype 6, MOVEMENT_TYPE_FACE_DOWN
# 83 "data/maps/ObsidianCity/scripts.pory"
	setmetatile 17, 28, 0x0A9, 0
# 84 "data/maps/ObsidianCity/scripts.pory"
	addobject 6
# 85 "data/maps/ObsidianCity/scripts.pory"
	clearflag FLAG_HIDE_GIO_OBSIDIAN
# 86 "data/maps/ObsidianCity/scripts.pory"
	setobjectxyperm 1, 21, 23
# 87 "data/maps/ObsidianCity/scripts.pory"
	setobjectxyperm 2, 21, 24
# 88 "data/maps/ObsidianCity/scripts.pory"
	setobjectxyperm 3, 21, 25
# 89 "data/maps/ObsidianCity/scripts.pory"
	setobjectxyperm 4, 21, 26
# 90 "data/maps/ObsidianCity/scripts.pory"
	releaseall
	end


# 106 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_Leave:
# 107 "data/maps/ObsidianCity/scripts.pory"
	walk_right
# 107 "data/maps/ObsidianCity/scripts.pory"
	walk_right
# 107 "data/maps/ObsidianCity/scripts.pory"
	walk_right
# 107 "data/maps/ObsidianCity/scripts.pory"
	walk_right
# 108 "data/maps/ObsidianCity/scripts.pory"
	walk_down
# 109 "data/maps/ObsidianCity/scripts.pory"
	walk_right
# 109 "data/maps/ObsidianCity/scripts.pory"
	walk_right
# 109 "data/maps/ObsidianCity/scripts.pory"
	walk_right
# 109 "data/maps/ObsidianCity/scripts.pory"
	walk_right
# 109 "data/maps/ObsidianCity/scripts.pory"
	walk_right
	step_end

ObsidianCity_EventScript_TriggerLeft::
# 113 "data/maps/ObsidianCity/scripts.pory"
	lockall
# 114 "data/maps/ObsidianCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 115 "data/maps/ObsidianCity/scripts.pory"
	msgbox ObsidianCity_Text_OuttaTheWay
# 116 "data/maps/ObsidianCity/scripts.pory"
	closemessage
# 117 "data/maps/ObsidianCity/scripts.pory"
	delay 60
# 118 "data/maps/ObsidianCity/scripts.pory"
	applymovement 1, ObsidianCity_Movement_Rocket1First
# 119 "data/maps/ObsidianCity/scripts.pory"
	applymovement 2, ObsidianCity_Movement_Rocket2First
# 120 "data/maps/ObsidianCity/scripts.pory"
	applymovement 3, ObsidianCity_Movement_Rocket3First
# 121 "data/maps/ObsidianCity/scripts.pory"
	applymovement 4, ObsidianCity_Movement_Rocket4First
# 122 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 123 "data/maps/ObsidianCity/scripts.pory"
	applymovement 6, ObsidianCity_Movement_GioOuttaWay
# 124 "data/maps/ObsidianCity/scripts.pory"
	applymovement 1, ObsidianCity_Movement_Rocket1Second
# 125 "data/maps/ObsidianCity/scripts.pory"
	applymovement 2, ObsidianCity_Movement_Rocket2Second
# 126 "data/maps/ObsidianCity/scripts.pory"
	applymovement 3, ObsidianCity_Movement_Rocket3Second
# 127 "data/maps/ObsidianCity/scripts.pory"
	applymovement 4, ObsidianCity_Movement_Rocket4Second
# 128 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 129 "data/maps/ObsidianCity/scripts.pory"
	applymovement 6, Common_Movement_FaceUp
# 130 "data/maps/ObsidianCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, ObsidianCity_Movement_PlayerLookRocketLeft
# 131 "data/maps/ObsidianCity/scripts.pory"
	applymovement 1, ObsidianCity_Movement_Rocket1Third
# 132 "data/maps/ObsidianCity/scripts.pory"
	applymovement 2, ObsidianCity_Movement_Rocket2Third
# 133 "data/maps/ObsidianCity/scripts.pory"
	applymovement 3, ObsidianCity_Movement_Rocket3Third
# 134 "data/maps/ObsidianCity/scripts.pory"
	applymovement 4, ObsidianCity_Movement_Rocket4Third
# 135 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 136 "data/maps/ObsidianCity/scripts.pory"
	delay 30
# 137 "data/maps/ObsidianCity/scripts.pory"
	msgbox ObsidianCity_Text_RightThing
# 138 "data/maps/ObsidianCity/scripts.pory"
	closemessage
# 139 "data/maps/ObsidianCity/scripts.pory"
	applymovement 4, ObsidianCity_Movement_Rocket4Fourth
# 140 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 141 "data/maps/ObsidianCity/scripts.pory"
	delay 30
# 142 "data/maps/ObsidianCity/scripts.pory"
	removeobject 1
# 143 "data/maps/ObsidianCity/scripts.pory"
	removeobject 2
# 144 "data/maps/ObsidianCity/scripts.pory"
	removeobject 3
# 145 "data/maps/ObsidianCity/scripts.pory"
	removeobject 4
# 146 "data/maps/ObsidianCity/scripts.pory"
	removeobject 5
# 147 "data/maps/ObsidianCity/scripts.pory"
	applymovement 6, ObsidianCity_Movement_GioToPlayerLeftMid
# 148 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 149 "data/maps/ObsidianCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 150 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 151 "data/maps/ObsidianCity/scripts.pory"
	msgbox ObsidianCity_Text_SeeThat
# 152 "data/maps/ObsidianCity/scripts.pory"
	closemessage
# 153 "data/maps/ObsidianCity/scripts.pory"
	applymovement 6, ObsidianCity_Movement_GioToRuinsLeftMid
# 154 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 155 "data/maps/ObsidianCity/scripts.pory"
	removeobject 6
# 156 "data/maps/ObsidianCity/scripts.pory"
	setvar VAR_MAP_SCENE_OBSIDIAN_CITY_EVENTS, 2
# 157 "data/maps/ObsidianCity/scripts.pory"
	releaseall
	end


ObsidianCity_EventScript_TriggerMid::
# 162 "data/maps/ObsidianCity/scripts.pory"
	lockall
# 163 "data/maps/ObsidianCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 164 "data/maps/ObsidianCity/scripts.pory"
	msgbox ObsidianCity_Text_OuttaTheWay
# 165 "data/maps/ObsidianCity/scripts.pory"
	closemessage
# 166 "data/maps/ObsidianCity/scripts.pory"
	delay 60
# 167 "data/maps/ObsidianCity/scripts.pory"
	applymovement 1, ObsidianCity_Movement_Rocket1First
# 168 "data/maps/ObsidianCity/scripts.pory"
	applymovement 2, ObsidianCity_Movement_Rocket2First
# 169 "data/maps/ObsidianCity/scripts.pory"
	applymovement 3, ObsidianCity_Movement_Rocket3First
# 170 "data/maps/ObsidianCity/scripts.pory"
	applymovement 4, ObsidianCity_Movement_Rocket4First
# 171 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 172 "data/maps/ObsidianCity/scripts.pory"
	applymovement 6, ObsidianCity_Movement_GioOuttaWay
# 173 "data/maps/ObsidianCity/scripts.pory"
	applymovement 1, ObsidianCity_Movement_Rocket1Second
# 174 "data/maps/ObsidianCity/scripts.pory"
	applymovement 2, ObsidianCity_Movement_Rocket2Second
# 175 "data/maps/ObsidianCity/scripts.pory"
	applymovement 3, ObsidianCity_Movement_Rocket3Second
# 176 "data/maps/ObsidianCity/scripts.pory"
	applymovement 4, ObsidianCity_Movement_Rocket4Second
# 177 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 178 "data/maps/ObsidianCity/scripts.pory"
	applymovement 6, Common_Movement_FaceUp
# 179 "data/maps/ObsidianCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, ObsidianCity_Movement_PlayerLookRocketMid
# 180 "data/maps/ObsidianCity/scripts.pory"
	applymovement 1, ObsidianCity_Movement_Rocket1Third
# 181 "data/maps/ObsidianCity/scripts.pory"
	applymovement 2, ObsidianCity_Movement_Rocket2Third
# 182 "data/maps/ObsidianCity/scripts.pory"
	applymovement 3, ObsidianCity_Movement_Rocket3Third
# 183 "data/maps/ObsidianCity/scripts.pory"
	applymovement 4, ObsidianCity_Movement_Rocket4Third
# 184 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 185 "data/maps/ObsidianCity/scripts.pory"
	delay 30
# 186 "data/maps/ObsidianCity/scripts.pory"
	msgbox ObsidianCity_Text_RightThing
# 187 "data/maps/ObsidianCity/scripts.pory"
	closemessage
# 188 "data/maps/ObsidianCity/scripts.pory"
	applymovement 4, ObsidianCity_Movement_Rocket4Fourth
# 189 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 190 "data/maps/ObsidianCity/scripts.pory"
	delay 30
# 191 "data/maps/ObsidianCity/scripts.pory"
	removeobject 1
# 192 "data/maps/ObsidianCity/scripts.pory"
	removeobject 2
# 193 "data/maps/ObsidianCity/scripts.pory"
	removeobject 3
# 194 "data/maps/ObsidianCity/scripts.pory"
	removeobject 4
# 195 "data/maps/ObsidianCity/scripts.pory"
	removeobject 5
# 196 "data/maps/ObsidianCity/scripts.pory"
	applymovement 6, ObsidianCity_Movement_GioToPlayerLeftMid
# 197 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 198 "data/maps/ObsidianCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 199 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 200 "data/maps/ObsidianCity/scripts.pory"
	msgbox ObsidianCity_Text_SeeThat
# 201 "data/maps/ObsidianCity/scripts.pory"
	closemessage
# 202 "data/maps/ObsidianCity/scripts.pory"
	applymovement 6, ObsidianCity_Movement_GioToRuinsLeftMid
# 203 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 204 "data/maps/ObsidianCity/scripts.pory"
	removeobject 6
# 205 "data/maps/ObsidianCity/scripts.pory"
	setvar VAR_MAP_SCENE_OBSIDIAN_CITY_EVENTS, 2
# 206 "data/maps/ObsidianCity/scripts.pory"
	releaseall
	end


ObsidianCity_EventScript_TriggerRight::
# 211 "data/maps/ObsidianCity/scripts.pory"
	lockall
# 212 "data/maps/ObsidianCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 213 "data/maps/ObsidianCity/scripts.pory"
	msgbox ObsidianCity_Text_OuttaTheWay
# 214 "data/maps/ObsidianCity/scripts.pory"
	closemessage
# 215 "data/maps/ObsidianCity/scripts.pory"
	delay 60
# 216 "data/maps/ObsidianCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 217 "data/maps/ObsidianCity/scripts.pory"
	applymovement 1, ObsidianCity_Movement_Rocket1First
# 218 "data/maps/ObsidianCity/scripts.pory"
	applymovement 2, ObsidianCity_Movement_Rocket2First
# 219 "data/maps/ObsidianCity/scripts.pory"
	applymovement 3, ObsidianCity_Movement_Rocket3First
# 220 "data/maps/ObsidianCity/scripts.pory"
	applymovement 4, ObsidianCity_Movement_Rocket4First
# 221 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 222 "data/maps/ObsidianCity/scripts.pory"
	applymovement 6, ObsidianCity_Movement_GioOuttaWay
# 223 "data/maps/ObsidianCity/scripts.pory"
	applymovement 1, ObsidianCity_Movement_Rocket1Second
# 224 "data/maps/ObsidianCity/scripts.pory"
	applymovement 2, ObsidianCity_Movement_Rocket2Second
# 225 "data/maps/ObsidianCity/scripts.pory"
	applymovement 3, ObsidianCity_Movement_Rocket3Second
# 226 "data/maps/ObsidianCity/scripts.pory"
	applymovement 4, ObsidianCity_Movement_Rocket4Second
# 227 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 228 "data/maps/ObsidianCity/scripts.pory"
	applymovement 6, Common_Movement_FaceUp
# 229 "data/maps/ObsidianCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, ObsidianCity_Movement_PlayerLookRocketRight
# 230 "data/maps/ObsidianCity/scripts.pory"
	applymovement 1, ObsidianCity_Movement_Rocket1Third
# 231 "data/maps/ObsidianCity/scripts.pory"
	applymovement 2, ObsidianCity_Movement_Rocket2Third
# 232 "data/maps/ObsidianCity/scripts.pory"
	applymovement 3, ObsidianCity_Movement_Rocket3Third
# 233 "data/maps/ObsidianCity/scripts.pory"
	applymovement 4, ObsidianCity_Movement_Rocket4Third
# 234 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 235 "data/maps/ObsidianCity/scripts.pory"
	delay 30
# 236 "data/maps/ObsidianCity/scripts.pory"
	msgbox ObsidianCity_Text_RightThing
# 237 "data/maps/ObsidianCity/scripts.pory"
	closemessage
# 238 "data/maps/ObsidianCity/scripts.pory"
	applymovement 4, ObsidianCity_Movement_Rocket4Fourth
# 239 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 240 "data/maps/ObsidianCity/scripts.pory"
	delay 30
# 241 "data/maps/ObsidianCity/scripts.pory"
	removeobject 1
# 242 "data/maps/ObsidianCity/scripts.pory"
	removeobject 2
# 243 "data/maps/ObsidianCity/scripts.pory"
	removeobject 3
# 244 "data/maps/ObsidianCity/scripts.pory"
	removeobject 4
# 245 "data/maps/ObsidianCity/scripts.pory"
	removeobject 5
# 246 "data/maps/ObsidianCity/scripts.pory"
	applymovement 6, ObsidianCity_Movement_GioToPlayerRight
# 247 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 248 "data/maps/ObsidianCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 249 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 250 "data/maps/ObsidianCity/scripts.pory"
	msgbox ObsidianCity_Text_SeeThat
# 251 "data/maps/ObsidianCity/scripts.pory"
	closemessage
# 252 "data/maps/ObsidianCity/scripts.pory"
	applymovement 6, ObsidianCity_Movement_GioToRuinsRight
# 253 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 254 "data/maps/ObsidianCity/scripts.pory"
	removeobject 6
# 255 "data/maps/ObsidianCity/scripts.pory"
	clearflag FLAG_HIDE_GIO_RUINS
# 256 "data/maps/ObsidianCity/scripts.pory"
	setflag FLAG_HIDE_GIO_GYM
# 257 "data/maps/ObsidianCity/scripts.pory"
	setvar VAR_MAP_SCENE_OBSIDIAN_CITY_EVENTS, 2
# 258 "data/maps/ObsidianCity/scripts.pory"
	releaseall
	end


# 274 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_Rocket1First:
	step_end

# 281 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_Rocket2First:
	step_end

# 287 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_Rocket3First:
	step_end

# 292 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_Rocket4First:
	step_end

# 297 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_GioOuttaWay:
# 298 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 299 "data/maps/ObsidianCity/scripts.pory"
	face_down
# 300 "data/maps/ObsidianCity/scripts.pory"
	delay_1
# 301 "data/maps/ObsidianCity/scripts.pory"
	face_right
	step_end

# 304 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_Rocket1Second:
# 305 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 306 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_right
# 307 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 308 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_right
# 309 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 309 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 309 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
	step_end

# 312 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_Rocket2Second:
# 313 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 313 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 314 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_right
# 315 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 316 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_right
# 317 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 317 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
	step_end

# 320 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_Rocket3Second:
# 321 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 321 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 321 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 322 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_right
# 323 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 324 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_right
# 325 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
	step_end

# 328 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_Rocket4Second:
# 329 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 329 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 329 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 329 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 330 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_right
# 331 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 332 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_right
	step_end

# 335 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_Rocket1Third:
# 336 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 336 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 336 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 336 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 336 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 336 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 337 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_left
# 338 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 339 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_left
# 339 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_left
	step_end

# 342 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_Rocket2Third:
# 343 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 343 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 343 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 343 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 343 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 343 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 343 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 344 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_left
# 345 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 346 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_left
	step_end

# 349 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_Rocket3Third:
# 350 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 350 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 350 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 350 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 350 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 350 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 350 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 350 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 351 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_left
# 352 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
	step_end

# 355 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_Rocket4Third:
# 356 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 356 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 357 "data/maps/ObsidianCity/scripts.pory"
	walk_up
# 357 "data/maps/ObsidianCity/scripts.pory"
	walk_up
# 358 "data/maps/ObsidianCity/scripts.pory"
	walk_slow_up
# 358 "data/maps/ObsidianCity/scripts.pory"
	walk_slow_up
# 359 "data/maps/ObsidianCity/scripts.pory"
	face_up
# 360 "data/maps/ObsidianCity/scripts.pory"
	delay_16
# 361 "data/maps/ObsidianCity/scripts.pory"
	face_left
# 362 "data/maps/ObsidianCity/scripts.pory"
	delay_16
# 363 "data/maps/ObsidianCity/scripts.pory"
	face_right
# 364 "data/maps/ObsidianCity/scripts.pory"
	delay_16
# 365 "data/maps/ObsidianCity/scripts.pory"
	delay_16
# 366 "data/maps/ObsidianCity/scripts.pory"
	face_up
	step_end

# 369 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_Rocket4Fourth:
# 370 "data/maps/ObsidianCity/scripts.pory"
	walk_up
# 370 "data/maps/ObsidianCity/scripts.pory"
	walk_up
# 370 "data/maps/ObsidianCity/scripts.pory"
	walk_up
# 371 "data/maps/ObsidianCity/scripts.pory"
	walk_left
# 372 "data/maps/ObsidianCity/scripts.pory"
	walk_up
	step_end

# 375 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_PlayerLookRocketLeft:
# 376 "data/maps/ObsidianCity/scripts.pory"
	walk_in_place_right
# 377 "data/maps/ObsidianCity/scripts.pory"
	walk_in_place_up
	step_end

# 380 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_PlayerLookRocketMid:
# 381 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_left
# 382 "data/maps/ObsidianCity/scripts.pory"
	walk_in_place_fast_right
# 383 "data/maps/ObsidianCity/scripts.pory"
	walk_in_place_up
	step_end

# 386 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_PlayerLookRocketRight:
# 387 "data/maps/ObsidianCity/scripts.pory"
	walk_in_place_left
# 388 "data/maps/ObsidianCity/scripts.pory"
	walk_in_place_up
	step_end

# 391 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_GioToPlayerLeftMid:
# 392 "data/maps/ObsidianCity/scripts.pory"
	walk_right
# 393 "data/maps/ObsidianCity/scripts.pory"
	walk_up
# 393 "data/maps/ObsidianCity/scripts.pory"
	walk_up
# 393 "data/maps/ObsidianCity/scripts.pory"
	walk_up
	step_end

# 396 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_GioToPlayerRight:
# 397 "data/maps/ObsidianCity/scripts.pory"
	walk_right
# 397 "data/maps/ObsidianCity/scripts.pory"
	walk_right
# 397 "data/maps/ObsidianCity/scripts.pory"
	walk_right
# 398 "data/maps/ObsidianCity/scripts.pory"
	walk_up
# 398 "data/maps/ObsidianCity/scripts.pory"
	walk_up
# 398 "data/maps/ObsidianCity/scripts.pory"
	walk_up
	step_end

# 401 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_GioToRuinsLeftMid:
# 402 "data/maps/ObsidianCity/scripts.pory"
	walk_down
# 402 "data/maps/ObsidianCity/scripts.pory"
	walk_down
# 402 "data/maps/ObsidianCity/scripts.pory"
	walk_down
# 402 "data/maps/ObsidianCity/scripts.pory"
	walk_down
# 403 "data/maps/ObsidianCity/scripts.pory"
	walk_left
# 403 "data/maps/ObsidianCity/scripts.pory"
	walk_left
# 404 "data/maps/ObsidianCity/scripts.pory"
	walk_down
# 404 "data/maps/ObsidianCity/scripts.pory"
	walk_down
# 404 "data/maps/ObsidianCity/scripts.pory"
	walk_down
	step_end

# 407 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_GioToRuinsRight:
# 408 "data/maps/ObsidianCity/scripts.pory"
	walk_down
# 408 "data/maps/ObsidianCity/scripts.pory"
	walk_down
# 408 "data/maps/ObsidianCity/scripts.pory"
	walk_down
# 408 "data/maps/ObsidianCity/scripts.pory"
	walk_down
# 409 "data/maps/ObsidianCity/scripts.pory"
	walk_left
# 409 "data/maps/ObsidianCity/scripts.pory"
	walk_left
# 409 "data/maps/ObsidianCity/scripts.pory"
	walk_left
# 409 "data/maps/ObsidianCity/scripts.pory"
	walk_left
# 410 "data/maps/ObsidianCity/scripts.pory"
	walk_down
# 410 "data/maps/ObsidianCity/scripts.pory"
	walk_down
# 410 "data/maps/ObsidianCity/scripts.pory"
	walk_down
	step_end

ObsidianCity_Text_WhatInTarnation::
# 94 "data/maps/ObsidianCity/scripts.pory"
	.string "GEOFFREY: What in tarnation was that?$"

ObsidianCity_Text_YouHeardToo::
# 98 "data/maps/ObsidianCity/scripts.pory"
	.string "Didja hear that too, kid?\nYou musta heard it!$"

ObsidianCity_Text_IGo::
# 102 "data/maps/ObsidianCity/scripts.pory"
	.string "GEOFFREY: Gosh dangit!\nSomethin's def'nitely up!\pI'll bet it's at that place!\nThe RUINS OF OMEG!$"

ObsidianCity_Text_OuttaTheWay::
# 262 "data/maps/ObsidianCity/scripts.pory"
	.string "???: Get out of the way!$"

ObsidianCity_Text_RightThing::
# 266 "data/maps/ObsidianCity/scripts.pory"
	.string "???: Killing all those UNOWN...\nWas that really the right thing?$"

ObsidianCity_Text_SeeThat::
# 270 "data/maps/ObsidianCity/scripts.pory"
	.string "GEOFFREY: Yeowch!\nThose people were so dang fast!\pI didn't quite catch what that\nlast person said.\pBut they musta been behind that\nquake earlier!\p...\pOh gosh! I should hurry to the\nRUINS!$"
