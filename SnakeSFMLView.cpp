
#include <iostream>
#include <cstring>
#include "SnakeSFMLView.h"

SnakeSFMLView::SnakeSFMLView(Snake &snake) : snake(snake) {

    if ( ! font.loadFromFile("fonts/BigSpace-rPKx.ttf") )
    {
        //PROBLEM!!!
        std::cerr << strerror(errno) << std::endl;
        abort();
    }

    for(auto & i : snakeBody)
        i = sf::RectangleShape (sf::Vector2f(10, 10) );
    for(auto & i : wall) {
        i = sf::RectangleShape(sf::Vector2f(10, 10));
        i.setFillColor(sf::Color::Black);
    }
    point = sf::RectangleShape (sf::Vector2f(10, 10) );

}

void SnakeSFMLView::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    if(snake.getStatus() == 0) {
        for (const auto &i : snakeBody)
            target.draw(i, states);
        for (const auto &i : wall)
            target.draw(i, states);
        target.draw(point, states);
    }
    if(snake.getStatus() == PAUSE) {
        target.draw(pause[0], states);
        target.draw(pause[1],states);
    }
}

void SnakeSFMLView::setBoard() {
    int PointX, PointY;
    PointX = snake.getPointPositionX() * 10;
    PointY = snake.getPointPositionY() * 10;

    for(int i = 0; i < snake.snake.size(); i++) {
        snakeBody[i].setPosition(snake.snake[i].x * 10, snake.snake[i].y * 10);
        snakeBody[i].setFillColor(sf::Color::Green);
    }
    point.setPosition(PointX,PointY);
    point.setFillColor(sf::Color::Red);

}

void SnakeSFMLView::setWall() {
    std::vector <float> xWallPoss;
    std::vector <float> yWallPoss;
    for(auto & i : snake.wall)
    {
        xWallPoss.push_back(i.x);
        yWallPoss.push_back(i.y);
    }

        for(int i = 0; i < snake.wall.size(); i++) {
            wall[i].setFillColor(sf::Color::Yellow);
            wall[i].setPosition(xWallPoss[i]*10, yWallPoss[i]*10);
        }
}

void SnakeSFMLView::updateView() {
            setBoard();
            setWall();
}

void SnakeSFMLView::clearScreen() {
    for (auto &i : snakeBody)
        i.setFillColor(sf::Color::Black);
    for (auto &i : wall) {
        i.setFillColor(sf::Color::Black);
    }
}

void SnakeSFMLView::pauseScreen() {
    pause[0].setFont(font);
    pause[0].setFillColor(sf::Color(151,219,5));
    pause[0].setString("PAUSED");
    pause[0].setCharacterSize(70);
    pause[0].setPosition(160, snake.getHeight() / 4  );

    pause[1].setFont(font);
    pause[1].setFillColor(sf::Color::White);
    pause[1].setCharacterSize(40);
    pause[1].setString("Press ENTER to resume");
    pause[1].setPosition(60, snake.getHeight() / 4 * 10  );
}
