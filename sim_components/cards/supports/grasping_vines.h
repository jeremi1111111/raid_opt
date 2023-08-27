#pragma once
#include "../support.h"

class grasping_vines : public support
{
public:
	double limb_sup_adt;
	grasping_vines(sim_deck* deck, int deck_index);
};