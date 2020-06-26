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
	std::cout << "     ��ӭʹ��ͼ�����ϵͳ      " << std::endl;
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
	std::cout << "�������鼮��Ϣ����������ţ��۸񣬳����磬���ߣ��鼮����������������Ϣδ֪�����롰null��:";
	std::cin >> BookName
		>> BookCode
		>> SPrice
		>> Press
		>> Author
		>> SCount;

	if (BookName._Equal("null") || BookCode._Equal("null"))
	{
		std::cout << "�������Ų���ΪNULL�����ʧ��" << std::endl;
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
	std::cout << "�Ȿ��ķ����ǣ�" << std::endl
		<< "1. �޷���" << std::endl
		<< "2. ��Ȼ��ѧ��" << std::endl
		<< "3. ���������" << std::endl
		<< "4. ������" << std::endl;
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
		std::cout << "�������鼮��������" << std::endl;
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
	std::cout << "Ҫ������һ�����������";

	int choose;
	std::cin >> choose;

	int numbers;
	std::cout << "���ӿ������:" << endl;
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
	std::cout << "Ҫ���ļ�����(����0����): ";

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
	std::cout << "��������Ҫ�������鼮�Ĺؼ���:";
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
	std::cout << "Ҫ�����ļ�����(����0����): ";

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
