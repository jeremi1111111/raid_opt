#pragma once
#include <iostream>
#include <cmath>
#include "card_info.h"
#include "player_card_info.h"
#include "sim_deck.h"
#include "sim_titan.h"

std::vector<deck*> deck_order(std::vector<player_card_info*> chosen_cards = player_info);