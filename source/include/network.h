#ifndef NETWORK_H_INCLUDED
#define NETWORK_H_INCLUDED

using namespace std;

    class Net{
        private:
            sf::UdpSocket net;
            sf::IpAddress server;
            unsigned short port = 704;
            sf::IpAddress ipp1=sf::IpAddress::None;
            sf::IpAddress ipp2=sf::IpAddress::None;
            unsigned short ipport1=0, ipport2=0;

            sf::Vector2f p1, oldcord1;
            int isBack1=1, dir1=1, isIdle1=1;
            float speed1=0;
            int CurrentFrame1=0;

            sf::Vector2f p2, oldcord2;
            int isBack2=1, dir2=1, isIdle2=1;
            float speed2=0;
            int CurrentFrame2=0;

            string ID1="pe", ID2="vt", ID;
            bool isClose=false;
            bool isDebug=false;
            int i=0;
            sf::Mutex mutex;
            //sf::Thread thread(this->SendToClient);
            sf::RenderWindow window;

            bool clientStarted=false;



        public:
            Net();
            //~Net();
            void setIPadress(sf::IpAddress);
            bool runUdpServer();
            //void startServerUI();
            void runUdpClient();
            void ListenToServer();
            bool SendToServer(sf::Vector2f& p, int& isIdle, int& isBack, int& dir, float& speed, int& CurrentFrame);
            bool SendToClient();
            sf::Vector2f getPPOS();
            void setPPOS(sf::Vector2f);
            void getVPData(sf::Vector2f& p, bool& isIdle, int& isBack, int& dir, float& speed, int& CurrentFrame);
            void stopUdpClient();
            string getID();
            string getPStats(int);
            sf::IpAddress getIPAdress();
            bool getClientStatus();

    };


#endif // NETWORK_H_INCLUDED
