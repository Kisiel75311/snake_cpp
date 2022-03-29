#ifndef SNAKE_MAP_H
#define SNAKE_MAP_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <fstream>

enum Direction {LEFT, RIGHT, UP, DOWN, STOP};
enum GameStatus {RUNNING, WIN, LOSE, PAUSE};
enum GameMode {EASY, MEDIUM, HARD};
enum Screen {MENU, GAME, SCOREBOARD, EXIT};

struct SnakePos
{
    int x;
    int y;
};

struct PointPos
{
    int x;
    int y;
};

struct WallPos
{
    int x;
    int y;
};

class Snake {
    int height;
    int width;
    int score = 0;
    PointPos pointpos;
    Direction dir;
    GameStatus status;
    GameMode mode;
    Screen screen;
    std::fstream scoreFile;
    std::vector <int> points;
public:
    std::vector <int> scoreboard;
    std::vector <SnakePos> snake;
    std::vector <WallPos> wall;

    virtual ~Snake();

    const std::vector<int> &getScoreboard() const;

    Snake(int height, int width);

    int getHeight() const;

    int getWidth() const;

    int getSnakePositionX() const;

    const std::vector<SnakePos> &getSnake() const;

    const std::vector<WallPos> &getWall() const;

    int getSnakePositionY() const;

    int getPointPositionX() const;

    int getPointPositionY() const;

    int getSnakeLength() const;

    int getMode() const;

    Screen getScreen() const;

    GameStatus getStatus() const;

    Direction getDir() const;

    int getScore() const;

    void debug_display() const;

    void update();

    void add_Wall();

    void move(int d);

    void GameLogic();

    void setGameMode(int lvl);

    void setScreen(int sc);

    void clearBoard();

    void saveScore();

    void loadScore();

    void pause();

    void resume();

    bool checkColision();

    void addPoint();

};


#endif 