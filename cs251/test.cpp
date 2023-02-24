#include <iostream>
#include <queue>
#include <map>
#include <string>
using namespace std;


int main () {
   queue<double>joyTime;
   double yourNum = 0; 
   joyTime.push(15.5);
   joyTime.push(14.5);
   joyTime.front();
   joyTime.push(13.5);
   joyTime.pop();
   joyTime.push(12.5);
   joyTime.pop();
   joyTime.push(11.5);
   joyTime.pop();
   yourNum = joyTime.front() + joyTime.size();
   cout << yourNum;
   return 0;
}