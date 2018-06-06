#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED

        class Text{
            private:
                sf::RenderWindow& window;
                sf::Font font;
                sf::Text tekst;

            public:
                Text(sf::RenderWindow&);
                void loadfont(string);
                void setColor(int, int, int);
                void move(float, float);
                void setposition(sf::Vector2f);
                void setString(string);
                void setStyle(unsigned short);
                void setCharacterSize(unsigned);
                void draw();

        };


#endif // TEXT_H_INCLUDED
