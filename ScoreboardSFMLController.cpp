

#include "ScoreboardSFMLController.h"

ScoreboardSFMLController::ScoreboardSFMLController(Snake &snake, ScoreboardSFMLView &scoreboard) : snake(snake),scoreboard(scoreboard) {}



void ScoreboardSFMLController::handleEvent(sf::Event &event) {

    if(event.type == sf::Event::KeyPressed)
    {
        if(event.key.code == sf::Keyboard::Escape)
        {
            snake.setScreen(1);
            snake.clearBoard();
        }
    }

}


