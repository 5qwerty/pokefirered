ObsidianCity_MapScripts::
# 9 "data/maps/ObsidianCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, ObsidianCity_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 13 "data/maps/ObsidianCity/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, ObsidianCity_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

ObsidianCity_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 10 "data/maps/ObsidianCity/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_OBSIDIAN_CITY
# 11 "data/maps/ObsidianCity/scripts.pory"
	call_if_eq VAR_MAP_SCENE_OBSIDIAN_CITY_EVENTS, 1, ObsidianCity_EventScript_MoveGio
	return

ObsidianCity_MapScripts_MAP_SCRIPT_ON_LOAD:
# 14 "data/maps/ObsidianCity/scripts.pory"
	call_if_ge VAR_MAP_SCENE_OBSIDIAN_CITY_EVENTS, 1, ObsidianCity_EventScript_OpenHole
	return


ObsidianCity_EventScript_OpenHole::
# 19 "data/maps/ObsidianCity/scripts.pory"
	setmetatile 17, 28, 0x0A9, 0
	return


ObsidianCity_EventScript_MoveGio::
# 23 "data/maps/ObsidianCity/scripts.pory"
	setobjectxyperm 6, 21, 22
# 24 "data/maps/ObsidianCity/scripts.pory"
	setobjectmovementtype 6, MOVEMENT_TYPE_FACE_DOWN
# 25 "data/maps/ObsidianCity/scripts.pory"
	setobjectxyperm 1, 21, 23
# 26 "data/maps/ObsidianCity/scripts.pory"
	setobjectxyperm 2, 21, 24
# 27 "data/maps/ObsidianCity/scripts.pory"
	setobjectxyperm 3, 21, 25
# 28 "data/maps/ObsidianCity/scripts.pory"
	setobjectxyperm 4, 21, 26
	return


ObsidianCity_EventScript_GymTrigger::
# 32 "data/maps/ObsidianCity/scripts.pory"
	lockall
# 33 "data/maps/ObsidianCity/scripts.pory"
	playse SE_PIN
# 34 "data/maps/ObsidianCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamDown
# 35 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 36 "data/maps/ObsidianCity/scripts.pory"
	setvar 0x8004, 2
# 37 "data/maps/ObsidianCity/scripts.pory"
	setvar 0x8005, 2
# 38 "data/maps/ObsidianCity/scripts.pory"
	setvar 0x8006, 20
# 39 "data/maps/ObsidianCity/scripts.pory"
	setvar 0x8007, 4
# 40 "data/maps/ObsidianCity/scripts.pory"
	special ShakeScreen
# 41 "data/maps/ObsidianCity/scripts.pory"
	delay 80
# 42 "data/maps/ObsidianCity/scripts.pory"
	opendoor 6, 5
# 43 "data/maps/ObsidianCity/scripts.pory"
	waitdooranim
# 44 "data/maps/ObsidianCity/scripts.pory"
	addobject 6
# 45 "data/maps/ObsidianCity/scripts.pory"
	clearflag FLAG_HIDE_GIO_OBSIDIAN
# 46 "data/maps/ObsidianCity/scripts.pory"
	applymovement 6, Common_Movement_WalkDown
# 47 "data/maps/ObsidianCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
# 48 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 49 "data/maps/ObsidianCity/scripts.pory"
	closedoor 6, 5
# 50 "data/maps/ObsidianCity/scripts.pory"
	waitdooranim
# 51 "data/maps/ObsidianCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 52 "data/maps/ObsidianCity/scripts.pory"
	msgbox ObsidianCity_Text_WhatInTarnation
# 53 "data/maps/ObsidianCity/scripts.pory"
	closemessage
# 54 "data/maps/ObsidianCity/scripts.pory"
	delay 30
# 55 "data/maps/ObsidianCity/scripts.pory"
	applymovement 6, Common_Movement_FaceLeft
# 56 "data/maps/ObsidianCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 57 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 58 "data/maps/ObsidianCity/scripts.pory"
	msgbox ObsidianCity_Text_YouHeardToo
