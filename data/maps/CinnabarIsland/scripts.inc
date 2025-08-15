CinnabarIsland_MapScripts::
# 2 "data/maps/CinnabarIsland/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, CinnabarIsland_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 5 "data/maps/CinnabarIsland/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, CinnabarIsland_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

CinnabarIsland_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/CinnabarIsland/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_CINNABAR_ISLAND
	return

CinnabarIsland_MapScripts_MAP_SCRIPT_ON_LOAD:
# 6 "data/maps/CinnabarIsland/scripts.pory"
	call_if_eq VAR_MAP_SCENE_SS_ANNE_STATE, 1, CinnabarIsland_EventScript_BlockWater
# 7 "data/maps/CinnabarIsland/scripts.pory"
	call_if_eq VAR_MAP_SCENE_SS_ANNE_STATE, 2, CinnabarIsland_EventScript_BlockWater
	return


CinnabarIsland_EventScript_BlockWater::
# 12 "data/maps/CinnabarIsland/scripts.pory"
	setmetatile 5, 17, 0x12B, 1
# 13 "data/maps/CinnabarIsland/scripts.pory"
	setmetatile 6, 17, 0x12B, 1
# 14 "data/maps/CinnabarIsland/scripts.pory"
	setmetatile 7, 17, 0x12B, 1
# 15 "data/maps/CinnabarIsland/scripts.pory"
	setmetatile 8, 17, 0x12B, 1
# 16 "data/maps/CinnabarIsland/scripts.pory"
	setmetatile 9, 17, 0x12B, 1
# 17 "data/maps/CinnabarIsland/scripts.pory"
	setmetatile 10, 17, 0x12B, 1
# 18 "data/maps/CinnabarIsland/scripts.pory"
	setmetatile 11, 17, 0x12B, 1
# 19 "data/maps/CinnabarIsland/scripts.pory"
	setmetatile 12, 17, 0x12C, 1
# 20 "data/maps/CinnabarIsland/scripts.pory"
	setmetatile 5, 16, 0x12B, 1
# 21 "data/maps/CinnabarIsland/scripts.pory"
	setmetatile 6, 16, 0x12B, 1
# 22 "data/maps/CinnabarIsland/scripts.pory"
	setmetatile 7, 16, 0x12B, 1
# 23 "data/maps/CinnabarIsland/scripts.pory"
	setmetatile 8, 16, 0x12B, 1
# 24 "data/maps/CinnabarIsland/scripts.pory"
	setmetatile 9, 16, 0x12B, 1
# 25 "data/maps/CinnabarIsland/scripts.pory"
	setmetatile 10, 16, 0x12B, 1
# 26 "data/maps/CinnabarIsland/scripts.pory"
	setmetatile 11, 16, 0x12B, 1
# 27 "data/maps/CinnabarIsland/scripts.pory"
	setmetatile 12, 16, 0x12C, 1
# 28 "data/maps/CinnabarIsland/scripts.pory"
	setmetatile 8, 15, 0x301, 0
# 29 "data/maps/CinnabarIsland/scripts.pory"
	setmetatile 9, 15, 0x302, 0
# 30 "data/maps/CinnabarIsland/scripts.pory"
	setmetatile 10, 15, 0x303, 0
	end


# 34 "data/maps/CinnabarIsland/scripts.pory"

# 35 "data/maps/CinnabarIsland/scripts.pory"

# 36 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_EventScript_IslandSign::
# 37 "data/maps/CinnabarIsland/scripts.pory"
	msgbox CinnabarIsland_Text_IslandSign, MSGBOX_SIGN
# 38 "data/maps/CinnabarIsland/scripts.pory"
	end
# 39 "data/maps/CinnabarIsland/scripts.pory"

# 40 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_EventScript_PokemonLabSign::
# 41 "data/maps/CinnabarIsland/scripts.pory"
	msgbox CinnabarIsland_Text_PokemonLab, MSGBOX_SIGN
# 42 "data/maps/CinnabarIsland/scripts.pory"
	end
# 43 "data/maps/CinnabarIsland/scripts.pory"

# 44 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_EventScript_GymSign::
# 45 "data/maps/CinnabarIsland/scripts.pory"
	lockall
# 46 "data/maps/CinnabarIsland/scripts.pory"
	famechecker FAMECHECKER_BLAINE, 0
# 47 "data/maps/CinnabarIsland/scripts.pory"
	msgbox CinnabarIsland_Text_GymSign
# 48 "data/maps/CinnabarIsland/scripts.pory"
	releaseall
# 49 "data/maps/CinnabarIsland/scripts.pory"
	end
