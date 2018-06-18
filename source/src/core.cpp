#include "../include/header.h"
#include "holo.cpp"

//#include <SFML/Network.hpp>
//#include <SFML/System.hpp>
//#include <SFML/Window.hpp>
//#include <SFML/Audio.hpp>
//#include <SFML/Graphics.hpp>
//#include <SFML/Graphics/Color.hpp>
//#include <SFML/Window/Keyboard.hpp>
//#include <SFML/OpenGL.hpp>
//#include <iostream>
//#include <cstdio>
//#include <windows.h>
//#include <conio.h>
//#include <cstdlib>
//#include <sstream>
//#include <string>
//#include <thread>
//#include <fstream>
//
//#include "../include/network.h"
//#include "../include/SettingsParser.hpp"
//#include "../include/sprite.h"
//#include "../include/text.h"
//#include "../include/player.h"
//#include "../include/mymap.h"
//#include "../include/button.h"
//#include "../include/ProgressBar.hpp"
//#include "../include/form.h"
//#include "../include/core.h"



    Core::Core(Net& temp, sf::RenderWindow& win)
    : net(temp), window(win), tiledMap(win), text("pre-alfa  TATATTATATTATATTATTATAT", font, 25), fpsc("0", font, 25),
      p1pos("0", font, 20), p2pos("0", font, 20), resolution("0", font, 20), p("Pope_Casual", 1000, 5330, 53, 86, tiledMap),
      pp("Pope_Casual", 1000, 5330, 53, 86, tiledMap), sometext(window), cursor(window), thread(&Net::runUdpClient, &net)
    {
        cout<<"SFML version: "<<SFML_VERSION_MAJOR<<"."<<SFML_VERSION_MINOR<<"."<<SFML_VERSION_PATCH<<"\n---------------------------------"<<endl;

        getSave();

        vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
        for (size_t i = 0; i < modes.size(); ++i)
        {
            sf::VideoMode mode = modes[i];
            cout << "Mode #" << i << ": "
                      << mode.width << "x" << mode.height << " - "
                      << mode.bitsPerPixel << " bpp" << endl;}

        fullWindowX=modes[0].width; fullWindowY=modes[0].height;

        //sf::RenderWindow  window(sf::VideoMode(1920, 1080), "ETO My window", sf::Style::Fullscreen);
        window.create(sf::VideoMode(windowX, windowY), gameName.c_str(), sf::Style::Close);
        if(!VerticalSyncEnabled && fpslimits!=0) window.setFramerateLimit(fpslimits);
        if(VerticalSyncEnabled) window.setVerticalSyncEnabled(true);

        window.setIcon( holo_image.width,  holo_image.height,  holo_image.pixel_data );

        view.setSize(windowX, windowY);
        //view.setSize(3840, 2160);

        // Create a graphical text to display
        if (!font.loadFromFile(DEFAULT_FONT))
            { cout<<"Mising font!"<<endl; getch(); return; }

//       // Load a sprite to display
//       sf::Texture btex;
//       if (!btex.loadFromFile("data/tex/background.png"))
//           { cout<<"Mising background image!"<<endl; getch(); return EXIT_FAILURE; }
//       btex.setSmooth(true);
//       sf::Sprite sprite(btex);
//       sf::Vector2f targetSize(window.getView().getSize());
//       sprite.scale(targetSize.x / sprite.getLocalBounds().width, targetSize.y / sprite.getLocalBounds().height);

        text.setFillColor(sf::Color::White);
        text.move(0,25);

        fpsc.setFillColor(sf::Color::White);

        p1pos.setFillColor(sf::Color::White);
        p1pos.move(0,75);
        p2pos.setFillColor(sf::Color::White);
        p2pos.move(0,100);

        resolution.setFillColor(sf::Color::White);
        resolution.move(0,55);

        //if(alcOpenDevice(NULL)!= NULL) isMusicDevice=true; else isMusicDevice=false;

        if (!music.openFromFile("data/audio/NightRadio_-_Music_in_Our_Souls.ogg"))
                { cout<<"Mising audio!"<<endl; getch(); return; }
        music.setVolume(musicVol);
        music.setLoop(true);

        pp.setPosition(330, 1300);

        // Activate the window for OpenGL rendering
        window.setActive();
        window.requestFocus();
        //window.setMouseCursorGrabbed(true);

        sometext.loadfont(DEFAULT_FONT);
        sometext.setCharacterSize(25);
        //sometext.setColor(255,0,0);
        sometext.setString("Jiggle text!");
        sometext.move(200, 300);

        cursor.loadimage("data/tex/cursor.png");
        cursor.move(0, 0);
        cursor.setScale(0.2, 0.2);

        window.setMouseCursorVisible(false);

        //for(int i=0;i<256;i++) cout<<i<<": \""<<(char)i<<"\""<<endl;

        progressBar.setShowBackgroundAndFrame(true);
        progressBar.setSize({ 300.f, 20.f });
        progressBar.setFrameThickness(1.f);
        //progressBar.setOrigin(progressBar.getSize() / 2.f);
        progressBar.setPosition(sf::Vector2f(window.getView().getCenter().x-window.getView().getSize().x/2+10, window.getView().getCenter().y+window.getView().getSize().y/2-30));
        progressBar.setColor(sf::Color::Green);
        progressBar.setBackgroundColor(sf::Color(0, 0, 0, 50));
        progressBar.setFrameColor(sf::Color::Black);
        progressBar.setPercentage(50.f);

        if (!bgimg.loadFromFile("data/tex/menubg.png")){ cout<<"Missing some image!"<<endl; }else{
                bgtex.loadFromImage(bgimg);
                bgtex.setSmooth(true);
                bgsprite.setTexture(bgtex);
            }
        bgsprite.setPosition(0, 0);

    }

    void Core::INTRO(){
        sf::Clock clock;
        float time=0, timer=0;

        sf::Font font;
        if (!font.loadFromFile("data/Caviar Dreams.ttf"))
            return;

        sf::Music music;
        if (!music.openFromFile("data/audio/nice_music.ogg"))
            return;

        music.play();

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            time=clock.restart().asMilliseconds();
            timer+=time; //18000

            if(timer>=18000 || sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
                music.stop();
                break;
            }

            window.clear(sf::Color::Black);
            drawText(window, font, 100, "NeD ius present");
            window.display();
        }
        return;
    }

    int Core::run(){
        clock.restart();

        music.play();

        while (window.isOpen())
        {
            // check all the window's events that were triggered since the last iteration of the loop
            sf::Event event;
            while (window.pollEvent(event))
            {
                // "close requested" event: we close the window
                if (event.type == sf::Event::Closed)
                    {window.close(); net.stopUdpClient();}
                if (event.type == sf::Event::KeyPressed)
                    if (event.key.code == sf::Keyboard::Escape)
                        menu();
                if (event.type == sf::Event::Resized)
                    {cursor.resize();}
                if (event.type == sf::Event::MouseMoved){
                    mouse.x=event.mouseMove.x;
                    mouse.y=event.mouseMove.y;
                    cursortime=0;
                    }
                if (event.type == sf::Event::MouseButtonPressed){
                    if (event.mouseButton.button == sf::Mouse::Left)
                            MouseReleased=true; else MouseReleased=false;
                            //if(MouseReleased) cout<<MouseReleased<<" MouseReleased"<<endl;
                    }else MouseReleased=false;
                if (event.type == sf::Event::TextEntered){
                    if (event.text.unicode < 128){
                        if(event.text.unicode == 13) cout<<endl;
                        else if(event.text.unicode == 8) cout<<(char)(event.text.unicode)<<" ";
                        cout<<(char)(event.text.unicode); //static_cast<char>
                    }}
            }

                time = clock.restart().asMicroseconds();
                //clock.restart();
                time = time/3000;
                ///cout<<time<<endl;

                tiledMap.update(time);

                if(1==2) MakeDISASTER();

                if(p.isInCave()) music.setPitch(0.5); else music.setPitch(1);


                //if(StringToInt(GetFrameRate())<=65){

                //if(framelimit<60){
                //framelimit++;
                //if(framelimit>=60) framelimit=0;

                //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                //{
                // move down...
                //text.move(-speed,-speed);}
                //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                //{
                // move down...
                //text.move(speed,-speed);}
                //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                //{
                // move down...
                //text.move(-speed,speed);}
                //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                //{
                // move down...
                //text.move(speed,speed);}
                // -----------------------------------------------------------

                //speed=5;

                //cout<<p.getHealth()<<" HP"<<endl;
                progressBar.setPercentage(p.getHealth());
                if(p.getHealth()<=0){ p.setDeath(); music.pause(); YouDied(); music.play(); p.toSpawn();  time=0; }

                if(window.hasFocus()){
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
                    getSave();
                }

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::P) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) YouDied();
                //menu(window);
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::I) && sf::Keyboard::isKeyPressed(sf::Keyboard::O)) menu();
                //if(sf::Keyboard::isKeyPressed(sf::Keyboard::C) && sf::Keyboard::isKeyPressed(sf::Keyboard::H) && cheatmode) cheatmode=true; else cheatmode=false;

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::C) && sf::Keyboard::isKeyPressed(sf::Keyboard::H) && !cheatmode){ cheatmode=true; window.setTitle(gameNameCH.c_str()); Sleep(100); }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::C) && sf::Keyboard::isKeyPressed(sf::Keyboard::H) && cheatmode){ cheatmode=false; window.setTitle(gameName.c_str()); Sleep(100); }

                if(cheatmode) window.setTitle(gameNameCH.c_str()); else window.setTitle(gameName.c_str());

                //if(!isMusic){music.setVolume(0); }
                //else if(isMusic){ music.setVolume(musicVol); }

                music.setVolume(musicVol);

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::M) && !isMusic){ isMusic=true; Sleep(100); }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::M) && isMusic){ isMusic=false; Sleep(100); }

                //if(!cheatmode)if(speed>10) speed=10;
                //if(cheatmode)if(speed>750) speed=750;
                //if(sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))  p2.setPosition(p1.getPosition());

                //p.sprite.setScale(-1,1);

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                {
                // move up...
    //            p1.move(0,-speed*time);
    //            p1.setScale(sf::Vector2f(1.0f, 1.0f));
                    isIdle=false; isBack=2;
                    cursortime=101;
                    //p.dir = 3; p.speed = 1;
                    dir=3; speed=1;
                    p.impulse(dir, speed);
                    CurrentFrame += 0.05*time;
                    if (CurrentFrame > 6) CurrentFrame -= CurrentFrame;
                    //p.animate(sf::IntRect(13 + 80*int(CurrentFrame), 250+(121*(isBack-1)), 53, 86)); //371 //.sprite
                    p.animate("up",CurrentFrame, isBack);

                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                {
                // move down...
    //            p1.move(0,speed*time);
    //            p1.setScale(sf::Vector2f(1.0f, -1.0f));
                    isIdle=false; isBack=1;
                    cursortime=101;
                    //p.dir = 2; p.speed = 1;
                    dir=2; speed=1;
                    p.impulse(dir, speed);
                    CurrentFrame += 0.05*time;
                    if (CurrentFrame > 6) CurrentFrame -= CurrentFrame;
                    //p.animate(sf::IntRect(13 + 80*int(CurrentFrame), 250+(121*(isBack-1)), 53, 86));
                    p.animate("down",CurrentFrame, isBack);

                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                { //1 player
                // move left...
    //            p1.move(-speed*time,0); //x, y
    //            p1.setScale(sf::Vector2f(-1.0f, 1.0f));
                    isIdle=false;
                    cursortime=101;
                    //p.dir=1; p.speed=1;
                    dir=1; speed=1;
                    p.impulse(dir, speed);
                    CurrentFrame += 0.05*time;
                    if (CurrentFrame > 6) CurrentFrame -= CurrentFrame;
                    //p.animate(sf::IntRect(13 + 80*int(CurrentFrame), 250+(121*(isBack-1)), 53, 86));
                    p.animate("left",CurrentFrame, isBack);
                    //p.setScale(1,1);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                // move right...
    //            p1.move(speed*time,0);
    //            p1.setScale(sf::Vector2f(1.0f, 1.0f));
                    isIdle=false;
                    cursortime=101;
                    //p.dir = 0; p.speed = 1;
                    dir=0; speed=1;
                    p.impulse(dir, speed);
                    CurrentFrame += 0.05*time;
                    if (CurrentFrame > 6) CurrentFrame -= CurrentFrame;
                    //p.animate(sf::IntRect(13 + 80*int(CurrentFrame), 250+(121*(isBack-1)), 53, 86)); //371
                    p.animate("right",CurrentFrame, isBack);
                    //p.setScale(-1,1);
                }else{
                    isIdle=true;
                }

                /*//2 player
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                {
                // move left...
                p2.move(-speed,0); //x, y
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                // move right...
                p2.move(speed,0);}
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                {
                // move up...
                p2.move(0,-speed);}
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) )
                {
                // move down...
                p2.move(0,speed);}*/


                //if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                //    menu(window);
                    //{window.close(); net.stopUdpClient();}

                //if(exitb.isKeyPressed(MouseReleased)) {
                //        menu();
                //        mouse.x=sf::Mouse::getPosition().x-window.getPosition().x-3;
                //        mouse.y=sf::Mouse::getPosition().y-window.getPosition().y-26;}
                //if(coub.isKeyPressed(MouseReleased)) {system("start chrome http://coub.com/nedfavre");} //system("start chrome http://coub.com/nedfavre"); coub channels with music

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::F11) && !fulls){ fulls=true; resHasChange=true; }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::F11) && fulls ){ fulls=false; resHasChange=true; }

                /// here been change window

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::F5) && !statshow){ statshow=true; Sleep(100); }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::F5) && statshow){ statshow=false; Sleep(100); }

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::F12) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
                    tiledMap.captureMap();
                }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::F12)){
                        sf::Texture Screen; Screen.create(window.getSize().x, window.getSize().y); Screen.update(window); SYSTEMTIME time; GetLocalTime(&time);
                        string dawae=WORDToStr(time.wDay)+"."+WORDToStr(time.wMonth)+"."+WORDToStr(time.wYear)+"_"+WORDToStr(time.wHour)+WORDToStr(time.wMinute)+WORDToStr(time.wSecond);
                        Screen.copyToImage().saveToFile("data/pics/screenshot_"+dawae+".png");
                }

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && sf::Keyboard::isKeyPressed(sf::Keyboard::Tilde)) p.changeCharacter(0);

                }//}

                if(fulls && resHasChange){
                        resHasChange=false; window.create(sf::VideoMode(fullWindowX, fullWindowY), gameName.c_str(), sf::Style::Fullscreen);
                        view.setSize(fullWindowX, fullWindowY);
                        if(!VerticalSyncEnabled && fpslimits!=0) window.setFramerateLimit(fpslimits);
                        if(VerticalSyncEnabled) window.setVerticalSyncEnabled(true);
                        window.setMouseCursorVisible(false);
                        window.setIcon( holo_image.width,  holo_image.height,  holo_image.pixel_data );
                        //window.setVerticalSyncEnabled(true); sf::Vector2f targetSize(window.getView().getSize()); sprite.setScale(1, 1);
                        //sprite.scale(targetSize.x / sprite.getLocalBounds().width, targetSize.y / sprite.getLocalBounds().height);
                        //exitb.move(window.getView().getSize().x/2-exitb.getSize().x/2, 0);
                        //coub.move(window.getView().getSize().x-coub.getSize().x*2, 0);
                        window.display();
                        }
                if(!fulls && resHasChange){
                        resHasChange=false; window.create(sf::VideoMode(windowX, windowY), gameName.c_str(), sf::Style::Close);
                        view.setSize(windowX, windowY);
                        if(!VerticalSyncEnabled && fpslimits!=0) window.setFramerateLimit(fpslimits);
                        if(VerticalSyncEnabled) window.setVerticalSyncEnabled(true);
                        window.setMouseCursorVisible(false);
                        window.setIcon( holo_image.width,  holo_image.height,  holo_image.pixel_data );
                        //window.setVerticalSyncEnabled(true); sf::Vector2f targetSize(window.getView().getSize()); sprite.setScale(1, 1);
                        //sprite.scale(targetSize.x / sprite.getLocalBounds().width, targetSize.y / sprite.getLocalBounds().height);
                        //exitb.move(window.getView().getSize().x/2-exitb.getSize().x/2, 0);
                        //coub.move(window.getView().getSize().x-coub.getSize().x*2, 0);
                        window.display();
                        }

                if(isIdle){
                    CurrentFrame += 0.03*time;
                    if (CurrentFrame > 6) CurrentFrame -= CurrentFrame;
                    //p.animate(sf::IntRect(13 + 80*int(CurrentFrame), 10+(121*(isBack-1)), 53, 86)); //37
                    if(isBack==2) p.animate("upI", CurrentFrame, isBack);
                    if(isBack==1) p.animate("downI", CurrentFrame, isBack);

                    speed=0;
                }

                p.update(time);

                //sf::VideoMode mode=sf::VideoMode::getDesktopMode();
                //unsigned int h=mode.height;
                //unsigned int w=mode.width;

                //vector=p1.getPosition();
                //vector=p.getPosition();

                //p2.setPosition(net.getPPOS();

                sf::Vector2f p2;
                bool isIdle2;
                int isBack2, dir2, CurrentFrame2;
                float speed2;

                net.getVPData(p2, isIdle2, isBack2, dir2, speed2, CurrentFrame2);

                //cout<<isIdle2<<" "<<isBack2<<" "<<dir2<<" "<<speed2<<" "<<CurrentFrame2<<" "<<p2.x<<" "<<p2.y<<endl;

                if(CurrentFrame2==-1){ pp.changeCharacter(-1); CurrentFrame2=0; }
                if(CurrentFrame2==-2){ pp.changeCharacter(-2); CurrentFrame2=0; }

                pp.impulse(dir2, speed2);

                if(dir2==3) pp.animate("up", CurrentFrame2, isBack2+1);
                if(dir2==2) pp.animate("down", CurrentFrame2, isBack2+1);
                if(dir2==1) pp.animate("left", CurrentFrame2, isBack2+1);
                if(dir2==0) pp.animate("right", CurrentFrame2, isBack2+1);
                if(isIdle2 && isBack2) pp.animate("upI", CurrentFrame2, isBack2+1);
                if(isIdle2 && !isBack2) pp.animate("downI", CurrentFrame2, isBack2+1);

                pp.update(time);
                pp.setPosition(p2.x, p2.y);

                net.setPPOS(p.getPosition());
                int isBackI=isBack, CurrentFrameI=CurrentFrame, isIdleI=isIdle;

                if(p.isCharacterChanged())
                    {
                        if(p.getCharacter()=="Pope_Casual") CurrentFrameI=-1;
                        if(p.getCharacter()=="Ezella") CurrentFrameI=-2;
                    }

                sf::Vector2f position=p.getPosition();
                if(!net.SendToServer(position, isIdleI, isBackI, dir, speed, CurrentFrameI)){
                        net.stopUdpClient();
                        ///cout<<"Cant send to server"<<endl;                                            /// CANT SEND TO SERVER
                        //getch();
                        //window.close();
                }

                view.setCenter(p.getPosition());

                resolution.setString(IntToString(view.getSize().x)+"x"+IntToString(view.getSize().y)+" speed:"+IntToString(speed));

                int px=p.getPosition().x, py=p.getPosition().y; //Player
                int mapw=32*tiledMap.getWidth()*tiledMap.getMapScale(), maph=32*tiledMap.getHeight()*tiledMap.getMapScale(); //Map Size
                //sf::Vector2f screensize=view.getSize();
                int scrw=view.getSize().x, scrh=view.getSize().y; // Screen size

                float camx, camy;

                camx=px; camy=py;
                if(maph-scrh/2<py)
                    camy = maph-scrh/2;
                if(scrh/2>py)
                    camy = scrh/2;
                if(mapw-scrw/2<px)
                    camx = mapw-scrw/2;
                if(scrw/2>px)
                    camx = scrw/2;
                view.setCenter(camx, camy);
                if(p.isInCave()){
                        camx=p.getPosition().x;
                        camy=p.getPosition().y;
                        view.setCenter(camx, camy);
                    }
                ///cout<<camx<<" "<<camy<<endl;
                //view.setCenter(camy+(scrw/10), camx-(scrw/10));
                //view.setCenter(tempX, tempY);

                fpsc.setPosition(camx-view.getSize().x/2, camy-view.getSize().y/2); ///text 0,25 p1pos 0.75 p2pos 0,100 resolution 0,55
                text.setPosition(camx-view.getSize().x/2, camy-view.getSize().y/2+25);
                text.setString("pre-alfa "+IntToString(camx)+"x "+IntToString(camy)+"y screen");
                resolution.setPosition(camx-view.getSize().x/2, camy-view.getSize().y/2+55);
                p1pos.setPosition(camx-view.getSize().x/2, camy-view.getSize().y/2+75);
                p2pos.setPosition(camx-view.getSize().x/2, camy-view.getSize().y/2+100);
                progressBar.setPosition(sf::Vector2f(camx-view.getSize().x/2+10, camy+view.getSize().y/2-30));

                sometext.setposition(sf::Vector2f(camx-view.getSize().x/2+50, camy-view.getSize().y/2));
                cursor.setposition(sf::Vector2f(camx-view.getSize().x/2+mouse.x, camy-view.getSize().y/2+mouse.y));

                //sf::Vector2f vector;
                window.setView(view);

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::V)) cout<<p.getPosition().x<<"x "<<p.getPosition().y<<"y"<<endl;

                ///-------------------RENDER---------------------///

                // Clear screen
                window.clear(sf::Color::Black);

                if(!p.isInCave()) tiledMap.draw(0);
                if(p.isInCave()) tiledMap.draw(1);

                //window.draw(p2);
                //window.draw(p1);
                //window.draw(p.getSprite);
                if(!pp.isInCave() && !p.isInCave()) pp.draw(window);
                if(pp.isInCave() && p.isInCave()) pp.draw(window);
                p.draw(window);

                if(!p.isInCave()) tiledMap.drawLayer();

                // Draw the string
                if(statshow){                           //statistic
                window.draw(resolution);
                window.draw(text);



                //vector=p1.getPosition();
                //float x = vector.x;
                //float y = vector.y;

                //p1pos.setString(FloatToStr(x)+"x "+FloatToStr(y)+"y");
                p1pos.setString(FloatToStr(p.getPosition().x)+"x "+FloatToStr(p.getPosition().y)+"y");
                window.draw(p1pos);

                //vector=p2.getPosition();
                //x = vector.x;
                //y = vector.y;

                p2pos.setString(FloatToStr(pp.getPosition().x)+"x "+FloatToStr(pp.getPosition().y)+"y");
                window.draw(p2pos);

                sometext.setString(IntToString(mouse.x)+"x "+IntToString(mouse.y)+"y mouse "+FloatToStr(cursortime));
                sometext.draw();               }

                fpsc.setString(IntToString(GetFrameRate()));
                window.draw(fpsc);

                                                                            //static int style=1;
                                                                            //sometext.setStyle(style);
                                                                            //style++;
                                                                            //sometext.setposition(sf::Vector2f(200, 300));
                                                                            //if(style>3) style=0;

                //exitb.draw(mouse);
                //if(isDebug) coub.draw(mouse);
                window.draw(progressBar);

                                                                            cursortime+=0.1*time;
                                                                            if(cursortime<100) cursor.draw();
                                                                            if(cursortime>400 && cursortime<450) elementNumber=rand() % masiveNumber;
                                                                            if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)){ /*srand(cursortime*elementNumber);*/ cursortime=440; }
                                                                            if(cursortime>500){ if(cursortime>550) cursortime-=100; drawText(window, font, 100, splash[elementNumber]);}


                ///drawText(window, font, 100, "002 13 6337"); //002 13 6337 OHAYO GOZAIMASU

                // Update the window
                window.display();

        }

        return 0;
    }

    void Core::menu(){
        //window.create(sf::VideoMode(1360, 760), "This is MY GAME", sf::Style::Close);
        window.setView(window.getDefaultView());

        sf::Clock clock;
        float time=0, timer=0;

        sf::Font font;
        if (!font.loadFromFile(DEFAULT_FONT))
            return;

        //sf::Music music;
        //if (!music.openFromFile("data/audio/nice_music.ogg"))
        //    return;

        sf::Vector2i mouse(sf::Mouse::getPosition().x-window.getPosition().x-3, sf::Mouse::getPosition().y-window.getPosition().y-26);
        //cout<<mouse.x<<" "<<mouse.y<<endl;

        bool close=false;
        bool MouseReleased=false;
        int mCount=1;
        static bool setings=false;
        static bool settGen=true;
        static bool settNet=false;
        static bool settDev=false;

        form::Label fps(0, 0, "0"); //fps

        form::Button button(30, 130);
        form::Label label(30, 180, "Privet"); //Settings General Volume
        form::Input input(190, 130, 200, 30);

        form::Button button2(230, 130, 150, 30, "Zamenit tekst");

        form::Label label2(230, 250, "Gav");

        form::Label label3(30, 350, "Vvedite IP-adress:");
        form::Input input2(30, 400, 200, 30, "192.168.1.64");
        form::Button button3(280, 350, 150, 150, "Connect");

        form::Button button4(30, 30, 150, 30, "Resume"); //Resume 160x 50y
        form::Button button5(190, 30, 150, 30, "Settings"); //Settings
        form::Button button7(350, 30, 150, 30, "Credits"); //Credits
        form::Button button6(510, 30, 150, 30, "Exit"); //Exit

        form::Button button51(30, 80, 150, 30, "General"); //Settings General
        form::Button button52(190, 80, 150, 30, "Network"); //Settings Network
        form::Button button53(350, 80, 150, 30, "DEV"); //Settings DEV

        form::Label label511(30, 130, "Volume"); //Settings General Volume
        form::Input input511(190, 130, 150, 30, IntToString(musicVol));
        form::Button button511(350, 130, 100, 30, "Set volume");

        form::Label label521(30, 130, "Status: STOPPED");
        form::Label label522(30, 180, "Server IP:");
        form::Input input521(120, 180, 150, 30, net.getIPAdress().toString());
        form::Button button521(280, 180, 100, 30, "Set ip");
        form::Button button522(30, 230, 100, 30, "START");
        form::Button button523(140, 230, 100, 30, "STOP");


        //music.play();

        window.setMouseCursorVisible(true);

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                // "close requested" event: we close the window
                if (event.type == sf::Event::Closed)
                    { close=true; window.close(); }
                if (event.type == sf::Event::KeyPressed)
                    if (event.key.code == sf::Keyboard::Escape)
                        close=true;
                if (event.type == sf::Event::MouseMoved){
                    mouse.x=event.mouseMove.x;
                    mouse.y=event.mouseMove.y;
                    //cout<<mouse.x<<" "<<mouse.y<<endl;
                    }
                if (event.type == sf::Event::TextEntered){
                    if (event.text.unicode < 128){
                        if(event.text.unicode == 13) cout<<endl;
                        else if(event.text.unicode == 8) cout<<(char)(event.text.unicode)<<" ";
                        cout<<(char)(event.text.unicode); //static_cast<char>
                    }
                    if(input.select()){
                        input.reText(event.text.unicode); }
                    if(input2.select()){
                        input2.reText(event.text.unicode); }
                    if(input511.select()){
                        //if(input511.readText()=="") input511.reText('0');
                        if(event.text.unicode==8) input511.reText(event.text.unicode);
                        if(event.text.unicode>=48 && event.text.unicode<=57 )
                            //if((int)StringToFloat(input511.readText())>=0 && (int)StringToFloat(input511.readText())<=100)
                                input511.reText(event.text.unicode); }
                        //input511.reText(event.text.unicode); }
                    if(input521.select()){
                        input521.reText(event.text.unicode); }
                    }
                }


            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                MouseReleased=true;
                if(mCount>1){MouseReleased=false; mCount++;
                }else mCount++;
                }else{MouseReleased=false; mCount=1;}

            //cout<<mCount<<" "<<MouseReleased<<endl;

            //if(close || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) break;
            if(close) break;

            time=clock.restart().asMilliseconds();
            timer+=time; //18000

            if( button4.select(mouse, MouseReleased)){ window.setMouseCursorVisible(false); return;} //resume
            if( button5.select(mouse, MouseReleased)){ if(setings) setings=false; else setings=true; } //setiings
            if( button7.select(mouse, MouseReleased)){ cout<<"Credits"<<endl; } //credits
            if( button6.select(mouse, MouseReleased)){ close=true; window.close(); } //exit

            if(setings){
                if( button51.select(mouse, MouseReleased)){
                    settGen=true;
                    settNet=false;
                    settDev=false;
                } //Settings General
                if( button52.select(mouse, MouseReleased)){
                    settGen=false;
                    settNet=true;
                    settDev=false;
                } //Settings Network
                if( button53.select(mouse, MouseReleased)){
                    settGen=false;
                    settNet=false;
                    settDev=true;
                } //Settings Dev
                if(settGen){
                    input511.select(mouse);
                    if( button511.select(mouse, MouseReleased)){musicVol=(int)StringToFloat(input511.readText());
                        if(musicVol>=0 && musicVol<=100) cout<<"\nSet music volume to: "<<musicVol<<endl;
                            else { musicVol=100; input511.text=IntToString(musicVol); cout<<"\nSet music volume to: "<<musicVol<<endl;
                                    music.setVolume(musicVol); }
                        }
                        settings.set("musicVol", musicVol);
                }
                if(settNet){
                    input521.select(mouse);
                    if(net.getClientStatus())
                        label521.text="Status: RUNNING"; else label521.text="Status: STOPPED";
                    if(button521.select(mouse, MouseReleased)){
                        tempadsress=input521.readText();
                        net.setIPadress(tempadsress);
                    }
                    if(button522.select(mouse, MouseReleased)){
                        label521.text="Status: ...";
                        tempadsress=input521.readText();
                        net.setIPadress(tempadsress);
                        client("start");
                    }
                    if(button523.select(mouse, MouseReleased)){
                        label521.text="Status: ...";
                        client("stop");
                    }
                }
                if(settDev && isDebug){
                    input.select(mouse);			//поле ввода
                    input2.select(mouse);	  		//поле ввода
                    if( button.select(mouse, MouseReleased)){label.text = "Nazhata knopka!" ;}
                    if( button2.select(mouse, MouseReleased)){label2.text = input.readText() ;}
                    if( button3.select(mouse, MouseReleased)){cout<<input2.readText()<<endl;}
                }
            }

            window.clear(sf::Color::Green);

            window.draw(bgsprite);

            if(setings){

                button51.displayButton(window); //Settings General
                button51.displayText(window);
                button52.displayButton(window); //Settings Network
                button52.displayText(window);
                if(settDev && isDebug){
                    button53.displayButton(window); //Settings DEV
                    button53.displayText(window);
                }

                if(settGen){
                    label511.displayText(window);
                    input511.displayButton(window);
                    input511.displayText(window);
                    button511.displayButton(window);
                    button511.displayText(window);
                }
                if(settNet){
                    label521.displayText(window);
                    label522.displayText(window);
                    input521.displayButton(window);
                    input521.displayText(window);
                    button521.displayButton(window);
                    button521.displayText(window);
                    button522.displayButton(window);
                    button522.displayText(window);
                    button523.displayButton(window);
                    button523.displayText(window);
                }
                if(settDev && isDebug){
                    label.displayText(window);
                    label2.displayText(window);
                    label3.displayText(window);

                    button2.displayButton(window);
                    button2.displayText(window);

                    button.displayButton(window);
                    button.displayText(window);

                    button3.displayButton(window);
                    button3.displayText(window);

                    input.displayButton(window);
                    input.displayText(window);
                    input2.displayButton(window);
                    input2.displayText(window);
                }
            }

            button4.displayButton(window); //resume
            button4.displayText(window);
            button5.displayButton(window); //settings
            button5.displayText(window);
            button7.displayButton(window); //credit
            button7.displayText(window);
            button6.displayButton(window); //exit
            button6.displayText(window);

            fps.text=IntToString(GetFrameRate());
            fps.displayText(window);
            drawText(window, font, 50, 670, 25, "This Is My game");

            window.display();
        }

        window.setMouseCursorVisible(false);

        return;
    }

        void Core::YouDied(){
        sf::Clock clock;
        float time=0, timer=0;

        sf::Texture texture;
        if (!texture.loadFromFile("data/tex/black.png"))
            return;
        sf::Sprite black(texture);
        black.setPosition(window.getView().getCenter().x-window.getView().getSize().x/2, window.getView().getCenter().y-window.getView().getSize().y/2);
        black.setScale(window.getView().getSize().x / black.getLocalBounds().width, window.getView().getSize().y / black.getLocalBounds().height);

        sf::Font font;
        if (!font.loadFromFile(DEFAULT_FONT))
            return;

        sf::Music music;
        if (!music.openFromFile("data/audio/dark_souls_death.ogg"))
            return;

        music.play();

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            time=clock.restart().asMilliseconds();
            timer+=time; //18000

            if(timer>=9000){
                music.stop();
                break;
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && sf::Keyboard::isKeyPressed(sf::Keyboard::P)){
                music.stop();
                break;
            }

            //window.clear(sf::Color::Black);
            window.draw(black);
            drawText(window, font, 100, "YOU DIED");
            window.display();
        }
        return;
    }

    void Core::save(){

        settings.loadFromFile("data/appdata");
        //if(settings.isChanged()){
            settings.set("VerticalSyncEnabled", VerticalSyncEnabled);
            settings.set("fpslimits", fpslimits);
            settings.set("fulls", fulls);
            settings.set("statshow", statshow);
            settings.set("cheatmode", cheatmode);
            settings.set("isMusic", isMusic);
            settings.set("musicVol", musicVol);
            //settings.set("isDebug", isDebug);
            resHasChange=true;
            //}
            //settings.print();
            cout<<"\n---------------SAVED--------------"<<endl;
        //


        return;
    }

    void Core::getSave(){
            if(!settings.loadFromFile("data/appdata")){
                    cout << "Error loading settings file!" << endl;
                }

            settings.get("VerticalSyncEnabled", VerticalSyncEnabled);
            settings.get("fpslimits", fpslimits);
            settings.get("fulls", fulls);
            settings.get("statshow", statshow);
            settings.get("cheatmode", cheatmode);
            settings.get("isMusic", isMusic);
            settings.get("musicVol", musicVol);
            settings.get("isDebug", isDebug);
            resHasChange=true;
            //settings.print();
            cout<<"\n---------------LOADED-------------"<<endl;

            return;
    }

    void Core::client(string command){
        if(net.getClientStatus() && command=="stop")
            net.stopUdpClient();
        if(!net.getClientStatus() && command=="start"){
            net.setIPadress(tempadsress);
            //sf::Thread thread(&Net::runUdpClient, &net);
            thread.launch();
            //sf::sleep(sf::seconds(1));
        }
        return;
    }
