
#ifndef SNAKE1_MENUSFMLCONTROL_H
#define SNAKE1_MENUSFMLCONTROL_H

#include <SFML/Graphics.hpp>

#include "MenuSFMLView.h"
#include "Snake.h"

namespace sf{
    class Event;
}

class MenuSFMLControl {
    Snake & snake;
    MenuSFMLView & menu;
public:
    MenuSFMLControl(Snake &snake, MenuSFMLView &menu);

    void handleEvent(sf::Event &event);

};


#endif //SNAKE1_MENUSFMLCONTROL_H
