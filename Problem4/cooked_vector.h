#include <iostream>

using namespace std;

template <typename T>
class MyDynamicArray {

  public:
    MyDynamicArray(unsigned long long initial_size = 0);
    void push_back(T element);
    unsigned long long size();
    T at(unsigned long long index);



  private:
    T* my_vector;
    unsigned long long size_of_array;
};


template<typename T>
MyDynamicArray<T>::MyDynamicArray(unsigned long long initial_size){
  my_vector = new T[initial_size];
  size_of_array = initial_size;
}

template<typename T>
void MyDynamicArray<T>::push_back(T element){
  T* temp = new T[size_of_array + 1];
  for(int i = 0; i < size_of_array; i++){
    temp[i] = my_vector[i];
  }
  size_of_array += 1;
  delete[] my_vector;
  my_vector = temp;
  my_vector[size_of_array - 1] = element;
}

template<typename T>
unsigned long long MyDynamicArray<T>::size(){
  return size_of_array;
}

template<typename T>
T MyDynamicArray<T>::at(unsigned long long index){
  return my_vector[index];
}
