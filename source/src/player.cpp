#include "../include/header.h"
//#include "../include/map.h"

    Player::Player(string F, float X, float Y, float W, float H, MyMap& temp) : tiledMap(temp){
                //tiledMap=temp;
                dx=0;dy=0;speed=0;dir=0;
                File = F;
                w = W; h = H;
                image.loadFromFile("data/tex/" + File + ".png");
                image.createMaskFromColor(sf::Color(0,0,0));
                texture.loadFromImage(image);
                sprite.setTexture(texture);
                x = X; y = Y;
                sprite.setTextureRect(sf::IntRect(13, 250, w, h));
             }

    void Player::setTileMap(MyMap& temp){ ///dont need
                //for(int i=0;i<40;i++){
                //for(int j=0;j<43-1;j++)
                //tileMap[i]=temp[i];
                //cout<<i<<"i "<<endl;}

                //for(int i=0;i<40;i++){
                //for(int j=0;j<43;j++){ cout<<tileMap[i][j]; } cout<<endl; }
            }

    float Player::getPlayerCoordinateX(){
                return x;
            }

    float Player::getPlayerCoordinateY(){
                return y;
            }

    void Player::interactionWithMap(){
                int sprite_p=32*tiledMap.getMapScale();
                sprite.setOrigin(w/2, h/2);

                        for (int i = (int)y / sprite_p; i < ((int)y + h/2) / sprite_p; i++)
                        for (int j = (int)x / sprite_p; j < ((int)x + w/4) / sprite_p; j++){
                            if (tiledMap.getTileID(i, j) == '1' || tiledMap.getTileID(i, j) == 'h' || tiledMap.getTileID(i, j) == 'i' || tiledMap.getTileID(i, j) == 'u' || tiledMap.getTileID(i, j) == 'E' ){
                                if (dy>0) y = (i * sprite_p - h/2); //
                                if (dy<0) y = (i * sprite_p + sprite_p);
                                if (dx>0) x = (j * sprite_p - w/4); //
                                if (dx<0) x = (j * sprite_p + sprite_p)+w/6;
                            }

                            if (tiledMap.getTileID(i, j) == 'r' || tiledMap.getTileID(i, j) == 's'){
                                if (dy>0) y = (i * sprite_p - h/2);
                                if (dy<0) { y = (i * sprite_p + sprite_p); if(hasFocus) if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) MakeDISASTER(); }//system("start chrome http://coub.com/nedfavre"); }
                                if (dx>0) x = (j * sprite_p - w/4);
                                if (dx<0) x = (j * sprite_p + sprite_p)+w/6;
                            }

                            if (tiledMap.getTileID(i, j) == 'a') {
                                x = 300; y = 300;
                                tiledMap.setTileID(i, j, ' ');
                            }
                        }
                }

    void Player::update(float time){
             switch (dir)
                 {
                     case 0: dx = speed; dy = 0; break;     ///left
                     case 1: dx = -speed; dy = 0; break;    ///right
                     case 2: dx = 0; dy = speed; break;     ///down
                     case 3: dx = 0; dy = -speed; break;    ///up
                 }

             x += dx*time;
             y += dy*time;


             speed = 0;
             sprite.setPosition(x,y);
             interactionWithMap();
             }

    void Player::impulse(int dir, float speed){
        this->dir=dir; this->speed=speed;
    }

    void Player::animate(string id, float CurrentFrame, int isBack){
        this->CurrentFrame=CurrentFrame; this->isBack=isBack;
        if(File=="Pope_Casual"){
            if(id=="up") sprite.setTextureRect(getIntRect(id, CurrentFrame, isBack));
            if(id=="down") sprite.setTextureRect(getIntRect(id, CurrentFrame, isBack));
            if(id=="left"){ sprite.setTextureRect(getIntRect(id, CurrentFrame, isBack)); sprite.setScale(1,1); }
            if(id=="right"){ sprite.setTextureRect(getIntRect(id, CurrentFrame, isBack)); sprite.setScale(-1,1); }
            if(id=="upI") sprite.setTextureRect(getIntRect(id, CurrentFrame, isBack));
            if(id=="downI") sprite.setTextureRect(getIntRect(id, CurrentFrame, isBack));
        }
        if(File=="Ezella"){
            if(CurrentFrame>6) CurrentFrame-=CurrentFrame;
            if(id=="up") sprite.setTextureRect(getIntRect(id, CurrentFrame, isBack));
            if(id=="down") sprite.setTextureRect(getIntRect(id, CurrentFrame, isBack));
            if(id=="left"){ sprite.setTextureRect(getIntRect(id, CurrentFrame, isBack)); sprite.setScale(1,1); }
            if(id=="right"){ sprite.setTextureRect(getIntRect(id, CurrentFrame, isBack)); sprite.setScale(-1,1); }
            if(id=="upI") sprite.setTextureRect(getIntRect(id, CurrentFrame, isBack));
            if(id=="downI") sprite.setTextureRect(getIntRect(id, CurrentFrame, isBack));
        }
        //sprite.setTextureRect(intrect);
    }

    sf::IntRect Player::getIntRect(string id, int CurrentFrame, int isBack){
            if(File=="Pope_Casual"){
                h=h1; w=w1;
                if(id=="left")  switch(CurrentFrame){ //left
                                case 0: return sf::IntRect(13 + 80*0, 250+(121*(isBack-1)), w1, h1); break;
                                case 1: return sf::IntRect(13 + 80*1, 250+(121*(isBack-1)), w1, h1); break;
                                case 2: return sf::IntRect(13 + 80*2, 250+(121*(isBack-1)), w1, h1); break;
                                case 3: return sf::IntRect(13 + 80*3, 250+(121*(isBack-1)), w1, h1); break;
                                case 4: return sf::IntRect(13 + 80*4, 250+(121*(isBack-1)), w1, h1); break;
                                case 5: return sf::IntRect(13 + 80*5, 250+(121*(isBack-1)), w1, h1); break;
                                case 6: return sf::IntRect(13 + 80*6, 250+(121*(isBack-1)), w1, h1); break;
                                case 7: return sf::IntRect(13 + 80*7, 250+(121*(isBack-1)), w1, h1); break;
                                }
                if(id=="right")  switch(CurrentFrame){ //right
                                case 0: return sf::IntRect(13 + 80*0, 250+(121*(isBack-1)), w1, h1); break;
                                case 1: return sf::IntRect(13 + 80*1, 250+(121*(isBack-1)), w1, h1); break;
                                case 2: return sf::IntRect(13 + 80*2, 250+(121*(isBack-1)), w1, h1); break;
                                case 3: return sf::IntRect(13 + 80*3, 250+(121*(isBack-1)), w1, h1); break;
                                case 4: return sf::IntRect(13 + 80*4, 250+(121*(isBack-1)), w1, h1); break;
                                case 5: return sf::IntRect(13 + 80*5, 250+(121*(isBack-1)), w1, h1); break;
                                case 6: return sf::IntRect(13 + 80*6, 250+(121*(isBack-1)), w1, h1); break;
                                case 7: return sf::IntRect(13 + 80*7, 250+(121*(isBack-1)), w1, h1); break;
                                }
                if(id=="down")  switch(CurrentFrame){ //down
                                case 0: return sf::IntRect(13 + 80*0, 250+(121*(dir-2)), w1, h1); break;
                                case 1: return sf::IntRect(13 + 80*1, 250+(121*(dir-2)), w1, h1); break;
                                case 2: return sf::IntRect(13 + 80*2, 250+(121*(dir-2)), w1, h1); break;
                                case 3: return sf::IntRect(13 + 80*3, 250+(121*(dir-2)), w1, h1); break;
                                case 4: return sf::IntRect(13 + 80*4, 250+(121*(dir-2)), w1, h1); break;
                                case 5: return sf::IntRect(13 + 80*5, 250+(121*(dir-2)), w1, h1); break;
                                case 6: return sf::IntRect(13 + 80*6, 250+(121*(dir-2)), w1, h1); break;
                                case 7: return sf::IntRect(13 + 80*7, 250+(121*(dir-2)), w1, h1); break;
                                }
                if(id=="up")  switch(CurrentFrame){ //up
                                case 0: return sf::IntRect(13 + 80*0, 250+(121*(dir-2)), w1, h1); break;
                                case 1: return sf::IntRect(13 + 80*1, 250+(121*(dir-2)), w1, h1); break;
                                case 2: return sf::IntRect(13 + 80*2, 250+(121*(dir-2)), w1, h1); break;
                                case 3: return sf::IntRect(13 + 80*3, 250+(121*(dir-2)), w1, h1); break;
                                case 4: return sf::IntRect(13 + 80*4, 250+(121*(dir-2)), w1, h1); break;
                                case 5: return sf::IntRect(13 + 80*5, 250+(121*(dir-2)), w1, h1); break;
                                case 6: return sf::IntRect(13 + 80*6, 250+(121*(dir-2)), w1, h1); break;
                                case 7: return sf::IntRect(13 + 80*7, 250+(121*(dir-2)), w1, h1); break;
                                }

                if(id=="upI" || id=="downI")  switch(CurrentFrame){
                                case 0: return sf::IntRect(13 + 80*0, 10+(121*(isBack-1)), w1, h1); break;
                                case 1: return sf::IntRect(13 + 80*1, 10+(121*(isBack-1)), w1, h1); break;
                                case 2: return sf::IntRect(13 + 80*2, 10+(121*(isBack-1)), w1, h1); break;
                                case 3: return sf::IntRect(13 + 80*3, 10+(121*(isBack-1)), w1, h1); break;
                                case 4: return sf::IntRect(13 + 80*4, 10+(121*(isBack-1)), w1, h1); break;
                                case 5: return sf::IntRect(13 + 80*5, 10+(121*(isBack-1)), w1, h1); break;
                                }
            }
            if(File=="Ezella"){
                if(id=="left"){
                    if(isBack-1){ w=54; h=100;
                                switch(CurrentFrame){
                                case 0: return sf::IntRect(0, 103, 54, 100);  break;
                                case 1: return sf::IntRect(55, 103, 54, 100); break;
                                case 2:  w=54+1; return sf::IntRect(110, 103, 54+1, 100); break;
                                case 3:  w=54+2; return sf::IntRect(166, 103, 54+2, 100); break;
                                case 4:  w=54+2; return sf::IntRect(223, 103, 54+2, 100); break;
                                case 5:  w=54+1; return sf::IntRect(280, 103, 54+1, 100); break;
                                }
                        }else{  w=54; h=102; switch(CurrentFrame){
                                case 0: return sf::IntRect(0 , 0, 45, 102); break;
                                case 1: w=54-1; return sf::IntRect(46, 0, 45-1, 102); break;
                                case 2: return sf::IntRect(91, 0, 45, 102); break;
                                case 3: w=54+1; return sf::IntRect(137, 0, 45+1, 102); break;
                                case 4: w=54+2; return sf::IntRect(184, 0, 45+2, 102); break;
                                case 5: w=54+1; return sf::IntRect(232, 0, 45+1, 102); break;
                                }}}
                if(id=="right"){
                    if(isBack-1){ w=54; h=100;
                                switch(CurrentFrame){
                                case 0: return sf::IntRect(0, 103, 54, 100);  break;
                                case 1: return sf::IntRect(55, 103, 54, 100); break;
                                case 2:  w=54+1; return sf::IntRect(110, 103, 54+1, 100); break;
                                case 3:  w=54+2; return sf::IntRect(166, 103, 54+2, 100); break;
                                case 4:  w=54+2; return sf::IntRect(223, 103, 54+2, 100); break;
                                case 5:  w=54+1; return sf::IntRect(280, 103, 54+1, 100); break;
                                }
                        }else{ w=54; h=102; switch(CurrentFrame){
                                case 0: return sf::IntRect(0 , 0, 45, 102); break;
                                case 1: w=54-1; return sf::IntRect(46, 0, 45-1, 102); break;
                                case 2: return sf::IntRect(91, 0, 45, 102); break;
                                case 3: w=54+1; return sf::IntRect(137, 0, 45+1, 102); break;
                                case 4: w=54+2; return sf::IntRect(184, 0, 45+2, 102); break;
                                case 5: w=54+1; return sf::IntRect(232, 0, 45+1, 102); break;
                                }}}
                if(id=="down"){ w=54; h=102; switch(CurrentFrame){
                                case 0: return sf::IntRect(0 , 0, 45, 102); break;
                                case 1: w=54-1; return sf::IntRect(46, 0, 45-1, 102); break;
                                case 2: return sf::IntRect(91, 0, 45, 102); break;
                                case 3: w=54+1; return sf::IntRect(137, 0, 45+1, 102); break;
                                case 4: w=54+2; return sf::IntRect(184, 0, 45+2, 102); break;
                                case 5: w=54+1; return sf::IntRect(232, 0, 45+1, 102); break;
                                }}
                if(id=="up"){ w=54; h=100; switch(CurrentFrame){
                                case 0: return sf::IntRect(0, 103, 54, 100);  break;
                                case 1: return sf::IntRect(55, 103, 54, 100); break;
                                case 2:  w=54+1; return sf::IntRect(110, 103, 54+1, 100); break;
                                case 3:  w=54+2; return sf::IntRect(166, 103, 54+2, 100); break;
                                case 4:  w=54+2; return sf::IntRect(223, 103, 54+2, 100); break;
                                case 5:  w=54+1; return sf::IntRect(280, 103, 54+1, 100); break;
                                }}

                if(id=="upI"){ w=54; h=100; switch(CurrentFrame){
                                case 0: return sf::IntRect(0, 103, 54, 100);  break;
                                case 1: return sf::IntRect(55, 103, 54, 100); break;
                                case 2:  w=54+1; return sf::IntRect(110, 103, 54+1, 100); break;
                                case 3:  w=54+2; return sf::IntRect(166, 103, 54+2, 100); break;
                                case 4:  w=54+2; return sf::IntRect(223, 103, 54+2, 100); break;
                                case 5:  w=54+1; return sf::IntRect(280, 103, 54+1, 100); break;
                                }}
                if(id=="downI"){ w=54; h=102; switch(CurrentFrame){
                                case 0: return sf::IntRect(0 , 0, 45, 102); break;
                                case 1: w=54-1; return sf::IntRect(46, 0, 45-1, 102); break;
                                case 2: return sf::IntRect(91, 0, 45, 102); break;
                                case 3: w=54+1; return sf::IntRect(137, 0, 45+1, 102); break;
                                case 4: w=54+2; return sf::IntRect(184, 0, 45+2, 102); break;
                                case 5: w=54+1; return sf::IntRect(232, 0, 45+1, 102); break;
                                }}

            }
            return sf::IntRect(0, 0, 64, 64);
    }///sf::IntRect(0 + 45*int(CurrentFrame), 104, 53, 102)

    void Player::setScale(float x, float y){
        sprite.setScale(x, y);
    }

    sf::Vector2f Player::getPosition(){
        return sprite.getPosition();
    }

    void Player::setPosition(float x, float y){
        this->x=x; this->y=y;
    }

    void Player::draw(sf::RenderWindow& window){
        window.draw(sprite);
        hasFocus=window.hasFocus();
    }

    void Player::changeCharacter(){
        if(File=="Pope_Casual") File="Ezella";
        else if(File=="Ezella") File="Pope_Casual";
        image.loadFromFile("data/tex/" + File + ".png");
        image.createMaskFromColor(sf::Color(0,0,0));
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        Sleep(100);
    }

    string Player::getCharacter(){
        return File;
    }
