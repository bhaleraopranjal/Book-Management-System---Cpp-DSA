#include "linkedList.h"
#include<fstream>

template <class T>
LinkedList<T> :: LinkedList()
{
	start = NULL;
	this->readFromFile("Book.txt");
}

template <class T>
void LinkedList<T> :: insertPos(int pos,T& data)
{
	Node<T>* temp = new Node<T>(data);
	if(start == NULL)
	{
		start = temp;
		cout<<"\nInsertion Successfully";
		return;
	}
	if(pos == 1)
	{
		temp->setNext(start);
		start = temp;
		cout<<"\nInsertion Successfully";
		return;
	}
	int i = 1;
	Node<T>* p = start;
	while(i < pos-1 && p->getNext() != NULL)
	{
		i++;
		p = p->getNext();
	}
	temp->setNext(p->getNext());
	p->setNext(temp);
	cout<<"\nInsertion successfully";	
}

template <class T>
void LinkedList<T> :: display()
{
	if(start == NULL)
	{
		cout<<"\nNo any record do display";
	}
	else
	{
		Node<T>* p = start;
		while(p != NULL)	
		{
			p->getData().bookDisplay();
			p = p->getNext();
		}		
	}
}

template <class T>
void LinkedList<T> :: deletePos(int pos)
{
	if(start == NULL)
	{
		cout<<"\nNo any record to delete";
		return;
	}
	Node<T>* p = start;
	if(pos == 1)
	{
		start = start->getNext();
		p->getData().bookDisplay();
		cout<<"\n--------------deleted successfully";
		delete p;
		return;
	}
	int i = 1;
	while(i < pos-1 && p->getNext() != NULL)
	{
		i++;
		p = p->getNext();
	}
	if(i == pos-1)
	{
		Node<T>* q = p->getNext();
		p->setNext(q->getNext());
		q->getData().bookDisplay();
		cout<<"\n--------------deleted successfully";
		delete q;
		return;
	}
	cout<<"\nInvalid Position";		
}

template <class T>
int LinkedList<T> :: searchBook(int id)
{
	if(start == NULL)
	{
		cout<<"\nNo any record to search";
		return -1;
	}
	Node<T>* p = start;
	int i = 1;
	while(p != NULL)
	{
		if((p->getData().getId()) == id)
		return i;
		p = p->getNext();
		i++;
	}
	return -1;
}

template <class T>
int LinkedList<T> :: searchBookName(char* nm)
{
	if(start == NULL)
	{
		cout<<"\nNo any record to search";
		return -1;
	}
	Node<T>* p = start;
	int i = 1;
	while(p != NULL)
	{
		if(strncasecmp(p->getData().getName(),nm,strlen(nm)) == 0)
			return i;
		i++;	
		p = p->getNext();
	}
	return -1;
}

template <class T>
void LinkedList<T> :: searchBookAuthor(char* aut)
{
	if(start == NULL)
	{
		cout<<"\nNo any record to search";
		return;
	}
	int flag = 1;
	Node<T>* p = start;
	while(p != NULL)
	{
		if(strncasecmp(p->getData().getAuthor(),aut,strlen(aut)) == 0)
		{
			p->getData().bookDisplay();
			flag = 0;			
		}
		p = p->getNext();			
	}
	if(flag == 1)
		cout<<"\nBook not found written by "<<aut;	
}

template <class T>
void LinkedList<T> :: searchBookCategory(char* cat)
{
	if(start == NULL)
	{
		cout<<"\nNo any record to search";
		return;
	}
	int flag = 1;
	Node<T>* p = start;
	while(p != NULL)
	{
		if(strncasecmp(p->getData().getCategory(),cat,strlen(cat)) == 0)
		{
			p->getData().bookDisplay();
			flag = 0;			
		}
		p = p->getNext();			
	}
	if(flag == 1)
		cout<<"\nBook not found of category "<<cat;	
}

