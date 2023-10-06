CeladonCity_EventScript_LeftTrigger::
	lockall
	fadenewbgm MUS_ROCKET_HIDEOUT
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, CeladonCity_Movement_ToEventSpotLeft
	waitmovement 0
	call CeladonCity_EventScript_MainEvent
	fadedefaultbgm
	applymovement OBJ_EVENT_ID_CAMERA, CeladonCity_Movement_FromEventSpotLeft
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_MAP_SCENE_CELADON_CITY_ROCKET, 2
	releaseall
	end


CeladonCity_EventScript_RightTrigger1::
	lockall
	fadenewbgm MUS_ROCKET_HIDEOUT
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, CeladonCity_Movement_ToEventSpotRight1
	waitmovement 0
	call CeladonCity_EventScript_MainEvent
	fadedefaultbgm
	applymovement OBJ_EVENT_ID_CAMERA, CeladonCity_Movement_FromEventSpotRight1
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_MAP_SCENE_CELADON_CITY_ROCKET, 2
	releaseall
	end


CeladonCity_EventScript_RightTrigger2::
	lockall
	fadenewbgm MUS_ROCKET_HIDEOUT
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, CeladonCity_Movement_ToEventSpotRight2
	waitmovement 0
	call CeladonCity_EventScript_MainEvent
	fadedefaultbgm
	applymovement OBJ_EVENT_ID_CAMERA, CeladonCity_Movement_FromEventSpotRight2
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_MAP_SCENE_CELADON_CITY_ROCKET, 2
	releaseall
	end


CeladonCity_EventScript_RightTrigger3::
	lockall
	fadenewbgm MUS_ROCKET_HIDEOUT
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, CeladonCity_Movement_ToEventSpotRight3
	waitmovement 0
	call CeladonCity_EventScript_MainEvent
	fadedefaultbgm
	applymovement OBJ_EVENT_ID_CAMERA, CeladonCity_Movement_FromEventSpotRight3
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_MAP_SCENE_CELADON_CITY_ROCKET, 2
	releaseall
	end


CeladonCity_EventScript_MainEvent::
	opendoor 27, 38
	waitdooranim
	addobject 1
	applymovement 1, Common_Movement_WalkDown
	waitmovement 0
	closedoor 27, 38
	waitdooranim
	applymovement 1, CeladonCity_Movement_AirikaLeft
	waitmovement 0
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox CeladonCity_Text_AirikaWhereAreThey
	closemessage
	delay 30
	opendoor 13, 38
	waitdooranim
	addobject 2
	applymovement 2, Common_Movement_WalkDown
	waitmovement 0
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamLeft
	applymovement 2, Common_Movement_WalkRight
	addobject 3
	applymovement 3, Common_Movement_WalkDown
	waitmovement 0
	closedoor 13, 38
	waitdooranim
	applymovement 1, CeladonCity_Movement_AirikaLeft2
	applymovement 2, CeladonCity_Movement_Rocket1ToAirika
	applymovement 3, CeladonCity_Movement_Rocket2ToAirika
	waitmovement 0
	msgbox CeladonCity_Text_AirikaAboutTime
	closemessage
	delay 30
	applymovement 2, Common_Movement_WalkInPlaceRight
	waitmovement 0
	textcolor NPC_TEXT_COLOR_MALE
	msgbox CeladonCity_Text_Rocket1DelayReason
	closemessage
	delay 30
	textcolor NPC_TEXT_COLOR_FEMALE
	applymovement 1, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox CeladonCity_Text_AirikaGoodNews
	closemessage
	applymovement 2, Common_Movement_WalkInPlaceRight
	applymovement 3, Common_Movement_WalkInPlaceRight
	textcolor NPC_TEXT_COLOR_MALE
	msgbox CeladonCity_Text_YesMaam
	closemessage
	applymovement 2, CeladonCity_Movement_Rocket1ToDoor
	applymovement 1, CeladonCity_Movement_AirikaToDoor
	applymovement 3, CeladonCity_Movement_Rocket2ToDoor
	waitmovement 0
	opendoor 13, 38
	waitdooranim
	applymovement 2, CeladonCity_Movement_Rocket1EnterDoor
	applymovement 1, CeladonCity_Movement_AirikaEnterDoor
	applymovement 3, CeladonCity_Movement_Rocket2EnterDoor
	waitmovement 0
	closedoor 13, 38
	waitdooranim
	return


CeladonCity_Movement_AirikaLeft:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_16
	walk_in_place_down
	delay_16
	walk_in_place_right
	delay_16
	walk_in_place_left
	delay_16
	step_end

CeladonCity_Movement_AirikaLeft2:
	walk_left
	walk_left
	step_end

CeladonCity_Movement_Rocket1ToAirika:
	walk_right
	walk_right
	walk_right
	step_end

