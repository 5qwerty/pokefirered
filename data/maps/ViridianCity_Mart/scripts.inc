ViridianCity_Mart_MapScripts::
	.byte 0


ViridianCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	call_if_le VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 2, ViridianCity_Mart_EventScript_NoBallMart
	call_if_ge VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 3, ViridianCity_Mart_EventScript_BallMart
	msgbox Text_PleaseComeAgain
	release
	end


ViridianCity_Mart_EventScript_NoBallMart::
	pokemart ViridianCity_Mart_Items_NoBall
	return


ViridianCity_Mart_EventScript_BallMart::
	pokemart ViridianCity_Mart_Items
	return


	.align 2
ViridianCity_Mart_Items_NoBall:
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_REPEL
	.2byte ITEM_NONE

	.align 2
ViridianCity_Mart_Items:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_REPEL
	.2byte ITEM_NONE

ViridianCity_Mart_EventScript_Woman::
	msgbox ViridianCity_Mart_Text_ShopDoesGoodBusinessInAntidotes, MSGBOX_NPC
	end

ViridianCity_Mart_EventScript_Youngster::
	msgbox ViridianCity_Mart_Text_GotToBuySomePotions, MSGBOX_NPC
	end
