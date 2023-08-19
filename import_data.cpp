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
			nam, cat, mst, dur, cha, mch, bta, btb, btc, btd, bte, baa, bab, bac, bad, bae
		);
		indexes.emplace(std::make_pair(nam, (int)cards.size()));
		cards.push_back(card);
	}
	for (int i = 0; i < 60; i++)
	{
		card_cost.push_back(std::stoi(line[i + 16]));
		dust_cost.push_back(std::stoi(line[i + 76]));
	}
	open_file.close();
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
		player_card_info* card = new player_card_info(name, level, c_amount);
		player_info.push_back(card);
	}
	open_file.close();
	std::sort(player_info.begin(), player_info.end(),
		[](player_card_info* a, player_card_info* b) { return a->index < b->index; });
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
// change indexes from map to enum (is it even possible?)