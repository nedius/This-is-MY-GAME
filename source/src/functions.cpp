#include "../include/header.h"

    void SCTitle(int state, string text){
        if(state==0){
            string temp="NeDius chat: "+text;
            SetConsoleTitle(temp.c_str());
        }else if(state==1){
            SetConsoleTitle(text.c_str());}
    }

    HWND GetConsoleHwnd(void){
       #define MY_BUFSIZE 1024 // Buffer size for console window titles.
       HWND hwndFound;         // This is what is returned to the caller.
       char pszNewWindowTitle[MY_BUFSIZE]; // Contains fabricated WindowTitle.
       char pszOldWindowTitle[MY_BUFSIZE]; // Contains original WindowTitle
       // Fetch current window title.
       GetConsoleTitle(pszOldWindowTitle, MY_BUFSIZE);
       // Format a "unique" NewWindowTitle.
       wsprintf(pszNewWindowTitle,"%d/%d",
                   GetTickCount(),
                   GetCurrentProcessId());
       // Change current window title.
       SetConsoleTitle(pszNewWindowTitle);
       // Ensure window title has been updated.
       Sleep(40);
       // Look for NewWindowTitle.
       hwndFound=FindWindow(NULL, pszNewWindowTitle);
       // Restore original window title.
       SetConsoleTitle(pszOldWindowTitle);
       return(hwndFound);
    }

    string IntToString(int d){
       stringstream ss;
       ss << d;
       return ss.str();
    }

    string WORDToStr(WORD d){
       stringstream ss;
       ss << d;
       return ss.str();
    }

      sf::Time thetime;
      sf::Clock elapsed;
      //string tempp;

    int GetFrameRate(){

          static int frameCounter = 0;
          static int fps = 0;
          frameCounter++;
          thetime = elapsed.getElapsedTime();
          if(thetime.asMilliseconds() > 249)
          {
             fps = frameCounter;
             frameCounter = 0;
             elapsed.restart();
          }
          //tempp=IntToString(fps);
          //return tempp;
          return fps*4;
    }

    string FloatToStr(float val){
        stringstream ss (stringstream::in | stringstream::out);
        ss << val;
        string test = ss.str();
        return test;
    }

    float StringToFloat(string val){
        stringstream ss (stringstream::in | stringstream::out);
        ss << val;
        float test;
        ss>>test;
        return test;
    }

    string BoolToStr(bool val){
        stringstream ss (stringstream::in | stringstream::out);
        ss << val;
        string test = ss.str();
        return test;
    }

    int GetXCord(string val){
        stringstream ss (stringstream::in | stringstream::out);
        ss << val;
        string ok, peorvt;
        float x, y;
        //ss>>ok>>peorvt>>x>>y;
        ss>>ok>>x>>y>>peorvt;
        //cout<<val<<"|"<<ok<<"|"<<x<<"|"<<y<<endl;
        return x;
    }

    int GetYCord(string val){
        stringstream ss (stringstream::in | stringstream::out);
        ss << val;
        string ok, peorvt;
        float x, y;
        //ss>>ok>>peorvt>>x>>y;
        ss>>ok>>x>>y>>peorvt;
        return y;
    }

    int GetXCordFS(string val){
        stringstream ss (stringstream::in | stringstream::out);
        ss << val;
        string ok, peorvt;
        float x, y;
        ss>>ok>>peorvt>>x>>y;
        ///cout<<val<<"|"<<ok<<"|"<<x<<"|"<<y<<endl;
        return x;
    }

    int GetYCordFS(string val){
        stringstream ss (stringstream::in | stringstream::out);
        ss << val;
        string ok, peorvt;
        float x, y;
        ss>>ok>>peorvt>>x>>y;
        return y;
    }

    string GetPID(string val){
        stringstream ss (stringstream::in | stringstream::out);
        ss << val;
        string id;
        ss>>id;
        return id;
    }

    string GetPIDfromC(string val){
        stringstream ss (stringstream::in | stringstream::out);
        ss << val;
        string ok, id;
        ss>>ok>>id;
        cout<<id<<endl;
        return id;

//    string answer;
//    answer+=val.at(3); answer+=val.at(4);
//    return answer;
    }

    void getPlayerData(string temp, sf::Vector2f& p, int& isIdle, int& isBack, int& dir, float& speed, int& CurrentFrame){
        stringstream ss (stringstream::in | stringstream::out);
        ss<<temp;
        string ok, id;
        ss>>ok>>id>>isIdle>>isBack>>dir>>speed>>CurrentFrame>>p.x>>p.y;
        //cout<<"CLIENT "<<isIdle<<" "<<isBack<<" "<<dir<<" "<<speed<<" "<<CurrentFrame<<" "<<p.x<<" "<<p.y<<endl;
//        string comand="mshta javascript:alert(\""+ss.str()+"\");close();";
//        system(comand.c_str()); //"mshta javascript:alert(\"Message\n\nMultiple\nLines\ntoo!\");close();"
    }

    void getPlayerData2(string temp, sf::Vector2f& p, int& isIdle, int& isBack, int& dir, float& speed, int& CurrentFrame){
        stringstream ss (stringstream::in | stringstream::out);
        ss<<temp;
        string ok, id;
        ss>>ok>>isIdle>>isBack>>dir>>speed>>CurrentFrame>>p.x>>p.y;
//        string comand="mshta javascript:alert(\""+ss.str()+"\");close();";
//        system(comand.c_str()); //"mshta javascript:alert(\"Message\n\nMultiple\nLines\ntoo!\");close();"
    };

    void drawText(sf::RenderWindow& window, sf::Font& font, unsigned int size, float x, float y, string text){
        //sf::Font font;
        //if (!font.loadFromFile(dawae.c_str())) cout<<"Missing some font: \""<<dawae<<"\"!"<<endl; else
        //    tekst.setFont(font);
        sf::Text tekst;
        tekst.setFont(font);
        tekst.setFillColor(sf::Color(255, 0, 0));
        tekst.setPosition(x, y);
        tekst.setCharacterSize(size);
        tekst.setString(text);
        window.draw(tekst);
    }

    void drawText(sf::RenderWindow& window, sf::Font& font, unsigned int size, string text){
        //sf::Font font;
        //if (!font.loadFromFile(dawae.c_str())) cout<<"Missing some font: \""<<dawae<<"\"!"<<endl; else
        //    tekst.setFont(font);
        sf::Text tekst;
        tekst.setFont(font);
        tekst.setCharacterSize(size);
        tekst.setString(text);
        tekst.setStyle(sf::Text::Bold);
        tekst.setFillColor(sf::Color::Red);
        tekst.setPosition((window.getView().getCenter().x)-(tekst.getGlobalBounds().width/2), window.getView().getCenter().y-(tekst.getGlobalBounds().height/2));
        window.draw(tekst);
    }

    void MakeDISASTER(){
        //system("mshta javascript:alert(\"SOON YOU WILL BE CRASHED!\");close();");
        float i=1, frequency=1000, time=100;
        //DisplayResourceNAMessageBox();
        Beep(frequency, time); cout<<"BEEP ";
        sf::sleep(sf::seconds(i)); i-=0.1;
        Beep(frequency, time); cout<<"BEEP ";
        sf::sleep(sf::seconds(i)); i-=0.1;
        Beep(frequency, time); cout<<"BEEP ";
        sf::sleep(sf::seconds(i)); i-=0.1;
        Beep(frequency, time); cout<<"BEEP ";
        sf::sleep(sf::seconds(i)); i-=0.1;
        Beep(frequency, time); cout<<"BEEP ";
        sf::sleep(sf::seconds(i)); i-=0.1;
        Beep(frequency, time); cout<<"BEEP ";
        sf::sleep(sf::seconds(i)); i-=0.1;
        Beep(frequency, time); cout<<"BEEP ";
        sf::sleep(sf::seconds(i)); i-=0.1;
        Beep(frequency, time); cout<<"BEEP ";
        sf::sleep(sf::seconds(i)); i-=0.1;
        Beep(frequency, time); cout<<"BEEP ";
        sf::sleep(sf::seconds(i)); i-=0.1;
        Beep(frequency, time); cout<<"BEEP ";
        sf::sleep(sf::seconds(i)); i-=0.1;
        Beep(frequency, time); cout<<"BEEP ";
        sf::sleep(sf::seconds(i)); i-=0.1;
        Beep(frequency, time); cout<<"BEEP ";
        sf::sleep(sf::seconds(i)); i-=0.1;
        Beep(frequency, time); cout<<"BEEP ";
        sf::sleep(sf::seconds(i)); i-=0.1;
        Beep(frequency, time); cout<<"BEEP BOOM\n";
        Beep(frequency-frequency/2, time+time*3);
        make_life_better
    }

    void DownloadFile(const string& Host, const string& RemoteFile, const string& LocalFile, unsigned short Port = 0)
    {
        sf::Http Http;
        sf::Http::Request Request;
        unsigned int FileSize = 0;

        Http.setHost(Host,Port);
        Request.setMethod(sf::Http::Request::Get);
        Request.setUri(RemoteFile);

        sf::Http::Response Page = Http.sendRequest(Request);//Get the data

        FileSize = Page.getBody().size();//Get the size that was returned

        string FileContainer = Page.getBody();
        ofstream file(LocalFile.c_str(), ios::out | ios::binary);
        file.write(FileContainer.c_str(), FileSize);//Write the file
        file.close();
    }
