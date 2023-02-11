using namespace std;
#include <iostream>
#include <set>
#include <string>
#include <map>
int main()
{

set<string> items;
map<string,set<string>> mapple;
string temp1;
string temp2;
char c;
while(cin<<temp1<<c<<temp2){
if(temp1=="exit"){
    break;
}
if (mapple.count(temp1)==1){

mapple[temp1].insert(temp2);
}
}

  else{
    mapple.emplace(temp1,temp2);
  }  

for(const auto &name: mapple){
    string key=name.first;
    set <string> val=name.second;

    cout<< key<< ": {";
    for(const auto &val){
cout << val << ", ";
    
    
    }

    cout<<"}"<<endl;

}
    
    return 0;
}