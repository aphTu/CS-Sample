#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
#include "..\..\includes\two_d_functions\two_d_functions.h"
#include "..\..\includes\array_functions\array_functions.h"
#include "..\..\includes\plane\plane.h"
#include "..\..\includes\lab\lab.h"
using namespace std;

bool test_stub(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  return true;
}

bool test_init_td(bool debug = false){
  int sizes[] = {6,5,3,3,4,-1};
  int** twod_arr = allocate_twod <int> (sizes);
  
  
  //filling the array with -1
  init_twod(twod_arr,sizes, -1);
  if(debug){
    cout << "Array filled with -1:" << endl;
    print_twod(twod_arr,sizes);
  }

  if(1){
    int** row_w = twod_arr;
    int* col_w;
    int* size_p = sizes;
    int row_counter = 0;
    while(*row_w != nullptr){
      col_w = *row_w;
      for(int i =0; i<*size_p;i++){
        if(*col_w != -1){
          cout << "FAILED: Expected to find -1 but instead found " << *col_w << " at row " << row_counter << ", column " << i << endl;
          return false;
        }
        col_w++;
      }
      row_w++;
      row_counter++;
      size_p++;
    }
  }
  
  //running init_debug
  if(debug){
    init_twod_debug(twod_arr,sizes);
    cout << "Init_twod_debug array:" << endl;
    print_twod(twod_arr,sizes);
  }



  //filling array with 13
  init_twod(twod_arr,sizes,13);
  if(debug){
    cout << "array filled with 13: " << endl;
    print_twod(twod_arr,sizes);
  }

  if(1){
    int** row_w = twod_arr;
    int* col_w;
    int* size_p = sizes;
    int row_counter = 0;
    while(*row_w != nullptr){
      col_w = *row_w;
      for(int i =0; i<*size_p;i++){
        if(*col_w != 13){
          cout << "FAILED: Expected to find 13 but instead found " << *col_w << " at row " << row_counter << ", column " << i << endl;
          return false;
        }
        col_w++;
      }
      row_w++;
      row_counter++;
      size_p++;
    }
  }
  
  //fill array with default T (int) value
  init_twod(twod_arr,sizes);
  if(debug){
    cout << "array filled with default T value: " << endl;
    print_twod(twod_arr,sizes);
  }

  if(1){
    int** row_w = twod_arr;
    int* col_w;
    int* size_p = sizes;
    int row_counter = 0;
    while(*row_w != nullptr){
      col_w = *row_w;
      for(int i =0; i<*size_p;i++){
        if(*col_w != 0){
          cout << "FAILED: Expected to find 0 but instead found " << *col_w << " at row " << row_counter << ", column " << i << endl;
          return false;
        }
        col_w++;
      }
      row_w++;
      row_counter++;
      size_p++;
    }
  }

  //----------------------//
  //testing char array
  char** char_twod_arr = allocate_twod <char> (sizes);
  //fill array with default T (int) value
  init_twod(char_twod_arr,sizes);
  if(debug){
    cout << "array filled with default T value: " << endl;
    print_twod(char_twod_arr,sizes);
  }

  if(1){
    char** row_w = char_twod_arr;
    char* col_w;
    int* size_p = sizes;
    int row_counter = 0;
    while(*row_w != nullptr){
      col_w = *row_w;
      for(int i =0; i<*size_p;i++){
        if(*col_w != 0){
          cout << "FAILED: Expected to find blank (0 in char) but instead found " << *col_w << " at row " << row_counter << ", column " << i << endl;
          return false;
        }
        col_w++;
      }
      row_w++;
      row_counter++;
      size_p++;
    }
  }

  //filling the array with 'c'
  init_twod(char_twod_arr,sizes,'c');
  if(debug){
    cout << "array filled with default T value: " << endl;
    print_twod(char_twod_arr,sizes);
  }

  if(1){
    char** row_w = char_twod_arr;
    char* col_w;
    int* size_p = sizes;
    int row_counter = 0;
    while(*row_w != nullptr){
      col_w = *row_w;
      for(int i =0; i<*size_p;i++){
        if(*col_w != 'c'){
          cout << "FAILED: Expected to find 'c' but instead found " << *col_w << " at row " << row_counter << ", column " << i << endl;
          return false;
        }
        col_w++;
      }
      row_w++;
      row_counter++;
      size_p++;
    }
  }
  
  twod_arr = deallocate_twod(twod_arr, 0);
  char_twod_arr = deallocate_twod(char_twod_arr, 0);
  return true;
}