template <class T>
void LinkedList<T> :: searchByPrice(double s ,double l)
{
	if(start == NULL)
	{
		cout<<"\nNo any record to search";
		return;
	}
	int flag = 0;
	Node<T>* p = start;
	while(p != NULL)
	{
		if(p->getData().getPrice() > s && p->getData().getPrice() < l)
		{
			p->getData().bookDisplay();
			flag = 0;
		}
		p = p->getNext();
	}
	if(flag == 1)
		cout<<"\nBook not found";	
}

template <class T>
void LinkedList<T> :: searchByRating(double s ,double l)
{
	if(start == NULL)
	{
		cout<<"\nNo any record to search";
		return;
	}
	int flag = 0;
	Node<T>* p = start;
	while(p != NULL)
	{
		if(p->getData().getRating() > s && p->getData().getRating() < l)
		{
			p->getData().bookDisplay();
			flag = 0;
		}
		p = p->getNext();
	}
	if(flag == 1)
		cout<<"\nBook not found";	
}

template <class T>
void LinkedList<T> :: updateBook(int id)
{
	if(start == NULL)
	{
		cout<<"\nNo any record to search";
		return;
	}
	int flag = 0;
	Node<T>* p = start;
	while(p != NULL)
	{
		if(p->getData().getId() == id)
		{
			double r,c;
			cout<<"\nEnter updated rating: ";
			cin>>r;
			cout<<"\nEnter updated price: ";
			cin>>c;
			
			Book& book = p->getData();
			book.setRating(r);
			book.setPrice(c);
			
			cout<<"\nRecord updated successfully";
			flag = 1;		
			return;
		}
		else
		{
			p = p->getNext();	
		}
	}
	if(flag == 0)
	cout<<"\nNo book found of id "<<id;
}

template <class T>
void LinkedList<T> :: sortId()
{
	for(Node<T>* p = start; p != NULL; p = p->getNext())
	{
		for(Node<T>* q = p->getNext(); q != NULL; q = q->getNext())
		{
			if(p->getData().getId() > q->getData().getId())
			{
				T temp = p->getData();
				p->setData(q->getData());
				q->setData(temp);
			}
		}
	}
	display();
}

template <class T>
void LinkedList<T> :: sortPrice()
{
	for(Node<T>* p = start; p != NULL; p = p->getNext())
	{
		for(Node<T>* q = p->getNext(); q != NULL; q = q->getNext())
		{
			if(p->getData().getPrice() > q->getData().getPrice())
			{
				T temp = p->getData();
				p->setData(q->getData());
				q->setData(temp);
			}
		}
	}
	display();	
}

template <class T>
void LinkedList<T> :: sortRating()
{
	for(Node<T>* p = start; p != NULL; p = p->getNext())
	{
		for(Node<T>* q = p->getNext(); q != NULL; q = q->getNext())
		{
			if(p->getData().getRating() > q->getData().getRating())
			{
				T temp = p->getData();
				p->setData(q->getData());
				q->setData(temp);
			}
		}
	}
	display();
}

template <class T>
void LinkedList<T> :: writeToFile(const char* file)
{
	std::ofstream outfile(file, ios::binary);
	Node<T>* p = start;
	while(p != NULL)
	{
		outfile.write(reinterpret_cast<char*>(&p->getData()),sizeof(T));
		p = p->getNext();
	}
	outfile.close();
}

template <class T>
void LinkedList<T> :: readFromFile(const char* file)
{
	std::ifstream infile(file, ios::binary);
	T bk;
	while(infile.read(reinterpret_cast<char*>(&bk),sizeof(T)))
	{
		this->insertPos(1,bk);
	}
	infile.close();
}
			
template <class T>
LinkedList<T> :: ~LinkedList()
{
	this->writeToFile("Book.txt");
	while(start != NULL)
	{
		Node<T>* p = start;
		start = p->getNext();
		delete p;
	}
}