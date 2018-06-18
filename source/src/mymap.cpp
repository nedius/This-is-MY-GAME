#include "../include/header.h"

        MyMap::MyMap(sf::RenderWindow& window): window(window){

            map_image.loadFromFile("data/map/map.png");
            map.loadFromImage(map_image);
            s_map.setTexture(map);
            s_map.scale(map_scale,map_scale);

            int i=0;
            tileMap[i]="1111111111111111111111111111111111111111111"; i++; //1
            tileMap[i]="111 1  11 1  1111                         1"; i++;
            tileMap[i]="11                                        1"; i++;
            tileMap[i]="11     1        1         1               u"; i++;
            tileMap[i]="1                                        uE"; i++; //5
            tileMap[i]="11       1       1                       Eu"; i++;
            tileMap[i]="111                      1              EuE"; i++;
            tileMap[i]="11                                     EuEu"; i++;
            tileMap[i]="1         1         1         1       EuEuE"; i++;
            tileMap[i]="11             1       1              uEuEu"; i++; //10
            tileMap[i]="1                      11             EuEuE"; i++;
            tileMap[i]="1111        11   EuE    1            EuEuEu"; i++;
            tileMap[i]="1a    hi     1   uEu   1            EuEuEuE"; i++;
            tileMap[i]="1     rs    11    uE   1           EuEuEuEu"; i++;
            tileMap[i]="1             1       11          EuEuEuEuE"; i++; //15
            tileMap[i]="1              11 1111           EuEuEuEuEu"; i++;
            tileMap[i]="1                                uEuEuEuEuE"; i++;
            tileMap[i]="1                                 uEuEuEuEu"; i++;
            tileMap[i]="1                                 EuEuEuEuE"; i++;
            tileMap[i]="1                                EuEuEuEuEu"; i++; //20
            tileMap[i]="1                                uEuEuEuEu1"; i++;
            tileMap[i]="1                               uEuEuEuEu11"; i++;
            tileMap[i]="1         uEuEuE                EuEuEuEu 11"; i++;
            tileMap[i]="1        EuEuEuEuE              uEuEuEuE 11"; i++;
            tileMap[i]="1       EuEuEuEuEuE             EuEuEuEu 11"; i++; //25
            tileMap[i]="1       uEuEuEuEuEuE           EuEuEuEuE 11"; i++;
            tileMap[i]="1       EuEuEuEuEuEu         uEuEuEuEuEu 11"; i++;
            tileMap[i]="1       uEuEuEuEuEuE        uEuEuEuEuEuE 11"; i++;
            tileMap[i]="1        uEuEuEuEuEu       uEuEuEuEuEuE  11"; i++;
            tileMap[i]="1         uEuEuEuEuEu     uEuEuEuEuEuE   11"; i++; //30
            tileMap[i]="1          uEuEuEuEuEu   uEuEuEuEuEuEu  111"; i++;
            tileMap[i]="1           uEuEuEuEuEuEuEuEuEuEuEuEu   111"; i++;
            tileMap[i]="1               EuEuEuEuEuEuEuEuEuEu     11"; i++;
            tileMap[i]="1                  EuEuEuEuEuEuEuEu      11"; i++;
            tileMap[i]="1                   EuEuEuEuEuEuEuE    1111"; i++; //35
            tileMap[i]="1                    EuEuEuEuEuEuE       11"; i++;
            tileMap[i]="1                    uEuEuEuEuEuE        11"; i++;
            tileMap[i]="1                    EuEuEuEuEuEu       111"; i++;
            tileMap[i]="1                    uEuEuEuEuEu      11111"; i++;
            tileMap[i]="111111111111111111111EuEuEuEuEuE11111111111"; i++; //40

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
            tileMapB[i]="                                           "; i++; //1
            tileMapB[i]="                                           "; i++;
            tileMapB[i]="                                           "; i++;
            tileMapB[i]="                                          3"; i++;
            tileMapB[i]="                                         3 "; i++; //5
            tileMapB[i]="                                         c "; i++;
            tileMapB[i]="                                        3  "; i++;
            tileMapB[i]="                                       3   "; i++;
            tileMapB[i]="                                      3    "; i++;
            tileMapB[i]="                                      c    "; i++; //10
            tileMapB[i]="                                      c    "; i++;
            tileMapB[i]="                 345 lvlv            3     "; i++;
            tileMapB[i]="    l            m e vlvl           3      "; i++;
            tileMapB[i]="    k             mo lvlv          3       "; i++;
            tileMapB[i]="                     vlvl         3        "; i++; //15
            tileMapB[i]="1                                3         "; i++;
            tileMapB[i]="1                                m         "; i++;
            tileMapB[i]="1                                 c        "; i++;
            tileMapB[i]="1          345                    c        "; i++;
            tileMapB[i]="1          c e                   3        n"; i++; //20
            tileMapB[i]="1          mno                   c       n1"; i++;
            tileMapB[i]="1                               3       n11"; i++;
            tileMapB[i]="1         344445                c      e 11"; i++;
            tileMapB[i]="1        3      45              c      e 11"; i++;
            tileMapB[i]="1       3         5             c      e 11"; i++; //25
            tileMapB[i]="1       c          5           3       e 11"; i++;
            tileMapB[i]="1       c          e         34        e 11"; i++;
            tileMapB[i]="1       m          e        3          o 11"; i++;
            tileMapB[i]="1        m         e       3          o  11"; i++;
            tileMapB[i]="1         m         5     3          e   11"; i++; //30
            tileMapB[i]="1          m         5   3           o  111"; i++;
            tileMapB[i]="1           mnnn      444           o   111"; i++;
            tileMapB[i]="1               mnn                o     11"; i++;
            tileMapB[i]="1                  m              e      11"; i++;
            tileMapB[i]="1                   m             o    1111"; i++; //35
            tileMapB[i]="1                    c           o       11"; i++;
            tileMapB[i]="1                    c          e        11"; i++;
            tileMapB[i]="1                    c          o       111"; i++;
            tileMapB[i]="1                    c         e      11111"; i++;
            tileMapB[i]="111111111111111111111c         e11111111111"; i++; //40

            i=0;
            tileMapF[i]="                                           "; i++; //1
            tileMapF[i]="                                           "; i++;
            tileMapF[i]="                                           "; i++;
            tileMapF[i]="                                           "; i++;
            tileMapF[i]="                                           "; i++; //5
            tileMapF[i]="                                           "; i++;
            tileMapF[i]="                                           "; i++;
            tileMapF[i]="                                           "; i++;
            tileMapF[i]="                                           "; i++;
            tileMapF[i]="                                           "; i++; //10
            tileMapF[i]="                                           "; i++;
            tileMapF[i]="      89                                   "; i++;
            tileMapF[i]="                                           "; i++;
            tileMapF[i]="                                           "; i++;
            tileMapF[i]="                                           "; i++; // 5
            tileMapF[i]="                                           "; i++;
            tileMapF[i]="                                           "; i++;
            tileMapF[i]="                                           "; i++;
            tileMapF[i]="                                           "; i++;
            tileMapF[i]="                                           "; i++; //20
            tileMapF[i]="                                           "; i++;
            tileMapF[i]="                                           "; i++;
            tileMapF[i]="                                           "; i++;
            tileMapF[i]="                                           "; i++;
            tileMapF[i]="                                           "; i++; //25
            tileMapF[i]="                                           "; i++;
            tileMapF[i]="                                           "; i++;
            tileMapF[i]="                                           "; i++;
            tileMapF[i]="                                           "; i++;
            tileMapF[i]="                                           "; i++; //30
            tileMapF[i]="                                           "; i++;
            tileMapF[i]="                                           "; i++;
            tileMapF[i]="                                           "; i++;
            tileMapF[i]="                                           "; i++;
            tileMapF[i]="                                           "; i++; //35
            tileMapF[i]="                                           "; i++;
            tileMapF[i]="                                           "; i++;
            tileMapF[i]="                                           "; i++;
            tileMapF[i]="                                           "; i++;
            tileMapF[i]="                                           "; i++; //40

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
            caveMap[i]="00000000tttttttttttt"; i++; //1
            caveMap[i]="ttDDDD00DDtttttttttt"; i++;
            caveMap[i]="tD00000000Dttttttttt"; i++;
            caveMap[i]="tj000000000tttDDDttt"; i++;
            caveMap[i]="tCC000000CCttt000ttt"; i++; //5
            caveMap[i]="tttC00CCCttttD000ttt"; i++;
            caveMap[i]="ttttC0Dtttttt000Cttt"; i++;
            caveMap[i]="ttttt00DDtttt0CCtttt"; i++;
            caveMap[i]="ttttt0000DDDD0Dttttt"; i++;
            caveMap[i]="tttttC000000000ttttt"; i++; //10
            caveMap[i]="tttttt000CCCCC0ttttt"; i++;
            caveMap[i]="ttttttCCCttttD0ttttt"; i++;
            caveMap[i]="ttttttttttttt00ttttt"; i++;
            caveMap[i]="tttttttttDDDt0Cttttt"; i++;
            caveMap[i]="ttttttttD000D0tttttt"; i++; //15
            caveMap[i]="tttttttt000000tttttt"; i++;
            caveMap[i]="ttttttttC0000Ctttttt"; i++;
            caveMap[i]="tttttttttCCCCttttttt"; i++;
            caveMap[i]="tttttttttttttttttttt"; i++;
            caveMap[i]="tttttttttttttttttttt"; i++; //20

            i=0;
            caveMapB[i]="                    "; i++; //1
            caveMapB[i]="                    "; i++;
            caveMapB[i]="                    "; i++;
            caveMapB[i]="       l  k         "; i++;
            caveMapB[i]="               k    "; i++; //5
            caveMapB[i]="                v   "; i++;
            caveMapB[i]="                    "; i++;
            caveMapB[i]="                    "; i++;
            caveMapB[i]="                    "; i++;
            caveMapB[i]="       v            "; i++; //10
            caveMapB[i]="       k            "; i++;
            caveMapB[i]="                    "; i++;
            caveMapB[i]="                    "; i++;
            caveMapB[i]="                    "; i++;
            caveMapB[i]="          l         "; i++; //15
            caveMapB[i]="        k           "; i++;
            caveMapB[i]="          k k       "; i++;
            caveMapB[i]="                    "; i++;
            caveMapB[i]="                    "; i++;
            caveMapB[i]="                    "; i++; //20

    }

    void MyMap::draw(int id){ //0=world 1=cave
            if(id==0){ //render world
                for (int i = 0; i < HEIGHT_MAP*1+0; i++)
                for (int j = 0; j < WIDTH_MAP*1+0; j++)
                {
                    if (tileMap[i][j] == ' ')  s_map.setTextureRect(sf::IntRect(32*9, 32*9, 32, 32)); //если встретили символ , то рисуем 100й квадратик
                    if (tileMap[i][j] == '1')  s_map.setTextureRect(sf::IntRect(32*0, 32*0, 32, 32)); //если встретили символ , то рисуем 1й квадратик
                    if (tileMap[i][j] == '2')  s_map.setTextureRect(sf::IntRect(32*1, 32*0, 32, 32)); //если встретили символ , то рисуем 2й квадратик
                    if (tileMap[i][j] == '3')  s_map.setTextureRect(sf::IntRect(32*2, 32*0, 32, 32)); //если встретили символ , то рисуем 3й квадратик
                    if (tileMap[i][j] == '4')  s_map.setTextureRect(sf::IntRect(32*3, 32*0, 32, 32)); //если встретили символ , то рисуем 4й квадратик
                    if (tileMap[i][j] == '5')  s_map.setTextureRect(sf::IntRect(32*4, 32*0, 32, 32)); //если встретили символ , то рисуем 5й квадратик
                    if (tileMap[i][j] == '6')  s_map.setTextureRect(sf::IntRect(32*5, 32*0, 32, 32)); //если встретили символ , то рисуем 6й квадратик
                    if (tileMap[i][j] == '7')  s_map.setTextureRect(sf::IntRect(32*6, 32*0, 32, 32)); //если встретили символ , то рисуем 7й квадратик
                    if (tileMap[i][j] == '8')  s_map.setTextureRect(sf::IntRect(32*7, 32*0, 32, 32)); //если встретили символ , то рисуем 8й квадратик
                    if (tileMap[i][j] == '9')  s_map.setTextureRect(sf::IntRect(32*8, 32*0, 32, 32)); //если встретили символ , то рисуем 9й квадратик
                    if (tileMap[i][j] == '0')  s_map.setTextureRect(sf::IntRect(32*9, 32*0, 32, 32)); //если встретили символ , то рисуем 10й квадратик
                    if (tileMap[i][j] == 'a')  s_map.setTextureRect(sf::IntRect(32*0, 32*1, 32, 32)); //если встретили символ , то рисуем 11й квадратик
                    if (tileMap[i][j] == 'b')  s_map.setTextureRect(sf::IntRect(32*1, 32*1, 32, 32)); //если встретили символ , то рисуем 12й квадратик
                    if (tileMap[i][j] == 'c')  s_map.setTextureRect(sf::IntRect(32*2, 32*1, 32, 32)); //если встретили символ , то рисуем 13й квадратик
                    if (tileMap[i][j] == 'd')  s_map.setTextureRect(sf::IntRect(32*3, 32*1, 32, 32)); //если встретили символ , то рисуем 14й квадратик
                    if (tileMap[i][j] == 'e')  s_map.setTextureRect(sf::IntRect(32*4, 32*1, 32, 32)); //если встретили символ , то рисуем 15й квадратик
                    if (tileMap[i][j] == 'f')  s_map.setTextureRect(sf::IntRect(32*5, 32*1, 32, 32)); //если встретили символ , то рисуем 16й квадратик
                    if (tileMap[i][j] == 'g')  s_map.setTextureRect(sf::IntRect(32*6, 32*1, 32, 32)); //если встретили символ , то рисуем 17й квадратик
                    if (tileMap[i][j] == 'h')  s_map.setTextureRect(sf::IntRect(32*7, 32*1, 32, 32)); //если встретили символ , то рисуем 18й квадратик
                    if (tileMap[i][j] == 'i')  s_map.setTextureRect(sf::IntRect(32*8, 32*1, 32, 32)); //если встретили символ , то рисуем 19й квадратик
                    if (tileMap[i][j] == 'j')  s_map.setTextureRect(sf::IntRect(32*9, 32*1, 32, 32)); //если встретили символ , то рисуем 20й квадратик
                    if (tileMap[i][j] == 'k')  s_map.setTextureRect(sf::IntRect(32*0, 32*2, 32, 32)); //если встретили символ , то рисуем 21й квадратик
                    if (tileMap[i][j] == 'l')  s_map.setTextureRect(sf::IntRect(32*1, 32*2, 32, 32)); //если встретили символ , то рисуем 22й квадратик
                    if (tileMap[i][j] == 'm')  s_map.setTextureRect(sf::IntRect(32*2, 32*2, 32, 32)); //если встретили символ , то рисуем 23й квадратик
                    if (tileMap[i][j] == 'n')  s_map.setTextureRect(sf::IntRect(32*3, 32*2, 32, 32)); //если встретили символ , то рисуем 24й квадратик
                    if (tileMap[i][j] == 'o')  s_map.setTextureRect(sf::IntRect(32*4, 32*2, 32, 32)); //если встретили символ , то рисуем 25й квадратик
                    if (tileMap[i][j] == 'p')  s_map.setTextureRect(sf::IntRect(32*5, 32*2, 32, 32)); //если встретили символ , то рисуем 26й квадратик
                    if (tileMap[i][j] == 'q')  s_map.setTextureRect(sf::IntRect(32*6, 32*2, 32, 32)); //если встретили символ , то рисуем 27й квадратик
                    if (tileMap[i][j] == 'r')  s_map.setTextureRect(sf::IntRect(32*7, 32*2, 32, 32)); //если встретили символ , то рисуем 28й квадратик
                    if (tileMap[i][j] == 's')  s_map.setTextureRect(sf::IntRect(32*8, 32*2, 32, 32)); //если встретили символ , то рисуем 29й квадратик
                    if (tileMap[i][j] == 't')  s_map.setTextureRect(sf::IntRect(32*9, 32*2, 32, 32)); //если встретили символ , то рисуем 30й квадратик
                    if (tileMap[i][j] == 'u')  s_map.setTextureRect(sf::IntRect(32*0, 32*3, 32, 32)); //если встретили символ , то рисуем 31й квадратик
                    if (tileMap[i][j] == 'v')  s_map.setTextureRect(sf::IntRect(32*1, 32*3, 32, 32)); //если встретили символ , то рисуем 32й квадратик
                    if (tileMap[i][j] == 'w')  s_map.setTextureRect(sf::IntRect(32*2, 32*3, 32, 32)); //если встретили символ , то рисуем 33й квадратик
                    if (tileMap[i][j] == 'x')  s_map.setTextureRect(sf::IntRect(32*3, 32*3, 32, 32)); //если встретили символ , то рисуем 34й квадратик
                    if (tileMap[i][j] == 'y')  s_map.setTextureRect(sf::IntRect(32*4, 32*3, 32, 32)); //если встретили символ , то рисуем 35й квадратик
                    if (tileMap[i][j] == 'z')  s_map.setTextureRect(sf::IntRect(32*5, 32*3, 32, 32)); //если встретили символ , то рисуем 36й квадратик
                    if (tileMap[i][j] == 'A')  s_map.setTextureRect(sf::IntRect(32*6, 32*3, 32, 32)); //если встретили символ , то рисуем 37й квадратик
                    if (tileMap[i][j] == 'B')  s_map.setTextureRect(sf::IntRect(32*7, 32*3, 32, 32)); //если встретили символ , то рисуем 38й квадратик
                    if (tileMap[i][j] == 'C')  s_map.setTextureRect(sf::IntRect(32*8, 32*3, 32, 32)); //если встретили символ , то рисуем 39й квадратик
                    if (tileMap[i][j] == 'D')  s_map.setTextureRect(sf::IntRect(32*9, 32*3, 32, 32)); //если встретили символ , то рисуем 40й квадратик
                    if (tileMap[i][j] == 'E')  s_map.setTextureRect(sf::IntRect(32*0, 32*4, 32, 32)); //если встретили символ , то рисуем 41й квадратик
                    if (tileMap[i][j] == 'F')  s_map.setTextureRect(sf::IntRect(32*1, 32*4, 32, 32)); //если встретили символ , то рисуем 42й квадратик
                    if (tileMap[i][j] == 'G')  s_map.setTextureRect(sf::IntRect(32*2, 32*4, 32, 32)); //если встретили символ , то рисуем 43й квадратик
                    if (tileMap[i][j] == 'H')  s_map.setTextureRect(sf::IntRect(32*3, 32*4, 32, 32)); //если встретили символ , то рисуем 44й квадратик
                    if (tileMap[i][j] == 'I')  s_map.setTextureRect(sf::IntRect(32*4, 32*4, 32, 32)); //если встретили символ , то рисуем 45й квадратик
                    if (tileMap[i][j] == 'J')  s_map.setTextureRect(sf::IntRect(32*5, 32*4, 32, 32)); //если встретили символ , то рисуем 46й квадратик
                    if (tileMap[i][j] == 'K')  s_map.setTextureRect(sf::IntRect(32*6, 32*4, 32, 32)); //если встретили символ , то рисуем 47й квадратик
                    if (tileMap[i][j] == 'L')  s_map.setTextureRect(sf::IntRect(32*7, 32*4, 32, 32)); //если встретили символ , то рисуем 48й квадратик
                    if (tileMap[i][j] == 'M')  s_map.setTextureRect(sf::IntRect(32*8, 32*4, 32, 32)); //если встретили символ , то рисуем 49й квадратик
                    if (tileMap[i][j] == 'N')  s_map.setTextureRect(sf::IntRect(32*9, 32*4, 32, 32)); //если встретили символ , то рисуем 40й квадратик

                    s_map.setPosition(j * 32 * map_scale , i * 32 * map_scale);

                    window.draw(s_map);

                    if(tileMapB[i][j] == '3' || tileMapB[i][j] == '4' || tileMapB[i][j] == '5' || tileMapB[i][j] == 'c' ||
                       tileMapB[i][j] == 'e' || tileMapB[i][j] == 'm' || tileMapB[i][j] == 'n' || tileMapB[i][j] == 'o' ||
                       tileMapB[i][j] == 'k' || tileMapB[i][j] == 'l' || tileMapB[i][j] == 'v') //345cemno klv
                        {
                            if (tileMapB[i][j] == '3')  s_map.setTextureRect(sf::IntRect(32*2, 32*0, 32, 32)); //если встретили символ , то рисуем 3й квадратик
                            if (tileMapB[i][j] == '4')  s_map.setTextureRect(sf::IntRect(32*3, 32*0, 32, 32)); //если встретили символ , то рисуем 4й квадратик
                            if (tileMapB[i][j] == '5')  s_map.setTextureRect(sf::IntRect(32*4, 32*0, 32, 32)); //если встретили символ , то рисуем 5й квадратик
                            if (tileMapB[i][j] == 'c')  s_map.setTextureRect(sf::IntRect(32*2, 32*1, 32, 32)); //если встретили символ , то рисуем 13й квадратик
                            if (tileMapB[i][j] == 'e')  s_map.setTextureRect(sf::IntRect(32*4, 32*1, 32, 32)); //если встретили символ , то рисуем 15й квадратик
                            if (tileMapB[i][j] == 'k')  s_map.setTextureRect(sf::IntRect(32*0, 32*2, 32, 32)); //если встретили символ , то рисуем 21й квадратик
                            if (tileMapB[i][j] == 'l')  s_map.setTextureRect(sf::IntRect(32*1, 32*2, 32, 32)); //если встретили символ , то рисуем 22й квадрати
                            if (tileMapB[i][j] == 'm')  s_map.setTextureRect(sf::IntRect(32*2, 32*2, 32, 32)); //если встретили символ , то рисуем 23й квадратик
                            if (tileMapB[i][j] == 'n')  s_map.setTextureRect(sf::IntRect(32*3, 32*2, 32, 32)); //если встретили символ , то рисуем 24й квадратик
                            if (tileMapB[i][j] == 'o')  s_map.setTextureRect(sf::IntRect(32*4, 32*2, 32, 32)); //если встретили символ , то рисуем 25й квадратик
                            if (tileMapB[i][j] == 'v')  s_map.setTextureRect(sf::IntRect(32*1, 32*3, 32, 32)); //если встретили символ , то рисуем 32й квадратик

                            window.draw(s_map);
                        }
                }
            }
            if(id==1){ // render cave
                for (int i = 0; i < CAVE_HEIGHT_MAP*1+0; i++)
                for (int j = 0; j < CAVE_WIDTH_MAP*1+0; j++)
                {
                    if (caveMap[i][j] == ' ')  s_map.setTextureRect(sf::IntRect(32*9, 32*9, 32, 32)); //если встретили символ , то рисуем 100й квадратик
                    if (caveMap[i][j] == '1')  s_map.setTextureRect(sf::IntRect(32*0, 32*0, 32, 32)); //если встретили символ , то рисуем 1й квадратик
                    if (caveMap[i][j] == '2')  s_map.setTextureRect(sf::IntRect(32*1, 32*0, 32, 32)); //если встретили символ , то рисуем 2й квадратик
                    if (caveMap[i][j] == '3')  s_map.setTextureRect(sf::IntRect(32*2, 32*0, 32, 32)); //если встретили символ , то рисуем 3й квадратик
                    if (caveMap[i][j] == '4')  s_map.setTextureRect(sf::IntRect(32*3, 32*0, 32, 32)); //если встретили символ , то рисуем 4й квадратик
                    if (caveMap[i][j] == '5')  s_map.setTextureRect(sf::IntRect(32*4, 32*0, 32, 32)); //если встретили символ , то рисуем 5й квадратик
                    if (caveMap[i][j] == '6')  s_map.setTextureRect(sf::IntRect(32*5, 32*0, 32, 32)); //если встретили символ , то рисуем 6й квадратик
                    if (caveMap[i][j] == '7')  s_map.setTextureRect(sf::IntRect(32*6, 32*0, 32, 32)); //если встретили символ , то рисуем 7й квадратик
                    if (caveMap[i][j] == '8')  s_map.setTextureRect(sf::IntRect(32*7, 32*0, 32, 32)); //если встретили символ , то рисуем 8й квадратик
                    if (caveMap[i][j] == '9')  s_map.setTextureRect(sf::IntRect(32*8, 32*0, 32, 32)); //если встретили символ , то рисуем 9й квадратик
                    if (caveMap[i][j] == '0')  s_map.setTextureRect(sf::IntRect(32*9, 32*0, 32, 32)); //если встретили символ , то рисуем 10й квадратик
                    if (caveMap[i][j] == 'a')  s_map.setTextureRect(sf::IntRect(32*0, 32*1, 32, 32)); //если встретили символ , то рисуем 11й квадратик
                    if (caveMap[i][j] == 'b')  s_map.setTextureRect(sf::IntRect(32*1, 32*1, 32, 32)); //если встретили символ , то рисуем 12й квадратик
                    if (caveMap[i][j] == 'c')  s_map.setTextureRect(sf::IntRect(32*2, 32*1, 32, 32)); //если встретили символ , то рисуем 13й квадратик
                    if (caveMap[i][j] == 'd')  s_map.setTextureRect(sf::IntRect(32*3, 32*1, 32, 32)); //если встретили символ , то рисуем 14й квадратик
                    if (caveMap[i][j] == 'e')  s_map.setTextureRect(sf::IntRect(32*4, 32*1, 32, 32)); //если встретили символ , то рисуем 15й квадратик
                    if (caveMap[i][j] == 'f')  s_map.setTextureRect(sf::IntRect(32*5, 32*1, 32, 32)); //если встретили символ , то рисуем 16й квадратик
                    if (caveMap[i][j] == 'g')  s_map.setTextureRect(sf::IntRect(32*6, 32*1, 32, 32)); //если встретили символ , то рисуем 17й квадратик
                    if (caveMap[i][j] == 'h')  s_map.setTextureRect(sf::IntRect(32*7, 32*1, 32, 32)); //если встретили символ , то рисуем 18й квадратик
                    if (caveMap[i][j] == 'i')  s_map.setTextureRect(sf::IntRect(32*8, 32*1, 32, 32)); //если встретили символ , то рисуем 19й квадратик
                    if (caveMap[i][j] == 'j')  s_map.setTextureRect(sf::IntRect(32*9, 32*1, 32, 32)); //если встретили символ , то рисуем 20й квадратик
                    if (caveMap[i][j] == 'k')  s_map.setTextureRect(sf::IntRect(32*0, 32*2, 32, 32)); //если встретили символ , то рисуем 21й квадратик
                    if (caveMap[i][j] == 'l')  s_map.setTextureRect(sf::IntRect(32*1, 32*2, 32, 32)); //если встретили символ , то рисуем 22й квадратик
                    if (caveMap[i][j] == 'm')  s_map.setTextureRect(sf::IntRect(32*2, 32*2, 32, 32)); //если встретили символ , то рисуем 23й квадратик
                    if (caveMap[i][j] == 'n')  s_map.setTextureRect(sf::IntRect(32*3, 32*2, 32, 32)); //если встретили символ , то рисуем 24й квадратик
                    if (caveMap[i][j] == 'o')  s_map.setTextureRect(sf::IntRect(32*4, 32*2, 32, 32)); //если встретили символ , то рисуем 25й квадратик
                    if (caveMap[i][j] == 'p')  s_map.setTextureRect(sf::IntRect(32*5, 32*2, 32, 32)); //если встретили символ , то рисуем 26й квадратик
                    if (caveMap[i][j] == 'q')  s_map.setTextureRect(sf::IntRect(32*6, 32*2, 32, 32)); //если встретили символ , то рисуем 27й квадратик
                    if (caveMap[i][j] == 'r')  s_map.setTextureRect(sf::IntRect(32*7, 32*2, 32, 32)); //если встретили символ , то рисуем 28й квадратик
                    if (caveMap[i][j] == 's')  s_map.setTextureRect(sf::IntRect(32*8, 32*2, 32, 32)); //если встретили символ , то рисуем 29й квадратик
                    if (caveMap[i][j] == 't')  s_map.setTextureRect(sf::IntRect(32*9, 32*2, 32, 32)); //если встретили символ , то рисуем 30й квадратик
                    if (caveMap[i][j] == 'u')  s_map.setTextureRect(sf::IntRect(32*0, 32*3, 32, 32)); //если встретили символ , то рисуем 31й квадратик
                    if (caveMap[i][j] == 'v')  s_map.setTextureRect(sf::IntRect(32*1, 32*3, 32, 32)); //если встретили символ , то рисуем 32й квадратик
                    if (caveMap[i][j] == 'w')  s_map.setTextureRect(sf::IntRect(32*2, 32*3, 32, 32)); //если встретили символ , то рисуем 33й квадратик
                    if (caveMap[i][j] == 'x')  s_map.setTextureRect(sf::IntRect(32*3, 32*3, 32, 32)); //если встретили символ , то рисуем 34й квадратик
                    if (caveMap[i][j] == 'y')  s_map.setTextureRect(sf::IntRect(32*4, 32*3, 32, 32)); //если встретили символ , то рисуем 35й квадратик
                    if (caveMap[i][j] == 'z')  s_map.setTextureRect(sf::IntRect(32*5, 32*3, 32, 32)); //если встретили символ , то рисуем 36й квадратик
                    if (caveMap[i][j] == 'A')  s_map.setTextureRect(sf::IntRect(32*6, 32*3, 32, 32)); //если встретили символ , то рисуем 37й квадратик
                    if (caveMap[i][j] == 'B')  s_map.setTextureRect(sf::IntRect(32*7, 32*3, 32, 32)); //если встретили символ , то рисуем 38й квадратик
                    if (caveMap[i][j] == 'C')  s_map.setTextureRect(sf::IntRect(32*8, 32*3, 32, 32)); //если встретили символ , то рисуем 39й квадратик
                    if (caveMap[i][j] == 'D')  s_map.setTextureRect(sf::IntRect(32*9, 32*3, 32, 32)); //если встретили символ , то рисуем 40й квадратик
                    if (caveMap[i][j] == 'E')  s_map.setTextureRect(sf::IntRect(32*0, 32*4, 32, 32)); //если встретили символ , то рисуем 41й квадратик
                    if (caveMap[i][j] == 'F')  s_map.setTextureRect(sf::IntRect(32*1, 32*4, 32, 32)); //если встретили символ , то рисуем 42й квадратик
                    if (caveMap[i][j] == 'G')  s_map.setTextureRect(sf::IntRect(32*2, 32*4, 32, 32)); //если встретили символ , то рисуем 43й квадратик
                    if (caveMap[i][j] == 'H')  s_map.setTextureRect(sf::IntRect(32*3, 32*4, 32, 32)); //если встретили символ , то рисуем 44й квадратик
                    if (caveMap[i][j] == 'I')  s_map.setTextureRect(sf::IntRect(32*4, 32*4, 32, 32)); //если встретили символ , то рисуем 45й квадратик
                    if (caveMap[i][j] == 'J')  s_map.setTextureRect(sf::IntRect(32*5, 32*4, 32, 32)); //если встретили символ , то рисуем 46й квадратик
                    if (caveMap[i][j] == 'K')  s_map.setTextureRect(sf::IntRect(32*6, 32*4, 32, 32)); //если встретили символ , то рисуем 47й квадратик
                    if (caveMap[i][j] == 'L')  s_map.setTextureRect(sf::IntRect(32*7, 32*4, 32, 32)); //если встретили символ , то рисуем 48й квадратик
                    if (caveMap[i][j] == 'M')  s_map.setTextureRect(sf::IntRect(32*8, 32*4, 32, 32)); //если встретили символ , то рисуем 49й квадратик
                    if (caveMap[i][j] == 'N')  s_map.setTextureRect(sf::IntRect(32*9, 32*4, 32, 32)); //если встретили символ , то рисуем 40й квадратик

                    s_map.setPosition(j * 32 * map_scale, (i + HEIGHT_MAP) * 32 * map_scale);

                    window.draw(s_map);

                    if(caveMapB[i][j] == '3' || caveMapB[i][j] == '4' || caveMapB[i][j] == '5' || caveMapB[i][j] == 'c' ||
                       caveMapB[i][j] == 'e' || caveMapB[i][j] == 'm' || caveMapB[i][j] == 'n' || caveMapB[i][j] == 'o' ||
                       caveMapB[i][j] == 'k' || caveMapB[i][j] == 'l' || caveMapB[i][j] == 'v') //345cemno klv
                        {
                            if (caveMapB[i][j] == '3')  s_map.setTextureRect(sf::IntRect(32*2, 32*0, 32, 32)); //если встретили символ , то рисуем 3й квадратик
                            if (caveMapB[i][j] == '4')  s_map.setTextureRect(sf::IntRect(32*3, 32*0, 32, 32)); //если встретили символ , то рисуем 4й квадратик
                            if (caveMapB[i][j] == '5')  s_map.setTextureRect(sf::IntRect(32*4, 32*0, 32, 32)); //если встретили символ , то рисуем 5й квадратик
                            if (caveMapB[i][j] == 'c')  s_map.setTextureRect(sf::IntRect(32*2, 32*1, 32, 32)); //если встретили символ , то рисуем 13й квадратик
                            if (caveMapB[i][j] == 'e')  s_map.setTextureRect(sf::IntRect(32*4, 32*1, 32, 32)); //если встретили символ , то рисуем 15й квадратик
                            if (caveMapB[i][j] == 'k')  s_map.setTextureRect(sf::IntRect(32*0, 32*2, 32, 32)); //если встретили символ , то рисуем 21й квадратик
                            if (caveMapB[i][j] == 'l')  s_map.setTextureRect(sf::IntRect(32*1, 32*2, 32, 32)); //если встретили символ , то рисуем 22й квадрати
                            if (caveMapB[i][j] == 'm')  s_map.setTextureRect(sf::IntRect(32*2, 32*2, 32, 32)); //если встретили символ , то рисуем 23й квадратик
                            if (caveMapB[i][j] == 'n')  s_map.setTextureRect(sf::IntRect(32*3, 32*2, 32, 32)); //если встретили символ , то рисуем 24й квадратик
                            if (caveMapB[i][j] == 'o')  s_map.setTextureRect(sf::IntRect(32*4, 32*2, 32, 32)); //если встретили символ , то рисуем 25й квадратик
                            if (caveMapB[i][j] == 'v')  s_map.setTextureRect(sf::IntRect(32*1, 32*3, 32, 32)); //если встретили символ , то рисуем 32й квадратик

                            window.draw(s_map);
                        }
                }
            }

    }

    void MyMap::drawLayer(){
            for (int i = 0; i < HEIGHT_MAP*1+0; i++)
            for (int j = 0; j < WIDTH_MAP*1+0; j++)
            {
                if (tileMapF[i][j] == '8')  s_map.setTextureRect(sf::IntRect(32*7, 32*0, 32, 32)); //если встретили символ , то рисуем 8й квадратик
                if (tileMapF[i][j] == '9')  s_map.setTextureRect(sf::IntRect(32*8, 32*0, 32, 32)); //если встретили символ , то рисуем 9й квадратик

                s_map.setPosition(j * 32 * map_scale , i * 32 * map_scale);

                if (tileMapF[i][j] != ' ') window.draw(s_map);
            }
    }

    char MyMap::getTileID(int x, int y){
        //cout<<x<<" "<<y<<endl;
        if(x<0 || x>WIDTH_MAP)
            return ' ';
        if(y<0 || y>WIDTH_MAP)
            return ' ';
        return tileMap[x][y];
    }

    void MyMap::setTileID(int x, int y, char tileID){
        tileMap[x][y]=tileID;
    }

    char MyMap::getTileIDB(int x, int y){
        //cout<<x<<" "<<y<<endl;
        if(x<0 || x>WIDTH_MAP)
            return ' ';
        if(y<0 || y>WIDTH_MAP+CAVE_WIDTH_MAP)
            return ' ';
        return tileMapB[x][y];
    }

    char MyMap::getTileIDC(int x, int y){
        //cout<<x<<" "<<y<<endl;
        if(x<0 || x>WIDTH_MAP)
            return ' ';
        if(y<0 || y>WIDTH_MAP+CAVE_WIDTH_MAP)
            return ' ';
        return caveMap[x][y];
    }

    char MyMap::getTileIDCB(int x, int y){
        //cout<<x<<" "<<y<<endl;
        if(x<0 || x>WIDTH_MAP)
            return ' ';
        if(y<0 || y>CAVE_WIDTH_MAP)
            return ' ';
        return caveMapB[x][y];
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

    void MyMap::captureMap(){  //ffmpeg -f image2 -framerate 2 -i tmp%d.png animated.gif
                sf::View mapview;
                mapview.setSize(32*WIDTH_MAP*map_scale, 32*HEIGHT_MAP*map_scale); mapview.setCenter(32*WIDTH_MAP*map_scale/2, 32*HEIGHT_MAP*map_scale/2);
                SYSTEMTIME time; GetLocalTime(&time);
                string dawae=WORDToStr(time.wDay)+"."+WORDToStr(time.wMonth)+"."+WORDToStr(time.wYear)+"_"+WORDToStr(time.wHour)+WORDToStr(time.wMinute)+WORDToStr(time.wSecond);

                sf::RenderTexture texture;
                texture.create(32*WIDTH_MAP*map_scale, 32*HEIGHT_MAP*map_scale);
                texture.setView(mapview);
                texture.clear();
                for (int i = 0; i < HEIGHT_MAP*1+0; i++)
                for (int j = 0; j < WIDTH_MAP*1+0; j++){
                        if (tileMap[i][j] == ' ')  s_map.setTextureRect(sf::IntRect(32*9, 32*9, 32, 32)); //если встретили символ , то рисуем 100й квадратик
                        if (tileMap[i][j] == '1')  s_map.setTextureRect(sf::IntRect(32*0, 32*0, 32, 32)); //если встретили символ , то рисуем 1й квадратик
                        if (tileMap[i][j] == '2')  s_map.setTextureRect(sf::IntRect(32*1, 32*0, 32, 32)); //если встретили символ , то рисуем 2й квадратик
                        if (tileMap[i][j] == '3')  s_map.setTextureRect(sf::IntRect(32*2, 32*0, 32, 32)); //если встретили символ , то рисуем 3й квадратик
                        if (tileMap[i][j] == '4')  s_map.setTextureRect(sf::IntRect(32*3, 32*0, 32, 32)); //если встретили символ , то рисуем 4й квадратик
                        if (tileMap[i][j] == '5')  s_map.setTextureRect(sf::IntRect(32*4, 32*0, 32, 32)); //если встретили символ , то рисуем 5й квадратик
                        if (tileMap[i][j] == '6')  s_map.setTextureRect(sf::IntRect(32*5, 32*0, 32, 32)); //если встретили символ , то рисуем 6й квадратик
                        if (tileMap[i][j] == '7')  s_map.setTextureRect(sf::IntRect(32*6, 32*0, 32, 32)); //если встретили символ , то рисуем 7й квадратик
                        if (tileMap[i][j] == '8')  s_map.setTextureRect(sf::IntRect(32*7, 32*0, 32, 32)); //если встретили символ , то рисуем 8й квадратик
                        if (tileMap[i][j] == '9')  s_map.setTextureRect(sf::IntRect(32*8, 32*0, 32, 32)); //если встретили символ , то рисуем 9й квадратик
                        if (tileMap[i][j] == '0')  s_map.setTextureRect(sf::IntRect(32*9, 32*0, 32, 32)); //если встретили символ , то рисуем 10й квадратик
                        if (tileMap[i][j] == 'a')  s_map.setTextureRect(sf::IntRect(32*0, 32*1, 32, 32)); //если встретили символ , то рисуем 11й квадратик
                        if (tileMap[i][j] == 'b')  s_map.setTextureRect(sf::IntRect(32*1, 32*1, 32, 32)); //если встретили символ , то рисуем 12й квадратик
                        if (tileMap[i][j] == 'c')  s_map.setTextureRect(sf::IntRect(32*2, 32*1, 32, 32)); //если встретили символ , то рисуем 13й квадратик
                        if (tileMap[i][j] == 'd')  s_map.setTextureRect(sf::IntRect(32*3, 32*1, 32, 32)); //если встретили символ , то рисуем 14й квадратик
                        if (tileMap[i][j] == 'e')  s_map.setTextureRect(sf::IntRect(32*4, 32*1, 32, 32)); //если встретили символ , то рисуем 15й квадратик
                        if (tileMap[i][j] == 'f')  s_map.setTextureRect(sf::IntRect(32*5, 32*1, 32, 32)); //если встретили символ , то рисуем 16й квадратик
                        if (tileMap[i][j] == 'g')  s_map.setTextureRect(sf::IntRect(32*6, 32*1, 32, 32)); //если встретили символ , то рисуем 17й квадратик
                        if (tileMap[i][j] == 'h')  s_map.setTextureRect(sf::IntRect(32*7, 32*1, 32, 32)); //если встретили символ , то рисуем 18й квадратик
                        if (tileMap[i][j] == 'i')  s_map.setTextureRect(sf::IntRect(32*8, 32*1, 32, 32)); //если встретили символ , то рисуем 19й квадратик
                        if (tileMap[i][j] == 'j')  s_map.setTextureRect(sf::IntRect(32*9, 32*1, 32, 32)); //если встретили символ , то рисуем 20й квадратик
                        if (tileMap[i][j] == 'k')  s_map.setTextureRect(sf::IntRect(32*0, 32*2, 32, 32)); //если встретили символ , то рисуем 21й квадратик
                        if (tileMap[i][j] == 'l')  s_map.setTextureRect(sf::IntRect(32*1, 32*2, 32, 32)); //если встретили символ , то рисуем 22й квадратик
                        if (tileMap[i][j] == 'm')  s_map.setTextureRect(sf::IntRect(32*2, 32*2, 32, 32)); //если встретили символ , то рисуем 23й квадратик
                        if (tileMap[i][j] == 'n')  s_map.setTextureRect(sf::IntRect(32*3, 32*2, 32, 32)); //если встретили символ , то рисуем 24й квадратик
                        if (tileMap[i][j] == 'o')  s_map.setTextureRect(sf::IntRect(32*4, 32*2, 32, 32)); //если встретили символ , то рисуем 25й квадратик
                        if (tileMap[i][j] == 'p')  s_map.setTextureRect(sf::IntRect(32*5, 32*2, 32, 32)); //если встретили символ , то рисуем 26й квадратик
                        if (tileMap[i][j] == 'q')  s_map.setTextureRect(sf::IntRect(32*6, 32*2, 32, 32)); //если встретили символ , то рисуем 27й квадратик
                        if (tileMap[i][j] == 'r')  s_map.setTextureRect(sf::IntRect(32*7, 32*2, 32, 32)); //если встретили символ , то рисуем 28й квадратик
                        if (tileMap[i][j] == 's')  s_map.setTextureRect(sf::IntRect(32*8, 32*2, 32, 32)); //если встретили символ , то рисуем 29й квадратик
                        if (tileMap[i][j] == 't')  s_map.setTextureRect(sf::IntRect(32*9, 32*2, 32, 32)); //если встретили символ , то рисуем 30й квадратик
                        if (tileMap[i][j] == 't')  s_map.setTextureRect(sf::IntRect(32*9, 32*2, 32, 32)); //если встретили символ , то рисуем 30й квадратик
                        if (tileMap[i][j] == 'u')  s_map.setTextureRect(sf::IntRect(32*0, 32*3, 32, 32)); //если встретили символ , то рисуем 31й квадратик
                        if (tileMap[i][j] == 'v')  s_map.setTextureRect(sf::IntRect(32*1, 32*3, 32, 32)); //если встретили символ , то рисуем 32й квадратик
                        if (tileMap[i][j] == 'w')  s_map.setTextureRect(sf::IntRect(32*2, 32*3, 32, 32)); //если встретили символ , то рисуем 33й квадратик
                        if (tileMap[i][j] == 'x')  s_map.setTextureRect(sf::IntRect(32*3, 32*3, 32, 32)); //если встретили символ , то рисуем 34й квадратик
                        if (tileMap[i][j] == 'y')  s_map.setTextureRect(sf::IntRect(32*4, 32*3, 32, 32)); //если встретили символ , то рисуем 35й квадратик
                        if (tileMap[i][j] == 'z')  s_map.setTextureRect(sf::IntRect(32*5, 32*3, 32, 32)); //если встретили символ , то рисуем 36й квадратик
                        if (tileMap[i][j] == 'A')  s_map.setTextureRect(sf::IntRect(32*6, 32*3, 32, 32)); //если встретили символ , то рисуем 37й квадратик
                        if (tileMap[i][j] == 'B')  s_map.setTextureRect(sf::IntRect(32*7, 32*3, 32, 32)); //если встретили символ , то рисуем 38й квадратик
                        if (tileMap[i][j] == 'C')  s_map.setTextureRect(sf::IntRect(32*8, 32*3, 32, 32)); //если встретили символ , то рисуем 39й квадратик
                        if (tileMap[i][j] == 'D')  s_map.setTextureRect(sf::IntRect(32*9, 32*3, 32, 32)); //если встретили символ , то рисуем 40й квадратик
                        if (tileMap[i][j] == 'E')  s_map.setTextureRect(sf::IntRect(32*0, 32*4, 32, 32)); //если встретили символ , то рисуем 41й квадратик
                        if (tileMap[i][j] == 'F')  s_map.setTextureRect(sf::IntRect(32*1, 32*4, 32, 32)); //если встретили символ , то рисуем 42й квадратик
                        if (tileMap[i][j] == 'G')  s_map.setTextureRect(sf::IntRect(32*2, 32*4, 32, 32)); //если встретили символ , то рисуем 43й квадратик
                        if (tileMap[i][j] == 'H')  s_map.setTextureRect(sf::IntRect(32*3, 32*4, 32, 32)); //если встретили символ , то рисуем 44й квадратик
                        if (tileMap[i][j] == 'I')  s_map.setTextureRect(sf::IntRect(32*4, 32*4, 32, 32)); //если встретили символ , то рисуем 45й квадратик
                        if (tileMap[i][j] == 'J')  s_map.setTextureRect(sf::IntRect(32*5, 32*4, 32, 32)); //если встретили символ , то рисуем 46й квадратик
                        if (tileMap[i][j] == 'K')  s_map.setTextureRect(sf::IntRect(32*6, 32*4, 32, 32)); //если встретили символ , то рисуем 47й квадратик
                        if (tileMap[i][j] == 'L')  s_map.setTextureRect(sf::IntRect(32*7, 32*4, 32, 32)); //если встретили символ , то рисуем 48й квадратик
                        if (tileMap[i][j] == 'M')  s_map.setTextureRect(sf::IntRect(32*8, 32*4, 32, 32)); //если встретили символ , то рисуем 49й квадратик
                        if (tileMap[i][j] == 'N')  s_map.setTextureRect(sf::IntRect(32*9, 32*4, 32, 32)); //если встретили символ , то рисуем 40й квадратик


                        s_map.setPosition(j * 32 * map_scale , i * 32 * map_scale);

                        texture.draw(s_map);

                        if(tileMapB[i][j] == '3' || tileMapB[i][j] == '4' || tileMapB[i][j] == '5' || tileMapB[i][j] == 'c' ||
                           tileMapB[i][j] == 'e' || tileMapB[i][j] == 'm' || tileMapB[i][j] == 'n' || tileMapB[i][j] == 'o' ||
                           tileMapB[i][j] == 'k' || tileMapB[i][j] == 'l' || tileMapB[i][j] == 'v') //345cemno klv
                            {
                                if (tileMapB[i][j] == '3')  s_map.setTextureRect(sf::IntRect(32*2, 32*0, 32, 32)); //если встретили символ , то рисуем 3й квадратик
                                if (tileMapB[i][j] == '4')  s_map.setTextureRect(sf::IntRect(32*3, 32*0, 32, 32)); //если встретили символ , то рисуем 4й квадратик
                                if (tileMapB[i][j] == '5')  s_map.setTextureRect(sf::IntRect(32*4, 32*0, 32, 32)); //если встретили символ , то рисуем 5й квадратик
                                if (tileMapB[i][j] == 'c')  s_map.setTextureRect(sf::IntRect(32*2, 32*1, 32, 32)); //если встретили символ , то рисуем 13й квадратик
                                if (tileMapB[i][j] == 'e')  s_map.setTextureRect(sf::IntRect(32*4, 32*1, 32, 32)); //если встретили символ , то рисуем 15й квадратик
                                if (tileMapB[i][j] == 'k')  s_map.setTextureRect(sf::IntRect(32*0, 32*2, 32, 32)); //если встретили символ , то рисуем 21й квадратик
                                if (tileMapB[i][j] == 'l')  s_map.setTextureRect(sf::IntRect(32*1, 32*2, 32, 32)); //если встретили символ , то рисуем 22й квадрати
                                if (tileMapB[i][j] == 'm')  s_map.setTextureRect(sf::IntRect(32*2, 32*2, 32, 32)); //если встретили символ , то рисуем 23й квадратик
                                if (tileMapB[i][j] == 'n')  s_map.setTextureRect(sf::IntRect(32*3, 32*2, 32, 32)); //если встретили символ , то рисуем 24й квадратик
                                if (tileMapB[i][j] == 'o')  s_map.setTextureRect(sf::IntRect(32*4, 32*2, 32, 32)); //если встретили символ , то рисуем 25й квадратик
                                if (tileMapB[i][j] == 'v')  s_map.setTextureRect(sf::IntRect(32*1, 32*3, 32, 32)); //если встретили символ , то рисуем 32й квадратик

                                window.draw(s_map);
                            }

                    }

                for (int i = 0; i < HEIGHT_MAP*1+0; i++)
                for (int j = 0; j < WIDTH_MAP*1+0; j++)
                {
                    if (tileMapF[i][j] == '8')  s_map.setTextureRect(sf::IntRect(32*7, 32*0, 32, 32)); //если встретили символ , то рисуем 8й квадратик
                    if (tileMapF[i][j] == '9')  s_map.setTextureRect(sf::IntRect(32*8, 32*0, 32, 32)); //если встретили символ , то рисуем 9й квадратик

                    s_map.setPosition(j * 32 * map_scale , i * 32 * map_scale);

                    if (tileMapF[i][j] != ' ') texture.draw(s_map);
                }

                texture.display();

                texture.getTexture().copyToImage().saveToFile("data/pics/map_"+dawae+".png");
                //sf::Image Screen(texture.getTexture()); Screen.saveToFile("data/pics/map_"+dawae+".jpg");
                //window.setView(view);
    }

    void MyMap::update(float time){
        timer+=0.25*time;

        if(timer>25){ timer=0;
                if(frame==1) frame=0; else frame=1;
                for (int i = 0; i < HEIGHT_MAP*1+0; i++) // world
                for (int j = 0; j < WIDTH_MAP*1+0; j++){
                        if (tileMapB[i][j] == 'l')  tileMapB[i][j] = 'v';      ///campfire
                        else if (tileMapB[i][j] == 'v')  tileMapB[i][j] = 'l';

                        if (tileMap[i][j] == 'u')  tileMap[i][j] = 'E';      ///water
                        else if (tileMap[i][j] == 'E')  tileMap[i][j] = 'u';
                    }

                for (int i = 0; i < CAVE_HEIGHT_MAP*1+0; i++) // cavessss
                for (int j = 0; j < CAVE_WIDTH_MAP*1+0; j++){
                        if (caveMapB[i][j] == 'l')  caveMapB[i][j] = 'v';      ///campfire
                        else if (caveMapB[i][j] == 'v')  caveMapB[i][j] = 'l';

                        if (caveMap[i][j] == 'u')  caveMap[i][j] = 'E';      ///water
                        else if (caveMap[i][j] == 'E')  caveMap[i][j] = 'u';
                    }
        }
    }

    int MyMap::getFrame(){
        return frame;
    }