# 59 "data/maps/ObsidianCity/scripts.pory"
	closemessage
# 60 "data/maps/ObsidianCity/scripts.pory"
	playse SE_PIN
# 61 "data/maps/ObsidianCity/scripts.pory"
	applymovement 6, Common_Movement_ExclamDown
# 62 "data/maps/ObsidianCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamDown
# 63 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 64 "data/maps/ObsidianCity/scripts.pory"
	setvar 0x8004, 3
# 65 "data/maps/ObsidianCity/scripts.pory"
	setvar 0x8005, 3
# 66 "data/maps/ObsidianCity/scripts.pory"
	setvar 0x8006, 30
# 67 "data/maps/ObsidianCity/scripts.pory"
	setvar 0x8007, 4
# 68 "data/maps/ObsidianCity/scripts.pory"
	special ShakeScreen
# 69 "data/maps/ObsidianCity/scripts.pory"
	delay 120
# 70 "data/maps/ObsidianCity/scripts.pory"
	msgbox ObsidianCity_Text_IGo
# 71 "data/maps/ObsidianCity/scripts.pory"
	closemessage
# 72 "data/maps/ObsidianCity/scripts.pory"
	applymovement 6, ObsidianCity_Movement_Leave
# 73 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 74 "data/maps/ObsidianCity/scripts.pory"
	removeobject 6
# 75 "data/maps/ObsidianCity/scripts.pory"
	setvar VAR_MAP_SCENE_OBSIDIAN_CITY_EVENTS, 1
# 76 "data/maps/ObsidianCity/scripts.pory"
	setobjectxyperm 6, 21, 22
# 77 "data/maps/ObsidianCity/scripts.pory"
	setobjectmovementtype 6, MOVEMENT_TYPE_FACE_DOWN
# 78 "data/maps/ObsidianCity/scripts.pory"
	setmetatile 17, 28, 0x0A9, 0
# 79 "data/maps/ObsidianCity/scripts.pory"
	addobject 6
# 80 "data/maps/ObsidianCity/scripts.pory"
	clearflag FLAG_HIDE_GIO_OBSIDIAN
# 81 "data/maps/ObsidianCity/scripts.pory"
	setobjectxyperm 1, 21, 23
# 82 "data/maps/ObsidianCity/scripts.pory"
	setobjectxyperm 2, 21, 24
# 83 "data/maps/ObsidianCity/scripts.pory"
	setobjectxyperm 3, 21, 25
# 84 "data/maps/ObsidianCity/scripts.pory"
	setobjectxyperm 4, 21, 26
# 85 "data/maps/ObsidianCity/scripts.pory"
	releaseall
	end


# 101 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_Leave:
# 102 "data/maps/ObsidianCity/scripts.pory"
	walk_right
# 102 "data/maps/ObsidianCity/scripts.pory"
	walk_right
# 102 "data/maps/ObsidianCity/scripts.pory"
	walk_right
# 102 "data/maps/ObsidianCity/scripts.pory"
	walk_right
# 103 "data/maps/ObsidianCity/scripts.pory"
	walk_down
# 104 "data/maps/ObsidianCity/scripts.pory"
	walk_right
# 104 "data/maps/ObsidianCity/scripts.pory"
	walk_right
# 104 "data/maps/ObsidianCity/scripts.pory"
	walk_right
# 104 "data/maps/ObsidianCity/scripts.pory"
	walk_right
# 104 "data/maps/ObsidianCity/scripts.pory"
	walk_right
	step_end

ObsidianCity_EventScript_TriggerLeft::
# 108 "data/maps/ObsidianCity/scripts.pory"
	lockall
# 109 "data/maps/ObsidianCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 110 "data/maps/ObsidianCity/scripts.pory"
	msgbox ObsidianCity_Text_OuttaTheWay
# 111 "data/maps/ObsidianCity/scripts.pory"
	closemessage
# 112 "data/maps/ObsidianCity/scripts.pory"
	delay 60
# 113 "data/maps/ObsidianCity/scripts.pory"
	applymovement 1, ObsidianCity_Movement_Rocket1First
