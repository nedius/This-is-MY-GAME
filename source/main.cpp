
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include "include/header.h"
#include "src/holo.cpp"

Net net;


////////////////////////////////////////////////////////////
/// Entry point of application
///
/// \return Application exit code
///
////////////////////////////////////////////////////////////
int main(int argc, char *argv[])
{
    //SetConsoleTitle("NeDius chat: null");
    //Coremodule core;
    //Net net;

    SCTitle(0 ,"null");
    system( "color 0a" );

    //==================================================================================================================
    // Choose an arbitrary port for opening sockets
    //const
    //unsigned short port = 10666;

    string tempadsress="";
    if(argc==3) tempadsress=argv[2];

    if(argc>=2){
    system("cls");
    cout<<"Starting ";
    if(strcmp(argv[1], "-s") == 0){
        cout<<"server..."<<endl;
        if(net.runUdpServer()) return EXIT_SUCCESS;
    }else if(strcmp(argv[1], "-c") == 0){
        cout<<"client..."<<endl;
        net.setIPadress(tempadsress);
        //net.runUdpClient();
    }else{system("cls"); cout<<"You choose wrong side )"<<endl; system("pause");}

    if(strcmp(argv[1], "-debug") != 0 && strcmp(argv[1], "-test") != 0 && strcmp(argv[1], "-c") != 0){
        return EXIT_SUCCESS;
    }}

    system("cls");
    if(argc>=2 && strcmp(argv[1], "-debug") == 0){
    // Client or server ?
    char who;
    cout << "Do you want to be a server (s) or a client (c)? ";
    cin  >> who;

    // Test the unconnected UDP protocol
        if (who == 's')
            net.runUdpServer();
        else if ( who == 'c' ){
            net.setIPadress(tempadsress);
            net.runUdpClient();
        }else cout<<"You choose wrong side )"<<endl;
    }

    system("cls");
    if(argc>=2 && strcmp(argv[1], "-test") != 1)
        { cout<<"TESTING MODE"<<endl; }
        //else net.runUdpClient(port, tempadsress);

    //==================================================================================================================

    //sf::RenderWindow  window(sf::VideoMode(1366, 768), "ETO My window");
    //sf::RenderWindow  window(sf::VideoMode(1920, 1080), "ETO My window", sf::Style::Fullscreen);

    cout<<"SFML version: "<<SFML_VERSION_MAJOR<<"."<<SFML_VERSION_MINOR<<"."<<SFML_VERSION_PATCH<<"\n---------------------------------"<<endl;

    SettingsParser settings;
    if(!settings.loadFromFile("data/appdata"))
    {
        cout << "Error loading settings file!" << endl;
        //return -1;
    }

    bool fulls=false;
    settings.get("fulls", fulls);

    bool statshow=true;
    settings.get("statshow", statshow);

    bool cheatmode=false;
    settings.get("cheatmode", cheatmode);

    bool isMusic=true;
    settings.get("isMusic", isMusic);

    bool noClear=false;
    settings.get("noClear", noClear);

    int fpslimits=60;
    settings.get("fpslimits", fpslimits);

    bool VerticalSyncEnabled=true;
    settings.get("VerticalSyncEnabled", VerticalSyncEnabled);

    bool isIdle=true;
    unsigned short isBack=1;

    sf::Clock clock;
    float time = 0;
    float CurrentFrame = 0;
    float cursortime = 0;
    bool MouseReleased=false;
    //bool isMusicDevice=true;
    bool resHasChange=true;

    vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
    for (size_t i = 0; i < modes.size(); ++i)
    {
        sf::VideoMode mode = modes[i];
        cout << "Mode #" << i << ": "
                  << mode.width << "x" << mode.height << " - "
                  << mode.bitsPerPixel << " bpp" << endl;}


    const unsigned short windowX=1360, windowY=760;
    const unsigned short fullWindowX=modes[0].width, fullWindowY=modes[0].height;

    string gameName="This is MY GAME",
            gameNameCH="This is MY GAME | CH";

    //sf::RenderWindow  window(sf::VideoMode(1920, 1080), "ETO My window", sf::Style::Fullscreen);
    sf::RenderWindow  window(sf::VideoMode(windowX, windowY), gameName.c_str(), sf::Style::Close);
    if(!VerticalSyncEnabled && fpslimits!=0) window.setFramerateLimit(fpslimits);
    if(VerticalSyncEnabled) window.setVerticalSyncEnabled(true);

    window.setIcon( holo_image.width,  holo_image.height,  holo_image.pixel_data );

    sf::View view;
    view.setSize(windowX, windowY);
    //view.setSize(3840, 2160);

    MyMap tiledMap(window);

    sf::Vector2i mouse;

    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile(DEFAULT_FONT))
        { cout<<"Mising font!"<<endl; getch(); return EXIT_FAILURE; }

