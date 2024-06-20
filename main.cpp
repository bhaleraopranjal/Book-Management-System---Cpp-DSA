#include "linkedList.cpp"

int main()
{	
	cout<<"\n+------------------------------------------------------------------------+";
	cout<<"\n+                         Book Management System                         +";
	cout<<"\n+------------------------------------------------------------------------+";
	LinkedList<Book> bk;
	int ch;
	do
	{
		cout<<"\n\t\t\t1.Add Book \n\t\t\t2.Display Books \n\t\t\t3.Delete Book \n\t\t\t4.Search Book \n\t\t\t5.Update Book \n\t\t\t6.Sort books \n\t\t\t7.Exit \nEnter your choice: ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				{
					int bId,pos;
					char bName[20],bAuthor[25],bCategory[15];
					double bPrice,bRating;
					
					cout<<"\nEnter position where you want to insert record: ";
					cin>>pos;
					cout<<"\nEnter book id: ";
					cin>>bId;
					cout<<"\nEnter book name: ";
					fflush(stdin);
					gets(bName);
					cout<<"\nEnter book author: ";
					fflush(stdin);
					gets(bAuthor);
					cout<<"\nEnter book category: ";
					fflush(stdin);
					gets(bCategory);
					cout<<"\nEnter book Price: ";
					cin>>bPrice;
					cout<<"\nEnter book rating: ";
					cin>>bRating;
					if(bRating > 5)
					{
						cout<<"\nEnter rating from 1 to 5.\nEnter book rating: ";
						cin>>bRating;					
					}
					Book b1(bId,bName,bAuthor,bCategory,bPrice,bRating);
					bk.insertPos(pos,b1);	
				}
				break;
				case 2:
					{
						bk.display();
					}
					break;
				case 3:{
					int pos;
					cout<<"\nEnter the position which you want to delete: ";
					cin>>pos;
					
					bk.deletePos(pos);
					break;
				}
				case 4:
					{
						int ch;
						do
						{
							cout<<"\n\t\t\t1.Serch by ID \n\t\t\t2.Search by Name \n\t\t\t3.Search by Author \n\t\t\t4.Search by Category \n\t\t\t5.Search by Price \n\t\t\t6.Search by Rating \n\t\t\t7.Exit \nEnter your choice: ";
							cin>>ch;
							
							if(ch == 1)
							{
								int id;
								cout<<"\nEnter book id you want to search: ";
								cin>>id;
								
								int ind = bk.searchBook(id);
								(ind == -1)?cout<<"\nBook not found":cout<<"\nBook found at "<<ind<<" index";
							}
							else if(ch == 2)
							{
								char nm[20];
								cout<<"\nEnter name of book you want to search: ";
								fflush(stdin);
								gets(nm);
								
								int ind = bk.searchBookName(nm);
								(ind == -1)?cout<<"\nBook not found":cout<<"\nBook found at "<<ind<<" index";
							}
							else if(ch == 3)
							{
								char author[20];
								cout<<"\nEnter name of author whose book you want to search: ";
								fflush(stdin);
								gets(author);
								
								bk.searchBookAuthor(author);
							}
							else if(ch == 4)
							{
								char cat[20];
								cout<<"\nEnter the category whose book you want to search: ";
								fflush(stdin);
								gets(cat);
								
								bk.searchBookCategory(cat);
							}
							else if(ch == 5)
							{
								double start,last;
								cout<<"\nEnter lowest range of price you want to search: ";
								cin>>start;
								cout<<"\nEnter highest range of price you want to search: ";
								cin>>last;
								
								bk.searchByPrice(start,last);
							}
							else if(ch == 6)
							{
								double start,last;
								cout<<"\nEnter lowest range of rating you want to search: ";
								cin>>start;
								cout<<"\nEnter highest range of rating you want to search: ";
								cin>>last;
								
								bk.searchByRating(start,last);
							}
							else if(ch == 7)
							{
								cout<<"\nThank you!!";
							}
							else
							{
								cout<<"\nEnter valid choice";
							}
						}while(ch != 7);					
					}
					break;
				case 5:
					{
						int id;
						cout<<"\nEnter book id you want to update: ";
						cin>>id;
						
						 bk.updateBook(id);
					}
					break;
				case 6:{
					int choice;
					cout<<"\n\t\t1.Sort by Id \n\t\t2.Sort by Price \n\t\t3.Sort by Rating \nEnter your choice: ";
					cin>>choice;
					
					if(choice == 1)
					{
						bk.sortId();
					}
					else if(choice == 2)
					{
						bk.sortPrice();
					}
					else if(choice == 3)
					{
						bk.sortRating();
					}
					else
					{
						cout<<"\nInvalid choice";
					}
					break;
				}
				case 7:
					{
						cout<<"\n--------Program End--------";
					}
					break;
				default:
					{
						cout<<"\nEnter valid choice";
					}
		}
	}while(ch != 7);	
	return 0;
}
