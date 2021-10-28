#include<iostream>
using namespace std;
template<class T>
class Node
{
	int data;
	Node * pre;
	Node* next;
public:
	Node()
	{
		pre=nullptr;
		next=nullptr;
	}
	void setdata(T element)
	{
		data=element;
	}
	T getdata()
	{
		return data;
	}
	Node* getpre()
	{
		return pre;
	}
	Node* getnext()
	{
		return next;
	}
	void setpre(Node* p)
	{
		pre=p;
	}
	void setnext(Node* n)
	{
		next=n;
	}
	~Node()
	{
		if(next!=nullptr)
		{
			delete [] next;
		}
		if(pre!=nullptr)
		{
			delete [] pre;
		}
	}
};
template<class T>
class DoubleList
{
Node<T> * head;
Node<T>*tail;
public:
	DoubleList()
	{
		head=nullptr;
		tail=nullptr;
	}
	void sethead(Node<int> * n)
	{
		head=n;
	}
	void settail(Node<int> * n)
	{
		tail=n;
	}
	void insertAtStart(T const element)
	{
		if(head==nullptr)
		{
			Node<T> * temp=new Node<T>();
			temp->setdata(element);
			temp->setnext(nullptr);
			temp->setpre(nullptr);
			head=temp;
			tail=temp;
		}
		else
		{
		Node<T>* temp=new Node<T>();
		temp->setdata(element);
		temp->setnext(head);
		head->setpre(temp);
		head=temp;
		}
	}
	void insertAtEnd(T const element)
	{
		if(head==nullptr)
		{
			Node<T> * temp=new Node<T>();
			temp->setdata(element);
			temp->setnext(nullptr);
			temp->setpre(nullptr);
			head=temp;
			tail=temp;
		}
		else
		{
		Node<T> *temp=new Node<T>();
		temp->setdata(element);
		temp->setnext(nullptr);
		tail->setnext(temp);
		temp->setpre(tail);
		tail=temp;
		}
	}
	void print()
	{
		Node<T>* p=head;
		while (p->getnext()!=nullptr)
		{
			cout<<p->getdata()<<'\t';
			p=p->getnext();
		}
		cout<<p->getdata()<<'\n';
	}
	void deleteFromStart()
	{
		Node<T> * temp=new Node<T>();
		temp=head;
		head=head->getnext();
		temp->setnext(nullptr);
		head->setpre(nullptr);
	}
	void DeleteAtEnd()
	{
		Node<T> * temp=new Node<T>();
		temp=tail;
		tail=tail->getpre();
		tail->setnext(nullptr);
		temp->setpre(nullptr);
	}
	void removeduplicates()
	{
		Node<T> *temp,*temp1;
		temp=head;
		while(temp!=nullptr)
		{
			temp1=temp->getnext();
			while(temp1!=nullptr)
			{
				if(temp->getdata()==temp1->getdata())
				{
					Node<T> * next=temp1->getnext();
					if(temp1->getpre()!=nullptr)
					{   
						Node<T> * pe=temp1->getpre();
						pe->setnext(temp1->getnext());
					}
					temp1=next;
				}
				else
				{
					temp1=temp1->getnext();
				}
			}

			temp=temp->getnext();
		}
	}
	void reverseLinkedlist()
	{
		Node<T> *temp=tail;
		tail=head;
		head=temp;
		Node<T>* cur = head; 
		   
		 while (cur != nullptr) 
		 { 
			 temp=cur->getpre();
			 cur->setpre(cur->getnext());
			 cur->setnext(temp);
			 cur=cur->getnext();
		 }
	}
	bool insertBefore(T const v1,T const v2)
	{
		Node<T> *newNode=new Node<T>();
		newNode->setdata(v1);
		Node<T> * temp=head;
		Node<T> * p=nullptr;
		bool ret=false;
		while(temp!=nullptr)
		{
			if(temp->getdata()==v2)
			{
				if(temp!=head)
				{
				newNode->setnext(temp);
				temp->getpre()->setnext(newNode);
				newNode->setpre(temp->getpre());
				temp->setpre(newNode);
				return true;
				}
			}
			temp=temp->getnext();
		}
		return ret;
	}
	~DoubleList()
	{

	}
};
void main()
{
	DoubleList<int>  p;
	p.insertAtEnd(7);
	p.insertAtEnd(9);
	p.insertAtStart(9);
	p.insertAtEnd(10);
	p.insertAtEnd(9);
	p.print();
	p.removeduplicates();
	bool t=p.insertBefore(6,11);
	if(t)
	{
		cout<<"Inserted\n";
	}
	else
	{
		cout<<"Not inserted\n";
	}
	p.print();
	p.reverseLinkedlist();
	cout<<"Afetr Reverse\n";
	p.print();
	system("pause");
}