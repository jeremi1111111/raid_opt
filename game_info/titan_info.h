#pragma once
//#include <string>
//#include <unordered_map>
//#include <vector>
//#include "enumerables.h"

class titan_info
{
public:
	const enemy_id name;
	const double body_head_mult;
	const double body_torso_mult;
	const double body_arms_mult;
	const double body_legs_mult;
	const double armor_head_mult;
	const double armor_torso_mult;
	const double armor_arms_mult;
	const double armor_legs_mult;
	const std::string bonus_type_a;
	const std::string bonus_type_b;
	const std::string bonus_type_c;
	const std::string bonus_type_d;
	const std::string bonus_type_e;
	const std::string bonus_type_f;
	const std::string bonus_type_g;
	const std::string bonus_type_h;
	const double bonus_amount_a;
	const double bonus_amount_b;
	const double bonus_amount_c;
	const double bonus_amount_d;
	const double bonus_amount_e;
	const double bonus_amount_f;
	const double bonus_amount_g;
	const double bonus_amount_h;

	titan_info(const enemy_id& name, double body_head_mult, double body_torso_mult, double body_arms_mult, double body_legs_mult, double armor_head_mult, double armor_torso_mult, double armor_arms_mult, double armor_legs_mult, const std::string& bonus_type_a, const std::string& bonus_type_b, const std::string& bonus_type_c, const std::string& bonus_type_d, const std::string& bonus_type_e, const std::string& bonus_type_f, const std::string& bonus_type_g, const std::string& bonus_type_h, double bonus_amount_a, double bonus_amount_b, double bonus_amount_c, double bonus_amount_d, double bonus_amount_e, double bonus_amount_f, double bonus_amount_g, double bonus_amount_h)
		: name(name), body_head_mult(body_head_mult), body_torso_mult(body_torso_mult), body_arms_mult(body_arms_mult), body_legs_mult(body_legs_mult), armor_head_mult(armor_head_mult), armor_torso_mult(armor_torso_mult), armor_arms_mult(armor_arms_mult), armor_legs_mult(armor_legs_mult), bonus_type_a(bonus_type_a), bonus_type_b(bonus_type_b), bonus_type_c(bonus_type_c), bonus_type_d(bonus_type_d), bonus_type_e(bonus_type_e), bonus_type_f(bonus_type_f), bonus_type_g(bonus_type_g), bonus_type_h(bonus_type_h), bonus_amount_a(bonus_amount_a), bonus_amount_b(bonus_amount_b), bonus_amount_c(bonus_amount_c), bonus_amount_d(bonus_amount_d), bonus_amount_e(bonus_amount_e), bonus_amount_f(bonus_amount_f), bonus_amount_g(bonus_amount_g), bonus_amount_h(bonus_amount_h)
	{}
};

extern std::unordered_map<std::string, enemy_id> titan_names;
extern std::vector<titan_info*> titans;