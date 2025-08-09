CeladonCity_GameCorner_MapScripts::
# 2 "data/maps/CeladonCity_GameCorner/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, CeladonCity_GameCorner_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

CeladonCity_GameCorner_MapScripts_MAP_SCRIPT_ON_LOAD:
# 3 "data/maps/CeladonCity_GameCorner/scripts.pory"
	call_if_unset FLAG_OPENED_ROCKET_HIDEOUT, CeladonCity_GameCorner_EventScript_HideRocketHideout
	return


CeladonCity_GameCorner_EventScript_HideRocketHideout::
# 8 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setmetatile 15, 2, METATILE_GameCorner_Floor_ShadeFull, 0
# 9 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setmetatile 16, 2, METATILE_GameCorner_Floor_ShadeFull, 0
# 10 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setmetatile 17, 2, METATILE_GameCorner_Floor_ShadeFull, 0
# 11 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setmetatile 16, 3, METATILE_GameCorner_PurpleWall_Floor, 1
# 12 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setmetatile 17, 3, METATILE_GameCorner_PurpleWall_Floor, 1
	return


# 16 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 17 "data/maps/CeladonCity_GameCorner/scripts.pory"
.set LOCALID_GRUNT, 11
# 18 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 19 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_InfoClerk::
# 20 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_CanExchangeCoinsNextDoor, MSGBOX_NPC
# 21 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 22 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 23 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_CoinsClerk::
# 24 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 25 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lock
# 26 "data/maps/CeladonCity_GameCorner/scripts.pory"
	faceplayer
# 27 "data/maps/CeladonCity_GameCorner/scripts.pory"
	showmoneybox 0, 0
# 28 "data/maps/CeladonCity_GameCorner/scripts.pory"
	showcoinsbox 0, 5
# 29 "data/maps/CeladonCity_GameCorner/scripts.pory"
	message CeladonCity_GameCorner_Text_WelcomeBuySomeCoins
# 30 "data/maps/CeladonCity_GameCorner/scripts.pory"
	waitmessage
# 31 "data/maps/CeladonCity_GameCorner/scripts.pory"
	multichoice 13, 0, MULTICHOICE_GAME_CORNER_COIN_PURCHASE_COUNTER, FALSE
# 32 "data/maps/CeladonCity_GameCorner/scripts.pory"
	copyvar VAR_0x8009, VAR_RESULT
# 33 "data/maps/CeladonCity_GameCorner/scripts.pory"
	switch VAR_RESULT
# 34 "data/maps/CeladonCity_GameCorner/scripts.pory"
	case 0, CeladonCity_GameCorner_EventScript_BuyCoins
# 35 "data/maps/CeladonCity_GameCorner/scripts.pory"
	case 1, CeladonCity_GameCorner_EventScript_BuyCoins
# 36 "data/maps/CeladonCity_GameCorner/scripts.pory"
	case 2, CeladonCity_GameCorner_EventScript_ClerkDeclineBuy
# 37 "data/maps/CeladonCity_GameCorner/scripts.pory"
	case 127, CeladonCity_GameCorner_EventScript_ClerkDeclineBuy
# 38 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 39 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 40 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_BuyCoins::
# 41 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto_if_unset FLAG_GOT_COIN_CASE, CeladonCity_GameCorner_EventScript_ClerkNoCoinCase
# 42 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto_if_eq VAR_0x8009, 0, CeladonCity_GameCorner_EventScript_Buy50Coins
# 43 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto_if_eq VAR_0x8009, 1, CeladonCity_GameCorner_EventScript_Buy500Coins
# 44 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 45 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 46 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_Buy500Coins::
# 47 "data/maps/CeladonCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_1
# 48 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1) - 500, CeladonCity_GameCorner_EventScript_ClerkNoRoomForCoins
# 49 "data/maps/CeladonCity_GameCorner/scripts.pory"
	checkmoney 10000
# 50 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_EventScript_ClerkNotEnoughMoney
# 51 "data/maps/CeladonCity_GameCorner/scripts.pory"
	addcoins 500
# 52 "data/maps/CeladonCity_GameCorner/scripts.pory"
	removemoney 10000
# 53 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_BoughtCoins
# 54 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 55 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 56 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_Buy50Coins::
# 57 "data/maps/CeladonCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_1
# 58 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1) - 50, CeladonCity_GameCorner_EventScript_ClerkNoRoomForCoins
# 59 "data/maps/CeladonCity_GameCorner/scripts.pory"
	checkmoney 1000