# 114 "data/maps/ObsidianCity/scripts.pory"
	applymovement 2, ObsidianCity_Movement_Rocket2First
# 115 "data/maps/ObsidianCity/scripts.pory"
	applymovement 3, ObsidianCity_Movement_Rocket3First
# 116 "data/maps/ObsidianCity/scripts.pory"
	applymovement 4, ObsidianCity_Movement_Rocket4First
# 117 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 118 "data/maps/ObsidianCity/scripts.pory"
	applymovement 6, ObsidianCity_Movement_GioOuttaWay
# 119 "data/maps/ObsidianCity/scripts.pory"
	applymovement 1, ObsidianCity_Movement_Rocket1Second
# 120 "data/maps/ObsidianCity/scripts.pory"
	applymovement 2, ObsidianCity_Movement_Rocket2Second
# 121 "data/maps/ObsidianCity/scripts.pory"
	applymovement 3, ObsidianCity_Movement_Rocket3Second
# 122 "data/maps/ObsidianCity/scripts.pory"
	applymovement 4, ObsidianCity_Movement_Rocket4Second
# 123 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 124 "data/maps/ObsidianCity/scripts.pory"
	applymovement 6, Common_Movement_FaceUp
# 125 "data/maps/ObsidianCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, ObsidianCity_Movement_PlayerLookRocketLeft
# 126 "data/maps/ObsidianCity/scripts.pory"
	applymovement 1, ObsidianCity_Movement_Rocket1Third
# 127 "data/maps/ObsidianCity/scripts.pory"
	applymovement 2, ObsidianCity_Movement_Rocket2Third
# 128 "data/maps/ObsidianCity/scripts.pory"
	applymovement 3, ObsidianCity_Movement_Rocket3Third
# 129 "data/maps/ObsidianCity/scripts.pory"
	applymovement 4, ObsidianCity_Movement_Rocket4Third
# 130 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 131 "data/maps/ObsidianCity/scripts.pory"
	delay 30
# 132 "data/maps/ObsidianCity/scripts.pory"
	msgbox ObsidianCity_Text_RightThing
# 133 "data/maps/ObsidianCity/scripts.pory"
	closemessage
# 134 "data/maps/ObsidianCity/scripts.pory"
	applymovement 4, ObsidianCity_Movement_Rocket4Fourth
# 135 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 136 "data/maps/ObsidianCity/scripts.pory"
	delay 30
# 137 "data/maps/ObsidianCity/scripts.pory"
	removeobject 1
# 138 "data/maps/ObsidianCity/scripts.pory"
	removeobject 2
# 139 "data/maps/ObsidianCity/scripts.pory"
	removeobject 3
# 140 "data/maps/ObsidianCity/scripts.pory"
	removeobject 4
# 141 "data/maps/ObsidianCity/scripts.pory"
	removeobject 5
# 142 "data/maps/ObsidianCity/scripts.pory"
	applymovement 6, ObsidianCity_Movement_GioToPlayerLeftMid
# 143 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 144 "data/maps/ObsidianCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 145 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 146 "data/maps/ObsidianCity/scripts.pory"
	msgbox ObsidianCity_Text_SeeThat
# 147 "data/maps/ObsidianCity/scripts.pory"
	closemessage
# 148 "data/maps/ObsidianCity/scripts.pory"
	applymovement 6, ObsidianCity_Movement_GioToRuinsLeftMid
# 149 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 150 "data/maps/ObsidianCity/scripts.pory"
	removeobject 6
# 151 "data/maps/ObsidianCity/scripts.pory"
	setvar VAR_MAP_SCENE_OBSIDIAN_CITY_EVENTS, 2
# 152 "data/maps/ObsidianCity/scripts.pory"
	releaseall
	end


ObsidianCity_EventScript_TriggerMid::
# 157 "data/maps/ObsidianCity/scripts.pory"
	lockall
# 158 "data/maps/ObsidianCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 159 "data/maps/ObsidianCity/scripts.pory"
	msgbox ObsidianCity_Text_OuttaTheWay
