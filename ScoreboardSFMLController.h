
#ifndef SNAKE1_SCOREBOARDSFMLCONTROLLER_H
#define SNAKE1_SCOREBOARDSFMLCONTROLLER_H

#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "ScoreboardSFMLView.h"

namespace sf{
    class Event;
}

class ScoreboardSFMLController {
    Snake & snake;
    ScoreboardSFMLView & scoreboard;
public:
    ScoreboardSFMLController(Snake &snake, ScoreboardSFMLView &scoreboard);

    void handleEvent(sf::Event &event);

};


#endif
