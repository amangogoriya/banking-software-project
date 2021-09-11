#include<iostream>
#include<vector>
#include"connect.h"
using namespace std;
void close(vector<account*>& vec, int account_no)
{
	int i = account_no - 1001;
	account* temp = new account();
	temp->next = vec[i];
	vec[i] = temp;
	cout << "account is closed" << endl;
}