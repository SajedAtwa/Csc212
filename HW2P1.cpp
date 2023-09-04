#include <iostream>
#include <string>
#include <cctype>
using namespace std;
using std::cout;
using std::cin;

class String{
    private:
        string Word;

    public:
        void setWord(string g);
        string getWord() const{
            return Word;
        }
        string reverser(string c);
        void palindrome(string Q);
 
};
void String::setWord(string g){
    Word = g;
}

string String::reverser(string h){
    string drow;
    for(int i = Word.length() - 1; i >= 0; i--){
                drow = drow + Word[i];
            }

    return drow;
}

void String::palindrome(string drow){
    if(drow ==  Word){
        cout << "The String is a palindrome " << endl;
    }else{
        cout << "The String is not a palindrome " << endl;
    }
}

int main(){
    cout << "Sajed Atwa" << " FILE: " << __FILE__ << " DATE: " << __DATE__ << endl;
    String word1;
    string input1;
    cout <<"Enter a string: " << endl;
    getline(cin,input1);
    word1.setWord(input1);
    string word = word1.getWord();
    string wordreverse = word1.reverser(word);
    word1.palindrome(wordreverse);
    return 0;
}