#include <iostream>
#include <cstdlib>
using namespace std;
using std::cout;
using std::cin;

void Populate(int *M_ptr[], int row, int col){   //Fills up the matrix
    unsigned int seed = 19;
    srand(seed);  //Primes the random generator with a seed value of 19   
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            M_ptr[i][j] = rand() % 60; //This will assign a random value between 0 and 60 to each index of the matrix
        }
    }
}

void YearAvrg(int *M_ptr[], int row, int col){  //This function will add the rain values of each year and divide them by 12 to find the average rain value per year
    float ave = 0;
    cout << "The Yearly Averages: " << endl;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            ave += M_ptr[i][j];
        }
        ave = ave /12;
        cout << "The average for year " << i + 1 <<  " is: " << ave << endl;
        ave = 0;
    }
}
void MonthAvrg(int *M_ptr[], int row, int col){  //This code will add the rain values of each month throughout 8 years and divide each of those values by 8 to find the average of each month.
    float ave = 0;
    float months[12]= {0,0,0,0,0,0,0,0,0,0,0,0};
    cout << "The monthly averages: " << endl;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            months[j] = months[j] + M_ptr[i][j];
        }
    }
    for(int k = 0; k < 12 ; k++){
        ave = months[k] / 8;
        cout << "The average of month " << k + 1 << " is: " << ave << endl;
        ave = 0;
    }
    
}

int main(){
    cout << "------------------------------------------------------------------------------\n";
    cout << "Name: " << "Sajed Atwa" << endl;
    cout << "FILE: " << __FILE__ << " DATE: " << __DATE__ << endl;
    cout << "------------------------------------------------------------------------------\n";
    int row = 8;  
    int col = 12;
    int yearthree = 0;
    int M[8][12];		//2D matrix declaration 
    int *M_ptr[8];		//array of int pointers to rows 
    for(int cnt = 0; cnt < 8; cnt++){ 
        M_ptr[cnt] = &M[cnt][0]; 
    }
    Populate(&M_ptr[0],row,col);
    cout << "The filled matrix: " << endl; //This chunk will print out the filled matrix
    for(int i = 0; i < row ; i++){
        for(int j = 0; j < col; j++){
            cout << *((M_ptr[i]+j)) << '\t'; 
        }
        cout << endl;
    }
    for(int h = 0; h < col; h++){  //This will add all the rain values for the 3rd year.
        yearthree += M_ptr[2][h];
    }
    YearAvrg(&M_ptr[0],row,col);
    MonthAvrg(&M_ptr[0],row,col);
    cout << "The total rainfall for year 3 is: " << yearthree << endl;
    return 0;
};