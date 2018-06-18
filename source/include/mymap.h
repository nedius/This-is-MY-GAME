#ifndef MYMAP_H_INCLUDED
#define MYMAP_H_INCLUDED

//#include <string>
//#include <SFML/Window.hpp>
//using namespace std;


    class MyMap{
        private:
            sf::RenderWindow& window;
            int HEIGHT_MAP=40;
            int WIDTH_MAP=43;
            int CAVE_HEIGHT_MAP=20;
            int CAVE_WIDTH_MAP=20;

            string tileMap[40];
            string tileMapF[40];
            string tileMapB[40];
            string caveMap[20];
            string caveMapB[20];

            sf::Image map_image;
            sf::Texture map;
            sf::Sprite s_map;
            float map_scale=3;

            float timer=0;
            int frame=0;

        public:
            MyMap(sf::RenderWindow&);
            void draw(int id);
            void drawLayer();
            char getTileID(int x, int y);
            void setTileID(int x, int y, char tileID);
            char getTileIDB(int x, int y);
            char getTileIDC(int x, int y);
            char getTileIDCB(int x, int y);
            unsigned short getHeight();
            unsigned short getWidth();
            float getMapScale();
            void captureMap();
            void update(float time);
            int getFrame();
    };

#endif // MAP_H_INCLUDED
