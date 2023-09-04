#include <iostream>
#include <string>
#include <cstring>
using namespace std;
using std::cout;
using std::cin;

int main(){
    cout << "Sajed Atwa" << " FILE: " << __FILE__ << " DATE: " << __DATE__ << " CSC 21200 LM24126" << endl;
    int linecnter;
    int totalvalue = 0;
    cout << "enter how many lines you want to enter: "<<endl;
    cin >> linecnter;
    int cnt[linecnter];  //This will give the output array a size depending on how mnay lines the user wants to input.
    for(int i = 0; i < linecnter +1 ;i++){  //this will allow the code to get input from the user, line by line.
        char Phrase[250] = {'\0'};
        cin.getline(Phrase, 250,'\n');        //This will get user input and put into into the c string.
        cout << "line " << i+1<<":" << endl;
        int len = strlen(Phrase); //this will get the size of the c string
        int value = 0;
        for(int j = 0; j < len - 1;j++){ //this will get the total ascii value of the entire c string
            value += int(Phrase[j]);
        }
        cnt[i] = value;  //this will put the total ascii value into the output array
    }
    for(int k = 1; k <=linecnter; k++){ //this will output every element of the array.
        cout << cnt[k] <<endl;
    }
    return 0;
}