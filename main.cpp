#include <iostream>
#include <iomanip>
#include "includes/lab_app/lab_app.h"
#include "includes/plane_app/plane_app.h"

using namespace std;

int main(int argv, char** argc) {
  int stations [] = {6,2,1,7,2,4,-1};
  int** labs = init_lab(stations);
  menu_lab(labs,stations);

  bool** plane = init_plane();

  menu_plane(plane);

}
