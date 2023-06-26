#include "card_info.h"
#include "import_data.h"

std::vector<card_info*> cards;
std::vector<int> card_cost;
std::vector<int> dust_cost;
std::vector<player_card_info*> player_info;

int main()
{
	import_cards("RaidSkillInfo.csv");
	import_player("export_sample_26_06.txt");
}