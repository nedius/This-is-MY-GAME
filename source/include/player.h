#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "mymap.h"

    class Player{
        private:
            float dx, dy;
            //int dir;
            string File;
            string PlayerName;
            sf::Image image;
            sf::Image fireI;
            sf::Texture texture;
            sf::Texture fireT;

            MyMap& tiledMap;

            bool hasFocus=false;

            //float map_scale=4;
            //string tileMap[40];

            int dir;
            float speed;
            float x, y, h, w;
            float spawnX, spawnY;
            sf::Sprite sprite;
            sf::Sprite fire;


            float CurrentFrame=0;
            unsigned short isBack=1;

            bool chChanged=false;
            bool isOnFire=false;
            //bool dead=false;
            bool inCave=false;

            float health=100;
            int fire_timer=0;

            /// id1 Pope_Casual
            float w1=53, h1=86;
            //sf::IntRect upG1 = decltype(upG1)         (13 + 80*int(CurrentFrame), 250+(121*(isBack-1)), w1, h1);
            //sf::IntRect downG1 = decltype(downG1)     (13 + 80*int(CurrentFrame), 250+(121*(isBack-1)), w1, h1);
            //sf::IntRect leftG1 = decltype(leftG1)     (13 + 80*int(CurrentFrame), 250+(121*(isBack-1)), w1, h1);
            //sf::IntRect rightG1 = decltype(rightG1)   (13 + 80*int(CurrentFrame), 250+(121*(isBack-1)), w1, h1);
            //sf::IntRect upI1 = decltype(upI1)         (13 + 80*int(CurrentFrame), 10+(121*(isBack-1)), w1, h1);
            //sf::IntRect downI1 = decltype(downI1)     (13 + 80*int(CurrentFrame), 10+(121*(isBack-1)), w1, h1);

            /// id2 Ezella
            float w2=45, h2=94;
            //sf::IntRect upG2 = decltype(upG2)         (18 + 80*int(CurrentFrame), 250+(121*(isBack-1)), 45, 94);
            //sf::IntRect downG2 = decltype(downG2)     (22 + 80*int(CurrentFrame), 250+(121*(isBack-1)), 45, 94);
            //sf::IntRect leftG2 = decltype(leftG2)     (13 + 80*int(CurrentFrame), 250+(121*(isBack-1)), w2, h2);
            //sf::IntRect rightG2 = decltype(rightG2)   (13 + 80*int(CurrentFrame), 250+(121*(isBack-1)), w2, h2);
            //sf::IntRect upI2 = decltype(upI2)         (22 + 109*int(CurrentFrame), 20+(151*(isBack-1)), w2, h2);
            //sf::IntRect downI2 = decltype(downI2)     (22 + 109*int(CurrentFrame), 20+(151*(isBack-1)), w2, h2);

        public:
            Player(string F, float X, float Y, float W, float H, MyMap& temp);
            //~Player();
            void setTileMap(MyMap&);
            [[deprecated("use getPosition instead")]] float getPlayerCoordinateX();
            [[deprecated("use getPosition instead")]] float getPlayerCoordinateY();
            void interactionWithMap();
            void update(float time);
            void impulse(int dir, float speed);
            void animate(string id, float CurrentFrame, int isBack);
            sf::IntRect getIntRect(string id, int CurrentFrame, int isBack);
            void setScale(float x, float y);
            sf::Vector2f getPosition();
            void setPosition(float x, float y);
            void draw(sf::RenderWindow&);
            void changeCharacter(int characterID);
            bool isCharacterChanged();
            string getCharacter();
            int getHealth();
            void setHealth(int newHealth);
            void setDeath();
            bool isInCave();
            void toSpawn();


    };



#endif // PLAYER_H_INCLUDED
