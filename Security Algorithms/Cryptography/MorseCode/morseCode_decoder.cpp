//C++ implemention of morse code decoding
#include <iostream>
#include<string>
#include <iomanip>
#include <map> //For map data structure
using namespace std;

//function for creating map structure
map<string,string> createMap()
{
    // Decalaring map structure and Defination of map
    map<string, string> decrypt;
    decrypt[".-"] = "A";
    decrypt["-..."] = "B";
    decrypt["-.-."] = "C";
    decrypt["-.."] = "D";
    decrypt["."] = "E";
    decrypt["..-."] = "F";
    decrypt["--."] = "G";
    decrypt["...."] = "H";
    decrypt[".."] = "I";
    decrypt[".---"] = "J";
    decrypt["-.-"] = "K";
    decrypt[".-.."] = "L";
    decrypt["--"] = "M";
    decrypt["-."] = "N";
    decrypt["---"] = "O";
    decrypt[".--."] = "P";
    decrypt["--.-"] = "Q";
    decrypt[".-."] = "R";
    decrypt["..."] = "S";
    decrypt["-"] = "T";
    decrypt["..-"] = "U";
    decrypt["...-"] = "V";
    decrypt[".--"] = "W";
    decrypt["-..-"] = "X";
    decrypt["-.--"] = "Y";
    decrypt["--.."] = "Z";
    decrypt[".----"] = "1";
    decrypt["..---"] = "2";
    decrypt["...--"] = "3";
    decrypt["....-"] = "4";
    decrypt["....."] = "5";
    decrypt["-...."] = "6";
    decrypt["--..."] = "7";
    decrypt["---.."] = "8";
    decrypt["---."] = "9";
    decrypt["-----"] = "0";
    return decrypt;
}

map<string, string> decrypt=createMap();
// decryption Function
void decryption(string msg)
{
    string plain = "", tempPlain;
    for (int i = 0; i < msg.size(); i++)
    {
        if (msg[i] != ' ' &&  msg[i] != '\t' && msg[i] != '\n')
        {
            tempPlain.append(1, msg[i]);
        }
        if ( msg[i] == ' ' || i==msg.size()-1)
        {
            plain=plain +decrypt[tempPlain];
            tempPlain="";
        }
        if(msg[i] == '\t' || msg[i] =='\n')
        {
            plain=plain +decrypt[tempPlain];
            tempPlain="";
            plain += " ";

        }
    }
    cout <<"Decrypted Code=:"<< plain<<endl;
}
//Driver program
int main()
{
    string input = "";
    char c;
    cout<<"Keep spacing as follows and end morse code 'q' character.\n";
    cout<<"----------------------------------------------------------------\n";
    cout<<setw(20)<<" |"<<setw(20)<<" Morse Spacing |"<<setw(25)<<"This Program Spacing |\n";
        cout<<"----------------------------------------------------------------\n";

    cout<<setw(20)<<"Letter to Letter |"<<setw(20)<<"Three dits |"<<setw(25)<<"Single Space |\n";
    cout<<setw(20)<<"Word to Word |"<<setw(20)<<"Five dits |"<<setw(25)<<"Tab(key) |\n";
    cout<<"----------------------------------------------------------------\n";

    cout<<"Enter Morse Code: ";
    while (cin.get(c) && c != 'q')
    {
        input.append(1, c);
    }
    cout << "\nInput=" << input << endl;
    //Calling Function
    decryption(input);
    return 0;
}
