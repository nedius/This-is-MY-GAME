#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

//#include <string>
#include "header.h"
//using namespace std;

    class Button{
        private:
            sf::RenderWindow& window;

            float x=0, y=0;
            float cornerX=0, cornerY=0;
            int m_cornerX=0, m_cornerY=0;
            int W=0, H=0;
            int origW=100, origH=50;

            sf::RectangleShape rectangle;

            sf::Font font;
            string text="example";
            sf::Text caption;

            //sf::Color fillC(100, 250, 50);
            //sf::Color borderC(0, 25, 50);
            //sf::Color transC(sf::Color::Transparent);

            bool isSelected=false;
            bool isPressed=false;
            bool isCustomSize=false;

        public:
            Button(sf::RenderWindow& window, int w, int h);
            void setSize(int w, int h);
            sf::Vector2i getSize();
            void setString(string str);
            void setCustomSize(bool bolean);
            void move(float x, float y);
            bool isKeyPressed(bool event);
            void draw(sf::Vector2i mouse);
    };



#endif // BUTTON_H_INCLUDED
