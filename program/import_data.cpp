#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include "import_data.h"
#include "../game_info/enumerables.h"
#include "../game_info/card_info_t.h"
#include "../game_info/titan_info_t.h"
#include "../game_info/area_info_t.h"
#include "../game_info/player_card_t.h"

const int area_info_t::BONUS_N = 9;

typedef std::vector<std::string> string_vector;
typedef std::vector<double> double_vector;

std::vector<card_info_t*> cards;
std::vector<int> card_cost;
std::vector<int> dust_cost;
std::vector<player_card_t*> player_cards;
std::vector<titan_info_t*> titans;
std::vector<area_info_t*> areas;

std::unordered_map<std::string, card_name> card_names = {
	{ "moon_beam", card_name::moon_beam },
	{ "fragmentize", card_name::fragmentize },
	{ "skull_bash", card_name::skull_bash },
	{ "razor_wind", card_name::razor_wind },
	{ "whip_of_lightning", card_name::whip_of_lightning },
	{ "clanship_barrage", card_name::clanship_barrage },
	{ "purifying_blast", card_name::purifying_blast },
	{ "psychic_shackles", card_name::psychic_shackles },
	{ "flak_shot", card_name::flak_shot },
	{ "cosmic_haymaker", card_name::cosmic_haymaker },
	{ "chain_of_vengeance", card_name::chain_of_vengeance },
	{ "mirror_force", card_name::mirror_force },
	{ "celestial_static", card_name::celestial_static },
	{ "blazing_inferno", card_name::blazing_inferno },
	{ "acid_drench", card_name::acid_drench },
	{ "decaying_strike", card_name::decaying_strike },
	{ "fusion_bomb", card_name::fusion_bomb },
	{ "grim_shadow", card_name::grim_shadow },
	{ "thriving_plague", card_name::thriving_plague },
	{ "radioactivity", card_name::radioactivity },
	{ "ravenous_swarm", card_name::ravenous_swarm },
	{ "ruinous_rain", card_name::ruinous_rain },
	{ "corrosive_bubbles", card_name::corrosive_bubbles },
	{ "maelstrom", card_name::maelstrom },
	{ "crushing_instinct", card_name::crushing_instinct },
	{ "insanity_void", card_name::insanity_void },
	{ "rancid_gas", card_name::rancid_gas },
	{ "inspiring_force", card_name::inspiring_force },
	{ "soul_fire", card_name::soul_fire },
	{ "victory_march", card_name::victory_march },
	{ "prismatic_rift", card_name::prismatic_rift },
	{ "ancestral_favor", card_name::ancestral_favor },
	{ "grasping_vines", card_name::grasping_vines },
	{ "totem_of_power", card_name::totem_of_power },
	{ "team_tactics", card_name::team_tactics },
	{ "skeletal_smash", card_name::skeletal_smash },
	{ "astral_echo", card_name::astral_echo }
};

std::unordered_map<std::string, card_category> card_categories{
	{ "burst", card_category::burst},
	{ "affliction", card_category::affliction},
	{ "support", card_category::support}
};

std::unordered_map<std::string, enemy_id> titan_names = {
	{ "enemy1", enemy_id::lojak },
	{ "enemy2", enemy_id::takedar },
	{ "enemy3", enemy_id::jukk },
	{ "enemy4", enemy_id::sterl },
	{ "enemy5", enemy_id::mohaca },
	{ "enemy6", enemy_id::terro },
	{ "enemy7", enemy_id::klonk },
	{ "enemy8", enemy_id::priker }
};
std::unordered_map<std::string, area_id> area_ids = {
	{ "area1", area_id::area1 },
	{ "area2", area_id::area2 },
	{ "area3", area_id::area3 },
	{ "area4", area_id::area4 },
	{ "areaspecial1", area_id::areaspecial1 }
};

string_vector csv_to_vector(std::string& f_buffer)
{
	string_vector contents;
	size_t i1 = 0;
	while (i1 < f_buffer.size())
	{
		size_t i2 = f_buffer.find(',', i1);
		if (i2 == -1)
			i2 = f_buffer.size();
		size_t quote = f_buffer.find('\"', i1);
		if (quote != -1 && quote < i2)
			i2 = f_buffer.find('\"', quote + 1) + 1;
		contents.push_back(f_buffer.substr(i1, i2 - i1));
		i1 = i2 + 1;
	}
	return contents;
}

