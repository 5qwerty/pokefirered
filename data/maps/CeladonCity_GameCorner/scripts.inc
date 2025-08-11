CeladonCity_GameCorner_MapScripts::
# 4 "data/maps/CeladonCity_GameCorner/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, CeladonCity_GameCorner_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

CeladonCity_GameCorner_MapScripts_MAP_SCRIPT_ON_LOAD:
# 5 "data/maps/CeladonCity_GameCorner/scripts.pory"
	call_if_unset FLAG_OPENED_ROCKET_HIDEOUT, CeladonCity_GameCorner_EventScript_HideRocketHideout
	return


CeladonCity_GameCorner_EventScript_HideRocketHideout::
# 10 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setmetatile 15, 2, METATILE_GameCorner_Floor_ShadeFull, 0
# 11 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setmetatile 16, 2, METATILE_GameCorner_Floor_ShadeFull, 0
# 12 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setmetatile 17, 2, METATILE_GameCorner_Floor_ShadeFull, 0
# 13 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setmetatile 16, 3, METATILE_GameCorner_PurpleWall_Floor, 1
# 14 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setmetatile 17, 3, METATILE_GameCorner_PurpleWall_Floor, 1
	return


CeladonCity_GameCorner_EventScript_InfoClerk::
# 19 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_CanExchangeCoinsNextDoor, MSGBOX_NPC
	return


CeladonCity_GameCorner_EventScript_CoinsClerk::
# 23 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 24 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lock
# 25 "data/maps/CeladonCity_GameCorner/scripts.pory"
	faceplayer
# 26 "data/maps/CeladonCity_GameCorner/scripts.pory"
	showmoneybox 0, 0
# 27 "data/maps/CeladonCity_GameCorner/scripts.pory"
	showcoinsbox 0, 5
# 28 "data/maps/CeladonCity_GameCorner/scripts.pory"
	message CeladonCity_GameCorner_Text_WelcomeBuySomeCoins
# 29 "data/maps/CeladonCity_GameCorner/scripts.pory"
	waitmessage
# 30 "data/maps/CeladonCity_GameCorner/scripts.pory"
	multichoice 13, 0, MULTICHOICE_GAME_CORNER_COIN_PURCHASE_COUNTER, FALSE
# 31 "data/maps/CeladonCity_GameCorner/scripts.pory"
	copyvar VAR_0x8009, VAR_RESULT
# 32 "data/maps/CeladonCity_GameCorner/scripts.pory"
	switch VAR_RESULT
# 33 "data/maps/CeladonCity_GameCorner/scripts.pory"
	case 0, CeladonCity_GameCorner_EventScript_CoinsClerk_3
# 34 "data/maps/CeladonCity_GameCorner/scripts.pory"
	case 1, CeladonCity_GameCorner_EventScript_CoinsClerk_4
# 35 "data/maps/CeladonCity_GameCorner/scripts.pory"
	case 2, CeladonCity_GameCorner_EventScript_CoinsClerk_5
# 36 "data/maps/CeladonCity_GameCorner/scripts.pory"
	case 127, CeladonCity_GameCorner_EventScript_CoinsClerk_6
CeladonCity_GameCorner_EventScript_CoinsClerk_1:
	end

CeladonCity_GameCorner_EventScript_CoinsClerk_3:
# 33 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_BuyCoins
	goto CeladonCity_GameCorner_EventScript_CoinsClerk_1

CeladonCity_GameCorner_EventScript_CoinsClerk_4:
# 34 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_BuyCoins
	goto CeladonCity_GameCorner_EventScript_CoinsClerk_1

CeladonCity_GameCorner_EventScript_CoinsClerk_5:
# 35 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_ClerkDeclineBuy
	goto CeladonCity_GameCorner_EventScript_CoinsClerk_1

CeladonCity_GameCorner_EventScript_CoinsClerk_6:
# 36 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_ClerkDeclineBuy
	goto CeladonCity_GameCorner_EventScript_CoinsClerk_1


