#include <algorithm>
#include "sim_stack.h"
#include "sim_part.h"
#include "sim_card.h"

bool sim_stack::is_full()
{
	//if (active_stacks.size() == card->get_max_stacks())
	//	return true;
	return false;
}

bool sim_stack::empty()
{
	return active_stacks.empty();
}

void sim_stack::add_stack(int tap)
{
	active_stacks.push_back(tap);
}

void sim_stack::remove_first()
{
	active_stacks.erase(active_stacks.begin());
}

void sim_stack::remove_stacks(int tap)
{
	auto it = std::remove_if(active_stacks.begin(), active_stacks.end(),
		[tap](int a) {
			if (a <= tap)
				return true;
			return false;
		});
	active_stacks.erase(it, active_stacks.end());
}

double sim_stack::calculate_dmg(double base_dmg, int tap)
{
	if (size() == 0)
		return 0.;
	double dmg = card->calculate_damage(part, tap, base_dmg);
	total_dmg += dmg;
	return dmg;
}

double sim_stack::get_dmg()
{
	return total_dmg;
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

void sim_stack::set_stacks(int tap)
{
	active_stacks.assign(active_stacks.size(), tap);
}

card_name sim_stack::get_name()
{
	return card->get_name();
}

int sim_stack::get_first()
{
	return active_stacks.front();
}
