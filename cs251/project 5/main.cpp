#include "priorityqueue.h"
#include <iostream>
using namespace std;

int main() {
    //cout<<"testing";
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
        
        priorityqueue <char> empty;
        empty.enqueue('a',0);
        empty.enqueue('z',28);
        empty.enqueue('c',3);
        empty.enqueue('d',3);
        empty.enqueue('b',1);
        empty.enqueue('e',4);
        empty.enqueue('f',5);
        string k=empty.toString();
        cout<<k;
        cout<<empty.dequeue()<<endl;
        cout<<empty.dequeue()<<endl;
        cout<<empty.dequeue()<<endl;
        cout<<empty.dequeue()<<endl;
        cout<<empty.dequeue()<<endl;
        cout<<empty.dequeue()<<endl;
        cout<<empty.dequeue()<<endl;


// priorityqueue <int> empty;
//         empty.enqueue(5,4);
//         empty.enqueue(15,4);
//         empty.enqueue(11,4);
//         empty.enqueue(12,4);
//         empty.enqueue(16,4);
//         empty.enqueue(25,3) ;
//         empty.enqueue(29,2) ;

                
return 0;
}