bool test_index_is_valid(bool debug =false){
  int capacity = 10;
  int size = 5;
  int sizes[capacity];
  int row;
  int col;
  int* sizes_p;
 
  // testing sizes of 1,2,3,4,-1
  for(int i = 0; i<size;i++){
    sizes_p = sizes+ i;
    *sizes_p = i+1;
    if(i+1 == size){
      *sizes_p = -1;
      break;
    }
  }

  if(debug){
    cout << "sizes array is: ";
    print_array(sizes,size,capacity);
  }
  if(1){
    row = 3;
    col = 4;
    bool t_or_f = index_is_valid(sizes,row,col);

    if(debug){
      cout << "Checking if row " << row << " and col " << col << " is valid in sizes array of " << size - 1 << " row" << endl;
    }

    if(t_or_f != true){
    cout << "FAILED: Expected row 3, col 4 to be valid but instead it is " << t_or_f <<endl;
    return false;
    }
  }

   // testing sizes of 3,2,3,2,-1
  for(int i = 0; i<size;i++){
    sizes_p = sizes + i;
    if(i%2 == 0){
      *sizes_p = 3;
    }else {
      *sizes_p = 2;
    }

    if(i+1 == size)
    {
      *sizes_p = -1;
    }
  }


  if(debug){
    cout << "sizes array is: ";
    print_array(sizes,size,capacity);
  }
  if(1){
    row = 3;
    col = 1;
    bool t_or_f = index_is_valid(sizes,row,col);

    if(debug){
      cout << "Checking if row " << row << " and col " << col << " is valid in sizes array of " << size - 1 << " row" << endl;
    }

    if(t_or_f != true){
    cout << "FAILED: Expected row 3, col 1 to be valid but instead it is " << t_or_f <<endl;
    return false;
    }
  }

  //testing if the array is 5, 4, -1, 2, 1
  for(int i = 0; i<size;i++){
    sizes_p = sizes + i;
    *sizes_p = 5 - i;
    if(i+1 == 3){
      *sizes_p = -1;
    }
  }

  if(debug){
    cout << "sizes array is: ";
    print_array(sizes,size,capacity);
  }
  if(1){
    row = 3;
    col = 1;
    bool t_or_f = index_is_valid(sizes,row,col);

    if(debug){
      cout << "Checking if row " << row << " and col " << col << " is invalid in sizes array of 2 row" << endl;
    }

    if(t_or_f != false){
    cout << "FAILED: Expected row 3, col 1 to be invalid but instead it is " << t_or_f <<endl;
    return false;
    }
  }


  //testing if the array is -1, 4, 3, 2, 1
  for(int i = 0; i<size;i++){
    sizes_p = sizes + i;
    *sizes_p = 5 - i;
    if(i == 0){
      *sizes_p = -1;
    }
  }

  if(debug){
    cout << "sizes array is: ";
    print_array(sizes,size,capacity);
  }
  if(1){
    row = 3;
    col = 1;
    bool t_or_f = index_is_valid(sizes,row,col);

    if(debug){
      cout << "Checking if row " << row << " and col " << col << " is invalid in sizes array of 0 row" << endl;
    }

    if(t_or_f != false){
    cout << "FAILED: Expected row 3, col 1 to be invalid but instead it is " << t_or_f <<endl;
    return false;
    }
  }

  return true;
}

