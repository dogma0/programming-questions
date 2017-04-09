#include<iostream>
#include<string>
using namespace std;


int main() {
   size_t s = 10;
   unsigned u = 10;
   int i = -11;
   int j = -9;
   // Wrapped around
   cout << u + i << endl;
   cout << s + i << endl;
   // No conversion before addition and result can fit in unsigned
   cout << u + j << endl;
   // Type conversion from int to long for i
   cout << u*i << endl;
   // List initilization doesn't allow initializer that is narrowing
   long double d = 3.14123123;
   int a = {d};
   int c(d);
   int b;
}
