#include "Stack.h"
#include <cstdio>

using namespace std;

int
main(int argc, char* argv[])
{
  Stack<int> a(8);
  int b[3] = {1, 2, 3};
  Stack<int> bb(3, b);
  bb.push(4);
  a = bb;
  bb[3] = 20;
  int k;
  a.pop(k);
  printf("%3d %3d\n", bb[3], k);
}
