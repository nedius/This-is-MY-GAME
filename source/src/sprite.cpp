#include "../include/header.h"

        Sprite::Sprite(sf::RenderWindow& win): window(win){
            //window(win);
            //window=win;
        }

        void Sprite::loadimage(string dawae){
            if (!image.loadFromFile(dawae.c_str())) { cout<<"Missing some image: \""<<dawae<<"\"!"<<endl; }else{
                    texture.loadFromImage(image);
                    texture.setSmooth(true);
                    sprite.setTexture(texture);
                }
        }

        void Sprite::setTransperent(int r, int g, int b, int alpha){
            image.createMaskFromColor(sf::Color(r, g, b), alpha);
            texture.loadFromImage(image);
            sprite.setTexture(texture);
        }

        void Sprite::move(float x, float y){
            sprite.move(x, y);
        }

        void Sprite::setposition(sf::Vector2f cord){
            sprite.setPosition(cord);
        }

        void Sprite::setposition(sf::Vector2i cord){
            sprite.setPosition(cord.x, cord.y);
        }

        void Sprite::setScale(float x, float y){
            sprite.setScale(x, y);
        }

        void Sprite::resize(){
            sf::Vector2f targetSize(window.getView().getSize());
            sprite.setScale(1, 1);
            //sprite.scale(targetSize.x / sprite.getLocalBounds().width, targetSize.y / sprite.getLocalBounds().height);
            sprite.scale(sprite.getLocalBounds().width / targetSize.x, sprite.getLocalBounds().height / targetSize.y);
        }

        void Sprite::draw(){
            window.draw(sprite);
        }
