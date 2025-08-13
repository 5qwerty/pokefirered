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
	clearflag FLAG_HIDE_GIO_RUINS
# 158 "data/maps/ObsidianCity/scripts.pory"
	releaseall
	end


ObsidianCity_EventScript_TriggerMid::
# 163 "data/maps/ObsidianCity/scripts.pory"
	lockall
# 164 "data/maps/ObsidianCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 165 "data/maps/ObsidianCity/scripts.pory"
	msgbox ObsidianCity_Text_OuttaTheWay
# 166 "data/maps/ObsidianCity/scripts.pory"
	closemessage
# 167 "data/maps/ObsidianCity/scripts.pory"
	delay 60
# 168 "data/maps/ObsidianCity/scripts.pory"
	applymovement 1, ObsidianCity_Movement_Rocket1First
# 169 "data/maps/ObsidianCity/scripts.pory"
	applymovement 2, ObsidianCity_Movement_Rocket2First
# 170 "data/maps/ObsidianCity/scripts.pory"
	applymovement 3, ObsidianCity_Movement_Rocket3First
# 171 "data/maps/ObsidianCity/scripts.pory"
	applymovement 4, ObsidianCity_Movement_Rocket4First
# 172 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 173 "data/maps/ObsidianCity/scripts.pory"
	applymovement 6, ObsidianCity_Movement_GioOuttaWay
# 174 "data/maps/ObsidianCity/scripts.pory"
	applymovement 1, ObsidianCity_Movement_Rocket1Second
# 175 "data/maps/ObsidianCity/scripts.pory"
	applymovement 2, ObsidianCity_Movement_Rocket2Second
# 176 "data/maps/ObsidianCity/scripts.pory"
	applymovement 3, ObsidianCity_Movement_Rocket3Second
# 177 "data/maps/ObsidianCity/scripts.pory"
	applymovement 4, ObsidianCity_Movement_Rocket4Second
# 178 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 179 "data/maps/ObsidianCity/scripts.pory"
	applymovement 6, Common_Movement_FaceUp
# 180 "data/maps/ObsidianCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, ObsidianCity_Movement_PlayerLookRocketMid
# 181 "data/maps/ObsidianCity/scripts.pory"
	applymovement 1, ObsidianCity_Movement_Rocket1Third
# 182 "data/maps/ObsidianCity/scripts.pory"
	applymovement 2, ObsidianCity_Movement_Rocket2Third
# 183 "data/maps/ObsidianCity/scripts.pory"
	applymovement 3, ObsidianCity_Movement_Rocket3Third
# 184 "data/maps/ObsidianCity/scripts.pory"
	applymovement 4, ObsidianCity_Movement_Rocket4Third
# 185 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 186 "data/maps/ObsidianCity/scripts.pory"
	delay 30
# 187 "data/maps/ObsidianCity/scripts.pory"
	msgbox ObsidianCity_Text_RightThing
# 188 "data/maps/ObsidianCity/scripts.pory"
	closemessage
# 189 "data/maps/ObsidianCity/scripts.pory"
	applymovement 4, ObsidianCity_Movement_Rocket4Fourth
# 190 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 191 "data/maps/ObsidianCity/scripts.pory"
	delay 30
# 192 "data/maps/ObsidianCity/scripts.pory"
	removeobject 1
# 193 "data/maps/ObsidianCity/scripts.pory"
	removeobject 2
# 194 "data/maps/ObsidianCity/scripts.pory"
	removeobject 3
# 195 "data/maps/ObsidianCity/scripts.pory"
	removeobject 4
# 196 "data/maps/ObsidianCity/scripts.pory"
	removeobject 5
# 197 "data/maps/ObsidianCity/scripts.pory"
	applymovement 6, ObsidianCity_Movement_GioToPlayerLeftMid
# 198 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 199 "data/maps/ObsidianCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 200 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 201 "data/maps/ObsidianCity/scripts.pory"
	msgbox ObsidianCity_Text_SeeThat
# 202 "data/maps/ObsidianCity/scripts.pory"
	closemessage
# 203 "data/maps/ObsidianCity/scripts.pory"
	applymovement 6, ObsidianCity_Movement_GioToRuinsLeftMid
