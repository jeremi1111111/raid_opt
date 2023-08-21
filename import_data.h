#pragma once
#include <string>
//#include <vector>
//#include <algorithm>
#include <fstream>
#include <iostream>
//#include "enumerables.h"
#include "card_info.h"
#include "titan_info.h"
#include "area_info.h"
#include "player_card_info.h"
#include "player_info.h"

void create_indexes();
void import_cards(std::string filename);
void import_player(std::string filename);
void import_titans(std::string filename);
void import_areas(std::string filename);
player_info* input_player_info();