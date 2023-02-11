#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
int main()
{
ifstream inputfile;
ofstream outputfile("output.txt");
vector <string> fn;
vector <string> words;
string fn2;
string word;
string temp;
string dataloc;
dataloc="datalocations.txt";
inputfile.open(dataloc);
if(!inputfile.is_open()){
  cout<<"**file not found"<< endl;  

return 1;
}

else{
while(inputfile >> temp)
{
    
 
 fn.push_back(temp);   

}
inputfile.close();
}


for(int i=0;i<fn.size();i++ )
{

inputfile.open(fn.at(i));
if(!inputfile.is_open())    
    {
    cout<<"**file not found"<< endl;
    return 1;
    }

//else{
while(inputfile >> temp){    
    
    words.push_back(temp);
    }   
inputfile.close();
}

for(int i=0;i<words.size(); i++){
outputfile<<words.at(i)<<endl;
}

outputfile<<"is this working"<<endl;
outputfile.close(); 
    return 0;
}