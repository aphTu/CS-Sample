#ifndef TWO_D_FUNCTIONS
#define TWO_D_FUNCTIONS
#include <iostream>
#include <fstream>
#include "../../includes/array_functions/array_functions.h"

using namespace std;

int array_size(int* sizes);
void print_array(int* a);
bool index_is_valid(int* sizes, int row, int col);



//To call: int** p = allocate_twod<int>(sizes_array)  

template <class T>
T** allocate_twod(int* sizes); 

template <class T>
T** deallocate_twod(T** twod, int size);

template <class T>
T read_twod(T** twod, int row, int col);

template <class T>
void write_twod(T** twod, int row, int col, const T& item);

template <class T>
T& get_twod(T** twod, int row, int col);

template<class T>
void init_twod(T** twod, int* sizes, T init_item = T());

template<class T>
bool search_twod(T** twod, int* sizes, const T& key, int& row, int& col);

//return a pointer to the item if found, nullptr if not found: 
//                                                 (Ms. Barskhian)
template<class T> 
T* search_twod(T** twod, int* sizes, const T& key); 

template <class T>
ostream& print_twod(T** twod, int* sizes, ostream& outs = cout);

template<class T>
void init_twod_debug(T** twod, int* sizes);


//=======================================================================


int array_size(int* sizes){
  int counter = 0;
  const bool debug = true;
  while(*sizes != -1){
    counter++;
    sizes++;
  }
  if(debug){
    cout << "# of row is: " << counter << endl;
  }
  return counter;
}
void print_array(int* a){
  int* a_p = a;
  int how_many = array_size(a_p) + 1;
  for (int i = 0; i<how_many; i++){
    cout << setw(6)  << *a_p << setw(6);
    a_p++;
    if(!(i + 1 == how_many)){
      cout << "|";
    }
  }
}
bool index_is_valid(int* sizes, int row, int col){

}



//To call: int** p = allocate_twod<int>(sizes_array)  

template <class T>
T** allocate_twod(int* sizes){
  assert(!(sizes == nullptr));
  int* column_walker = sizes;
  T** arr;
  T** arr_walker;

  //--------debug var------//
  const bool debug = false;
  int count_row = 0;
  //-----------------------//

  int row = array_size(sizes);
  arr = new T* [row+1];
  arr_walker = arr;
  while(1){
    if(*column_walker == -1)
    {
      *arr_walker = nullptr;
      break;
    } 
    if(debug){
      cout << "creating an array of " << *column_walker << " inside row of " << count_row << endl;
    }
    // *arr_walker = new T [*column_walker];
    *arr_walker = allocate<T>(*column_walker);
    count_row++;
    column_walker++;
    arr_walker++;
  }
  return arr;
}

template <class T>
T** deallocate_twod(T** twod, int size){

}

template <class T>
T read_twod(T** twod, int row, int col){

}

template <class T>
void write_twod(T** twod, int row, int col, const T& item){

}

template <class T>
T& get_twod(T** twod, int row, int col){

}

template<class T>
void init_twod(T** twod, int* sizes, T init_item){
  assert(!(sizes == nullptr));
  assert(!(twod == nullptr));
  T** row_w = twod;
  T*col_w;
  int*sizes_p = sizes;
  const bool debug = false;
  int row_counter = 0;
  if(debug){
    cout << "Beginning to initialize the element in the 2d array" << endl;
  }
  while(*row_w != nullptr){
    col_w = *row_w;
    for(int i = 0; i<*sizes_p;i++){
      if(debug){
        cout << "placing " << init_item << " into " << i << " column, row  " << row_counter << endl;
      }
       *col_w = init_item;
       col_w++;
    } 
    sizes_p++;
    row_w++;
    row_counter++; 
  }
}

template<class T>
bool search_twod(T** twod, int* sizes, const T& key, int& row, int& col){

}

//return a pointer to the item if found, nullptr if not found: 
//                                                 (Ms. Barskhian)
template<class T> 
T* search_twod(T** twod, int* sizes, const T& key){

} 

template <class T>
ostream& print_twod(T** twod, int* sizes, ostream& outs){
  T** row_walker = twod;
  T*column_walker;
  int* sizes_w = sizes;
  while(*row_walker!= nullptr){
    column_walker = *row_walker;
    print(column_walker, *sizes_w);
    cout << endl;
    row_walker++;
    sizes_w++;
  }
}

template <class T>
void init_twod_debug(T** twod, int* sizes ){
  T** row_w = twod;
  T*col_w;
  int*sizes_p = sizes;
  const bool debug = false;
  int row_counter = 0;
  int j = 0;
  if(debug){
    cout << "Beginning to initialize the element in the 2d array" << endl;
  }

  while(*row_w != nullptr){
    col_w = *row_w;
    j = row_counter * 10;
    for(int i = 0; i<*sizes_p;i++){
      if(debug){
        cout << "placing " << i<< " into " << i/10 << " column, row  " << row_counter << endl;
      }
       *col_w = j;
       col_w++;
       j++;
    } 
    sizes_p++;
    row_w++;
    row_counter++; 
  } 
}

#endif