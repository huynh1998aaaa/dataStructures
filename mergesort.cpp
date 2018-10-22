#include<iostream>
 
using namespace std;

class node
{
public:
	int data;
	node *next;
};
 
// tao node 
node* NewNode(int d)
{
	 node *temp = new node;
	temp->data = d;
	temp->next = NULL;
	return temp;
}
 
// them vao cuoi linked list
node* AddToList(node *tail, int data)
{
	 node *newnode;
	newnode = NewNode(data);
 
	if(tail == NULL)
	{
		tail = newnode;
	}
	// neu ko NULL thi them tiep vao duoi
	else
	{
		tail->next = newnode;
		tail = tail->next;
	}
 
	return tail;
}
 
node* Merge(node* h1, node* h2)
{
	node *t1 = new node;
	node *t2 = new node;
	node *temp = new node;
	//return lkl1
	if(h1 == NULL)
		return h2;
 
	// Return lkl2
	if(h2 == NULL)
		return h1;
 
	t1 = h1;
 
	// lap qua lkl2 va sap xep voi lkl1
	while (h2 != NULL)
	{
		t2 = h2;
 
		// chuyen lkl2 sang dau lkl ke tiep
		h2 = h2->next;
		t2->next = NULL;
 
		// neu nho hon thi them node o dau
		if(h1->data > t2->data)
		{
			t2->next = h1;
			h1 = t2;
			t1 = h1;
			continue;
		}
 
		// chay qua lkl1
		flag:
		if(t1->next == NULL)
		{
			t1->next = t2;
			t1 = t1->next;
		}
		
		else if((t1->next)->data <= t2->data)
		{
			t1 = t1->next;
			goto flag;
		}
		else
		{
			
			temp = t1->next;
			t1->next = t2;
			t2->next = temp;
		}
	}
 

	return h1;
}
 
 

void MergeSort(node **head)
{
	node *first = new node;
	node *second = new node;
	node *temp = new node;
	first = *head;
	temp = *head;
 
	// tra ve neu it hon 2 nut
	if(first == NULL || first->next == NULL)
	{
		return;
	}
	else
	{
		//chia doi 2 nua 
		while(first->next != NULL)
		{
			first = first->next;
			if(first->next != NULL)
			{
				temp = temp->next;
				first = first->next;
			}
		}
		second = temp->next;
		temp->next = NULL;
		first = *head;
	}
 	//merge
	MergeSort(&first);
	MergeSort(&second);
 
	//ghep      
	*head = Merge(first, second);
}
 
int main()
{
	int n, i, num;
	 node *head = new node;
	 node *tail = new node;
	head = NULL;
	tail = NULL;
	cout<<"Nhap so phan tu";
	cin>>n;
 
 

	for(i = 0; i < n; i++)
	{
		cout<<"nhap phan tu thu"<<i+1<<": ";
		cin>>num;
 
		tail = AddToList(tail, num);
		if(head == NULL)
			head = tail;
	}
 
	// tham chieu vao mergesort()
	MergeSort(&head);
 
 
	while(head != NULL) 
	{
		cout<<"  "<<head->data;
		head=head->next;
	}
	return 0;	
}