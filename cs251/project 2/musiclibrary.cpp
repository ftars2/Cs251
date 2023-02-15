//@filename musiclibrary.cpp
/// TODO Update File Header
/// @author Frank Tarshis
/// @date February 14/2023
/// @brief creates a simplistic music library that you can do various actions to manipulate
/// Assignment details and provided code are created and
/// owned by Adam T Koehler, PhD - Copyright 2023.
/// University of Illinois Chicago - CS 251 Spring 2023

#include <iostream>
#include <string>
#include <map>
#include <set>
#include "ctype.h"
#include <sstream>

// INSERTS GIVEN HELPERS CODE BELOW - DO NOT REMOVE
#include "helpers.cpp"
// INSERTS GIVEN HELPERS CODE ABOVE - DO NOT REMOVE

// NOTE TO STUDENTS:
// You may use the functions in the helpers file,
// but you may not modify the file or its contents in any way whatsoever.

// STUDENT CODE MAY GO BELOW THIS LINE

/// @brief contains the info of music libraries
/// album stores the name of the album
/// artist stores a set containing artists of a album
/// song stores a set containing songs of a album
struct musicl{
string album;
set<string> artist;
set<string> song;
};


/// @brief loads in a file containing albums and their associated artists and songs
/// @param loc the name of the file being loaded
/// @param library the container where albums + info are stored
/// @return returns the library with/without additional albums
map<string,musicl> load(string loc, map<string, musicl> library){
musicl talbum;//temp musicl struct for adding to map of musicl structs
string temp;
string tempa="";
bool albumred=false;
fstream s;

 if(loc==("nothing")||loc==("")){
 s.open("musicdatabase.txt");
 }
else{
 s.open(loc);
 if(!s.is_open()){
    cout<<"Error: Could not open music library file - "<<loc<<endl;
return library;
 }
 }


while(getline(s,temp)){
if(!albumred){//if the albums name hasnt been read in yet
 talbum.album=(temp);
 albumred=true;
 tempa=temp;//used to see when album is read a second time
 }
 else if((albumred) && (temp==tempa)){
     albumred=false;
     library.insert({tempa,talbum});// inserts the albums name as the key with the musicl struct 
     talbum.artist.clear();//clears temp musicl
    talbum.song.clear();
 }
 else if(!isdigit(temp.at(0))){//if first char of temp is not a number then it is a artust 
talbum.artist.insert(temp);
 }

 else if(isdigit(temp.at(0))){//if first char is a number then it is a song
    talbum.song.insert(temp);
}
 }
s.close();
    return library;
}


/// @brief used to output stats and optionally names of the albums that are loaded
/// @param extra  used to call for printing out all albums loaded in 
/// @param library holds all album information 
void stats (string extra, map <string, musicl> library){
cout<<"Overall Music Library Stats"<<endl<<"===========================\nTotal Records: ";
cout<<library.size()<<endl;
set <string> art;
int ssize=0;

for(const auto name: library){
art.insert(name.second.artist.begin(),name.second.artist.end());
ssize+=name.second.song.size();
}
cout<<"Total Unique Artists: "<<art.size()<<endl;
cout<<"Total Songs: "<<ssize<<endl<<endl;

if(extra=="-d"){
    cout<<"Your Current Music Library Includes\n===================================\n";
    for(const auto name: library){
    cout<<name.second.album<<endl;
    for(const auto person : name.second.artist){
        cout<<" "<<person<<endl;
        
    }
    for(const auto song: name.second.song){
        cout<<"   "<<song<<endl;
    }
    }
cout<<endl;
}
}
/// @brief clears the music library of all albums
/// @param library contains the albums loaded in
/// @return returns a empty music library
map <string, musicl> clear(map<string,musicl> library){
    library.clear();
return library;
}