# 204 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 205 "data/maps/ObsidianCity/scripts.pory"
	removeobject 6
# 206 "data/maps/ObsidianCity/scripts.pory"
	setvar VAR_MAP_SCENE_OBSIDIAN_CITY_EVENTS, 2
# 207 "data/maps/ObsidianCity/scripts.pory"
	clearflag FLAG_HIDE_GIO_RUINS
# 208 "data/maps/ObsidianCity/scripts.pory"
	releaseall
	end


ObsidianCity_EventScript_TriggerRight::
# 213 "data/maps/ObsidianCity/scripts.pory"
	lockall
# 214 "data/maps/ObsidianCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 215 "data/maps/ObsidianCity/scripts.pory"
	msgbox ObsidianCity_Text_OuttaTheWay
# 216 "data/maps/ObsidianCity/scripts.pory"
	closemessage
# 217 "data/maps/ObsidianCity/scripts.pory"
	delay 60
# 218 "data/maps/ObsidianCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 219 "data/maps/ObsidianCity/scripts.pory"
	applymovement 1, ObsidianCity_Movement_Rocket1First
# 220 "data/maps/ObsidianCity/scripts.pory"
	applymovement 2, ObsidianCity_Movement_Rocket2First
# 221 "data/maps/ObsidianCity/scripts.pory"
	applymovement 3, ObsidianCity_Movement_Rocket3First
# 222 "data/maps/ObsidianCity/scripts.pory"
	applymovement 4, ObsidianCity_Movement_Rocket4First
# 223 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 224 "data/maps/ObsidianCity/scripts.pory"
	applymovement 6, ObsidianCity_Movement_GioOuttaWay
# 225 "data/maps/ObsidianCity/scripts.pory"
	applymovement 1, ObsidianCity_Movement_Rocket1Second
# 226 "data/maps/ObsidianCity/scripts.pory"
	applymovement 2, ObsidianCity_Movement_Rocket2Second
# 227 "data/maps/ObsidianCity/scripts.pory"
	applymovement 3, ObsidianCity_Movement_Rocket3Second
# 228 "data/maps/ObsidianCity/scripts.pory"
	applymovement 4, ObsidianCity_Movement_Rocket4Second
# 229 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 230 "data/maps/ObsidianCity/scripts.pory"
	applymovement 6, Common_Movement_FaceUp
# 231 "data/maps/ObsidianCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, ObsidianCity_Movement_PlayerLookRocketRight
# 232 "data/maps/ObsidianCity/scripts.pory"
	applymovement 1, ObsidianCity_Movement_Rocket1Third
# 233 "data/maps/ObsidianCity/scripts.pory"
	applymovement 2, ObsidianCity_Movement_Rocket2Third
# 234 "data/maps/ObsidianCity/scripts.pory"
	applymovement 3, ObsidianCity_Movement_Rocket3Third
# 235 "data/maps/ObsidianCity/scripts.pory"
	applymovement 4, ObsidianCity_Movement_Rocket4Third
# 236 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 237 "data/maps/ObsidianCity/scripts.pory"
	delay 30
# 238 "data/maps/ObsidianCity/scripts.pory"
	msgbox ObsidianCity_Text_RightThing
# 239 "data/maps/ObsidianCity/scripts.pory"
	closemessage
# 240 "data/maps/ObsidianCity/scripts.pory"
	applymovement 4, ObsidianCity_Movement_Rocket4Fourth
# 241 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 242 "data/maps/ObsidianCity/scripts.pory"
	delay 30
# 243 "data/maps/ObsidianCity/scripts.pory"
	removeobject 1
# 244 "data/maps/ObsidianCity/scripts.pory"
	removeobject 2
# 245 "data/maps/ObsidianCity/scripts.pory"
	removeobject 3
# 246 "data/maps/ObsidianCity/scripts.pory"
	removeobject 4
# 247 "data/maps/ObsidianCity/scripts.pory"
	removeobject 5
# 248 "data/maps/ObsidianCity/scripts.pory"
	applymovement 6, ObsidianCity_Movement_GioToPlayerRight
