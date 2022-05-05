#include "std_lib_facilities.h"
//18.1
int ga[10] ={1,2,4,8,16,32,64,128,256,512};

//18.2
void f(int a[], int n)
{
	//18.3
	int la[10];
	//copying values
	for (int i = 0;i < 10;i++)
		la[i] = ga[i];
	//printing values
	for (int i = 0;i < 10;i++)
		cout << "[" << la[i] << "]";

	int* p = new int[n];
	for (int i = 0;i < 10;i++)
		p[i] = a[i];
	// printing
	cout << endl;
	for (int i = 0;i < 10;i++)
		cout << "[" << p[i] << "]";
	cout << endl;
	delete[] p;
}
//18.4
//optional, but I wanted to implement this extra function
int factorial(int aa) {
  if(aa > 1)
    return aa * factorial(aa - 1);
  else
    return 1;
}
int main()
{
	f(ga, 10);
	//using factorial function
	int aa[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	for (int i = 0;i < 10;i++)
		cout << "[" << factorial(aa[i]) << "]";
    //using printing function that we declared
    //f(aa, 10);

	return 0;
}
