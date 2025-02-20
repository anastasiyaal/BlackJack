//
//  TableController.hpp
//  BlackJack
//
//  Created by Анастасия Мехова on 29.01.2025.
//

#ifndef TableController_hpp
#define TableController_hpp

#include <stdio.h>

class TableView;
class TableModel;
class PlayerModel;
class DeckModel;

enum class GameState {
    PreMatch,
    PlayerChoice,
    DealerChoice,
    EndGame
};

enum class CompetitionState {
    InGame,
    PlayerWins,
    DealerWins,
    Draw
};

class TableController {
private:
    TableView* table_view;
    TableModel* table_model;
    GameState game_state;
    void GiveCardToPlayer(PlayerModel* const player, DeckModel* deck);
    CompetitionState GetCompetitionState() const;
    void DrawPlayers();
    void DrawMenu();
    void GameLoop();
public:
    TableController(TableView* _table_view, TableModel* _table_model);
    void StartGame();
    ~TableController();
};



#endif /* TableController_hpp */
