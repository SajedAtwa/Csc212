#include <iostream>
#include <cstdlib>
using namespace std;
using std::cout;
using std::cin;

void Populate(int &M_ptr[0], int row, int col){
    //int seed;
    //int RV;
    srand(19);
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            M_ptr[i][j] = rand() % 60;
        }
    }
}

int main(){
    int row = 8;
    int col = 12;
    int M[8][12];		//2D matrix declaration 
    int *M_ptr[8];		//array of int pointers to rows 
    for(int cnt = 0; cnt < 8; cnt++){ 
        M_ptr[cnt] = &M[cnt][0]; 
    }
    Populate(&M_ptr[0],row,col);
    for(int i = 0; i < row ; i++){
        for(int j = 0; j < col; j++){
            cout << M[i][j];
        }
        cout <<endl;
    }
    
    return 0;
};