void string_to_lower_underscores(std::string& str)
{
	std::transform(str.begin(), str.end(), str.begin(),
		[](char c) {
			if (c == ' ') return '_';
			return (char)std::tolower(c);
		});
}

void import_cards(std::string filename)
{
	std::cout << "\nImporting card info from \"" << filename << "\".\n";
	std::string open_file_buffer = "";
	std::fstream open_file;
	open_file.open(filename, std::ios::in);
	std::getline(open_file, open_file_buffer);
	string_vector line;
	while (std::getline(open_file, open_file_buffer))
	{
		line = csv_to_vector(open_file_buffer);
		std::string nam = line[1];
		string_to_lower_underscores(nam);
		card_name c_nam;
		try
		{
			c_nam = card_names.at(nam);
		}
		catch (const std::exception&)
		{
			std::cout << "No card with given name (" << line[1] << ")\n";
			continue;
		}
		std::string cat = line[4];
		string_to_lower_underscores(cat);
		card_category c_cat;
		try
		{
			c_cat = card_categories.at(cat);
		}
		catch (const std::exception&)
		{
			std::cout << "No such category (" << line[4] << ")\n";
			continue;
		}
		int mst = std::stoi(line[8]);
		double dur = std::stod(line[9]);
		double cha = std::stod(line[10]);
		double mch = std::stod(line[11]);
		string_vector btv = {
			line[176], line[257], line[338], line[340], line[342]
		};
		double_vector bav;
		bav.reserve(163);
		string_vector::iterator it1 = line.begin() + 177;
		string_vector::iterator it2 = it1 + 80;
		while (it1 < it2)
			bav.push_back(std::stod(*(it1++)));
		it2 = ++it1 + 80;
		while (it1 < it2)
			bav.push_back(std::stod(*(it1++)));
		for (++it1; it1 < line.end(); it1 += 2)
			bav.push_back(std::stod(*it1));
		card_info_t* card = new card_info_t(
			c_nam, c_cat, mst, dur, cha, mch, btv, bav
		);
		cards.push_back(card);
	}
	open_file.close();
	std::sort(cards.begin(), cards.end(),
		[](card_info_t* a, card_info_t* b) { return a->name < b->name; });
	std::cout << "Imported " << cards.size() << " cards.\n";
	for (int i = 0; i < 80; i++)
	{
		card_cost.push_back(std::stoi(line[i + 16]));
		dust_cost.push_back(std::stoi(line[i + 96]));
	}
	std::cout << "Imported " << card_cost.size() << " card cost per card level info.\n";
	std::cout << "Imported " << dust_cost.size() << " dust cost per card level info.\n";
}

void import_player(std::string filename)
{
	std::cout << "\nImporting player card info from \"" << filename << "\".\n";
	std::string open_file_buffer = "";
	std::fstream open_file;
	open_file.open(filename, std::ios::in);
	std::getline(open_file, open_file_buffer);
	while (open_file_buffer.find("raidCards") == std::string::npos)
		std::getline(open_file, open_file_buffer);
	while (true)
	{
		std::getline(open_file, open_file_buffer);
		if (open_file_buffer.find("},") != std::string::npos)
			break;
		size_t i1 = open_file_buffer.find('\"') + 1;
		size_t i2 = open_file_buffer.find('\"', i1);
		std::string name = open_file_buffer.substr(i1, i2 - i1);
		string_to_lower_underscores(name);
		card_name c_name;
		try
		{
			c_name = card_names.at(name);
		}
		catch (const std::exception&)
		{
			std::cout << "No card with given name (" << open_file_buffer.substr(i1, i2 - i1) << ")\n";
			continue;
		}
		std::getline(open_file, open_file_buffer);
		i1 = open_file_buffer.find(':') + 2;
		i2 = open_file_buffer.find(',', i1);
		int level = std::stoi(open_file_buffer.substr(i1, i2 - i1));
		std::getline(open_file, open_file_buffer);
		i1 = open_file_buffer.find(':') + 2;
		int c_amount = std::stoi(open_file_buffer.substr(i1));
		std::getline(open_file, open_file_buffer);
		player_card_info_t* card = new player_card_info_t(card_names.at(name), level, c_amount);
		player_cards.push_back(card);
	}
	open_file.close();
	std::sort(player_cards.begin(), player_cards.end(),
		[](player_card_info_t* a, player_card_info_t* b) { return a->name < b->name; });
	std::cout << "Imported " << player_cards.size() << " cards.\n";
}

