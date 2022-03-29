#include <iostream>
#include "Snake.h"
using namespace std;

Snake::Snake(int height, int width) : height(height), width(width) {
    status = RUNNING;
    screen = MENU;

    snake.push_back({height/2,width/2});

    pointpos.x = rand() % width;
    pointpos.y = rand() % height;
}

void Snake::debug_display() const {
    for (int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {
            if( snake[0].x == x && snake[0].y == y)
                cout<<"G";
            else{
                bool print = false;
                for (int i = 1; i < snake.size(); i++) {
                    if (snake[i].x == x && snake[i].y == y){
                        cout << "o";
                        print = true;
                    }
                    if (pointpos.x == x && pointpos.y == y){
                        cout << "X";
                        print = true;
                    }

                }
                for(auto i : wall)
                {
                    if(i.x == x && i.y == y)
                    {
                        cout << "#";
                        print = true;
                    }
                }
                if(!print)
                    cout << ".";
            }
        }
        cout<<endl;
    }
}

int Snake::getHeight() const {
    return height;
}

int Snake::getWidth() const {
    return width;
}

void Snake::update(){
    if(dir == STOP)
        return;
    if(dir == LEFT)
        snake[0].x-=1;
    if(dir == RIGHT)
        snake[0].x+=1;
    if(dir == UP)
        snake[0].y-=1;
    if(dir == DOWN)
        snake[0].y+=1;;


        for( int i = snake.size()-1; i > 0; i--) // podążanie ciała za głową
        {
            snake[i].x = snake[i-1].x;
            snake[i].y = snake[i-1].y;
        }

        // przechodzanie przez krawędzie planszy
    if (snake[0].x == width)
        snake[0].x = 0;
    if (snake[0].x < 0)
        snake[0].x = width;
    if (snake[0].y == height)
        snake[0].y = 0;
    if (snake[0].y < 0)
        snake[0].y = height;
}

void Snake::move(int d) {
    if( d == 0)
        dir = STOP;
    if(d == 1 && dir != RIGHT)
        dir=LEFT;
    if(d == 2 && dir != LEFT)
        dir=RIGHT;
    if(d == 3 && dir != DOWN)
        dir=UP;
    if(d == 4 && dir != UP)
        dir=DOWN;
}

GameStatus Snake::getStatus() const {
    return status;
}

Direction Snake::getDir() const {
    return dir;
}

int Snake::getScore() const {
    return score;
}


int Snake::getSnakePositionX() const {
    return snake[0].x;
}

int Snake::getSnakePositionY() const {
    return snake[0].y;
}

int Snake::getPointPositionX() const {
    return pointpos.x;
}

int Snake::getPointPositionY() const {
    return pointpos.y;
}

int Snake::getSnakeLength() const {
    return snake.size();
}

void Snake::add_Wall() {
    for(int i = 7; i < 42; i++)
        wall.push_back({i,7});
    for(int i = 7; i < 42; i++)
        wall.push_back({i,42});

    for(int i = 7; i < 15; i++)
        wall.push_back({7,i});
    for(int i = 34; i < 42; i++)
        wall.push_back({7,i});

    for(int i = 7; i < 15; i++)
        wall.push_back({41,i});
    for(int i = 34; i < 42; i++)
        wall.push_back({41,i});
}

int Snake::getMode() const {
    return mode;
}

void Snake::GameLogic() {
    if (status == RUNNING) {
        addPoint();

        bool rv = checkColision();
        if (rv) {
            status = LOSE;
            saveScore();
            loadScore();
        }
    }
}



void Snake::setGameMode(int lvl) {
    clearBoard();
    if(lvl == 1)
    {
        mode = EASY;
        screen = GAME;
    }
    if(lvl == 2)
    {
        mode = MEDIUM;
        screen = GAME;
    }
    if(lvl == 3)
    {
        mode = HARD;
        screen = GAME;
        add_Wall();
    }
    if(lvl == 0)
        return;
}

const vector<SnakePos> &Snake::getSnake() const {
    return snake;
}

const vector<WallPos> &Snake::getWall() const {
    return wall;
}

Screen Snake::getScreen() const {
    return screen;
}

void Snake::setScreen(int sc) {
    if( sc == 1 )
        screen = MENU;
    if( sc == 2 ) {
        resume();
        screen = GAME;
    }
    if( sc == 3 )
        screen = SCOREBOARD;
    if( sc == 0 )
        screen = EXIT;
}

Snake::~Snake() {

}

void Snake::clearBoard() {
    snake.clear();
    wall.clear();
    score=0;
    scoreboard.clear();
    snake.push_back({height/2,width/2});
    pointpos.x = rand() % width;
    pointpos.y = rand() % height;
}


const vector<int> &Snake::getScoreboard() const {
    return scoreboard;
}

void Snake::pause() {
    status = PAUSE;
    dir = STOP;
}

void Snake::resume() {
    status = RUNNING;
}

bool Snake::checkColision() { // sprawdza kolizję głowy ze ścianą lub ciałem
    for(auto & i : wall){
        if( (snake[0].x == i.x) && (snake[0].y == i.y) ) {
            move(0);
            setScreen(3);
            std::cout<<"COLLISION"<<std::endl;
            return true;
        }
    }

    /*
    for(int i = 1; i < snake.size(); i++) // sprawdzanie kolizji głowy z resztą ciała nie działa
    {
        if( snake[0].x == snake[i].x && snake[0].y == snake[i].y )
        {
           move(0);
            setScreen(3);
            status = LOSE;
           std::cout<<"COLLISION"<<std::endl;
            return true;
       }
    }
*/
    return false;
}

void Snake::saveScore() {
    scoreFile.open("scoreboard/score.txt", std::ios::in | std::ios::out);
    if(scoreFile.good())
    {
        points.push_back(score);

        for(int i = 0; i <points.size(); i++)
        {
            scoreFile<<points[i]<< std::endl;
        }
        scoreFile.close();
    }
}

void Snake::loadScore() {
    scoreFile.open("scoreboard/score.txt", std::ios::in | std::ios::out);
    if(scoreFile.good())
    {
        std::string tmp;
        while(scoreFile >> tmp){
            int x = std::stoi(tmp);
            scoreboard.push_back(x);
        }
        scoreFile.close();
    }
}

void Snake::addPoint() { // dodaje punkt na planszy, dodaje punkt do wyniku, powiększa węża
    for (auto & i : wall) {
        if ((pointpos.x == i.x) && (pointpos.y == i.y)) {
            pointpos.x = rand() % width;
            pointpos.y = rand() % height;
        }
    }

    if ((snake[0].x == pointpos.x) && (snake[0].y == pointpos.y)) {

        pointpos.x = rand() % width;
        pointpos.y = rand() % height;
        if (mode == EASY) {
            score += 10;
            snake.push_back({snake.back().x,snake.back().y});
            snake.push_back({snake.back().x,snake.back().y});

        }
        if (mode == MEDIUM) {
            score += 15;
            snake.push_back({snake.back().x,snake.back().y});
            snake.push_back({snake.back().x,snake.back().y});
            snake.push_back({snake.back().x,snake.back().y});

        }
        if (mode == HARD) {
            score += 20;
            snake.push_back({snake.back().x,snake.back().y});
            snake.push_back({snake.back().x,snake.back().y});
            snake.push_back({snake.back().x,snake.back().y});
            snake.push_back({snake.back().x,snake.back().y});

        }
    }
}