# 60 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_EventScript_ClerkNotEnoughMoney
# 61 "data/maps/CeladonCity_GameCorner/scripts.pory"
	addcoins 50
# 62 "data/maps/CeladonCity_GameCorner/scripts.pory"
	removemoney 1000
# 63 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_BoughtCoins
# 64 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 65 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 66 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_BoughtCoins::
# 67 "data/maps/CeladonCity_GameCorner/scripts.pory"
	updatemoneybox
# 68 "data/maps/CeladonCity_GameCorner/scripts.pory"
	updatecoinsbox 0, 5
# 69 "data/maps/CeladonCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 70 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_HereAreYourCoins
# 71 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_ClerkEnd
# 72 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 73 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 74 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_ClerkEnd::
# 75 "data/maps/CeladonCity_GameCorner/scripts.pory"
	hidemoneybox
# 76 "data/maps/CeladonCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 77 "data/maps/CeladonCity_GameCorner/scripts.pory"
	release
# 78 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 79 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 80 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_ClerkDeclineBuy::
# 81 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_ComePlaySometime
# 82 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_ClerkEnd
# 83 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 84 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 85 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_ClerkNoCoinCase::
# 86 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_SorryDontHaveCoinCase
# 87 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_ClerkEnd
# 88 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 89 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 90 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_ClerkNoRoomForCoins::
# 91 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_CoinCaseIsFull
# 92 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_ClerkEnd
# 93 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 94 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 95 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_ClerkNotEnoughMoney::
# 96 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_CantAffordCoins
# 97 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_ClerkEnd
# 98 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 99 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 100 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_BaldingMan::
# 101 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lock
# 102 "data/maps/CeladonCity_GameCorner/scripts.pory"
	faceplayer
# 103 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_RumoredTeamRocketRunsThisPlace
# 104 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
# 105 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 106 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 107 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_FaceSlotMachine::
# 108 "data/maps/CeladonCity_GameCorner/scripts.pory"
	closemessage
# 109 "data/maps/CeladonCity_GameCorner/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 110 "data/maps/CeladonCity_GameCorner/scripts.pory"
	waitmovement 0
# 111 "data/maps/CeladonCity_GameCorner/scripts.pory"
	release
# 112 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 113 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 114 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_Woman1::
# 115 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lock
# 116 "data/maps/CeladonCity_GameCorner/scripts.pory"
	faceplayer
# 117 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_ThinkMachinesHaveDifferentOdds
# 118 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
# 119 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 120 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 121 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_Fisher::
# 122 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lock
# 123 "data/maps/CeladonCity_GameCorner/scripts.pory"
	faceplayer
# 124 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto_if_set FLAG_GOT_10_COINS_FROM_GAMBLER, CeladonCity_GameCorner_EventScript_FisherAlreadyGotCoins
# 125 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_DoYouWantToPlay
# 126 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto_if_unset FLAG_GOT_COIN_CASE, CeladonCity_GameCorner_EventScript_GamblerNoCoinCase
# 127 "data/maps/CeladonCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_1
# 128 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1) - 10, CeladonCity_GameCorner_EventScript_FisherNoRoomForCoins
# 129 "data/maps/CeladonCity_GameCorner/scripts.pory"
	addcoins 10
# 130 "data/maps/CeladonCity_GameCorner/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 131 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_Received10CoinsFromMan
# 132 "data/maps/CeladonCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 133 "data/maps/CeladonCity_GameCorner/scripts.pory"
	waitse
# 134 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setflag FLAG_GOT_10_COINS_FROM_GAMBLER
# 135 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
# 136 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 137 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 138 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_FisherNoRoomForCoins::
# 139 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_DontNeedMyCoins
# 140 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
# 141 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 142 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 143 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_GamblerNoCoinCase::
# 144 "data/maps/CeladonCity_GameCorner/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 145 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_DontHaveCoinCase
# 146 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
# 147 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 148 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 149 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_FisherAlreadyGotCoins::
# 150 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_WinsComeAndGo
# 151 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
# 152 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 153 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 154 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_GymGuy::
# 155 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lock
# 156 "data/maps/CeladonCity_GameCorner/scripts.pory"
	faceplayer
# 157 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto_if_set FLAG_DEFEATED_ERIKA, CeladonCity_GameCorner_EventScript_GymGuyPostVictory
# 158 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_GymGuyAdvice
# 159 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
# 160 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 161 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 162 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_GymGuyPostVictory::
# 163 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_RareMonsForCoins
# 164 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
# 165 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 166 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 167 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_Woman2::
# 168 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lock
# 169 "data/maps/CeladonCity_GameCorner/scripts.pory"
	faceplayer
