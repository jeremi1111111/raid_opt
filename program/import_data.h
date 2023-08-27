#pragma once
#include <string>
#include "player_info.h"

void create_indexes();
void import_cards(std::string filename);
void import_player(std::string filename);
void import_titans(std::string filename);
void import_areas(std::string filename);
player_info* input_player_info();