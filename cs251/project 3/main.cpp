#include "mymatrix.h"
#include "cassert"
using namespace std;
void test1(){
mymatrix<int> M;
assert(M.numrows() == 4);
assert(M.numcols(0) == 4);
assert(M(0, 0) == 0);
cout<<"\ntest 1 cleared"<<endl;
}
void test2(){
mymatrix<int> M(3, 5);
assert(M.numrows() == 3);
assert(M.numcols(0) == 5);
assert(M(0, 0) == 0);
cout<<"\ntest 2 cleared"<<endl;
}
void test3(){
  mymatrix<int> M(3, 5);
M(1, 1) = 42;
mymatrix<int> N(M);
assert(N.numrows() == 3);
assert(N.numcols(0) == 5);
assert(N(1, 1) == 42);
cout<<"\ntest 3 cleared"<<endl;
}
void test4(){
  mymatrix<int> M(2, 2);
M(1, 1) = 42;
M._output();
M.growcols(1, 4);
assert(M.numrows() == 2);
assert(M.numcols(1) == 4);
assert(M(1, 2) == 0);
assert(M(1, 1) == 42);
cout<<"\ntest 4 cleared"<<endl;
}
void test5(){
  mymatrix<int> A(2, 3);
A(0, 0) = 1; A(0, 1) = 2; A(0, 2) = 3;
A(1, 0) = 4; A(1, 1) = 5; A(1, 2) = 6;

mymatrix<int> B(3, 2);
B(0, 0) = 1; B(0, 1) = 4;
B(1, 0) = 2; B(1, 1) = 5;
B(2, 0) = 3; B(2, 1) = 6;

mymatrix<int> C = A * B;
assert(C.numrows() == 2);
assert(C.numcols(0) == 2);
A._output();
B._output();
C._output();
assert(C(0, 0) == 14);
assert(C(1, 1) == 77);
cout<<"\ntest 5 cleared"<<endl;
}
void test6(){
  mymatrix<int> M(3, 5);
M(1, 1) = 42;
assert(M(1,1) == 42);
cout<<"\ntest 6 cleared"<<endl;
}


int main(){
mymatrix<int> tester;
cout<<"welcome to testing place thing!"<<endl;
test1();
test2();
test3();
test4();
test5();
test6();

return 0;
}