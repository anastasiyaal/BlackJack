//
//  PlayerModel.hpp
//  BlackJack
//
//  Created by Анастасия Мехова on 24.01.2025.
//

#ifndef PlayerModel_hpp
#define PlayerModel_hpp

#include <stdio.h>
#include <vector>

class CardModel;


class PlayerModel {
private:
    unsigned short aces = 0;
    std::vector<CardModel*> hand;
public:
    bool AddCard(CardModel* card);
    unsigned short GetHandValue() const;
    std::vector<CardModel*> const & GetHand() const;
    virtual ~PlayerModel();
};



#endif /* PlayerModel_hpp */
