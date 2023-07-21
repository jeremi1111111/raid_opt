#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cctype>
#include "enumerates.h"
#include "card_info.h"
#include "player_card_info.h"

std::vector<std::string> csv_to_vector(std::string& f_buffer);
void import_cards(std::string filename);
void import_player(std::string filename);