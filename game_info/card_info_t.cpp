#include "card_info_t.h"

double card_info_t::get_bonus_amount(char c, int level)
{
	switch (c)
	{
	case 'a':
		return bonus_amount_vec[level];
	case 'b':
		return bonus_amount_vec[80+level];
	case 'c':
		return bonus_amount_vec[160];
	case 'd':
		return bonus_amount_vec[161];
	case 'e':
		return bonus_amount_vec[162];
	default:
		return 0.0;
	}
}