CeladonCity_GameCorner_EventScript_BuyCoins::
# 42 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto_if_unset FLAG_GOT_COIN_CASE, CeladonCity_GameCorner_EventScript_ClerkNoCoinCase
# 43 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto_if_eq VAR_0x8009, 0, CeladonCity_GameCorner_EventScript_Buy50Coins
# 44 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto_if_eq VAR_0x8009, 1, CeladonCity_GameCorner_EventScript_Buy500Coins
	return


CeladonCity_GameCorner_EventScript_Buy500Coins::
# 48 "data/maps/CeladonCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_1
# 49 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto_if_ge VAR_TEMP_1, ( MAX_COINS + 1 ) - 500, CeladonCity_GameCorner_EventScript_ClerkNoRoomForCoins
# 50 "data/maps/CeladonCity_GameCorner/scripts.pory"
	checkmoney 10000
# 51 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_EventScript_ClerkNotEnoughMoney
# 52 "data/maps/CeladonCity_GameCorner/scripts.pory"
	addcoins 500
# 53 "data/maps/CeladonCity_GameCorner/scripts.pory"
	removemoney 10000
# 54 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_BoughtCoins
	end


CeladonCity_GameCorner_EventScript_Buy50Coins::
# 59 "data/maps/CeladonCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_1
# 60 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto_if_ge VAR_TEMP_1, ( MAX_COINS + 1 ) - 50, CeladonCity_GameCorner_EventScript_ClerkNoRoomForCoins
# 61 "data/maps/CeladonCity_GameCorner/scripts.pory"
	checkmoney 1000
# 62 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_EventScript_ClerkNotEnoughMoney
# 63 "data/maps/CeladonCity_GameCorner/scripts.pory"
	addcoins 50
# 64 "data/maps/CeladonCity_GameCorner/scripts.pory"
	removemoney 1000
# 65 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_BoughtCoins
	end


CeladonCity_GameCorner_EventScript_BoughtCoins::
# 70 "data/maps/CeladonCity_GameCorner/scripts.pory"
	updatemoneybox
# 71 "data/maps/CeladonCity_GameCorner/scripts.pory"
	updatecoinsbox 0, 5
# 72 "data/maps/CeladonCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 73 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_HereAreYourCoins
# 74 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_ClerkEnd
	end


CeladonCity_GameCorner_EventScript_ClerkEnd::
# 79 "data/maps/CeladonCity_GameCorner/scripts.pory"
	hidemoneybox
# 80 "data/maps/CeladonCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 81 "data/maps/CeladonCity_GameCorner/scripts.pory"
	release
	end


CeladonCity_GameCorner_EventScript_ClerkDeclineBuy::
# 86 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_ComePlaySometime
# 87 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_ClerkEnd
	end


CeladonCity_GameCorner_EventScript_ClerkNoCoinCase::
# 92 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_SorryDontHaveCoinCase
# 93 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_ClerkEnd
	end


CeladonCity_GameCorner_EventScript_ClerkNoRoomForCoins::
# 98 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_CoinCaseIsFull
# 99 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_ClerkEnd
	end


CeladonCity_GameCorner_EventScript_ClerkNotEnoughMoney::
# 104 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_CantAffordCoins
# 105 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_ClerkEnd
	end


CeladonCity_GameCorner_EventScript_FaceSlotMachine::
# 139 "data/maps/CeladonCity_GameCorner/scripts.pory"
	closemessage
# 140 "data/maps/CeladonCity_GameCorner/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 141 "data/maps/CeladonCity_GameCorner/scripts.pory"
	waitmovement 0
# 142 "data/maps/CeladonCity_GameCorner/scripts.pory"
	release
	end


CeladonCity_GameCorner_EventScript_BaldingMan::
# 147 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lock
# 148 "data/maps/CeladonCity_GameCorner/scripts.pory"
	faceplayer
# 149 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_RumoredTeamRocketRunsThisPlace
# 150 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
	end


CeladonCity_GameCorner_EventScript_Woman1::
# 155 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lock
# 156 "data/maps/CeladonCity_GameCorner/scripts.pory"
	faceplayer
