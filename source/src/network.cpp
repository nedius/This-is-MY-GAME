#include "../include/header.h"

    Net::Net() : server(sf::IpAddress::LocalHost){
        SettingsParser settings;
        settings.loadFromFile("data/appdata");
        settings.get("isDebug", isDebug);
    }

        void Net::setIPadress(sf::IpAddress ip){
        //cout<<"ip: "<<ip<<endl;
        server=ip;
        //cout<<server.toString()<<endl;
        //cout<<"server: "<<server<<endl;
        }

////////////////////////////////////////////////////////////
/// Launch a server, wait for a message, send an answer.
/// UDP
////////////////////////////////////////////////////////////

    int tps=0;

    bool Net::runUdpServer(){
        // Create a socket to receive a message from anyone
        //sf::UdpSocket socket;
        SCTitle(0 ,"server");

        cout<<"Server isDebug="<<isDebug<<endl;

        HWND consoleHWND=GetConsoleHwnd();

        //ShowWindow( consoleHWND, SW_HIDE );

        bool consoleShow=false;

        sf::RenderWindow  window(sf::VideoMode(320, 500), "Server runing ...");
        //window.setFramerateLimit(120);
        window.setVerticalSyncEnabled(true);

        window.setPosition(sf::Vector2i(1590,510));

//        // Load a sprite to display
//        sf::Texture btex;
//        if (!btex.loadFromFile("data/tex/bg.png"))
//            { cout<<"Mising background image!"<<endl; getch(); return EXIT_FAILURE; }
//        btex.setSmooth(true);
//        sf::Sprite sprite(btex);
//        sf::Vector2f targetSize(window.getView().getSize());
//        sprite.scale(targetSize.x / sprite.getLocalBounds().width, targetSize.y / sprite.getLocalBounds().height);
//
//        sf::Font font;
//        if (!font.loadFromFile("data/Caviar Dreams.ttf"))
//            { cout<<"Mising font!"<<endl; getch(); return false; }
//
//        sf::Text text("0", font, 25);
//        text.setFillColor(sf::Color::Green);

        //p1.x=50; p1.y=15;
        //p2.x=100; p2.y=-100;

        // Listen to messages on the specified port
        if (net.bind(this->port) != sf::Socket::Done)
            return false;
        cout << "Server is listening to " << sf::IpAddress::getPublicAddress() << ":" << port << ", waiting for a client... " << endl;

        //cout<<ipp1.toString()<<endl<<ipp2.toString()<<endl;


        //unsigned int tps=120, ktps=0;
        //int tps;

//        Button kick1(window, 30, 30);
//        kick1.setString("X");
//        kick1.move(window.getSize().x-25, 25);
//        kick1.setCustomSize(false);
//
//        Button kick2(window, 30, 30);
//        kick2.setString("X");
//        kick2.move(window.getSize().x-25, 125);
//        kick2.setCustomSize(false);

        //Net a;
        //sf::Thread t(&Net::startServerUI, std::ref(a));

        //std::thread thr(this->startServerUI); ///sf::RenderWindow &window
        //thread.launch();



        sf::Thread thread(&startServerUI, &window); //, &window

        window.setActive(false);

        thread.launch();

        sf::Clock clock;
        float time = 0;

        sf::Vector2i mouse;

        //int countt=0;


        while (window.isOpen())
            {

                sf::Event event;
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed){
                        window.close();
                        return false;
                    }
                    if (event.type == sf::Event::MouseMoved){
                        mouse.x=event.mouseMove.x;
                        mouse.y=event.mouseMove.y;
                    }
                }

                time = clock.restart().asMicroseconds();
                //clock.restart();
                time = time/3000;
                //cout<<time<<endl;

                //cout<<GetFrameRate()<<" tps "<<endl;
                tps=GetFrameRate();

                //if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                //    countt+=10;
                //if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                //    countt-=10;

                //countt-=100000;

                //sf::sleep(sf::microseconds(countt));

