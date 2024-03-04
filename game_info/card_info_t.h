#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <random>
#include "enumerables.h"

typedef std::vector<std::string> string_vector;
typedef std::vector<double> double_vector;

class card_info_t
{
public:
	const card_name name;
	const card_category category;
	const int max_stacks;
	const double duration;
	const double chance;
	const double max_chance;
	const string_vector bonus_type_vec;
	const double_vector bonus_amount_vec;

	card_info_t(const card_name& name, const card_category& category, int max_stacks, double duration, double chance, double max_chance, string_vector& btv, double_vector& bav)
		: name(name), category(category), max_stacks(max_stacks), duration(duration), chance(chance), max_chance(max_chance), bonus_type_vec(btv), bonus_amount_vec(bav)
	{}

	double get_bonus_amount(char c, int level = 0);
};

extern std::vector<card_info_t*> cards;
extern std::vector<int> card_cost;
extern std::vector<int> dust_cost;
extern std::unordered_map<std::string, card_name> card_names;
extern std::unordered_map<std::string, card_category> card_categories;