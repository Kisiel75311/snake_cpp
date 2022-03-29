#include "SnakeSFMLController.h"

SnakeSFMLController::SnakeSFMLController(Snake &snake, SnakeSFMLView &view) : snake(snake), view(view) {

}

void SnakeSFMLController::handleEvent(sf::Event &event) {

    if(event.type == sf::Event::KeyPressed)
    {
        if( event.key.code == sf::Keyboard::Left)
            snake.move(1);
        if(event.key.code == sf::Keyboard::Right)
            snake.move(2);
        if(event.key.code == sf::Keyboard::Up)
            snake.move(3);
        if(event.key.code == sf::Keyboard::Down)
         snake.move(4);
        if(event.key.code == sf::Keyboard::Escape)
        {
            snake.pause();
        }
        if(event.key.code == sf::Keyboard::Enter)
        {
            snake.resume();
        }
    }
}

