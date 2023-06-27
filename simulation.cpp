#include "simulation.h"

std::vector<deck*> deck_order(std::vector<player_card_info*> chosen_cards)
{
	std::vector<deck*> decks;
	int count = 0;
	for (int i = 0; i < chosen_cards.size(); i++)
	{
		for (int j = i + 1; j < chosen_cards.size(); j++)
		{
			for (int k = j + 1; k < chosen_cards.size(); k++)
			{
				deck* new_deck = new deck(chosen_cards[i], chosen_cards[j], chosen_cards[k]);
				decks.push_back(new_deck);
				count++;
			}
		}
	}
	return decks;
}

