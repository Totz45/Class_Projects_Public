#include <iostream>
using namespace std;

int main()
{
	string one = "red";
	string two = "hot dog";
	
	cout << endl << endl;
	
	cout << two << endl; //prints out hot dog
	
	two.at(0) = one.at(0);
	two.at(1) = one.at(1);
	two.at(2) = one.at(2);
	
	cout << two << endl; //prints out red dog
	
	two.at(4) = 'h';
	two.at(5) = 'a';
	two.at(6) = 'n';
	//two.at(7) = 'd';  //causes an exception to be thrown!
	//two.at(8) = 's';
	cout << two;
	
	two = "hot hands";
	
	cout << two << endl << endl;
	
	return 0;
}