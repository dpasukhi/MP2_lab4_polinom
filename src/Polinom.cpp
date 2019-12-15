#include "Polinom.h"


/*########################################################################################################
                                          Methods for Monom
#########################################################################################################*/

//Default constructor
Monom::Monom():pow(0),coeff(0),next(nullptr),size(0)
{
}

//Destructor
Monom::~Monom()
{
	delete[] name;
	name = nullptr;
}

//Copy constructor
Monom::Monom(const Monom& mon):coeff(mon.coeff),pow(mon.pow),next(mon.next),size(mon.size)
{
	name = new Type[size];
	for (int i = 0; i < size; i++)
	{
		name[i] = mon.name[i];
	}
}

//A constructor that takes a coefficient, an array of variables and their number, but a pointer to the next element=nullptr
Monom::Monom(double n_coef,Type* m,int count):coeff(n_coef),next(nullptr),size(count)
{
	sort(m,count);
	pow = 0;
	name = new Type[size];
	for (int i = 0; i < size; i++)
	{
		pow += m[i].pow;
		name[i] = m[i];
	}
}

//A constructor that takes a coefficient, an array of variables and their number, and a pointer to the next element
Monom::Monom(double n_coef, Type* m,int count, Monom* mon):coeff(n_coef),next(mon),size(count)
{
	sort(m, count);
	pow = 0;
	name = new Type[count];
	for (int i = 0; i < count; i++)
	{
		pow += m[i].pow;
		name[i] = m[i];
	}
}

//sorting variables alphabetically in monomial
void Monom::sort(Type* nam, int count)
{
	Type tmp;
	for (int i = 0; i < count; i++) {
		if (nam[i].pow == 0)
		{
			Type* temp = new Type[count - 1];
			for (int j = 0, l = 0; j < count; j++)
				if (nam[j].pow != 0)
				{
					temp[l] = nam[j];
					l++;
				}
			size--;
			delete[] nam;
			nam = new Type[size];
			for (int j = 0; j < size; j++)
				nam[j] = temp[j];
			delete[] temp;
			temp = nullptr; 
			count--;
		}
	}
	for (int i = 0; (i < count-1); i++)
		for (int j = 0; j < count - i-1 ; j++)
			if (nam[j] > nam[j + 1]) 
			{
				tmp = nam[j];
				nam[j] = nam[j + 1];
				nam[j + 1] = tmp;
			}
		
}

//Checking for a match all the variables & their powers
bool Monom::operator==(const Monom& mon)
{
	bool tmp = true;
	for (int i = 0; i < size; i++)
	{
		if (name[i].str != mon.name[i].str || name[i].pow != mon.name[i].pow)
			tmp = false;

	}
	return (pow == mon.pow&&size==mon.size&&tmp);
}

// Checking for a match all the variables
bool Monom::Is_eq(Monom& mon)
{
	bool tmp = true;
	for (int i = 0; i < size; i++)
	{
		if (name[i].str != mon.name[i].str)
			tmp = false;
	}
	return tmp;
}


/*########################################################################################################
                                            Methods for  Polynom
#########################################################################################################*/

//Default constructor
Polynom::Polynom():head(nullptr)
{
}

//Destructor
Polynom::~Polynom()
{
	clear();
}

//Copy constructor
Polynom::Polynom(const Polynom& pol):head(nullptr)
{
	Monom* tmp = pol.head;
	while (tmp != nullptr)
	{
		push_back(tmp->coeff,tmp->name,tmp->size);
		tmp = tmp->next;
	}
}

//Returns a pointer to the end of the list
Monom* Polynom::get_tail()
{

	if (head == nullptr)
		throw "Incorrect actions";
	else
	{
		Monom* temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		return temp;
	}
}

//Insert at the end of the list 
void Polynom::push_back(double _coeff,Type* m,int count)
{
	if (head == nullptr)
	{
		head = new Monom(_coeff, m,count);
	}
	else {
		Monom* temp = get_tail();
		temp->next = new Monom(_coeff, m, count);
	}
}

//Returns a size of the list 
int Polynom::get_size()
{
	Monom* temp = head;
	if (temp == nullptr)
		return 0;
	int couter = 0;
	while (temp->next != nullptr)
	{
		couter++;
		temp = temp->next;
	}
	couter++;
	return couter;
}

//Insert at %ind% position of the list
void Polynom::insert(int ind, double _coeff, Type* m, int count)
{
	Monom* tmp = head;
	if (ind < 0 || ind > get_size()) throw "incorrect index";
	else if (ind == 0)
	{
		Monom* y = new Monom(_coeff,  m, count);
		y->next = head;
		head = y;
	}
	else
	{
		int i = 1;
		while (i != ind)
		{
			tmp = tmp->next;
			i++;
		}
		Monom* y = new Monom(_coeff, m, count);
		y->next = tmp->next;
		tmp->next = y;
	}
}

