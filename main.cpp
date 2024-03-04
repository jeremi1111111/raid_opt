#include <iostream>
#include <fstream>
#include <numeric>
#include <chrono>
#include "game_info/card_info_t.h"
#include "game_info/player_card_t.h"
#include "game_info/titan_info_t.h"
#include "game_info/area_info_t.h"
#include "program/import_data.h"
#include "program/simulation.h"

void statistics(const std::vector<double>& results)
{
	double r_avg = std::accumulate(results.begin(), results.end(), 0.) / results.size();
	std::cout << "results\navg: " << r_avg << "\tmin: " << results.front() << "\tmax: " << results.back() << '\n';

	double diff = (results.back() - results.front()) / 10;
	double threshold = results.front() + diff;
	int counter = 0;
	for (double r : results)
	{
		if (r < threshold || threshold + diff > results.back())
		{
			counter++;
			continue;
		}
		std::cout << (double) counter / results.size() * 100. << "%\t";
		counter = 0;
		threshold += diff;
	}

	auto c_begin = results.begin() + results.size() / 10;
	auto c_end = results.end() - results.size() / 10;
	double c_size = results.size() * 0.8;
	double c_avg = std::accumulate(c_begin, c_end, 0.) / c_size;
	std::cout << "\ncropped (80%)\navg: " << c_avg << "\tmin: " << *c_begin << "\tmax: " << *c_end << '\n';
}

// number save format:
// false - '.'
// true - ','
void save_results(std::vector<double>& results, bool format = false, std::string filename = "results_dump.txt")
{
	std::fstream save_file;
	save_file.open(filename, std::ios::out);
	for (double r : results)
	{
		std::string r_s = std::to_string(r);
		if (format)
			r_s = r_s.replace(r_s.find('.'), 1, ",");
		save_file << r_s << '\n';
	}
	save_file.close();
	std::cout << "\nSaved " << results.size() << " results to \"" << filename << "\".\n";
}

int main()
{
	import_cards("data_csv/RaidSkillInfo.csv");
	import_player("data_csv/export_sample_21_08.txt");
	import_titans("data_csv/RaidEnemyInfo.csv");
	import_areas("data_csv/RaidAreaInfo.csv");
	std::cout << '\n';
	std::vector<double> results;
	int sim_cycles = 100;
	auto start = std::chrono::steady_clock::now();
	for (int i = 0; i < sim_cycles; i++)
		results.push_back(simulate());
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> time = end - start;
	std::cout << time.count() << " seconds\n";
	std::sort(results.begin(), results.end());
	statistics(results);
	//save_results(results);
	//return 0;
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
	//for (card_info_t* ci : cards)
	//	std::cout << ci->name << '\n';
	//std::vector<sim_deck*> decks = deck_order();
	//std::cout << decks.size();
	//player_card_t* c = nullptr;
	//for (player_card_t* card : player_cards)
	//	if (card->card_data->name == "Skull Bash")
	//	{
	//		c = card;
	//		break;
	//	}
	//std::cout << /*794 * 1.01 * 1.04 * */c->calculate_support(true, 0) << '\n';
	//std::cout << c->calculate_damage(1, 1, false, 0) * 794 * 1.01 * 1.04 << '\n';
}