#pragma once
#include <string>
#include <vector>

class card_info
{
public:
	std::string name, category;
	int max_stacks;
	double duration, chance, max_chance;
	std::string bonus_type_a, bonus_type_b, bonus_type_c, bonus_type_d, bonus_type_e;
	std::vector<double> bonus_amount_a, bonus_amount_b;
	double bonus_amount_c, bonus_amount_d, bonus_amount_e;
	card_info(
		std::string nam,
		std::string cat,
		int mst,
		double dur,
		double cha,
		double mch,
		std::string bta,
		std::string btb,
		std::string btc,
		std::string btd,
		std::string bte,
		std::vector<double> baa,
		std::vector<double> bab,
		double bac,
		double bad,
		double bae
	);
};
