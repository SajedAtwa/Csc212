#include <iostream>
using namespace std;
using std::cout;
using std::cin;

int averagearray(int *array, int size){
    int average;
    int sum = 0;
    for(int i = 0; i <= size -1; i++){
        int y = *array;
        sum = sum + y;
        array = array + 1;
    }
    average = sum / size;
    return average; 
}


int main(){
    cout << "Sajed Atwa" << " FILE: " << __FILE__ << " DATE: " << __DATE__ << endl;
    int array1[8] = {5,6,7,2,4,9,16,7};
    int size = 8;
    int *array = &array1[0];
    int answer = averagearray(array,size);
    cout << "The average of the array is: " << answer << endl;
    return 0;
}

