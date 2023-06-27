#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <cmath>
#include "card_info.h"
#include "player_card_info.h"

std::vector<std::string> csv_to_vector(std::string&);
void import_cards(std::string);
void import_player(std::string);