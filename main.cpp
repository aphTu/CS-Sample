#include <iostream>
#include <iomanip>
#include "includes/lab_app/lab_app.h"

using namespace std;

int main(int argv, char** argc) {
  int stations [] = {6,2,1,7,2,4,-1};
  int** labs = init_lab(stations);
  menu(labs,stations);

}