//    // Load a sprite to display
//    sf::Texture btex;
//    if (!btex.loadFromFile("data/tex/background.png"))
//        { cout<<"Mising background image!"<<endl; getch(); return EXIT_FAILURE; }
//    btex.setSmooth(true);
//    sf::Sprite sprite(btex);
//    sf::Vector2f targetSize(window.getView().getSize());
//    sprite.scale(targetSize.x / sprite.getLocalBounds().width, targetSize.y / sprite.getLocalBounds().height);

    //char textik[1024];
    //int razmer;
    //gets(textik);
    //cin>>razmer;
    //sf::Text text("0\n\\|/\n/\\", font, 50);
    sf::Text text("pre-alfa  TATATTATATTATATTATTATAT", font, 25);
    //sf::Text text(textik, font, razmer);
    text.setFillColor(sf::Color::White);
    text.move(0,25);

    sf::Text fpsc("0", font, 25);
    fpsc.setFillColor(sf::Color::White);

    sf::Text p1pos("0", font, 20);
    p1pos.setFillColor(sf::Color::White);
    p1pos.move(0,75);
    sf::Text p2pos("0", font, 20);
    p2pos.setFillColor(sf::Color::White);
    p2pos.move(0,100);

    sf::Text resolution("0", font, 20);
    resolution.setFillColor(sf::Color::White);
    resolution.move(0,55);

    //if(alcOpenDevice(NULL)!= NULL) isMusicDevice=true; else isMusicDevice=false;

    sf::Music music;
    if (!music.openFromFile("data/audio/NightRadio_-_Music_in_Our_Souls.ogg"))
            { cout<<"Mising audio!"<<endl; getch(); return EXIT_FAILURE; }
    music.setVolume(100);
    music.setPitch(0.1);
    //music.openFromFile("tada.wav");
    music.setLoop(true);
    music.play();

    sf::Image image;
    if (!image.loadFromFile("data/tex/player.png"))
        { cout<<"Mising player image!"<<endl; getch(); return EXIT_FAILURE; }
    image.createMaskFromColor(sf::Color::Green);

                                                                                    Player p("Pope_Casual", 330, 1300, 53, 86, tiledMap); ///ezela kades
                                                                                    //Player p("Ezella", 330, 1300, 45, 94, tiledMap);
                                                                                    Player pp("Pope_Casual", 250, 100, 53, 86, tiledMap);
                                                                                    //pp.setPosition(330, 1300);

    sf::Texture ptex;
    //if (!ptex.loadFromFile("player.png"))
    //    return EXIT_FAILURE;
    ptex.loadFromImage(image);
    ptex.setSmooth(true);

    //ptex.createMaskFromColor(sf::Color(0, 0, 0), 0);

    //sf::Sprite p1{ptex};
    //p1.setTexture(ptex);
    //p1.setColor(sf::Color(0, 255, 0));
    ///p1.setScale(sf::Vector2f(1.0f, 1.0f));
    //p1.setOrigin(37, 37); //p1.setOrigin(32, 32);
    //p1.move(50, 15);

    sf::Sprite p2(ptex);
    p2.setTexture(ptex);
    p2.setColor(sf::Color(255, 0, 0));
    //p2.setScale(sf::Vector2f(-1.0f, 1.0f));
    p2.setOrigin(37, 37); //p2.setOrigin(32, 32);
    p2.move(100, 15);

    // Activate the window for OpenGL rendering
    window.setActive();
    window.requestFocus();
    //window.setMouseCursorGrabbed(true);

    float speed=1;
    int dir=1;
    //int framelimit=0;

    //cout<<"Server adress?"<<endl;
    //cin>>tempadsress;
    net.setIPadress(tempadsress);
    sf::Thread thread(&Net::runUdpClient, &net);
    thread.launch();

    sf::sleep(sf::seconds(1));

    if(net.getID()!=""){
        text.setString(text.getString()+" "+net.getID());
        if(net.getID()=="vt"){
                //p1.setColor(sf::Color(255, 0, 0));
                p2.setColor(sf::Color(0, 255, 0));
        }
    }//else{text.setString(text.getString()+" ");}

                                                                            Text sometext(window);

                                                                            sometext.loadfont(DEFAULT_FONT);
                                                                            sometext.setCharacterSize(25);
                                                                            //sometext.setColor(255,0,0);
                                                                            sometext.setString("Jiggle text!");
                                                                            sometext.move(200, 300);

                                                                            Button exitb(window, 100, 50);
                                                                            //exitb.move(windowX/2, 0);
                                                                            exitb.setString("exit");
                                                                            exitb.move(windowX/2-exitb.getSize().x/2, 0);
                                                                            exitb.setCustomSize(true);

                                                                            Button coub(window, 100, 50);
                                                                            //coub.move(windowX/2, 0);
                                                                            coub.setString("COUB !!!");
                                                                            coub.move(windowX/2-coub.getSize().x/2, 0);
                                                                            coub.setCustomSize(true);

                                                                            Sprite cursor(window);
                                                                            cursor.loadimage("data/tex/cursor.png");
                                                                            cursor.move(0, 0);
                                                                            cursor.setScale(0.2, 0.2);

                                                                            window.setMouseCursorVisible(false);