# 157 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_ThinkMachinesHaveDifferentOdds
# 158 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
	end


CeladonCity_GameCorner_EventScript_Fisher::
# 163 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lock
# 164 "data/maps/CeladonCity_GameCorner/scripts.pory"
	faceplayer
# 165 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto_if_set FLAG_GOT_10_COINS_FROM_GAMBLER, CeladonCity_GameCorner_EventScript_FisherAlreadyGotCoins
# 166 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_DoYouWantToPlay
# 167 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto_if_unset FLAG_GOT_COIN_CASE, CeladonCity_GameCorner_EventScript_GamblerNoCoinCase
# 168 "data/maps/CeladonCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_1
# 169 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto_if_ge VAR_TEMP_1, ( MAX_COINS + 1 ) - 10, CeladonCity_GameCorner_EventScript_FisherNoRoomForCoins
# 170 "data/maps/CeladonCity_GameCorner/scripts.pory"
	addcoins 10
# 171 "data/maps/CeladonCity_GameCorner/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 172 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_Received10CoinsFromMan
# 173 "data/maps/CeladonCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 174 "data/maps/CeladonCity_GameCorner/scripts.pory"
	waitse
# 175 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setflag FLAG_GOT_10_COINS_FROM_GAMBLER
# 176 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
	end


CeladonCity_GameCorner_EventScript_FisherNoRoomForCoins::
# 181 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_DontNeedMyCoins
# 182 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
	end


CeladonCity_GameCorner_EventScript_GamblerNoCoinCase::
# 187 "data/maps/CeladonCity_GameCorner/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 188 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_DontHaveCoinCase
# 189 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
	end


CeladonCity_GameCorner_EventScript_FisherAlreadyGotCoins::
# 194 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_WinsComeAndGo
# 195 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
	end


CeladonCity_GameCorner_EventScript_GymGuy::
# 200 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lock
# 201 "data/maps/CeladonCity_GameCorner/scripts.pory"
	faceplayer
# 202 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto_if_set FLAG_DEFEATED_ERIKA, CeladonCity_GameCorner_EventScript_GymGuyPostVictory
# 203 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_GymGuyAdvice
# 204 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
	end


CeladonCity_GameCorner_EventScript_GymGuyPostVictory::
# 209 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_RareMonsForCoins
# 210 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
	end


CeladonCity_GameCorner_EventScript_Woman2::
# 215 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lock
# 216 "data/maps/CeladonCity_GameCorner/scripts.pory"
	faceplayer
# 217 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_WinOrLoseItsOnlyLuck
# 218 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
	end


CeladonCity_GameCorner_EventScript_OldMan::
# 223 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lock
# 224 "data/maps/CeladonCity_GameCorner/scripts.pory"
	faceplayer
# 225 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_SoEasyToGetHooked
# 226 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
	end


CeladonCity_GameCorner_EventScript_Scientist::
# 231 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lock
# 232 "data/maps/CeladonCity_GameCorner/scripts.pory"
	faceplayer
# 233 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_WantSomeCoins
# 234 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
	end


CeladonCity_GameCorner_EventScript_Gentleman::
# 239 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lock
# 240 "data/maps/CeladonCity_GameCorner/scripts.pory"
	faceplayer
# 241 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_HereAreSomeCoinsShoo
# 242 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
	end


CeladonCity_GameCorner_EventScript_Poster::
# 309 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_Poster, MSGBOX_SIGN
# 310 "data/maps/CeladonCity_GameCorner/scripts.pory"
	closemessage
	end


CeladonCity_GameCorner_EventScript_Tree1::
# 320 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 321 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_SwitchBehindTreePushIt
# 322 "data/maps/CeladonCity_GameCorner/scripts.pory"
	call_if_unset FLAG_GAME_CORNER_SWITCH_1, CeladonCity_GameCorner_EventScript_Switch1
# 323 "data/maps/CeladonCity_GameCorner/scripts.pory"
	releaseall
	end


