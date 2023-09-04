#include <iostream>
#include <map>
#include <fstream>
#include <vector>
using namespace std;
using std::cout;
using std::cin;


int main(){
    cout << "------------------------------------------------------------------------------\n";  
    cout << "Name: " << "Sajed Atwa" << endl; 
    cout << "FILE: " << __FILE__ << " DATE: " << __DATE__ << endl; 
    cout << "------------------------------------------------------------------------------\n"; 
    ifstream myfile; 
    multimap<string,int> Roman;
    multimap<string,int>::iterator itr;
    string word;
    int longestword = 0;
    myfile.open("SunRises.txt"); //opens the file so text can be copied from it
    while(getline(myfile, word, ' ')){   //Will fill the map up with words taken from the text file.
        Roman.insert(pair<string,int>(word,word.length()));
    }
    cout << "The Filled up Multimap: " <<endl;
    for(itr = Roman.begin() ; itr != Roman.end();itr++){ // will print out all the values in the Map
        cout << "Key: " << itr->first << " , " << "Value: " << itr->second << endl;
    }
    for(itr = Roman.begin() ; itr != Roman.end();itr++){
        if(itr->second > longestword){
            longestword = itr->second;
        }
    }
    cout << "The value of the longest word is: " << longestword <<endl;
    vector<int> Histogram(longestword);
    for(int i = 0; i < longestword; i++){ //will fill up the histogram based on what the length of the string is.
        for(itr = Roman.begin() ; itr != Roman.end();itr++){
            if(itr->second == i + 1){
                Histogram[i]++;
            }
        }
    }
    cout << "The Histogram: " <<endl;
    for(int j = 0; j < longestword; j++){           //prints the histogram
        cout << "Hist[" << j << "]" << ": ";
        for(int k = 0; k <Histogram[j]; k++){
            cout << "*";
        }
        cout <<endl;
    }
    cout << "The Letters in roman that are longer than 9 words is: " <<endl;
    for(itr = Roman.begin() ; itr != Roman.end();itr++){ // will print out all the values in the Map that is greater than 9
        if(itr->second > 9){
            cout << "Key: " << itr->first << " , " << "Value: " << itr->second << endl;
        }
    }
    return 0;
}