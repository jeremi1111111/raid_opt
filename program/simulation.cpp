#include <iostream>
#include "simulation.h"
#include "../game_info/card_info_t.h"
#include "../sim_components/sim_deck.h"
#include "../sim_components/sim_card.h"
#include "../sim_components/sim_part.h"
#include "../sim_components/sim_stack.h"
#include "../sim_components/sim_titan.h"
#include "attack_details.h"

std::random_device rd;
std::mt19937 rng(rd());
std::uniform_real_distribution<double> dist(0., 1.);
//std::uniform_int_distribution<int> fairy_spawner(0, 3800);

std::vector<sim_deck*> deck_order(std::vector<card_name> chosen_cards)
{
	//if (chosen_cards.empty())
	//	for (card_info_t* ci : cards)
	//		chosen_cards.push_back(ci->name);
	//std::vector<sim_deck*> decks;
	//int count = 0;
	//for (int i = 0; i < chosen_cards.size(); i++)
	//	for (int j = i + 1; j < chosen_cards.size(); j++)
	//		for (int k = j + 1; k < chosen_cards.size(); k++)
	//		{
	//			sim_deck* new_deck = new sim_deck(chosen_cards[i], chosen_cards[j], chosen_cards[k]);
	//			decks.push_back(new_deck);
	//			count++;
	//		}
	//return decks;
	return {};
}

double simulate()
{
	sim_titan* titan = new sim_titan(enemy_id::lojak, 1e9);
	player_info* player = new player_info(824, 4, 1, 0, 0);
	attack_details* attack = new attack_details(player, { part_name::head }, 600, 600);
	sim_deck* deck = new sim_deck({ 1, 2, 3 }, titan, attack);
	titan->set_cards(deck->get_deck_cards());
	double dmg = deck->simulate();
	//std::cout << deck->get_tap_dmg() << '\t';
	//for (sim_card* card : deck->get_deck_cards())
	//	std::cout << card->get_dmg_dealt() << '\t';
	//std::cout << "|\t" << dmg << '\n';
	delete titan;
	delete player;
	delete attack;
	delete deck;
	return dmg;
}