CeladonCity_GameCorner_EventScript_Tree2::
# 328 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 329 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_SwitchBehindTreePushIt
# 330 "data/maps/CeladonCity_GameCorner/scripts.pory"
	call_if_unset FLAG_GAME_CORNER_SWITCH_2, CeladonCity_GameCorner_EventScript_Switch2
# 331 "data/maps/CeladonCity_GameCorner/scripts.pory"
	releaseall
	end


CeladonCity_GameCorner_EventScript_Switch1::
# 336 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setflag FLAG_GAME_CORNER_SWITCH_1
# 337 "data/maps/CeladonCity_GameCorner/scripts.pory"
	call_if_set FLAG_GAME_CORNER_SWITCH_2, CeladonCity_GameCorner_EventScript_OpenRocketHideout
	return


CeladonCity_GameCorner_EventScript_Switch2::
# 341 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setflag FLAG_GAME_CORNER_SWITCH_2
# 342 "data/maps/CeladonCity_GameCorner/scripts.pory"
	call_if_set FLAG_GAME_CORNER_SWITCH_1, CeladonCity_GameCorner_EventScript_OpenRocketHideout
	return


CeladonCity_GameCorner_EventScript_OpenRocketHideout::
# 352 "data/maps/CeladonCity_GameCorner/scripts.pory"
	playse SE_UNLOCK
# 353 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setmetatile 15, 2, METATILE_GameCorner_Floor_StairsTop, 0
# 354 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setmetatile 16, 2, METATILE_GameCorner_StairsTop, 1
# 355 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setmetatile 17, 2, METATILE_GameCorner_StairsBottom, 1
# 356 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setmetatile 16, 3, METATILE_GameCorner_PurpleWall_StairsTop, 1
# 357 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setmetatile 17, 3, METATILE_GameCorner_PurpleWall_stairsBottom, 1
# 358 "data/maps/CeladonCity_GameCorner/scripts.pory"
	special DrawWholeMapView
# 359 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setflag FLAG_OPENED_ROCKET_HIDEOUT
	return


CeladonCity_GameCorner_EventScript_YoungRocketGrunt::
# 364 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lock
# 365 "data/maps/CeladonCity_GameCorner/scripts.pory"
	faceplayer
# 366 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto_if_unset FLAG_GAME_CORNER_SWITCH_2, CeladonCity_GameCorner_EventScript_YoungRocketGrunt_BeforeSwitch
# 367 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_YoungGruntAfterSwitch
# 368 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
	end


CeladonCity_GameCorner_EventScript_YoungRocketGrunt_BeforeSwitch::
# 373 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_YoungGruntBeforeSwitch
# 374 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
	end


CeladonCity_GameCorner_EventScript_OldRocketGrunt::
# 389 "data/maps/CeladonCity_GameCorner/scripts.pory"
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_7, CeladonCity_GameCorner_Text_GruntIntro, CeladonCity_GameCorner_Text_GruntDefeat, CeladonCity_GameCorner_Text_DefeatedGrunt
# 390 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_GruntPostBattle, MSGBOX_AUTOCLOSE
	end


CeladonCity_GameCorner_Text_DefeatedGrunt::
# 395 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_GruntPostBattle
# 396 "data/maps/CeladonCity_GameCorner/scripts.pory"
	closemessage
# 397 "data/maps/CeladonCity_GameCorner/scripts.pory"
	call CeladonCity_GameCorner_Text_GruntExit
# 398 "data/maps/CeladonCity_GameCorner/scripts.pory"
	removeobject 3
# 399 "data/maps/CeladonCity_GameCorner/scripts.pory"
	release
	end


CeladonCity_GameCorner_Text_GruntExit::
# 404 "data/maps/CeladonCity_GameCorner/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, CeladonCity_GameCorner_Movement_Player
# 405 "data/maps/CeladonCity_GameCorner/scripts.pory"
	applymovement 3, CeladonCity_GameCorner_Movement_GruntExit
# 406 "data/maps/CeladonCity_GameCorner/scripts.pory"
	waitmovement 0
	return


