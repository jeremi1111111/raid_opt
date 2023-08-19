#pragma once
#include <string>
#include <vector>

class area_info
{
public:
	std::string area_id;
	std::string bonus_type_a;
	std::string bonus_type_b;
	std::string bonus_type_c;
	std::string bonus_type_d;
	std::string bonus_type_e;
	std::string bonus_type_f;
	std::string bonus_type_g;
	std::string bonus_type_h;
	std::string bonus_type_i;
	double bonus_amout_a;
	double bonus_amout_b;
	double bonus_amout_c;
	double bonus_amout_d;
	double bonus_amout_e;
	double bonus_amout_f;
	double bonus_amout_g;
	double bonus_amout_h;
	double bonus_amout_i;
	area_info(const std::string& area_id, const std::string& bonus_type_a, const std::string& bonus_type_b, const std::string& bonus_type_c, const std::string& bonus_type_d, const std::string& bonus_type_e, const std::string& bonus_type_f, const std::string& bonus_type_g, const std::string& bonus_type_h, const std::string& bonus_type_i, double bonus_amout_a, double bonus_amout_b, double bonus_amout_c, double bonus_amout_d, double bonus_amout_e, double bonus_amout_f, double bonus_amout_g, double bonus_amout_h, double bonus_amout_i)
		: area_id(area_id), bonus_type_a(bonus_type_a), bonus_type_b(bonus_type_b), bonus_type_c(bonus_type_c), bonus_type_d(bonus_type_d), bonus_type_e(bonus_type_e), bonus_type_f(bonus_type_f), bonus_type_g(bonus_type_g), bonus_type_h(bonus_type_h), bonus_type_i(bonus_type_i), bonus_amout_a(bonus_amout_a), bonus_amout_b(bonus_amout_b), bonus_amout_c(bonus_amout_c), bonus_amout_d(bonus_amout_d), bonus_amout_e(bonus_amout_e), bonus_amout_f(bonus_amout_f), bonus_amout_g(bonus_amout_g), bonus_amout_h(bonus_amout_h), bonus_amout_i(bonus_amout_i)
	{}
};

extern std::vector<area_info*> areas;