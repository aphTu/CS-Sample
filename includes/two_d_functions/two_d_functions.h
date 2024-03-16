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

template <typename T>
void delete_repeats(T* a, int& size);

template <class T>
bool delete_keys_twod(T**twod,int* sizes, T key);


//=======================================================================


int array_size(int* sizes){
  int counter = 0;
  const bool debug = false;
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
  assert(!(sizes==nullptr));

  //sizes_p take the row given to find column that belong to that row
  //how_many_value find how many row the 2d array actually have, does not count -1
  int* sizes_p = row + sizes; 
  int how_many_value = array_size(sizes);
  const bool debug = false;
  if(debug){
  cout << "how_many_value: " << how_many_value << " and sizes_p is " << *sizes_p << endl; 
  }
  //check if the row given is within the boundary of row in the 2d array
  if(row <= how_many_value) {
    //if true, it then check if col given is within the col in the 2d array
    if(col <= *sizes_p){
    return true;
    }
    return false;
  }
  else {
    return false;
  }
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
  //create the row needed for the array
  arr = new T* [row+1];
  arr_walker = arr;
  //arr_walker walk throughout the created space
  //column_walker is the pointer that point to sizes
  //dereferencing it gives us the size we need to allocate
  while(1){
    if(*column_walker == -1)
    {
      *arr_walker = nullptr;
      break;
    } 
    if(debug){
      cout << "creating an array of " << *column_walker << " inside row of " << count_row << endl;
    }
    *arr_walker = allocate<T>(*column_walker);
    count_row++;
    column_walker++;
    arr_walker++;
  }
  return arr;
}

template <class T>
T** deallocate_twod(T** twod, int size){
  T** row_w = twod;
  T* col_w;
  //delete the pointer within the row first
  //delete the entire 2d pointer
  while(*row_w != nullptr){
   col_w = *row_w;
   delete []col_w;
   row_w++; 
  }
  delete []twod;
  return nullptr;
}

template <class T>
T read_twod(T** twod, int row, int col){
  assert(!(row < 0));
  assert(!(col < 0));
  assert(!(twod == nullptr));
  
  T reading = get_twod(twod,row,col);
  return reading;
}

template <class T>
void write_twod(T** twod, int row, int col, const T& item){
  assert(!(row < 0));
  assert(!(col < 0));
  assert(!(twod == nullptr));
  get_twod(twod,row,col) = item; 
}

template <class T>
T& get_twod(T** twod, int row, int col){
  assert(!(row < 0));
  assert(!(col < 0));
  assert(!(twod == nullptr));

  T** row_w = twod + row;
  T* col_w = *row_w + col;
  return *col_w;
}

template<class T>
void init_twod(T** twod, int* sizes, T init_item){
  assert(!(sizes == nullptr));
  assert(!(twod == nullptr));
  T** row_w = twod;
  T*col_w;
  int*sizes_p = sizes;

  //-------debug var------//
  const bool debug = false;
  int row_counter = 0;
  //---------------------//
  if(debug){
    cout << "Beginning to initialize the element in the 2d array" << endl;
  }

  // row_w run through the allocated space within the 2d array
  //col_w run through the space within those allocated spaces
  while(*row_w != nullptr){
    col_w = *row_w;
    for(int i = 0; i<*sizes_p;i++){
      if(debug){
        cout << "placing " << init_item << " into " << i << " column, row  " << row_counter << endl;
      }
      //placing the initialize item inside each column of that row
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
  T**row_w = twod;
  T*col_w;
  int* sizes_p = sizes;
  const bool debug = false;
  //row_counter is the value that will be return into row
  int row_counter = 0;

  //loop will continue until it find the row and col
  //meaning key is in the array

  //or when *row_w reach nullptr
  //meaning key is not in the array
  while(*row_w != nullptr){
    col_w = *row_w;

    //index is the index key is at
    //if it -1, it mean it not in that row
    //if it the key, it mean it in that row
    int index = search(col_w,*sizes_p,key);
    T* col_current = index + col_w;
    if(*col_current== key){
        if(debug){
          cout << "correct row is " << row_counter << " and correct col is " << index << endl;  
        }
        row = row_counter;
        col = index;
        return true;
      }
    sizes_p++;
    row_w++;
    row_counter++;
  }
  
  return false;
}

//return a pointer to the item if found, nullptr if not found: 
//                                                 (Ms. Barskhian)
template<class T> 
T* search_twod(T** twod, int* sizes, const T& key){
  T** row_w = twod;
  T* col_w;
  int* sizes_p = sizes;
  const bool debug = false;
  int row_counter = 0;

  while(*row_w!= nullptr){
    col_w = *row_w;
    if(debug){
    cout << "row is "<< row_counter;
    }
    //found take in the pointer from search_entry
    //that pointer is pointing at position of key if key is in the array
    //pointer point at nullptr if it did not find key
    T* found = search_entry(col_w, *sizes_p, key);
    if(found != nullptr){
      if(debug){
        cout << "found " << key << " at row " << row_counter;
      }
      return found;
    }
    //changes the row
    row_w++;
    sizes_p++;
    row_counter++;
  }
  return nullptr;
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

template <typename T>
void delete_repeats(T*a, int& size){ 
  assert(!(size <= 0));
  T* a_p = a;
  bool debug = false;  
  for (int i = 0; i < size; i++){
    //i_walker walk along the array depending on i
    //the code check if current address of the array matches the return address of search_entry

    T* i_walker = a_p + i;
    T* current = i_walker;
    T* found = search_entry(a_p, size , *current);
    if(debug){
      cout << "checking if " << *current << " is repeated or not" << endl;
    }

    //if not equal the code will delete the code and decrement i by 1
    if(current != found){
      if(debug){
      cout << *current << " is repeated, deleting it" <<endl;
      }
      shift_left(a_p,size,current);
      i--;
    }
  }
}


template <class T>
bool delete_keys_twod(T**twod,int* sizes, T key){
  T** row_w = twod;
  T* col_w;
  int* sizes_p = sizes;

  int row;
  int col;
  T* still_repeat = search_twod(twod,sizes,key);
  if(still_repeat == nullptr){
    return false;
  }
  while(1){
    bool found = search_twod(twod,sizes,key,row,col);
    if(found == true){
      write_twod(twod,row,col,0);
    }
    
    still_repeat = search_twod(twod,sizes,key);
    if(still_repeat == nullptr){
      return true;
    }
  }
}

#endif