# 160 "data/maps/ObsidianCity/scripts.pory"
	closemessage
# 161 "data/maps/ObsidianCity/scripts.pory"
	delay 60
# 162 "data/maps/ObsidianCity/scripts.pory"
	applymovement 1, ObsidianCity_Movement_Rocket1First
# 163 "data/maps/ObsidianCity/scripts.pory"
	applymovement 2, ObsidianCity_Movement_Rocket2First
# 164 "data/maps/ObsidianCity/scripts.pory"
	applymovement 3, ObsidianCity_Movement_Rocket3First
# 165 "data/maps/ObsidianCity/scripts.pory"
	applymovement 4, ObsidianCity_Movement_Rocket4First
# 166 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 167 "data/maps/ObsidianCity/scripts.pory"
	applymovement 6, ObsidianCity_Movement_GioOuttaWay
# 168 "data/maps/ObsidianCity/scripts.pory"
	applymovement 1, ObsidianCity_Movement_Rocket1Second
# 169 "data/maps/ObsidianCity/scripts.pory"
	applymovement 2, ObsidianCity_Movement_Rocket2Second
# 170 "data/maps/ObsidianCity/scripts.pory"
	applymovement 3, ObsidianCity_Movement_Rocket3Second
# 171 "data/maps/ObsidianCity/scripts.pory"
	applymovement 4, ObsidianCity_Movement_Rocket4Second
# 172 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 173 "data/maps/ObsidianCity/scripts.pory"
	applymovement 6, Common_Movement_FaceUp
# 174 "data/maps/ObsidianCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, ObsidianCity_Movement_PlayerLookRocketMid
# 175 "data/maps/ObsidianCity/scripts.pory"
	applymovement 1, ObsidianCity_Movement_Rocket1Third
# 176 "data/maps/ObsidianCity/scripts.pory"
	applymovement 2, ObsidianCity_Movement_Rocket2Third
# 177 "data/maps/ObsidianCity/scripts.pory"
	applymovement 3, ObsidianCity_Movement_Rocket3Third
# 178 "data/maps/ObsidianCity/scripts.pory"
	applymovement 4, ObsidianCity_Movement_Rocket4Third
# 179 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 180 "data/maps/ObsidianCity/scripts.pory"
	delay 30
# 181 "data/maps/ObsidianCity/scripts.pory"
	msgbox ObsidianCity_Text_RightThing
# 182 "data/maps/ObsidianCity/scripts.pory"
	closemessage
# 183 "data/maps/ObsidianCity/scripts.pory"
	applymovement 4, ObsidianCity_Movement_Rocket4Fourth
# 184 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 185 "data/maps/ObsidianCity/scripts.pory"
	delay 30
# 186 "data/maps/ObsidianCity/scripts.pory"
	removeobject 1
# 187 "data/maps/ObsidianCity/scripts.pory"
	removeobject 2
# 188 "data/maps/ObsidianCity/scripts.pory"
	removeobject 3
# 189 "data/maps/ObsidianCity/scripts.pory"
	removeobject 4
# 190 "data/maps/ObsidianCity/scripts.pory"
	removeobject 5
# 191 "data/maps/ObsidianCity/scripts.pory"
	applymovement 6, ObsidianCity_Movement_GioToPlayerLeftMid
# 192 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 193 "data/maps/ObsidianCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 194 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 195 "data/maps/ObsidianCity/scripts.pory"
	msgbox ObsidianCity_Text_SeeThat
# 196 "data/maps/ObsidianCity/scripts.pory"
	closemessage
# 197 "data/maps/ObsidianCity/scripts.pory"
	applymovement 6, ObsidianCity_Movement_GioToRuinsLeftMid
# 198 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 199 "data/maps/ObsidianCity/scripts.pory"
	removeobject 6
# 200 "data/maps/ObsidianCity/scripts.pory"
	setvar VAR_MAP_SCENE_OBSIDIAN_CITY_EVENTS, 2
# 201 "data/maps/ObsidianCity/scripts.pory"
	releaseall
	end


