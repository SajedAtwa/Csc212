#include <iostream>
#include <cstring>
using namespace std;
using std::string;
using std::cout;
using std::cin;

int main(){
    cout << "Sajed Atwa" << " FILE: " << __FILE__ << " DATE: " << __DATE__ << " CSC 21200 LM24126" << endl;
    string word1;
    string word2;
    cout <<"Enter first word: "<< endl;  
    cin >>word1;
    cout <<"Enter second word: "<< endl;
    cin >>word2;         //This gets input from the user 
    int len1 = word1.size();
    int len2 = word2.size();
    if(len1 == len2){    //This will compare the lengths of the two words because words cannot be anagrams if they are not equal length
        sort(word1.begin(), word1.end());
        sort(word2.begin(), word2.end()); 
        if(word1 == word2){  //This will compare the sorted words to see if they have the same characters to check if they are anagrams
            cout <<"The words are anagrams"<<endl;
        }else{
            cout <<"The words are not anagrams"<<endl;
        }
    }else{     
        cout <<"The words are not anagrams"<<endl;
    }
    return 0;
}