bool test_search_twod_bool(bool debug = false){
  int sizes [] = { 6, 3, 5, 2 , 1 , -1};
  int** twod_arr = allocate_twod <int> (sizes);
  int key;
  int row;
  int col;
  int row_return;
  int col_return;
  string tabs = "//---------------------// \n";
  init_twod(twod_arr,sizes,-1);
  if(debug){
    cout << "Original Array: " << endl;
    print_twod(twod_arr,sizes);
  }

  //trying to find 4 in row 2 and col 1
  if(1){
    key = 4;
    row = 2;
    col = 1;
    write_twod(twod_arr,row,col,key);

    bool found = search_twod(twod_arr,sizes,key, row_return, col_return);

    if(debug){
      cout << tabs;
      cout << "Trying to find " << key << " at row " << row << " and col " << col << endl;
      print_twod(twod_arr,sizes); 
    }

    
    if(found != true){
      cout << "FAILED: Expected to find " << key << " in the array" << endl;
      return false;
    }

    if(row_return != row && col_return != col){
      cout << "FAILED: Expected to find " << key << " at row " << row << " and col " << col << " but instead found it at row " << row_return << " and col " << col_return << endl;
      return false;   
    }
  }

  //trying to find the row and col for 30
  if(1){
    key = 30;
    row = 0;
    col = 0;
    write_twod(twod_arr,row,col,key);

    bool found = search_twod(twod_arr,sizes,key, row_return, col_return);

    if(debug){
      cout << tabs;
      cout << "Trying to find " << key << " at row " << row << " and col " << col << endl;
      print_twod(twod_arr,sizes); 
    }

    
    if(found != true){
      cout << "FAILED: Expected to find " << key << " in the array" << endl;
      return false;
    }

    if(row_return != row && col_return != col){
      cout << "FAILED: Expected to find " << key << " at row " << row << " and col " << col << " but instead found it at row " << row_return << " and col " << col_return << endl;
      return false;   
    }
  }



  //trying to find a value not in the array
  if(1){
    key = 50;

    bool found = search_twod(twod_arr,sizes,key, row_return, col_return);

    if(debug){
      cout << tabs;
      cout << "Trying to find number not in the array (" << key << ") "<< endl;
      print_twod(twod_arr,sizes); 
    }

    
    if(found == true){
      cout << "FAILED: Expected to to not find " << key << " in the array" << endl;
      return false;
    }
  }

  //-----------------------//
  //testing char array
  char** char_twod_arr = allocate_twod <char> (sizes);
  char char_key;
  init_twod(char_twod_arr,sizes,'x');
  if(debug){
    cout << "Original Array: " << endl;
    print_twod(char_twod_arr,sizes);
  }

  //trying to find 'a' in the array in row 3, col 1

  if(1){
    char_key = 'a';
    row = 3;
    col = 1;
    write_twod(char_twod_arr,row,col,char_key);
    bool found = search_twod(char_twod_arr,sizes,char_key,row_return,col_return);
    if(debug){
      cout << tabs;
      cout << "Trying to find " << char_key << " in array" << endl;
      print_twod(char_twod_arr,sizes); 
    }

    if(found != true){
      cout << "FAILED: Expected to find " << char_key << " in the array" << endl;
      return false;
    }

    if(row_return != row && col_return != col){
      cout << "FAILED: Expected to find " << char_key << " at row " << row << " and col " << col << " but instead found it at row " << row_return << " and col " << col_return << endl;
      return false;   
    }
  }

  twod_arr = deallocate_twod(twod_arr, 0);
  char_twod_arr = deallocate_twod(char_twod_arr, 0);
  return true;
}

