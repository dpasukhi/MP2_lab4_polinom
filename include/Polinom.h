#pragma once
#include <iostream>
#include <cmath>
#include <regex>
#include <string>
using namespace std;

//Array of variables with their powers
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

void ssort(Type* nam, int count); //sorting variables alphabetically in monomial

class  Monom
{
public:
	 Monom();//Default constructor
	 ~Monom();//Destructor
	 Monom(const Monom& mon);//A constructor that takes a coefficient, an array of variables and their number, but a pointer to the next element=nullptr
	 Monom(double n_coef, Type* m,int count);//A constructor that takes a coefficient, an array of variables and their number, and a pointer to the next element
	 Monom(double n_coef, Type* m, int count, Monom* mon);
	 void sort(Type* nam, int count);//sorting variables alphabetically in monomial
	 double coeff;//Monomial coefficient
	 bool operator==(const Monom& mon);//Checking for a match all the variables & their powers
	 bool Is_eq(Monom& mon);// Checking for a match all the variables
	 int pow;//The total power of a monomial
	 int size;//Number of variables
	 Type* name; //Array of variables with their powers
   	 Monom* next;//pointer to next element
};

class Polynom
{
public:
	Polynom();//Default constructor
	~Polynom();//Destructor
	Polynom(const Polynom&);//Copy constructor
	Monom* get_tail();//Returns a pointer to the end of the list
	void push_back(double _coeff,Type* m,int count);//Insert at the end of the list 
	int get_size();//Returns a size of the list 
	void insert(int ind, double _coeff,Type* m, int count);//Insert at %ind% position of the list
	Monom* Delete(int);//Removing an item from a list at %ind% position
	void print_all();//Display the polynomial on the screen. Equivalent to operation << Polynom
	void clear();//List cleaning
	Polynom& operator=(Polynom& pol);// %*this% polynomial is equal to the polynomial passed by the parameter||Assignment operation
	Polynom operator*(Polynom& pol);//Multiplication of two polynomials
	Polynom operator+(Polynom& pol);//Addition of two polynomials
	Polynom operator*(double num)const; //Multiplication of %*this% polynomial by double %num%
	Polynom operator-(Polynom& pol);//Subtraction of two polynomials
	friend ostream& operator<<(ostream& o, Polynom& p); //Display Polynomial
	friend istream& operator>>(istream& i, Polynom& p); //Entering a polynomial with the introduction of the number of monomials
	void sort(); //Sorting polynomial by degrees ascending
private:
	Monom* head;// pointer to the first element
};