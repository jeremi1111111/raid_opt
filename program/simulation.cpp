#include "simulation.h"
#include "../game_info/card_info.h"
#include "../sim_components/sim_deck.h"

std::vector<sim_deck*> deck_order(std::vector<card_name> chosen_cards)
{
	if (chosen_cards.empty())
		for (card_info* ci : cards)
			chosen_cards.push_back(ci->name);
	std::vector<sim_deck*> decks;
	int count = 0;
	for (int i = 0; i < chosen_cards.size(); i++)
		for (int j = i + 1; j < chosen_cards.size(); j++)
			for (int k = j + 1; k < chosen_cards.size(); k++)
			{
				sim_deck* new_deck = new sim_deck(chosen_cards[i], chosen_cards[j], chosen_cards[k]);
				decks.push_back(new_deck);
				count++;
			}
	return decks;
}