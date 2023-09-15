#include <iostream>
#include "acid_drench.h"

acid_drench::acid_drench(sim_deck* deck, int deck_index)
	: affliction(card_name::acid_drench, deck, deck_index)
{}

int acid_drench::calculate_expire_tap(sim_stack* stack, int tap)
{
	//std::cout << stack->size() << '\n';
	int expire_tap = tap + duration * 20;
	stack->set_stacks(expire_tap);
	return expire_tap;
}