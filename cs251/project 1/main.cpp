//Frank Tarshis
//  Project 1 Starter Code - Gerrymandering
//  cs 251
//  1/31/2023
//  Summary: this code has 5 main operations that are used to calculate in Gerrymandering is occouring in a state.
// those operations are load, search, stats, plot, and exit.
// load loads in 2 files, one containing the states names, district #, democratic voting # for that district, and republican voting # for that district.  
//search searches for a state that was previously loaded in.
//stats displays information about specified state, specifically if that state has Gerrymandering.
//plot plots a chart of D's and R's porportional to the #of people in each party.
//exit ends the program.
#include "ourvector.h"
#include "fstream"
#include "string"
#include "sstream"
#include "cctype"
#include "algorithm"
#include "limits"
#include "iostream"
#include "cmath"
using namespace std;
    struct state{//struct used to store information from both input files
        string name;//contains the name of a state
    ourvector <int> demnum;// ourvector of democratic voters in a state. ourvector so it holds each district in a state
    ourvector <int> repnum;// ourvector of republican voters in a state. ourvector so it holds each district in a state
    int dnum;//# of districts
    int elinum;//# of eligible voters in a state
};
    struct vote{// contains information from second file;
        string name;//states name
        int elinum;//# of eligible voters
    };
    struct facts{//used to determine what has or hasnt been loaded or searched, and other program progreession information
        bool load1;//true if file 1 loaded
        bool load2;//true if file 2 is loaded
        bool search;// true if a file was successfully searched
        bool gar;// true if a state garrymandered 
    };



//this function creates a simple menu that says if data has been loaded correctly
void menu(struct facts& fact){
string A;//used to hold yes or no
if(fact.load2) {//if load 2 was loaded correctly
 A="Yes";   //data loaded: yes
}
else {
    A="no";// data laoded: no
}  
    cout<<"data loaded? "<<A<<endl<<"State: N/A"<<endl<<endl<<"Enter Command:"<<endl<<"-----------------------------"<<endl;
}



//this function displays a more specified menu, as well as a error message in certain situations
void menus(ourvector <struct state>& place, int space, struct facts fact){// takes in vector of structs containing names of states, a interger that holds specified states place, and struct of progression
    string A;// holds eitehr yes or no
    if(fact.load2){//if second file loaded correctly
        A="Yes";//data loaded: yes
    }
    else if(fact.load1 && fact.search){
        A="No";//data loaded: no
    }
    if(!fact.search){//if second file failed to load
        cout<<"State does not exist, search again.\n\ndata loaded? Yes"<<endl<<"State: N/A"<<endl<<endl<<"Enter Command:"<<endl<<"-----------------------------"<<endl;
    
    }
    
    else if((fact.search)&&(fact.load1)){   //if both file 1 loaded and search worked
        cout<<"data loaded? "<<A<<endl<<"State: "<<place.at(space).name<<endl<<endl<<"Enter Command:"<<endl<<"-----------------------------"<<endl;
    }}


    //this function loads in 2 data files that contain states, # of districts, and # of both democratic and republican voters