CeladonCity_Movement_Rocket2ToAirika:
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

CeladonCity_Movement_Rocket1ToDoor:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

CeladonCity_Movement_AirikaToDoor:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

CeladonCity_Movement_Rocket2ToDoor:
	delay_16
	delay_16
	walk_up
	walk_left
	step_end

CeladonCity_Movement_Rocket1EnterDoor:
	walk_up
	set_invisible
	step_end

CeladonCity_Movement_AirikaEnterDoor:
	walk_left
	walk_up
	set_invisible
	step_end

CeladonCity_Movement_Rocket2EnterDoor:
	walk_left
	walk_left
	walk_up
	set_invisible
	step_end

CeladonCity_Movement_ToEventSpotLeft:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

CeladonCity_Movement_FromEventSpotLeft:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

CeladonCity_Movement_ToEventSpotRight1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

CeladonCity_Movement_FromEventSpotRight1:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

CeladonCity_Movement_ToEventSpotRight2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

CeladonCity_Movement_FromEventSpotRight2:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

CeladonCity_Movement_ToEventSpotRight3:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

CeladonCity_Movement_FromEventSpotRight3:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

CeladonCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_OnTransition
	.byte 0

CeladonCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_CELADON_CITY
	end

CeladonCity_EventScript_LittleGirl::
	msgbox CeladonCity_Text_GotMyKoffingInCinnabar, MSGBOX_NPC
	end

CeladonCity_EventScript_OldMan1::
	lock
	msgbox CeladonCity_Text_GymIsGreatFullOfWomen
	release
	end

CeladonCity_EventScript_Woman::
	msgbox CeladonCity_Text_GameCornerIsBadForCitysImage, MSGBOX_NPC
	end

CeladonCity_EventScript_OldMan2::
	msgbox CeladonCity_Text_BlewItAllAtSlots, MSGBOX_NPC
	end

CeladonCity_EventScript_SoftboiledTutor::
	goto EventScript_SoftboiledTutor
	end

CeladonCity_EventScript_FatMan::
	lock
	faceplayer
	msgbox CeladonCity_Text_MyTrustedPalPoliwrath
	closemessage
	applymovement 1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

CeladonCity_EventScript_Poliwrath::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWRATH, CRY_MODE_NORMAL
	msgbox CeladonCity_Text_Poliwrath
	closemessage
	waitmoncry
	applymovement 2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

CeladonCity_EventScript_RocketGrunt1::
	msgbox CeladonCity_Text_KeepOutOfTeamRocketsWay, MSGBOX_NPC
	end

CeladonCity_EventScript_RocketGrunt2::
	msgbox CeladonCity_Text_GetLostOrIllPunchYou, MSGBOX_NPC
	end

CeladonCity_EventScript_Boy::
	msgbox CeladonCity_Text_ScaldedTongueOnTea, MSGBOX_NPC
	end

CeladonCity_EventScript_SilphCoScientist::
	msgbox CeladonCity_Text_SomeoneStoleSilphScope, MSGBOX_NPC
	end

CeladonCity_EventScript_TrainerTips1::
	msgbox CeladonCity_Text_ExplainXAccuracyDireHit, MSGBOX_SIGN
	end

CeladonCity_EventScript_CitySign::
	msgbox CeladonCity_Text_CitySign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GymSign::
	lockall
	famechecker FAMECHECKER_ERIKA, 0
	msgbox CeladonCity_Text_GymSign
	releaseall
	end

CeladonCity_EventScript_MansionSign::
	msgbox CeladonCity_Text_MansionSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_DeptStoreSign::
	msgbox CeladonCity_Text_DeptStoreSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_TrainerTips2::
	msgbox CeladonCity_Text_GuardSpecProtectsFromStatus, MSGBOX_SIGN
	end

CeladonCity_EventScript_PrizeExchangeSign::
	msgbox CeladonCity_Text_PrizeExchangeSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GameCornerSign::
	msgbox CeladonCity_Text_GameCornerSign, MSGBOX_SIGN
	end

CeladonCity_Text_AirikaWhereAreThey::
	.string "AIRIKA: They're late!\nWhat could be keeping them?$"

CeladonCity_Text_AirikaAboutTime::
	.string "AIRIKA: It's about time!\nWhat kept you so long?$"

CeladonCity_Text_Rocket1DelayReason::
	.string "MAN 1: Well, boss, you see...\nThe protoypes have been completed.\pWe were all watching the new\nlifeforms demonstrate their\labilities.$"

CeladonCity_Text_AirikaGoodNews::
	.string "AIRIKA: Ah, so the doctor finally\nsucceeded, did he?\pTake me at once! I wish to see one\nof these prototypes for myself.\p"
	.string "But make sure to cover your tracks!\nProtect your switches!$"

CeladonCity_Text_YesMaam::
	.string "MAN 1 & 2: Yes ma'am!$"
