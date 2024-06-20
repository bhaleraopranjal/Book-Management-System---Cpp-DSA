#include "node.cpp"

template <class T>
class LinkedList{
	Node<T>* start;
	
	public:
		LinkedList();
		void insertPos(int,T&);
		void display();
		void deletePos(int);
		int searchBook(int);
		int searchBookName(char*);
		void searchBookAuthor(char*);
		void searchBookCategory(char*);
		void searchByPrice(double,double);
		void searchByRating(double,double);
		void updateBook(int);
		void sortId();
		void sortPrice();
		void sortRating();
		void writeToFile(const char*);
		void readFromFile(const char*);
		~LinkedList();
};