//
//  main.cpp
//  BlackJack
//
//  Created by Анастасия Мехова on 23.01.2025.
//

#include <iostream>
#include "CardModel.hpp"
#include "DeckModel.hpp"

int main(int argc, const char * argv[]) {
    DeckModel d;
    
    std::cout << d.PopRandomCard()->GetFullName() << std::endl;
    std::cout << d.PopRandomCard()->GetFullName() << std::endl;
    std::cout << d.PopRandomCard()->GetFullName() << std::endl;
    std::cout << d.PopRandomCard()->GetFullName() << std::endl;
    
    
    return 0;
}
