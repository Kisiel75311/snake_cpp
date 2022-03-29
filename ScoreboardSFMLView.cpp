
#include <string>
#include <iostream>
#include <cstring>
#include "ScoreboardSFMLView.h"

ScoreboardSFMLView::ScoreboardSFMLView(Snake &snake) : snake(snake) {
    if ( ! font.loadFromFile("fonts/BigSpace-rPKx.ttf") )
    {
        //PROBLEM!!!
        std::cerr << strerror(errno) << std::endl;
        abort();
    }
}

void ScoreboardSFMLView::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(text,states);
    for(int i=0; i < 100; i++)
        target.draw(scoreboard[i],states);
}

void ScoreboardSFMLView::setScoreboard() {

    std::sort(snake.scoreboard.begin(), snake.scoreboard.end(), std::greater<int>());



    text.setFont(font);
    text.setString("Scoreboard");
    text.setCharacterSize(70);
    text.setFillColor(sf::Color(151, 219, 5));
    text.setPosition(80, snake.getHeight() / 4);

    scoreboard[11].setFont(font);
    scoreboard[11].setString("Press ESC to back to MENU");
    scoreboard[11].setFillColor(sf::Color::White);
    scoreboard[11].setPosition(40, snake.getHeight() / 2 * 10 + 200);

      for (int i = 0; i < 10 ; i++) {
       scoreboard[i].setFont(font);
      scoreboard[i].setString(std::to_string(i+1) + ".   " + std::to_string(snake.scoreboard[i]));
      scoreboard[i].setFillColor(sf::Color::White);
      scoreboard[i].setPosition(40, snake.getHeight() / 2 * i + 100);
     }
}