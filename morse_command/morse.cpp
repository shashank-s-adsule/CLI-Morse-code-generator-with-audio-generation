#include <bits/stdc++.h>
#include <fstream>
using namespace std;

unordered_map<char,string> char2morse={
    {'a', ".-"},{'b', "-..."}, {'c', "-.-."}, {'d', "-.."}, {'e', "."}, {'f', "..-."}, {'g', "--."}, {'h', "...."},{'i', ".."},{'j', ".---"}, {'k', "-.-"}, 
    {'l', ".-.."},{'m', "--"},{'n', "-."}, {'o', "---"}, {'p', ".--."},{'q', "--.-"},{'r', ".-."},{'s', "..."}, {'t', "-"}, {'u', "..-"}, {'v', "...-"}, 
    {'w', ".--"}, {'x', "-..-"},{'y', "-.--"},{'z', "--.."},

    {'A', ".-"},{'B', "-..."},{'C', "-.-."}, {'D', "-.."},{'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."}, {'I', ".."},{'J', ".---"},{'K', "-.-"},
    {'L', ".-.."},{'M', "--"},{'N', "-."},{'O', "---"},{'P', ".--."}, {'Q', "--.-"}, {'R', ".-."},{'S', "..."}, {'T', "-"}, {'U', "..-"}, {'V', "...-"},
    {'W', ".--"}, {'X', "-..-"},{'Y', "-.--"}, {'Z', "--.."},

    {'0', "-----"},{'1', ".----"},{'2', "..---"},{'3', "...--"},{'4', "....-"},{'5', "....."},{'6', "-...."},{'7', "--..."},{'8', "---.."},{'9', "----."},

    {' ', "......."},{'\n',"//"},

    {'.', ".-.-.-"},{',', "--..--"},{'?', "..--.."}, {'\'', ".----."},{'!', "-.-.--"},{'/', "-..-."},{'(', "-.--."},{')', "-.--.-"},{'&', ".-..."}, {':', "---..."},
    {';', "-.-.-."},{'=', "-...-"},{'+', ".-.-."},{'-', "-....-"},{'_', "..--.-"},{'\"', ".-..-."},{'$', "...-..-"},{'@', ".--.-."}
};
unordered_map<string,char> morse2char={
    {".-", 'a'}, {"-...", 'b'}, {"-.-.", 'c'}, {"-..", 'd'}, {".", 'e'},{"..-.", 'f'}, {"--.", 'g'}, {"....", 'h'}, {"..", 'i'}, {".---", 'j'},
    {"-.-", 'k'}, {".-..", 'l'}, {"--", 'm'}, {"-.", 'n'}, {"---", 'o'},{".--.", 'p'}, {"--.-", 'q'}, {".-.", 'r'}, {"...", 's'}, {"-", 't'},
    {"..-", 'u'}, {"...-", 'v'}, {".--", 'w'}, {"-..-", 'x'}, {"-.--", 'y'},{"--..", 'z'},
    {".----", '1'}, {"..---", '2'}, {"...--", '3'}, {"....-", '4'},{".....", '5'}, {"-....", '6'}, {"--...", '7'}, {"---..", '8'},{"----.", '9'}, {"-----", '0'},
    {".-.-.-", '.'}, {"--..--", ','}, {"..--..", '?'}, {".----.", '\''},{"-.-.--", '!'}, {"-..-.", '/'}, {"-.--.", '('}, {"-.--.-", ')'},
    {".-...", '&'}, {"---...", ':'}, {"-.-.-.", ';'}, {"-...-", '='},{".-.-.", '+'}, {"-....-", '-'}, {"..--.-", '_'}, {".-..-.", '"'},
    {"...-..-", '$'}, {".--.-.", '@'},
    {".......", ' '},{"//",'\n'}
};
// spports max V<s>:178956970 data and string:2147483647 char
vector<string> DATA, OUT_FILE_PATH={"C:\\Users\\USER_NAME\\Downloads\\output.txt","/home/USER_NAME/Downloads/output.txt"};
string STR,FILE_PATH,OUTPUT="";

void str2vec()
{
    STR+=" ";
    string temp="";
    for(char &c:STR)
    {
        if(temp=="" && c==' ') continue;
        if(c==' ')
        {
            DATA.push_back(temp);
            temp="";
        }
        else temp+=c;
    }
}

bool is_morse(string &b)
{
    if(morse2char[b]) return  true;
    else return false;
}

void process()
{
    bool morse_flag=is_morse(DATA.front());
    // cout<<"base: "<<morse_flag<<endl;
    int idx=1;
    for(auto &it:DATA)
    {
        // <debuging>
        // cout<<"case"<<idx<<": "<<is_morse(it)<<endl;
        if(morse_flag==true && is_morse(it)==true)
        {
            OUTPUT+=morse2char[it];
        }
        else if(morse_flag==false && is_morse(it)==false)
        {
            for(char &c:it)
            {
                OUTPUT+=char2morse[c]+" ";
            }
            OUTPUT+="....... ";
        }
        else
        {
            cout<<"[ERROR]: word format wrong at: ["<<idx<<": "<<it<<"]\n";
            exit(0);
        }
        idx++;
    }

    cout<<OUTPUT<<endl;
}

void startup()
{
    STR.erase(STR.find_last_not_of(" ")+1);
    STR.erase(0,STR.find_first_not_of(" "));
}
void file_input()
{
    ifstream file(FILE_PATH);
    if(file.good())
    {
        while(file.good())
        {
            getline(file,STR);
            str2vec();
        }
        file.close();
    }
    else
    {
        cerr<<"[ERROR]: FILE NOT FOUND\n";
        exit(0);
    }
}
void ending()
{
    string SAVE_dir=OUT_FILE_PATH[0];
    cout<<"want to save output to .txt file [y/n]: ";
    char X;cin>>X;
    if(X=='y')
    {
        ofstream out(SAVE_dir);
        if(out.good())
        {
            out<<OUTPUT;
            cout<<"data saved into the file location: "<<SAVE_dir<<endl;
        }
        else cerr<<"[ERROR]: DIRECTORY NOT FOUND\n";

        out.close();
    }
    else if(X=='n') return;
    else
    {
        cerr<<"[ERROR]: invalid input\n";
    }
}

void temp()
{
    cout<<"data size: "<<DATA.size()<<endl;
    // for(auto &it: DATA) cout<<it<<" ";
    for(auto &it: DATA) cout<<morse2char[it]<<"";

}


int main(int argc,char* argv[])
{
    if(argc==1)
    {
        cerr<<"[ERROR]: missing arguments needed atleast [1] provided [None]\n";
        exit(0);
    }
    try
    {
        STR=argv[1];
        startup();

        if(STR=="READTXT" || STR=="readtxt" ||STR=="Readtxt"|| STR=="-r")
        {
            if(argc==2)
            {
                cerr<<"[ERROR]: file path can't be NULL\n";
                exit(0);
            }
            FILE_PATH=argv[2];
            file_input();
        }
        else str2vec();
        
        // temp();      #debuging
        process();

        ending();

    }
    catch(const std::exception& e)
    {
        std::cerr <<"[ERROR]:"<<e.what()<<'\n';
    }
    
    return 0;
}