//Removing an item from a list at %ind% position
Monom* Polynom::Delete(int ind)
{
	if (ind == 0)
	{
		Monom* t = head->next;
		delete head;
		head = t;
		return t;
	}
	else if (ind < 0 || ind > get_size())
		throw"Incorrect index";
	else
	{
		Monom* tmp = head->next;
		Monom* tmp2 = head;
		while (ind != 1)
		{
			tmp = tmp->next;
			tmp2 = tmp2->next;
			ind--;
		}
		tmp2->next = tmp->next;
		delete tmp;
		return tmp2;
	}
}

//Display the polynomial on the screen. Equivalent to operation << Polynom
void Polynom::print_all()
{
	if (head != nullptr) {
		Monom* temp = head;
		while (temp != nullptr)
		{
			std::cout <<"Pow "<<temp->pow<<" "<< temp->coeff;;
			for (int i = 0; i < temp->size; i++)
				cout << temp->name[i].str <<"^"<< temp->name[i].pow;
			temp = temp->next;
			cout << endl;
		}
	}
	else
		std::cout << "Is_empty" << std::endl;
}

//List cleaning
void Polynom::clear()
{
	int ind;
	while ((ind = (get_size()-1)) !=-1)
		Delete(ind);
}

// *this polynomial is equal to the polynomial passed by the parameter
//Assignment operation
Polynom& Polynom::operator=( Polynom& pol)
{
	if (head == pol.head)
		return *this;
	clear();
	Monom* tmp = pol.head;
	while (tmp != nullptr) 
	{
		push_back(tmp->coeff,tmp->name,tmp->size);
		tmp = tmp->next;
	}
	return *this;
}

//Multiplication of two polynomials
Polynom Polynom::operator*(Polynom& pol)
{
	sort();
	pol.sort();
	Polynom tmp;
	int js = 0;
	for (Monom* mon_i = pol.head; mon_i != nullptr; mon_i = mon_i->next)
	{
		for (Monom* mon_j = head; mon_j != nullptr; mon_j = mon_j->next, js++)
		{
			if (mon_i->Is_eq(*mon_j))
			{
				int coef = mon_j->coeff * mon_i->coeff;
				for (int i = 0; i < mon_j->size; i++)
					int pow=mon_j->name[i].pow + mon_i->name[i].pow;
				tmp.push_back(coef, mon_j->name, mon_j->size);
			}
			else 
			{
				int coef= mon_j->coeff * mon_i->coeff;
				int s = mon_j->size + mon_i->size;
				Type* mass = new Type[s];
				for (int i = 0; i < mon_j->size; i++)
				{
					mass[i].str = mon_j->name[i].str;
					mass[i].pow = mon_j->name[i].pow;
					mass[i] = mon_j->name[i];
				}
				int ssize = mon_j->size;
				int tt = ssize;
				for (int i = 0; i <mon_i->size ; i++)
				{
					bool exist = false; int j;
					for (j = 0; j < ssize; j++)
					{
						if (mass[j].str == mon_i->name[i].str)
						{
							mass[j].pow += mon_i->name[i].pow;
							exist = true;
							break;
						}
					}
					if (!exist)
					{
						mass[ssize] = mon_i->name[i];
						ssize++;
					}
				}

				Type* tmas = new Type[ssize];
				for (int k = 0; k < ssize; k++)
					tmas[k] = mass[k];
				ssort(tmas, ssize);
				tmp.push_back(coef, tmas, ssize);
				delete[]mass;
				delete[] tmas;

			}
		}
	}
	return tmp;
}

//Addition of two polynomials
Polynom Polynom::operator+(Polynom& pol)
{
	sort();
	pol.sort();
	Polynom tmp(*this);
	Monom* m_tmp = head;

	bool exist=false;


	for (Monom* mon_i = pol.head; mon_i != nullptr; mon_i = mon_i->next)
	{
		int j = 0;
		exist = false;

		for (Monom* mon_j = tmp.head; mon_j != nullptr; mon_j = mon_j->next,j++)
			if (mon_j->operator==(*mon_i))
			{
				mon_j->coeff += mon_i->coeff;
				if (mon_j->coeff == 0.)
					tmp.Delete(j);
				exist = true;
				break;
			}
		if (!exist)
		{
			int l=0;
			for (Monom* mon_j = tmp.head; mon_j != nullptr && mon_j->pow <= mon_i->pow; mon_j = mon_j->next, l++);
			tmp.insert(l, mon_i->coeff, mon_i->name, mon_i->size);
		}
	}
	return tmp;

}

//Multiplication of %*this% polynomial by double %num%
Polynom Polynom::operator*(const double num) const
{
	Polynom tmp(*this);
	//Monom* m_tmp = head;
	//while (m_tmp != nullptr)
	//{
	//	tmp.push_back(m_tmp->coeff, m_tmp->pow);
	//	m_tmp = m_tmp->next;
	//}
	Monom* m2_tmp = tmp.head;
	while (m2_tmp != nullptr)
	{
		m2_tmp->coeff = m2_tmp->coeff * num;
		m2_tmp = m2_tmp->next;
	}
	return tmp;
}

