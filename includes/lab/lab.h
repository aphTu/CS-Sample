#ifndef LAB_H
#define LAB_H
#include <iostream>
#include <fstream>
#include "../../includes/two_d_functions/two_d_functions.h"


using namespace std;

int **init_lab(int* stations);
bool login(int** labs, int lab, int station, int id);
bool logout(int** labs, int* sizes, int id);

//=======================================================================
int **init_lab(int* stations){
  int** lab = allocate_twod <int>(stations);
  init_twod(lab,stations,0);
  return lab;
}
bool login(int** labs, int lab, int station, int id){
 int current_id = read_twod(labs,lab,station);
 if(current_id == 0){
  write_twod(labs,lab,station,id);
  return true;
 }
 return false;
}
bool logout(int** labs, int* sizes, int id){
  bool found = delete_keys_twod(labs,sizes,id);
  if(found == true){
    return true;
  }
  return false;
}



#endif