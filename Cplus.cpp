#include<iostream>
using namespace std;
struct Node
{
	int data;
	struct Node *next;
};
int main()
{
	int n, i;
	struct Node* head=NULL;
	struct Node* temp=NULL;
	struct Node* a=NULL;
	cout<<"enter no of nodes:";
	cin>>n;
	for(i=0;i<n;i++)
	{
		a=(struct Node*)malloc(sizeof(struct Node));
		a->data=i;
		a->next=NULL;
		cout<<a->data<<endl;
		if(i==0)
		{
			head=a;
		}
		else
		{
			temp->next=a;
		}
		temp=a;
	}
	cout<<"Linked List:\n";
	temp=head;
	while(temp!=NULL)
	{
		cout<<"DATA="<<temp->data<<endl;
		temp=temp->next;
	}
	return 0;
}