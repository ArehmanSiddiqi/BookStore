// Header.h
#include <iostream>
#include <string>

using namespace std;

// ====================================================== Book Class
class bookType
{
	string title;
	int ISBN;
	float price;
	int copies_left;
	string author[4];
	string publisher;
	int no_of_author;
public:
	bookType::bookType()
	{
		ISBN = copies_left = no_of_author = 0;
		price = 0.0;
	};

	void input();
	void update_title();
	void update_isbn();
	void update_price();
	void update_publisher();
	void update_author();
	void modify_books_left();
	void modify_books_left(int);

	string get_title();
	int get_isbn();
	float get_price();

	void display();
};

// ============================================ Member Class
class memberType
{
	string name;
	int ID;
	bool membership;
	float amount_spent;
	int books_buy;
	int count, average;
public:
	memberType::memberType()
	{
		ID = books_buy = 0;
		membership = false;
		amount_spent = 0.0;
		count = average = 0;
	};

	void input();
	void update_name();
	void update_id();
	void update_membership();
	void update_amount_spent(float);
	void update_amount_spent();
	void update_books_buy(int);
	void update_books_buy();
	int get_book_buy();
	float get_amount();
	void display();

	bool get_status();
	int get_id();
};