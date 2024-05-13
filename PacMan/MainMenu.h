#pragma once
#include <SFML/Graphics.hpp>
#include<stack>
#include <sstream>
#include<unordered_map>
#include <fstream>
#include <iostream>


using namespace sf;
using namespace std;

class MainMenu
{

public:
    MainMenu(float length, float width);
    unordered_map<int, Text> menuTexts;
    unordered_map<int, Sprite> levelSprites;
    unordered_map<int, Text> winTexts;
    unordered_map<int, Text> loseTexts;
    void drawmenu(RenderWindow& window);
    void drawLevels(RenderWindow& window);
    void drawWinTexts(RenderWindow& window);
    void drawloseTexts(RenderWindow& window);
    void up(int cn);
    void down(int cn);
    void left();
    void right();
    int selectChoice; //hardness selector
    int levelCntr; //levels maps selector
    int winChoice; //win options selector
    int loseChoice; //lose options selector
    int newhighscore;
    Texture l[3];


    int getHighestScore() {
        std::ifstream scoreFile("scores.txt");
        int score = 0, highestScore = 0;

        if (scoreFile.is_open()) {
            while (scoreFile >> score) { // Read each score
                highestScore = max(highestScore, score); // Update highest score found
            }
            cout << highestScore << "dddddddddddddddddddddddddddddddddddd";

            scoreFile.close();
        }
        else {
            std::cout << "Unable to open file to read scores." << std::endl;
        }

        return highestScore;
    }



    ~MainMenu();
private:
    Font font;
};