# 249 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 250 "data/maps/ObsidianCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 251 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 252 "data/maps/ObsidianCity/scripts.pory"
	msgbox ObsidianCity_Text_SeeThat
# 253 "data/maps/ObsidianCity/scripts.pory"
	closemessage
# 254 "data/maps/ObsidianCity/scripts.pory"
	applymovement 6, ObsidianCity_Movement_GioToRuinsRight
# 255 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 256 "data/maps/ObsidianCity/scripts.pory"
	removeobject 6
# 257 "data/maps/ObsidianCity/scripts.pory"
	clearflag FLAG_HIDE_GIO_RUINS
# 258 "data/maps/ObsidianCity/scripts.pory"
	setflag FLAG_HIDE_GIO_GYM
# 259 "data/maps/ObsidianCity/scripts.pory"
	setvar VAR_MAP_SCENE_OBSIDIAN_CITY_EVENTS, 2
# 260 "data/maps/ObsidianCity/scripts.pory"
	clearflag FLAG_HIDE_GIO_RUINS
# 261 "data/maps/ObsidianCity/scripts.pory"
	releaseall
	end


# 277 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_Rocket1First:
	step_end

# 284 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_Rocket2First:
	step_end

# 290 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_Rocket3First:
	step_end

# 295 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_Rocket4First:
	step_end

# 300 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_GioOuttaWay:
# 301 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 302 "data/maps/ObsidianCity/scripts.pory"
	face_down
# 303 "data/maps/ObsidianCity/scripts.pory"
	delay_1
# 304 "data/maps/ObsidianCity/scripts.pory"
	face_right
	step_end

# 307 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_Rocket1Second:
# 308 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 309 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_right
# 310 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 311 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_right
# 312 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 312 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 312 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
	step_end

# 315 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_Rocket2Second:
# 316 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 316 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 317 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_right
# 318 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 319 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_right
# 320 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 320 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
	step_end

# 323 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_Rocket3Second:
# 324 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 324 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 324 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 325 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_right
# 326 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 327 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_right
# 328 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
	step_end

# 331 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_Rocket4Second:
# 332 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 332 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 332 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 332 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 333 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_right
# 334 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 335 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_right
	step_end

# 338 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_Rocket1Third:
# 339 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 339 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 339 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 339 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 339 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 339 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 340 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_left
# 341 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 342 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_left
# 342 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_left
	step_end

# 345 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_Rocket2Third:
# 346 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 346 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 346 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 346 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 346 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 346 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 346 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 347 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_left
# 348 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 349 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_left
	step_end

# 352 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_Rocket3Third:
# 353 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 353 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 353 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 353 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 353 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 353 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 353 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 353 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 354 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_left
# 355 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
	step_end

# 358 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_Rocket4Third:
# 359 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 359 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 360 "data/maps/ObsidianCity/scripts.pory"
	walk_up
# 360 "data/maps/ObsidianCity/scripts.pory"
	walk_up
# 361 "data/maps/ObsidianCity/scripts.pory"
	walk_slow_up
# 361 "data/maps/ObsidianCity/scripts.pory"
	walk_slow_up
# 362 "data/maps/ObsidianCity/scripts.pory"
	face_up
# 363 "data/maps/ObsidianCity/scripts.pory"
	delay_16
# 364 "data/maps/ObsidianCity/scripts.pory"
	face_left
# 365 "data/maps/ObsidianCity/scripts.pory"
	delay_16
# 366 "data/maps/ObsidianCity/scripts.pory"
	face_right
# 367 "data/maps/ObsidianCity/scripts.pory"
	delay_16
# 368 "data/maps/ObsidianCity/scripts.pory"
	delay_16
# 369 "data/maps/ObsidianCity/scripts.pory"
	face_up
	step_end

# 372 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_Rocket4Fourth:
# 373 "data/maps/ObsidianCity/scripts.pory"
	walk_up
# 373 "data/maps/ObsidianCity/scripts.pory"
	walk_up
# 373 "data/maps/ObsidianCity/scripts.pory"
	walk_up
# 374 "data/maps/ObsidianCity/scripts.pory"
	walk_left