bool test_search_twod(bool debug = false){
  int sizes [] = { 6, 3, 5, 2 , 1 , -1};
  int** twod_arr = allocate_twod <int> (sizes);
  int key;
  int row;
  int col;
  string tabs = "//---------------------// \n";
  init_twod(twod_arr,sizes,-1);
  if(debug){
    cout << "Original Array: " << endl;
    print_twod(twod_arr,sizes);
  }


  //trying to find 4 in row 2 and col 1
  if(1){
    key = 4;
    row = 2;
    col = 1;
    write_twod(twod_arr,row,col,key);
    int* found = search_twod(twod_arr,sizes,key);

    if(debug){
      cout << tabs;
      cout << "Trying to find " << key << " in array" << endl;
      print_twod(twod_arr,sizes); 
    }

    int** row_w = twod_arr + row;
    int* col_w = *row_w + col;
    if(*row_w != found && *col_w != key){
      cout << "FAILED: Expected to find  " << key << " at row " << row << " and col " << col << " but instead found " << *col_w << endl;
      return false;
    }
    
  }

  //trying to find 5 in row 1 and col 2
  if(1){
    key = 5;
    row = 1;
    col = 2;
    write_twod(twod_arr,row,col,key);
    int* found = search_twod(twod_arr,sizes,key);

    if(debug){
      cout << tabs;
      cout << "Trying to find " << key << " in array" << endl;
      print_twod(twod_arr,sizes); 
    }

    int** row_w = twod_arr + row;
    int* col_w = *row_w + col;
    if(*row_w != found && *col_w != key){
      cout << "FAILED: Expected to find  " << key << " at row " << row << " and col " << col << " but instead found " << *col_w  << endl;
      return false;
    }
    
  }

  //trying to find 9 in row 4 and col 0
  if(1){
    key = 9;
    row = 4;
    col = 0;
    write_twod(twod_arr,row,col,key);
    int* found = search_twod(twod_arr,sizes,key);
    if(debug){
      cout << tabs;
      cout << "Trying to find " << key << " in array" << endl;
      print_twod(twod_arr,sizes); 
    }

    int** row_w = twod_arr + row;
    int* col_w = *row_w + col;
    if(*row_w != found && *col_w != key){
      cout << "FAILED: Expected to find  " << key << " at row " << row << " and col " << col << " but instead found " << *col_w  << endl;
      return false;
    }
  }

  //trying to find 10 in row 0 and col 0
  if(1){
    key = 10;
    row = 0;
    col = 0;
    write_twod(twod_arr,row,col,key);
    int* found = search_twod(twod_arr,sizes,key);
    if(debug){
      cout << tabs;
      cout << "Trying to find " << key << " in array" << endl;
      print_twod(twod_arr,sizes); 
    }

    int** row_w = twod_arr + row;
    int* col_w = *row_w + col;
    if(*row_w != found && *col_w != key){
      cout << "FAILED: Expected to find  " << key << " at row " << row << " and col " << col << " but instead found " << *col_w  << endl;
      return false;
    }
  }

  //trying to find a number not in the array
  if(1){
    key = 2;
    row = 4;
    col = 0;
    int* found = search_twod(twod_arr,sizes,key);
    if(debug){
      cout << tabs;
      cout << "Trying to find " << key << " in array" << endl;
      print_twod(twod_arr,sizes); 
    }

    int** row_w = twod_arr + row;
    int* col_w = *row_w + col;
    if(*col_w == key){
      cout << "FAILED: Expected to find  " << key << " at row " << row << " and col " << col << " but instead found " << *col_w  << endl;
      return false;
    }
  }




  //-----------------------//
  //testing char array
  char** char_twod_arr = allocate_twod <char> (sizes);
  char char_key;
  init_twod(char_twod_arr,sizes,'x');
  if(debug){
    cout << "Original Array: " << endl;
    print_twod(char_twod_arr,sizes);
  }

  //trying to find 'a' in the array in row 2, col 4

  if(1){
    char_key = 'a';
    row = 2;
    col = 4;
    write_twod(char_twod_arr,row,col,char_key);
    char* char_found = search_twod(char_twod_arr,sizes,char_key);
    if(debug){
      cout << tabs;
      cout << "Trying to find " << char_key << " in array" << endl;
      print_twod(char_twod_arr,sizes); 
    }

    char** row_w = char_twod_arr + row;
    char* col_w = *row_w + col;
    if(*row_w != char_found && *col_w != char_key){
      cout << "FAILED: Expected to find  " << char_key << " at row " << row << " and col " << col << " but instead found " << *col_w  << endl;
      return false;
    }
  }

  twod_arr = deallocate_twod(twod_arr, 0);
  char_twod_arr = deallocate_twod(char_twod_arr, 0);
return true;
}

