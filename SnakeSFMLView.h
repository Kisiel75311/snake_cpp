
#ifndef SNAKE_SNAKESFMLVIEW_H
#define SNAKE_SNAKESFMLVIEW_H

#include <SFML/Graphics.hpp>
#include "Snake.h"

struct WallPosSFML
{
    int x;
    int y;
};
struct SnakePosSFML
{
    int x;
    int y;
};

class SnakeSFMLView : public sf::Drawable {
    Snake & snake;
    std::vector <SnakePosSFML> snakeSFML;
    std::vector <WallPosSFML> wallSFML;

    sf::Font font;
    sf::Text pause[2];

    sf::RectangleShape snakeBody [2500];
    sf::RectangleShape point;
    sf::RectangleShape wall [102];
public:

    explicit SnakeSFMLView(Snake &snake);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    void setBoard();

    void setWall();

    void updateView();

    void clearScreen();

    void pauseScreen();

};


#endif