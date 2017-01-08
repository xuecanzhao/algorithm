
#include <iostream> 
#include<string>
#include<vector>
using namespace std;


int calculateMax(vector<int> prices) {
	int firstBuy = INT_MIN, firstSell = 0;
	int secondBuy = INT_MIN, secondSell = 0;

	for (int curPrice : prices) {
		if (firstBuy < -curPrice) firstBuy = -curPrice; // the max profit after you buy first stock
		if (firstSell < firstBuy + curPrice) firstSell = firstBuy + curPrice; // the max profit after you sell it
		if (secondBuy < firstSell - curPrice) secondBuy = firstSell - curPrice; // the max profit after you buy the second stock
		if (secondSell < secondBuy + curPrice) secondSell = secondBuy + curPrice; // the max profit after you sell the second stock
	}

	return secondSell;
}
int main()
{
	vector<int> prices;
	prices.push_back(5);
	prices.push_back(15);
	prices.push_back(56);
	prices.push_back(26);
	prices.push_back(62);
	prices.push_back(65);
	prices.push_back(57);
	prices.push_back(69);
	cout << calculateMax(prices) << endl;
}