# 170 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_WinOrLoseItsOnlyLuck
# 171 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
# 172 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 173 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 174 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_OldMan::
# 175 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lock
# 176 "data/maps/CeladonCity_GameCorner/scripts.pory"
	faceplayer
# 177 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_SoEasyToGetHooked
# 178 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
# 179 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 180 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 181 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_Scientist::
# 182 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lock
# 183 "data/maps/CeladonCity_GameCorner/scripts.pory"
	faceplayer
# 184 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto_if_set FLAG_GOT_20_COINS_FROM_GAMBLER, CeladonCity_GameCorner_EventScript_ScientistAlreadyGotCoins
# 185 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_WantSomeCoins
# 186 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto_if_unset FLAG_GOT_COIN_CASE, CeladonCity_GameCorner_EventScript_GamblerNoCoinCase
# 187 "data/maps/CeladonCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_1
# 188 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1) - 20, CeladonCity_GameCorner_EventScript_ScientistNoRoomForCoins
# 189 "data/maps/CeladonCity_GameCorner/scripts.pory"
	addcoins 20
# 190 "data/maps/CeladonCity_GameCorner/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 191 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_Received20CoinsFromNiceGuy
# 192 "data/maps/CeladonCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 193 "data/maps/CeladonCity_GameCorner/scripts.pory"
	waitse
# 194 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setflag FLAG_GOT_20_COINS_FROM_GAMBLER
# 195 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
# 196 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 197 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 198 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_ScientistNoRoomForCoins::
# 199 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_YouHaveLotsOfCoins
# 200 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
# 201 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 202 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 203 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_ScientistAlreadyGotCoins::
# 204 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_NeedMoreCoinsForMonIWant
# 205 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
# 206 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 207 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 208 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_Gentleman::
# 209 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lock
# 210 "data/maps/CeladonCity_GameCorner/scripts.pory"
	faceplayer
# 211 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto_if_set FLAG_GOT_20_COINS_FROM_GAMBLER_2, CeladonCity_GameCorner_EventScript_GentlemanAlreadyGotCoins
# 212 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_HereAreSomeCoinsShoo
# 213 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto_if_unset FLAG_GOT_COIN_CASE, CeladonCity_GameCorner_EventScript_GamblerNoCoinCase
# 214 "data/maps/CeladonCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_1
# 215 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1) - 20, CeladonCity_GameCorner_EventScript_GentlemanNoRoomForCoins
# 216 "data/maps/CeladonCity_GameCorner/scripts.pory"
	addcoins 20
# 217 "data/maps/CeladonCity_GameCorner/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 218 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_Received20CoinsFromMan
# 219 "data/maps/CeladonCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 220 "data/maps/CeladonCity_GameCorner/scripts.pory"
	waitse
# 221 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setflag FLAG_GOT_20_COINS_FROM_GAMBLER_2
# 222 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
# 223 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 224 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 225 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_GentlemanNoRoomForCoins::
# 226 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_YouveGotPlentyCoins
# 227 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
# 228 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 229 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 230 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_GentlemanAlreadyGotCoins::
# 231 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_WatchReelsClosely
# 232 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
# 233 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 234 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 235 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachine0::
# 236 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 237 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 0
# 238 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_SlotMachine
# 239 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 240 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 241 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_DontPlaySlotMachine::
# 242 "data/maps/CeladonCity_GameCorner/scripts.pory"
	releaseall
# 243 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 244 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 245 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachine::
# 246 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto_if_unset FLAG_GOT_COIN_CASE, CeladonCity_GameCorner_EventScript_SlotMachineNoCoinCase
# 247 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_SlotMachineWantToPlay, MSGBOX_YESNO
# 248 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, CeladonCity_GameCorner_EventScript_DontPlaySlotMachine
# 249 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setfieldeffectargument 0, OBJ_EVENT_ID_PLAYER
# 250 "data/maps/CeladonCity_GameCorner/scripts.pory"
.ifdef BUGFIX
# 251 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setfieldeffectargument 1, MAP_NUM(CELADON_CITY_GAME_CORNER)
# 252 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setfieldeffectargument 2, MAP_GROUP(CELADON_CITY_GAME_CORNER)
# 253 "data/maps/CeladonCity_GameCorner/scripts.pory"
.else
# 254 "data/maps/CeladonCity_GameCorner/scripts.pory"
	@ Map num/group were provided in the wrong order
