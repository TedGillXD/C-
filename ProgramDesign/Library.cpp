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
#include <conio.h>
#include <cctype>
#include <fstream>


//若Debug != 0， 则开启调试模式，在程序运行的过程中有辅助判断流程的输出和暂停等出现
#define DEBUG if(debug != 0)
int debug = 0;

bool Library::printLogin() const
{
	std::string Account, Password;
	bool bIsLogined = false;
	int times = 0;
	while (!bIsLogined)
	{
		std::cout << "*****************************" << std::endl;
		std::cout << "     欢迎使用图书管理系统      " << std::endl;
		std::cout << "*****************************" << std::endl;
		std::cout << "账号: ";

		std::cin >> Account;
		if (!Account._Equal("admin") && !Account._Equal("user"))
		{
			std::cout << "无此账号,请重新输入" << std::endl;
			continue;
		}

		while (!bIsLogined)
		{
			REFRESH
			std::cout << "*****************************" << std::endl;
			std::cout << "     欢迎使用图书管理系统      " << std::endl;
			std::cout << "*****************************" << std::endl;
			std::cout << "账号: " << Account << std::endl;

			if (times >= 5)
			{
				exit(EXIT_LOGIN_FAIL);
			}
			std::cout << "密码: ";
			std::cin >> Password;
			if (Account._Equal("admin") && Password._Equal("12345"))
			{
				bIsLogined = true;
			}
			else if (Account._Equal("user") && Password._Equal("123456"))
			{
				bIsLogined = true;
			}
			else
			{
				times++;
				std::cout << "密码错误，请重新输入，剩余次数" << 5 - times << "次";
				PAUSE
			}
		}

	}

	if (Account._Equal("admin"))
	{
		return true;
	}
	else return false;
}

void Library::ReadDataText(std::ifstream& ifs)
{
	DocumentCheck(ifs);

	Book* NewBook;
	ScienceBook* NewScienceBook;
	SocialBook* NewSocialBook;
	ForeignBook* NewForeignBook;

	std::string BookName, BookCode, Author, Press;
	double Price;
	int Count;

	while (!ifs.eof())
	{

		int Class;
		ifs >> Class;
		switch (Class)
		{
		case 0:
			NewBook = new Book();
			ifs >> NewBook;
			BookList.push_back(NewBook);
			break;

		case 1:
			NewScienceBook = new ScienceBook();
			ifs >> NewScienceBook;
			BookList.push_back(NewScienceBook);
			break;

		case 2:
			NewSocialBook = new SocialBook();
			ifs >> NewSocialBook;
			BookList.push_back(NewSocialBook);
			break;

		case 3:
			NewForeignBook = new ForeignBook();
			ifs >> NewForeignBook;
			BookList.push_back(NewForeignBook);
			break;
		}

	}
}

Library::Library()
{
	init();
}

void Library::init()
{
	bool bIsAdmin = printLogin();

	//@TODO: initial BookList form document, print user interface
	std::ifstream BookListFile;
	BookListFile.open("BookList.dat");
	ReadDataText(BookListFile);
	BookListFile.close();

	while (true) 
	{

		REFRESH

		std::cout << "*****************************" << std::endl;
		std::cout << "     请选择你要进行的服务      " << std::endl;
		std::cout << "*****************************" << std::endl;
		if (bIsAdmin)
		{
			std::cout << "1.添加书籍数量" << std::endl
				<< "2.添加书籍种类" << std::endl
				<< "3.搜索书籍" << std::endl
				<< "4.查看书籍" << std::endl
				<< "5.修改书籍信息" << std::endl
				<< "按其余键退出" << std::endl;

			char cchoose = _getch();
			int choose = CharToNum(cchoose);
			switch (choose)
			{
			case 1:
				AddCount();
				break;

			case 2:
				Add();
				break;

			case 3:
				Search();
				break;

			case 4:
			{
				ShowBookList();
				PAUSE
				break;
			}

			case 5:
			{
				Modify();
				break;
			}

			default:
				exit(0);
			}
		}
		else
		{
			std::cout << "1.借书" << std::endl
				<< "2.还书" << std::endl
				<< "3.搜索" << std::endl
				<< "4.购买" << std::endl
				<< "按其余键退出" << std::endl;
			char cchoose = _getch();
			int choose = CharToNum(cchoose);
			switch (choose)
			{
			case 1:
				Lend();
				break;

			case 2:
				Return();
				break;

			case 3:
				Search();
				break;

			case 4:
				Purchase();
				break;

			default:
				exit(0);
			}
		}
	}

}

