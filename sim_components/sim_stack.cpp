#include "sim_stack.h"

bool sim_stack::is_full()
{
	if (active_stacks.size() == card->get_max_stacks())
		return true;
	return false;
}

void sim_stack::add_stack(int expire_tap)
{
	active_stacks.push_back(expire_tap);
}

void sim_stack::remove_first_stack()
{
	active_stacks.erase(active_stacks.begin());
}

int sim_stack::size()
{
	return active_stacks.size();
}
