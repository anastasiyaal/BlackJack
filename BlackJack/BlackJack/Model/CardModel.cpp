//
//  CardModel.cpp
//  BlackJack
//
//  Created by Анастасия Мехова on 23.01.2025.
//

#include "CardModel.hpp"


CardModel::CardModel(std::string const & _name, std::string const & _suit, unsigned short const & _value) : name(_name), suit(_suit), value(_value) {}


std::string CardModel::GetFullName() const {
    return suit + " " + name;
}
unsigned short CardModel::GetValue() const {
    return value;
}
