//
//  TableView.cpp
//  BlackJack
//
//  Created by Анастасия Мехова on 29.01.2025.
//

#include "TableView.hpp"
#include <iostream>


int TableView::GetInput() {
    int input;
    std::cin >> input;
    return input;
}

void TableView::DrawPlayers(std::string const & players) {
    std::cout << players;
}

void TableView::DrawMenu(std::string const & menu) {
    std::cout << menu;
}

void TableView::DrawResult(std::string const & result) {
    std::cout << result;
}
