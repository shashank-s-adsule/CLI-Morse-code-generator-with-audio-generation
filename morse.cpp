#include <bits/stdc++.h>
#include <fstream>

// for utils and audio_gen files
#include "./utils.h"

using namespace std;

// spports max V<s>:178956970 data and string:2147483647 char
string USERNAME="shashank";
// #ifdef __WIN32
//     USERNAME=getenv("USERNAME");
// #elif __linux__
//     USERNAME=getenv("USER");
// #endif
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
    string SAVE_dir;
    cout<<"\u001b[1;32mWant to save output to .txt file [y/n]: \u001b[0m";
    char X;cin>>X;
    if(X=='y')
    {
        // to create folder 
        #ifdef __WIN32
            OUT_FILE_PATH="C:\\Users\\"+USERNAME+"\\Downloads\\Morse";
            string command="mkdir "+OUT_FILE_PATH;
            system(command.c_str());
            
            SAVE_dir=OUT_FILE_PATH+"\\output.txt";
        #elif __linux__
            OUT_FILE_PATH="/home/"+USERNAME+"/Downloads/"
            string command="mkdir "+OUT_FILE_PATH;
            system(command.c_str());

            SAVE_dir=OUT_FILE_PATH+"output.txt";
        #endif

        ofstream out(SAVE_dir);
        if(out.good())
        {
            out<<OUTPUT;
            cout<<"data saved into the file location: \u001b[1;33m"<<SAVE_dir<<"\u001b[0m"<<endl;
        }
        else cerr<<"\u001b[1;34m[\u001b[1;31mERROR\u001b[1;34m]:\u001b[0m DIRECTORY NOT FOUND\n";

        out.close();

        if(!MORSE_FLAG)
        {
            cout<<"\u001b[1;32mWant to save output to .wav file [y/n]: \u001b[0m";
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
        
        process();

        ending();

    }
    catch(const std::exception& e)
    {
        std::cerr <<"\u001b[1;34m[\u001b[1;31mERROR\u001b[1;34m]:\u001b[0m"<<e.what()<<'\n';
    }
    
    return 0;
}