//        const int HEIGHT_MAP=40;
//        const int WIDTH_MAP=43;
//
//        string tileMap[HEIGHT_MAP] = {
//        "1111111111111111111111111111111111111111111", //1
//        "111 1  11 1  1111                         1",
//        "11 b 2   b 2 b b 2    b 2 b               1",
//        "11     b  b   2b 2 2                      1",
//        "1     2b 2 2       b  b                   1", //5
//        "11  dddd ddd  d   d ddd  ddd ddddd        1",
//        "111 d  d d  d dd  d d  d d     d          1",
//        "11  d  d ddd  d d d ddd  dd    d          1",
//        "1   d  d d    d d d d  d d     d          1",
//        "11  d  d d    d  dd ddd  ddd   d          1", //10
//        "1               34445                     1",
//        "1111     345 67 c6n7e    89               1",
//        "1a  lv   cde fg ce2ce  l hi               1",
//        "1    k   mno    cf4ge  k rs               1",
//        "1   11          mnnno                     1", //15
//        "1                                         1",
//        "1   35    34445                           1",
//        "1   mf44446nnnf445                        1",
//        "1    mnnnno   mnno                        1",
//        "1     111                                 1", //20
//        "1    1    1                               1",
//        "1    1    1                               1",
//        "1    1    1                               1",
//        "1    111111                               1",
//        "1                                         1", //25
//        "1                                         1",
//        "1                                         1",
//        "1                                         1",
//        "1                                         1",
//        "1                                         1", //30
//        "1                                         1",
//        "1                                         1",
//        "1                                         1",
//        "1                                         1",
//        "1                                         1", //35
//        "1                                         1",
//        "1                                         1",
//        "1                                         1",
//        "1                                         1",
//        "1111111111111111111111111111111111111111111", //40
//    };
//
//
//        /// 1 2 3 4 5 6 7 8 9 0
//        /// a b c d e f g h i j
//        /// k l m n o p q r s t
//        /// u v w x y z A B C D
//        /// E F G H I J K L M N
//        /// O P Q R S T U V W X
//        /// Y Z
//        ///
//        ///
//        ///                  " "

        //p.setTileMap(tiledMap);

        //for(int i=0;i<256;i++) cout<<i<<": \""<<(char)i<<"\""<<endl;


    //float map_scale=tiledMap.getMapScale();
    //p.map_scale=tiledMap.getMapScale();

    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                {window.close(); net.stopUdpClient();}
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

            //sf::Vector2f vector;
            window.setView(view);

            // Clear screen
            if(!noClear) window.clear(sf::Color::Black);
            // Draw the sprite
            //if(!noClear) //window.draw(sprite);

            tiledMap.draw();

            //window.draw(p2);
            //window.draw(p1);
            //window.draw(p.getSprite);
            pp.draw(window);
            p.draw(window);

            tiledMap.drawLayer();

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
            window.draw(p2pos);                        }

            fpsc.setString(IntToString(GetFrameRate()));
            window.draw(fpsc);

                                                                        //static int style=1;
                                                                        //sometext.setStyle(style);
                                                                        //style++;
                                                                        //sometext.setposition(sf::Vector2f(200, 300));
                                                                        sometext.setString(IntToString(mouse.x)+"x "+IntToString(mouse.y)+"y mouse");
                                                                        sometext.draw();
                                                                        //if(style>3) style=0;

                                                                        exitb.draw(mouse);
                                                                        coub.draw(mouse);

                                                                        cursortime+=0.1*time;
                                                                        if(cursortime<100) cursor.draw();
                                                                        if(cursortime>500){ if(cursortime>550) cursortime-=100; drawText(window, font, 100, view.getCenter().x-300, view.getCenter().y, "Are you there ?");}

            // Update the window
            window.display();

            tiledMap.update(time);

            if(1==2) MakeDISASTER();


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

            if(window.hasFocus()){
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) speed+=1; else if(speed>1) speed-=1;
            //if(sf::Keyboard::isKeyPressed(sf::Keyboard::C) && sf::Keyboard::isKeyPressed(sf::Keyboard::H) && cheatmode) cheatmode=true; else cheatmode=false;

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::C) && sf::Keyboard::isKeyPressed(sf::Keyboard::H) && !cheatmode){ cheatmode=true; window.setTitle(gameNameCH.c_str()); Sleep(100); }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::C) && sf::Keyboard::isKeyPressed(sf::Keyboard::H) && cheatmode){ cheatmode=false; window.setTitle(gameName.c_str()); Sleep(100); }

            if(cheatmode) window.setTitle(gameNameCH.c_str()); else window.setTitle(gameName.c_str());

            if(!isMusic){music.setVolume(0); }
            else if(isMusic){ music.setVolume(100); }

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

            p.update(time);

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


            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {window.close(); net.stopUdpClient();}

            if(exitb.isKeyPressed(MouseReleased)) {window.close(); net.stopUdpClient();} //system("start chrome http://coub.com/nedfavre");
            if(coub.isKeyPressed(MouseReleased)) {system("start chrome http://coub.com/nedfavre");}

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

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Tilde)) p.changeCharacter();

            }//}

            if(fulls && resHasChange){
                    resHasChange=false; window.create(sf::VideoMode(1, 1), gameName.c_str(), sf::Style::Fullscreen);
                    view.setSize(fullWindowX, fullWindowY);
                    if(!VerticalSyncEnabled && fpslimits!=0) window.setFramerateLimit(fpslimits);
                    if(VerticalSyncEnabled) window.setVerticalSyncEnabled(true);
                    window.setMouseCursorVisible(false);
                    window.setIcon( holo_image.width,  holo_image.height,  holo_image.pixel_data );
                    //window.setVerticalSyncEnabled(true); sf::Vector2f targetSize(window.getView().getSize()); sprite.setScale(1, 1);
                    //sprite.scale(targetSize.x / sprite.getLocalBounds().width, targetSize.y / sprite.getLocalBounds().height);
                    exitb.move(window.getView().getSize().x/2-exitb.getSize().x/2, 0);
                    coub.move(window.getView().getSize().x-coub.getSize().x*2, 0);
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
                    exitb.move(window.getView().getSize().x/2-exitb.getSize().x/2, 0);
                    coub.move(window.getView().getSize().x-coub.getSize().x*2, 0);
                    }

            if(isIdle){
                CurrentFrame += 0.03*time;
                if (CurrentFrame > 6) CurrentFrame -= CurrentFrame;
                //p.animate(sf::IntRect(13 + 80*int(CurrentFrame), 10+(121*(isBack-1)), 53, 86)); //37
                if(isBack==2) p.animate("upI", CurrentFrame, isBack);
                if(isBack==1) p.animate("downI", CurrentFrame, isBack);

                speed=0;
            }

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

            cout<<isIdle2<<" "<<isBack2<<" "<<dir2<<" "<<speed2<<" "<<CurrentFrame2<<" "<<p2.x<<" "<<p2.y<<endl;

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
            sf::Vector2f position=p.getPosition();
            if(!net.SendToServer(position, isIdleI, isBackI, dir, speed, CurrentFrameI)){
                    net.stopUdpClient();
                    ///cout<<"Cant send to server"<<endl;                                            /// CANT SEND TO SERVER
                    //getch();
                    //window.close();
            }

            view.setCenter(p.getPosition());

            //sf::Vector2f vectoru=view.getSize();

            //int x=vectoru.x;
            //int y=vectoru.y;

            resolution.setString(IntToString(view.getSize().x)+"x"+IntToString(view.getSize().y)+" speed:"+IntToString(speed));

            ///if(vector.x>vectoru.x) p1.setPosition(0, vector.y); ///p1.move(-x, 0);
            ///if(vector.x<0) p1.setPosition(x, vector.y); ///p1.move(x, 0);
            ///if(vector.y>vectoru.y) p1.setPosition(vector.x, 0); ///p1.move(0, -y);
            ///if(vector.y<0) p1.setPosition(vector.x, y); ///p1.move(0, y);

            //const int HEIGHT_MAP = 30;//размер карты высота
            //const int WIDTH_MAP = 43;//размер карты ширина

            //if(vector.x>32*WIDTH_MAP*map_scale) p1.setPosition(32*WIDTH_MAP*map_scale, vector.y);
            //vector=p1.getPosition();
            //if(vector.x<0) p1.setPosition(0, vector.y);
            //vector=p1.getPosition();
            //if(vector.y>32*HEIGHT_MAP*map_scale) p1.setPosition(vector.x, 32*HEIGHT_MAP*map_scale);
            //vector=p1.getPosition();
            //if(vector.y<0) p1.setPosition(vector.x, 0);
            //vector=p1.getPosition();

            //sf::Vector2f center=view.getCenter();
            float tempX=view.getCenter().x, tempY=view.getCenter().y;
            if(view.getCenter().x<680) tempX=680;
            if(view.getCenter().y<383) tempY=383;

            //if(center.y>(97+32)+(480*map_scale)) tempY=(97+32)+(480*map_scale);
            //480*map_scale     609 577     vector.y>(32*HEIGHT_MAP*map_scale)-765/2
                                                                //576   1
                                                                //1057  1.5     480
                                                                //1537  2       480
                                                                //2017  2.5     480
                                                                //2497  3       480

            int px=p.getPosition().x, py=p.getPosition().y; //Player
            int mapw=32*tiledMap.getWidth()*tiledMap.getMapScale(), maph=32*tiledMap.getHeight()*tiledMap.getMapScale(); //Map Size
            //sf::Vector2f screensize=view.getSize();
            int scrw=view.getSize().x, scrh=view.getSize().y; // Screen size

            int camx, camy;
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
            ///cout<<camx<<" "<<camy<<endl;
            //view.setCenter(camy+(scrw/10), camx-(scrw/10));
            //view.setCenter(tempX, tempY);

            tempX=camx; tempY=camy;

            fpsc.setPosition(tempX-view.getSize().x/2, tempY-view.getSize().y/2); ///text 0,25 p1pos 0.75 p2pos 0,100 resolution 0,55
            text.setPosition(tempX-view.getSize().x/2, tempY-view.getSize().y/2+25);
            text.setString("pre-alfa "+IntToString(camx)+"x "+IntToString(camy)+"y screen");
            resolution.setPosition(tempX-view.getSize().x/2, tempY-view.getSize().y/2+55);
            p1pos.setPosition(tempX-view.getSize().x/2, tempY-view.getSize().y/2+75);
            p2pos.setPosition(tempX-view.getSize().x/2, tempY-view.getSize().y/2+100);

            sometext.setposition(sf::Vector2f(tempX-view.getSize().x/2+50, tempY-view.getSize().y/2));
            cursor.setposition(sf::Vector2f(tempX-view.getSize().x/2+mouse.x, tempY-view.getSize().y/2+mouse.y));


            //if(vector.x<0 && vector.y<0) p1.setPosition(0, 0);
            //if(vector.x<0 && vector.y>32*WIDTH_MAP*map_scale) p1.setPosition(32*WIDTH_MAP*map_scale, 0);
            //if(vector.x<0 && vector.y<0) p1.setPosition(0, 0);
            //if(vector.x<0 && vector.y<0) p1.setPosition(0, 0);

            //vector=p2.getPosition();

            //x=vectoru.x;
            //y=vectoru.y;

            //if(vector.x>vectoru.x) p2.move(-x, 0);
            //if(vector.x<0) p2.move(x, 0);
            //if(vector.y>vectoru.y) p2.move(0, -y);
            //if(vector.y<0) p2.move(0, y);

    }

    // Wait until the user presses 'enter' key
    //cout << "Press enter to exit..." << endl;
    //cin.ignore(10000, '\n');
    //cin.ignore(10000, '\n');
    //system("pause");

    return EXIT_SUCCESS;
}
