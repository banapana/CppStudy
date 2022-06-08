#include<iostream>
#include<cstring>

using namespace std;

class Book
{
private:
	char * title;
	char * isbn;
	int price;

public:
	Book(char* _title, char* _isbn, int _price)
		:price(_price)
	{
		title = new char[strlen(_title) + 1];
		isbn = new char[strlen(_isbn) + 1];

		strcpy(title, _title);
		strcpy(isbn, _isbn);
	}

	~Book()
	{
		delete[] title;
		delete[] isbn;
	}

	void ShowBookInfo()
	{
		cout << "����: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "����: " << price << endl;
	}
};

class EBook : public Book
{
private:
	char * DRMKey;

public:
	EBook(char* _title, char* _isbn, int _price, char* _drmKey)
		:Book(_title, _isbn, _price)
	{
		DRMKey = new char[strlen(_drmKey) + 1];

		strcpy(DRMKey, _drmKey);
	}

	~EBook()
	{
		delete[] DRMKey;
	}

	void ShowEBookInfo()
	{
		ShowBookInfo();
		cout << "����Ű: " << DRMKey << endl;
	}
};

void main()
{
	Book book("���� C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;
	EBook ebook("���� c++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowBookInfo();
}