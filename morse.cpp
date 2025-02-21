#include <bits/stdc++.h>
#include <fstream>

// preprocessing and utils function  
#include "./utils.h"
// audio genration header
#include "./audio_genrator.h"

using namespace std;

// to get username for specifiic OS
#ifdef __WIN32
    #define USERNAME getenv("USERNAME")
#elif __linux__
    #define USERNAME getenv("USER")
#endif

vector<string> DATA;
string STR,FILE_PATH,OUTPUT="",OUT_FILE_PATH;
bool MORSE_FLAG;

void process()
{
    MORSE_FLAG=is_morse(DATA.front());
    int idx=0;
    for(auto &it:DATA)
    {
        if(MORSE_FLAG==true && is_morse(it)==true)
        {
            OUTPUT+=morse2char[it];
        }
        else if(MORSE_FLAG==false && is_morse(it)==false)
        {
            for(char &c:it)
            {
                OUTPUT+=char2morse[c]+" ";
            }
            if(idx!=DATA.size()-1) OUTPUT+="....... ";
        }
        else
        {
            cout<<"\u001b[1;34m[\u001b[1;31mERROR\u001b[1;34m]:\u001b[0m word format wrong at: ["<<idx<<": "<<it<<"]\n";
            exit(0);
        }
        idx++;
    }
    cout<<OUTPUT<<endl;
}

void ending()
{
    string SAVE_text_dir, SAVE_audio_dir;
    cout<<"\u001b[1;32mWant to save output to .txt file [y/n]: \u001b[0m";
    char X;cin>>X;
    if(X=='y')
    {
        // to create folder 
        #ifdef __WIN32
            OUT_FILE_PATH="C:\\Users\\"+((string)USERNAME)+"\\Downloads\\Morse";
            string command="mkdir "+OUT_FILE_PATH;
            system(command.c_str());
            
            SAVE_text_dir=OUT_FILE_PATH+"\\output.txt";             //for text output
            SAVE_audio_dir=OUT_FILE_PATH+"\\morse.wav";             //for audio output
        #elif __linux__
            OUT_FILE_PATH="/home/"+(string)USERNAME+"/Downloads/";
            string command="mkdir "+OUT_FILE_PATH;
            system(command.c_str());
            
            SAVE_text_dir=OUT_FILE_PATH+"output.txt";               //for text output
            SAVE_audio_dir=OUT_FILE_PATH+"morse.wav";               //for audio output
        #endif

        ofstream out(SAVE_text_dir);
        if(out.good())
        {
            out<<OUTPUT;
            cout<<"data saved into the file location: \u001b[1;33m"<<SAVE_text_dir<<"\u001b[0m"<<endl;
        }
        else cerr<<"\u001b[1;34m[\u001b[1;31mERROR\u001b[1;34m]:\u001b[0m DIRECTORY NOT FOUND\n";
        
        out.close();
        
        if(!MORSE_FLAG)
        {
            cout<<"\u001b[1;32mWant to save output to .wav file [y/n]: \u001b[0m";
            char Y;cin>>Y;
            if(Y=='y')
            {
                vector<string> temp;
                str2vec(OUTPUT,temp);

                // convert morse audio
                morse2audio(temp,SAVE_audio_dir);
                
                cout<<"data saved into the file location: \u001b[1;33m"<<SAVE_audio_dir<<"\u001b[0m"<<endl;
            }
            else if(Y=='n') return;
            else cerr<<"\u001b[1;34m[\u001b[1;31mERROR\u001b[1;34m]:\u001b[0m invalid input\n";    
        }
    }
    else if(X=='n') return;
    else
    {
        cerr<<"\u001b[1;34m[\u001b[1;31mERROR\u001b[1;34m]:\u001b[0m invalid input\n";
    }
}


int main(int argc,char* argv[])
{
    if(argc==1)
    {
        cerr<<"\u001b[1;34m[\u001b[1;31mERROR\u001b[1;34m]:\u001b[0m missing arguments needed atleast [1] provided [None]\n";
        exit(0);
    }
    try
    {
        STR=argv[1];

        if(STR=="READTXT" || STR=="readtxt" ||STR=="Readtxt"|| STR=="-r")
        {
            if(argc==2)
            {
                cerr<<"\u001b[1;34m[\u001b[1;31mERROR\u001b[1;34m]:\u001b[0m file path can't be NULL\n";
                exit(0);
            }
            FILE_PATH=argv[2];
            file_input(FILE_PATH,DATA);
        }
        else str2vec(STR,DATA);
        
        process();      //main process which convertes text->Morse (viceversa)

        ending();

    }
    catch(const std::exception& e)
    {
        std::cerr <<"\u001b[1;34m[\u001b[1;31mERROR\u001b[1;34m]:\u001b[0m"<<e.what()<<'\n';
    }
    
    return 0;
}