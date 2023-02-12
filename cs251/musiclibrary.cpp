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
map<string,set<string>> artist;
map<string,set<string>> song;
};

musicl load(string loc, map<string, musicl> library){
// musicl talbum;
// string temp;
// string tempa="";
// bool albumred=false;
// //bool artred=false;
// fstream s;

// if(loc==("nothing")||loc==("")){
// s.open("musicdatabase.txt");
// //cout<<loc;
// }
// else{
//  s.open(loc);
//  if(!s.is_open()){
//     cout<<"Error: Could not open music library file - "<<loc<<endl;
//  }}
// return library;
// }}

// while(getline(s,temp)){
// if(!albumred){
// library.album.insert(temp);
// albumred=true;
// tempa=temp;
// }
// else if(!isdigit(temp.at(0))){
//     // library.artist.insert({tempa,temp});
// auto it = library.artist.find(tempa);
//     if(it==library.artist.end()){
//         set<string> tset = {temp};
//         library.artist[tempa] = tset;
//     }
//     else{
//         set<string>& artistset = library.song[tempa];
//         artistset.insert(temp);
//     }

// }

// else if(isdigit(temp.at(0))){
//     auto it = library.song.find(tempa);
//     if(it==library.song.end()){
//         set<string> tset = {temp};
//         library.song[tempa] = tset;
//     }
//     else{
//         set<string>& songset = library.song[tempa];
//         songset.insert(temp);
//     }
// }
// else if(albumred && temp==tempa){
//     albumred=false;
//     continue;
// }
// }
    return library;
}
int countUniqueArtists( musicl music) {
    std::set<std::string> uniqueArtists;
    for (const auto& album : music.album) {
        const auto& albumArtists = music.artist.at(album);
        for (const auto& artist : albumArtists) {
            uniqueArtists.insert(artist);
        }
    }
    return uniqueArtists.size();
}

void stats (musicl library){
cout<<"Overall Music Library Stats"<<endl<<"===========================\nTotal Records: ";
cout<<library.album.size()<<endl;
set <string> art;
set <string> song; 
set <string> temp;
int asize=0;
/*
for( auto ill: library.album){

for( int i=0;i<library.album.size();i++){


for (int l=0; l<library.artist[ill].size();l++){
    if (temp.find(library.artist[ill])){

    }
}
// if(!temp.find(it[ill].second)){

// }
temp=it[ill].second;

}
}


*/
cout<<"Total Unique Artists: "<<(countUniqueArtists(library));



}
int main()
{
    string userEntry;
    string command, remains="nothing";
    map<string, musicl> lib;
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
          //  cout<<"r here"<<remains<<endl<<"did you see me?";
            lib=load(remains, lib);
        }
        else if (command == "stats")
        {
            stats(lib);
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
