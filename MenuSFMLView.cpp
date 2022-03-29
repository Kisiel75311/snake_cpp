//
// Created by Kisiel on 10.05.2020.
//

#include <cstring>
#include <iostream>
#include "MenuSFMLView.h"

MenuSFMLView::MenuSFMLView(Snake &snake) : snake(snake) {

    if ( ! font.loadFromFile("fonts/BigSpace-rPKx.ttf") )
    {
        //PROBLEM!!!
        std::cerr << strerror(errno) << std::endl;
        abort();
    }

    gameName.setFont(font);
    gameName.setString("SNAKE");
    gameName.setCharacterSize(70);
    gameName.setFillColor(sf::Color(151,219,5));
    gameName.setPosition(160, snake.getHeight()/4);

    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setString("EASY");
    menu[0].setPosition(180, snake.getHeight() / 4 * 10  );

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("MEDIUM");
    menu[1].setPosition(180, snake.getHeight() / 4 * 10 + 40 );

    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("HARD");
    menu[2].setPosition(180, snake.getHeight() / 4 * 10 + 80 );

    menu[3].setFont(font);
    menu[3].setFillColor(sf::Color::White);
    menu[3].setString("EXIT");
    menu[3].setPosition(180, snake.getHeight() / 4 * 10 + 120 );

    selectedOption = 0;

}

void MenuSFMLView::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for( int i = 0; i < 4; i++)
    {
        target.draw(menu[i],states);
    }
    target.draw(gameName,states);

}

void MenuSFMLView::Up() {
    if( selectedOption - 1 >= 0)
    {
        menu[selectedOption].setFillColor(sf::Color::White);
        selectedOption--;
        menu[selectedOption].setFillColor(sf::Color::Red);
    }
}

void MenuSFMLView::Down() {
    if( selectedOption + 1 < 4)
    {
        menu[selectedOption].setFillColor(sf::Color::White);
        selectedOption++;
        menu[selectedOption].setFillColor(sf::Color::Red);
    }
}

int MenuSFMLView::getSelectedOption() const {
    return selectedOption;
}
