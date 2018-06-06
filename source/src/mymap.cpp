#include "../include/header.h"

        MyMap::MyMap(sf::RenderWindow& window): window(window){

            map_image.loadFromFile("data/map/map.png");
            map.loadFromImage(map_image);
            s_map.setTexture(map);
            s_map.scale(map_scale,map_scale);

            int i=0;
            tileMap[i]="1111111111111111111111111111111111111111111"; i++; //1
            tileMap[i]="111 1  11 1  1111                         1"; i++;
            tileMap[i]="11 b 2   b 2 b b 2    b 2 b               1"; i++;
            tileMap[i]="11     b  b   2b 2 2                      1"; i++;
            tileMap[i]="1     2b 2 2       b  b                   1"; i++; //5
            tileMap[i]="11  dddd ddd  d   d ddd  ddd ddddd        1"; i++;
            tileMap[i]="111 d  d d  d dd  d d  d d     d          1"; i++;
            tileMap[i]="11  d  d ddd  d d d ddd  dd    d          1"; i++;
            tileMap[i]="1   d  d d    d d d d  d d     d          1"; i++;
            tileMap[i]="11  d  d d    d  dd ddd  ddd   d          1"; i++; //10
            tileMap[i]="1               34445                     1"; i++;
            tileMap[i]="1111     345 67 c6n7e    uE               1"; i++;
            tileMap[i]="1a  l hi cde fg ce2ce     uE              1"; i++;
            tileMap[i]="1   k rs mno    cf4ge                     1"; i++;
            tileMap[i]="1  11           mnnno    lvlv             1"; i++; //15
            tileMap[i]="1      uE                vlvl             1"; i++;
            tileMap[i]="1   35  u 34445          lvlv             1"; i++;
            tileMap[i]="1   mf44446nnnf445       vlvl             1"; i++;
            tileMap[i]="1    mnnnno   mnno                        1"; i++;
            tileMap[i]="1     111                                 1"; i++; //20
            tileMap[i]="1    1    1                               1"; i++;
            tileMap[i]="1    1    1                               1"; i++;
            tileMap[i]="1    1    1                               1"; i++;
            tileMap[i]="1    111111                               1"; i++;
            tileMap[i]="1                                         1"; i++; //25
            tileMap[i]="1                                         1"; i++;
            tileMap[i]="1                                         1"; i++;
            tileMap[i]="1                                         1"; i++;
            tileMap[i]="1                                         1"; i++;
            tileMap[i]="1                                         1"; i++; //30
            tileMap[i]="1                                         1"; i++;
            tileMap[i]="1                                         1"; i++;
            tileMap[i]="1                     uuu u               1"; i++;
            tileMap[i]="1                       u u               1"; i++;
            tileMap[i]="1                     uuuuu               1"; i++; //35
            tileMap[i]="1                     u u                 1"; i++;
            tileMap[i]="1                     u uuu               1"; i++;
            tileMap[i]="1                                         1"; i++;
            tileMap[i]="1                                         1"; i++;
            tileMap[i]="1111111111111111111111111111111111111111111"; i++; //40

            /// 1 2 3 4 5 6 7 8 9 0
            /// a b c d e f g h i j
            /// k l m n o p q r s t
            /// u v w x y z A B C D
            /// E F G H I J K L M N
            /// O P Q R S T U V W X
            /// Y Z
            ///
            ///
            ///                  " "

            i=0;
            tileMapLayer[i]="                                           "; i++; //1
            tileMapLayer[i]="                                           "; i++;
            tileMapLayer[i]="                                           "; i++;
            tileMapLayer[i]="                                           "; i++;
            tileMapLayer[i]="                                           "; i++; //5
            tileMapLayer[i]="                                           "; i++;
            tileMapLayer[i]="                                           "; i++;
            tileMapLayer[i]="                                           "; i++;
            tileMapLayer[i]="                                           "; i++;
            tileMapLayer[i]="                                           "; i++; //10
            tileMapLayer[i]="                                           "; i++;
            tileMapLayer[i]="      89                                   "; i++;
            tileMapLayer[i]="                                           "; i++;
            tileMapLayer[i]="                                           "; i++;
            tileMapLayer[i]="                                           "; i++; // 5
            tileMapLayer[i]="                                           "; i++;
            tileMapLayer[i]="                                           "; i++;
            tileMapLayer[i]="                                           "; i++;
            tileMapLayer[i]="                                           "; i++;
            tileMapLayer[i]="                                           "; i++; //20
            tileMapLayer[i]="                                           "; i++;
            tileMapLayer[i]="                                           "; i++;
            tileMapLayer[i]="                                           "; i++;
            tileMapLayer[i]="                                           "; i++;
            tileMapLayer[i]="                                           "; i++; //25
            tileMapLayer[i]="                                           "; i++;
            tileMapLayer[i]="                                           "; i++;
            tileMapLayer[i]="                                           "; i++;
            tileMapLayer[i]="                                           "; i++;
            tileMapLayer[i]="                                           "; i++; //30
            tileMapLayer[i]="                                           "; i++;
            tileMapLayer[i]="                                           "; i++;
            tileMapLayer[i]="                                           "; i++;
            tileMapLayer[i]="                                           "; i++;
            tileMapLayer[i]="                                           "; i++; //35
            tileMapLayer[i]="                                           "; i++;
            tileMapLayer[i]="                                           "; i++;
            tileMapLayer[i]="                                           "; i++;
            tileMapLayer[i]="                                           "; i++;
            tileMapLayer[i]="                                           "; i++; //40
    }

    void MyMap::draw(){
            for (int i = 0; i < HEIGHT_MAP*1+0; i++)
            for (int j = 0; j < WIDTH_MAP*1+0; j++)
            {
                if (tileMap[i][j] == ' ')  s_map.setTextureRect(sf::IntRect(32*9, 32*9, 32, 32)); //���� ��������� ������ , �� ������ 100� ���������
                if (tileMap[i][j] == '1')  s_map.setTextureRect(sf::IntRect(32*0, 32*0, 32, 32)); //���� ��������� ������ , �� ������ 1� ���������
                if (tileMap[i][j] == '2')  s_map.setTextureRect(sf::IntRect(32*1, 32*0, 32, 32)); //���� ��������� ������ , �� ������ 2� ���������
                if (tileMap[i][j] == '3')  s_map.setTextureRect(sf::IntRect(32*2, 32*0, 32, 32)); //���� ��������� ������ , �� ������ 3� ���������
                if (tileMap[i][j] == '4')  s_map.setTextureRect(sf::IntRect(32*3, 32*0, 32, 32)); //���� ��������� ������ , �� ������ 4� ���������
                if (tileMap[i][j] == '5')  s_map.setTextureRect(sf::IntRect(32*4, 32*0, 32, 32)); //���� ��������� ������ , �� ������ 5� ���������
                if (tileMap[i][j] == '6')  s_map.setTextureRect(sf::IntRect(32*5, 32*0, 32, 32)); //���� ��������� ������ , �� ������ 6� ���������
                if (tileMap[i][j] == '7')  s_map.setTextureRect(sf::IntRect(32*6, 32*0, 32, 32)); //���� ��������� ������ , �� ������ 7� ���������
                if (tileMap[i][j] == '8')  s_map.setTextureRect(sf::IntRect(32*7, 32*0, 32, 32)); //���� ��������� ������ , �� ������ 8� ���������
                if (tileMap[i][j] == '9')  s_map.setTextureRect(sf::IntRect(32*8, 32*0, 32, 32)); //���� ��������� ������ , �� ������ 9� ���������
                if (tileMap[i][j] == '0')  s_map.setTextureRect(sf::IntRect(32*9, 32*0, 32, 32)); //���� ��������� ������ , �� ������ 10� ���������
                if (tileMap[i][j] == 'a')  s_map.setTextureRect(sf::IntRect(32*0, 32*1, 32, 32)); //���� ��������� ������ , �� ������ 11� ���������
                if (tileMap[i][j] == 'b')  s_map.setTextureRect(sf::IntRect(32*1, 32*1, 32, 32)); //���� ��������� ������ , �� ������ 12� ���������
                if (tileMap[i][j] == 'c')  s_map.setTextureRect(sf::IntRect(32*2, 32*1, 32, 32)); //���� ��������� ������ , �� ������ 13� ���������
                if (tileMap[i][j] == 'd')  s_map.setTextureRect(sf::IntRect(32*3, 32*1, 32, 32)); //���� ��������� ������ , �� ������ 14� ���������
                if (tileMap[i][j] == 'e')  s_map.setTextureRect(sf::IntRect(32*4, 32*1, 32, 32)); //���� ��������� ������ , �� ������ 15� ���������
                if (tileMap[i][j] == 'f')  s_map.setTextureRect(sf::IntRect(32*5, 32*1, 32, 32)); //���� ��������� ������ , �� ������ 16� ���������
                if (tileMap[i][j] == 'g')  s_map.setTextureRect(sf::IntRect(32*6, 32*1, 32, 32)); //���� ��������� ������ , �� ������ 17� ���������
                if (tileMap[i][j] == 'h')  s_map.setTextureRect(sf::IntRect(32*7, 32*1, 32, 32)); //���� ��������� ������ , �� ������ 18� ���������
                if (tileMap[i][j] == 'i')  s_map.setTextureRect(sf::IntRect(32*8, 32*1, 32, 32)); //���� ��������� ������ , �� ������ 19� ���������
                if (tileMap[i][j] == 'j')  s_map.setTextureRect(sf::IntRect(32*9, 32*1, 32, 32)); //���� ��������� ������ , �� ������ 20� ���������
                if (tileMap[i][j] == 'k')  s_map.setTextureRect(sf::IntRect(32*0, 32*2, 32, 32)); //���� ��������� ������ , �� ������ 21� ���������
                if (tileMap[i][j] == 'l')  s_map.setTextureRect(sf::IntRect(32*1, 32*2, 32, 32)); //���� ��������� ������ , �� ������ 22� ���������
                if (tileMap[i][j] == 'm')  s_map.setTextureRect(sf::IntRect(32*2, 32*2, 32, 32)); //���� ��������� ������ , �� ������ 23� ���������
                if (tileMap[i][j] == 'n')  s_map.setTextureRect(sf::IntRect(32*3, 32*2, 32, 32)); //���� ��������� ������ , �� ������ 24� ���������
                if (tileMap[i][j] == 'o')  s_map.setTextureRect(sf::IntRect(32*4, 32*2, 32, 32)); //���� ��������� ������ , �� ������ 25� ���������
                if (tileMap[i][j] == 'p')  s_map.setTextureRect(sf::IntRect(32*5, 32*2, 32, 32)); //���� ��������� ������ , �� ������ 26� ���������
                if (tileMap[i][j] == 'q')  s_map.setTextureRect(sf::IntRect(32*6, 32*2, 32, 32)); //���� ��������� ������ , �� ������ 27� ���������
                if (tileMap[i][j] == 'r')  s_map.setTextureRect(sf::IntRect(32*7, 32*2, 32, 32)); //���� ��������� ������ , �� ������ 28� ���������
                if (tileMap[i][j] == 's')  s_map.setTextureRect(sf::IntRect(32*8, 32*2, 32, 32)); //���� ��������� ������ , �� ������ 29� ���������
                if (tileMap[i][j] == 't')  s_map.setTextureRect(sf::IntRect(32*9, 32*2, 32, 32)); //���� ��������� ������ , �� ������ 30� ���������
                if (tileMap[i][j] == 'u')  s_map.setTextureRect(sf::IntRect(32*0, 32*3, 32, 32)); //���� ��������� ������ , �� ������ 31� ���������
                if (tileMap[i][j] == 'v')  s_map.setTextureRect(sf::IntRect(32*1, 32*3, 32, 32)); //���� ��������� ������ , �� ������ 32� ���������
                if (tileMap[i][j] == 'w')  s_map.setTextureRect(sf::IntRect(32*2, 32*3, 32, 32)); //���� ��������� ������ , �� ������ 33� ���������
                if (tileMap[i][j] == 'x')  s_map.setTextureRect(sf::IntRect(32*3, 32*3, 32, 32)); //���� ��������� ������ , �� ������ 34� ���������
                if (tileMap[i][j] == 'y')  s_map.setTextureRect(sf::IntRect(32*4, 32*3, 32, 32)); //���� ��������� ������ , �� ������ 35� ���������
                if (tileMap[i][j] == 'z')  s_map.setTextureRect(sf::IntRect(32*5, 32*3, 32, 32)); //���� ��������� ������ , �� ������ 36� ���������
                if (tileMap[i][j] == 'A')  s_map.setTextureRect(sf::IntRect(32*6, 32*3, 32, 32)); //���� ��������� ������ , �� ������ 37� ���������
                if (tileMap[i][j] == 'B')  s_map.setTextureRect(sf::IntRect(32*7, 32*3, 32, 32)); //���� ��������� ������ , �� ������ 38� ���������
                if (tileMap[i][j] == 'C')  s_map.setTextureRect(sf::IntRect(32*8, 32*3, 32, 32)); //���� ��������� ������ , �� ������ 39� ���������
                if (tileMap[i][j] == 'D')  s_map.setTextureRect(sf::IntRect(32*9, 32*3, 32, 32)); //���� ��������� ������ , �� ������ 40� ���������

                if (tileMap[i][j] == 'E')  s_map.setTextureRect(sf::IntRect(32*0, 32*4, 32, 32)); //���� ��������� ������ , �� ������ 41� ���������
                if (tileMap[i][j] == 'F')  s_map.setTextureRect(sf::IntRect(32*1, 32*4, 32, 32)); //���� ��������� ������ , �� ������ 42� ���������
                if (tileMap[i][j] == 'G')  s_map.setTextureRect(sf::IntRect(32*2, 32*4, 32, 32)); //���� ��������� ������ , �� ������ 43� ���������
                if (tileMap[i][j] == 'H')  s_map.setTextureRect(sf::IntRect(32*3, 32*4, 32, 32)); //���� ��������� ������ , �� ������ 44� ���������
                if (tileMap[i][j] == 'I')  s_map.setTextureRect(sf::IntRect(32*4, 32*4, 32, 32)); //���� ��������� ������ , �� ������ 45� ���������
                if (tileMap[i][j] == 'J')  s_map.setTextureRect(sf::IntRect(32*5, 32*4, 32, 32)); //���� ��������� ������ , �� ������ 46� ���������
                if (tileMap[i][j] == 'K')  s_map.setTextureRect(sf::IntRect(32*6, 32*4, 32, 32)); //���� ��������� ������ , �� ������ 47� ���������
                if (tileMap[i][j] == 'L')  s_map.setTextureRect(sf::IntRect(32*7, 32*4, 32, 32)); //���� ��������� ������ , �� ������ 48� ���������
                if (tileMap[i][j] == 'M')  s_map.setTextureRect(sf::IntRect(32*8, 32*4, 32, 32)); //���� ��������� ������ , �� ������ 49� ���������
                if (tileMap[i][j] == 'N')  s_map.setTextureRect(sf::IntRect(32*9, 32*4, 32, 32)); //���� ��������� ������ , �� ������ 40� ���������

                s_map.setPosition(j * 32 * map_scale , i * 32 * map_scale);

                window.draw(s_map);
            }

    }

    void MyMap::drawLayer(){
            for (int i = 0; i < HEIGHT_MAP*1+0; i++)
            for (int j = 0; j < WIDTH_MAP*1+0; j++)
            {
                if (tileMapLayer[i][j] == '8')  s_map.setTextureRect(sf::IntRect(32*7, 32*0, 32, 32)); //���� ��������� ������ , �� ������ 8� ���������
                if (tileMapLayer[i][j] == '9')  s_map.setTextureRect(sf::IntRect(32*8, 32*0, 32, 32)); //���� ��������� ������ , �� ������ 9� ���������

                s_map.setPosition(j * 32 * map_scale , i * 32 * map_scale);

                if (tileMapLayer[i][j] != ' ') window.draw(s_map);
            }
    }

    char MyMap::getTileID(int x, int y){
        return tileMap[x][y];
    }

    void MyMap::setTileID(int x, int y, char tileID){
        tileMap[x][y]=tileID;
    }

    unsigned short MyMap::getHeight(){
        return HEIGHT_MAP;
    }

    unsigned short MyMap::getWidth(){
        return WIDTH_MAP;
    }


    float MyMap::getMapScale(){
        return map_scale;
    }

    void MyMap::captureMap(){
                sf::View mapview;
                mapview.setSize(32*WIDTH_MAP*map_scale, 32*HEIGHT_MAP*map_scale); mapview.setCenter(32*WIDTH_MAP*map_scale/2, 32*HEIGHT_MAP*map_scale/2);
                SYSTEMTIME time; GetLocalTime(&time);
                sf::RenderTexture texture;
                texture.create(32*WIDTH_MAP*map_scale, 32*HEIGHT_MAP*map_scale);
                texture.setView(mapview);
                texture.clear();
                for (int i = 0; i < HEIGHT_MAP*1+0; i++)
                for (int j = 0; j < WIDTH_MAP*1+0; j++){
                        if (tileMap[i][j] == ' ')  s_map.setTextureRect(sf::IntRect(32*9, 32*9, 32, 32)); //���� ��������� ������ , �� ������ 100� ���������
                        if (tileMap[i][j] == '1')  s_map.setTextureRect(sf::IntRect(32*0, 32*0, 32, 32)); //���� ��������� ������ , �� ������ 1� ���������
                        if (tileMap[i][j] == '2')  s_map.setTextureRect(sf::IntRect(32*1, 32*0, 32, 32)); //���� ��������� ������ , �� ������ 2� ���������
                        if (tileMap[i][j] == '3')  s_map.setTextureRect(sf::IntRect(32*2, 32*0, 32, 32)); //���� ��������� ������ , �� ������ 3� ���������
                        if (tileMap[i][j] == '4')  s_map.setTextureRect(sf::IntRect(32*3, 32*0, 32, 32)); //���� ��������� ������ , �� ������ 4� ���������
                        if (tileMap[i][j] == '5')  s_map.setTextureRect(sf::IntRect(32*4, 32*0, 32, 32)); //���� ��������� ������ , �� ������ 5� ���������
                        if (tileMap[i][j] == '6')  s_map.setTextureRect(sf::IntRect(32*5, 32*0, 32, 32)); //���� ��������� ������ , �� ������ 6� ���������
                        if (tileMap[i][j] == '7')  s_map.setTextureRect(sf::IntRect(32*6, 32*0, 32, 32)); //���� ��������� ������ , �� ������ 7� ���������
                        if (tileMap[i][j] == '8')  s_map.setTextureRect(sf::IntRect(32*7, 32*0, 32, 32)); //���� ��������� ������ , �� ������ 8� ���������
                        if (tileMap[i][j] == '9')  s_map.setTextureRect(sf::IntRect(32*8, 32*0, 32, 32)); //���� ��������� ������ , �� ������ 9� ���������
                        if (tileMap[i][j] == '0')  s_map.setTextureRect(sf::IntRect(32*9, 32*0, 32, 32)); //���� ��������� ������ , �� ������ 10� ���������
                        if (tileMap[i][j] == 'a')  s_map.setTextureRect(sf::IntRect(32*0, 32*1, 32, 32)); //���� ��������� ������ , �� ������ 11� ���������
                        if (tileMap[i][j] == 'b')  s_map.setTextureRect(sf::IntRect(32*1, 32*1, 32, 32)); //���� ��������� ������ , �� ������ 12� ���������
                        if (tileMap[i][j] == 'c')  s_map.setTextureRect(sf::IntRect(32*2, 32*1, 32, 32)); //���� ��������� ������ , �� ������ 13� ���������
                        if (tileMap[i][j] == 'd')  s_map.setTextureRect(sf::IntRect(32*3, 32*1, 32, 32)); //���� ��������� ������ , �� ������ 14� ���������
                        if (tileMap[i][j] == 'e')  s_map.setTextureRect(sf::IntRect(32*4, 32*1, 32, 32)); //���� ��������� ������ , �� ������ 15� ���������
                        if (tileMap[i][j] == 'f')  s_map.setTextureRect(sf::IntRect(32*5, 32*1, 32, 32)); //���� ��������� ������ , �� ������ 16� ���������
                        if (tileMap[i][j] == 'g')  s_map.setTextureRect(sf::IntRect(32*6, 32*1, 32, 32)); //���� ��������� ������ , �� ������ 17� ���������
                        if (tileMap[i][j] == 'h')  s_map.setTextureRect(sf::IntRect(32*7, 32*1, 32, 32)); //���� ��������� ������ , �� ������ 18� ���������
                        if (tileMap[i][j] == 'i')  s_map.setTextureRect(sf::IntRect(32*8, 32*1, 32, 32)); //���� ��������� ������ , �� ������ 19� ���������
                        if (tileMap[i][j] == 'j')  s_map.setTextureRect(sf::IntRect(32*9, 32*1, 32, 32)); //���� ��������� ������ , �� ������ 20� ���������
                        if (tileMap[i][j] == 'k')  s_map.setTextureRect(sf::IntRect(32*0, 32*2, 32, 32)); //���� ��������� ������ , �� ������ 21� ���������
                        if (tileMap[i][j] == 'l')  s_map.setTextureRect(sf::IntRect(32*1, 32*2, 32, 32)); //���� ��������� ������ , �� ������ 22� ���������
                        if (tileMap[i][j] == 'm')  s_map.setTextureRect(sf::IntRect(32*2, 32*2, 32, 32)); //���� ��������� ������ , �� ������ 23� ���������
                        if (tileMap[i][j] == 'n')  s_map.setTextureRect(sf::IntRect(32*3, 32*2, 32, 32)); //���� ��������� ������ , �� ������ 24� ���������
                        if (tileMap[i][j] == 'o')  s_map.setTextureRect(sf::IntRect(32*4, 32*2, 32, 32)); //���� ��������� ������ , �� ������ 25� ���������
                        if (tileMap[i][j] == 'p')  s_map.setTextureRect(sf::IntRect(32*5, 32*2, 32, 32)); //���� ��������� ������ , �� ������ 26� ���������
                        if (tileMap[i][j] == 'q')  s_map.setTextureRect(sf::IntRect(32*6, 32*2, 32, 32)); //���� ��������� ������ , �� ������ 27� ���������
                        if (tileMap[i][j] == 'r')  s_map.setTextureRect(sf::IntRect(32*7, 32*2, 32, 32)); //���� ��������� ������ , �� ������ 28� ���������
                        if (tileMap[i][j] == 's')  s_map.setTextureRect(sf::IntRect(32*8, 32*2, 32, 32)); //���� ��������� ������ , �� ������ 29� ���������
                        if (tileMap[i][j] == 't')  s_map.setTextureRect(sf::IntRect(32*9, 32*2, 32, 32)); //���� ��������� ������ , �� ������ 30� ���������
                        if (tileMap[i][j] == 't')  s_map.setTextureRect(sf::IntRect(32*9, 32*2, 32, 32)); //���� ��������� ������ , �� ������ 30� ���������
                        if (tileMap[i][j] == 'u')  s_map.setTextureRect(sf::IntRect(32*0, 32*3, 32, 32)); //���� ��������� ������ , �� ������ 31� ���������
                        if (tileMap[i][j] == 'v')  s_map.setTextureRect(sf::IntRect(32*1, 32*3, 32, 32)); //���� ��������� ������ , �� ������ 32� ���������
                        if (tileMap[i][j] == 'w')  s_map.setTextureRect(sf::IntRect(32*2, 32*3, 32, 32)); //���� ��������� ������ , �� ������ 33� ���������
                        if (tileMap[i][j] == 'x')  s_map.setTextureRect(sf::IntRect(32*3, 32*3, 32, 32)); //���� ��������� ������ , �� ������ 34� ���������
                        if (tileMap[i][j] == 'y')  s_map.setTextureRect(sf::IntRect(32*4, 32*3, 32, 32)); //���� ��������� ������ , �� ������ 35� ���������
                        if (tileMap[i][j] == 'z')  s_map.setTextureRect(sf::IntRect(32*5, 32*3, 32, 32)); //���� ��������� ������ , �� ������ 36� ���������
                        if (tileMap[i][j] == 'A')  s_map.setTextureRect(sf::IntRect(32*6, 32*3, 32, 32)); //���� ��������� ������ , �� ������ 37� ���������
                        if (tileMap[i][j] == 'B')  s_map.setTextureRect(sf::IntRect(32*7, 32*3, 32, 32)); //���� ��������� ������ , �� ������ 38� ���������
                        if (tileMap[i][j] == 'C')  s_map.setTextureRect(sf::IntRect(32*8, 32*3, 32, 32)); //���� ��������� ������ , �� ������ 39� ���������
                        if (tileMap[i][j] == 'D')  s_map.setTextureRect(sf::IntRect(32*9, 32*3, 32, 32)); //���� ��������� ������ , �� ������ 40� ���������
                        if (tileMap[i][j] == 'E')  s_map.setTextureRect(sf::IntRect(32*0, 32*4, 32, 32)); //���� ��������� ������ , �� ������ 41� ���������
                        if (tileMap[i][j] == 'F')  s_map.setTextureRect(sf::IntRect(32*1, 32*4, 32, 32)); //���� ��������� ������ , �� ������ 42� ���������
                        if (tileMap[i][j] == 'G')  s_map.setTextureRect(sf::IntRect(32*2, 32*4, 32, 32)); //���� ��������� ������ , �� ������ 43� ���������
                        if (tileMap[i][j] == 'H')  s_map.setTextureRect(sf::IntRect(32*3, 32*4, 32, 32)); //���� ��������� ������ , �� ������ 44� ���������
                        if (tileMap[i][j] == 'I')  s_map.setTextureRect(sf::IntRect(32*4, 32*4, 32, 32)); //���� ��������� ������ , �� ������ 45� ���������
                        if (tileMap[i][j] == 'J')  s_map.setTextureRect(sf::IntRect(32*5, 32*4, 32, 32)); //���� ��������� ������ , �� ������ 46� ���������
                        if (tileMap[i][j] == 'K')  s_map.setTextureRect(sf::IntRect(32*6, 32*4, 32, 32)); //���� ��������� ������ , �� ������ 47� ���������
                        if (tileMap[i][j] == 'L')  s_map.setTextureRect(sf::IntRect(32*7, 32*4, 32, 32)); //���� ��������� ������ , �� ������ 48� ���������
                        if (tileMap[i][j] == 'M')  s_map.setTextureRect(sf::IntRect(32*8, 32*4, 32, 32)); //���� ��������� ������ , �� ������ 49� ���������
                        if (tileMap[i][j] == 'N')  s_map.setTextureRect(sf::IntRect(32*9, 32*4, 32, 32)); //���� ��������� ������ , �� ������ 40� ���������


                        s_map.setPosition(j * 32 * map_scale , i * 32 * map_scale);

                        texture.draw(s_map);
                    }

                for (int i = 0; i < HEIGHT_MAP*1+0; i++)
                for (int j = 0; j < WIDTH_MAP*1+0; j++)
                {
                    if (tileMapLayer[i][j] == '8')  s_map.setTextureRect(sf::IntRect(32*7, 32*0, 32, 32)); //���� ��������� ������ , �� ������ 8� ���������
                    if (tileMapLayer[i][j] == '9')  s_map.setTextureRect(sf::IntRect(32*8, 32*0, 32, 32)); //���� ��������� ������ , �� ������ 9� ���������

                    s_map.setPosition(j * 32 * map_scale , i * 32 * map_scale);

                    if (tileMapLayer[i][j] != ' ') texture.draw(s_map);
                }
                texture.display();
                string dawae=WORDToStr(time.wDay)+"."+WORDToStr(time.wMonth)+"."+WORDToStr(time.wYear)+"_"+WORDToStr(time.wHour)+WORDToStr(time.wMinute);
                texture.getTexture().copyToImage().saveToFile("data/pics/map_"+dawae+".png");
                //sf::Image Screen(texture.getTexture()); Screen.saveToFile("data/pics/map_"+dawae+".jpg");
                //window.setView(view);
    }

    void MyMap::update(float time){
        timer+=0.25*time;

        if(timer>25){ timer=0;
                for (int i = 0; i < HEIGHT_MAP*1+0; i++)
                for (int j = 0; j < WIDTH_MAP*1+0; j++){
                        if (tileMap[i][j] == 'l')  tileMap[i][j] = 'v';      ///campfire
                        else if (tileMap[i][j] == 'v')  tileMap[i][j] = 'l';

                        if (tileMap[i][j] == 'u')  tileMap[i][j] = 'E';      ///water
                        else if (tileMap[i][j] == 'E')  tileMap[i][j] = 'u';
                    }
        }
    }
