#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class student {
	int Roll_No;
	string Name;
	int Semester;
public:
	
	student()
	{
		Roll_No = 1;
		Name = "No_Data";
		Semester = 0;
	}
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
	void FileRead(fstream& f, student& s)
	{
		while (f.read((char*)&s, sizeof(s))) {
			
			cout << "name:" << s.Name << endl << "roll no:" << s.Roll_No << endl <<
				"semester:" << s.Semester << endl;
		}
		


	}
	void FileWrite(fstream& f, student& s)
	{
		f.write((char*)&s, sizeof(s));
	}


};

int main()
{
	student s1, s2;

	cout << "Writting on file" << endl;
	fstream file("data.dat", ios::binary | ios::out);
	s1.InputData();
	s1.FileWrite(file, s1);
	file.close();
	//cout << "Following data Written Successfully" << endl;
	//s1.DisplayData();
	cout << "Reading from file" << endl;
	file.open("data.dat", ios::binary | ios::in);
	//s1.InputData();
	//file.write((char*)&s1, sizeof(s1));
	s2.FileRead(file,s2);

	s2.DisplayData();
	file.close();
	return 0;
}