ObsidianCity_EventScript_TriggerRight::
# 206 "data/maps/ObsidianCity/scripts.pory"
	lockall
# 207 "data/maps/ObsidianCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 208 "data/maps/ObsidianCity/scripts.pory"
	msgbox ObsidianCity_Text_OuttaTheWay
# 209 "data/maps/ObsidianCity/scripts.pory"
	closemessage
# 210 "data/maps/ObsidianCity/scripts.pory"
	delay 60
# 211 "data/maps/ObsidianCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 212 "data/maps/ObsidianCity/scripts.pory"
	applymovement 1, ObsidianCity_Movement_Rocket1First
# 213 "data/maps/ObsidianCity/scripts.pory"
	applymovement 2, ObsidianCity_Movement_Rocket2First
# 214 "data/maps/ObsidianCity/scripts.pory"
	applymovement 3, ObsidianCity_Movement_Rocket3First
# 215 "data/maps/ObsidianCity/scripts.pory"
	applymovement 4, ObsidianCity_Movement_Rocket4First
# 216 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 217 "data/maps/ObsidianCity/scripts.pory"
	applymovement 6, ObsidianCity_Movement_GioOuttaWay
# 218 "data/maps/ObsidianCity/scripts.pory"
	applymovement 1, ObsidianCity_Movement_Rocket1Second
# 219 "data/maps/ObsidianCity/scripts.pory"
	applymovement 2, ObsidianCity_Movement_Rocket2Second
# 220 "data/maps/ObsidianCity/scripts.pory"
	applymovement 3, ObsidianCity_Movement_Rocket3Second
# 221 "data/maps/ObsidianCity/scripts.pory"
	applymovement 4, ObsidianCity_Movement_Rocket4Second
# 222 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 223 "data/maps/ObsidianCity/scripts.pory"
	applymovement 6, Common_Movement_FaceUp
# 224 "data/maps/ObsidianCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, ObsidianCity_Movement_PlayerLookRocketRight
# 225 "data/maps/ObsidianCity/scripts.pory"
	applymovement 1, ObsidianCity_Movement_Rocket1Third
# 226 "data/maps/ObsidianCity/scripts.pory"
	applymovement 2, ObsidianCity_Movement_Rocket2Third
# 227 "data/maps/ObsidianCity/scripts.pory"
	applymovement 3, ObsidianCity_Movement_Rocket3Third
# 228 "data/maps/ObsidianCity/scripts.pory"
	applymovement 4, ObsidianCity_Movement_Rocket4Third
# 229 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 230 "data/maps/ObsidianCity/scripts.pory"
	delay 30
# 231 "data/maps/ObsidianCity/scripts.pory"
	msgbox ObsidianCity_Text_RightThing
# 232 "data/maps/ObsidianCity/scripts.pory"
	closemessage
# 233 "data/maps/ObsidianCity/scripts.pory"
	applymovement 4, ObsidianCity_Movement_Rocket4Fourth
# 234 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 235 "data/maps/ObsidianCity/scripts.pory"
	delay 30
# 236 "data/maps/ObsidianCity/scripts.pory"
	removeobject 1
# 237 "data/maps/ObsidianCity/scripts.pory"
	removeobject 2
# 238 "data/maps/ObsidianCity/scripts.pory"
	removeobject 3
# 239 "data/maps/ObsidianCity/scripts.pory"
	removeobject 4
# 240 "data/maps/ObsidianCity/scripts.pory"
	removeobject 5
# 241 "data/maps/ObsidianCity/scripts.pory"
	applymovement 6, ObsidianCity_Movement_GioToPlayerRight
# 242 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 243 "data/maps/ObsidianCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 244 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 245 "data/maps/ObsidianCity/scripts.pory"
	msgbox ObsidianCity_Text_SeeThat
# 246 "data/maps/ObsidianCity/scripts.pory"
	closemessage
# 247 "data/maps/ObsidianCity/scripts.pory"
	applymovement 6, ObsidianCity_Movement_GioToRuinsRight
# 248 "data/maps/ObsidianCity/scripts.pory"
	waitmovement 0