# 375 "data/maps/ObsidianCity/scripts.pory"
	walk_up
	step_end

# 378 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_PlayerLookRocketLeft:
# 379 "data/maps/ObsidianCity/scripts.pory"
	walk_in_place_right
# 380 "data/maps/ObsidianCity/scripts.pory"
	walk_in_place_up
	step_end

# 383 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_PlayerLookRocketMid:
# 384 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_left
# 385 "data/maps/ObsidianCity/scripts.pory"
	walk_in_place_fast_right
# 386 "data/maps/ObsidianCity/scripts.pory"
	walk_in_place_up
	step_end

# 389 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_PlayerLookRocketRight:
# 390 "data/maps/ObsidianCity/scripts.pory"
	walk_in_place_left
# 391 "data/maps/ObsidianCity/scripts.pory"
	walk_in_place_up
	step_end

# 394 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_GioToPlayerLeftMid:
# 395 "data/maps/ObsidianCity/scripts.pory"
	walk_right
# 396 "data/maps/ObsidianCity/scripts.pory"
	walk_up
# 396 "data/maps/ObsidianCity/scripts.pory"
	walk_up
# 396 "data/maps/ObsidianCity/scripts.pory"
	walk_up
	step_end

# 399 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_GioToPlayerRight:
# 400 "data/maps/ObsidianCity/scripts.pory"
	walk_right
# 400 "data/maps/ObsidianCity/scripts.pory"
	walk_right
# 400 "data/maps/ObsidianCity/scripts.pory"
	walk_right
# 401 "data/maps/ObsidianCity/scripts.pory"
	walk_up
# 401 "data/maps/ObsidianCity/scripts.pory"
	walk_up
# 401 "data/maps/ObsidianCity/scripts.pory"
	walk_up
	step_end

# 404 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_GioToRuinsLeftMid:
# 405 "data/maps/ObsidianCity/scripts.pory"
	walk_down
# 405 "data/maps/ObsidianCity/scripts.pory"
	walk_down
# 405 "data/maps/ObsidianCity/scripts.pory"
	walk_down
# 405 "data/maps/ObsidianCity/scripts.pory"
	walk_down
# 406 "data/maps/ObsidianCity/scripts.pory"
	walk_left
# 406 "data/maps/ObsidianCity/scripts.pory"
	walk_left
# 407 "data/maps/ObsidianCity/scripts.pory"
	walk_down
# 407 "data/maps/ObsidianCity/scripts.pory"
	walk_down
# 407 "data/maps/ObsidianCity/scripts.pory"
	walk_down
	step_end

# 410 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_GioToRuinsRight:
# 411 "data/maps/ObsidianCity/scripts.pory"
	walk_down
# 411 "data/maps/ObsidianCity/scripts.pory"
	walk_down
# 411 "data/maps/ObsidianCity/scripts.pory"
	walk_down
# 411 "data/maps/ObsidianCity/scripts.pory"
	walk_down
# 412 "data/maps/ObsidianCity/scripts.pory"
	walk_left
# 412 "data/maps/ObsidianCity/scripts.pory"
	walk_left
# 412 "data/maps/ObsidianCity/scripts.pory"
	walk_left
# 412 "data/maps/ObsidianCity/scripts.pory"
	walk_left
# 413 "data/maps/ObsidianCity/scripts.pory"
	walk_down
# 413 "data/maps/ObsidianCity/scripts.pory"
	walk_down
# 413 "data/maps/ObsidianCity/scripts.pory"
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
# 265 "data/maps/ObsidianCity/scripts.pory"
	.string "???: Get out of the way!$"

ObsidianCity_Text_RightThing::
# 269 "data/maps/ObsidianCity/scripts.pory"
	.string "???: Killing all those UNOWN...\nWas that really the right thing to\ldo?$"

ObsidianCity_Text_SeeThat::
# 273 "data/maps/ObsidianCity/scripts.pory"
	.string "GEOFFREY: Yeowch!\nThose people were so dang fast!\pI didn't quite catch what that\nlast person said.\pBut they musta been behind that\nquake earlier!\p...\pOh gosh! I should hurry to the\nRUINS!$"
