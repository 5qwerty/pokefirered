SSAnne_Exterior_MapScripts::
# 5 "data/maps/SSAnne_Exterior/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SSAnne_Exterior_OnTransition
# 6 "data/maps/SSAnne_Exterior/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SSAnne_Exterior_MapScripts_MAP_SCRIPT_ON_LOAD
# 9 "data/maps/SSAnne_Exterior/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SSAnne_Exterior_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SSAnne_Exterior_MapScripts_MAP_SCRIPT_ON_LOAD:
# 7 "data/maps/SSAnne_Exterior/scripts.pory"
	call_if_set FLAG_HIDE_VERMILION_SS_ANNE, SSAnne_Exterior_ChangeTile
	return

SSAnne_Exterior_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 10 "data/maps/SSAnne_Exterior/scripts.pory"
	map_script_2 VAR_MAP_SCENE_SS_ANNE_STATE, 3, SSAnne_Exterior_EventScript_PlayerWalk
	.2byte 0


SSAnne_Exterior_OnTransition::
# 15 "data/maps/SSAnne_Exterior/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_SSANNE_EXTERIOR
	return


SSAnne_Exterior_ChangeTile::
# 19 "data/maps/SSAnne_Exterior/scripts.pory"
	setmetatile 32, 14, 0x1C1, 0
	return


SSAnne_Exterior_EventScript_PlayerWalk::
# 23 "data/maps/SSAnne_Exterior/scripts.pory"
	lockall
# 24 "data/maps/SSAnne_Exterior/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SSAnne_Exterior_Movement_PlayerLeave
# 25 "data/maps/SSAnne_Exterior/scripts.pory"
	waitmovement 0
# 26 "data/maps/SSAnne_Exterior/scripts.pory"
	warp MAP_VERMILION_CITY, 11, 45
# 27 "data/maps/SSAnne_Exterior/scripts.pory"
	waitstate
# 28 "data/maps/SSAnne_Exterior/scripts.pory"
	releaseall
	end


# 32 "data/maps/SSAnne_Exterior/scripts.pory"
SSAnne_Exterior_Movement_PlayerLeave:
# 33 "data/maps/SSAnne_Exterior/scripts.pory"
	walk_up
# 33 "data/maps/SSAnne_Exterior/scripts.pory"
	walk_up
# 33 "data/maps/SSAnne_Exterior/scripts.pory"
	walk_up
# 33 "data/maps/SSAnne_Exterior/scripts.pory"
	walk_up
# 33 "data/maps/SSAnne_Exterior/scripts.pory"
	walk_up
# 33 "data/maps/SSAnne_Exterior/scripts.pory"
	walk_up
# 33 "data/maps/SSAnne_Exterior/scripts.pory"
	walk_up
# 33 "data/maps/SSAnne_Exterior/scripts.pory"
	walk_up
# 33 "data/maps/SSAnne_Exterior/scripts.pory"
	walk_up
	step_end
