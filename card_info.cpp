#include "card_info.h"

card_info::card_info(
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
) {
	this->name = nam;
	this->category = cat;
	this->max_stacks = mst;
	this->duration = dur;
	this->chance = cha;
	this->max_chance = mch;
	this->bonus_type_a = bta;
	this->bonus_amount_a = baa;
	this->bonus_type_b = btb;
	this->bonus_amount_b = bab;
	this->bonus_type_c = btc;
	this->bonus_amount_c = bac;
	this->bonus_type_d = btd;
	this->bonus_amount_d = bad;
	this->bonus_type_e = bte;
	this->bonus_amount_e = bae;
}