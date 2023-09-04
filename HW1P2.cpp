#include <iostream>
using namespace std;
using std::cout;
using std::cin;

int sum(int X , int Y){
    int Sum = X + Y;
    int binaryarray[8];
    int convert = Sum;
    int i = 0;
    int counter = 0;
    while (convert!= 0){
        binaryarray[i] = convert % 2;
        convert = convert / 2;
        i++;
        counter++;
    }
    for(int j = counter; j < 8;j++){
        binaryarray[j] = 0;
    }
    for(int k = counter; k >= 0 ;k--){
        cout << binaryarray[k];
    }
    return 0;
}
// Octal/hex to decimal conversion
// a)	042(octal) -> 4 * 8^1 + 2* 8^0 = 32 + 2 = 34 (decimal form)
// b)	0X42(hex) -> 4 * 16^1 + 2 * 16^0 = 64 + 2 = 66 (decimal form)
int main(){

    cout <<"====================================" << endl;
    cout << "Sajed Atwa" << " HW1P2" << " 09/06/2022 " << endl;
    cout <<"====================================" << endl;
    int t = 34;
    int r = 66;
    sum(r,t);
    return 0;
}