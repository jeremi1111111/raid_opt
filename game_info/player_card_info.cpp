// THIS FILE SHOULD BE DELETED, but just for now i wanna keep it because of the formulas below

//#include "player_card_t.h"

//player_card_t::player_card_t(std::string& nam, int lvl, int cds)
//{
//	auto it = card_names.find(nam);
//	if (it != card_names.end())
//		this->index = (*it).second;
//	else
//		this->index = -1;
//	this->level = lvl;
//	this->card_shards = cds;
//}

//bool player_card_t::roll(double modifier, int counter)
//{
//	double roll_chance = this->card_data->chance;
//	if (counter)
//	{
//		if (this->card_data->name == "Whip Of Lightning")
//			roll_chance += std::min(this->card_data->bonus_amount_b[level - 1] * (double)counter, this->card_data->bonus_amount_c);
//		else if (this->card_data->name == "Blazing Inferno")
//			roll_chance += this->card_data->bonus_amount_c * (double)counter;
//	}
//	if (dist(rng) < roll_chance * modifier)
//		return true;
//	return false;
//}
//
//double player_card_t::calculate_damage(double modifier, int counter_multiplicative, bool flag_b, int counter_additive)
//{
//	if (modifier <= 0.)
//		return 0.;
//	double damage = card_data->bonus_amount_a[level - 1] * modifier;
//	if (counter_additive)
//		return damage * (1. + card_data->bonus_amount_c * (double)counter_additive);
//	damage *= std::pow(card_data->bonus_amount_c, counter_multiplicative);
//	if (flag_b)
//		damage *= card_data->bonus_amount_b[level - 1];
//	return damage;
//}
//
//double player_card_t::calculate_support(double modifier, bool flag_a, int counter)
//{
//	if (modifier <= 0.)
//		return 1.;
//	double support = 1.;
//	if (flag_a)
//		support += card_data->bonus_amount_a[level - 1] + card_data->bonus_amount_b[level - 1] * (double)counter;
//	else
//	{
//		support += card_data->bonus_amount_a[level - 1] * (double)counter;
//		if (!counter)
//			support += card_data->bonus_amount_b[level - 1];
//	}
//	return support;
//}

// if results don't match, each calculation should be rounded to 2 decimal points

