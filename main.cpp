#include "import_data.h"
#include "simulation.h"

std::vector<card_info*> cards;
std::vector<int> card_cost;
std::vector<int> dust_cost;
std::map<std::string, int> indexes;
std::vector<player_card_info*> player_info;

int main()
{
	import_cards("RaidSkillInfo.csv");
	import_player("export_sample_26_06.txt");
	std::vector<deck*> decks = deck_order();
	//std::cout << decks.size();
	player_card_info* c = nullptr;
	for (player_card_info* card : player_info)
		if (card->name == "Skull Bash")
		{
			c = card;
			break;
		}
	//std::cout << /*794 * 1.01 * 1.04 * */calculate_support(c, false, 1) << '\n';
	std::cout << calculate_damage(c, 1, 1, false, 0) * 794 * 1.01 * 1.04 << '\n';
}