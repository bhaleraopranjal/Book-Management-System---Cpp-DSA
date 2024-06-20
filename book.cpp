#include "book.h"

Book :: Book()
{
	this->bId = -1;
	strcpy(this->bName,"NULL");
	strcpy(this->bAuthor,"NULL");
	strcpy(this->bCategory,"NULL");
	this->bPrice = -1;
	this->bRating = -1;
}
Book :: Book(int id ,char* name,char* author,char* category,double price,double rating)
{
	this->bId = id;
	strcpy(this->bName,name);
	strcpy(this->bAuthor,author);
	strcpy(this->bCategory,category);
	this->bPrice = price;
	this->bRating = rating;
}
void Book :: setId(int id)
{
	this->bId = id;
}
void Book :: setName(char* name)
{
	strcpy(this->bName,name);
}
void Book :: setAuthor(char* author)
{
	strcpy(this->bAuthor,author);
}
void Book :: setCategory(char* category)
{
	strcpy(this->bCategory,category);
}
void Book :: setPrice(double price)
{
	this->bPrice = price;
}
void Book :: setRating(double rating)
{
	this->bRating = rating;
}
int Book :: getId()
{
	return this->bId;
}
char* Book :: getName()
{
	return this->bName;
}
char* Book :: getAuthor()
{
	return this->bAuthor;
}
char* Book :: getCategory()
{
	return this->bCategory;
}
double Book :: getPrice()
{
	return this->bPrice;
}
double Book :: getRating()
{
	return this->bRating;
}
void Book :: bookDisplay()	
{	
	cout<<"\nBook Id: "<<this->bId<<"\nBook Name: "<<this->bName<<"\nBook Author: "<<this->bAuthor<<"\nBook Category: "<<this->bCategory<<"\nBook Price: "<<this->bPrice<<"\nBook Rating: "<<this->bRating<<"\n";
}