SSAnne_1F_Corridor_MapScripts::
# 2 "data/maps/SSAnne_1F_Corridor/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SSAnne_1F_Corridor_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

SSAnne_1F_Corridor_MapScripts_MAP_SCRIPT_ON_LOAD:
# 3 "data/maps/SSAnne_1F_Corridor/scripts.pory"
	call_if_eq VAR_MAP_SCENE_SS_ANNE_STATE, 0, SSAnne_1F_Corridor_EventScript_SetVermilion
# 4 "data/maps/SSAnne_1F_Corridor/scripts.pory"
	call_if_eq VAR_MAP_SCENE_SS_ANNE_STATE, 1, SSAnne_1F_Corridor_EventScript_SetCinnabar
# 5 "data/maps/SSAnne_1F_Corridor/scripts.pory"
	call_if_eq VAR_MAP_SCENE_SS_ANNE_STATE, 2, SSAnne_1F_Corridor_EventScript_SetCinnabar
# 6 "data/maps/SSAnne_1F_Corridor/scripts.pory"
	call_if_eq VAR_MAP_SCENE_SS_ANNE_STATE, 3, SSAnne_1F_Corridor_EventScript_SetVermilion
	return


SSAnne_1F_Corridor_EventScript_SetVermilion::
# 11 "data/maps/SSAnne_1F_Corridor/scripts.pory"
	setdynamicwarp MAP_SSANNE_EXTERIOR, 255, 32, 14
	end


SSAnne_1F_Corridor_EventScript_SetCinnabar::
# 16 "data/maps/SSAnne_1F_Corridor/scripts.pory"
	setdynamicwarp MAP_CINNABAR_ISLAND, 255, 9, 15
	end


# 20 "data/maps/SSAnne_1F_Corridor/scripts.pory"

# 21 "data/maps/SSAnne_1F_Corridor/scripts.pory"
SSAnne_1F_Corridor_EventScript_WorkerM::
# 22 "data/maps/SSAnne_1F_Corridor/scripts.pory"
	msgbox SSAnne_1F_Corridor_Text_LeStrongSilentType, MSGBOX_NPC
# 23 "data/maps/SSAnne_1F_Corridor/scripts.pory"
	end
# 24 "data/maps/SSAnne_1F_Corridor/scripts.pory"

# 25 "data/maps/SSAnne_1F_Corridor/scripts.pory"
SSAnne_1F_Corridor_EventScript_Sailor::
# 26 "data/maps/SSAnne_1F_Corridor/scripts.pory"
	msgbox SSAnne_1F_Corridor_Text_PassengersAreRestless, MSGBOX_NPC
# 27 "data/maps/SSAnne_1F_Corridor/scripts.pory"
	end
