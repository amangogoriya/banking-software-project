#ifndef Connector
#define Connector
#include<iostream>
using namespace std;
struct account {
	int account_no = -1; double balance;
	int pin;
	account* next = NULL;
};
void printall(vector<account*>& vec);
void interest(vector<account*>& vec, int rate);
void close(vector<account*>& vec, int account_no);
void open(vector<account*>& vec, int balance, int pin);
#endif
