#include "declarations.h"
#include "import_data.h"
#include "simulation.h"
#include "sim_card.h"

std::vector<card_info*> cards;
std::vector<int> card_cost;
std::vector<int> dust_cost;
std::map<std::string, int> indexes;
std::vector<player_card_info*> player_info;

std::random_device rd;
std::mt19937 rng(rd());
std::uniform_real_distribution<double> dist(0., 1.);

int main()
{
	import_cards("RaidSkillInfo.csv");
	std::cout << cards.size() << '\n';
	std::cout << indexes.size() << '\n';
	import_player("export_sample_26_06.txt");
	std::cout << player_info.size() << '\n';
	sim_part* sp = new sim_part(nullptr, part_name::head);
	sim_card* sc = new chain_of_vengeance(indexes["chain_of_vengeance"]);
	std::cout << sc->calculate_dmg(sp);
	//while (!sc->roll(sp))
	//	std::cout << "reroll\n";
	//sim_card* mb = new moon_beam(0);
	//mb->calculate_dmg();
	//for (card_info* ci : cards)
	//	std::cout << ci->name << '\n';
	//std::vector<deck*> decks = deck_order();
	//std::cout << decks.size();
	//player_card_info* c = nullptr;
	//for (player_card_info* card : player_info)
	//	if (card->card_data->name == "Skull Bash")
	//	{
	//		c = card;
	//		break;
	//	}
	//std::cout << /*794 * 1.01 * 1.04 * */c->calculate_support(true, 0) << '\n';
	//std::cout << c->calculate_damage(1, 1, false, 0) * 794 * 1.01 * 1.04 << '\n';
}