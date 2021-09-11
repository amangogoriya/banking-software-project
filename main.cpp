#include<iostream>
#include<vector>
#include "connect.h"
using namespace std;



int main()
{
	int pinformanager = 111111;
	vector<int> atm(10, 1000);
	vector<account*> vec;
	for (int i = 0; i < 100; i++)
	{
		account* p = new account();
		vec.push_back(p);
	}
	int check = 0;
	while (1)
	{
		cout << "Transaction Type?" << endl;
		char transtype; cin >> transtype;

		if (transtype == 'S') {
			cout << "enter pin  "; int pin; 
			cin >> pin;
			if (pin == pinformanager) check = 1;
			continue;
		}
		if (!check)	cout << "bank is closed" << endl;
		else
			switch (transtype)
			{
			case 'O': {cout << "Initital deposit?" << endl; double value; 
				cin >> value;
				cout << "PIN?" << endl; int pin; cin >> pin;
				int check = 0;
				for (int i = 0; i < 100; i++)
					if (vec[i]->account_no == -1) { check = 1; break; }
				if (!check) cout << "we cannot open another account limit is reached" << endl;
				else open(vec, value, pin); }
					break;
			case 'B': {cout << "Account number?" << endl; int account_no; cin >> account_no;
				cout << "PIN" << endl; int pin; 
				cin >> pin;
				if (vec[account_no - 1000 - 1]->account_no == -1 || pin != vec[account_no - 1000 - 1]->pin) cout << "not allowed. please recheck the credentials" << endl;
				else { cout << "yout account no:" << account_no << "\navailable balance: Rs" << vec[account_no - 1001]->balance << endl; }
			}
					break;
			case 'D': {cout << "Account number?" << endl; int account_no; cin >> account_no;
				cout << "PIN" << endl; int pin; cin >> pin; cout << "deposit amount" << endl; double value; cin >> value;
				if (vec[account_no - 1000 - 1]->account_no == -1 || pin != vec[account_no - 1000 - 1]->pin) cout << "Access denied" << endl;
				else {
					vec[account_no - 1001]->balance += value;
					cout << "yout account no is:" << account_no << "\navailable balance: Rs" << vec[account_no - 1001]->balance << endl;
				}
			}
					break;
			case 'W': {cout << "Account number?" << endl; int account_no; cin >> account_no;
				cout << "PIN" << endl; int pin; cin >> pin; cout << "withdrawal amount" << endl; double value; cin >> value;
				cout << "choose ATM: \nATM1\nATM2\nATM3\nATM4\nATM5\nATM6\nATM7\nATM8\nATM9\nATM10" << endl;
				int atmnumber; cin >> atmnumber;
				if (atmnumber > 10 || atmnumber < 1) {cout<<"invalid"; break; }
				if (value > atm[atmnumber - 1]) { cout << "machine does not have enough money" << endl; break; }
				else
					if (vec[account_no - 1000 - 1]->account_no == -1 || pin != vec[account_no - 1000 - 1]->pin || vec[account_no - 1001]->balance < value) cout << "not allowed.(balance might be low)" << endl;
					else {
						vec[account_no - 1001]->balance -= value;
						atm[atmnumber - 1] -= value;
						cout << "yout account no is:" << account_no << "\navailable balance: Rs" << vec[account_no - 1001]->balance << endl;
					}
			}
					break;
			case 'C': {cout << "Account number?" << endl; int account_no; cin >> account_no;
				cout << "PIN" << endl; int pin; cin >> pin;
				if (vec[account_no - 1000 - 1]->account_no == -1 || pin != vec[account_no - 1000 - 1]->pin) cout << "not allowed. please recheck the credentials" << endl;
				else close(vec, account_no);
			}
					break;
			case 'I': {cout << "enter pin  "; int pin; cin >> pin;
				if (pin == pinformanager) {
					double Interest; cout << "enter the interest rate " << endl; cin >> Interest;
					interest(vec, Interest);
				}
				else cout << "wrong pin" << endl;
			}
					break;
			case 'P': {cout << "enter pin  "; int pin; cin >> pin;
				if (pin == pinformanager)
					printall(vec);
				else cout << "wrong pin" << endl;
			}
					break;
			case 'E': {cout << "enter pin  "; int pin; cin >> pin;
				if (pin == pinformanager)
				{
					for (int i = 0; i < 100; i++)
						if (vec[i]->account_no != -1) close(vec, i + 1001);

					exit(0);
				}
				else cout << "wrong pin" << endl;
			}
					break;
			case 'M': {
				cout << "\n which ATM are you goin to fill\n";
					int atmnumber; cin >> atmnumber;
				int pin;
				cout << "enter you pin :"; cin >> pin;
				if (atmnumber < 1 || atmnumber>10) {cout << "invalid"; break; }
				if (pin != pinformanager) { cout << "invalid entry"; break;}
				cout << "enter the refill amount \n"; int refill; cin >> refill;
				atm[atmnumber - 1] += refill;
				cout << "the new cash amount in atm" << atmnumber << " is Rs" << atm[atmnumber - 1] << endl;
			}
					break;
			case 'Q': {
				int pin;
				cout << "\n for which ATM do you want to see available balance\n";
					int atmnumber; cin >> atmnumber;
				cout << "enter you pin :"; cin >> pin;
				if (atmnumber < 1 || atmnumber>10) { cout << "invalid"; break; }
				if (pin != pinformanager) { cout << "invalid entry"; break; }
				cout << "Rs" << atm[atmnumber - 1] << endl;
			}
					break;
			default: cout << "invalid entry. please try again" << endl;
			}
	}

}