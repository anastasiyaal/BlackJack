//
//  DeckModel.cpp
//  BlackJack
//
//  Created by Анастасия Мехова on 23.01.2025.
//

#include "DeckModel.hpp"
#include "CardModel.hpp"
#include <algorithm>
#include <ctime>

DeckModel::DeckModel() {
    std::vector<std::string> names{"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    std::vector<std::string> suits{"♠️", "♣️", "♥️", "♦️"};
    unsigned short value;
    for(unsigned short i = 0; i < names.size(); ++i) {
        for(unsigned short j = 0; j < suits.size(); ++j) {
            if(names[i] == "J" || names[i] == "Q" || names[i] == "K") {
                value = 10;
            }
            else if(names[i] == "A") {
                value = 11;
            }
            else {
                value = i + 2;
            }
            cards.push_back(new CardModel(names[i], suits[j], value));
        }
    }
}
CardModel* DeckModel::PopRandomCard() {
//    int range = max - min + 1;
//    int num = rand() % range + min;
    if(cards.size()) {
        srand(static_cast<unsigned int>(time(nullptr)));
        unsigned short range = static_cast<unsigned short>(cards.size());
        unsigned short num = static_cast<unsigned short>(rand() % range);
        CardModel* temp = cards[num];
        cards.erase(cards.begin() + num);
        return temp;
    }
    else {
        return nullptr;
    }
}

DeckModel::~DeckModel() {
    for(unsigned short i = 0; i < cards.size(); ++i) {
        delete cards[i];
    }
    cards.clear();
}

