//
//  main.cpp
//  BlackJack
//
//  Created by Анастасия Мехова on 23.01.2025.
//

#include <iostream>
#include "CardModel.hpp"
#include "DeckModel.hpp"
#include "PlayerModel.hpp"
#include "DealerModel.hpp"
#include "TableModel.hpp"
#include "TableView.hpp" /// ???
#include "TableController.hpp"

int main(int argc, const char * argv[]) {
//    DeckModel d;
//    
//    std::cout << d.PopRandomCard()->GetFullName() << std::endl;
//    std::cout << d.PopRandomCard()->GetFullName() << std::endl;
//    std::cout << d.PopRandomCard()->GetFullName() << std::endl;
//    std::cout << d.PopRandomCard()->GetFullName() << std::endl;
//    
//    PlayerModel player;
//    player.AddCard(new CardModel{"2", "♠️", 2});
//    player.AddCard(new CardModel{"8", "♦️", 8});
//    player.AddCard(new CardModel{"A", "♠️", 11});
//    std::cout << player.GetHandValue() << "\n";
//    player.AddCard(new CardModel{"J", "♠️", 10});
//    std::cout << player.GetHandValue() << "\n";
//    
//    PlayerModel * a = new DealerModel;
//    delete a;
//    
//    TableModel t;
//    t.GetPlayer()->AddCard(new CardModel{"2", "♠️", 2});
//    t.GetPlayer()->AddCard(new CardModel{"A", "♠️", 11});
//    std::cout <<  t.GetPlayer()->GetHandValue() << "\n";
//    
//    std::cout << t.GetDealer()->GetDeck()->PopRandomCard()->GetFullName() << "\n";
//    std::cout << t.GetDealer()->GetDeck()->PopRandomCard()->GetFullName() << "\n";
//    std::cout << t.GetDealer()->GetDeck()->PopRandomCard()->GetFullName() << "\n";
//    std::cout << t.GetDealer()->GetDeck()->PopRandomCard()->GetFullName() << "\n";
    
    TableController c(new TableView, new TableModel);
    c.StartGame();
    
    return 0;
}
