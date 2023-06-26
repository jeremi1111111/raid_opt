#include "player_card_info.h"

player_card_info::player_card_info(std::string nam, int lvl, int cds)
{
	this->name = nam;
	this->level = lvl;
	this->cards = cds;
}