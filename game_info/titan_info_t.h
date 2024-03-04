#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "enumerables.h"

typedef std::vector<std::string> string_vector;
typedef std::vector<double> double_vector;

class titan_info_t
{
public:
	const enemy_id name;
	const double_vector body_multipliers;
	const double_vector armor_multipliers;
	const string_vector bonus_type_names;
	const double_vector bonus_amounts;

	titan_info_t(const enemy_id& name, double_vector& bm, double_vector& am, string_vector& btn, double_vector& ba)
		: name(name), body_multipliers(bm), armor_multipliers(am), bonus_type_names(btn), bonus_amounts(ba)
	{}

	double get_body_mult(const part_name& part);
	double get_armor_mult(const part_name& part);
};

extern std::unordered_map<std::string, enemy_id> titan_names;
extern std::vector<titan_info_t*> titans;