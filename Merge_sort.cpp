#include<iostream>
using namespace std;
int *A;
void merge(int a,int b,int c)
{
	int m,n, L[b-a+1], M[c-b];
	m=a;
	n=b;
	cout<<"L: ";
	for(int i=0;i<(b-a+1);i++)
	{
		L[i]=A[m];
		cout<<L[i];
		m+=1;
	}
	cout<<endl;
	for(int i=0;i<(c-b);i++)
	{
		M[i]=A[n+1];
		cout<<M[i];
		n+=1;
	}
	cout<<endl;
	int i=0;
	int j=0;
	for(int k=a;k<=c;k++)
	{
		if(j==(c-b))
		{
			A[k]=L[i];
			i+=1;
		}
		else if(i==(b-a+1))
		{
			A[k]=M[j];
			j+=1;
		}
		else if(L[i]<M[j])
			{
				A[k]=L[i];
				i+=1;
			}
			else
			{
				A[k]=M[j];
				j+=1;
			}
			cout<<A[k];
	}
	cout<<endl;
	return;
}
void mergesort(int p,int r)
{
	if(p==r)
	{
		return;
	}
	int q=(p+r)/2;
	cout<<p<<"to1 "<<q<<endl;
	mergesort(p,q);
	cout<<q+1<<"to2 "<<r<<endl;
	mergesort(q+1,r);
	cout<<"Merging"<<p<<"to"<<r<<endl;
	merge(p,q,r);
	return;
}
int main()
{
	int n,p=0;
	cout<<"Enter the size of array:"<<endl;
	cin>>n;
	A=new int[n];
	cout<<"Enter the elements"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	mergesort(p,n-1);
	cout<<"Sorted array:"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<A[i]<<endl;
	}
	return 0;
}