#include <iostream>
#include <time.h>
#include <iostream>
#include <sstream>
#include "BSTAVL.h"

int main(){
  BSTAVL bst;
  bst.addNode(100);


  clock_t t = clock();
  size_t size = 100000;
  int *pInt = new int[size]; for(size_t i = 0; i < size; i++)
  pInt[i] = rand();
//just for testing //randomizes an array
  t = clock() - t;
  cout << "time: " << t << " miliseconds" << endl;
  cout << CLOCKS_PER_SEC << " clocks per second" << endl;
  cout << "time: " << t*1.0/CLOCKS_PER_SEC << " seconds" << endl;
  delete [] pInt;

  string input = "a,b,c";
  istringstream ss(input);
  string token;
  while(getline(ss, token, ',')) { //uses , as splitter instead of white space
    cout << token <<" ";
  }

  return 0;
}