//Subtraction of two polynomials
Polynom Polynom::operator-(Polynom& pol)
{
	sort();
	pol.sort();
	Polynom tmp(*this);
	Monom* m_tmp = head;
	//while (m_tmp != nullptr)
	//{
	//	tmp.push_back(m_tmp->coeff, m_tmp->name, m_tmp->size);
	//	m_tmp = m_tmp->next;
	//}

	bool exist = false;


	for (Monom* mon_i = pol.head; mon_i != nullptr; mon_i = mon_i->next)
	{
		int j = 0;
		exist = false;

		for (Monom* mon_j = tmp.head; mon_j != nullptr; mon_j = mon_j->next, j++)
			if (mon_j->operator==(*mon_i))
			{
				mon_j->coeff -= mon_i->coeff;
				if (mon_j->coeff == 0.)
					tmp.Delete(j);
				exist = true;
				break;
			}
		if (!exist)
		{
			int l = 0;
			for (Monom* mon_j = tmp.head; mon_j != nullptr && mon_j->pow <= mon_i->pow; mon_j = mon_j->next, l++);
			tmp.insert(l, -mon_i->coeff, mon_i->name, mon_i->size);
		}
	}
	return tmp;
}

//Sorting polynomial by degrees ascending
void Polynom::sort()
{
	if (head != nullptr)
	{
		int i=0;
		for (Monom* mon_i = head; mon_i!= nullptr; mon_i = mon_i->next,i++)
		{
			int j = i+1;
			for (Monom* mon_j=mon_i->next; mon_j!= nullptr; mon_j = mon_j->next,j++)
			{
					if (mon_i->pow > mon_j->pow)
					{
						mon_i->sort(mon_i->name, mon_i->size);
						mon_j->sort(mon_j->name, mon_j->size);
						insert(j+1, mon_i->coeff, mon_i->name, mon_i->size);
						mon_i = Delete(i);
					}
			}
		}
		i = 0;
		for (Monom* mon_i = head; mon_i != nullptr; mon_i = mon_i->next, i++)
			if (mon_i->coeff == 0.)
			{
				mon_i = Delete(i);
			}

	}

}

//Display Polynomial
ostream& operator<<(ostream& o, Polynom& p)
{
	p.sort();
	if (p.head != nullptr) 
	{
		Monom* temp = p.head;
		while (temp != nullptr)
		{
			if (temp->coeff > 0&&temp==p.head)
				o <<temp->coeff;
			else if(temp->coeff > 0 && temp != p.head)
				o << "+" << temp->coeff;
			for (int i = 0; i < temp->size; i++)
				o << temp->name[i].str << "^" << temp->name[i].pow;
			temp = temp->next;
		}
		o << endl;
	}
	else
		o << "Is_empty" << std::endl;
	return o;
}

//Entering a polynomial with the introduction of the number of monomials
istream& operator>>(istream& istr, Polynom& p)
{
	cout << "Input count of monoms";
	int count;
	istr >> count;
	for (int i = 0; i<count; i++)
	{
		cout << "Input you polynoms[" << i << "]" << endl;
		cmatch result;
		smatch res;
		regex rx("^[\\d]+[\\.\\d+)]*");
		regex lx("[0-9]+");
		regex rxx("[a-z]{1}[\^]{1}[0-9]+");
		regex rx_mon("[a-z]{1}[\\^]+");
		string mon;
		istr >> mon;
		regex_search(mon.c_str(), result, rx);
		//cout << result.str();
		//regex_search(mon.c_str(), res, rxx);
		std::sregex_iterator beg{ mon.cbegin(), mon.cend(), rxx }; 
		std::sregex_iterator end{}; 
		int ind=0;
		Type* mass=new Type[100];
		for (auto i = beg; i != end; ++i, ind++)
		{
			cmatch result_num;
			string resut_word="";
			resut_word += i->str()[0];
			//regex_search(i->str().c_str(), resut_word, rx_mon);
			//cout << resut_word;
			//cout << i->str()[0] << endl;
			regex_search(i->str().c_str(), result_num, lx);
			mass[ind].str = resut_word;
			mass[ind].pow = stoi(result_num.str());
			//std::cout << i->str() /*<< "(" << i->position() << ") ["
				//<< i->length() << "]\n"*/;
		}
		if (result.str() != "") 
		{
			double coef = strtod(result.str().c_str(), 0);
			p.push_back(coef, mass, ind);
		}
		else
		{
			p.push_back(1, mass, ind);
		}
	}
	return istr;
}

//sorting variables alphabetically in monomial
void ssort(Type* nam, int count)
{
	Type tmp;
	for (int i = 0; i < count; i++) {
		if (nam[i].pow == 0)
		{
			Type* temp = new Type[count - 1];
			for (int j = 0, l = 0; j < count; j++)
				if (nam[j].pow != 0)
				{
					temp[l] = nam[j];
					l++;
				}
			count--;
			delete[] nam;
			nam = new Type[count];
			for (int j = 0; j < count; j++)
				nam[j] = temp[j];
			delete[] temp;
			temp = nullptr;
			count--;
		}
	}
	for (int i = 0; (i < count - 1); i++)
		for (int j = 0; j < count - i - 1; j++)
			if (nam[j] > nam[j + 1])
			{
				tmp = nam[j];
				nam[j] = nam[j + 1];
				nam[j + 1] = tmp;
			}
}