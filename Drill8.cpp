#include "std_lib_facilities.h"

void swap_v(int a, int b){
        int temp;
        temp=a,
        a=b;
        b=temp;
    }

void swap_r(int& a, int& b){
        int temp;
        temp=a;
        a=b;
        b=temp;
}

//void swap_cr(const int&a, const int &b){
//        int temp;
  //      temp=a;
    //    a=b;
      //  b=temp;
//}

int main(){
        int x=7;
        int y=9;

        cout << "x = " << x <<" and y = " << y << endl;

        cout << "###############################" << endl;
        swap_v(x, y);

        cout << "after swap_v() x = " << x << " and y = " << y << endl;
        swap_r(x, y);

        cout << "after swap_r() x = " << x << " and y = " << y << endl;
        cout << "###############################" << endl;
        //swap_cr(x, y); //can't swap constants

        swap_v(7, 9); //no change to x and y
//        swap_r(7, 9); //can't convert from "int" to "int&"
//        swap_cr(7, 9); //can't swap constants

        //cout << "x = " << x << " and y = " << y << endl;
        cout << endl;

        const int cx = 7;
        const int cy = 9;

        cout << "cx = " << cx << " and cy = " << cy << endl;
        swap_v(cx, cy); //no change to x and y

        cout << "###############################" << endl;
        cout << "after swap_v() cx = " << cx << " and cy = " << cy << endl;

       // swap_r(cx, cy); // can't convert from "const int" to "int&"
       //swap_cr(cx, cy); // can't swap constants

        cout << "###############################" << endl;
        cout << endl;

       double dx = 7.7;
       double dy = 9.9;

        cout << "dx = " << dx << " and dy = " << dy << endl;
        cout << "###############################" << endl;
        swap_v(dx, dy); //no change to x and y

        cout << "after swap_v() dx = " << dx << " and dy = " << dy << endl;
      // swap_r(dx, dy); //can't convert from double to int
      // swap_cr(dx, dy); //can't swap constants

        cout << "###############################" << endl;
       swap_v(7.7, 9.9);
      // swap_r(7.7, 9.9); //can't convert from double to int
      // swap_cr(7.7, 9.9); //can't swap constants

   return 0;
}
