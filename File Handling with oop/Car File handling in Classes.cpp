#include<iostream>
using namespace std;
const int SIZE = 2;
#include<string>
#include<fstream>
class Car {
private:
	int reg_no;
	char owner_name[30];
	char color[10];
public:
	Car()
	{
		reg_no = 123;
		strcpy_s(owner_name, "Adnan");
		strcpy_s(color, "Black");
	}
	Car(int r, char on[], char c[])
	{
		reg_no = r;
		strcpy_s(owner_name,on);
		strcpy_s(color,c);
	}
	void Display()
	{
		cout << "Registeration No:" << reg_no << endl<<"Owner Name:" 
			<< owner_name << endl<<"Color:" << color << endl;
	}
	void WFile(fstream& file, Car& c)
	{
		file.write((char*)&c, sizeof(c));
	}
	void InputData()
	{
		cout << "Enter Registeration Number:" << endl;
		cin >> reg_no;
		cin.ignore();
		cout<< "Enter Owner Name:" << endl;
		cin.get(owner_name,30);
		cin.ignore();
		cout << "Enter the Car Color:" << endl;
		cin.get(color, 10);
	}
};
int main()
{
	Car c1,c2;
	
	fstream fileA("A.dat", ios::binary | ios::out);
	fstream fileB("B.dat", ios::binary | ios::out);
	cout << "Storing Data in File A" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << "Student" << i + 1 << " \tDetails" << endl;
		c1.InputData();
		c1.WFile(fileA,c1);
	}
	fileA.close();
	cout << "Storing Data in File B" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << "Student" << i + 1 << " \tDetails" << endl;
		c1.InputData();
		c1.WFile(fileB, c1);
	}
	fileB.close();
	//writting data of A
	fstream fileS("S.dat", ios::binary | ios::out);
	fileA.open("A.dat", ios::binary | ios::in);
	while (fileA.read((char*)&c2, sizeof(c2)))
	{
		fileS.write((char*)&c2, sizeof(c2));
	}
	//fileA.close();
	fileS.close();
	//writing data of B
	fileB.open("B.dat", ios::binary | ios::in);
	fileS.open("S.dat", ios::binary | ios::app);
	while(fileB.read((char*)&c2, sizeof(c2)))
	{
		fileS.write((char*)&c2, sizeof(c2));
	}
	fileS.close();
	//Reading data from S File
	cout << "+++++++++++++++++++++++++++++" << endl;
	cout << "Reading Data From file" << endl;
	fileS.open("S.dat", ios::binary | ios::in);
		while (fileS.read((char*)&c2, sizeof(c2)))
		{
			
			c2.Display();
	    }
	
		
		fileS.close();
	return 0;
}