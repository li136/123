#include<iostream>
#include"List.h"
using namespace std;
int main()
{
	try
	{
		p.Push_first(2.1);
		cout << p.Seek(1);
	}
	catch (const char *asd)
	{
		cerr << asd << endl;
	}
	return 0;
}