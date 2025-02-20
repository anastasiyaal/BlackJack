//
//  TableController.cpp
//  BlackJack
//
//  Created by Анастасия Мехова on 29.01.2025.
//

#include <iostream>
#include "TableController.hpp"
#include "TableView.hpp"
#include "TableModel.hpp"
#include "PlayerModel.hpp"
#include "DeckModel.hpp"
#include "DealerModel.hpp"
#include "CardModel.hpp"

#include <string>


TableController::TableController(TableView* _table_view, TableModel* _table_model) : table_view(_table_view), table_model(_table_model), game_state(GameState::PreMatch) {
    
}

void TableController::GiveCardToPlayer(PlayerModel* const player, DeckModel* deck) {
    player->AddCard(deck->PopRandomCard());
}

CompetitionState TableController::GetCompetitionState() const {
    unsigned short player_score = table_model->GetPlayer()->GetHandValue();
    unsigned short dealer_score = table_model->GetDealer()->GetHandValue();
    switch(game_state) {
        case GameState::PreMatch:
            if (player_score == 21) {
                return CompetitionState::PlayerWins;
            }
            if(dealer_score == 21) {
                return CompetitionState::DealerWins;
            }
            break;
        case GameState::PlayerChoice:
            if (player_score > 21) {
                return CompetitionState::DealerWins;
            }
            break;
        case GameState::DealerChoice:
        case GameState::EndGame:
            if (player_score > 21) {
                return CompetitionState::DealerWins;
            }
            else if (player_score == 21) {
                return CompetitionState::PlayerWins;
            }
            if((dealer_score > 17) && (dealer_score <= 21)) {
                if(dealer_score > player_score) {
                    return CompetitionState::DealerWins;
                }
                else if (dealer_score < player_score) {
                    return CompetitionState::PlayerWins;
                }
                else {
                    return CompetitionState::Draw;
                }
            }
            else if(dealer_score > 21) {
                return CompetitionState::PlayerWins;
            }
            break;
            
    }
    return CompetitionState::InGame;
}

void TableController::DrawPlayers() {
    std::string players;
    players = "Dealer: ";
    for(CardModel* const card : table_model->GetDealer()->GetHand()) {
        players += card->GetFullName() + ", ";
    }
    players += "dealer score: " + std::to_string(table_model->GetDealer()->GetHandValue()) + "\n";
    
    players += "Player: ";
    for(CardModel* const card : table_model->GetPlayer()->GetHand()) {
        players += card->GetFullName() + ", ";
    }
    players += "player score: " + std::to_string(table_model->GetPlayer()->GetHandValue()) + "\n";
    table_view->DrawPlayers(players);
}

void TableController::DrawMenu() {
    std::string menu;
    menu = "1 - Take a card";
    menu += "\n";
    menu += "2 - Enough";
    menu += "\n";
    table_view->DrawMenu(menu);
}


void TableController::GameLoop() {
    int input;
    while(true) {
        switch(game_state) {
            case GameState::PreMatch:
                DrawPlayers();
                if((GetCompetitionState() == CompetitionState::PlayerWins) || (GetCompetitionState() == CompetitionState::DealerWins)) {
                    game_state = GameState::EndGame;
                }
                else {
                    game_state = GameState::PlayerChoice;
                }
                break;
            case GameState::PlayerChoice:
                DrawMenu();
                input = table_view->GetInput();
                if(input == 1) {
                    GiveCardToPlayer(table_model->GetPlayer(), table_model->GetDealer()->GetDeck());
                    DrawPlayers();
                    if(GetCompetitionState() == CompetitionState::DealerWins) {
                        game_state = GameState::EndGame;
                    }
                }
                else if(input == 2) {
                    game_state = GameState::DealerChoice;
                }
                break;
            case GameState::DealerChoice:
                if (table_model->GetDealer()->GetHandValue() <= 17) {
                    GiveCardToPlayer(table_model->GetDealer(), table_model->GetDealer()->GetDeck());
                    DrawPlayers();
                }
                else {
                    game_state = GameState::EndGame;
                }
                break;
            case GameState::EndGame:
                std::string result;
                if(GetCompetitionState() == CompetitionState::PlayerWins) {
                    result = "Player Wins!\n";
                    table_view->DrawResult(result);
                }
                else if(GetCompetitionState() == CompetitionState::DealerWins) {
                    result = "Dealer Wins!\n";
                    table_view->DrawResult(result);
                }
                else {
                    result = "Draw!\n";
                    table_view->DrawResult(result);
                }
                return;
        }
    }
}

void TableController::StartGame() {
//    GiveCardToPlayer(table_model->GetPlayer(), table_model->GetDealer()->GetDeck());
//    GiveCardToPlayer(table_model->GetPlayer(), table_model->GetDealer()->GetDeck());
    table_model->GetPlayer()->AddCard(new CardModel("A", "♣️", 11));
    table_model->GetPlayer()->AddCard(new CardModel("Q", "♣️", 10));
    table_model->GetDealer()->AddCard(new CardModel("3", "♣️", 3));
    table_model->GetDealer()->AddCard(new CardModel("10", "♣️", 10));
    
//    GiveCardToPlayer(table_model->GetDealer(), table_model->GetDealer()->GetDeck());
//    GiveCardToPlayer(table_model->GetDealer(), table_model->GetDealer()->GetDeck());
    GameLoop();
}


TableController::~TableController() {
    delete table_view;
    delete table_model;
}

