#include "std_lib_facilities.h"

int main()
{
	//17.2.1
	int* p1 = new int(7);
	// 10.2
	cout << "p1 = " << p1 << endl;
	cout << "*p1 = " << *p1<<endl;

	//17.2.3
	int* p2 = new int[7]{1,2,4,8,16,32,64};
	//17.2.4
	cout << "p2 = " << p2 << endl;
	cout << "Array of p2 = ";
	int i = 0;
	for (;i < 7;i++)
		cout << "[" << p2[i] << "]";
	cout << endl;
	//17.2.5
	int* p3 = p2;
	//17.2.6
	p2 = p1;
	//17.2.7
	p2 = p3;
	//17.2.8
	cout << "p1 = " << p1 << endl;
	cout << "p1 points to " << *p1 << endl;
	cout << "p2 = " << p2 << endl;
	cout << "p2 points to " << *p2 << endl;
	//17.2.9
	delete p1;
	delete p2;
	//17.2.10
	 p1 = new int[10]{1,2,4,8,16,32,64,128,256,512};
	p2 = new int[10];
	for (i = 0;i < 10;i++)
		p2[i] = p1[i];
	cout << "Array of p2 = ";
	for (i = 0;i < 10;i++)
		cout << "[" << p2[i] << "]";
	cout<<endl;
	// 17.2.13
	vector<int> vect{ 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };
	vector<int> vect2;
	for (i = 0;i < 10;i++)
		vect2.push_back(vect[i]);
	cout << "Vector vect = ";
	for (int  i : vect2)
		cout << "[" << i << "]";
	cout << endl;
	return 0;
}
