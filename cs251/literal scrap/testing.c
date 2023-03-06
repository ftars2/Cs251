#include <iostream>
#include <set>
#include <string>
using namespace std;
int main () 
{
   set<double>avrageNum;
   int z = 0;
   avrageNum.insert(5);
   avrageNum.insert(10.0);
   avrageNum.insert(12);
   avrageNum.insert(5.5);
   avrageNum.insert(10);
   for(auto i : avrageNum) {
      z += i; 
      cout << z << " ";
   }  
   return 0;
}