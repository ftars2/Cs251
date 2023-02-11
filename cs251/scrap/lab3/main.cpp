#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
int main()
{
int sum;
int temp;
bool soom;

vector <int> v;
vector <int> m;
cout<<"what is sum?"<<endl;
cin>>sum;
cout<< "what are number"<<endl;
cin>>temp;
v.push_back(temp);
while(cin>>temp){
  
v.push_back(temp);
}
for(auto temps:v){
m.push_back(sum-temps);


}
for(int i=0; i<v.size();i++){

    for(int j=0; j<v.size();j++){
  if( v.at(i)==m.at(j)){
soom=true;
  }
  else{
    soom=false;
  }  
}    
}
if(soom){
  cout<< "there is pair";
  
}

return 0;
}