#include "iostream"
#include <regex>
#include <Polinom.h>

using namespace std;

int main()
{
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
	//pp.push_back(3, ttt, 3);
	//pp.push_back(4, tr, 1);
	//P.sort();	
	//pp.sort();
	//Polynom ppp;
 //	ppp = P*pp;
	//P.print_all();
	//pp.print_all();
	//cout << "##########################################" << endl;
	//ppp.sort();
	//cout << ppp;

//
//		cmatch result;
//		smatch res;
//		regex rx("^[\\d]+[\\.\\d+)]*");
//		regex rxx("[a-z]{1}[\^]{1}[0-9]+");
//		string mon;
//		cin >> mon;
//		std::sregex_iterator beg{ mon.cbegin(), mon.cend(), rxx }; // итератор
//// на начало последовательности найденных совпадений
//		std::sregex_iterator end{};  // 'нулевой' итератор
//		regex_search(mon.c_str(), result, rx);
//		for (auto i = beg; i != end; ++i)
//		{
//
//			std::cout << i->str() /*<< "(" << i->position() << ") ["
//				<< i->length() << "]\n"*/;
//		}
//		//regex_search(mon.c_str(), res, rxx);
//		cout << result[0] << endl;
		//for (int l = 0; l < res.size(); l++)
		//	cout << res[l] << endl;

	//Type* tt = new Type[3];
	//tt[0] = Type(0, "g");
	//tt[1] = Type(2, "j");
	//tt[2] = Type(1, "a");
	//Monom m(4, tt, 3);
	//for (int i = 0; i < 2; i++)
	//	cout << m.name[i].str << " ";
	Polynom p;
	cin >> p;
	return 0;
}