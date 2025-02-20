//
//  PlayerModel.cpp
//  BlackJack
//
//  Created by Анастасия Мехова on 24.01.2025.
//

#include "PlayerModel.hpp"
#include "CardModel.hpp"

bool PlayerModel::AddCard(CardModel* card) {
    if(!card) {
        return false;
    }
    for(CardModel*& card_in_hand : hand) {
        if(card_in_hand == card) {
            return false;
        }
    }
    if(card->GetValue() == 11) {
        ++aces;
    }
    hand.push_back(card);
    return true;
}


unsigned short PlayerModel::GetHandValue() const {
    unsigned short current_value = 0;
    for(CardModel const * const & card_in_hand : hand) {
        current_value += card_in_hand->GetValue();
    }
    unsigned short current_aces = aces;
    while((current_value > 21) && (current_aces)) {
        if(current_value > 21) {
            current_value -= 10;
        }
        --current_aces;
    }
    return current_value;
}

std::vector<CardModel*> const & PlayerModel::GetHand() const {
    return hand;
}

PlayerModel::~PlayerModel() {
}
