#ifndef TWO_D_FUNCTIONS
#define TWO_D_FUNCTIONS
#include <iostream>
#include <fstream>

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


//=======================================================================


int array_size(int* sizes){

}
void print_array(int* a){

}
bool index_is_valid(int* sizes, int row, int col){

}



//To call: int** p = allocate_twod<int>(sizes_array)  

template <class T>
T** allocate_twod(int* sizes){

}

template <class T>
T** deallocate_twod(T** twod, int size){

}

template <class T>
T read_twod(T** twod, int row, int col){

}

template <class T>
void write_twod(T** twod, int row, int col, const T& item){

}

template <class T>
T& get_twod(T** twod, int row, int col){

}

template<class T>
void init_twod(T** twod, int* sizes, T init_item){

}

template<class T>
bool search_twod(T** twod, int* sizes, const T& key, int& row, int& col){

}

//return a pointer to the item if found, nullptr if not found: 
//                                                 (Ms. Barskhian)
template<class T> 
T* search_twod(T** twod, int* sizes, const T& key){

} 

template <class T>
ostream& print_twod(T** twod, int* sizes, ostream& outs){

}


#endif