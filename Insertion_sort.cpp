#include <iostream>

using namespace std;

int *A;
int main()
{
	int n;
	cout<<"Enter no of elements:";
	cin>>n;
	A= new int[n];
	cout<<"Fill the array:"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	for(int i=1;i<n;i++)
	{
		int key= A[i];
		int j=i-1;
		while(key<A[j] && j>-1)
		{
			A[j+1]=A[j];
			A[j]=key;
			j--;
		}
	}
	cout<<"Sorted Array"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<A[i]<<endl;
	}
	return 0;
}