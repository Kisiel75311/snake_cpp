#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "SnakeSFMLView.h"
#include "SnakeSFMLController.h"
#include "MenuSFMLView.h"
#include "MenuSFMLControl.h"
#include "ScoreboardSFMLView.h"
#include "ScoreboardSFMLController.h"

int main() {
    srand(time( NULL ) );
    Snake snake(50,50);

    SnakeSFMLView view(snake);
    SnakeSFMLController ctrl(snake, view);

    MenuSFMLView menu(snake);
    MenuSFMLControl menuCtrl(snake, menu);

    ScoreboardSFMLView scoreboard(snake);
    ScoreboardSFMLController scoreboardCtrl(snake, scoreboard);

    sf::RenderWindow win (sf::VideoMode(snake.getWidth()*10, snake.getHeight()*10), "Snake" );
    win.setVerticalSyncEnabled(true);

    sf::Clock clk;
    float timer=0;
    while (win.isOpen())
    {
        float time = clk.getElapsedTime().asSeconds();
        clk.restart();
        timer+=time;

        sf::Event event{};

        while (win.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                win.close();
                continue;
            }
            if(snake.getScreen() == MENU)
                menuCtrl.handleEvent(event);
            if(snake.getScreen() == GAME)
                ctrl.handleEvent(event);
            if(snake.getScreen() == SCOREBOARD)
                scoreboardCtrl.handleEvent(event);

        }

        if (timer>0.09)
        {
            timer=0;
            snake.update();
        }

        win.clear(sf::Color::Black);
        if(snake.getScreen() == MENU ){
            view.clearScreen();
            win.draw(menu);
        }
        if(snake.getScreen() == GAME){
            if(snake.getStatus() == PAUSE) {
                view.pauseScreen();
                win.draw(view);
            }
                view.updateView();
                win.draw(view);
                snake.GameLogic();
        }
        if(snake.getScreen() == SCOREBOARD){
            scoreboard.setScoreboard();
            win.draw(scoreboard);
        }
        win.display();
        if(snake.getScreen() == EXIT)
            win.close();
    }
}
