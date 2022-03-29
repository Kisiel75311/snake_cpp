#ifndef SNAKE_SNAKESFMLCOTROLLER_H
#define SNAKE_SNAKESFMLCOTROLLER_H

#include "SnakeSFMLView.h"
#include "Snake.h"

namespace sf{
    class Event;
}

class SnakeSFMLController {
    Snake & snake;
    SnakeSFMLView & view;
public:
    SnakeSFMLController(Snake &snake, SnakeSFMLView &view);

    void handleEvent (sf::Event &event);
};


#endif 