ObsidianCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ObsidianCity_OnTransition
	.byte 0

ObsidianCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_OBSIDIAN_CITY
	end
