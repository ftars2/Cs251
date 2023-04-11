#include "priorityqueue.h"
#include <iostream>
using namespace std;

int main() {
    cout<<"testing";
  // priorityqueue <int> empty;
  //   empty.enqueue(100,2);
  //   empty.enqueue(55,10);
  //   empty.enqueue(21,3);
  //   empty.enqueue(99,4);
  //   empty.enqueue(23,15);
  //   cout<<(empty.dequeue())<<endl;
  //   cout<<(empty.dequeue())<<endl;
  //   cout<<(empty.dequeue())<<endl;
  //   cout<<(empty.dequeue())<<endl;
  //   cout<<(empty.dequeue())<<endl;
  //   cout<<(empty.dequeue())<<endl;
priorityqueue <string> empty;
        empty.enqueue("hello",1);
        empty.enqueue("hope",3);
        empty.enqueue("i",2);
        empty.enqueue("you have a great day",4);
        string k=empty.toString();
        cout<<k;

return 0;
}