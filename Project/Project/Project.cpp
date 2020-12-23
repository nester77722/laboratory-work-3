#include <iostream>
#include <conio.h>
#include <string>

#pragma warning(disable:4996)

using std::cout;
using std::endl;

class Date {
public:
	void set(int, int, int);
	void get(int&, int&, int&);
	void next();
	void print();
private:
	int day, month, year;
};

void Date::set(int d, int m, int y) {
	day = d;
	month = m;
	year = y;
}
void Date::get(int& d, int& m, int& y) {
	d = day;
	m = month;
	y = year;
}
void Date::next()
{
	day++;
}

void Date::print()
{
	cout << "day=" << day << " month=" << month << " year=" << year << endl;
}

enum string_code {
	h,
	g,
	p,
	n,
	err
};

string_code hashit(std::string const& inString) {
	if (inString == "-h") return h;
	if (inString == "-g") return g;
	if (inString == "-p") return p;
	if (inString == "-n") return n;
	return err;
}


int main(int argc, char* argv[])
{
	setlocale(0, "");
	Date d1;
	cout << endl << "argc =" << argc << endl;
	cout << "Arguments:" << endl;
	for (int i = 0; i < argc; i++)
		cout << "argument" << i + 1 << ":" << argv[i] << endl;
	int d, m, y;
	d1.set(30, 9, 2018);
	if (argc != 1)
	{
		for (int i = 1; i < argc; i++) {
			switch (hashit(argv[i]))
			{
			case  h: {
				cout << "Opions:" << endl;
				cout << "-h display this help" << endl;
				cout << "-g get Date" << endl;
				cout << "-n next Date" << endl;
				break;
			}
			case  g: {
				d1.get(d, m, y);
				cout << "g:day=" << d << " month=" << m << " year=" << y << endl;
				break;
			}
			case  p: {
				d1.print();
				break;
			}
			case n: {
				d1.next();
				d1.print();
				break;
			}
			case err: {
				cout << "Not found this param: " << argv[i] << endl;
				break;
			}
			}
		}
	}
	else
		cout << "User -h for more help" << endl;
	_getch();
	return 0;
}
