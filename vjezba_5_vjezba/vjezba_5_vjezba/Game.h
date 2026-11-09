#pragma once

#include <string>
#include "Level.h"
#include "Player.h"

class Game {
    std::string title;
    Player player;

public:
    Game(const std::string& title, const std::string& player_name);
    void print() const;
};