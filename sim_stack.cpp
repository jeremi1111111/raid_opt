#include "sim_stack.h"

sim_stack::sim_stack(sim_card* card)
{
	this->card = card;
	this->total_stack_count = 0;
}
