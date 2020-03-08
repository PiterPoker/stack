
#include "stdafx.h"
struct List
{
	int x;                                              
	List *Next, *Head;                                   
};

struct tstk
{
	int inf;
	tstk *head, *next;
};

/*adding an item to the stack*/
void Add(int x, List *&MyList, tstk *&pt)                          
{
	List *temp = new List;                              
	tstk *temp2 = new tstk;
	if (x%2 != 0) 
	{
		temp2->inf = x;
		temp2->next = pt->head;
		pt->head = temp2;
	}
	temp->x = x;                                        
	temp->Next = MyList->Head;                          
	MyList->Head = temp;                                
}

/*display stack*/
void Show(List *MyList, tstk *pt)                                 
{
	List *temp = MyList->Head;                          
	tstk *temp2 = pt-> head;
														
	while (temp != NULL)                                
	{
		cout << temp->x << " ";                         
		temp = temp->Next;                              
	}
	cout << endl;
	cout <<"Result:"<< endl;
	while (temp2 != NULL)                                
	{
		cout << temp2->inf << " ";                         
		temp2 = temp2->next;                              
	}
}

/*delete stack from memory*/
void ClearList(List *MyList, tstk *pt)
{
	while (MyList->Head != NULL)                        
	{
		List *temp = MyList->Head->Next;                   
		delete MyList->Head;                                
		MyList->Head = temp;                                
	}
	while (pt->head != NULL)                        
	{
		tstk *temp2 = pt->head->next;                   
		delete pt->head;                                
		pt->head = temp2;                               
	}
}

int main()
{
	int index = -50;
	List *MyList = new List;
	tstk *List = new tstk; 


	MyList->Head = NULL; 
	List->head = NULL; 

	for (int i = 0; i <= 100; i++)
	{
		Add(index, MyList, List); 
		index++;
	}
	Show(MyList, List);

	ClearList(MyList, List); 
	delete MyList->Head;
	delete MyList;
	delete List->head;
	delete List;
	
	system("pause");
	return 0;
}
