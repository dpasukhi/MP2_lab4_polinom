#include "iostream"
#include <regex>
#include <Polinom.h>

using namespace std;

int main()
{
	//setlocale(0, "rus");
	//setlocale(LC_NUMERIC, "C");
	//Polynom P;
	//P.push_back(1, 2);
	//P.push_back(3, 4);
	//P.push_back(4, 6);
	//P.push_back(7, 8);
	//P.print_all();
	//cout << endl;
	//P.clear();
	//P.print_all();

	//Type* t = new Type[1];
	//t[0] = Type(1,"g");
	//Type* tr = new Type[1];
	//tr[0] = Type(1, "g");
	//Type* tt = new Type[3];
	//tt[0] = Type(5, "g");
	//tt[1] = Type(5, "a");
	//tt[2] = Type(5, "j");
	//Type* ttt = new Type[3];
	//ttt[0] = Type(5, "g");
	//ttt[1] = Type(5, "a");
	//ttt[2] = Type(5, "j");
	//Polynom P;
	//Polynom pp;
	//P.push_back(4, t, 1);
	//P.push_back(3, tt, 3);
	//cout << P << endl;
	//P.insert(1, 5, ttt, 3);
	//P.Delete(1);
	
	//pp.push_back(3, ttt, 3);
	//pp.push_back(4, tr, 1);
	//P.sort();	
	//pp.sort();
	//Polynom ppp;
 //	ppp = P*pp;
	//cout << P;
	//P.print_all();
	//pp.print_all();
	//cout << "##########################################" << endl;
	//ppp.sort();
	//cout << ppp;


	Polynom p,pp;
	cin >> p;
	cout <<"Your polynom [0] is: "<< p << endl;
	cin >> pp;
	cout << "Your polynom [1] is: " << pp << endl;
	cout << p - pp << endl;
	cout << p * pp << endl;
	cout << p + pp << endl;
	return 0;

}