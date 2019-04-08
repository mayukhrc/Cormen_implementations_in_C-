#include<iostream>
#include<tuple>
using namespace std;
int *A;
tuple<int, int, int> max_crossing_subarray(int low, int mid, int high)
{
	int flag=0,left,right, left_sum=0, right_sum=0, sum=0;
	for(int i=mid;i>=low;i--)
	{
		sum=sum+A[i];
		if(flag==0)
		{
			left_sum=sum;
			flag=1;
		}
		if(left_sum<sum)
		{
			sum=left_sum;
			left=i;
		}
	}
	sum=0;
	flag=0;
	for(int i=mid;i<=high;i++)
	{
		sum=sum+A[i];		
		if(flag==0)
		{
			right_sum=sum;
			flag=1;
		}
		if(right_sum<sum)
		{
			sum=right_sum;
			right=i;
		}
	}
	sum=right_sum+left_sum;
	return make_tuple(left, right, sum);
}
tuple<int, int, int> max_subarray(int low, int high)
{
	int left_low, left_high, left_sum, right_low, right_high, right_sum, cross_low, cross_high, cross-sum;
	tuple<int,int,int> left_arr, right_arr, cross_arr;
	if(low==high)
	{
		return make_tuple(low, high, A[low]);
	}
	else
	{
		int mid=(low+high)/2;
		left_arr(left_low, left_high, left_sum)=max_subarray(low,mid);
		right_arr(right_low, right_high, right_sum)=max_subarray(mid+1,high);
		cross_arr(cross_low, cross_high, cross-sum)=max_crossing_subarray(low,mid,high);
		if(left_sum>right_sum && left_sum>cross_sum)
		{
			return left_arr;
		}
		else if(right_sum>left_sum && right_sum>cross_sum)
		{
			return right_arr;
		}
		else
		{
			return cross_arr;
		}
	}
}
int main()
{
	int n, low, high, sum;
	tuple<int,int,int> max_sub;
	cout<<"Enter no of elements:"<<endl;
	cin>>n;
	max_sub(low, high, sum)=max_subarray(0,n-1);
	for (int i = low; i < high; i++)
	{
		cout>>A[i]>>" ";
	}
	cout>>"Sum=">>sum;
}