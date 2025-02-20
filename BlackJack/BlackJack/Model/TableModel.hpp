//
//  TableModel.hpp
//  BlackJack
//
//  Created by Анастасия Мехова on 29.01.2025.
//

#ifndef TableModel_hpp
#define TableModel_hpp

#include <stdio.h>

class PlayerModel;
class DealerModel;

class TableModel {
private:
    PlayerModel* player;
    DealerModel* dealer;
public:
    TableModel();
    PlayerModel* GetPlayer();
    DealerModel* GetDealer();
    ~TableModel();
};



#endif /* TableModel_hpp */
