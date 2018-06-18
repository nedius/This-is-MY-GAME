#ifndef CORE_H_INCLUDED
#define CORE_H_INCLUDED

//#include <SFML/Network.hpp>
//#include <SFML/System.hpp>
//#include <SFML/Window.hpp>
//#include <SFML/Audio.hpp>
//#include <SFML/Graphics.hpp>
//#include <SFML/Graphics/Color.hpp>
//#include <SFML/Window/Keyboard.hpp>
//#include <SFML/OpenGL.hpp>
//#include <SFML/Graphics/Text.hpp>
//
//#include <iostream>
//#include <cstdio>
//#include <windows.h>
//#include <conio.h>
//#include <cstdlib>
//#include <sstream>
//#include <string>
//#include <thread>
//#include <fstream>
#include "button.h"


    using namespace std;
    ///this is good music https://www.youtube.com/watch?v=5det3Gkxngg
    ///this also https://www.youtube.com/watch?v=UY3mAoqQh0k

    class Core{
        private:
            Net& net;
            sf::IpAddress tempadsress;

            SettingsParser settings;

            bool fulls=false, statshow=true, cheatmode=false, isMusic=true, VerticalSyncEnabled=true, isDebug=false; //setings
            int fpslimits=60, musicVol=100;

            bool isIdle=true;
            unsigned short isBack=1;

            sf::Clock clock;
            float time = 0;
            float CurrentFrame = 0;
            float cursortime = 0;
            bool MouseReleased=false;
            //bool isMusicDevice=true;
            bool resHasChange=true;

            int windowX=1360, windowY=760;
            int fullWindowX, fullWindowY;

            sf::RenderWindow& window;

            string gameName="This is MY GAME", gameNameCH="This is MY GAME | CH";

            sf::View view;

            MyMap tiledMap;

            sf::Vector2i mouse;

            sf::Font font;

            sf::Text text;
            sf::Text fpsc;
            sf::Text p1pos;
            sf::Text p2pos;
            sf::Text resolution;

            sf::Music music;

            Player p; ///ezela kades
            Player pp;

            float speed=1;
            int dir=1;

            Text sometext;
            Sprite cursor;

            static const int masiveNumber=40;
            int elementNumber=0;

            string splash[masiveNumber] = {
                "Are you there ?", //1
                "002 13 6337",
                "OHAYO GOZAIMASU",
                "What you excepted here ?",
                "Make your face simplistic :)", //5
                "90% bug free! .. maybe ..",
                "Now supports ###!",
                "3.1415926535897932384",
                "**THIS IS SCREAMING TEXT**",
                "Who is DEGUR ???", //10
                "What are we doing here ?",
                "Dont forget about\n  srand(time(0));",
                "Something's not quite right...",
                "OOOOOF!",
                "Open Source!", //15
                "100% meme free!",
                "...!",
                "YAAY!",
                "Follow the train, CJ!",
                "C++", //20
                "  One day, somewhere\n       in the future,\nmy work will be quoted!",
                "Follow NeD ius!",
                "Singleplayer!",
                "Now With Multiplayer!", //25
                "It's a game!",
                "Rule #1: it's never my fault",
                "Rule #2: it's always your fault",
                "12345 is a bad password!",
                "C# = C++++", //30
                "Should not be played\n     while driving",
                "Who put it there?",
                "Not on steam!",
                "Follow N3D1U3!",
                "32x32 textures", //35
                "Try it!",
                "if not ok then return end",
                "I have crash function!",
                "Woah.",
                "-\\_({}{})_/-", //40
            };

            sw::ProgressBar progressBar;

            sf::Image bgimg;
            sf::Texture bgtex;
            sf::Sprite bgsprite;

            sf::Thread thread;

            //
        public:
            Core(Net& temp, sf::RenderWindow& win);
            void INTRO();
            int run();
            void menu();
            void YouDied();
            void save();
            void getSave();
            void client(string command);
            //
    };

#endif // CORE_H_INCLUDED
