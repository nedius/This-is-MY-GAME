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
                fireI.loadFromFile("data/tex/fire.png");
                fireI.createMaskFromColor(sf::Color(0,0,0));
                fireT.loadFromImage(fireI);
                fire.setTexture(fireT);
                fire.setOrigin(fire.getLocalBounds().width/2, fire.getLocalBounds().height/2);
                fire.setScale(0.27, 0.27);
                x = X; y = Y;
                spawnX=X; spawnY=Y;
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
                                if (dy<0) { y = (i * sprite_p + sprite_p); }//system("start chrome http://coub.com/nedfavre"); }
                                if (dx>0) { x = (j * sprite_p - w/4); x=250; y=4170; dir=1; speed=0; inCave=true; } //157.972x 4173.07y
                                if (dx<0) x = (j * sprite_p + sprite_p)+w/6;
                            }

                            if (inCave){
                                int i = ((int)y-40*sprite_p) / sprite_p;
                                if (tiledMap.getTileIDC(i, j) == 't' || tiledMap.getTileIDC(i, j) == 'C' || tiledMap.getTileIDC(i, j) == 'D'){
                                    if (dy>0) y = (i * sprite_p + 3840 - h/16); //
                                    if (dy<0) y = (i * sprite_p + 3840 + sprite_p);
                                    if (dx>0) x = (j * sprite_p - w/4); //
                                    if (dx<0) x = (j * sprite_p + sprite_p)+w/6;
                                }

                               if (i==3 && j==0){ x=520; y=1275; }

                                if (tiledMap.getTileIDCB(i, j) == 'l' || tiledMap.getTileIDCB(i, j) == 'v' ) {
                                    isOnFire=true;
                                    fire_timer=100;
                                }else{ isOnFire=false;
                                        if(fire_timer!=0) fire_timer--;
                                }

                            }



                            //if (tiledMap.getTileID(i, j) == 'a') {
                            //    x = 300; y = 300;
                            //    tiledMap.setTileID(i, j, ' ');
                            //}

                            if (tiledMap.getTileIDB(i, j) == 'l' || tiledMap.getTileIDB(i, j) == 'v' ) {
                                isOnFire=true;
                                fire_timer=100;
                            }else{ isOnFire=false;
                                    if(fire_timer!=0) fire_timer--;
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
             if(health<=100) health+=0.01*time;
             if(isOnFire) if(health>0) health-=0.1*time;
             if(fire_timer>0) if(health>0) health-=0.1*time;
             if(health>100) health=100;
             //cout<<health<<" HP"<<endl;
             //if(health<=0) dead=true; else dead=false;
             if(y>32*40*tiledMap.getMapScale()) inCave=true; else inCave=false;
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
        if(isOnFire || fire_timer!=0){
            //fire.setOrigin(fire.getGlobalBounds().width/2, fire.getGlobalBounds().height/2);
            if(tiledMap.getFrame()==1) fire.setScale(-0.27, 0.27); else fire.setScale(0.27, 0.27);
            fire.setPosition(sprite.getPosition().x, sprite.getPosition().y); //-sprite.getGlobalBounds().width/2 -sprite.getGlobalBounds().height/2
        }
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
        if(isOnFire || fire_timer!=0) window.draw(fire);
        hasFocus=window.hasFocus();
    }

    void Player::changeCharacter(int characterID=0){
        if(characterID==0)
            {
                if(File=="Pope_Casual") File="Ezella";
                else if(File=="Ezella") File="Pope_Casual";
            }
        if(characterID==-1) File="Pope_Casual";
        if(characterID==-2) File="Ezella";
        image.loadFromFile("data/tex/" + File + ".png");
        image.createMaskFromColor(sf::Color(0,0,0));
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        chChanged=true;
        Sleep(100);
    }

    bool Player::isCharacterChanged(){
        if(chChanged){ chChanged=false; return true;}
        return false;
    }

    string Player::getCharacter(){
        return File;
    }

    int Player::getHealth(){
        return health;
    }

    void Player::setHealth(int newHealth){
        health=newHealth;
    }

    void Player::setDeath(){
        health=100;
        isOnFire=false;
        fire_timer=0;
    }

    bool Player::isInCave(){
        return inCave;
    }

    void Player::toSpawn(){
        x=spawnX;
        y=spawnY;
    }
