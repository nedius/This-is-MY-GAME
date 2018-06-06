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

            string tileMap[40];
            string tileMapLayer[40];

            sf::Image map_image;
            sf::Texture map;
            sf::Sprite s_map;
            float map_scale=3;

            float timer=0;

        public:
            MyMap(sf::RenderWindow&);
            void draw();
            void drawLayer();
            char getTileID(int x, int y);
            void setTileID(int x, int y, char tileID);
            unsigned short getHeight();
            unsigned short getWidth();
            float getMapScale();
            void captureMap();
            void update(float time);
    };

#endif // MAP_H_INCLUDED
