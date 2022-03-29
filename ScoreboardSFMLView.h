

#ifndef SNAKE1_SCOREBOARDSFMLVIEW_H
#define SNAKE1_SCOREBOARDSFMLVIEW_H

#include <SFML/Graphics.hpp>
#include "Snake.h"
#include <vector>
#include <fstream>

class ScoreboardSFMLView :public sf::Drawable{
    Snake & snake;

    sf::Font font;
    sf::Text text;
    sf::Text scoreboard[100];

public:
    explicit ScoreboardSFMLView(Snake &snake);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    void setScoreboard();

};


#endif
