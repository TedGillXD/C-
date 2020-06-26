#include "Library.h"
#include "Book.h"
#include "ForeignBook.h"
#include "ScienceBook.h"
#include "SocialBook.h"
#include "BasicFunction.h"
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>



void Library::printUI() const
{
	std::cout << "*****************************" << std::endl;
	std::cout << "     欢迎使用图书管理系统      " << std::endl;
	std::cout << "*****************************" << std::endl;
}

Library::Library()
{
	init();
}

void Library::init()
{
	printUI();

	//@TODO: initial BookList form document, print user interface
	ofstream BookListFile("BookList.dat");


	//@TODO: Login UI, have User account and Administrator account
	ofstream UserListFile("UserList.dat");
}

void Library::Add()
{
	system("cls");

	Book* NewBook;
	string BookName, BookCode, SPrice, Press, Author, SCount, BookClass;
	std::cout << "请输入书籍信息（书名，编号，价格，出版社，作者，书籍数量），其中若信息未知则填入“null”:";
	std::cin >> BookName
		>> BookCode
		>> SPrice
		>> Press
		>> Author
		>> SCount;

	if (BookName._Equal("null") || BookCode._Equal("null"))
	{
		std::cout << "书名与编号不能为NULL，添加失败" << std::endl;
		return;
	}
	if (!Press.compare("null"))
		Press.copy(Empty, 4);
	if (!Author.compare("null"))
		Author.copy(Empty, 4);

	double Price = 0.0;
	int Count = 1;

	if (SPrice.compare("null"))
	{
		Price = StringToNum<double>(SPrice);
	}
	if (SCount.compare("null"))
	{
		Count = StringToNum<int>(SCount);
	}

	NewBook = new Book(BookName, BookCode, Price, Press, Author, Count);

	int choose;
	std::cout << "这本书的分类是：" << std::endl
		<< "1. 无分类" << std::endl
		<< "2. 自然科学类" << std::endl
		<< "3. 人文社会类" << std::endl
		<< "4. 外语类" << std::endl;
	std::cin >> choose;



	switch (choose)
	{
	case 1:break;

	case 2:
	{
		ScienceBook* ScienceNewBook = new ScienceBook(NewBook);
		BookList.push_back(ScienceNewBook);
		break;
	}

	case 3:
	{
		SocialBook* SocialNewBook = new SocialBook(NewBook);
		BookList.push_back(SocialNewBook);
		break;
	}
	 
	case 4:
	{
		std::cout << "请输入书籍所用语言" << std::endl;
		std::string Language;
		std::cin >> Language;
		ForeignBook* ForeignNewBook = new ForeignBook(NewBook, Language);
		BookList.push_back(ForeignNewBook);
		break;
	}

	}

	return;
}

void Library::AddCount()
{
	ShowBookList();
	std::cout << "要增加哪一本书的数量：";

	int choose;
	std::cin >> choose;

	int numbers;
	std::cout << "增加库存数量:" << endl;
	std::cin >> numbers;

	choose--;
	BookList[choose]->Add(numbers);

	return;
}

void Library::Lend()
{
	//clear the List in last time
	ChosenBook.clear();

	ShowBookList();
	std::cout << "要借哪几本书(输入0结束): ";

	int choose;
	std::cin >> choose;
	while (choose != 0)
	{
		ChosenBook.push_back(BookList[choose - 1]);
		BookList[choose - 1]->Lend();
		std::cin >> choose;
	}

	return;
}

void Library::Return()
{
	//@TODO: Read the User's lending order and choose which book User wants to return
}

void Library::Serach()
{
	std::cout << "请输入你要搜索的书籍的关键字:";
	std::string KeyWord;
	std::cin >> KeyWord;
	std::vector<Book*>::iterator it = BookList.begin();

	size_t judge;
	for (; *it; ++it)
	{
		//judge BookName
		judge = (*it)->GetBookName().find(KeyWord);
		if (judge != string::npos)
		{
			(*it)->Display();
			continue;
		}

		//judge BookAuthor
		judge = (*it)->GetBookAuthor().find(KeyWord);
		if (judge != string::npos)
		{
			(*it)->Display();
			continue;
		}

		//judge BookPress
		judge = (*it)->GetBookPress().find(KeyWord);
		if (judge != string::npos)
		{
			(*it)->Display();
			continue;
		}
	}

	system("pause");
}

void Library::Purchase()
{
	//clear the List in last time
	ChosenBook.clear();

	ShowBookList();
	std::cout << "要购买哪几本书(输入0结束): ";

	int choose;
	std::cin >> choose;
	while (choose != 0)
	{
		ChosenBook.push_back(BookList[choose - 1]);
		BookList[choose - 1]->Lend();
		std::cin >> choose;
	}

	return;
}

void Library::ShowBookList()
{
	std::vector<Book*>::iterator it = BookList.begin();
	for (int i = 1; *it; ++it, i++)
	{
		std::cout << i;
		it->Display();
	}

	return;
}
