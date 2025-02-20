//
//  DealerModel.hpp
//  BlackJack
//
//  Created by Анастасия Мехова on 24.01.2025.
//

#ifndef DealerModel_hpp
#define DealerModel_hpp

#include <stdio.h>
#include "PlayerModel.hpp"

class DeckModel; 

class DealerModel : public PlayerModel {
private:
    DeckModel* deck;
public:
    DealerModel();
    DeckModel* GetDeck();
    ~DealerModel() override;
};

#endif /* DealerModel_hpp */
