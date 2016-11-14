//             Microsoft Visual Studio 2013           
/*       It is a Program to automize the bookstore 
          It keep record of Books and its Member.
     It also give 5% discount to its membership holders.*/


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Header.h"

#define MAX_BOOK 1000
#define MAX_MEMBER 500
#define TRUE true

using namespace std;

// Functions Declaration
void process(memberType&, bookType&);

// ============================================================================================== Member function for bookType

// Input 
void bookType::input()
{
	update_title();
	update_isbn();
	update_price();
	update_publisher();
	update_author();
	modify_books_left();
}
// Update Title
void bookType::update_title()
{
	int count;

	do{
		count = 0;
		cin.clear();
		cin.ignore(10, '\n');

		cout << "Enter the title of the book : ";
		getline(cin, title);

		if (title.length() <= 50 && title.length() > 0)
		{
			for (unsigned int j = 0; j < title.length(); j++)
			{
				title.at(j) = toupper(title.at(j));
				if (((title.at(j)<'A') && (title.at(j) != ' ')) || ((title.at(j)>'Z') && (title.at(j) != ' ')))
				{
					cout << "\n\t Invalid Input (TRY AGAIN) \n";
					count = 1;
					break;
				}
			}
		}
		else
		{
			cout << "\n\t Input too long (TRY AGAIN) \n";
			count = 1;
		}
	} while (count == 1);
};
// Update ISBN
void bookType::update_isbn()
{
	cout << "Enter the ISBN number : ";
	cin >> ISBN;
};
// Update Price
void bookType::update_price()
{
	cout << "Enter the Price : ";
	cin >> price;
};
// Update Publisher
void bookType::update_publisher()
{
	int count;

	do{
		count = 0;
		cin.clear();
		cin.ignore(10, '\n');

		cout << "Enter the name of publisher : ";
		getline(cin, publisher);

		if (publisher.length() <= 50 && publisher.length() > 0)
		{
			for (unsigned int j = 0; j < publisher.length(); j++)
			{
				publisher.at(j) = toupper(publisher.at(j));
				if (((publisher.at(j)<'A') && (publisher.at(j) != ' ')) || ((publisher.at(j)>'Z') && (publisher.at(j) != ' ')))
				{
					cout << "\n\t Invalid Input (TRY AGAIN) \n";
					count = 1;
					break;
				}
			}
		}
		else
		{
			cout << "\n\t Input too long (TRY AGAIN) \n";
			count = 1;
		}
	} while (count == 1);

};
// Upadate Author
void bookType::update_author()
{
	int count;

	cout << "How many author for this book : ";
	cin >> no_of_author;
	for (int i = 0; i < no_of_author; i++)
	{

		do{
			count = 0;
			cin.clear();
			cin.ignore(10, '\n');

			cout << "Enter the name of Author No :" << i+1 << ": ";
			getline(cin, author[i]);

			if (author[i].length() <= 50 && author[i].length() > 0)
			{
				for (unsigned int j = 0; j < author[i].length(); j++)
				{
					author[i].at(j) = toupper(author[i].at(j));
					if (((author[i].at(j)<'A') && (author[i].at(j) != ' ')) || ((author[i].at(j)>'Z') && (author[i].at(j) != ' ')))
					{
						cout << "\n\t Invalid Input (TRY AGAIN) \n";
						count = 1;
						break;
					}
				}
			}
			else
			{
				cout << "\n\t Input too long (TRY AGAIN) \n";
				count = 1;
			}
		} while (count == 1);
	}
};
// Update Books in Stock
void bookType::modify_books_left()
{
	cout << "Enter the copies in stock : ";
	cin >> copies_left;
};
// Function Overloading
void bookType::modify_books_left(int add)
{
	copies_left = copies_left + (add);
};