# 249 "data/maps/ObsidianCity/scripts.pory"
	removeobject 6
# 250 "data/maps/ObsidianCity/scripts.pory"
	clearflag FLAG_HIDE_GIO_RUINS
# 251 "data/maps/ObsidianCity/scripts.pory"
	setflag FLAG_HIDE_GIO_GYM
# 252 "data/maps/ObsidianCity/scripts.pory"
	setvar VAR_MAP_SCENE_OBSIDIAN_CITY_EVENTS, 2
# 253 "data/maps/ObsidianCity/scripts.pory"
	releaseall
	end


# 269 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_Rocket1First:
	step_end

# 276 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_Rocket2First:
	step_end

# 282 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_Rocket3First:
	step_end

# 287 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_Rocket4First:
	step_end

# 292 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_GioOuttaWay:
# 293 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 294 "data/maps/ObsidianCity/scripts.pory"
	face_down
# 295 "data/maps/ObsidianCity/scripts.pory"
	delay_1
# 296 "data/maps/ObsidianCity/scripts.pory"
	face_right
	step_end

# 299 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_Rocket1Second:
# 300 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 301 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_right
# 302 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 303 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_right
# 304 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 304 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 304 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
	step_end

# 307 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_Rocket2Second:
# 308 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
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
	step_end

# 315 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_Rocket3Second:
# 316 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
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
	step_end

# 323 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_Rocket4Second:
# 324 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
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
	step_end

# 330 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_Rocket1Third:
# 331 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 331 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 331 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 331 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 331 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 331 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 332 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_left
# 333 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 334 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_left
# 334 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_left
	step_end

# 337 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_Rocket2Third:
# 338 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 338 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 338 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 338 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 338 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 338 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 338 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 339 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_left
# 340 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 341 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_left
	step_end

# 344 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_Rocket3Third:
# 345 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 345 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 345 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 345 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 345 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 345 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 345 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 345 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 346 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_left
# 347 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
	step_end

# 350 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_Rocket4Third:
# 351 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 351 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_up
# 352 "data/maps/ObsidianCity/scripts.pory"
	walk_up
# 352 "data/maps/ObsidianCity/scripts.pory"
	walk_up
# 353 "data/maps/ObsidianCity/scripts.pory"
	walk_slow_up
# 353 "data/maps/ObsidianCity/scripts.pory"
	walk_slow_up
# 354 "data/maps/ObsidianCity/scripts.pory"
	face_up
# 355 "data/maps/ObsidianCity/scripts.pory"
	delay_16
# 356 "data/maps/ObsidianCity/scripts.pory"
	face_left
# 357 "data/maps/ObsidianCity/scripts.pory"
	delay_16
# 358 "data/maps/ObsidianCity/scripts.pory"
	face_right
# 359 "data/maps/ObsidianCity/scripts.pory"
	delay_16
# 360 "data/maps/ObsidianCity/scripts.pory"
	delay_16
# 361 "data/maps/ObsidianCity/scripts.pory"
	face_up
	step_end

# 364 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_Rocket4Fourth:
# 365 "data/maps/ObsidianCity/scripts.pory"
	walk_up
# 365 "data/maps/ObsidianCity/scripts.pory"
	walk_up
# 365 "data/maps/ObsidianCity/scripts.pory"
	walk_up
# 366 "data/maps/ObsidianCity/scripts.pory"
	walk_left
# 367 "data/maps/ObsidianCity/scripts.pory"
	walk_up
	step_end

# 370 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_PlayerLookRocketLeft:
# 371 "data/maps/ObsidianCity/scripts.pory"
	walk_in_place_right
# 372 "data/maps/ObsidianCity/scripts.pory"
	walk_in_place_up
	step_end

# 375 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_PlayerLookRocketMid:
# 376 "data/maps/ObsidianCity/scripts.pory"
	walk_fast_left
# 377 "data/maps/ObsidianCity/scripts.pory"
	walk_in_place_fast_right
# 378 "data/maps/ObsidianCity/scripts.pory"
	walk_in_place_up
	step_end

