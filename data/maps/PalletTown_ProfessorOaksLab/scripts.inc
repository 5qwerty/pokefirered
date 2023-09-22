PalletTown_ProfessorOaksLab_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_ProfessorOaksLab_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PalletTown_ProfessorOaksLab_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PalletTown_ProfessorOaksLab_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

PalletTown_ProfessorOaksLab_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1, PalletTown_SoakLab_EventScript_ReadySoakRivalForStarterScene
	return

PalletTown_ProfessorOaksLab_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
	map_script_2 VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1, PalletTown_SoakLab_EventScript_ReadyPlayerForStarterScene
	.2byte 0

PalletTown_ProfessorOaksLab_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1, PalletTown_SoakLab_EventScript_ChooseStarterScene
	.2byte 0


PalletTown_SoakLab_EventScript_ReadySoakRivalForStarterScene::
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_UP
	setobjectxyperm 6, 6, 11
	setobjectmovementtype 6, MOVEMENT_TYPE_FACE_UP
	savebgm MUS_OAK
	return


PalletTown_SoakLab_EventScript_ReadyPlayerForStarterScene::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end


PalletTown_SoakLab_EventScript_ChooseStarterScene::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	applymovement 6, PalletTown_SoakLab_Movement_Up3
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_SoakLab_Movement_Up3
	waitmovement 0
	applymovement 6, Common_Movement_FaceDown
	waitmovement 0
	msgbox PalletTown_SoakLab_Text_GoAhead
	closemessage
	applymovement 6, PalletTown_SoakLab_Movement_AideRight
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_SoakLab_Movement_PlayerToSpot
	waitmovement 0
	setobjectmovementtype 6, MOVEMENT_TYPE_LOOK_AROUND
	applymovement 5, Common_Movement_WalkInPlaceFasterUp
	clearflag FLAG_DONT_TRANSITION_MUSIC
	savebgm MUS_DUMMY
	fadedefaultbgm
	msgbox PalletTown_SoakLab_Text_TiredOfWaiting
	closemessage
	delay 30
	msgbox PalletTown_SoakLab_Text_ChooseThree
	closemessage
	delay 30
	applymovement 5, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox PalletTown_SoakLab_Text_CompletelyUnfair
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_SoakLab_Movement_PlayerOuttaWay
	applymovement 1, PalletTown_SoakLab_Movement_DelayLookRight
	applymovement 5, PalletTown_SoakLab_Movement_ToMudkip
	waitmovement 0
	msgbox PalletTown_SoakLab_Text_IWantedThis
	closemessage
	delay 30
	removeobject 4
	textcolor NPC_TEXT_COLOR_NEUTRAL
	bufferspeciesname STR_VAR_1, SPECIES_MUDKIP
	message PalletTown_SoakLab_Text_RivalReceivedFromSoak
	waitmessage
	playfanfare MUS_OBTAIN_KEY_ITEM
	waitfanfare
	delay 30
	textcolor NPC_TEXT_COLOR_MALE
	applymovement 1, Common_Movement_WalkInPlaceFasterDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PalletTown_SoakLab_Text_ChooseTwo
	closemessage
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 2
	releaseall
	end


PalletTown_SoakLab_Movement_Up3:
	walk_up
	walk_up
	walk_up
	step_end

PalletTown_SoakLab_Movement_AideRight:
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

PalletTown_SoakLab_Movement_PlayerToSpot:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PalletTown_SoakLab_Movement_PlayerOuttaWay:
	walk_fast_down
	walk_in_place_fast_up
	walk_in_place_fast_right
	step_end

PalletTown_SoakLab_Movement_DelayLookRight:
	delay_16
	walk_in_place_fast_right
	step_end

PalletTown_SoakLab_Movement_ToMudkip:
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	face_up
	step_end

PalletTown_SoakLab_EventScript_SquirtleBall::
	lock
	faceplayer
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, SPECIES_SQUIRTLE
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 2, PalletTown_SoakLab_EventScript_ConfirmStarterChoice
	msgbox PalletTown_SoakLab_Text_SoakLastMon
	release
	end


PalletTown_SoakLab_EventScript_TotodileBall::
	lock
	faceplayer
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_2, SPECIES_TOTODILE
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 2, PalletTown_SoakLab_EventScript_ConfirmStarterChoice
	msgbox PalletTown_SoakLab_Text_SoakLastMon
	release
	end


PalletTown_SoakLab_EventScript_ConfirmStarterChoice::
	applymovement 1, Common_Movement_FaceRight
	waitmovement 0
	showmonpic VAR_TEMP_2, 10, 3
	textcolor NPC_TEXT_COLOR_MALE
	goto_if_eq VAR_TEMP_1, 0, PalletTown_SoakLab_EventScript_ConfirmSquirtle
	goto_if_eq VAR_TEMP_1, 1, PalletTown_SoakLab_EventScript_ConfirmTotodile
	end


