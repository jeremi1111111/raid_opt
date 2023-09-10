#include "sim_stack.h"
#include "sim_part.h"
#include "sim_card.h"

bool sim_stack::is_full()
{
	//if (active_stacks.size() == card->get_max_stacks())
	//	return true;
	return false;
}

bool sim_stack::is_empty()
{
	return active_stacks.empty();
}

void sim_stack::add_stack(int tap)
{
	active_stacks.push_back(tap);
}

void sim_stack::remove_first_stack()
{
	active_stacks.erase(active_stacks.begin());
}

int sim_stack::size()
{
	return active_stacks.size();
}

card_category sim_stack::get_category()
{
	return card->get_category();
}

sim_part* sim_stack::get_part()
{
	return part;
}
