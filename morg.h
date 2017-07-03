#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
class order
{
public:
	order(string orderid, double price, int share, int side);
	void checkorderbook(map<int,vector<double>> ma1, map<int, vector<double>> ma2);

private:
	string orderid;
	double price;
	int share;
	int side;
};