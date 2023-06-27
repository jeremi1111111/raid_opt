#pragma once
#include <iostream>
#include <cmath>
#include "card_info.h"
#include "player_card_info.h"
#include "deck.h"

std::vector<deck*> deck_order(std::vector<player_card_info*> = player_info);
double calculate_damage(player_card_info* card, double modifier, int counter_multiplicative, bool flag_b, int counter_additive);
double calculate_support(player_card_info* card, bool flag, int counter_aditive);