#include "std_lib_facilities.h"
//17.4
void print_array10(ostream& os, int* a)
{
	for (int i = 0;i < 10; i++)
		os << "[" << a[i] << "]" << " ";
	cout << endl;
}
//17.7
void print_array(ostream& os, int* a,int n)
{
	for (int i = 0;i < n; i++)
		os << "[" << a[i] << "]" << " ";
	cout << endl;
}
//17.10
void print_vector(ostream& os, vector <int>& v )
{
	for (int i :v)
		os << "[" << i << "]" << " ";
	cout << endl;
}
int main()
{ //1st
	int* arr = new int[10] {1,2,3,4,5,6,7,8,9,10};
    //2nd
	for (int i = 0;i < 10;i++)
		cout << arr[i] << " ";
		cout << endl;
	// 3rd
	delete[] arr;
	// 4th
	cout << endl;
	cout << "Array representation below:" << endl;
	int* arr2 = new int[10]{ 100,101,102,103,104,105,106,107,108,109 };
	print_array10(cout, arr2);
	delete[] arr2;
	//6th
	int* arr3 = new int[11]{ 100,101,102,103,104,105,106,107,108,109,110 };
    print_array10 (cout, arr3);
	delete[] arr3;
	//8th
	int* arr4 = new int[20]{ 100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119 };
	print_array(cout, arr4, 20);
	delete[] arr4;
	// ----------------------------------------------
	cout << endl;
	cout << "Vector representation below:\n";
	//10th
	vector <int> vect;
	vect.reserve(10);
	vect = { 100,101,102,103,104,105,106,107,108,109 };
	print_vector(cout, vect);

	vector <int> vect2;
	vect2 = { 100,101,102,103,104,105,106,107,108,109,110 };
	print_vector(cout, vect2);

	vector <int> vect3;
	vect3 = { 100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119 };
	print_vector(cout, vect3);

	return 0;
}