bool test_get_twod(bool debug = false){
  int sizes [] = { 6, 3, 5, 2 , 1 , -1};
  int** twod_arr = allocate_twod <int> (sizes);
  int key;
  int row;
  int col;
  string tabs = "//---------------------// \n\n";
  init_twod(twod_arr,sizes,-1);
  if(debug){
    cout << "Original Array: " << endl;
    print_twod(twod_arr,sizes);
  }

  //trying to get 4 in the array at row 0, col 0 
  if(1){
    key = 4;
    row = 0;
    col = 0;
    write_twod(twod_arr,row,col,key); 

    if(debug){
      cout << tabs;
      cout << "Trying to get " << key << " in array" << endl;
      print_twod(twod_arr,sizes); 
    }

    if(get_twod(twod_arr,row,col) != key){
      cout << "FAILED: Expected to get " << key << " at row " << row << " and col " << col << " but instead found " << get_twod(twod_arr,row,col) << endl;
      return false;
    }
  }

  //trying to get 5 in the array at row 4, col 0
  if(1){
    key = 5;
    row = 4;
    col = 0;
    write_twod(twod_arr,row,col,key); 

    if(debug){
      cout << tabs;
      cout << "Trying to get " << key << " in array" << endl;
      print_twod(twod_arr,sizes); 
    }

    if(get_twod(twod_arr,row,col) != key){
      cout << "FAILED: Expected to get " << key << " at row " << row << " and col " << col << " but instead found " << get_twod(twod_arr,row,col) << endl;
      return false;
    }
  }

  //trying to get 10 in the array at row 1, col 2 
  if(1){
    key = 10;
    row = 1;
    col = 2;
    write_twod(twod_arr,row,col,key); 

    if(debug){
      cout << tabs;
      cout << "Trying to get " << key << " in array" << endl;
      print_twod(twod_arr,sizes); 
    }

    if(get_twod(twod_arr,row,col) != key){
      cout << "FAILED: Expected to get " << key << " at row " << row << " and col " << col << " but instead found " << get_twod(twod_arr,row,col) << endl;
      return false;
    }
  }



  //-------------------------//
  //testing char array

  char** char_twod_arr = allocate_twod <char> (sizes);
  char char_key;
  init_twod(char_twod_arr,sizes,'x');
  if(debug){
    cout << "Original Array: " << endl;
    print_twod(char_twod_arr,sizes);
  }

  //trying to get a in the array at row 3, col 1 

  if(1){
    char_key = 'a';
    row = 3;
    col = 1;
    write_twod(char_twod_arr,row,col,char_key);
    if(debug){
      cout << tabs;
      cout << "Trying to find " << char_key << " in array" << endl;
      print_twod(char_twod_arr,sizes); 
    }
    if(get_twod(char_twod_arr,row,col) != char_key){
      cout << "FAILED: Expected to get " << char_key << " at row " << row << " and col " << col << " but instead found " << get_twod(char_twod_arr,row,col) << endl;
      return false;
    }
    
  }  
    

  twod_arr = deallocate_twod(twod_arr, 0);
  char_twod_arr = deallocate_twod(char_twod_arr, 0);
  return true;
}

