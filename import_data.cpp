#include "import_data.h"

std::vector<std::string> csv_to_vector(std::string& f_buffer)
{
	std::vector<std::string> contents;
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

void create_indexes()
{
	std::cout << "\nCreating card indexes.\n";
	card_names.insert(std::make_pair("moon_beam", card_name::moon_beam));
	card_names.insert(std::make_pair("fragmentize", card_name::fragmentize));
	card_names.insert(std::make_pair("skull_bash", card_name::skull_bash));
	card_names.insert(std::make_pair("razor_wind", card_name::razor_wind));
	card_names.insert(std::make_pair("whip_of_lightning", card_name::whip_of_lightning));
	card_names.insert(std::make_pair("clanship_barrage", card_name::clanship_barrage));
	card_names.insert(std::make_pair("purifying_blast", card_name::purifying_blast));
	card_names.insert(std::make_pair("psychic_shackles", card_name::psychic_shackles));
	card_names.insert(std::make_pair("flak_shot", card_name::flak_shot));
	card_names.insert(std::make_pair("cosmic_haymaker", card_name::cosmic_haymaker));
	card_names.insert(std::make_pair("chain_of_vengeance", card_name::chain_of_vengeance));
	card_names.insert(std::make_pair("mirror_force", card_name::mirror_force));
	card_names.insert(std::make_pair("celestial_static", card_name::celestial_static));
	card_names.insert(std::make_pair("blazing_inferno", card_name::blazing_inferno));
	card_names.insert(std::make_pair("acid_drench", card_name::acid_drench));
	card_names.insert(std::make_pair("decaying_strike", card_name::decaying_strike));
	card_names.insert(std::make_pair("fusion_bomb", card_name::fusion_bomb));
	card_names.insert(std::make_pair("grim_shadow", card_name::grim_shadow));
	card_names.insert(std::make_pair("thriving_plague", card_name::thriving_plague));
	card_names.insert(std::make_pair("radioactivity", card_name::radioactivity));
	card_names.insert(std::make_pair("ravenous_swarm", card_name::ravenous_swarm));
	card_names.insert(std::make_pair("ruinous_rain", card_name::ruinous_rain));
	card_names.insert(std::make_pair("corrosive_bubbles", card_name::corrosive_bubbles));
	card_names.insert(std::make_pair("maelstrom", card_name::maelstrom));
	card_names.insert(std::make_pair("crushing_instinct", card_name::crushing_instinct));
	card_names.insert(std::make_pair("insanity_void", card_name::insanity_void));
	card_names.insert(std::make_pair("rancid_gas", card_name::rancid_gas));
	card_names.insert(std::make_pair("inspiring_force", card_name::inspiring_force));
	card_names.insert(std::make_pair("soul_fire", card_name::soul_fire));
	card_names.insert(std::make_pair("victory_march", card_name::victory_march));
	card_names.insert(std::make_pair("prismatic_rift", card_name::prismatic_rift));
	card_names.insert(std::make_pair("ancestral_favor", card_name::ancestral_favor));
	card_names.insert(std::make_pair("grasping_vines", card_name::grasping_vines));
	card_names.insert(std::make_pair("totem_of_power", card_name::totem_of_power));
	card_names.insert(std::make_pair("team_tactics", card_name::team_tactics));
	card_names.insert(std::make_pair("skeletal_smash", card_name::skeletal_smash));
	card_names.insert(std::make_pair("astral_echo", card_name::astral_echo));
	std::cout << "Created " << card_names.size() << " card indexes.\n";

	std::cout << "\nCreating card category indexes.\n";
	card_categories.insert(std::make_pair("burst", card_category::burst));
	card_categories.insert(std::make_pair("affliction", card_category::affliction));
	card_categories.insert(std::make_pair("support", card_category::support));
	std::cout << "Created " << card_categories.size() << " card category indexes.\n";

	std::cout << "\nCreating titan name indexes.\n";
	titan_names.insert(std::make_pair("enemy1", enemy_id::lojak));
	titan_names.insert(std::make_pair("enemy2", enemy_id::takedar));
	titan_names.insert(std::make_pair("enemy3", enemy_id::jukk));
	titan_names.insert(std::make_pair("enemy4", enemy_id::sterl));
	titan_names.insert(std::make_pair("enemy5", enemy_id::mohaca));
	titan_names.insert(std::make_pair("enemy6", enemy_id::terro));
	titan_names.insert(std::make_pair("enemy7", enemy_id::klonk));
	titan_names.insert(std::make_pair("enemy8", enemy_id::priker));
	std::cout << "Created " << titan_names.size() << " titan name indexes.\n";

	std::cout << "\nCreating area id indexes.\n";
	area_ids.insert(std::make_pair("area1", area_id::area1));
	area_ids.insert(std::make_pair("area2", area_id::area2));
	area_ids.insert(std::make_pair("area3", area_id::area3));
	area_ids.insert(std::make_pair("area4", area_id::area4));
	area_ids.insert(std::make_pair("areaspecial1", area_id::areaspecial1));
	std::cout << "Created " << area_ids.size() << " area id indexes.\n";
}

void import_cards(std::string filename)
{
	std::cout << "\nImporting card info from \"" << filename << "\".\n";
	std::string open_file_buffer = "";
	std::fstream open_file;
	open_file.open(filename, std::ios::in);
	std::getline(open_file, open_file_buffer);
	std::vector<std::string> line;
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
		//double dur = std::floor(std::stod(line[9]) * 100) / 100.;
		//double cha = std::floor(std::stod(line[10]) * 100) / 100.;
		//double mch = std::floor(std::stod(line[11]) * 100) / 100.;
		double dur = std::stod(line[9]);
		double cha = std::stod(line[10]);
		double mch = std::stod(line[11]);
		std::string bta = line[176];
		std::string btb = line[257];
		std::string btc = line[338];
		std::string btd = line[340];
		std::string bte = line[342];
		std::vector<double> baa;
		std::vector<double> bab;
		for (size_t i = 0; i < 80; i++)
		{
			//baa.push_back(std::floor(std::stod(line[i + 177]) * 100) / 100.);
			//bab.push_back(std::floor(std::stod(line[i + 258]) * 100) / 100.);
			baa.push_back(std::stod(line[i + 177]));
			bab.push_back(std::stod(line[i + 258]));
		}
		//double bac = std::floor(std::stod(line[339]) * 100) / 100.;
		//double bad = std::floor(std::stod(line[341]) * 100) / 100.;
		//double bae = std::floor(std::stod(line[343]) * 100) / 100.;
		double bac = std::stod(line[339]);
		double bad = std::stod(line[341]);
		double bae = std::stod(line[343]);
		card_info* card = new card_info(
			c_nam, c_cat, mst, dur, cha, mch, bta, btb, btc, btd, bte, baa, bab, bac, bad, bae
		);
		cards.push_back(card);
	}
	open_file.close();
	std::sort(cards.begin(), cards.end(),
		[](card_info* a, card_info* b) { return a->name < b->name; });
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
		player_card_info* card = new player_card_info(card_names.at(name), level, c_amount);
		player_cards.push_back(card);
	}
	open_file.close();
	std::sort(player_cards.begin(), player_cards.end(),
		[](player_card_info* a, player_card_info* b) { return a->name < b->name; });
	std::cout << "Imported " << player_cards.size() << " cards.\n";
}

