#include<iostream>
#include <fstream>  
#include<string>
#include<map>
using namespace std;


bool issuffix(string s1, string s2) {
	int a = s1.length();
	int b = s2.length();
	if (a > b) { return 0; }
	else {
		int count = 0;
		for (int i = 0; i < a; i++) {
			if (s1[i] == s2[b - a + i]) { count++; }
		}
		if (count == a) { return 1; }
		else { return 0; }
	}
}

int main() {
	map<string, int>   wordMap;
	int   i = 0;
	string suffix;
	cout << "please input the suffix:";
	cin >> suffix;

	ifstream infile("EnglishWords.txt");
	string  str;
	int p;
	
	while (getline(infile,str))
	{
		if (issuffix(suffix, str) == 1)
			wordMap[suffix] = i;
			i++;
			cout << str<<endl;
	}
	cout << wordMap[suffix]<<endl;
	cin.get();
	cin.get();
	return 0;

}