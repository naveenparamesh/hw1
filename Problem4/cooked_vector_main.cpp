#include <iostream>
#include <string>
#include "cooked_vector.h"
#include "cooked_vector_malloc.h"

using namespace std;
int main(){
  MyDynamicArray<int> my_array(1); //this version uses new and delete
  cout << my_array.size() << endl;
  my_array.push_back(3); // add this function to the class tomorrow
  cout << my_array.size() << endl;
  my_array.push_back(8);
  cout << my_array.size() << endl;
  cout << "my_array.at(0) = " << my_array.at(0) << endl;
  cout << "my_array.at(1) = " << my_array.at(1) << endl;
  cout << "my_array.at(2) = " << my_array.at(2) << endl;
  MyDynamicArray2<int> my_array2(4); // this version uses malloc and free
  cout << my_array2.size() << endl;
  my_array2.push_back(6); // add this function to the class tomorrow
  cout << my_array2.size() << endl;
  my_array2.push_back(9);
  cout << my_array2.size() << endl;
  cout << "my_array.at(0) = " << my_array2.at(0) << endl;
  cout << "my_array.at(1) = " << my_array2.at(1) << endl;
  cout << "my_array.at(2) = " << my_array2.at(2) << endl;
  cout << "my_array.at(0) = " << my_array2.at(3) << endl;
  cout << "my_array.at(1) = " << my_array2.at(4) << endl;
  cout << "my_array.at(2) = " << my_array2.at(5) << endl;

  // assuming these functions are the only ones that are necessary because none others were specified

    return 0;
}