# 255 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setfieldeffectargument 1, MAP_GROUP(CELADON_CITY_GAME_CORNER)
# 256 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setfieldeffectargument 2, MAP_NUM(CELADON_CITY_GAME_CORNER)
# 257 "data/maps/CeladonCity_GameCorner/scripts.pory"
.endif
# 258 "data/maps/CeladonCity_GameCorner/scripts.pory"
	dofieldeffect FLDEFF_SMILEY_FACE_ICON
# 259 "data/maps/CeladonCity_GameCorner/scripts.pory"
	waitfieldeffect FLDEFF_SMILEY_FACE_ICON
# 260 "data/maps/CeladonCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetRandomSlotMachineId
# 261 "data/maps/CeladonCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 262 "data/maps/CeladonCity_GameCorner/scripts.pory"
	releaseall
# 263 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 264 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 265 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachine1::
# 266 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 267 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 1
# 268 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_SlotMachine
# 269 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 270 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 271 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachine2::
# 272 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 273 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 2
# 274 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_SlotMachine
# 275 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 276 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 277 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachine3::
# 278 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 279 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 3
# 280 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_SlotMachine
# 281 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 282 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 283 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachine4::
# 284 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 285 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 4
# 286 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_SlotMachine
# 287 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 288 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 289 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachine5::
# 290 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 291 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 5
# 292 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_SlotMachine
# 293 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 294 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 295 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachine6::
# 296 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 297 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 6
# 298 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_SlotMachine
# 299 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 300 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 301 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachine7::
# 302 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 303 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 7
# 304 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_SlotMachine
# 305 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 306 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 307 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachine8::
# 308 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 309 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 8
# 310 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_SlotMachine
# 311 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 312 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 313 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachine9::
# 314 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 315 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 9
# 316 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_SlotMachine
# 317 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 318 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 319 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachine10::
# 320 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 321 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 10
# 322 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_SlotMachine
# 323 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 324 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 325 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachine11::
# 326 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 327 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 11
# 328 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_SlotMachine
# 329 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 330 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 331 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachine12::
# 332 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 333 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 12
# 334 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_SlotMachine
# 335 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 336 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 337 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachine13::
# 338 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 339 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 13
# 340 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_SlotMachine
# 341 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 342 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 343 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachine14::
# 344 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 345 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 14
# 346 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_SlotMachine
# 347 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 348 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 349 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachine15::
# 350 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 351 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 15
# 352 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_SlotMachine
# 353 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 354 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 355 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachine16::
# 356 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 357 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 16
# 358 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_SlotMachine
# 359 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 360 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 361 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachine17::
# 362 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 363 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 17
# 364 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_SlotMachine
# 365 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 366 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 367 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachine18::
# 368 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 369 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 18
# 370 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_SlotMachine
# 371 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 372 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 373 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachine19::
# 374 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 375 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 19
# 376 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_SlotMachine
# 377 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 378 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 379 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachine20::
# 380 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 381 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 20
# 382 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_SlotMachine
# 383 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 384 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 385 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachine21::
# 386 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 387 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 21
# 388 "data/maps/CeladonCity_GameCorner/scripts.pory"
	goto CeladonCity_GameCorner_EventScript_SlotMachine
# 389 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 390 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 391 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_SlotMachineNoCoinCase::
# 392 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_CoinCaseIsRequired
# 393 "data/maps/CeladonCity_GameCorner/scripts.pory"
	releaseall
# 394 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 395 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 396 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_Poster::
# 397 "data/maps/CeladonCity_GameCorner/scripts.pory"
	lockall
# 398 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_SwitchBehindPosterPushIt
# 399 "data/maps/CeladonCity_GameCorner/scripts.pory"
	call_if_unset FLAG_OPENED_ROCKET_HIDEOUT, CeladonCity_GameCorner_EventScript_OpenRocketHideout
# 400 "data/maps/CeladonCity_GameCorner/scripts.pory"
	releaseall
# 401 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 402 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 403 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_OpenRocketHideout::
# 404 "data/maps/CeladonCity_GameCorner/scripts.pory"
	playse SE_UNLOCK
# 405 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setmetatile 15, 2, METATILE_GameCorner_Floor_StairsTop, 0
# 406 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setmetatile 16, 2, METATILE_GameCorner_StairsTop, 1
# 407 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setmetatile 17, 2, METATILE_GameCorner_StairsBottom, 1
# 408 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setmetatile 16, 3, METATILE_GameCorner_PurpleWall_StairsTop, 1
# 409 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setmetatile 17, 3, METATILE_GameCorner_PurpleWall_stairsBottom, 1
# 410 "data/maps/CeladonCity_GameCorner/scripts.pory"
	special DrawWholeMapView
