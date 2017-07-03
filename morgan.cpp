#include<iostream>
#include<string>
#include<vector>
#include"morg.h"
using namespace std;
order::order(string ordid, double pri, int sha, int si) {
	orderid = ordid;
	price = pri;
	share = sha;
	side = si;

}
void order::checkorderbook(map<int, vector<double>> ma1, map<int, vector<double>> ma2) {
	map<int, vector<double>>::iterator it1;
	map<int, vector<double>>::iterator it2;
	cout << "BUY ORDERS" << endl;
	for (it1 = ma1.begin(); it1 != ma1.end(); it1++) {
		for (int i = 0; it1->second.size(); i++) {
			cout << it1->first << "  " << it1->second[i] << endl;
		}
	}
	cout << "SALE ORDERS" << endl;
	for (it2 = ma2.begin(); it2 != ma2.end(); it2++) {
		for (int j = 0; it2->second.size(); j++) {
			cout << it2->first << "  " << it2->second[j] << endl;
		}
	}
}
