#pragma once
#include <vector>
#include <random>
#include "../game_info/enumerables.h"

class sim_deck;

std::vector<sim_deck*> deck_order(std::vector<card_name> chosen_cards);

extern std::random_device rd;
extern std::mt19937 rng;
extern std::uniform_real_distribution<double> dist;
//extern std::uniform_int_distribution<int> fairy_spawner;