# 411 "data/maps/CeladonCity_GameCorner/scripts.pory"
	setflag FLAG_OPENED_ROCKET_HIDEOUT
# 412 "data/maps/CeladonCity_GameCorner/scripts.pory"
	return
# 413 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 414 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_RocketGrunt::
# 415 "data/maps/CeladonCity_GameCorner/scripts.pory"
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_7, CeladonCity_GameCorner_Text_GruntIntro, CeladonCity_GameCorner_Text_GruntDefeat, CeladonCity_GameCorner_Text_DefeatedGrunt
# 416 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_GruntPostBattle, MSGBOX_AUTOCLOSE
# 417 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 418 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 419 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_Text_DefeatedGrunt::
# 420 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_GruntPostBattle
# 421 "data/maps/CeladonCity_GameCorner/scripts.pory"
	closemessage
# 422 "data/maps/CeladonCity_GameCorner/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, CeladonCity_GameCorner_Text_GruntExitWest
# 423 "data/maps/CeladonCity_GameCorner/scripts.pory"
	call_if_ne VAR_FACING, DIR_WEST, CeladonCity_GameCorner_Text_GruntExit
# 424 "data/maps/CeladonCity_GameCorner/scripts.pory"
	removeobject LOCALID_GRUNT
# 425 "data/maps/CeladonCity_GameCorner/scripts.pory"
	release
# 426 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 427 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 428 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_Text_GruntExitWest::
# 429 "data/maps/CeladonCity_GameCorner/scripts.pory"
	applymovement LOCALID_GRUNT, CeladonCity_GameCorner_Movement_GruntExitWest
# 430 "data/maps/CeladonCity_GameCorner/scripts.pory"
	waitmovement 0
# 431 "data/maps/CeladonCity_GameCorner/scripts.pory"
	return
# 432 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 433 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_Text_GruntExit::
# 434 "data/maps/CeladonCity_GameCorner/scripts.pory"
	applymovement LOCALID_GRUNT, CeladonCity_GameCorner_Movement_GruntExit
# 435 "data/maps/CeladonCity_GameCorner/scripts.pory"
	waitmovement 0
# 436 "data/maps/CeladonCity_GameCorner/scripts.pory"
	return
# 437 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 438 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_Movement_GruntExitWest::
# 439 "data/maps/CeladonCity_GameCorner/scripts.pory"
	walk_down
# 440 "data/maps/CeladonCity_GameCorner/scripts.pory"
	walk_right
# 441 "data/maps/CeladonCity_GameCorner/scripts.pory"
	walk_right
# 442 "data/maps/CeladonCity_GameCorner/scripts.pory"
	walk_up
# 443 "data/maps/CeladonCity_GameCorner/scripts.pory"
	walk_right
# 444 "data/maps/CeladonCity_GameCorner/scripts.pory"
	walk_right
# 445 "data/maps/CeladonCity_GameCorner/scripts.pory"
	walk_right
# 446 "data/maps/CeladonCity_GameCorner/scripts.pory"
	walk_right
# 447 "data/maps/CeladonCity_GameCorner/scripts.pory"
	step_end
# 448 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 449 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_Movement_GruntExit::
# 450 "data/maps/CeladonCity_GameCorner/scripts.pory"
	walk_right
# 451 "data/maps/CeladonCity_GameCorner/scripts.pory"
	walk_right
# 452 "data/maps/CeladonCity_GameCorner/scripts.pory"
	walk_right
# 453 "data/maps/CeladonCity_GameCorner/scripts.pory"
	walk_right
# 454 "data/maps/CeladonCity_GameCorner/scripts.pory"
	walk_right
# 455 "data/maps/CeladonCity_GameCorner/scripts.pory"
	walk_right
# 456 "data/maps/CeladonCity_GameCorner/scripts.pory"
	step_end
# 457 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 458 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_UnusableSlotMachine1::
# 459 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_OutOfOrder, MSGBOX_SIGN
# 460 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 461 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 462 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_UnusableSlotMachine2::
# 463 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_OutToLunch, MSGBOX_SIGN
# 464 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
# 465 "data/maps/CeladonCity_GameCorner/scripts.pory"

# 466 "data/maps/CeladonCity_GameCorner/scripts.pory"
CeladonCity_GameCorner_EventScript_UnusableSlotMachine3::
# 467 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_SomeonesKeys, MSGBOX_SIGN
# 468 "data/maps/CeladonCity_GameCorner/scripts.pory"
	end
