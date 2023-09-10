#pragma once
#include <string>
#include <unordered_map>
#include <random>
#include "enumerables.h"

class card_info
{
public:
	const card_name name;
	const card_category category;
	const int max_stacks;
	const double duration;
	const double chance;
	const double max_chance;
	const std::string bonus_type_a;
	const std::string bonus_type_b;
	const std::string bonus_type_c;
	const std::string bonus_type_d;
	const std::string bonus_type_e;
	const std::vector<double> bonus_amount_a;
	const std::vector<double> bonus_amount_b;
	const double bonus_amount_c;
	const double bonus_amount_d;
	const double bonus_amount_e;

	card_info(const card_name& name, const card_category& category, int max_stacks, double duration, double chance, double max_chance, const std::string& bonus_type_a, const std::string& bonus_type_b, const std::string& bonus_type_c, const std::string& bonus_type_d, const std::string& bonus_type_e, const std::vector<double>& bonus_amount_a, const std::vector<double>& bonus_amount_b, double bonus_amount_c, double bonus_amount_d, double bonus_amount_e)
		: name(name), category(category), max_stacks(max_stacks), duration(duration), chance(chance), max_chance(max_chance), bonus_type_a(bonus_type_a), bonus_type_b(bonus_type_b), bonus_type_c(bonus_type_c), bonus_type_d(bonus_type_d), bonus_type_e(bonus_type_e), bonus_amount_a(bonus_amount_a), bonus_amount_b(bonus_amount_b), bonus_amount_c(bonus_amount_c), bonus_amount_d(bonus_amount_d), bonus_amount_e(bonus_amount_e)
	{}
};

extern std::vector<card_info*> cards;
extern std::vector<int> card_cost;
extern std::vector<int> dust_cost;
extern std::unordered_map<std::string, card_name> card_names;
extern std::unordered_map<std::string, card_category> card_categories;