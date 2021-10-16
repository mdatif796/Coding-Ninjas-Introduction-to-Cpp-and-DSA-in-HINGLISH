#include<iostream>
#include<cmath>
using namespace std;

int main() {
	// Write your code here
	int basicSalary; float totalSalary;
    char grade;
    cin >> basicSalary >> grade;
    float hra = (20 * basicSalary)/100.0;
    float da = (50 * basicSalary)/100.0;
    float pf = (11 * basicSalary)/100.0;
    if(grade == 'A'){
        totalSalary = basicSalary + hra + da + 1700 - pf;
    } else if(grade == 'B'){
        totalSalary = basicSalary + hra + da + 1500 - pf;
    } else {
        totalSalary = basicSalary + hra + da + 1300 - pf;
    }
    int salary = round(totalSalary);
    cout << salary << endl;
}