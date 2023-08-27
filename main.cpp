#include "game_info/card_info.h"
#include "game_info/player_card_info.h"
#include "game_info/titan_info.h"
#include "game_info/area_info.h"
#include "program/import_data.h"

std::vector<card_info*> cards;
std::vector<int> card_cost;
std::vector<int> dust_cost;
std::unordered_map<std::string, card_name> card_names;
std::unordered_map<std::string, card_category> card_categories;
std::unordered_map<std::string, enemy_id> titan_names;
std::unordered_map<std::string, area_id> area_ids;
std::vector<player_card_info*> player_cards;
std::vector<titan_info*> titans;
std::vector<area_info*> areas;

std::random_device rd;
std::mt19937 rng(rd());
std::uniform_real_distribution<double> dist(0., 1.);

int main()
{
	create_indexes();
	import_cards("data_csv/RaidSkillInfo.csv");
	import_player("data_csv/export_sample_21_08.txt");
	import_titans("data_csv/RaidEnemyInfo.csv");
	import_areas("data_csv/RaidAreaInfo.csv");
	//player_info* player = input_player_info();
	//sim_part* sp = new sim_part(nullptr, part_name::head);
	//sim_card* sc = new moon_beam(card_name::moon_beam, nullptr, 0);
	//std::cout << sc->calculate_dmg(812 * 1.06) * 4;
	//std::cout << sc->calculate_dmg(sp);
	//while (!sc->roll(sp))
	//	std::cout << "reroll\n";
	//sim_card* mb = new moon_beam(0);
	//mb->calculate_dmg();
	//for (card_info* ci : cards)
	//	std::cout << ci->name << '\n';
	//std::vector<sim_deck*> decks = deck_order();
	//std::cout << decks.size();
	//player_card_info* c = nullptr;
	//for (player_card_info* card : player_cards)
	//	if (card->card_data->name == "Skull Bash")
	//	{
	//		c = card;
	//		break;
	//	}
	//std::cout << /*794 * 1.01 * 1.04 * */c->calculate_support(true, 0) << '\n';
	//std::cout << c->calculate_damage(1, 1, false, 0) * 794 * 1.01 * 1.04 << '\n';
}