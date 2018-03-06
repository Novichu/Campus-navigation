#include<string>
#include <iostream>
#include<cstdlib>

using namespace std;
class Campus {
public:  int number;
		 string namelist;
public:
	Campus(int num, string name){
		number = num;
		namelist = name;
	}
	~Campus(){}


};

class Distance{
public:	 int a[10][10];

		 void distance(){

			 for (int i = 0; i < 10; i++)
			 {
				 for (int j = 0; j< 10; j++)
				 {
					 a[i][j] = INT_MAX;
				 }


			 }
			 for (int i = 0; i < 10; i++)
			 {
				 a[i][i] = 0;

			 }
			 a[0][1] = 10;
			 a[0][2] = 12;
			 a[0][9] = 18;
			 a[1][2] = 9;
			 a[1][3] = 11;
			 a[1][5] = 2;
			 a[1][7] = 8;
			 a[1][8] = 19;
			 a[1][9] = 22;
			 a[2][3] = 6;
			 a[3][4] = 18;
			 a[3][5] = 5;
			 a[4][5] = 16;
			 a[4][6] = 3;
			 a[5][6] = 7;
			 a[5][7] = 4;
			 a[6][7] = 9;
			 a[7][8] = 7;
			 a[8][9] = 21;
			 for (int i = 0; i < 5; i++)
			 {
				 for (int j = 0; j<5; j++)
				 {
					 a[j][i] = a[i][j];
				 }


			 }
		 }


};