// Return title of Book
string bookType::get_title()
{
	return title;
};
// Return ISBN number
int bookType::get_isbn()
{
	return ISBN;
};
// Return price
float bookType::get_price()
{
	return price;
};
// Display Function
void bookType::display()
{
	cout << setw(5) << ISBN
		<< setw(14) << title
		<< setw(6) << price << "$";
	for (int i = 0; i < no_of_author; i++)
		cout << setw(9) << author[i];
	cout << setw(10) << publisher
		<< setw(11) << copies_left << endl;
};

// ======================================================================================= Member Functions for memberType

// Input Function
void memberType::input()
{
	update_name();
	update_id();
	update_membership();
};
// Update the Name 
void memberType::update_name()
{
	int count;
	
	do{
		count = 0;
		cin.clear();
		cin.ignore(10, '\n');

		cout << "Enter your name : ";
		getline(cin, name);

		if (name.length() <= 50 && name.length() > 0)
		{
			for (unsigned int j = 0; j < name.length(); j++)
			{
				name.at(j) = toupper(name.at(j));
				if (((name.at(j)<'A') && (name.at(j) != ' ')) || ((name.at(j)>'Z') && (name.at(j) != ' ')))
				{
					cout << "\n\t Invalid Input (TRY AGAIN) \n";
					count = 1;
					break;
				}
			}
		}
		else
		{
			cout << "\n\t Input too long (TRY AGAIN) \n";
			count = 1;
		}
	} while (count == 1);
};
// Update the ID
void memberType::update_id()
{
	cout << "Enter your ID number : ";
	cin >> ID;
};
// Update Membership status
void memberType::update_membership()
{
	char temp;
	do{
		cout << "Do you have Membership (Y/N) : ";
		cin >> temp;
		temp = toupper(temp);
		if (temp == 'Y')
		{
			membership = true;
			break;
		}
		else if (temp == 'N')
		{
			membership = false;
			break;
		}
		else
		{
			cout << "Enter correct Option ... " << endl;
			cin.ignore();
			cin.clear();
		}
	} while (true);
};
// Update Amount
void memberType::update_amount_spent(float addAmount)
{
	amount_spent = amount_spent + addAmount;
};
// Function Overloading
void memberType::update_amount_spent()
{
	cout << "Enter your amount Spent : ";
	cin >> amount_spent;
};
// Display Function
void memberType::display()
{
	string temp;

	cout << setw(5) << ID
		<< setw(10) << name
		<< setw(14) << books_buy
		<< setw(14) << amount_spent;
	if (membership == true) temp = "Yes"; else temp = "No";
	cout << setw(12) << temp << endl;
};
// Update Books Bought
void memberType::update_books_buy(int add)
{	books_buy = books_buy + add;
};
// Function Overloading
void memberType::update_books_buy()
{
	cout << "How many books you have bought : ";
	cin >> books_buy;
};
// Return Member ID
int memberType::get_id()
{
	return ID;
};
// Return Memebership Status
bool memberType::get_status()
{
	return membership;
};
// get books bought
int memberType::get_book_buy()
{
	return books_buy;
}
// Get Amount 
float memberType::get_amount()
{
	return amount_spent;
}