bool test_read_twod(bool debug = false){
  int sizes [] = { 6, 3, 5, 2 , 1 , -1};
  int** twod_arr = allocate_twod <int> (sizes);
  int key;
  int row;
  int col;
  string tabs = "//---------------------// \n\n";
  init_twod(twod_arr,sizes,-1);
  if(debug){
    cout << "Original Array: " << endl;
    print_twod(twod_arr,sizes);
  }

  //testing if it can read 50 at row 3, col 1
  if(1){
    key = 50;
    row = 3;
    col = 1;
    write_twod(twod_arr,row,col,key);
    if(debug){
      cout << tabs;
      cout << "Trying to read at row " << row << " and col " << col << endl;
      print_twod(twod_arr,sizes); 
    }
    int found = read_twod(twod_arr,row,col);
    if(found != key){
      cout << "FAILED: Expected to find " << key << " at row " << row << " and col " << col << " but instead found " << found << endl;
      return false;
    }
  }

  //testing if it can read 100 at row 1, col 2
  if(1){
    key = 100;
    row = 1;
    col = 2;
    write_twod(twod_arr,row,col,key);
    if(debug){
      cout << tabs;
      cout << "Trying to read at row " << row << " and col " << col << endl;
      print_twod(twod_arr,sizes); 
    }
    int found = read_twod(twod_arr,row,col);
    if(found != key){
      cout << "FAILED: Expected to find " << key << " at row " << row << " and col " << col << " but instead found " << found << endl;
      return false;
    }
  }


  //testing if it can read 150 at row 0, col 5
  if(1){
    key = 150;
    row = 0;
    col = 5;
    write_twod(twod_arr,row,col,key);
    if(debug){
      cout << tabs;
      cout << "Trying to read at row " << row << " and col " << col << endl;
      print_twod(twod_arr,sizes); 
    }
    int found = read_twod(twod_arr,row,col);
    if(found != key){
      cout << "FAILED: Expected to find " << key << " at row " << row << " and col " << col << " but instead found " << found << endl;
      return false;
    }
  }

  //testing if it can fail to read at row 0, and col 5
  if(1){
    key = -1;
    row = 0;
    col = 5;
    if(debug){
      cout << tabs;
      cout << "Trying to read at row " << row << " and col " << col << endl;
      print_twod(twod_arr,sizes); 
    }
    int found = read_twod(twod_arr,row,col);
    if(found == key){
      cout << "FAILED: Expected to not find " << key << " at row " << row << " and col " << col << " but instead did" << endl;
      return false;
    }
  }

  //-------------------------//
  //testing char array

  char** char_twod_arr = allocate_twod <char> (sizes);
  char char_key;
  init_twod(char_twod_arr,sizes,'x');
  if(debug){
    cout << "Original Array: " << endl;
    print_twod(char_twod_arr,sizes);
  }

  //trying to get a in the array at row 2, col 4 

  if(1){
    char_key = 'a';
    row = 2;
    col = 4;
    write_twod(char_twod_arr,row,col,char_key);
    if(debug){
      cout << tabs;
      cout << "Trying to find " << char_key << " in array" << endl;
      print_twod(char_twod_arr,sizes); 
    }
    char found = read_twod(char_twod_arr,row,col);
    if(found != char_key){
      cout << "FAILED: Expected to find " << char_key << " at row " << row << " and col " << col << " but instead found " << found << endl;
      return false;
    }
  }

  twod_arr = deallocate_twod(twod_arr, 0);
  char_twod_arr = deallocate_twod(char_twod_arr, 0);
  return true;
}

