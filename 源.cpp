#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	ifstream infile;
	infile.open("test.in", ios::in);
	string str;
	while (getline(infile, str))
	{
		cout << str << endl;
	}


	cin.get();
	return 0;

}