void import_titans(std::string filename)
{
	std::cout << "\nImporting titan info from \"" << filename << "\".\n";
	std::string open_file_buffer = "";
	std::fstream open_file;
	open_file.open(filename, std::ios::in);
	std::getline(open_file, open_file_buffer);
	string_vector line;
	while (std::getline(open_file, open_file_buffer))
	{
		line = csv_to_vector(open_file_buffer);
		std::string eid = line[0];
		string_to_lower_underscores(eid);
		enemy_id nam;
		try
		{
			nam = titan_names.at(eid);
		}
		catch (const std::exception&)
		{
			std::cout << "No titan with given id (" << line[0] << ")\n";
			continue;
		}
		double_vector bm;
		bm.reserve(4);
		double_vector am;
		am.reserve(4);
		for (int i = 5; i < 9; i++)
		{
			bm.push_back(std::stod(line[i]));
			am.push_back(std::stod(line[i + 4]));
		}
		string_vector btn;
		btn.reserve(8);
		double_vector ba;
		ba.reserve(8);
		for (int i = 35; i < 50; i += 2)
		{
			btn.push_back(line[i]);
			ba.push_back(std::stod(line[i + 1]));
		}
		titan_info_t* titan = new titan_info_t(
			nam, bm, am, btn, am
		);

		titans.push_back(titan);
	}
	open_file.close();
	std::sort(titans.begin(), titans.end(),
		[](titan_info_t* a, titan_info_t* b) { return a->name < b->name; });
	std::cout << "Imported " << titans.size() << " titans.\n";
}

void import_areas(std::string filename)
{
	std::cout << "\nImporting area info from \"" << filename << "\".\n";
	areas.reserve(area_ids.size());
	std::string open_file_buffer = "";
	std::fstream open_file;
	open_file.open(filename, std::ios::in);
	std::getline(open_file, open_file_buffer);
	string_vector line;
	while (std::getline(open_file, open_file_buffer))
	{
		line = csv_to_vector(open_file_buffer);
		std::string aid = line[0];
		string_to_lower_underscores(aid);
		area_id nam;
		try
		{
			nam = area_ids.at(aid);
		}
		catch (const std::exception&)
		{
			std::cout << "No area with given id (" << line[0] << ")\n";
			continue;
		}
		string_vector btv;
		btv.reserve(area_info_t::BONUS_N);
		double_vector bav;
		bav.reserve(area_info_t::BONUS_N);
		for (int i = 0, s = 7; i < area_info_t::BONUS_N; i++, s += 2)
		{
			btv.push_back(line[s]);
			bav.push_back(std::stod(line[s + 1]));
		}
		area_info_t* area = new area_info_t(
			nam, btv, bav
		);
		areas.push_back(area);
	}
	open_file.close();
	std::sort(areas.begin(), areas.end(),
		[](area_info_t* a, area_info_t* b) { return a->a_id < b->a_id; });
	std::cout << "Imported " << areas.size() << " areas.\n";
}

player_info* input_player_info()
{
	std::cout << "Input your player info:\n";
	std::cout << "Raid level: ";
	int rl;
	std::cin >> rl;
	std::cout << "Jade set? (y/n): ";
	char js;
	std::cin >> js;
	std::cout << "(0 - none | 1 - hero, champion | 2 - master, titan slayer)\nSeason bonus: ";
	int sb;
	std::cin >> sb;
	std::cout << "Dust to use: ";
	int dust;
	std::cin >> dust;
	std::cout << "Wildcards to use: ";
	int wc;
	std::cin >> wc;
	int jb;
	if (js == 'y')
		jb = 4;
	else
		jb = 0;
	return new player_info(rl + 100, jb, sb, dust, wc);
}