void Library::Add()
{
	REFRESH

	Book* NewBook;
	string BookName, BookCode, SPrice, Press, Author, SCount, BookClass;
	std::cout << "请输入书籍信息（书名，编号，价格，出版社，作者，书籍数量），其中若信息未知则填入“null”，输入-1退出:" << std::endl;
	std::cin >> BookName;

	if (!BookName.compare("-1"))
	{
		return;
	}

	std::cin >> BookCode
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
		Press = "NULL";
	if (!Author.compare("null"))
		Author = "NULL";

	double Price = 0.0;
	int Count = 1;

	if (SPrice.compare("null"))
	{
		Price = StringToDouble(SPrice);
	}
	if (SCount.compare("null"))
	{
		Count = StringToInt(SCount);
	}

	NewBook = new Book(BookName, BookCode, Price, Press, Author, Count);

	char cchoose = '0';
	while (cchoose < '1' || cchoose > '4')
	{
		std::cout << "这本书的分类是：" << std::endl
			<< "1. 无分类" << std::endl
			<< "2. 自然科学类" << std::endl
			<< "3. 人文社会类" << std::endl
			<< "4. 外语类" << std::endl;
		cchoose = _getch();
		if (!isdigit(cchoose) || cchoose < '1' || cchoose > '4')
		{
			std::cout << "选择错误，请重新选择" << std::endl;
			PAUSE
		}

	}

	int choose = CharToNum(cchoose);

	std::ofstream BookListFile("BookList.dat", std::ios::app);
	switch (choose)
	{
	case 1:
		BookList.push_back(NewBook);
		OutputDataText(BookListFile, *NewBook, Null);
		break;

	case 2:
	{
		ScienceBook* ScienceNewBook = new ScienceBook(NewBook);
		BookList.push_back(ScienceNewBook);
		OutputDataText(BookListFile, *ScienceNewBook, Science);
		break;
	}

	case 3:
	{
		SocialBook* SocialNewBook = new SocialBook(NewBook);
		BookList.push_back(SocialNewBook);
		OutputDataText(BookListFile, *SocialNewBook, Social);
		break;
	}

	case 4:
	{
		std::cout << "请输入书籍所用语言" << std::endl;
		std::string Language;
		std::cin >> Language;
		ForeignBook* ForeignNewBook = new ForeignBook(NewBook, Language);
		BookList.push_back(ForeignNewBook);
		OutputDataText(BookListFile, *ForeignNewBook);
		break;
	}

	}

	BookListFile.close();

	return;
}

void Library::AddCount()
{
	bool bIsBookListExist = ShowBookList();
	if (!bIsBookListExist)
	{
		return;
	}

	std::cout << "要增加哪一本书的数量：";

	int choose;
	std::cin >> choose;

	int numbers;
	std::cout << "增加库存数量(输入小于1的数退出):" << std::endl;
	std::cin >> numbers;

	if (numbers <= 0)
	{
		return;
	}

	choose--;
	BookList[choose]->Add(numbers);

	//@TODO: Write the new information to BookList.dat
	std::ofstream BookListFile;
	BookListFile.open("BookList.dat");
	for (int i = 0; i < BookList.size(); i++)
	{
		if (BookList[i]->GetBookClassNumber() != 3)
		{
			OutputDataText(BookListFile, *BookList[i], BookList[i]->GetBookClassNumber());
		}
		else
		{
			OutputDataText(BookListFile, BookList[i]);
		}
	}

	BookListFile.close();

	return;
}

void Library::Lend()
{
	//check if user can lend book
	if (IsBooksLendOut())
	{
		std::cout << "你仍有图书未归还，请先归还上次书籍后再次借书" << std::endl;
		PAUSE
		return;
	}

	//clear the List in last time
	ChosenBook.clear();

	ShowBookList();
	std::cout << "要借哪几本书(输入0结束,输入小于0退出): ";

	int choose;
	std::cin >> choose;

	if (choose < 0)
	{
		return;
	}

	while (choose != 0)
	{
		ChosenBook.push_back(BookList[choose - 1]);
		BookList[choose - 1]->Lend();
		std::cin >> choose;
	}

	//@TODO: write the new information into data document
	std::ofstream BookListFile;
	BookListFile.open("BookList.dat");
	for (int i = 0; i < BookList.size(); i++)
	{
		if (BookList[i]->GetBookClassNumber() != 3)
		{
			OutputDataText(BookListFile, *BookList[i], BookList[i]->GetBookClassNumber());
		}
		else
		{
			OutputDataText(BookListFile, BookList[i]);
		}
	}

	BookListFile.close();


	//Write the Borrow information into BorrowedBook.dat
	std::ofstream BorrowedBookFile("BorrowedBook.dat");
	DocumentCheck(BorrowedBookFile);
	std::vector<Book*>::iterator itl = ChosenBook.begin();
	for (; itl != ChosenBook.end(); ++itl)
	{
		BorrowedBookFile << (*itl)->GetBookName() << " ";
	}

	return;
}

