#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class student {
	int Roll_No;
	string Name;
	int Semester;
public:

	void InputData() {
		cout << "+++++Input Student Details++++" << endl;
		cout << "Enter the Roll Number:" << endl;
		cin >> Roll_No;
		cin.ignore();
		cout << "Enter Name:" << endl;
		getline(cin, Name);

		cout << "Enter Semester:" << endl;
		cin >> Semester;
	}
	void DisplayData()
	{
		cout << "+++Student Details are:" << endl;
		cout << "Roll Number:" << Roll_No << endl;
		cout << "Name:" << Name << endl;
		cout << "Semester:" << Semester << endl;
	}

};

int main()
{
	student s1;
	s1.InputData();
	s1.DisplayData();
	return 0;
}