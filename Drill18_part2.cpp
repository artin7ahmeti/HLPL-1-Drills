#include "std_lib_facilities.h"
//18.2.1
vector<int> gv ={1 , 2, 4, 8, 16, 32, 64, 128, 256, 512};
//18.2.2
void f(vector <int> v)
{
	//18.2.3 local vector
	vector <int> lv;
	//copying values
	for (int i = 0;i < v.size();i++)
		lv.push_back(gv[i]);
	//printing
	for (int i = 0;i < lv.size();i++)
		cout << "[" << lv[i] << "]";
	cout << endl;
	//18.2.3/d local vector 2
	vector <int> lv2;
	//copying values
	for (int i = 0;i < v.size();i++)
		lv2.push_back( v[i]);
	//printing
	for (int i = 0;i < lv2.size();i++)
		cout << "[" << lv2[i] << "]";
	cout << endl;
}
//optional, but I wanted to implement this extra function
/*int factorial(int aa) {
  if(aa > 1)
    return aa * factorial(aa - 1);
  else
    return 1;
}*/

//18.3.
int main()
{
	f(gv);
	vector <int> vv = {1 , 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};
	f(vv);
    /* vector <int> vv = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	for (int i = 0;i < 10;i++)
		cout << "[" << factorial(vv[i]) << "]";
	*/
	return 0;
}