void load( ourvector <struct state>& place, struct facts& fact){//takes in both structs that store in the files content, as well as the struct containing whether a file loaded correctly 
 ourvector <struct vote> eligible;// used to print out second file in propper order
string temp;//used for reading in each line of the files
string temp1;// contains the name of each state
state tem;// stores each state along with its associated values temporarily so it can be added to the vector of states
int temp2;// holds # of demcratic voters
int temp3;// holds # of republican voters
int temp4=1;//counts # of districts in each state
int t;// used to get rid of some commas
char c;// takes commas in to clear <<
int k;//used to take in unwanted #
string middleman;// is the middleman between file stream and the file locations
string fileloc, locelig;//stores the names of first and second file
cin>>fileloc>>locelig;// takes file locations from cin/ user input
middleman=fileloc;// makes middleman contain the file name
fstream in(middleman);//opens the file
vote tam; //used to temporarily hold data from second file
if(!in.is_open()){// if file is not open...
cout<<"Invalid first file, try again."<<endl<<endl;
fact.load1=false;//... file 1 failed to laod
return;
}
else{//otherwise...
fact.load1=true;// file 1 loaded correctly 
cout<<"reading: "<<fileloc<<endl;// "reading [filename here]"
while(getline(in,temp)){//continues to get each line from file 1 until it is empty and stores it in temp
    tem.demnum.clear();//clears tem's values
    tem.repnum.clear();//clears tem's values
    t=temp.find(',');//finds the first comma which is after the states name
    temp1= temp.substr(0,t);// temp1 is name of state, excluding comma
    temp.erase(0,t+1);//erases the states name as well as comma from temp
    t=temp.find(',');//finds the second comma in the line, which is after the first #/ acronym
    temp.erase(0,t);// erases everything before the second comma
stringstream s(temp);// string streams the remainder of the line/ temp
temp4=0;//# of districs=0
    while(s>>c){//while a character can be taken from the string stream...
        s>>temp2>>c>>temp3;//reads in democratic #, a comma, and republican #
        temp4++;//# of district increment
tem.name=temp1;//states name is added to the temp struct
tem.demnum.push_back(temp2);//# of democratic voters is added to temporary structs ourvector
tem.repnum.push_back(temp3);//# of republican voters is added to temporary structs ourvector
if(!(s>>c>>k)){//if character and interger cant be taken in from string stream...
break;//break the inner while loop
}
    }

    tem.dnum=temp4;//# of districts is added to temp state struct
place.push_back(tem);// adds tem to back of ourvector struct state place
    }
    }

for(int l=0;l<place.size();l++){//for all states read in print out there name and # of districts
cout<<"..."<<place.at(l).name<<"..."<<place.at(l).dnum<<" districts total"<<endl<<endl;
}
in.close();//closes the first file
in.open(locelig);// opens 2nd file
if(in.is_open()){//if file is open...
cout<<"reading: "<<locelig<<endl;//"reading: [filename here]"
fact.load2=true;//...second file loaded correctly
}
else{//otherwise...
    cout<<"Invalid second file, try again."<<endl<<endl;
fact.load2=false;//file 2 failed to load
return;//ends the loading process
}
while(getline(in,temp)){//while temp can get entire lines of text...
    t=temp.find(',');//finds first comma in a line
    temp1= temp.substr(0,t);// temp1 is name of state
    temp.erase(0,t+1);//erases first and only comma
    stringstream s(temp);//reads in the number of eligible voters
    s>>temp2;//temp2 contains eligible vothers
    for(int l=0;l<place.size();l++){//for all states contained in second file...
       if( place.at(l).name==temp1){//if state is in both files...
        place.at(l).elinum=temp2;//# of eligible voters is added to the coresponding state
        tam.name=temp1;//state name is added to temp voter struct
        tam.elinum=temp2;//# of eligible voters added to temp vote struct
        eligible.push_back(tam);//adds struct to the associated vecotr
       break;//ends the loop
       }
    }
}
  for(int i=0;i<place.size();i++){//for all states in first and second file...
cout<<"..."<<eligible.at(i).name<<"..."<<eligible.at(i).elinum<<" eligible Voters"<<endl<<endl;//"[state] # of elgible voters"
}
return;
}



//used to turn a string into a "search friendly" format
string ucase(string str){// takes in a string that will be returned in propper format
int size=str.size();//containts size of string
for(int i=0;i<size;i++){//for the size of the string...
str.at(i)=tolower(str.at(i));//all characters are lowercased
}
for(int i=0;i<size;i++){// for the size of the string...
if(str.at(i)==' '){//if a char in the string is a space..
str.at(i+1)=toupper(str.at(i+1));// captalze the char after it
}
}
    str.at(0)=toupper(str.at(0));//captalize the first character of the string
    return str;//returns the string in propper format
}



//used to search through the names of states and see if user input is a state loaded
int search( ourvector <struct state>& place, struct facts& fact){//requires the ourvector state struct that contains the states names as well as the progression struct
string sta;
int val;
getline(cin,sta);//gets the enire user input
if(sta.at(0)==' '){//if there is a space at the start of the string...
    sta.erase(0,1);//erase it
}
sta=ucase(sta);//calls for the uppercase function to propperly format the string
//cout<<"\n\n hello"<<sta;
int palace= place.size();//palace holds the length of the place vector 
  for(int i=0;i<palace;i++){//for the size of the place vector...
    if(sta==place.at(i).name){//if user input is a state...
       val=i;//val is equal to the index of that state
       fact.search=true;//search was completed succesfully
       return val;//return the index value

    }
    else{//otherwise...
        val=0;//sets the value=0
    fact.search=false;//search did not work out
    }}
return val;//returns the value
}


