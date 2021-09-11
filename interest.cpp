#include<iostream>
#include<vector>
#include"connect.h"
using namespace std;
void interest(vector<account*>& vec, int rate)
{
	cout << "for one year these are the simple interests :" << endl;
	for (int i = 0; i < 100; i++)
		if (vec[i]->account_no != -1)
		{
			double ans = vec[i]->balance * rate * 1 / 100;
			cout << ans << endl;
		}
}