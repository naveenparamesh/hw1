#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T>
class MyDynamicArray2 {
     public:
    MyDynamicArray2(unsigned long long initial_size = 0);
    void push_back(T element);
    unsigned long long size();
    T at(unsigned long long index);



  private:
    T* my_vector;
    unsigned long long size_of_array;
};

template<typename T>
MyDynamicArray2<T>::MyDynamicArray2(unsigned long long initial_size){
  my_vector = (T*)malloc(initial_size * sizeof(T));
  size_of_array = initial_size;
}

template<typename T>
void MyDynamicArray2<T>::push_back(T element){
  T* temp = (T*)malloc((size_of_array + 1) * sizeof(T));
  for(int i = 0; i < size_of_array; i++){
    temp[i] = my_vector[i];
  }
  size_of_array += 1;
  free(my_vector);
  my_vector = temp;
  my_vector[size_of_array - 1] = element;
}

template<typename T>
unsigned long long MyDynamicArray2<T>::size(){
  return size_of_array;
}

template<typename T>
T MyDynamicArray2<T>::at(unsigned long long index){
  return my_vector[index];
}