# TT2 Card Optimizer

(This project is still in development)

TT2 Card Optimizer is a C++ project based on mobile game's **Tap Titans 2** raid system. The objective is to calculate the best possible decks given player's card levels, raid bonuses and titan's state.

## Basics
Titan can be attacked each 12 hours with 6 decks consisting of 3 cards each. Each card gives different bonus, they are split into 3 categories, some decks play better, while others are completely unusable.
Cards can be leveled up and each can be used once each cycle, which makes deck building harder. It's crucial to pick best possible decks to deal the most damage.

## Program outline
### Raid optimizer
Program simulates each possible deck of 3 cards, ranking them in order of most damage dealt. Basing on these results, each simulation cycle the worst decks are rejected and calculations are repeated.
Some cards are strongly rng-based, while others can give the same output each time. After a "couple" of rounds, algorithm picks 6 decks that combined give the most damage.
### Card optimizer
Based on results from raid optimizer for every possible combination of raids, titans and decks, total usability score is calculated for each card.
After that, the best card is chosen to be upgraded (if player has enough resources to do so) and certain decks are resimulated in order to rank it again. 

## State of the project and plans for the future
Right now the project is **semi-suspended**. I have implemented core simulation components, but the program lacks logic of most cards. Without it, I couldn't implement whole Card optimizer logic and deck picking algorithm for Raid optimizer.
Process is very time consuming and I don't include coding for this project in planning my work. It's a side project, I'm doing it for fun and maybe one day I'll finish my work :)
