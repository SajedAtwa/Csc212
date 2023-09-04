#include <iostream>
#include <fstream>
#include <set>
#include <cctype>
using namespace std;
using std::cout;
using std::cin;

int main(){
    cout << "------------------------------------------------------------------------------\n";
    cout << "Name: " << "Sajed Atwa" << endl;
    cout << "FILE: " << __FILE__ << " DATE: " << __DATE__ << endl;
    cout << "------------------------------------------------------------------------------\n";
    string word;
    string worder;
    int uppercase = 0;
    ifstream myfile;
    set<string> Novel; //declares a set
    set<string, greater<string> >::iterator itr; //will allow us to go through the set
    myfile.open("sunHem.txt"); //opens the file so text can be copied from it
    while(getline(myfile, word, ' ')){   //Will fill the set up with words taken from the text file.
        Novel.insert(word);
    } 
    int uniquewrd = Novel.size(); //Sets already dont allow the same values in twice so the number of unique words is found from the size of the set
    cout << "The filled in Set: " << endl;
    for(itr = Novel.begin() ; itr != Novel.end();itr++){ // will print out all the values in the set
        cout << *itr << endl;
    }
    cout << "The number of unique words is: " << uniquewrd << endl;
    int Hist[20] = {0};
    for(int i = 0; i < 20; i++){ //will fill up the histogram based on what the length of the string is.
        for(itr = Novel.begin() ; itr != Novel.end();itr++){
            if(itr->length() == i + 1){
                Hist[i]++;
            }
        }
    }
    for(int j = 0; j < 20; j++){           //prints the histogram
        cout << "Hist[" << j << "]" << ": ";
        for(int k = 0; k <Hist[j]; k++){
            cout << "*";
        }
        cout <<endl;
    }
    for(itr = Novel.begin() ; itr != Novel.end();itr++){  //will go through the set and look for which words start with a capital letter.
        worder = *itr;
        if(isupper(worder[0])){
            uppercase++;
        }
    }
    cout << "The number of upper case words is: " << uppercase << endl;
    myfile.close(); //closes the txt file

    return 0;
}