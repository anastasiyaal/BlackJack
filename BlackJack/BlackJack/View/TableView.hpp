//
//  TableView.hpp
//  BlackJack
//
//  Created by Анастасия Мехова on 29.01.2025.
//

#ifndef TableView_hpp
#define TableView_hpp

#include <stdio.h>
#include <string>

class TableView {
private:
    
public:
    int GetInput();
    void DrawPlayers(std::string const & players);
    void DrawMenu(std::string const & menu);
    void DrawResult(std::string const & result);
};

#endif /* TableView_hpp */
