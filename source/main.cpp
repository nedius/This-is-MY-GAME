
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include "include/header.h"
#include "src/holo.cpp"

//Net net;


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
    Net net;

    SCTitle(0 ,"null");
    system( "color 0a" );


//    sf::Clock someclock;
//    float sometime=0, cursorio=0;
//    int numerio=0;
//
//    for(int i=0; i<500;i++){
//        sometime = someclock.restart().asMicroseconds();
//        sometime = sometime/3000;
//        cursorio+=0.01*sometime;
//        //srand(cursorio*numerio);
//        numerio=rand() % 40;
//        cout<<numerio<<endl;
//    }
//    system("pause");

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

    sf::RenderWindow window;

    Button exitb(window, 100, 50);

    Core core(net, window);

    int EXIT_CODE;

    //INIT(window);
    core.INTRO();
    core.menu();
    EXIT_CODE=core.run();
    core.save();

    net.stopUdpClient();

    return EXIT_CODE;
}
