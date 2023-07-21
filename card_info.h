#pragma once
#include <string>
#include <vector>
#include <map>
#include <random>

class card_info
{
public:
	std::string name;
	std::string category;
	int max_stacks;
	double duration;
	double chance;
	double max_chance;
	std::string bonus_type_a;
	std::string bonus_type_b;
	std::string bonus_type_c;
	std::string bonus_type_d;
	std::string bonus_type_e;
	std::vector<double> bonus_amount_a;
	std::vector<double> bonus_amount_b;
	double bonus_amount_c;
	double bonus_amount_d;
	double bonus_amount_e;
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

extern std::vector<card_info*> cards;
extern std::vector<int> card_cost;
extern std::vector<int> dust_cost;
extern std::map<std::string, int> indexes;

extern std::random_device rd;
extern std::mt19937 rng;
extern std::uniform_real_distribution<double> dist;