PalletTown_SoakLab_EventScript_ConfirmSquirtle::
	msgbox PalletTown_SoakLab_Text_ChoosingSquirtle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PalletTown_SoakLab_EventScript_ChoseStarter
	goto_if_eq VAR_RESULT, NO, PalletTown_SoakLab_EventScript_DeclinedStarter
	end


PalletTown_SoakLab_EventScript_ConfirmTotodile::
	msgbox PalletTown_SoakLab_Text_ChoosingTotodile, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PalletTown_SoakLab_EventScript_ChoseStarter
	goto_if_eq VAR_RESULT, NO, PalletTown_SoakLab_EventScript_DeclinedStarter
	end


PalletTown_SoakLab_EventScript_DeclinedStarter::
	hidemonpic
	release
	end


PalletTown_SoakLab_EventScript_ChoseStarter::
	hidemonpic
	removeobject VAR_LAST_TALKED
	msgbox PalletTown_SoakLab_Text_Energetic
	call EventScript_RestorePrevTextColor
	setflag FLAG_SYS_POKEMON_GET
	givemon VAR_TEMP_2, 5
	copyvar VAR_STARTER_MON, VAR_TEMP_1
	bufferspeciesname STR_VAR_1, VAR_TEMP_2
	message PalletTown_SoakLab_Text_ReceivedMonFromSoak
	waitmessage
	playfanfare MUS_OBTAIN_KEY_ITEM
	waitfanfare
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	closemessage
	goto_if_eq VAR_RESULT, YES, EventScript_GiveNicknameToStarter
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 3
	end


EventScript_GiveNicknameToStarter::
	setvar VAR_0x8004, 0
	call EventScript_ChangePokemonNickname
	end


PalletTown_SoakLab_EventScript_RivalBattleTriggerLeft::
	lockall
	setvar VAR_TEMP_2, 3
	goto PalletTown_SoakLab_EventScript_RivalBattle
	end


PalletTown_SoakLab_EventScript_RivalBattleTriggerMid::
	lockall
	setvar VAR_TEMP_2, 2
	goto PalletTown_SoakLab_EventScript_RivalBattle
	end


PalletTown_SoakLab_EventScript_RivalBattleTriggerRight::
	lockall
	setvar VAR_TEMP_2, 1
	goto PalletTown_SoakLab_EventScript_RivalBattle
	end


PalletTown_SoakLab_EventScript_RivalBattle::
	textcolor NPC_TEXT_COLOR_MALE
	playbgm MUS_ENCOUNTER_RIVAL, 0
	applymovement 5, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	msgbox PalletTown_SoakLab_Text_BeatDown
	closemessage
	applymovement 1, Common_Movement_FaceDown
	waitmovement 0
	call_if_eq VAR_TEMP_2, 3, PalletTown_SoakLab_EventScript_RivalToPlayerLeft
	call_if_eq VAR_TEMP_2, 2, PalletTown_SoakLab_EventScript_RivalToPlayerMid
	call_if_eq VAR_TEMP_2, 1, PalletTown_SoakLab_EventScript_RivalToPlayerRight
	trainerbattle_earlyrival TRAINER_RIVAL_SOAK_LAB, RIVAL_BATTLE_TUTORIAL, PalletTown_SoakLab_Text_RivalDefeat, PalletTown_SoakLab_Text_RivalVictory
	special HealPlayerParty
	msgbox PalletTown_SoakLab_Text_RivalLeave
	closemessage
	playbgm MUS_RIVAL_EXIT, 0
	call_if_eq VAR_TEMP_2, 3, PalletTown_SoakLab_EventScript_RivalLeaveLeft
	call_if_eq VAR_TEMP_2, 2, PalletTown_SoakLab_EventScript_RivalLeaveMid
	call_if_eq VAR_TEMP_2, 1, PalletTown_SoakLab_EventScript_RivalLeaveRight
	removeobject 5
	playse SE_EXIT
	fadedefaultbgm
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 4
	setflag FLAG_BEAT_RIVAL_IN_OAKS_LAB
	releaseall
	end


PalletTown_SoakLab_EventScript_RivalToPlayerLeft::
	applymovement 5, PalletTown_SoakLab_Movement_RivalToPlayerLeft
	waitmovement 0
	return


PalletTown_SoakLab_EventScript_RivalToPlayerMid::
	applymovement 5, PalletTown_SoakLab_Movement_RivalToPlayerMid
	waitmovement 0
	return


PalletTown_SoakLab_EventScript_RivalToPlayerRight::
	applymovement 5, PalletTown_SoakLab_Movement_RivalToPlayerRight
	waitmovement 0
	return


PalletTown_SoakLab_EventScript_RivalLeaveLeft::
	applymovement 5, PalletTown_SoakLab_Movement_RivalExitLeft
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_SoakLab_Movement_PlayerWatchLeftMid
	waitmovement 5
	return


PalletTown_SoakLab_EventScript_RivalLeaveMid::
	applymovement 5, PalletTown_SoakLab_Movement_RivalExitMid
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_SoakLab_Movement_PlayerWatchLeftMid
	waitmovement 5
	return


