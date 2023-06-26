#include "card_info.h"
#include "import_cards.h"

std::vector<card_info*> cards;

int main()
{
	import_cards("RaidSkillInfo.csv");
	return 0;
}