void Library::Return()
{
	//@TODO: Read the User's lending order and choose which book User wants to return
	std::ifstream BorrowedBookFile("BorrowedBook.dat");
	DocumentCheck(BorrowedBookFile);

	std::vector<std::string> BookName;
	while (!BorrowedBookFile.eof())
	{
		std::string TempName;
		BorrowedBookFile >> TempName;
		BookName.push_back(TempName);
	}

	BorrowedBookFile.close();

	std::vector<std::string>::iterator its = BookName.begin();

	DEBUG
	{
		for (; its != BookName.end(); ++its)
		{
			std::cout << its->c_str() << std::endl;
		}
	}

	std::vector<Book*>::iterator itb = BookList.begin();
	for (its = BookName.begin(); its != BookName.end(); ++its)
	{
		for (itb = BookList.begin(); itb != BookList.end(); ++itb)
		{
			if (!((*itb)->GetBookName().compare(its->c_str())))

			{
				(*itb)->Return();
			}
		}
	}

	DEBUG
	{
		PAUSE
	}

	std::ofstream BorrowedBook("BorrowedBook.dat");
	BorrowedBook.close();

	std::ofstream BookListFile;
	BookListFile.open("BookList.dat");
	DocumentCheck(BookListFile);
	for (int i = 0; i < BookList.size(); i++)
	{
		if (BookList[i]->GetBookClassNumber() != 3)
		{
			OutputDataText(BookListFile, *BookList[i], BookList[i]->GetBookClassNumber());
		}
		else
		{
			OutputDataText(BookListFile, BookList[i]);
		}
	}

	BookListFile.close();
}

void Library::Search()
{
	std::string KeyWord;
	do
	{
		REFRESH

		std::cout << "请输入你要搜索的书籍的关键字(不接受null):";
		std::cin >> KeyWord;
	} while (KeyWord == "null" || KeyWord == "NULL");

	std::vector<Book*>::iterator it = BookList.begin();
	size_t judge;
	bool bIsFound = false;
	for (; it != BookList.end(); ++it)
	{
		//judge BookName
		judge = (*it)->GetBookName().find(KeyWord);
		if (judge != string::npos)
		{
			(*it)->Display();
			bIsFound = true;
			continue;
		}

		//judge BookAuthor
		judge = (*it)->GetBookAuthor().find(KeyWord);
		if (judge != string::npos)
		{
			(*it)->Display();
			bIsFound = true;
			continue;
		}

		//judge BookPress
		judge = (*it)->GetBookPress().find(KeyWord);
		if (judge != string::npos)
		{
			(*it)->Display();
			bIsFound = true;
			continue;
		}
	}

	if (!bIsFound)
	{
		std::cout << "没有查询到相关书籍" << std::endl;
	}

	PAUSE
}

void Library::Purchase()
{
	//clear the List in last time
	ChosenBook.clear();

	ShowBookList();
	std::cout << "要购买哪几本书(输入0结束): ";

	int choose;
	std::cin >> choose;
	double sum = 0;
	while (choose != 0)
	{
		ChosenBook.push_back(BookList[choose - 1]);
		sum += BookList[choose - 1]->Buy();
		std::cin >> choose;
	}

	std::cout << "共计金额：" << sum << std::endl
		<< "订单号" << GetRandomNumberInString() << std::endl
		<< "书籍信息：" << std::endl;

	std::vector<Book*>::iterator it = BookList.begin();
	for (; it != BookList.end(); ++it)
	{
		std::cout << "\t" << "《" << (*it)->GetBookName() << "》" << std::endl;
	}

	//@TODO: write the new information into data document
	std::ofstream BookListFile;
	BookListFile.open("BookList.dat");
	for (int i = 0; i < BookList.size(); i++)
	{
		if (BookList[i]->GetBookClassNumber() != 3)
		{
			OutputDataText(BookListFile, *BookList[i], BookList[i]->GetBookClassNumber());
		}
		else
		{
			OutputDataText(BookListFile, BookList[i]);
		}
	}

	BookListFile.close();

	PAUSE

	return;
}

void Library::Modify()
{
	ShowBookList();

	std::cout << "请输入要修改的图书序号(输入0或以下或大于图书数量的数退出)" << std::endl;
	char cchoose = _getch();
	int choose = CharToNum(cchoose);
	choose--;

	if (choose < 0 || choose > BookList.size())
	{
		return;
	}

	DEBUG
	{
		std::cout << choose << std::endl;
		std::cout << BookList.size() << std::endl;
		PAUSE
	}

	bool judge = BookList[choose]->Modify();

	if (judge)
	{
		std::ofstream BookListFile;
		BookListFile.open("BookList.dat");
		for (int i = 0; i < BookList.size(); i++)
		{
			if (BookList[i]->GetBookClassNumber() != 3)
			{
				OutputDataText(BookListFile, *BookList[i], BookList[i]->GetBookClassNumber());
			}
			else
			{
				OutputDataText(BookListFile, BookList[i]);
			}
		}

		BookListFile.close();
	}

}

// if the BookList empty, return false
bool Library::ShowBookList()
{
	std::cout << "序号    类别      书名               编号      价格     作者          出版社         剩余数量      语言" << std::endl;
	if (!BookList.empty())
	{
		std::vector<Book*>::iterator it = BookList.begin();
		for (int i = 1; it != BookList.end(); ++it, i++)
		{
			std::cout <<" "<< i << "     ";
			(*it)->Display();
		}
		return true;
	}
	else
	{
		std::cout << "书架为空" << std::endl;
		PAUSE
		return false;
	}
}
