#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "card_info.h"
#include "player_card_info.h"

extern std::vector<card_info*> cards;
extern std::vector<int> card_cost;
extern std::vector<int> dust_cost;
extern std::vector<player_card_info*> player_info;

std::vector<std::string> csv_to_vector(std::string&);
void import_cards(std::string);
void import_player(std::string);