# 381 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_PlayerLookRocketRight:
# 382 "data/maps/ObsidianCity/scripts.pory"
	walk_in_place_left
# 383 "data/maps/ObsidianCity/scripts.pory"
	walk_in_place_up
	step_end

# 386 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_GioToPlayerLeftMid:
# 387 "data/maps/ObsidianCity/scripts.pory"
	walk_right
# 388 "data/maps/ObsidianCity/scripts.pory"
	walk_up
# 388 "data/maps/ObsidianCity/scripts.pory"
	walk_up
# 388 "data/maps/ObsidianCity/scripts.pory"
	walk_up
	step_end

# 391 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_GioToPlayerRight:
# 392 "data/maps/ObsidianCity/scripts.pory"
	walk_right
# 392 "data/maps/ObsidianCity/scripts.pory"
	walk_right
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
ObsidianCity_Movement_GioToRuinsLeftMid:
# 397 "data/maps/ObsidianCity/scripts.pory"
	walk_down
# 397 "data/maps/ObsidianCity/scripts.pory"
	walk_down
# 397 "data/maps/ObsidianCity/scripts.pory"
	walk_down
# 397 "data/maps/ObsidianCity/scripts.pory"
	walk_down
# 398 "data/maps/ObsidianCity/scripts.pory"
	walk_left
# 398 "data/maps/ObsidianCity/scripts.pory"
	walk_left
# 399 "data/maps/ObsidianCity/scripts.pory"
	walk_down
# 399 "data/maps/ObsidianCity/scripts.pory"
	walk_down
# 399 "data/maps/ObsidianCity/scripts.pory"
	walk_down
	step_end

# 402 "data/maps/ObsidianCity/scripts.pory"
ObsidianCity_Movement_GioToRuinsRight:
# 403 "data/maps/ObsidianCity/scripts.pory"
	walk_down
# 403 "data/maps/ObsidianCity/scripts.pory"
	walk_down
# 403 "data/maps/ObsidianCity/scripts.pory"
	walk_down
# 403 "data/maps/ObsidianCity/scripts.pory"
	walk_down
# 404 "data/maps/ObsidianCity/scripts.pory"
	walk_left
# 404 "data/maps/ObsidianCity/scripts.pory"
	walk_left
# 404 "data/maps/ObsidianCity/scripts.pory"
	walk_left
# 404 "data/maps/ObsidianCity/scripts.pory"
	walk_left
# 405 "data/maps/ObsidianCity/scripts.pory"
	walk_down
# 405 "data/maps/ObsidianCity/scripts.pory"
	walk_down
# 405 "data/maps/ObsidianCity/scripts.pory"
	walk_down
	step_end

ObsidianCity_Text_WhatInTarnation::
# 89 "data/maps/ObsidianCity/scripts.pory"
	.string "GEOFFREY: What in tarnation was that?$"

ObsidianCity_Text_YouHeardToo::
# 93 "data/maps/ObsidianCity/scripts.pory"
	.string "Didja hear that too, kid?\nYou musta heard it!$"

ObsidianCity_Text_IGo::
# 97 "data/maps/ObsidianCity/scripts.pory"
	.string "GEOFFREY: Gosh dangit!\nSomethin's def'nitely up!\pI'll bet it's at that place!\nThe RUINS OF OMEG!$"

ObsidianCity_Text_OuttaTheWay::
# 257 "data/maps/ObsidianCity/scripts.pory"
	.string "???: Get out of the way!$"

ObsidianCity_Text_RightThing::
# 261 "data/maps/ObsidianCity/scripts.pory"
	.string "???: Killing all those UNOWN...\nWas that really the right thing?$"

ObsidianCity_Text_SeeThat::
# 265 "data/maps/ObsidianCity/scripts.pory"
	.string "GEOFFREY: Yeowch!\nThose people were so dang fast!\pI didn't quite catch what that\nlast person said.\pBut they musta been behind that\nquake earlier!\p...\pOh gosh! I should hurry to the\nRUINS!$"
