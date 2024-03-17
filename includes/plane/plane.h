#ifndef PLANE_H
#define PLANE_H
#include <iostream>
#include "../../includes/two_d_functions/two_d_functions.h"

using namespace std;

bool **init_plane();
bool reserve(bool **plane, int row, int seat);
bool cancel(bool** plane, int row, int seat);
void print_plane(bool **plane);


//=======================================================================
bool **init_plane(){
  int sizes[] = {4,4,4,4,4,4,4,-1};
  bool** plane = allocate_twod <bool> (sizes);
  init_twod(plane, sizes, false);
  return plane;
}
bool reserve(bool **plane, int row, int seat){
  bool **plane_w = plane;
  bool found = read_twod(plane_w, row, seat);
  if(found == false){
    write_twod(plane_w,row,seat, true);
    return true;
  }
  return false;
}
bool cancel(bool** plane, int row, int seat){
  bool **plane_w = plane;
  bool found = read_twod(plane_w, row, seat);
  if(found == true){
    write_twod(plane_w,row,seat,false);
    return true;
  }
  return false;
}
void print_plane(bool **plane){
  bool** row_w = plane;
  bool * col_w;
  char seats[] = "ABCD";
  cout << "   ";
  for(int m =0;m<4;m++){
    char* seats_w = seats+m;
    cout << setw(6)<<*seats_w;
  }
  cout << endl;
  for(int i = 0; i<7;i++){
    cout << "["<< i + 1 << "]";
    col_w = *row_w;
    for(int j =0; j<4;j++){
      if(*col_w == false){
        char* seats_w = seats + j;
        cout << setw(6) << *seats_w;
      } else{
        cout << setw(6) << 'X';
      }
      col_w++;
    }
    row_w++;
    cout << endl;
  }
}


#endif