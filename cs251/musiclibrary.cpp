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
string album;
set<string> artist;
set<string> song;
};
struct settle{
    bool m=false;
    bool p=false;
    set<string> found;
    string lost;
};

map<string,musicl> load(string loc, map<string, musicl> library){
musicl talbum;
string temp;
string tempa="";
bool albumred=false;
//bool artred=false;
fstream s;

 if(loc==("nothing")||loc==("")){
 s.open("musicdatabase.txt");
 //cout<<loc;
 }
else{
 s.open(loc);
 if(!s.is_open()){
    cout<<"Error: Could not open music library file - "<<loc<<endl;
return library;
 }
 }


while(getline(s,temp)){
//cout<<tempa<<endl;
if(!albumred){
 talbum.album=(temp);
 albumred=true;
 tempa=temp;
 }
 else if((albumred) && (temp==tempa)){
     albumred=false;
     library.insert({tempa,talbum});
     talbum.artist.clear();
    talbum.song.clear();
 //   cout<<"\n\nsize"<<"\n\n";
  //  cout<<"hi";
 }
 else if(!isdigit(temp.at(0))){
talbum.artist.insert(temp);
     // library.artist.insert({tempa,temp});
// auto it = talbum.artist.find(tempa);
//     if(it==library.artist.end()){
//         set<string> tset = {temp};
//         library.artist[tempa] = tset;
//     }
//     else{
//         set<string>& artistset = library.song[tempa];
//         artistset.insert(temp);
//     }

 }

 else if(isdigit(temp.at(0))){
    talbum.song.insert(temp);

//     auto it = library.song.find(tempa);
//     if(it==library.song.end()){
//         set<string> tset = {temp};
//         library.song[tempa] = tset;
//     }
//     else{
//         set<string>& songset = library.song[tempa];
//         songset.insert(temp);
//     }
}
 
// if(temp==tempa){
//     cout<<"\n\ntempa is temp\n\n";
    
// }
// else{
//     cout<<"\n\ntempa is NOT temp\n\n";
// }
//  if(albumred){
//     cout<<"\n\nalbum is read\n\n";

//  }
//  else{
//     cout<<"\n\nalbum is NOT read\n\n";
//  }
 }
s.close();
    return library;
}
// int countUniqueArtists( musicl music) {
//     set<string> uniqueArtists;
//     for (const auto& album : music.album) {
//         const auto& albumArtists = music.artist.at(album);
//         for (const auto& artist : albumArtists) {
//             uniqueArtists.insert(artist);
//         }
//     }
//     return uniqueArtists.size();
//}

void stats (string extra, map <string, musicl> library){
cout<<"Overall Music Library Stats"<<endl<<"===========================\nTotal Records: ";
cout<<library.size()<<endl;
set <string> art;
set <string> song; 
set <string> temp;
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
//cout<<"Total Unique Artists: "<<(countUniqueArtists(library));
}
map <string,musicl> clear(map<string,musicl> library){
    library.clear();
return library;
}
void search(string com, map <string,musicl> library ){
string type;
set <string> place;
string temp;
string temp1;
string tname;
string tname2;
string tempsym;
set <string> nset;
set<settle> sset;
settle tem;
map <string,set<string>> tset;
set <string> ttset;
splitFirstWord(com,type,temp);
if(temp==""){
cout<<"Error: Search terms cannot be empty.\nNo results found.\n\n";
return;
}
//cout<<"\n\ntype "<<type<<"\n\n";
while(true){
//cout<<"\n\n temp: "<<temp<<"\n\ntemp1: "<<temp1;
tem.m=false;
tem.p=false;
if(temp==""){
//cout<<"this worked"<<i;
break;
}
    splitFirstWord(temp,temp1,temp);
place.insert(temp1);
 if(!100>temp1.find('+')){
    tem.lost=(temp1);
    tem.p=true;

}
 if(!100>temp1.find('+')){
    tem.lost=(temp1);
    tem.m=true;
}
sset.insert(tem);
}
for( auto& palace : sset){
    for( auto name: library){
            tname=(name.first);
            tolower(tname);

            if(100>tname.find(palace.lost)){
                ttset.insert<
            }
        }
                tset.insert({palace.lost,name.first});
}



if(type=="album"){
    if(!isalnum(tempsym.at(0))){
           
    }
    for(const auto look : place){
        for( const auto name: library){
            tname=(name.first);
            tolower(tname);

            if(100>tname.find(look)){
                nset.insert(name.first);
                //cout<<"\n\nlook: "<<look<<"\n\ntname: "<<tname;

                
            }
        }
    }
                cout<<"Your search results exist in the following albums: "<<endl;
                for (const auto lol : nset){
                    cout<<lol<<endl;
                }
                cout<<endl;
}
if(type=="artist"){
    for(const auto look : place){
        for( const auto name: library){
            for(const auto person : name.second.artist){

            tname=(person);
            tolower(tname);

            if(100>tname.find(look)){
                nset.insert(name.first);
                //cout<<"\n\nlook: "<<look<<"\n\ntname: "<<tname;
            }
                } }    }
                cout<<"Your search results exist in the following albums: "<<endl;
                for (const auto lol : nset){
                    cout<<lol<<endl;
                }
                cout<<endl;
}
if(type=="song"){
    for(const auto look : place){
        for( const auto name: library){
            for(const auto music : name.second.song){

            tname=(music);
            tolower(tname);

            if(100>tname.find(look)){
                nset.insert(name.first);
                //cout<<"\n\nlook: "<<look<<"\n\ntname: "<<tname;
            }
                } }    }
                cout<<"Your search results exist in the following albums: "<<endl;
                for (const auto lol : nset){
                    cout<<lol<<endl;
                }
                cout<<endl;
}

}
void exports(map <string, musicl> library, string remains){
ofstream output;
bool notfirst=false;
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
            lib=clear(lib);
            // TODO
        }
        else if (command == "export")
        {
            exports(lib, remains);
        
            // TODO
        }
        else if (command == "load")
        {
          //  cout<<"r here"<<remains<<endl<<"did you see me?";
            lib=load(remains, lib);
        }
        else if (command == "stats")
        {
            stats(remains,lib);
            // TODO
        }          
        else if (command == "search")
        {
         search(remains,lib);
            // TODO
        }

    }while(command != "exit");    

    cout << "Thank you for using the Music Library App" << endl;
    return 0;
}
