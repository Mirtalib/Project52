#include<iostream>

using namespace std;

#include"SHARED_PTR.h"
using namespace HearderFiles;






int main() {
	Myshared_ptr<int> s2(new int(1));
	Myshared_ptr<int> s4(new int(112));
	Myshared_ptr<int> s5(new int(1212));
	Myshared_ptr<int> s6;


	s6 = s2;


	if (s6)
	{
		cout << "This Value=>" << *s6 <<endl;
	}
	else
	{
		cout << "This Not Value" << endl;
	}

	s5.swap(s4);
	
	
	cout << *s5 << endl;
	cout << "Use Count=>" << s4.use_count() <<endl;
	cout << boolalpha << "Unique=>" << s4.unique() << endl;

	cout << "Result=> " << s6.owner_before(s5) << endl;
}