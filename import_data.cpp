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
		for (int i = 0; i < 60; i++)
		{
			baa.push_back(std::floor(std::stod(line[i+137]) * 100) / 100.);
			bab.push_back(std::floor(std::stod(line[i+198]) * 100) / 100.);
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
		int i1 = open_file_buffer.find('\"') + 1;
		int i2 = open_file_buffer.find('\"', i1);
		std::string name = open_file_buffer.substr(i1, i2 - i1);
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
}

// ideas:
// save cards and player_info as std::map