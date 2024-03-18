#ifndef PLANE_APP_H
#define PLANE_APP_H
#include "../../includes/plane/plane.h"
void menu_plane(bool** plane);
void choice_r(bool** plane);
void choice_c(bool** plane);

//-----------------------------------//

void menu_plane(bool** plane){
 char choice;
  string tabs = "\n//-------------------------//\n";
  cout << setw(20) <<"Welcome to PLANE program" << endl;
  do{
    cout << tabs;
    cout << setw(6)<< "[R]eserve a spot, [C]anceled a reservation, or [E]xit"<< endl;
    cout << setw(6) << "Please enter what you would like to do: ";
    cin >> choice;
    switch(choice){
      case 'r':
      case 'R':
        choice_r(plane);
        break; 
      case 'c':
      case 'C':
        choice_c(plane);
        break;
      case 'e':
      case 'E':
        return;
        break;
      default:
        cout << "\nThat not a valid command, please enter a different one"<< endl;
    }
  } while (choice != 'e' || choice != 'E'); 
}

void choice_r(bool** plane){
  int row, seat;
  const bool debug = true;
  cout << "\nWhat row & seat would you like to reserve?" << endl;
  
  do {
    cout << "Enter the row & seat number: ";
    cin >> row >> seat;
    
    if(debug){
      cout << "row: " << row << ", seat: " << seat;
      cout << endl;
    }
    bool valid = false;
    if(row < 7 && seat < 4){
      valid = true;
    }

    if(valid == false){
      cout << "\nPlease enter a valid row and/or seat" << endl;
      continue;
    }

    bool logged_in = reserve(plane,row,seat);
    if(debug){
      cout << "plane are: \n";
      print_plane(plane);
    }
    if(logged_in == true){
      cout << "Successfully reserve row " << row;
      cout << ", seat "<< seat << endl;
      cout << "Bringing user back into main program\n";
      break;
    } else{
      cout << "The row and/or seat is occupied. ";
      cout << "Please choose a different one" << endl;
      continue;
    }
  } while (1);
}

void choice_c(bool** plane){
   int row, seat;
  char cont;
  const bool debug = true;
  cout << "\nWhat row & seat would you like to cancel the reservation of?" << endl;
  
  do {
    cout << "Enter the row & seat you would like to cancel: ";
    cin >>row>>seat;
    

    bool canceled = cancel(plane,row,seat);
    if(debug){
      cout << "seats are: \n";
      print_plane(plane);
    }
    if(canceled == true){
      cout << "Successfully canceled row "<< row;
      cout << " & seat " << seat << endl;
      cout << "Bringing user back into main program\n";
      break;
    } else{
      cout << "The row & seat is not reserve\n";
      cout << "Please input the correct row & seat you wishes to [c]ancel";
      cout << " or [e]xit to main program: "; 
      cin >> cont;

      if(cont == 'E' || cont == 'e') {
        cout << "\nExiting to main program\n"; 
        break;
      }    
      continue;
    }
  } while (1);
}

#endif