#include "priorityqueue.h"
#include <iostream>
using namespace std;

int main() {
    cout<<"testing";
  priorityqueue <int> empty;
    empty.enqueue(100,2);
    empty.enqueue(55,10);
    empty.enqueue(21,3);
    empty.enqueue(99,4);
    empty.enqueue(23,15);
    cout<<(empty.dequeue())<<endl;
    cout<<(empty.dequeue())<<endl;
    cout<<(empty.dequeue())<<endl;
    cout<<(empty.dequeue())<<endl;
    cout<<(empty.dequeue())<<endl;
    cout<<(empty.dequeue())<<endl;

return 0;
}