PalletTown_SoakLab_EventScript_RivalLeaveRight::
	applymovement 5, PalletTown_SoakLab_Movement_RivalExitRight
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_SoakLab_Movement_PlayerWatchRight
	waitmovement 5
	return


PalletTown_SoakLab_Movement_RivalToPlayerLeft:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

PalletTown_SoakLab_Movement_RivalToPlayerMid:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

PalletTown_SoakLab_Movement_RivalToPlayerRight:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

PalletTown_SoakLab_Movement_RivalExitLeft:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

PalletTown_SoakLab_Movement_RivalExitMid:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	delay_8
	step_end

PalletTown_SoakLab_Movement_RivalExitRight:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

PalletTown_SoakLab_Movement_PlayerWatchLeftMid:
	delay_16
	delay_8
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_down
	step_end

PalletTown_SoakLab_Movement_PlayerWatchRight:
	delay_16
	delay_8
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

PalletTown_SoakLab_Event_LeaveStarterSceneTrigger::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	applymovement 1, Common_Movement_FaceDown
	waitmovement 0
	msgbox PalletTown_SoakLab_Text_DontLeave
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	releaseall
	end


PalletTown_SoakLab_Text_GoAhead::
	.string "Please go ahead.$"

PalletTown_SoakLab_Text_TiredOfWaiting::
	.string "{RIVAL}: Gramps!\n"
	.string "Why'd you make me wait so long just\l"
	.string "for this loser?$"

PalletTown_SoakLab_Text_ChooseThree::
	.string "SOAK: {RIVAL}!\n"
	.string "Don't be mean, little dude!\p"
	.string "I had already decided that {PLAYER}\n"
	.string "would get to choose first today.\p"
	.string "Now, {PLAYER}, I have three POKéMON\n"
	.string "in the POKé BALLS here.\p"
	.string "You can go ahead and have one!\n"
	.string "C'mon, one of these is all yours!$"

PalletTown_SoakLab_Text_CompletelyUnfair::
	.string "{RIVAL}: What?\n"
	.string "That's dumb and completely unfair!\p"
	.string "I'm the one who's your grandson!\n"
	.string "I should get to choose first no\l"
	.string "matter what!$"

PalletTown_SoakLab_Text_OuttaTheWay::
	.string "{RIVAL}: Out of my way, you idiot!\p"
	.string "I'm picking first no matter what!$"

PalletTown_SoakLab_Text_IWantedThis::
	.string "{RIVAL}: Yes, I've had my eye on\n"
	.string "this one for a long time!\p"
	.string "I choose you!$"

PalletTown_SoakLab_Text_ChooseTwo::
	.string "SOAK: Yeesh...\n"
	.string "Somebody oughta teach him some\l"
	.string "manners some day...\p"
	.string "Well at least there are two POKéMON\n"
	.string "left, {PLAYER}.\p"
	.string "Go ahead an choose one!$"

PalletTown_SoakLab_Text_RivalReceivedFromSoak::
	.string "{RIVAL} received the {STR_VAR_1}\n"
	.string "from PROF. SOAK!$"

PalletTown_SoakLab_Text_SoakLastMon::
	.string "That's PROF. SOAK's last POKéMON!$"

PalletTown_SoakLab_Text_ChoosingSquirtle::
	.string "SOAK: Cool pick!\n"
	.string "It's definitely one worth raising.\p"
	.string "So, {PLAYER}, you're grabbing the\n"
	.string "WATER POKéMON SQUIRTLE?$"

PalletTown_SoakLab_Text_ChoosingTotodile::
	.string "SOAK: Solid choice!\n"
	.string "This one's pretty easy to raise.\p"
	.string "So, {PLAYER}, you're going with the\n"
	.string "WATER POKéMON TOTODILE?$"

PalletTown_SoakLab_Text_Energetic::
	.string "This POKéMON seems pretty gnarly,\n"
	.string "no cap!$"

PalletTown_SoakLab_Text_ReceivedMonFromSoak::
	.string "{PLAYER} received the {STR_VAR_1}\n"
	.string "from PROF. SOAK!$"

PalletTown_SoakLab_Text_BeatDown::
	.string "{RIVAL}: Huh?\n"
	.string "Trying to leave?\p"
	.string "Let me give you a beatdown first!$"

PalletTown_SoakLab_Text_RivalDefeat::
	.string "What?\n"
	.string "This isn't possible!\p"
	.string "You only won because of the tips\n"
	.string "my gramps gave!$"

PalletTown_SoakLab_Text_RivalVictory::
	.string "Oh yeah, my MUDKIP stomped you!\n"
	.string "Aren't I the greatest?$"

PalletTown_SoakLab_Text_RivalLeave::
	.string "{RIVAL}: Sniff ya later, loser!\n"
	.string "I'm outta here!$"

PalletTown_SoakLab_Text_DontLeave::
	.string "SOAK: Ayo!\n"
	.string "Don't leave yet!$"