///@brief searches for if a string is contained in a albums name/authors/songs
///@param t determines the type of search between album song or artist
///@param word the search word
///@param set1 the current values that previous words have matched
///@param library library of albums
set <string> match(string t,string word, set<string> set1, map<string,musicl> library){
    set <string> set2={};
    set <string> set3={};
    string temp;
    bool minus=false;//true if search word contains '-'
    bool plus=false;//true if search word contains '+'
    if(t=="album"){
        for(const auto place : library){
            temp=place.first;//album name
            tolower(temp);
if ( word.at(0) == '-') {
    minus = true; 
    word.erase(0, 1);//gets rid of + or - symbol if in string
} else if ( word.at(0) == '+') {
    plus = true;
    word.erase(0, 1);
}

            if(100>temp.find(word)){
                set2.insert(place.first);//inserts album name into set of string
            }
        }
    }
    if(t=="artist"){
        for(const auto place : library){
            for(const auto person: place.second.artist){//goes through each artists name for every album
            temp=person;
            tolower(temp);
if ( word.at(0) == '-') {
    minus = true; 
    word.erase(0, 1);//gets rid of + or - symbol if in string
} else if ( word.at(0) == '+') {
    plus = true;
    word.erase(0, 1);
}
                           
                        
if(100>temp.find(word)){
     set2.insert(place.first);//inserts album name into set of string
 }
 }
        }
    }
    if(t=="song"){
        for(const auto place : library){
            for(const auto person: place.second.song){
            temp=person;
            tolower(temp);
if ( word.at(0) == '-') {
    minus = true; 
    word.erase(0, 1);//gets rid of + or - symbol if in string
} else if ( word.at(0) == '+') {
    plus = true;
    word.erase(0, 1);
}
            if(100>temp.find(word)){
                set2.insert(place.first);//inserts album name into set of string
            }}} }    
     if(plus){
        set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(),inserter(set3, set3.begin()));
    }
    else if(minus){
        set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(),inserter(set3, set3.begin()));
    }
    else if(!minus && !plus){
        set_union(set1.begin(), set1.end(), set2.begin(), set2.end(),inserter(set3, set3.begin()));
    }
   
    
    return set3;
}
/// @brief function called when searching for a song/artist/album
/// @param com contains the type and words to search
/// @param library album information
void search(string com, map <string,musicl> library ){
string type;
string temp;
string temp1;
set <string> nset={};
splitFirstWord(com,type,temp);
if(temp==""){
cout<<"Error: Search terms cannot be empty.\nNo results found.\n\n";
return;
}
stringstream s (temp);
while(s>>temp1){
    tolower(temp1);
if(temp1==""){
break;
}
nset=match(type,temp1,nset,library);
    if(temp1.empty()){
        break;
    }
}
cout<<"Your search results exist in the following albums: "<<endl;
                for (const auto lol : nset){
                    cout<<lol<<endl;
                }
                cout<<endl;

}
/// @brief creates or opens a file then prints out all album information
/// @param library library of albums information
/// @param remains optional location of where to export
void exports(map <string, musicl> library, string remains){
ofstream output;
bool notfirst=false;//used to fomat file correctly
if(remains==""){
 output.open("musicdatabase.txt");
}
else{
     output.open(remains);
}
for(const auto name: library){
    if(notfirst){
        output<<endl;
    }
    output<<name.second.album<<endl;
    for(const auto person : name.second.artist){
        output<<person<<endl;
        
    }
    for(const auto song: name.second.song){
        output<<song<<endl;
    }
    output<<name.first;
    notfirst=true;
    }
output<<endl;
output.close();
return;
}

int main()
{
    string userEntry;
    string command, remains="nothing";
    map<string, musicl> lib;//map with the key being a albums name, and the key accesssing all other information
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
            lib=clear(lib);
            
        }
        else if (command == "export")
        {
            exports(lib, remains);
        
        }
        else if (command == "load")
        {
         lib=load(remains, lib);
        }
        else if (command == "stats")
        {
            stats(remains,lib);
        }          
        else if (command == "search")
        {
         search(remains,lib);

        }

    }while(command != "exit");    

    cout << "Thank you for using the Music Library App" << endl;
    return 0;
}
