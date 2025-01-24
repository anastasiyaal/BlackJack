//
//  DeckModel.hpp
//  BlackJack
//
//  Created by Анастасия Мехова on 23.01.2025.
//

#ifndef DeckModel_hpp
#define DeckModel_hpp

#include <stdio.h>
#include <vector>
#include <string>

class CardModel; //forward declaration

class DeckModel {
private:
    std::vector<CardModel*> cards;
public:
    DeckModel();
    CardModel* PopRandomCard();
    ~DeckModel();
};





#endif /* DeckModel_hpp */
