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


TEST(TEST_STUB, TestStub) { 
  //EXPECT_EQ(0, <your individual test functions are called here>)
  EXPECT_EQ(1, test_stub(false));
}

TEST(TEST_INIT,TestInit){
  EXPECT_EQ(1,test_init_td(false));
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

