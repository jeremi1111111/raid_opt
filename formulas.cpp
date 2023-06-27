#include "card_info.h"
#include "player_card_info.h"
#include "simulation.h"

double calculate_damage(player_card_info* card, double modifier, int counter_multiplicative, bool flag_b, int counter_additive)
{
	card_info* c = cards[indexes[card->name]];
	double damage = c->bonus_amount_a[card->level - 1] * modifier;
	if (counter_additive)
		return damage * (1. + c->bonus_amount_c * (double)counter_additive);
	damage *= std::pow(c->bonus_amount_c, counter_multiplicative);
	if (flag_b)
		damage *= c->bonus_amount_b[card->level - 1];
	return damage;
}

double calculate_support(player_card_info* card, bool flag_a, int counter)
{
	card_info* c = cards[indexes[card->name]];
	double support = 1.;
	//if (!flag)
	//	support += c->bonus_amount_a[card->level - 1];
	//else if (!counter)
	//	support += c->bonus_amount_b[card->level - 1];
	//if (counter)
	//{
	//	if (flag)
	//		support += c->bonus_amount_a[card->level - 1] * (double)counter;
	//	else
	//		support += c->bonus_amount_b[card->level - 1] * (double)counter;
	//}
	//return support;
	if (flag_a)
		support += c->bonus_amount_a[card->level - 1] + c->bonus_amount_b[card->level - 1] * (double)counter;
	else
	{
		support += c->bonus_amount_a[card->level - 1] * (double)counter;
		if (!counter)
			support += c->bonus_amount_b[card->level - 1];
	}
	return support;
}