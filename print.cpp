#include<iostream>
#include<vector>
#include"connect.h"
using namespace std;
void printall(vector<account*>& vec)
{
	cout << "account no	   balance" << endl;
	for (int i = 0; i < 100; i++)
		if (vec[i]->account_no != -1)
		{
			cout << i + 1001 << "	  Rs" << vec[i]->balance << endl;
		}
}