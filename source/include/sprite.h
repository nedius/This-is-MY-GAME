#ifndef SPRITE_H_INCLUDED
#define SPRITE_H_INCLUDED

        class Sprite{
            private:
                sf::RenderWindow& window;
                sf::Image image;
                sf::Texture texture;
                sf::Sprite sprite;

                /*if (!image.loadFromFile("data/tex/player.png")) { cout<<"Mising some image!"<<endl; getch(); return EXIT_FAILURE; }
                image.createMaskFromColor(sf::Color::Green);
                ptex.loadFromImage(image);
                ptex.setSmooth(true);
                //ptex.createMaskFromColor(sf::Color(0, 0, 0), 0);
                p1.setTexture(ptex);
                p1.setColor(sf::Color(0, 255, 0));
                //p1.setScale(sf::Vector2f(1.0f, 1.0f));
                p1.setOrigin(37, 37); //p1.setOrigin(32, 32);
                p1.move(50, 15);*/

            public:
                Sprite(sf::RenderWindow&);
                void loadimage(string);
                void setTransperent(int, int, int, int);
                void move(float, float);
                void setposition(sf::Vector2f);
                void setposition(sf::Vector2i);
                void setScale(float x, float y);
                void resize();
                void draw();

        };


#endif // SPRITE_H_INCLUDED
