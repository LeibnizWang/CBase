#include<iostream>
#include<time.h>
using namespace std;
int main()
{
	clock_t start,end;
	start=clock();
	//cout<<start<<endl;
	//end=clock();
	//cout<<end<<endl;
	for(int i=0;i<1000;i++)
	{
		end=clock();
		cout<<(double)(end-start)/CLK_TCK<<endl;
	}
}
