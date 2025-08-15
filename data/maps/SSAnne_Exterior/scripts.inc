SSAnne_Exterior_MapScripts::
# 5 "data/maps/SSAnne_Exterior/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SSAnne_Exterior_OnTransition
# 6 "data/maps/SSAnne_Exterior/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SSAnne_Exterior_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

SSAnne_Exterior_MapScripts_MAP_SCRIPT_ON_LOAD:
# 7 "data/maps/SSAnne_Exterior/scripts.pory"
	call_if_set FLAG_HIDE_SS_ANNE, SSAnne_Exterior_ChangeTile
	return


SSAnne_Exterior_OnTransition::
# 12 "data/maps/SSAnne_Exterior/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_SSANNE_EXTERIOR
	return


SSAnne_Exterior_ChangeTile::
# 16 "data/maps/SSAnne_Exterior/scripts.pory"
	setmetatile 32, 14, 0x1C1, 0
	return