# 410 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_Movement_Player:
# 411 "data/maps/CeladonCity_GameCorner/scripts.pory"
	walk_right
# 412 "data/maps/CeladonCity_GameCorner/scripts.pory"
	face_down
	step_end

# 415 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_Movement_GruntExit:
# 416 "data/maps/CeladonCity_GameCorner/scripts.pory"
	walk_down
# 416 "data/maps/CeladonCity_GameCorner/scripts.pory"
	walk_down
# 417 "data/maps/CeladonCity_GameCorner/scripts.pory"
	walk_right
# 417 "data/maps/CeladonCity_GameCorner/scripts.pory"
	walk_right
# 418 "data/maps/CeladonCity_GameCorner/scripts.pory"
	walk_down
# 418 "data/maps/CeladonCity_GameCorner/scripts.pory"
	walk_down
# 418 "data/maps/CeladonCity_GameCorner/scripts.pory"
	walk_down
# 418 "data/maps/CeladonCity_GameCorner/scripts.pory"
	walk_down
# 418 "data/maps/CeladonCity_GameCorner/scripts.pory"
	walk_down
	step_end

# 421 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 422 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 423 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 424 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachine0::
# 425 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 426 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 0
# 427 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_SlotMachine
# 428 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 429 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 430 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_DontPlaySlotMachine::
# 431 "data/maps/CeladonCity_GameCorner/scripts.pory"
	releaseall
# 432 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 433 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 434 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachine::
# 435 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto_if_unset FLAG_GOT_COIN_CASE, CeladonCity_GameCorner_EventScript_SlotMachineNoCoinCase
# 436 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_SlotMachineWantToPlay, MSGBOX_YESNO
# 437 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, CeladonCity_GameCorner_EventScript_DontPlaySlotMachine
# 438 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setfieldeffectargument 0, OBJ_EVENT_ID_PLAYER
# 439 "data/maps/CeladonCity_GameCorner/scripts.pory"
.ifdef BUGFIX
# 440 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setfieldeffectargument 1, MAP_NUM(CELADON_CITY_GAME_CORNER)
# 441 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setfieldeffectargument 2, MAP_GROUP(CELADON_CITY_GAME_CORNER)
# 442 "data/maps/CeladonCity_GameCorner/scripts.pory"
.else
# 443 "data/maps/CeladonCity_GameCorner/scripts.pory"
	@ Map num/group were provided in the wrong order
# 444 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setfieldeffectargument 1, MAP_GROUP(CELADON_CITY_GAME_CORNER)
# 445 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setfieldeffectargument 2, MAP_NUM(CELADON_CITY_GAME_CORNER)
# 446 "data/maps/CeladonCity_GameCorner/scripts.pory"
.endif
# 447 "data/maps/CeladonCity_GameCorner/scripts.pory"
	dofieldeffect FLDEFF_SMILEY_FACE_ICON
# 448 "data/maps/CeladonCity_GameCorner/scripts.pory"
	waitfieldeffect FLDEFF_SMILEY_FACE_ICON
# 449 "data/maps/CeladonCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetRandomSlotMachineId
# 450 "data/maps/CeladonCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 451 "data/maps/CeladonCity_GameCorner/scripts.pory"
	releaseall
