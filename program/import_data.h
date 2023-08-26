#pragma once
#include <string>
//#include <vector>
//#include <algorithm>
#include <fstream>
#include <iostream>
#include "../game_info/enumerables.h"
#include "../game_info/card_info.h"
#include "../game_info/titan_info.h"
#include "../game_info/area_info.h"
#include "../game_info/player_card_info.h"
#include "player_info.h"

void create_indexes();
void import_cards(std::string filename);
void import_player(std::string filename);
void import_titans(std::string filename);
void import_areas(std::string filename);
player_info* input_player_info();