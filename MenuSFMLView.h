

#ifndef SNAKE1_MENUSFMLVIEW_H
#define SNAKE1_MENUSFMLVIEW_H

#include <SFML/Graphics.hpp>
#include "Snake.h"
#include <vector>

class MenuSFMLView :public sf::Drawable{
    Snake & snake;
    int selectedOption;
    sf::Font font;
    sf::Text menu[5];
    sf::Text gameName;
public:
    explicit MenuSFMLView(Snake &snake);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    void Up();
    void Down();

    int getSelectedOption() const;
};


#endif
