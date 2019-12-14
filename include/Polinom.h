#pragma once
#include <iostream>
#include <cmath>
#include <regex>
#include <string>
using namespace std;


class Type:public string
{
public:
	int pow;
	string str;
	Type(int _pow, string st) :std::string(st)
	{
		pow = _pow;
		str = st;
	}
	Type() :std::string()
	{
		pow = 0;
		str = "";
	}
};
void ssort(Type* nam, int count);
class  Monom
{
public:
	 Monom();
	 ~Monom();
	 Monom(const Monom& mon);
	 Monom(double n_coef, Type* m,int count);
	 Monom(double n_coef, Type* m, int count, Monom* mon);
	 void sort(Type* nam, int count);
	 double coeff;
	 bool operator==(const Monom& mon);
	 bool Is_eq(Monom& mon);

	 int pow;
	 int size;
	 Type* name;
   	 Monom* next;
};

class Polynom
{
public:
	Polynom();
	~Polynom();
	Polynom(const Polynom&);
	Monom* get_tail();
	void push_back(double _coeff,Type* m,int count);
	int get_size();
	void insert(int ind, double _coeff,Type* m, int count);
	Monom* Delete(int);
	void print_all();
	void clear();
	Polynom& operator=(Polynom& pol);
	Polynom operator*(Polynom& pol);
	Polynom operator+(Polynom& pol);
	Polynom operator*(double num)const; 
	Polynom operator-(Polynom& pol);
	friend ostream& operator<<(ostream& o, Polynom& p);
	friend istream& operator>>(istream& i, Polynom& p);
	void sort();
private:
	Monom* head;
};