//                window.clear(sf::Color::White);
//                window.draw(sprite);
//                ///draw fps
//                text.setPosition(0,0);
//                text.setString(IntToString(GetFrameRate())+" tps");
//                window.draw(text);
//                ///draw INTERFACE IS NOT USER FRIENDLY
//                text.setString("INUF");
//                text.setPosition(320-(text.getLocalBounds().width*2),0);
//                window.draw(text);
//                ///draw 1 player status
//                text.setPosition(0,25);
//                text.setString(getPStats(1));
//                window.draw(text);
//                ///draw 2 player status
//                text.setPosition(0,25*5);
//                text.setString(getPStats(2));
//                window.draw(text);
//
//                //kick1.draw(mouse);
//                //kick2.draw(mouse);
//
//                window.display();

                ///------------------------

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::PageUp) && consoleShow){ consoleShow=false; ShowWindow( consoleHWND, SW_RESTORE ); sf::sleep(sf::milliseconds(100)); }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::PageUp) && !consoleShow){ consoleShow=true; ShowWindow( consoleHWND, SW_HIDE ); sf::sleep(sf::milliseconds(100)); }
                //tps=GetFrameRate();

                //if(tps<120){

                //ktps++;

                //cout<<tps<<endl;

                //if(net.isBlocking()) cout<<"Blocking"<<endl;

                string answer="";

                /// ok pe/vt impulse bool_isIdle int_isBack int_dir float_speed int_CurrentFrame
                /// answer="ok vt impulse "+BoolToStr(isIdle)+" "+IntToString(isBack)+" "+IntToString(dir)+" "+FloatToStr(speed)+" "+IntToString(CurrentFrame);

                /// ok pe/vt cord float_x float_y
                /// answer="ok vt cord "+FloatToStr(p1.x)+" "+FloatToStr(p1.y);

                // Wait for a message
                char in[128];
                size_t received;
                sf::IpAddress sender;
                unsigned short senderPort;
                net.setBlocking(false);
                if (net.receive(in, sizeof(in), received, sender, senderPort) == sf::Socket::Done){ //!= sf::Socket::Done
                    //continue; //return;
                //net.setBlocking(true);
                i++;
                if(isDebug) cout << i << "|in|" << sender << ":"<<senderPort<<"| " << (string)in << " " << endl;
                }else{

                if(ipp1!=sf::IpAddress::None && ipport1!=0){ //|| ipp1==sf::IpAddress::Any
                    //answer="ok pe "+FloatToStr(p2.x)+" "+FloatToStr(p2.y);
                    answer="ok vt "+IntToString(isIdle2)+" "+IntToString(isBack2-1)+" "+IntToString(dir2)+" "+FloatToStr(speed2)+" "+IntToString(CurrentFrame2)+" "+FloatToStr(p2.x)+" "+FloatToStr(p2.y); /// impulse
                        if(!net.send(answer.c_str(),  answer.size() + 1, ipp1, ipport1) ){  //!= sf::Socket::Done
                    //answer="";
                    i++;
                    if(isDebug) cout << i << "|out|" << ipp1 << ":"<<ipport1<<"| " << answer << " " << endl;
                }}

                if(ipp2!=sf::IpAddress::None && ipport2!=0){
                    //answer="ok vt "+FloatToStr(p1.x)+" "+FloatToStr(p1.y);
                    answer="ok pe "+IntToString(isIdle1)+" "+IntToString(isBack1-1)+" "+IntToString(dir1)+" "+FloatToStr(speed1)+" "+IntToString(CurrentFrame1)+" "+FloatToStr(p1.x)+" "+FloatToStr(p1.y); /// impulse
                        if(!net.send(answer.c_str(),  answer.size() + 1, ipp2, ipport2) ){  //!= sf::Socket::Done
                    //answer="";
                    i++;
                    if(isDebug) cout << i << "|out|" << ipp2 << ":"<<ipport2<<"| " << answer << " " << endl;
                }} continue; }

                net.setBlocking(true);

                // See what message we get
                string temp=in;

                if(GetPID(temp)!=ID1 && GetPID(temp)!=ID2){
                if(temp=="cic"){
                    if(ipp1==sf::IpAddress::None){ ipp1=sender; ipport1=senderPort; answer="ok "+ID1; if(net.send(answer.c_str(),  answer.size() + 1, sender, senderPort) != sf::Socket::Done) return false; }else //!= sf::Socket::Done
                    if(ipp2==sf::IpAddress::None){ ipp2=sender; ipport2=senderPort; answer="ok "+ID2; if(net.send(answer.c_str(),  answer.size() + 1, sender, senderPort) != sf::Socket::Done) return false; } //!= sf::Socket::Done
                    //answer="";

                }else{answer="NOO"; if(net.send(answer.c_str(),  answer.size() + 1, sender, senderPort) != sf::Socket::Done) return false;} //!= sf::Socket::Done

                    i++;
                    if(isDebug) cout << i << "|out|" << sender << ":"<<senderPort<<"| " << answer << " " << endl;

                if(temp=="bye "+ID1){ ipp1=sf::IpAddress::None; ipport1=0; }
                if(temp=="bye "+ID2){ ipp2=sf::IpAddress::None; ipport2=0; }

                }else if(GetPID(temp)==ID1){ /*p1.x=GetXCord(temp); p1.y=GetYCord(temp);*/ getPlayerData2(temp, p1, isIdle1, isBack1, dir1, speed1, CurrentFrame1);
                }else if(GetPID(temp)==ID2){ /*p2.x=GetXCord(temp); p2.y=GetYCord(temp);*/ getPlayerData2(temp, p2, isIdle2, isBack2, dir2, speed2, CurrentFrame2);}

                //cout<<"!! "<<p1.x<<" "<<p1.y<<" | "<<p2.x<<" "<<p2.y<<endl;

                if(ipp1!=sf::IpAddress::None && ipport1!=0){ //|| ipp1==sf::IpAddress::Any
                    answer="ok vt "+IntToString(isIdle2)+" "+IntToString(isBack2-1)+" "+IntToString(dir2)+" "+FloatToStr(speed2)+" "+IntToString(CurrentFrame2)+" "+FloatToStr(p2.x)+" "+FloatToStr(p2.y); ///impulse
                        if(net.send(answer.c_str(),  answer.size() + 1, ipp1, ipport1) != sf::Socket::Done) return false; //!= sf::Socket::Done
                    //answer="";
                    i++;
                    if(isDebug) cout << i << "|out|" << ipp1 << ":"<<ipport1<<"| " << answer << " " << endl;
                }

                if(ipp2!=sf::IpAddress::None && ipport2!=0){
                    answer="ok pe "+IntToString(isIdle1)+" "+IntToString(isBack1-1)+" "+IntToString(dir1)+" "+FloatToStr(speed1)+" "+IntToString(CurrentFrame1)+" "+FloatToStr(p1.x)+" "+FloatToStr(p1.y); /// impulse
                        if(net.send(answer.c_str(),  answer.size() + 1, ipp2, ipport2) != sf::Socket::Done) return false; //!= sf::Socket::Done
                    //answer="";
                    i++;
                    if(isDebug) cout << i << "|out|" << ipp2 << ":"<<ipport2<<"| " << answer << " " << endl;
                }

                // Send an answer to the client
                /**int num;
                //int numcount;
                string zOTVET[]={"200 ok", "400 Bad_Request", "404 Not_Found", "voistinu pidr"};
                if(temp=="") num=1; else if(temp=="olezha pidr") num=3; else if(temp=="hui" || temp=="huj" || temp=="gblh" || temp=="pidor" || temp=="pidr") num=2; else num=0;
                //const char out[128];//=zOTVET[num].c_str();
                //for(int i=0;i<numcount;i++){out[i] = zOTVET[i].at[i];}
                //if (socket.send(out, sizeof(out), sender, senderPort) != sf::Socket::Done)
                //numcount==(strlen(zOTVET[num].c_str()) + 1)  * sizeof(char)+4;
                if (net.send(zOTVET[num].c_str(),  zOTVET[num].size() + 1, sender, senderPort) != sf::Socket::Done)
                    return;
                //cout << "Message sent to the client: \"" << out << "\"" << endl;}
                cout << "Message sent to the client: \"" << zOTVET[num] << "\"" << endl;*/

                //}else{ sf::sleep(sf::milliseconds(6)); }
            }

            thread.wait();

            ///while(1){
            ///}
            return false;
    }

    void startServerUI(sf::RenderWindow* win){

        sf::RenderWindow& window=*win;

        // Load a sprite to display
        sf::Texture btex;
        if (!btex.loadFromFile("data/tex/bg.png"))
            { cout<<"Mising background image!"<<endl; getch(); return; }
        btex.setSmooth(true);
        sf::Sprite sprite(btex);
        sf::Vector2f targetSize(window.getView().getSize());
        sprite.scale(targetSize.x / sprite.getLocalBounds().width, targetSize.y / sprite.getLocalBounds().height);

        sf::Font font;
        if (!font.loadFromFile("data/Caviar Dreams.ttf"))
            { cout<<"Mising font!"<<endl; getch(); return; }

        sf::Text text("0", font, 25);
        text.setFillColor(sf::Color::Green);

        Button kick1(window, 30, 30);
        kick1.setString("X");
        kick1.move(window.getSize().x-25, 25);
        kick1.setCustomSize(false);

        Button kick2(window, 30, 30);
        kick2.setString("X");
        kick2.move(window.getSize().x-25, 125);
        kick2.setCustomSize(false);

        sf::Vector2i mouse;

        sf::Time time;
        sf::Clock elaps;

        while(window.isOpen()){

                sf::Event event;
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed){
                        window.close();
                        return;
                    }
                    if (event.type == sf::Event::MouseMoved){
                        mouse.x=event.mouseMove.x;
                        mouse.y=event.mouseMove.y;
                    }
                }

                      static int frameCounter = 0;
                      static int fps = 0;
                      frameCounter++;
                      time = elaps.getElapsedTime();
                      if(time.asMilliseconds() > 249)
                      {
                         fps = frameCounter;
                         frameCounter = 0;
                         elaps.restart();
                      }
                      //tempp=IntToString(fps);
                      //return tempp;
                      //fps=fps*4;
                      //cout<<fps*4<<" | "<<frameCounter<<endl;

                window.clear(sf::Color::White);
                window.draw(sprite);
                ///draw fps
                text.setPosition(0,0);
                text.setString(IntToString(fps*4)+" fps | "+IntToString(tps)+" tps");
                window.draw(text);
                ///draw INTERFACE IS NOT USER FRIENDLY
                //text.setString("INUF");
                //text.setPosition(320-(text.getLocalBounds().width*2),0);
                //window.draw(text);
                ///draw 1 player status
                text.setPosition(0,25);
                text.setString("Player: 1\nnot 1 conected\n"); //text.setString(net.getPStats(1));
                window.draw(text);
                ///draw 2 player status
                text.setPosition(0,25*5);
                text.setString("Player: 2\nnot 2 conected\n"); //text.setString(net.getPStats(2));
                window.draw(text);

                //kick1.draw(mouse);
                //kick2.draw(mouse);

                window.display();

        }

    }


