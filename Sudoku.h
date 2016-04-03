#include<iostream>

using namespace std;

class Sudoku{
    public:
	int giveQuestion();
	void readIn();
	int solve();
	void changeNum(int a,int b);
	void changeRow(int a,int b);
	void changeCol(int a,int b);
	void rotate(int n);
	void flip(int n);
	int transform();

};