bool test_write_twod(bool debug = false){
  int sizes [] = { 6, 3, 5, 2 , 1 , -1};
  int** twod_arr = allocate_twod <int> (sizes);
  int key;
  int row;
  int col;
  string tabs = "//---------------------// \n\n";
  init_twod(twod_arr,sizes,-1);
  if(debug){
    cout << "Original Array: " << endl;
    print_twod(twod_arr,sizes);
  }

  //testing if it can write 0 at row 2, col 1
  if(1){
    key = 0;
    row = 2;
    col = 1;
    write_twod(twod_arr,row,col,key);
    if(debug){
      cout << tabs;
      cout << "Trying to write " << key << " at row " << row << " and col " << col << endl;
      print_twod(twod_arr,sizes); 
    }
    int found = read_twod(twod_arr,row,col);
    if(found != key){
      cout << "FAILED: Expected to find " << key << " at row " << row << " and col " << col << " but instead found " << found << endl;
      return false;
    }
  }


  //testing if it can write -4 at row 4, col 0
  if(1){
    key = -4;
    row = 4;
    col = 0;
    write_twod(twod_arr,row,col,key);
    if(debug){
      cout << tabs;
      cout << "Trying to write " << key << " at row " << row << " and col " << col << endl;
      print_twod(twod_arr,sizes); 
    }
    int found = read_twod(twod_arr,row,col);
    if(found != key){
      cout << "FAILED: Expected to find " << key << " at row " << row << " and col " << col << " but instead found " << found << endl;
      return false;
    }
  }

  //testing if it can write 10 at row 1, col 2
  if(1){
    key = 10;
    row = 1;
    col = 2;
    write_twod(twod_arr,row,col,key);
    if(debug){
      cout << tabs;
      cout << "Trying to write " << key << " at row " << row << " and col " << col << endl;
      print_twod(twod_arr,sizes); 
    }
    int found = read_twod(twod_arr,row,col);
    if(found != key){
      cout << "FAILED: Expected to find " << key << " at row " << row << " and col " << col << " but instead found " << found << endl;
      return false;
    }
  }

  //-------------------------//
  //testing char array

  char** char_twod_arr = allocate_twod <char> (sizes);
  char char_key;
  init_twod(char_twod_arr,sizes,'x');
  if(debug){
    cout << "Original Array: " << endl;
    print_twod(char_twod_arr,sizes);
  }

  //trying to get a in the array at row 0, col 1

  if(1){
    char_key = 'a';
    row = 0;
    col = 1;
    write_twod(char_twod_arr,row,col,char_key);
    if(debug){
      cout << tabs;
      cout << "Trying to write " << char_key << " at row " << row << " and col " << col << endl;;
      print_twod(char_twod_arr,sizes); 
    }
    char found = read_twod(char_twod_arr,row,col);
    if(found != char_key){
      cout << "FAILED: Expected to find " << char_key << " at row " << row << " and col " << col << " but instead found " << found << endl;
      return false;
    }
  }

  twod_arr = deallocate_twod(twod_arr, 0);
  char_twod_arr = deallocate_twod(char_twod_arr, 0);
  return true;
}

TEST(TEST_STUB, TestStub) { 
  //EXPECT_EQ(0, <your individual test functions are called here>)
  EXPECT_EQ(1, test_stub(false));
}

TEST(TEST_INIT,TestInit){
  EXPECT_EQ(1,test_init_td(false));
}

TEST(TEST_INDEX_IS_VALLID,TestIndexIsValid){
  EXPECT_EQ(1,test_index_is_valid(false));
}

TEST(TEST_SEARCH_TWOD, TestSearchTwod){
  EXPECT_EQ(1,test_search_twod(false));
}

TEST(TEST_GET_TWOD,TestGetTwod){
  EXPECT_EQ(1,test_get_twod(false));
}

TEST(TEST_READ_TWOD,TestReadTwod){
  EXPECT_EQ(1,test_read_twod(false));
}

TEST(TEST_WRITE_TWOD,TestWriteTwod){
  EXPECT_EQ(1,test_write_twod(true));
}

TEST(TEST_SEARCH_TWOD,TestSearchTwodBool){
  EXPECT_EQ(1,test_search_twod_bool(false));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

