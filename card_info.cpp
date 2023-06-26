#include "card_info.h"

card_info::card_info(
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
	double bae)
{
	this->name = nam;
	this->category = cat;
	this->max_stacks = mst;
	this->duration = dur;
	this->chance = cha;
	this->max_chance = mch;
	this->bonus_type_a = bta;
	this->bonus_type_b = btb;
	this->bonus_type_c = btc;
	this->bonus_type_d = btd;
	this->bonus_type_e = bte;
	this->bonus_amount_a = baa;
	this->bonus_amount_b = bab;
	this->bonus_amount_c = bac;
	this->bonus_amount_d = bad;
	this->bonus_amount_e = bae;
}