//calculates various values, but specifically whether a state is gerrymandering
void stats(ourvector<struct state>& place, int ind, facts fact){//requires the ourvecotr of states, the index of specifed state, and the progression struct    
    float eff;//efficency of gerrymandering
    int tot=0, wasr=0, wasd=0, totv=0, D=0 ,R=0, totr, totd;//tott: total votes for singluar districts  waasr:wasted republican votes  wasd:wasted democratic votes  totv;total votes for all districts D/R: number wins for each party   totr/totd: total number of votes for all districts for each party 
    ourvector <int> tott;// holds all district total votes 
    struct state temp;
    temp=place.at(ind);//access the states values
    bool pass;//allows a value to skip certain steps of the function
    int size=temp.demnum.size();//size is equal to # of districts
    string A;
    if(temp.dnum<3){// if less then 3 districts in a state...
            fact.gar=false;//not gerreymandering
            pass=true;//skips certain steps
    }
        for(int i=0;i<size;i++){//# of districts...
            totr+=place.at(ind).repnum.at(i);//add up republican votes
            totd+=place.at(ind).demnum.at(i);//adds upd democratic votes
            tot= place.at(ind).demnum.at(i)+place.at(ind).repnum.at(i);//total # of votes per disticts
            totv+=tot;//total # of votes in all districts
            tott.push_back(tot);//adds total # of votes per distict to its vector 
        
        if(place.at(ind).demnum.at(i)<place.at(ind).repnum.at(i)){//if there are more republican voters in this district...
            D++;//add 1 democratic loss 
            wasr+=place.at(ind).repnum.at(i)-(tot/2+1);//wasted republican votes= to republican votes in (i) district - half total
            wasd+=place.at(ind).demnum.at(i);//wated democratic votes = democratic votes
            }
        else{
            wasr+=place.at(ind).repnum.at(i);
            R++;//add 1 republican loss //wated republican votes = republican votes
            wasd+=place.at(ind).demnum.at(i)-(tot/2+1);//wasted democratic votes= to democratic votes in (i) district - half total
        }
               }
               eff=(float)abs(wasr-wasd)/totv*100;//efficency= the absolute value of((wasted republican votes) -(wasted democratic votes))/(total votes)*100  
               if(!pass){//if no pass...

               if(eff>7){///if eff is greater then 7...
               fact.gar=true;//gerrymandering is happening
               }
               else{//otherwise...
                fact.gar=false;//garrymandering isnt happening
               }
               }
        if(fact.gar){//if there is gerrymandering...
        if(wasd>wasr){//if there are more wasted democratic votes then republican...
            A="Democrats";//against : Democrats
        }
        else{//otherwise...
            A="Republicans";//against : Republicans
        }
cout<<endl<<"Gerrymandered: Yes"<<endl<<"Gerrymandered against: "<<A<<endl<<"Efficiency Factor: "<<eff<<"%"<<endl<<"Wasted Democratic votes: "<<wasd<<endl<<"Wasted Republican votes: "<<wasr<<endl<<"Eligible voters: "<<place.at(ind).elinum<<endl; 

    }
else{
cout<<endl<<"Gerrymandered: No"<<endl<<"Wasted Democratic votes: "<<wasd<<endl<<"Wasted Republican votes: "<<wasr<<endl<<"Eligible voters: "<<place.at(ind).elinum<<endl;     
}
return;
}