// ===============================================================================================   Main Function 
int main()
{
	// Declarations
	memberType member[MAX_MEMBER];
	bookType book[MAX_BOOK];
	int sinfo, posB, posM, nB, nM;
	char ch;

	
	do{  // Do Main program again and again  
		cout << endl;

	MAINMENU:do{ 
		system("cls");
		cout << "\t\t\t\t MAIN MENU" << endl
			<< "\t\t\t    1. Books Info  " << endl
			<< "\t\t\t    2. Member Info " << endl
			<< "\t\t\t    X. Exit             " << endl
			<< "\t\t\t******************************" << endl
			<< "\n\n\t\t  Enter your choice : ";

		cin >> ch;
		ch = toupper(ch);
		if (((ch > '0') && (ch <= '2')) || (ch == 'X') || (ch == 'R'))
			break;
	} while (TRUE);

			 switch (ch)
			 {
			 case '1':
			 {
						 do{
							 ch = 0;

						 BOOKMENU:do{
							 system("cls");
							 cout << "********************************************************************************" << endl;
							 cout << "\t\t\t\t BOOKS MENU" << endl
								 << "\t\t\t    1. Add Book " << endl
								 << "\t\t\t    2. Display All Books " << endl
								 << "\t\t\t    3. Update Book Info " << endl
								 << "\t\t\t    4. Search Book " << endl
								 << "\t\t\t    5. Buy Book " << endl
								 << "\t\t\t    6. Save Book Records " << endl
								 << "\t\t\t    7. Back  " << endl
								 << "\t\t\t    X. Exit " << endl
								 << "\t\t\t******************************" << endl
								 << "\n\n\t\t  Enter your choice : ";

							 cin >> ch;
							 ch = toupper(ch);
							 if (((ch > '0') && (ch <= '7')) || (ch == 'X'))
								 break;
						 } while (TRUE);

								  switch (ch)
								  {
								  case '1':
								  {
											  cout << " How many books do you want to add : ";
											  cin >> nB;
											  if (!(cin))
											  {
												  cout << "Enter Valid input " << endl;
												  do{
													  cin.clear();
													  cin.ignore(10, '\n');
													  cout << " How many books do you want to add : ";
													  cin >> nB;
												  } while (!(cin));							
												  
												  for (int i = 0; i < nB; i++)
												  {
													  cout << "\t\t Enter info of Book No # " << i + 1 << endl;
													  book[i].input();
													  cout << "\t*********************************************" << endl;
												  }
											  }

											  else
											  {
												  for (int i = 0; i < nB; i++)
												  {
													  cout << "\t\t Enter info of Book No # " << i + 1 << endl;
													  book[i].input();
													  cout << "\t*********************************************" << endl;
												  }
											  }
											  system("pause");
											  break;
								  }
								  case '2':
								  {
											  cout << "********************************************************************************" << endl;
											  cout << setw(5) << "ISBN"
												  << setw(14) << "title"
												  << setw(6) << "price"
												  << setw(9) << "author"
												  << setw(10) << "publisher"
												  << setw(11) << "Stock Left" << endl;

											  // Display All Books
											  for (int i = 0; i < nB; i++)
												  book[i].display();
											  cout << "********************************************************************************" << endl;
											  system("pause");
											  break;
								  }
								  case '3':
								  {
											  cout << "********************************************************************************" << endl;
											  cout << setw(5) << "ISBN"
												  << setw(14) << "title"
												  << setw(6) << "price"
												  << setw(9) << "author"
												  << setw(10) << "publisher"
												  << setw(11) << "Stock Left" << endl;

											  // Display All Books
											  for (int i = 0; i < nB; i++)
												  book[i].display();
											  cout << "********************************************************************************" << endl;

											  cout << " Enter the ISBN of book you want to update : ";
											  cin >> sinfo;
											  for (int i = 0; i < nB; i++)
											  {
												  if (book[i].get_isbn() == sinfo)
												  {
													  posB = i;
													  break;
												  }
											  }

											  sinfo = -1;
											  ch = 0;
											  do{
												  cout << "********************************************************************************" << endl;
												  cout << "\t\t\t\t UPDATE MENU" << endl
													  << "\t\t\t    1. Update Title " << endl
													  << "\t\t\t    2. Update ISBN " << endl
													  << "\t\t\t    3. Update Price " << endl
													  << "\t\t\t    4. Update Author " << endl
													  << "\t\t\t    5. Update Publisher " << endl
													  << "\t\t\t    6. Update Stock Left " << endl
													  << "\t\t\t    7. Back (Book Menu) " << endl
													  << "\t\t\t    X. Exit " << endl
													  << "\t\t\t******************************" << endl
													  << "\n\n\t\t  Enter your choice : ";

												  cin >> ch;
												  ch = toupper(ch);
												  if (((ch > '0') && (ch <= '7')) || (ch == 'X'))
													  break;
											  } while (TRUE);

											  switch (ch)
											  {
											  case '1':
											  {
														  book[posB].update_title();
														  cout << " Title Updated " << endl;
														  break;
											  }
											  case '2':
											  {
														  book[posB].update_isbn();
														  cout << " ISBN Updated " << endl;
														  break;
											  }
											  case '3':
											  {
														  book[posB].update_price();
														  cout << " Price Updated " << endl;
														  break;
											  }
											  case '4':
											  {
														  book[posB].update_author();
														  cout << " Author Updated " << endl;
														  break;
											  }
											  case '5':
											  {
														  book[posB].update_publisher();
														  cout << " Publisher Updated " << endl;
														  break;
											  }
											  case '6':
											  {
														  book[posB].modify_books_left();
														  cout << " Book Stock Updated " << endl;
														  break;
											  }
											  case '7':
											  {
														  goto BOOKMENU;
														  break;
											  }
											  case 'X':
											  {
														  return 0;
											  }
											  }// update switch end
											  system("pause");
											  break;

								  }
								  case '4':
								  {
											  posB = -1;

											  cout << "********************************************************************************" << endl;
											  cout << setw(5) << "ISBN"
												  << setw(14) << "title"
												  << setw(6) << "price"
												  << setw(9) << "author"
												  << setw(10) << "publisher"
												  << setw(11) << "Stock Left" << endl;

											  // Display All Books
											  for (int i = 0; i < nB; i++)
												  book[i].display();
											  cout << "********************************************************************************" << endl;
											  cout << endl;
											  // Ask for Specific ISBN
											  cout << " Enter the ISBN of book you want to Search : ";
											  cin >> sinfo;
											  // Search that ISBN
											  for (int i = 0; i < nB; i++)
											  {
												  if (book[i].get_isbn() == sinfo)
												  {
													  posB = i;
													  break;
												  }
											  }

											  cout << endl;

											  cout << "********************************************************************************" << endl;
											  cout << setw(5) << "ISBN"
												  << setw(14) << "title"
												  << setw(6) << "price"
												  << setw(9) << "author"
												  << setw(10) << "publisher"
												  << setw(11) << "Stock Left" << endl;
											  // Display Searched Book
											  book[posB].display();
											  cout << "********************************************************************************" << endl;
											  system("pause");
											  break;
								  }
								  case '5':
								  {
											  posB = posM = -1;

											  cout << " Enter the ISBN of the Book : ";
											  cin >> sinfo;
											  // Search that Book ISBN
											  for (int i = 0; i < nB; i++)
											  {
												  if (book[i].get_isbn() == sinfo)
												  {
													  posB = i;
													  break;
												  }
											  }
											  cout << " Enter the member id : ";
											  cin >> sinfo;
											  // Search that Member ID
											  for (int i = 0; i < nB; i++)
											  {
												  if (member[i].get_id() == sinfo)
												  {
													  posM = i;
													  break;
												  }
											  }
											  // Process Function update the stock of book and member info
											  process(member[posM], book[posB]);
											  // display Confirmation
											  cout << " Books Stock and Member info has been Updated ... " << endl;
											  system("pause");
											  break;
								  }
								  case '6':
								  {
											  ofstream book_o;

											  book_o.open("Books.dat", ios::binary | ios::app);
											  if (!book_o)
												  cout << "\t\t Can't Create the File ." << endl;
											  else
											  {
												  book_o.write((char*)&nB, sizeof(int));
												  book_o.write((char*)book, nB* sizeof(bookType));
											  }
											  book_o.close();
											  system("pause");
											  break;
								  }
								  case '7':
								  {
											  goto MAINMENU;
											  break;
								  }
								  case 'X':
								  {
											  return 0;
								  }
								  } // Switch  Book Menu End
						 }while (true);
							  break;
			 }  // End CASE 1 for BOOKS
			 case '2':
			 {
						 do{
							 ch = 0;
						 MEMBERMENU:do{
							 system("cls");
							 cout << "*********************************************************************************" << endl;
							 cout << "\t\t\t\t MEMBER MENU" << endl
								 << "\t\t\t    1. Add Person " << endl
								 << "\t\t\t    2. Display All Members Info " << endl
								 << "\t\t\t    3. Update Member Info " << endl
								 << "\t\t\t    4. Search Member " << endl
								 << "\t\t\t    5. Buy Book " << endl
								 << "\t\t\t    6. Save Member Records " << endl
								 << "\t\t\t    7. Back  " << endl
								 << "\t\t\t    X. Exit " << endl
								 << "\t\t\t******************************" << endl
								 << "\n\n\t\t  Enter your choice : ";

							 cin >> ch;
							 ch = toupper(ch);
							 if (((ch > '0') && (ch <= '7')) || (ch == 'X'))
								 break;
						 } while (TRUE);

									switch (ch)
									{
									case '1':
									{
												cout << " How many Member do you want to add : ";
												cin >> nM;
												if (!(cin))
												{
													cout << "Enter Valid input " << endl;
													do{
														cin.clear();
														cin.ignore(10, '\n');
														cout << " How many Member do you want to add : ";
														cin >> nM;
													} while (!(cin));

													for (int i = 0; i < nM; i++)
													{
														cout << "\t\t Enter info of Member No # " << i + 1 << endl;
														member[i].input();
														cout << "\t************************************************" << endl;
													}
												}

												else
												{
													for (int i = 0; i < nM; i++)
													{
														cout << "\t\t Enter info of Member No # " << i + 1 << endl;
														member[i].input();
														cout << "\t************************************************" << endl;
													}
												}
												system("pause");
												break;

									}
									case '2':
									{
												cout << "********************************************************************************" << endl;
												cout << setw(5) << "ID"
													<< setw(10) << " Name"
													<< setw(14) << " Books Bought"
													<< setw(14) << " Amount Spent"
													<< setw(12) << " Membership" << endl;
												for (int i = 0; i < nM; i++)
													member[i].display();
												cout << "********************************************************************************" << endl;
												system("pause");
												break;
									}
									case '3':
									{
												cout << "********************************************************************************" << endl;
												cout << setw(5) << "ID"
													<< setw(10) << " Name"
													<< setw(14) << " Books Bought"
													<< setw(14) << " Amount Spent"
													<< setw(12) << " Membership" << endl;
												for (int i = 0; i < nM; i++)
													member[i].display();
												cout << "********************************************************************************" << endl;

												cout << endl;
												cout << " Enter the ID of Member you want to Update : ";
												cin >> sinfo;
												for (int i = 0; i < nB; i++)
												{
													if (member[i].get_id() == sinfo)
													{
														posM = i;
														break;
													}
												}

												sinfo = -1;
												ch = 0;
												do{
													cout << "********************************************************************************" << endl;
													cout << "\t\t\t\t UPDATE MENU" << endl
														<< "\t\t\t    1. Update ID " << endl
														<< "\t\t\t    2. Update Name " << endl
														<< "\t\t\t    3. Update Amount Spent " << endl
														<< "\t\t\t    4. Update Books Bought " << endl
														<< "\t\t\t    5. Update Membership " << endl
														<< "\t\t\t    6. Back (Member Menu) " << endl
														<< "\t\t\t    X. Exit " << endl
														<< "\t\t\t******************************" << endl
														<< "\n\n\t\t  Enter your choice : ";

													cin >> ch;
													ch = toupper(ch);
													if (((ch > '0') && (ch <= '6')) || (ch == 'X'))
														break;
												} while (TRUE);

												switch (ch)
												{
												case '1':
												{
															member[posM].update_id();
															cout << " ID Updated " << endl;
															break;
												}
												case '2':
												{
															member[posM].update_name();
															cout << " Name Updated " << endl;
															break;
												}
												case '3':
												{
															member[posM].update_amount_spent();
															cout << " Amount Spent Updated " << endl;
															break;
												}
												case '4':
												{
															member[posM].update_books_buy();
															cout << " Books bought Updated " << endl;
															break;
												}
												case '5':
												{
															member[posM].update_membership();
															cout << " Membership Updated " << endl;
															break;
												}
												case '6':
												{
															goto MEMBERMENU;
															break;
												}
												case 'X':
												{
															return 0;
												}
												}// End of switch

												system("pause");
												break;
									}
									case '4':
									{
												sinfo = 0;
												posM = -1;
												cout << " Enter the ID of member to search : ";
												cin >> sinfo;
												for (int i = 0; i < nM; i++)
												{
													if (member[i].get_id() == sinfo)
													{
														posM = i;
														break;
													}
												}
												// Display Searched Member
												cout << "********************************************************************************" << endl;
												cout << setw(5) << "ID"
													<< setw(10) << " Name"
													<< setw(14) << " Books Bought"
													<< setw(14) << " Amount Spent"
													<< setw(12) << " Membership" << endl;
												member[posM].display();
												cout << "********************************************************************************" << endl;
												system("pause");
												break;
									}
									case '5':
									{

												posB = posM = -1;

												cout << " Enter the ISBN of the Book : ";
												cin >> sinfo;
												// Search that Book ISBN
												for (int i = 0; i < nB; i++)
												{
													if (book[i].get_isbn() == sinfo)
													{
														posB = i;
														break;
													}
												}
												cout << " Enter the member id : ";
												cin >> sinfo;
												// Search that Member ID
												for (int i = 0; i < nB; i++)
												{
													if (member[i].get_id() == sinfo)
													{
														posM = i;
														break;
													}
												}
												// Process Function update the stock of book and member info
												process(member[posM], book[posB]);
												// display Confirmation
												cout << " Books Stock and Member info has been Updated ... " << endl;
												// Saving on file
												ofstream member_o;

												system("pause");
												break;
									}
									case '6':
									{
												// Saving on file
												ofstream member_o;

												member_o.open("Members.dat", ios::binary | ios::app);
												if (!member_o)
													cout << "\t\t Can't Create the File ." << endl;
												else
												{
													member_o.write((char*)&nM, sizeof(int));
													member_o.write((char*)member, nM* sizeof(memberType));
												}
												member_o.close();
												system("pause");
												break;
									}
									case '7':
									{
												goto MAINMENU;
												break;
									}
									case 'X':
									{
												return 0;
									}
									}
						 } while (true);
								break;

			 }
			 case 'R':
			 {
						 // Reading Books Record
						 ifstream book_input;

						 book_input.open("Books.dat", ios::binary);
						 if (!book_input)
							 cout << "\t\t Can't open the File ." << endl;
						 else
						 {
							 book_input.read((char*)&nB, sizeof(int));
							 book_input.read((char*)book, nB* sizeof(bookType));
							 cout << "\t\t The DataBase has been Restored . " << endl;
						 }

						 book_input.close();
						 
						 // Reading Members Record
						 ifstream member_input;

						 member_input.open("Members.dat", ios::binary);
						 if (!member_input)
							 cout << "\t\t Can't open the File ." << endl;
						 else
						 {
							 member_input.read((char*)&nM, sizeof(int));
							 member_input.read((char*)member, nM* sizeof(memberType));
							 cout << "\t\t The DataBase has been Restored . " << endl;
						 }

						 member_input.close();

						 break;
			 }
			 case 'X':
			 {
						 return 0;
			 }
			 }// End MAIN switch


	} while (TRUE);

	system("pause");
	return 0;
}

// Function to Process the Discount for Members
void process(memberType& memID, bookType& BookISBN)
{
	float book_price, amount, amount_S;


	book_price = BookISBN.get_price();

	if (memID.get_status() == true)
	{
		if (memID.get_book_buy() > 5)
		{
			amount_S = memID.get_amount();
			amount = book_price - (amount_S / 5);
			memID.update_amount_spent(amount);
			memID.update_books_buy(-5);
			BookISBN.modify_books_left(-1);
		}
		else
		{
			amount = book_price - ((book_price * 5) / 100);
			memID.update_amount_spent(amount);
			memID.update_books_buy(1);
			BookISBN.modify_books_left(-1);
		}
	}
	else
	{
		amount = book_price;
		memID.update_amount_spent(amount);
		memID.update_books_buy(1);
		BookISBN.modify_books_left(-1);
	}
};