////////////////////////////////////////////////////////////
/// Send a message to the server, wait for the answer
///
////////////////////////////////////////////////////////////


    void Net::runUdpClient(){
        SCTitle(0 ,"client");

        cout<<"Server isDebug="<<isDebug<<endl;

        p1.x=100; p1.y=-100;
        p2.x=100; p2.y=-100;
        //cout<<FloatToStr(p1.x)<<" "<<FloatToStr(p1.y)<<endl;

        if(server==sf::IpAddress::None){
            clientStarted=false;
            return;
        }
        // Ask for the server address
        //sf::IpAddress server;
        SCTitle(0 ,"client");

//        do
//        {
//            cout << "Type the address or name of the server to connect to: ";
//            cin  >> server;
//        }
//        while (server == sf::IpAddress::None);
//        }else if(server == sf::IpAddress::None){cout<<"Not valid server address: "<<server<<endl; return;}


        cout<<"Server is "<<server<<":"<<this->port<<endl;


        // Create a socket for communicating with the server
        //sf::UdpSocket socket;

        //sf::Thread listentoserver(&ListenToServer);
        //sf::Thread sendntoserver(&SendToServer, server);

        //HWND consolehwnd=GetConsoleHwnd();
        //bool isConsoleWindowFocussed = (GetConsoleHwnd() == GetForegroundWindow());
        //consolehwnd

        // Send a message to the server

            //while(1){if (socket.send("DIC", 3, server, port) != sf::Socket::Done)
            //    return;                                                                           //for dos
            //cout << "Message sent to the server: \"DIC\"" << endl;}
        //char cic[]="cic";
        string cic="cic";

        //if (net.send(cic,  sizeof(cic), server, this->port) != sf::Socket::Done)
        if (net.send(cic.c_str(),  cic.size() + 1, server, port) != sf::Socket::Done){
            clientStarted=false;
            return;
        }
        i++;
        if(isDebug) cout << i << "|->" << server << ":"<<port<<"| " << (string)cic << " " << endl;


        char in[128];
        size_t received;
        sf::IpAddress sender;
        unsigned short senderPort;
        if (net.receive(in, sizeof(in), received, sender, senderPort) != sf::Socket::Done){
            clientStarted=false;
            return;
        }

        string temp=in;

        i++;
        if(isDebug) cout << i << "|in|" << sender << ":"<<senderPort<<"| " << temp << " " << endl;

        if(temp=="ok pe") {ID="pe";}//cout<<ID<<" "<<floatToStr(p1.x)<<" "<<floatToStr(p1.y)<<endl;}
        if(temp=="ok vt") {ID="vt";}//cout<<ID<<" "<<floatToStr(p1.x)<<" "<<floatToStr(p1.y)<<endl;}

        if(temp=="ok pe" || temp=="ok vt"){
                if(net.receive(in, sizeof(in), received, sender, senderPort) != sf::Socket::Done){
                    clientStarted=false;
                    return;
                }
                temp=in;
                getPlayerData(temp, p2, isIdle2, isBack2, dir2, speed2, CurrentFrame2);
                //p2.x=GetXCordFS(temp); p2.y=GetYCordFS(temp);

         }else getPlayerData(temp, p2, isIdle2, isBack2, dir2, speed2, CurrentFrame2);

        i++;
        if(isDebug) cout << i << "|in|" << sender << ":"<<senderPort<<"| " << temp << " " << endl;

        while(!isClose){// ListenToServer(); //listentoserver.launch();
        //if(isConsoleWindowFocussed && sf::Keyboard::isKeyPressed(sf::Keyboard::Slash)){ //SendToServer(server); //sendntoserver.launch();
        //    unsigned short port=704;
        //    sf::UdpSocket socket;

            //char out[128];
            string answer="";
            //cout<<"Your mesage: ";
            //getch();
            //gets(out); answer=out;

            ///Here been send code///

            char in[128];
            std::size_t received;
            sf::IpAddress sender;
            unsigned short senderPort;
            //if (net.receive(in, sizeof(in), received, sender, senderPort) != sf::Socket::Done) return;
            net.receive(in, sizeof(in), received, sender, senderPort);
            i++;
            if(isDebug) cout << i << "|in|" << sender << ":"<<senderPort<<"| " << in << " " << endl;

            temp=in;
            //if(GetPIDfromC(temp)==ID){
                    getPlayerData(temp, p2, isIdle2, isBack2, dir2, speed2, CurrentFrame2);
                    //cout<<"CLIENT "<<isIdle2<<" "<<isBack2<<" "<<dir2<<" "<<speed2<<" "<<CurrentFrame2<<" "<<p2.x<<" "<<p2.y<<endl;
            //p2.x=GetXCordFS(temp); p2.y=GetYCordFS(temp);}
        //}
        }


        ///disconnecting from server

        if(ID!=""){
        string answer="bye "+ID;
        if (net.send(answer.c_str(),  answer.size() + 1, server, this->port) != sf::Socket::Done){
            clientStarted=false;
            return;
        }
        i++;
        if(isDebug) cout << i << "|->" << server << ":"<<port<<"| " << (string)cic << " " << endl;
        }

        isClose=false;
        clientStarted=false;

        //ListenToServer();
        //SendToServer(server);
        //ListenToServer();

        /**const char out[] = "Hi, I'm a client";
        if (socket.send(out, sizeof(out), server, port) != sf::Socket::Done)
        return;
        std::cout << "Message sent to the server: \"" << out << "\"" << std::endl;

        // Receive an answer from anyone (but most likely from the server)
        char in[128];
        std::size_t received;
        sf::IpAddress sender;
        unsigned short senderPort;
        if (socket.receive(in, sizeof(in), received, sender, senderPort) != sf::Socket::Done)
            {return; cout<<"returned"<<endl;}
        system("mshta javascript:alert(\"Message\n\nMultiple\nLines\ntoo!\");close();");
        cout << "Message received from " << sender << ": \"" << in << "\"" << endl;*/

    }

    void Net::ListenToServer(){

        //sf::UdpSocket socket;
        // Receive an answer from anyone (but most likely from the server)
        char in[128];
        std::size_t received;
        sf::IpAddress sender;
        unsigned short senderPort;
        if (net.receive(in, sizeof(in), received, sender, senderPort) != sf::Socket::Done)
            {return; cout<<"returned"<<endl;}
        system("mshta javascript:alert(\"Message\n\nMultiple\nLines\ntoo!\");close();");
        cout << "Message received from " << sender << ": \"" << in << "\"" << endl;
    }

    bool Net::SendToServer(sf::Vector2f& p, int& isIdle, int& isBack, int& dir, float& speed, int& CurrentFrame){

        if(ID=="") return false;

        p1=p; isIdle1=isIdle; isBack1=isBack; dir1=dir; speed1=speed; CurrentFrame1=CurrentFrame;

        if(oldcord1!=p1){

        string answer="";
        answer=ID+" "/*+FloatToStr(p.x)+" "+FloatToStr(p.y)+" "*/+IntToString(isIdle)+" "+IntToString(isBack)+" "+IntToString(dir)+" "+FloatToStr(speed)+" "+IntToString(CurrentFrame)+" "+FloatToStr(p1.x)+" "+FloatToStr(p1.y);
        //cout<<answer<<"|"<<floatToStr(p1.x)<<" "<<floatToStr(p1.y)<<endl;

        //if (net.send(answer.c_str(),  answer.size() + 1, server, this->port) != sf::Socket::Done)
        //    return false;
        net.send(answer.c_str(),  answer.size() + 1, server, this->port);
        i++;

        mutex.lock();

        if(isDebug) cout << i << "|out|" << server << ":"<<port<<"| " << answer << " " << endl;

        mutex.unlock();

        oldcord1=p1;

        return true;
        }else{ string answer=ID+" "/*+FloatToStr(p.x)+" "+FloatToStr(p.y)+" "*/+IntToString(isIdle)+" "+IntToString(isBack)+" "+IntToString(dir)+" "+FloatToStr(speed)+" "+IntToString(CurrentFrame)+" "+FloatToStr(p1.x)+" "+FloatToStr(p1.y);
                net.send(answer.c_str(),  answer.size() + 1, server, this->port);}

        oldcord1=p1;

        return true;

        /*//while(1){
        unsigned short port=704;
        //sf::UdpSocket socket;
            char out[128];
            cout<<"Your mesage: ";
            getch();
            gets(out);

            if (net.send(out, sizeof(out), server, port) != sf::Socket::Done)
                return;
            cout << "Message sent to the server: \"" << out << "\"" << endl;//}*/
    }

    bool Net::SendToClient(){

        string answer="";
        ///unsigned short senderPort;

        if(ipp1!=sf::IpAddress::None ){ //|| ipp1==sf::IpAddress::Any
            answer="ok pe "+FloatToStr(p2.x)+" "+FloatToStr(p2.y);
                ///if(net.send(answer.c_str(),  answer.size() + 1, ipp1, senderPort) != sf::Socket::Done) return false; //!= sf::Socket::Done
            //answer="";
            i++;
            ///cout << i << "|out|" << ipp1 << ":"<<senderPort<<"| " << answer << " " << endl;
        }

        if(ipp2!=sf::IpAddress::None ){
            answer="ok vt "+FloatToStr(p1.x)+" "+FloatToStr(p1.y);
                ///if(net.send(answer.c_str(),  answer.size() + 1, ipp2, senderPort) != sf::Socket::Done) return false; //!= sf::Socket::Done
            //answer="";
            i++;
            ///cout << i << "|out|" << ipp2 << ":"<<senderPort<<"| " << answer << " " << endl;
        }

        return true;

    }

    sf::Vector2f Net::getPPOS(){
        //cout<<"checked"<<endl;
        return p2;
    }

    void Net::getVPData(sf::Vector2f& p, bool& isIdle, int& isBack, int& dir, float& speed, int& CurrentFrame){
        bool tru=true, fals=false;
        p.x=p2.x; p.y=p2.y; if(isIdle2) isIdle=tru; if(!isIdle2) isIdle=fals; isBack=isBack2; dir=dir2; speed=speed2; CurrentFrame=CurrentFrame2;
    }

    void Net::setPPOS(sf::Vector2f vector){
        p1=vector;
    }

    void Net::stopUdpClient(){
        isClose=true;
    }

    string Net::getID(){
        return ID;
    }

    string Net::getPStats(int player){
        string stats;
        //stats="Player: "+IntToString(player)+"\n255.255.255.255:65536\nno stats";
        stats="Player: "+IntToString(player)+"\n";
        switch(player){
            case 1:{
                    if(player==1 && ipp1!=sf::IpAddress::None) stats+=ipp1.toString()+":"+IntToString(ipport1)+"\n"+FloatToStr(p1.x)+"x"+FloatToStr(p1.y); else{ stats+="not 1 conected\n";  }
                   break;
                   };
            case 2:{
                    if(player==2 && ipp2!=sf::IpAddress::None) stats+=ipp2.toString()+":"+IntToString(ipport2)+"\n"+FloatToStr(p2.x)+"x"+FloatToStr(p2.y); else{ stats+="not 2 conected\n";  }
                   break;
                   };
        }

        return stats;
    }

    sf::IpAddress Net::getIPAdress(){
        return server;
    }

    bool Net::getClientStatus(){
        return clientStarted;
    }