//this function creates a plot of R's and D's that represent the porportions of each parties votes in each district of a state
void plot(ourvector <struct state>& place, int ind, facts& fact){// requires the vecotor containing information about states, the index of specified state, and the progression struct
int size=place.at(ind).dnum;//size is equal to # of districts
int dtotr;//district total votes for republican
int dtotd, tott,l;//dtotd: district total votes for   tott: total number of votes per district   r: number of R's to be printed    l:coutns numbers of letters printed 
int d;//number of D's to be printed
for(int i=0;i<size;i++){//for # of disticts
    dtotd=0;//
    dtotr=0;//
    tott=0;//resets the vales for each loop
    d=0.0;//
    l=0;//
dtotd=place.at(ind).demnum.at(i);//equal democratic votes per district
dtotr=place.at(ind).repnum.at(i);//equal republican votes per district 
tott=dtotd+dtotr;//adds both republican and democratic votes to get total votes
if(dtotd==0 && dtotr==0) {//if both parties have no votes...
    cout<<"District: "<<i+1<<endl<<endl;
    continue;//dont print any letters, and go to next loop
}
if(dtotd==0){//if only democrats have no votes...
    cout<<"District: "<<i+1<<endl<<"RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR"<<endl;
    continue;// print 100 R's, go to next loop   
}
else if(dtotr==0){
    cout<<"District: "<<i+1<<endl<<"DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD"<<endl;
continue;// print 100 D's, go to next loop
}
d=((dtotd*100)/tott);//# of D's is equal to # of democratic votes*100/total votes, rounded downwards
cout<<"District: "<<i+1<<endl;//the district is always 1 more then the iteration of the for loop
while(d>=1 ){//while d is greater then 1...
    cout<<"D";
d--;//d increment downards by 1
l++;//increment l by 1
}
while((l<100)){//while l is not greater then 100 (because percentage is out of 100)
    cout<<"R";
l++;//increment l by 1
}
cout<<endl;
}

}

//mainly used to transition between functions via user input
int main() {
ourvector <struct state> var;// main ourvector that holds all information about each state

struct facts fax;
fax.load1=false;
fax.load2=false;//at the start of the program, the user hasnt progressed at all, so all fax. are false
fax.search=false;
   int index=9995;//sets the index to a high value to start 
    string com;//issued command by user
    cout<<"Welcome to the Gerrymandering App!"<<endl<<"Data loaded? No"<<endl<<"State: N/A"<<endl<<endl<<"Enter command:"<<endl<<"-----------------------------"<<endl<<endl;

while(cin>>com){// reads in the command issued
if((com=="load" )&& (fax.load2==false)){// if users command is load but file 2 hasnt been loaded correctly yet... 
    //cout<<"com worked";
    load(var,fax);//launches load function
     menu(fax);//opens basic menu
}
else if((com=="load") && (fax.load2==true)){//// if users command is load but they already loaded information in....
cout<<endl<<"Already read data in, exit and start over."<<endl<<endl;
menu(fax);// open basic menu
}
if((com=="search") && (fax.load1)){//// if users command is search and they loaded the first file in...
    index=search(var,fax);//index is equal to the the index of the state in vector var
    menus(var,index,fax);// displays advanced menu that shows if a state is loaded/ specified
}
if((com=="search") && (!fax.load1)){//// if users command is search but file 1 failed to load/ isnt loaded yet
    cout<<"\n\nNo data loaded, please load data first.\n\n";
menu(fax);//opens basic menu
}
if((com=="stats") && (fax.search)&&(fax.load2)){// if users command is stats and user loaded file 2 and searched for a state...
stats(var,index, fax);// displays stats of specifed state
menus(var,index,fax);// opens an advanced menu
}
else if((com=="stats") &&(!fax.search)){// if users command is stats but search failed/ hasnt been done
    cout<<"No state indicated, please search for state first.";
    menu(fax);//displays basic menu
}
else if((com=="stats") &&(!fax.load2)){// if users command is stats but user hasnt correctly loaded in a second file
    cout<<"\n\nNo data loaded, please load data first.\n\n";
menus(var,index,fax);// dsiplays a advanced menu
}
if(com=="plot" && (fax.load2) &&( fax.search)){//// if users command is plot and both the state search and file 2 have loaded correctly...
    plot(var,index, fax);// plots the porportions of the voting districts for that state
    menus(var,index,fax);//displays advanced menu
}
else if(com=="plot" &&(!fax.load2)){// if users command is plot but they havent propperly loaded file 2...
    cout<<"\n\nNo data loaded, please load data first.\n\n";
menus(var,index,fax);// opens advanced menu
}
else if(com=="plot" &&(!fax.search)){// if users command is plot but user hasnt searched for a state correctly yet
    cout<<"No state indicated, please search for state first.";
    menu(fax);//opens basic menu
}
if(com=="exit"){// if users command is exit...
    break;//end the while loop, causing program to end
}
}
    return 0;
}