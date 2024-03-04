#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "enumerables.h"

typedef std::vector<std::string> string_vector;
typedef std::vector<double> double_vector;

class area_info_t
{
public:
	const static int BONUS_N;
	const area_id a_id;
	const string_vector bonus_type_vec;
	const double_vector bonus_amount_vec;

	area_info_t(const area_id& a_id, const string_vector& btv, const double_vector& bav)
		: a_id(a_id), bonus_type_vec(btv), bonus_amount_vec(bav)
	{}
};

extern std::unordered_map<std::string, area_id> area_ids;
extern std::vector<area_info_t*> areas;