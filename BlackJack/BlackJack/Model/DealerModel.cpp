//
//  DealerModel.cpp
//  BlackJack
//
//  Created by Анастасия Мехова on 24.01.2025.
//
#include "DealerModel.hpp"
#include "DeckModel.hpp"

DealerModel::DealerModel() : deck(new DeckModel()) {
    }

DeckModel* DealerModel::GetDeck() {
    return deck;
}

DealerModel::~DealerModel() {
    delete deck;
}
