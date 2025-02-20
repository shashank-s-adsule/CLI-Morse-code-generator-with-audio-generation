#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>

// Maps for Morse->char & char->Morse
std::unordered_map<char,std::string> char2morse ={
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
std::unordered_map<std::string,char> morse2char={
    {".-", 'a'}, {"-...", 'b'}, {"-.-.", 'c'}, {"-..", 'd'}, {".", 'e'},{"..-.", 'f'}, {"--.", 'g'}, {"....", 'h'}, {"..", 'i'}, {".---", 'j'},
    {"-.-", 'k'}, {".-..", 'l'}, {"--", 'm'}, {"-.", 'n'}, {"---", 'o'},{".--.", 'p'}, {"--.-", 'q'}, {".-.", 'r'}, {"...", 's'}, {"-", 't'},
    {"..-", 'u'}, {"...-", 'v'}, {".--", 'w'}, {"-..-", 'x'}, {"-.--", 'y'},{"--..", 'z'},
    {".----", '1'}, {"..---", '2'}, {"...--", '3'}, {"....-", '4'},{".....", '5'}, {"-....", '6'}, {"--...", '7'}, {"---..", '8'},{"----.", '9'}, {"-----", '0'},
    {".-.-.-", '.'}, {"--..--", ','}, {"..--..", '?'}, {".----.", '\''},{"-.-.--", '!'}, {"-..-.", '/'}, {"-.--.", '('}, {"-.--.-", ')'},
    {".-...", '&'}, {"---...", ':'}, {"-.-.-.", ';'}, {"-...-", '='},{".-.-.", '+'}, {"-....-", '-'}, {"..--.-", '_'}, {".-..-.", '"'},
    {"...-..-", '$'}, {".--.-.", '@'},
    {".......", ' '},{"//",'\n'}
};

// string to vector function
void str2vec(std::string &STR,std::vector<std::string> &DATA)
{
    STR+=" ";
    std::string temp="";
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

// to check if string is morse or not
bool is_morse(std::string &b)
{
    return morse2char.find(b)!=morse2char.end();
}

// to get input from txt file
void file_input(std::string &FILE_PATH,std::vector<std::string> &DATA)
{
    std::ifstream file(FILE_PATH);
    std::string STR="";
    if(file.good())
    {
        while(file.good())
        {
            std::getline(file,STR);
            str2vec(STR,DATA);
        }
        file.close();
    }
    else
    {
        std::cerr<<"\u001b[1;34m[\u001b[1;31mERROR\u001b[1;34m]:\u001b[0m FILE NOT FOUND\n";
        exit(0);
    }
}