# 452 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 453 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 454 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachine1::
# 455 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 456 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 1
# 457 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_SlotMachine
# 458 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 459 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 460 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachine2::
# 461 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 462 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 2
# 463 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_SlotMachine
# 464 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 465 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 466 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachine3::
# 467 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 468 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 3
# 469 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_SlotMachine
# 470 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 471 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 472 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachine4::
# 473 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 474 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 4
# 475 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_SlotMachine
# 476 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 477 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 478 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachine5::
# 479 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 480 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 5
# 481 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_SlotMachine
# 482 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 483 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 484 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachine6::
# 485 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 486 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 6
# 487 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_SlotMachine
# 488 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 489 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 490 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachine7::
# 491 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 492 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 7
# 493 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_SlotMachine
# 494 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 495 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 496 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachine8::
# 497 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 498 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 8
# 499 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_SlotMachine
# 500 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 501 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 502 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachine9::
# 503 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 504 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 9
# 505 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_SlotMachine
# 506 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 507 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 508 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachine10::
# 509 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 510 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 10
# 511 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_SlotMachine
# 512 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 513 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 514 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachine11::
# 515 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 516 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 11
# 517 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_SlotMachine
# 518 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 519 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 520 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachine12::
# 521 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 522 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 12
# 523 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_SlotMachine
# 524 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 525 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 526 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachine13::
# 527 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 528 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 13
# 529 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_SlotMachine
# 530 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 531 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 532 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachine14::
# 533 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 534 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 14
# 535 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_SlotMachine
# 536 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 537 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 538 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachine15::
# 539 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 540 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 15
# 541 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_SlotMachine
# 542 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 543 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 544 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachine16::
# 545 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 546 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 16
# 547 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_SlotMachine
# 548 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 549 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 550 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachine17::
# 551 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 552 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 17
# 553 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_SlotMachine
# 554 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 555 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 556 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachine18::
# 557 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 558 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 18
# 559 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_SlotMachine
# 560 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 561 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 562 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachine19::
# 563 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 564 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 19
# 565 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_SlotMachine
# 566 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 567 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 568 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachine20::
# 569 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 570 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 20
# 571 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_SlotMachine
# 572 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 573 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 574 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachine21::
# 575 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 576 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 21
# 577 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_SlotMachine
# 578 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 579 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 580 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachineNoCoinCase::
# 581 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_CoinCaseIsRequired
# 582 "data/maps/CeladonCity_GameCorner/scripts.pory"
	releaseall
# 583 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 584 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 585 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_UnusableSlotMachine1::
# 586 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_OutOfOrder, MSGBOX_SIGN
# 587 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 588 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 589 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_UnusableSlotMachine2::
# 590 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_OutToLunch, MSGBOX_SIGN
# 591 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 592 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 593 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_UnusableSlotMachine3::
# 594 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_SomeonesKeys, MSGBOX_SIGN
# 595 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end

CeladonCity_GameCorner_Text_CanExchangeCoinsNextDoor::
# 109 "data/maps/CeladonCity_GameCorner/scripts.pory"
	.string "Welcome!\p"
	.string "You can exchange your COINS for\n"
	.string "fabulous prizes next door.$"

CeladonCity_GameCorner_Text_WelcomeBuySomeCoins::
# 113 "data/maps/CeladonCity_GameCorner/scripts.pory"
	.string "Welcome to ROBOT GAME CORNER!\p"
	.string "Do you need some game COINS?\n"
	.string "Would you like to buy some?$"

CeladonCity_GameCorner_Text_ComePlaySometime::
# 117 "data/maps/CeladonCity_GameCorner/scripts.pory"
	.string "No?\n"
	.string "Please come play sometime!$"

CeladonCity_GameCorner_Text_SorryDontHaveCoinCase::
# 121 "data/maps/CeladonCity_GameCorner/scripts.pory"
	.string "Oh, I'm sorry.\n"
	.string "You don't have a COIN CASE.$"

CeladonCity_GameCorner_Text_CoinCaseIsFull::
# 125 "data/maps/CeladonCity_GameCorner/scripts.pory"
	.string "Whoops!\n"
	.string "Your COIN CASE is full.$"

CeladonCity_GameCorner_Text_CantAffordCoins::
# 129 "data/maps/CeladonCity_GameCorner/scripts.pory"
	.string "You can't afford the COINS.$"

CeladonCity_GameCorner_Text_HereAreYourCoins::
# 133 "data/maps/CeladonCity_GameCorner/scripts.pory"
	.string "Thank you.\n"
	.string "Here are your COINS!$"

CeladonCity_GameCorner_Text_RumoredTeamRocketRunsThisPlace::
# 246 "data/maps/CeladonCity_GameCorner/scripts.pory"
	.string "Keep this quiet.\p"
	.string "It's rumored that this place is run\n"
	.string "by TEAM ROCKET.$"

