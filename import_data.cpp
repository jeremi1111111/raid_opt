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
	names.insert(std::make_pair("moon_beam", card_name::moon_beam));
	names.insert(std::make_pair("fragmentize", card_name::fragmentize));
	names.insert(std::make_pair("skull_bash", card_name::skull_bash));
	names.insert(std::make_pair("razor_wind", card_name::razor_wind));
	names.insert(std::make_pair("whip_of_lightning", card_name::whip_of_lightning));
	names.insert(std::make_pair("clanship_barrage", card_name::clanship_barrage));
	names.insert(std::make_pair("purifying_blast", card_name::purifying_blast));
	names.insert(std::make_pair("psychic_shackles", card_name::psychic_shackles));
	names.insert(std::make_pair("flak_shot", card_name::flak_shot));
	names.insert(std::make_pair("cosmic_haymaker", card_name::cosmic_haymaker));
	names.insert(std::make_pair("chain_of_vengeance", card_name::chain_of_vengeance));
	names.insert(std::make_pair("mirror_force", card_name::mirror_force));
	names.insert(std::make_pair("celestial_static", card_name::celestial_static));
	names.insert(std::make_pair("blazing_inferno", card_name::blazing_inferno));
	names.insert(std::make_pair("acid_drench", card_name::acid_drench));
	names.insert(std::make_pair("decaying_strike", card_name::decaying_strike));
	names.insert(std::make_pair("fusion_bomb", card_name::fusion_bomb));
	names.insert(std::make_pair("grim_shadow", card_name::grim_shadow));
	names.insert(std::make_pair("thriving_plague", card_name::thriving_plague));
	names.insert(std::make_pair("radioactivity", card_name::radioactivity));
	names.insert(std::make_pair("ravenous_swarm", card_name::ravenous_swarm));
	names.insert(std::make_pair("ruinous_rain", card_name::ruinous_rain));
	names.insert(std::make_pair("corrosive_bubbles", card_name::corrosive_bubbles));
	names.insert(std::make_pair("maelstrom", card_name::maelstrom));
	names.insert(std::make_pair("crushing_instinct", card_name::crushing_instinct));
	names.insert(std::make_pair("insanity_void", card_name::insanity_void));
	names.insert(std::make_pair("rancid_gas", card_name::rancid_gas));
	names.insert(std::make_pair("inspiring_force", card_name::inspiring_force));
	names.insert(std::make_pair("soul_fire", card_name::soul_fire));
	names.insert(std::make_pair("victory_march", card_name::victory_march));
	names.insert(std::make_pair("prismatic_rift", card_name::prismatic_rift));
	names.insert(std::make_pair("ancestral_favor", card_name::ancestral_favor));
	names.insert(std::make_pair("grasping_vines", card_name::grasping_vines));
	names.insert(std::make_pair("totem_of_power", card_name::totem_of_power));
	names.insert(std::make_pair("team_tactics", card_name::team_tactics));
	names.insert(std::make_pair("skeletal_smash", card_name::skeletal_smash));
	names.insert(std::make_pair("astral_echo", card_name::astral_echo));

	categories.insert(std::make_pair("burst", card_category::burst));
	categories.insert(std::make_pair("affliction", card_category::affliction));
	categories.insert(std::make_pair("support", card_category::support));
}

void import_cards(std::string filename)
{
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
		std::string cat = line[4];
		string_to_lower_underscores(cat);
		int mst = std::stoi(line[8]);
		double dur = std::floor(std::stod(line[9]) * 100) / 100.;
		double cha = std::floor(std::stod(line[10]) * 100) / 100.;
		double mch = std::floor(std::stod(line[11]) * 100) / 100.;
		std::string bta = line[136];
		std::string btb = line[197];
		std::string btc = line[258];
		std::string btd = line[260];
		std::string bte = line[262];
		std::vector<double> baa;
		std::vector<double> bab;
		for (size_t i = 0; i < 60; i++)
		{
			baa.push_back(std::floor(std::stod(line[i + 137]) * 100) / 100.);
			bab.push_back(std::floor(std::stod(line[i + 198]) * 100) / 100.);
		}
		double bac = std::floor(std::stod(line[259]) * 100) / 100.;
		double bad = std::floor(std::stod(line[261]) * 100) / 100.;
		double bae = std::floor(std::stod(line[263]) * 100) / 100.;
		card_info* card = new card_info(
			names.at(nam), categories.at(cat), mst, dur, cha, mch, bta, btb, btc, btd, bte, baa, bab, bac, bad, bae
		);
		cards.push_back(card);
	}
	open_file.close();
	for (int i = 0; i < 60; i++)
	{
		card_cost.push_back(std::stoi(line[i + 16]));
		dust_cost.push_back(std::stoi(line[i + 76]));
	}
	std::sort(cards.begin(), cards.end(),
		[](card_info* a, card_info* b) { return a->name < b->name; });
}

void import_player(std::string filename)
{
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
		std::getline(open_file, open_file_buffer);
		i1 = open_file_buffer.find(':') + 2;
		i2 = open_file_buffer.find(',', i1);
		int level = std::stoi(open_file_buffer.substr(i1, i2 - i1));
		std::getline(open_file, open_file_buffer);
		i1 = open_file_buffer.find(':') + 2;
		int c_amount = std::stoi(open_file_buffer.substr(i1));
		std::getline(open_file, open_file_buffer);
		player_card_info* card = new player_card_info(names.at(name), level, c_amount);
		player_info.push_back(card);
	}
	open_file.close();
	std::sort(player_info.begin(), player_info.end(),
		[](player_card_info* a, player_card_info* b) { return a->name < b->name; });
}

void import_titans(std::string filename)
{
	std::string open_file_buffer = "";
	std::fstream open_file;
	open_file.open(filename, std::ios::in);
	std::getline(open_file, open_file_buffer);
	std::vector<std::string> line;
	while (std::getline(open_file, open_file_buffer))
	{
		line = csv_to_vector(open_file_buffer);
		std::string eid = line[0];
		if (eid == "EnemyGlobalBoss" || eid == "EnemyPractice")
			continue;
		string_to_lower_underscores(eid);
		std::string nam = line[1];
		string_to_lower_underscores(nam);
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
			eid, nam, bhm, btm, bam, blm, ahm, atm, aam, alm, bta, btb, btc, btd, bte, btf, btg, bth, baa, bab, bac, bad, bae, baf, bag, bah
		);
		titans.push_back(titan);
	}
	open_file.close();
}

void import_areas(std::string filename)
{
	std::string open_file_buffer = "";
	std::fstream open_file;
	open_file.open(filename, std::ios::in);
	std::getline(open_file, open_file_buffer);
	std::vector<std::string> line;
	while (std::getline(open_file, open_file_buffer))
	{
		line = csv_to_vector(open_file_buffer);
		std::string aid = line[0];
		if (aid == "AreaGlobalBoss" || aid == "AreaPractice")
			continue;
		string_to_lower_underscores(aid);
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
			aid, bta, btb, btc, btd, bte, btf, btg, bth, bti, baa, bab, bac, bad, bae, baf, bag, bah, bai
		);
		areas.push_back(area);
	}
}

// ideas:
// save cards and player_info as std::map
// change names from map to enum (is it even possible?)