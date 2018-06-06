#include "../include/button.h"

    Button::Button(sf::RenderWindow& win, int w, int h) : window(win) {
        font.loadFromFile(DEFAULT_FONT);
        caption.setFont(font);
        setString(text);
        //unsigned int chSize=caption.getCharacterSize();
        //caption.setCharacterSize(10);
        W=w; H=h;
        origW=w; origH=h;
        //W=chSize*text.length();
        rectangle.setSize(sf::Vector2f(origW, origH));
        //rectangle.setOrigin(W/2, H/2);
        rectangle.setFillColor(sf::Color(58, 137, 237));
        rectangle.setOutlineColor(sf::Color::Transparent);
        rectangle.setOutlineThickness(2);
    }

    void Button::setSize(int w, int h){
        W=w; H=h;
        if(isCustomSize) rectangle.setSize(sf::Vector2f(w, h));
        if(!isCustomSize) rectangle.setSize(sf::Vector2f(origW, origH));
    }

    void Button::setString(string str){
        text=str;
        caption.setString(text);
        setSize(caption.getLocalBounds().width, H);
        //W=caption.getLocalBounds().width;
    }

    void Button::setCustomSize(bool bolean){
        isCustomSize=!bolean;
        rectangle.setSize(sf::Vector2f(getSize().x, getSize().y));
    }

    sf::Vector2i Button::getSize(){
        if(isCustomSize) return sf::Vector2i(W, H);
        if(!isCustomSize) return sf::Vector2i(origW, origH);
        return sf::Vector2i(origW, origH);
        //return sf::Vector2i(W, H);
    }

    void Button::move(float x, float y){
        this->x=x; this->y=y;
        rectangle.setPosition(sf::Vector2f(x, y));
    }


    bool Button::isKeyPressed(bool event){
        //sf::Event event; if(window.pollEvent(event)==sf::Event::MouseButtonReleased)
        if(isSelected) if(event) return isPressed;
        return false;
    }

    void Button::draw(sf::Vector2i mouse){

        cornerX=window.getView().getCenter().x-window.getView().getSize().x/2;
        cornerY=window.getView().getCenter().y-window.getView().getSize().y/2;
        m_cornerX=mouse.x+cornerX;
        m_cornerY=mouse.y+cornerY;

        rectangle.setPosition(cornerX+x, cornerY+y);
        //x=cornerX+x; y=cornerY+y;

        if(m_cornerX>cornerX+x && m_cornerX<cornerX+x+getSize().x && m_cornerY>cornerY+y && m_cornerY<cornerY+y+getSize().y) isSelected=true; else isSelected=false;
        //if(mouse.x>x && mouse.x<W && mouse.y>y && mouse.y<H)

        if(isSelected) rectangle.setOutlineColor(sf::Color(9, 45, 93)); else rectangle.setOutlineColor(sf::Color::Transparent);
        if(isSelected){ if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) isPressed=true; else isPressed=false; }

        window.draw(rectangle);

        if(isCustomSize) caption.setPosition(cornerX+x, cornerY+y);
        if(!isCustomSize) caption.setPosition((cornerX+x)+(caption.getLocalBounds().width/2), (cornerY+y)+(caption.getLocalBounds().height/4));

        window.draw(caption);

        ///debug cout
        //cout<<mouse.x<<" "<<mouse.y<<" mouse("<<m_cornerX<<"x"<<m_cornerY<<"y) ("<<isSelected<<" isSelected "<<isPressed<<" isPressed "<<") "<<cornerX+x<<" "<<cornerX+x+W<<" "<<cornerY+y<<" "<<cornerY+y+H<<" "<<cornerX<<" "<<cornerY<<endl;
    }