CeladonCity_GameCorner_Text_ThinkMachinesHaveDifferentOdds::
# 250 "data/maps/CeladonCity_GameCorner/scripts.pory"
	.string "I think these machines have\n"
	.string "different odds.$"

CeladonCity_GameCorner_Text_DoYouWantToPlay::
# 254 "data/maps/CeladonCity_GameCorner/scripts.pory"
	.string "Kid, do you want to play?$"

CeladonCity_GameCorner_Text_Received10CoinsFromMan::
# 258 "data/maps/CeladonCity_GameCorner/scripts.pory"
	.string "{PLAYER} received 10 COINS\n"
	.string "from the man.$"

CeladonCity_GameCorner_Text_DontNeedMyCoins::
# 262 "data/maps/CeladonCity_GameCorner/scripts.pory"
	.string "You don't need my COINS!$"

CeladonCity_GameCorner_Text_WinsComeAndGo::
# 266 "data/maps/CeladonCity_GameCorner/scripts.pory"
	.string "Wins seem to come and go.\n"
	.string "Nothing's a sure thing.$"

CeladonCity_GameCorner_Text_WinOrLoseItsOnlyLuck::
# 270 "data/maps/CeladonCity_GameCorner/scripts.pory"
	.string "These slot games…\n"
	.string "Win or lose, it's only by luck.$"

CeladonCity_GameCorner_Text_GymGuyAdvice::
# 274 "data/maps/CeladonCity_GameCorner/scripts.pory"
	.string "Hey!\p"
	.string "You have better things to do,\n"
	.string "champ in the making!\p"
	.string "CELADON GYM's LEADER is ERIKA.\p"
	.string "She is a user of GRASS-type\n"
	.string "POKéMON, and at one with nature.\p"
	.string "She might appear docile because of\n"
	.string "her flower arranging…\p"
	.string "But she's not one to be taken\n"
	.string "lightly!$"

CeladonCity_GameCorner_Text_RareMonsForCoins::
# 287 "data/maps/CeladonCity_GameCorner/scripts.pory"
	.string "They offer rare POKéMON that can\n"
	.string "be exchanged for your COINS.\p"
	.string "But, I just can't seem to win!$"

CeladonCity_GameCorner_Text_SoEasyToGetHooked::
# 293 "data/maps/CeladonCity_GameCorner/scripts.pory"
	.string "Games are scary!\n"
	.string "It's so easy to get hooked!$"

CeladonCity_GameCorner_Text_WantSomeCoins::
# 298 "data/maps/CeladonCity_GameCorner/scripts.pory"
	.string "What's up?\n"
	.string "Want some COINS?$"

CeladonCity_GameCorner_Text_HereAreSomeCoinsShoo::
# 303 "data/maps/CeladonCity_GameCorner/scripts.pory"
	.string "Hey, what? You're throwing me off!\n"
	.string "Here are some COINS, so shoo!$"

CeladonCity_GameCorner_Text_Poster::
# 314 "data/maps/CeladonCity_GameCorner/scripts.pory"
	.string "It's just a normal poster.\n"
	.string "Did you expect something here?$"

CeladonCity_GameCorner_Text_SwitchBehindTreePushIt::
# 345 "data/maps/CeladonCity_GameCorner/scripts.pory"
	.string "Hey!\p"
	.string "A switch inside the tree!?\n"
	.string "Gotta push it!$"

CeladonCity_GameCorner_Text_YoungGruntBeforeSwitch::
# 378 "data/maps/CeladonCity_GameCorner/scripts.pory"
	.string "Huh? This tree? Ah, yes!\n"
	.string "This tree is absolutely normal!$"

CeladonCity_GameCorner_Text_YoungGruntAfterSwitch::
# 383 "data/maps/CeladonCity_GameCorner/scripts.pory"
	.string "What? Why did you do that?\n"
	.string "I mean, nothing. Hahaha.$"
