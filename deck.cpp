#include "deck.h"

deck::deck(player_card_info* c1, player_card_info* c2, player_card_info* c3)
{
	this->card_1 = c1;
	this->card_2 = c2;
	this->card_3 = c3;
	this->total = 0.;
}