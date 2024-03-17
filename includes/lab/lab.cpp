#include <iostream>
#include <iomanip>
#include "lab.h"

using namespace std;

void menu(int** labs, int*sizes);
void choice_i(int** labs, int* sizes);


void menu(int** labs, int* sizes){
  char choice;
  string tabs = "\n//-------------------------//\n";
  cout << setw(20) <<"Welcome to LAB program" << endl;
  do{
    cout << tabs;
    cout << setw(6)<< "Log[i]n, Log[o]ut, or [E]xit"<< endl;
    cout << setw(6) << "Please enter what you would like to do: ";
    cin >> choice;
    switch(choice){
      case 'i':
      case 'I':
        choice_i(labs,sizes);
        break; 
      case 'o':
      case 'O':
        break;
      case 'e':
      case 'E':
        return;
        break;
      default:
        cout << "That not a valid command, please enter a different one"<< endl;
    }
  } while (choice != 'e' || choice != 'E');
}

void choice_i(int** labs, int* sizes){
  int lab, station, id;
  bool occupied, not_valid;
  const bool debug = true;
  cout << "\nWhat lab station would you like to login?" << endl;
  
  do {
    //--------------------------------//
    
    //long version

    // cout << "Enter the lab number: ";
    // cin >> lab;
    // cout << "Enter the station number: ";
    // cin >> station;
    // cout << "Enter id number: ";
    // cin >> id;

    //--------------------------------//
    cout << "Enter the lab number, station number, and id number: ";
    cin >> lab>>station>> id;
    
    if(debug){
      cout << "lab: " << lab << ", station: " << station;
      cout << ", id: " << id << endl;
    }
    bool valid = index_is_valid(sizes,lab,station);

    if(valid == false){
      cout << "\nPlease enter a valid lab and/or station" << endl;
      continue;
    }

    bool logged_in = login(labs,lab,station,id);
    if(debug){
      cout << "labs are: \n";
      print_twod(labs,sizes);
    }
    if(logged_in == true){
      cout << "Successfully login into lab " << lab;
      cout << ", station "<< station << endl;
      cout << "Bringing user back into main program\n";
      break;
    } else{
      cout << "The lab and/or station is occupied. ";
      cout << "Please choose a different one" << endl;
      continue;
    }
  } while (1);
}