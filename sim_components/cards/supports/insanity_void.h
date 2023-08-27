#pragma once
#include "../support.h"

class insanity_void : public support
{
public:
	double all_sup_adt;
	double all_sup_adt_per_body_part;
	insanity_void(sim_deck* deck, int deck_index);
};