void import_titans(std::string filename)
{
	std::cout << "\nImporting titan info from \"" << filename << "\".\n";
	std::string open_file_buffer = "";
	std::fstream open_file;
	open_file.open(filename, std::ios::in);
	std::getline(open_file, open_file_buffer);
	std::vector<std::string> line;
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
		double bhm = std::stod(line[5]);
		double btm = std::stod(line[6]);
		double bam = std::stod(line[7]);
		double blm = std::stod(line[8]);
		double ahm = std::stod(line[9]);
		double atm = std::stod(line[10]);
		double aam = std::stod(line[11]);
		double alm = std::stod(line[12]);
		std::string bta = line[35];
		std::string btb = line[37];
		std::string btc = line[39];
		std::string btd = line[41];
		std::string bte = line[43];
		std::string btf = line[45];
		std::string btg = line[47];
		std::string bth = line[49];
		double baa = std::stod(line[36]);
		double bab = std::stod(line[38]);
		double bac = std::stod(line[40]);
		double bad = std::stod(line[42]);
		double bae = std::stod(line[44]);
		double baf = std::stod(line[46]);
		double bag = std::stod(line[48]);
		double bah = std::stod(line[50]);
		titan_info* titan = new titan_info(
			nam, bhm, btm, bam, blm, ahm, atm, aam, alm, bta, btb, btc, btd, bte, btf, btg, bth, baa, bab, bac, bad, bae, baf, bag, bah
		);
		titans.push_back(titan);
	}
	open_file.close();
	std::sort(titans.begin(), titans.end(),
		[](titan_info* a, titan_info* b) { return a->name < b->name; });
	std::cout << "Imported " << titans.size() << " titans.\n";
}

void import_areas(std::string filename)
{
	std::cout << "\nImporting area info from \"" << filename << "\".\n";
	std::string open_file_buffer = "";
	std::fstream open_file;
	open_file.open(filename, std::ios::in);
	std::getline(open_file, open_file_buffer);
	std::vector<std::string> line;
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
		std::string bta = line[7];
		std::string btb = line[9];
		std::string btc = line[11];
		std::string btd = line[13];
		std::string bte = line[15];
		std::string btf = line[17];
		std::string btg = line[19];
		std::string bth = line[21];
		std::string bti = line[23];
		double baa = std::stod(line[8]);
		double bab = std::stod(line[10]);
		double bac = std::stod(line[12]);
		double bad = std::stod(line[14]);
		double bae = std::stod(line[16]);
		double baf = std::stod(line[18]);
		double bag = std::stod(line[20]);
		double bah = std::stod(line[22]);
		double bai = std::stod(line[24]);
		area_info* area = new area_info(
			nam, bta, btb, btc, btd, bte, btf, btg, bth, bti, baa, bab, bac, bad, bae, baf, bag, bah, bai
		);
		areas.push_back(area);
	}
	open_file.close();
	std::sort(areas.begin(), areas.end(),
		[](area_info* a, area_info* b) { return a->a_id < b->a_id; });
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

// ideas:
// save cards and player_cards as std::map
// change card_names from map to enum (is it even possible?)