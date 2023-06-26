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
		std::vector<double> baa,
		std::string btb,
		std::vector<double> bab,
		std::string btc,
		double bac,
		std::string btd,
		double bad,
		std::string bte,
		double bae
	);
};

extern std::vector<card_info*> cards;