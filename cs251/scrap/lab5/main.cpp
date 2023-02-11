using namespace std;    
#include <iostream>
#include <algorithm>
#include <vector>
int count(string thing){
    int num=1;
for(int i=0;i<thing.size();i++){
    if(thing.at(i)==' '){
        num++;
    }
    }
    return num;
}
void split(string thing, vector <string>& v1, vector<string>& v2, int num){
int n=num/2;
int f=0;
int s=0;
int space=0;
for(int i=0;i<thing.size();i++){
while(space*2<=n){
    cout<<n;

if(thing.at(i)==' '){
       space++;
       s=i;
       v1.push_back(thing.substr(f,s-f));
    
    
    }

}
if(thing.at(i)==' '){
       space++;
       s=i;
       v2.push_back(thing.substr(f,s-f));
    
    
    }
}
}

//set_intersection() union, diffference
int main()
{
vector <string> v1;
vector <string> v2;
string input;
int num;
getline(cin,input);
num=count(input);
cout<<num;
split(input,v1,v2,num);
 for(int i=0;i<v1.size();i++){
cout<<"vector"<<v1.at(i)<<endl;

 }
    return 0;
}