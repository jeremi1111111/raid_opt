#include "import_cards.h"

std::vector<std::string> csv_to_vector(std::string& f_buffer) {
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
	while (std::getline(open_file, open_file_buffer))
	{
		std::vector<std::string> line = csv_to_vector(open_file_buffer);
		std::string nam = line[1];
		std::string cat = line[4];
		int mst = std::stoi(line[8]);
		double dur = std::stod(line[9]);
		double cha = std::stod(line[10]);
		double mch = std::stod(line[11]);
		std::string bta = line[136];
		std::vector<double> baa;
		for (int i = 137; i < 197; i++)
			baa.push_back(std::stod(line[i]));
		std::string btb = line[197];
		std::vector<double> bab;
		for (int i = 198; i < 258; i++)
			bab.push_back(std::stod(line[i]));
		std::string btc = line[258];
		double bac = std::stod(line[259]);
		std::string btd = line[260];
		double bad = std::stod(line[261]);
		std::string bte = line[262];
		double bae = std::stod(line[263]);
		card_info* card = new card_info(
			nam, cat, mst, dur, cha, mch, bta, baa, btb, bab, btc, bac, btd, bad, bte, bae
		);
		cards.push_back(card);
	}
	open_file.close();
}