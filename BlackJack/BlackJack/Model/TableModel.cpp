//
//  TableModel.cpp
//  BlackJack
//
//  Created by Анастасия Мехова on 29.01.2025.
//

#include "TableModel.hpp"
#include "PlayerModel.hpp"
#include "DealerModel.hpp"

TableModel::TableModel() : player(new PlayerModel()), dealer(new DealerModel()) {
    
}

PlayerModel* TableModel::GetPlayer() {
    return player;
}

DealerModel* TableModel::GetDealer() {
    return dealer;
}

TableModel::~TableModel() {
    delete player;
    delete dealer;
}
