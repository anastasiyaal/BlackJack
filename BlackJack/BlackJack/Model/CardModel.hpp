//
//  CardModel.hpp
//  BlackJack
//
//  Created by Анастасия Мехова on 23.01.2025.
//

#ifndef CardModel_hpp
#define CardModel_hpp

#include <stdio.h>
#include <string>


class CardModel{
private:
    std::string const name;
    std::string const suit;
    unsigned short const value;
public:
    CardModel() = delete;
    CardModel(std::string const & _name, std::string const & _suit, unsigned short const & _value);
    std::string GetFullName() const;
    unsigned short GetValue() const;
};


#endif /* CardModel_hpp */
