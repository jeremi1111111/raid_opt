#include "deck.h"

deck::deck(player_card_info* c1, player_card_info* c2, player_card_info* c3)
{
	this->deck_cards = { c1, c2, c3 };
	this->total_damage = 0.;
}