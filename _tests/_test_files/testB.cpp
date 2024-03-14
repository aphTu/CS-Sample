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

init_twod(twod_arr,sizes,-1);
if(debug){
  cout << "Original Array: ";
  print_twod(twod_arr,sizes);
}

//checking num 4 in row 2, col 1
if(1){
  key = 4;
  row = 2;
  col = 1;
  
  write_twod(twod_arr,row,col,key);
  print_twod(twod_arr,sizes);
  int found = search_twod(twod_arr,sizes, key, row, col);
  if(debug){
    cout << "Checking if number " << key << " in row " << row << " and colum " << col << endl;
    print_twod(twod_arr,sizes);
  }

  if(found != true){
    cout << "FAILED: Expected to find num " << key << " in row " << row << " and column " << col << " but it is not there" << endl; 
  }
}

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

TEST(TEST_SEARCH_TWOD, TestSearchTwod_bool){
  EXPECT_EQ(1,test_search_twod_bool(true));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

