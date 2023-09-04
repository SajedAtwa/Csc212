#include <iostream>
#include <string>
using namespace std;
using std::cout;
using std::cin;

int Days_in_each_month[12]
    = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // amount of days in each month


class Date{ //parent class
    protected:
        int month;
        int day;
        int year;

    public:
        Date(){
            month = 9;
            day = 20;
            year = 2022;
        };
        void arraydate(int date[3]);
        ~Date(){};




};

void Date::arraydate(int date[3]){  //This will display the date.
    date[0] = month;
    date[1] = day;
    date[2] = year;
    cout << "The date is: " << date[0] << "/" << date[1] << "/" << date[2] << endl;
}

class Employee: Date{ //composed class
    private:
        string name;
        float salary;
        int date_of_birth[3];
    public:
    Employee(){   //default constructor
        name = "George";
        salary = 75000.25;
        date_of_birth[0] = 6;
        date_of_birth[1] = 10;
        date_of_birth[2] = 1998;
    };
    Employee(string nam, float sal, int m, int d, int y){  //paramerterized constructor
        name = nam;   
        salary = sal;
        date_of_birth[0] = m; 
        date_of_birth[1] = d;
        date_of_birth[2] = y;
    }
    void say_employee();
    int days_of_date();
    int days_of_birth();
    int dif_between_dates(int a, int b);
    ~Employee(){};
};

void Employee::say_employee(){ 
    cout << "Hello my name is " << name << " and I make a salary of " << salary << " and i was born on " << date_of_birth[0] << "/" << date_of_birth[1] << "/" << date_of_birth[2] << endl;
}

int Employee::days_of_date(){  //This will calculate the amount of days in the date given by the date class
    int days2 = (year * 365) + day;
    int numleap1;
    int monthcounter1 = 0;
    while(monthcounter1 != month -1){  //will add days for each month that passed
       days2 += Days_in_each_month[monthcounter1]; 
        monthcounter1++;
    }
    if(month<= 2){ //If the month of the date doesnt go past feburary then it wont make a difference if the year is a leap year or not
        year--;
    }
    numleap1 = (year / 4) - (year / 100) + (year / 400); // A year is a leap year if it is evenly divisble by 4, years that are evenly divisble by 100 are not leap years, if they are evenly divisble by 400 then it is a leap year.
    days2 += numleap1; //leap years have an extra day compared to regular years so add 1 for each leap year
    return days2;
}

int Employee::days_of_birth(){   //This will calculate the amount of days in the emoloyees date of birth
    int days1 = (date_of_birth[2] * 365) + date_of_birth[1];
    int numleap2;
    int monthcounter2 = 0;
    while(monthcounter2 != date_of_birth[0]- 1){
        days1 += Days_in_each_month[monthcounter2];
        monthcounter2++;
    }
    if(date_of_birth[0]<= 2){
        date_of_birth[2]--;
    }
    numleap2 = (date_of_birth[2] / 4) - (date_of_birth[2] / 100) + (date_of_birth[2] / 400);
    days1 += numleap2;
    return days1;
}

int Employee::dif_between_dates(int days1, int days2){ //this will subtract the amount of days of the date given and the days of the date of birth to find the difference 
    int daystotal = days2 - days1;
    return daystotal;
}

int main(){
    cout << "Sajed Atwa" << " FILE: " << __FILE__ << " DATE: " << __DATE__ << " CSC 21200 LM24126" << endl;
    int days1;
    int days2;
    int daystotal;
    int date[3];
    string name;
    float salary;
    int m;
    int d;
    int y;
    cout << "enter a name: ";
    cin >> name;
    cout << "enter a salary: ";
    cin >> salary;
    cout << "enter the number of the month of birth: ";
    cin >> m;
    cout << "enter day of birth: ";
    cin >> d;
    cout << "enter year of birthday: ";
    cin >> y;  
    Date date1;   //class calls
    date1.arraydate(date);
    Employee employ1(name,salary,m,d,y);
    employ1.say_employee();
    days2 = employ1.days_of_date();
    days1 = employ1.days_of_birth();
    daystotal = employ1.dif_between_dates(days1,days2);
    cout << "the difference between the days is: " << daystotal << endl;
    return 0;
}