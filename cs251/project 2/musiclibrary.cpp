/// TODO Update File Header
///
/// Assignment details and provided code are created and
/// owned by Adam T Koehler, PhD - Copyright 2023.
/// University of Illinois Chicago - CS 251 Spring 2023

#include <iostream>
#include <string>
#include <map>
#include <set>
#include "ctype.h"
// INSERTS GIVEN HELPERS CODE BELOW - DO NOT REMOVE
#include "helpers.cpp"
// INSERTS GIVEN HELPERS CODE ABOVE - DO NOT REMOVE

//
// NOTE TO STUDENTS:
// You may use the functions in the helpers file,
// but you may not modify the file or its contents in any way whatsoever.
//

//
// STUDENT CODE MAY GO BELOW THIS LINE
//



//contains the info of music libraries
struct musicl{
set<string> album;
map<string,string> artist;
map<string,set<string>> song;
};

musicl load(string loc, musicl library){
fstream s(loc);
string temp;
string tempa;
string tempr;
string temps;
bool albumred=false;
bool artred=false;
while(getline(s,temp)){
if(!albumred){
library.album.insert(temp);
albumred=true;
}
else if(!isdigit(temp.at(0))){

    library.artist.insert({tempa,temp});
}
//else if(isdigit(temp.at(0))){
//library.song.insert({tempa,temp});
//}
else if(albumred && temp==tempa){
    albumred=false;

    
    continue;
}
/*
*/
}
    return library;
}
int main()
{
    string userEntry;
    string command, remains="nothing";
    struct musicl lib;
    // TODO: Declare any necessary variables for the music libary

    // Display welcome message once per program execution
    cout << "Welcome to the Music Library App" << endl;
    cout << "--------------------------------" << endl;

    // Stay in menu until exit command
    do
    {
        cout << endl;
        cout << "Enter a command (help for help): " << endl;
        getline(cin, userEntry);
        cout << endl;

        // Split the user entry into two pieces
        splitFirstWord(userEntry, command, remains);
        tolower(command);

        // take an action, one per iteration, based on the command
        if (command == "help")
        {
            helpCommand();
        }
        else if (command == "clear")
        {
            // TODO
        }
        else if (command == "export")
        {
            // TODO
        }
        else if (command == "load")
        {
            lib=load(remains, lib);
        }
        else if (command == "stats")
        {
            // TODO
        }          
        else if (command == "search")
        {
            // TODO
        }

    }while(command != "exit");    

    cout << "Thank you for using the Music Library App" << endl;
    return 0;
}
