#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include <cstdio>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <sstream>
#include <string>
#include <thread>
#include <fstream>

#include "network.h"
#include "SettingsParser.hpp"
#include "sprite.h"
#include "text.h"
#include "player.h"
#include "mymap.h"
#include "button.h"
#include "ProgressBar.hpp"
#include "form.h"
#include "core.h"

#define DEFAULT_FONT "data/Caviar Dreams.ttf"
#define make_life_better abort();

using namespace std;
//using namespace sf;

    string IntToString(int);
    string FloatToStr(float);
    string WORDToStr(WORD);
    string BoolToStr(bool);
    float StringToFloat(string);
    int GetFrameRate();
    int GetXCord(string);
    int GetYCord(string);
    int GetXCordFS(string);
    int GetYCordFS(string);
    string GetPID(string);
    string GetPIDfromC(string);
    void getPlayerData(string temp, sf::Vector2f& p, int& isIdle, int& isBack, int& dir, float& speed, int& CurrentFrame);
    void getPlayerData2(string temp, sf::Vector2f& p, int& isIdle, int& isBack, int& dir, float& speed, int& CurrentFrame);

    void SCTitle(int, string);
    HWND GetConsoleHwnd(void);
    void MakeDISASTER();
    void drawText(sf::RenderWindow& window, sf::Font& font, unsigned int size, float x, float y, string text);
    void drawText(sf::RenderWindow& window, sf::Font& font, unsigned int size, string text);
    void startServerUI(sf::RenderWindow* win);

#endif // HEADER_H_INCLUDED
