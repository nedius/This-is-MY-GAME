#include "../include/header.h"

        Text::Text(sf::RenderWindow& win): window(win){
            //window(win);
            //window=win;
        }

        void Text::loadfont(string dawae){
            if (!font.loadFromFile(dawae.c_str())) { cout<<"Missing some font: \""<<dawae<<"\"!"<<endl; }else{
                    tekst.setFont(font);
                }

        }

        void Text::setColor(int r, int g, int b){
            //image.createMaskFromColor(sf::Color(r, g, b), alpha);
            //texture.loadFromImage(image);
            //sprite.setTexture(texture);
            tekst.setFillColor(sf::Color(r, g, b));
        }

        void Text::move(float x, float y){
            tekst.move(x, y);
        }

        void Text::setposition(sf::Vector2f cord){
            tekst.setPosition(cord);
        }

        void Text::setString(string newText){
            tekst.setString(newText);
        }

        void Text::setStyle(unsigned short style){
            switch(style){
                case 0:{
                        tekst.setStyle(sf::Text::Regular);
                        break;
                        }
                case 1:{
                        tekst.setStyle(sf::Text::Italic);
                        break;
                        }
                case 2:{
                        tekst.setStyle(sf::Text::Bold);
                        break;
                        }
                case 3:{
                        tekst.setStyle(sf::Text::Bold | sf::Text::Italic);
                        break;
                        }
            }
        }

        void Text::setCharacterSize(unsigned Size){
            tekst.setCharacterSize(Size);
        }

        void Text::draw(){
            window.draw(tekst);
        }
