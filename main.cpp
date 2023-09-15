#include <iostream>
#include "game_info/card_info.h"
#include "game_info/player_card_info.h"
#include "game_info/titan_info.h"
#include "game_info/area_info.h"
#include "program/import_data.h"
#include "sim_components/sim_card.h"

int main()
{
	//create_indexes();
	import_cards("data_csv/RaidSkillInfo.csv");
	import_player("data_csv/export_sample_21_08.txt");
	import_titans("data_csv/RaidEnemyInfo.csv");
	import_areas("data_csv/RaidAreaInfo.csv");
	double total = 0.;
	double min = 1e10;
	double max = 0.;
	for (int i = 0; i < 100; i++)
	{
		double dmg = simulate();
		total += dmg;
		if (dmg < min)
			min = dmg;
		else if (dmg > max)
			max = dmg;
	}
	std::cout << "avg: " << total / 100 << "\tmin: " << min << "\tmax: " << max << '\n';
	/*
	sim_part* part = new sim_part(nullptr, part_name::head);
	sim_card* sc = sim_card::sim_card_builder[1]();
	std::cout << sc->calculate_damage(part, 861);
	std::cout << "tap\tx\ty\tdelay\ttrig\tend\n";
	int counter = 0;
	for (int i = 0; i < 600; i++)
	{
		int res = sc->calculate_expire_tap(nullptr, i);
		if (res > -1)
			counter++;
	}
	std::cout << counter;
	*/
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