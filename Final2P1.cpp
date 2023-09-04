#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
using std::cout;
using std::cin;



int main(){
    cout << "------------------------------------------------------------------------------\n";  
    cout << "Name: " << "Sajed Atwa" << endl; 
    cout << "FILE: " << __FILE__ << " DATE: " << __DATE__ << endl; 
    cout << "------------------------------------------------------------------------------\n"; 
    string fruitArr[20] = {"pear", "banana", "apple", "fig", "date", "watermelon", "guava", "grape", "berry", "orange", "blueberry" , "mimosa", "mango", "mandarin", "grapefruit", "lemon", "lime", "papaya", "peach", "eldenberry"}; //Array of the fruits
    map<string,int> Fruit;
    map<string,int>::iterator itr;
    vector<int> Sum;
    int value;
    int mean;
    for(int i = 0; i < 20; i++){ //Will populate the map with the fruits and their word length
        Fruit.insert(pair<string,int>(fruitArr[i],fruitArr[i].length()));
    }
    for(itr = Fruit.begin() ; itr != Fruit.end();itr++){ // will print out all the values in the Map
        cout << "Key: " << itr->first << " , " << "Value: " << itr->second << endl;
    }
    cout << "Fruits with a word length greater than 5: " << endl;
    for(itr = Fruit.begin() ; itr != Fruit.end();itr++){ // will print out all the values in the Map that have a length less than 5
        if(itr->second > 5){
            cout << "Key: " << itr->first << " , " << "Value: " << itr->second << endl;
        }
    }
    for(itr = Fruit.begin() ; itr != Fruit.end();itr++){ //Will add up the characters of each element of the map and add it to the vector
        for(int j = 0; j < itr->second; j++){
            value += itr->first[j];
        }
        Sum.push_back(value);
        value = 0;
    }
    cout << "Vector of the Sums: " <<endl;  //will print out the vector
    for(int k = 0; k < 20; k++){
        cout << Sum[k] << endl;
    }
    for(int w = 0; w < 20; w++){  //This chunk will add the sum values of the vector and find its total average
        mean += Sum[w];
    }
    mean = mean/20;
    cout << "The mean is: " << mean <<endl;
    cout << "The Fruits with values less than the mean are: " <<endl; //This will print out the fruits with a numerical value that is less than mean.
    for(itr = Fruit.begin() ; itr != Fruit.end();itr++){
        for(int j = 0; j < itr->second; j++){
            value += itr->first[j];
        }
        if(value < mean){
            cout << "Key: " << itr->first << " , " << "Value: " << itr->second << endl;
        }
        value = 0;
    }
    return 0;
}