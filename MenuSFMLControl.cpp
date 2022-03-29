

#include <iostream>
#include "MenuSFMLControl.h"

MenuSFMLControl::MenuSFMLControl(Snake &snake, MenuSFMLView &menu) : snake(snake), menu(menu) {

}

void MenuSFMLControl::handleEvent(sf::Event &event) {

    if(event.type == sf::Event::KeyPressed)
    {
        if(event.key.code == sf::Keyboard::Up) {
            menu.Up();
        }
        if(event.key.code == sf::Keyboard::Down){
            menu.Down();
        }
        if(event.key.code == sf::Keyboard::Enter){
            if(menu.getSelectedOption() == 0){
                snake.setGameMode(1);
                snake.setScreen(2);
            }
            if(menu.getSelectedOption() == 1) {
                snake.setGameMode(2);
                snake.setScreen(2);
            }
            if(menu.getSelectedOption() == 2) {
                snake.setGameMode(3);
                snake.setScreen(2);
            }

            if(menu.getSelectedOption() == 3)
                snake.setScreen(0);
        }
    }
}
