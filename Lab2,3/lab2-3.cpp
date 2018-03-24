#include "stdafx.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>

void printTab(int start, int mid, int end);
void printInstance(class Document card);

class Document {
private:
	char* docName;
	char* author;
	int day;
	int month;
	int year;
	char* fileName;
	char* type;
	char* docSize;
	char* location;
public:
	//методы (внутри классов)
	void InputDocName();
	void InputAuthor();
	void InputDay();
	void InputMonth();
	void InputYear();
	void InputFileName();
	void InputType();
	void InputDocSize();
	void InputLocation();

	char* getDocName();
	char* getAuthor();
	int getDay();
	int getMonth();
	int getYear();
	char* getFileName();
	char* getType();
	char* getDocSize();
	char* getLocation();

	Document(); //Constructor
	Document(char*, char*, int, int, int, char*, char*, char*, char*); //Initialization
	Document(const Document &N); //Copying
	~Document(); //Destructor
				 //удаляет только динамически выделенные

				 //overloaded +
	Document operator+(Document &obj) {
		Document res;
		res.day = day + obj.day;
		res.month = month + obj.month;
		res.year = year + obj.year;
		return res;
	}

	//overloaded >
	bool operator>(const Document &obj) {
		if (this->year > obj.year)
			return true;
		/*
		if (this->year < obj.year)
		return false;
		if (this->month > obj.month)
		return true;
		if (this->month < obj.month)
		return false;
		if (this->day > obj.day)
		return true;
		*/
		else
			return false;
	}

	//overloaded (int)
	operator int() const {
		return atoi(docSize);
	}

	//overloaded ++()
	int operator++() {
		return ++year;
	}

	//overloaded (=)
	Document operator=(const Document &obj) {
		if (this == &obj)
			return *this;
		if (!docName)
			delete[] docName;
		docName = new char[strlen(obj.docName) + 1];
		strcpy(docName, obj.docName);
		if (!author)
			delete[] author;
		author = new char[strlen(obj.author) + 1];
		strcpy(author, obj.author);
		day = obj.day;
		month = obj.month;
		year = obj.year;
		if (!fileName)
			delete[] fileName;
		fileName = new char[strlen(obj.fileName) + 1];
		strcpy(fileName, obj.fileName);
		if (!type)
			delete[] type;
		type = new char[strlen(obj.type) + 1];
		strcpy(type, obj.type);
		if (!docSize)
			delete[] docSize;
		docSize = new char[strlen(obj.docSize) + 1];
		strcpy(docSize, obj.docSize);
		if (!location)
			delete[] location;
		location = new char[strlen(obj.location) + 1];
		strcpy(location, obj.location);

		return *this;
	}
};

Document::Document()//в классе document инициализация конструктора
{
	docName = new char[strlen("World inside out") + 1];
	strcpy(docName, "World inside out");//в строку docName записываем ...

	author = new char[strlen("Dmitry") + 1];
	strcpy(author, "Dmitry");

	day = 16;
	month = 7;
	year = 2016;

	fileName = new char[strlen("Scenario") + 1];
	strcpy(fileName, "Scenario");

	type = new char[strlen("pdf") + 1];
	strcpy(type, "pdf");

	docSize = new char[strlen("987kb") + 1];
	strcpy(docSize, "987kb");

	location = new char[strlen("D:\\Project\\1") + 1];
	strcpy(location, "D:\\Project\\1");
}

Document::Document(char* docName1, char* author1, int day1, int month1,
	int year1, char* fileName1, char* type1, char* docSize1, char* location1)
{
	docName = new char[strlen(docName1) + 1];
	strcpy(docName, docName1);

	author = new char[strlen(author1) + 1];
	strcpy(author, author1);

	day = day1;
	month = month1;
	year = year1;

	fileName = new char[strlen(fileName1) + 1];
	strcpy(fileName, fileName1);

	type = new char[strlen(type1) + 1];
	strcpy(type, type1);

	docSize = new char[strlen(docSize1) + 1];
	strcpy(docSize, docSize1);

	location = new char[strlen(location1) + 1];
	strcpy(location, location1);
}

Document::Document(const Document &Document)
{
	docName = new char[strlen(Document.docName) + 1];
	strcpy(docName, Document.docName);
	author = new char[strlen(Document.author) + 1];
	strcpy(author, Document.author);
	day = Document.day;
	month = Document.month;
	year = Document.year;
	fileName = new char[strlen(Document.fileName) + 1];
	strcpy(fileName, Document.fileName);
	type = new char[strlen(Document.type) + 1];
	strcpy(type, Document.type);
	docSize = new char[strlen(Document.docSize) + 1];
	strcpy(docSize, Document.docSize);
	location = new char[strlen(Document.location) + 1];
	strcpy(location, Document.location);
}

Document::~Document()
{
	if (docName)
		delete[] docName;
	if (author)
		delete[] author;
	if (fileName)
		delete[] fileName;
	if (type)
		delete[] type;
	if (docSize)
		delete[] docSize;
	if (location)
		delete[] location;
}

void Document::InputDocName()
{
	fflush(stdin);
	int n;
	char DocName[300];
	printf("\n\nEnter Name of Document (no more than 20 symbols and numerics): ");
	do {
		//printf("\n\nEnter Name of Document (no more than 20 symbols and numerics): ");
		gets_s(DocName, 20);
		n = strlen(DocName);
	} while ((n > 20) || (n < 1));
	strcpy(docName, DocName);
}

void Document::InputAuthor()
{
	fflush(stdin);
	int correct, n;
	char Author[300];
	do {
		correct = 0;
		printf("\nEnter Author (no more than 14 symbols): ");
		gets_s(Author, 14);
		n = strlen(Author);
		for (int i = 0; i < n; i++)
			if (isalpha(Author[i]))
				correct++;
	} while ((correct != n) || (n > 14) || (n < 1));
	strcpy(author, Author);
}

void Document::InputDay()
{
	int correct, n, incorrect;
	char Day[300];
	fflush(stdin);
	printf("\nDate of creation:\n");
	do
	{
		correct = 0;
		incorrect = 0;
		printf("\nEnter Day of creation (from 1 to 31): ");
		gets_s(Day, 31);
		n = atoi(Day);	//Convert string to integer
		for (int i = 0; i < strlen(Day); i++)
		{
			if (isdigit(Day[i]))
				correct++;
			if (!isdigit(Day[i]))
				incorrect++;
		}
	} while ((correct > 2) || (n > 31) || (n < 1) || (incorrect != 0));
	day = n;
}

void Document::InputMonth()
{
	int correct, n, incorrect;
	char Month[300];
	fflush(stdin);
	do
	{
		correct = 0;
		incorrect = 0;
		printf("\nEnter Month of creation (from 1 to 12): ");
		gets_s(Month, 12);
		n = atoi(Month);
		for (int i = 0; i < strlen(Month); i++)
		{
			if (isdigit(Month[i]))
				correct++;
			if (!isdigit(Month[i]))
				incorrect++;
		}
	} while ((correct > 2) || (n > 12) || (n < 1) || (incorrect != 0));
	month = n;
}

void Document::InputYear()
{
	int correct, n, incorrect;
	char Year[300];
	fflush(stdin);
	do
	{
		correct = 0;
		incorrect = 0;
		printf("\nEnter Year of creation (from 1900 to 2017): ");
		gets_s(Year, 10);
		n = atoi(Year);
		for (int i = 0; i < strlen(Year); i++)
		{
			if (isdigit(Year[i]))
				correct++;
			if (!isdigit(Year[i]))
				incorrect++;
		}
	} while ((correct > 4) || (n > 2017) || (n < 1900) || (incorrect != 0));
	year = n;
}


void Document::InputFileName()
{
	fflush(stdin);
	int n;
	char FileName[300];
	do {
		printf("\nEnter Name of file (no more than 20 symbols and numerics): ");
		gets_s(FileName, 20);
		n = strlen(FileName);
	} while ((n > 20) || (n < 1));
	strcpy(fileName, FileName);
}

void Document::InputType()
{
	fflush(stdin);
	int correct, n;
	char Type[300];
	do {
		correct = 0;
		printf("\nEnter Type of file (no more than 5 symbols): ");
		gets_s(Type, 5);
		n = strlen(Type);
		for (int i = 0; i < n; i++)
			if (isalpha(Type[i]))
				correct++;
	} while ((correct != n) || (n > 5) || (n < 1));
	strcpy(type, Type);
}

void Document::InputDocSize()
{
	fflush(stdin);
	int n;
	char DocumentSize[300];
	do {
		printf("\nEnter Size of file (no more than 8 symbols and numerics): ");
		gets_s(DocumentSize, 8);
		n = strlen(DocumentSize);
	} while ((n > 8) || (n < 1));
	strcpy(docSize, DocumentSize);
}


void Document::InputLocation()
{
	fflush(stdin);
	int n;
	char Location[300];
	do {
		printf("\nEnter Document location (no more than 30): ");
		gets_s(Location, 30);
		n = strlen(Location);
	} while ((n > 30) || (n < 1));
	strcpy(location, Location);
}



char* Document::getDocName()//метод (метод это свойство класса (ф-ция внутри класса))
{
	return docName;
}

char* Document::getAuthor()
{
	return author;
}

int Document::getDay()
{
	return day;
}

int Document::getMonth()
{
	return month;
}

int Document::getYear()
{
	return year;
}

char* Document::getFileName()
{
	return fileName;
}

char* Document::getType()
{
	return type;
}

char* Document::getDocSize()
{
	return docSize;
}

char* Document::getLocation()
{
	return location;
}

Document global_card("Kursova robota", "John", 11, 06, 2017, "Kursova", "doc", "4.6mb", "D:\\Study\\New");


int menu()
{
	bool flag = true;
	int k, incorrect;
	char input[15];
	do {
		fflush(stdin);
		incorrect = 0;
		printf("\n1: Input data\n");
		printf("2: Show data\n");
		printf("3: Copy data.\n");
		printf("4: Show overloaded + operator.\n");
		printf("5: Show overloaded > operator.\n");
		printf("6: Show overloaded (int) operator.\n");
		printf("7: Show overloaded prefix increment operator.\n");
		printf("8: Show overloaded = operator.\n");
		printf("0: Exit\n");
		gets_s(input, 15);
		for (int i = 0; i < strlen(input); i++)
			if (!isdigit(input[i]))
				incorrect++;
		k = atoi(input);
		if ((incorrect != 0) || (strlen(input) == 0))
			printf("Error. Try again\n");
		else if ((k == 0) || (k == 1) || (k == 2) || (k == 3) || (k == 4) || (k == 5) || (k == 6) || (k == 7) || (k == 8))
			flag = false;
		else
			printf("Error. Try again\n");
	} while (flag);
	return k;
}

int main()
{
	Document default_card, card;

	int choice, correct, choiceCopy;
	correct = 0;
	do {
		choice = menu();
		switch (choice)
		{
		case 1:
		{
			printf("\nInput data:\n");
			card.InputDocName();
			card.InputAuthor();
			card.InputDay();
			card.InputMonth();
			card.InputYear();
			card.InputFileName();
			card.InputType();
			card.InputDocSize();
			card.InputLocation();
			correct++;
			break;
		}
		case 2:
		{
			//Table Printing
			printf("\nDocument(s):");
			printTab(218, 194, 191); //Top
			printf("\n%c%-20s%c%-14s%c", 179, "Document Name", 179, "Author", 179);
			printf("%-10s%c%-20s%c", "Date", 179, "File Name", 179);
			printf("%-5s%c%-8s%c%-30s%c", "Type", 179, "Doc size", 179, "Location", 179);

			printInstance(card);//которая вводится

			printTab(195, 197, 180); //Middle
			printf("\n%-39c~~Initialized Constructor Example.~~%40c", 179, 179);

			printInstance(global_card);//определена перед main (вне ф-ции)

			printTab(195, 197, 180); //Middle
			printf("\n%-44c~~~~Default Constructor.~~~~%43c", 179, 179);

			printInstance(default_card); //Default Constructor

			printTab(192, 193, 217); //Bottom
			printf("\n");
			break;
		}
		case 3: {
			system("CLS");
			fflush(stdin);
			printf("Press 1: Copy default object\nPress 2: Copy your object\n");
			scanf("%d", &choiceCopy);
			switch (choiceCopy) {
			case 1: {
				printTab(218, 194, 191); //Top
				printf("\n%c%-20s%c%-14s%c", 179, "Document Name", 179, "Author", 179);
				printf("%-10s%c%-20s%c", "Date", 179, "File Name", 179);
				printf("%-5s%c%-8s%c%-30s%c", "Type", 179, "Doc size", 179, "Location", 179);

				printTab(195, 197, 180); //Middle
				printf("\n%-39c~~~~Copying Default Constructor.~~~~%40c", 179, 179);

				Document copied_def(default_card);
				printInstance(copied_def); //Copied Default Constructor

				printTab(192, 193, 217); //Bottom
				printf("\n");
				system("pause");
				system("CLS");
				break;
			}
			case 2: {
				printTab(218, 194, 191); //Top
				printf("\n%c%-20s%c%-14s%c", 179, "Document Name", 179, "Author", 179);
				printf("%-10s%c%-20s%c", "Date", 179, "File Name", 179);
				printf("%-5s%c%-8s%c%-30s%c", "Type", 179, "Doc size", 179, "Location", 179);

				printTab(195, 197, 180); //Middle
				printf("\n%-37c~~~~Copying Initialized Constructor.~~~~%38c", 179, 179);

				Document copied_def(card);
				printInstance(copied_def); //Copied Default Constructor

				printTab(192, 193, 217); //Bottom
				printf("\n");
				system("pause");
				system("CLS");
				break;
			}
			}
		}
		case 4:
		{
			Document newcard = default_card + global_card;
			printf("\n + operator:\nDefault(year = 2016) + Global(year = 2017): %i\n\n", newcard.getYear());
			break;
		}
		case 5:
		{
			printf("\n > operator:\nGlobal(year = 2017) > Default(year = 2016)?:\n\n");
			if (global_card > default_card)
				printf("true\n\n");
			break;
		}
		case 6:
		{
			int temp = (int)global_card;
			printf("\n (int) [ int() ] operator:\nGlobal(size = 4.6mb):\n\n");
			printf("(int): %i\n\n", temp);
			break;
		}
		case 7:
		{
			int temp = ++global_card;
			printf("\n prefix increment operator:\nGlobal(year = 2017):\n\n");
			printf("++year: %i\n\n", temp);
			break;
		}
		case 8:
		{
			Document newcard = global_card;
			printf("Global:\n");
			printInstance(global_card);
			printf("\n");
			printf("New:\n");
			printInstance(newcard);
			printf("\n");
			break;
		}
		case 0:
			break;
		}
	} while (choice != 0);
	return 0;
}

void printInstance(class Document card)
{
	printTab(195, 197, 180); //Middle
	printf("\n%c%-20s%c%-14s%c", 179, card.getDocName(), 179, card.getAuthor(), 179);
	printf("%02i/%02i/%4i%c%-20s%c", card.getDay(), card.getMonth(), card.getYear(), 179, card.getFileName(), 179);
	printf("%-5s%c%-8s%c", card.getType(), 179, card.getDocSize(), 179);
	printf("%-30s%c", card.getLocation(), 179);
}

void printTab(int start, int mid, int end)
{
	char line = 196;
	printf("\n%c", start);
	for (int i = 0; i < 20; i++)
		printf("%c", line);
	printf("%c", mid);
	for (int i = 0; i < 14; i++)
		printf("%c", line);
	printf("%c", mid);
	for (int i = 0; i < 10; i++)
		printf("%c", line);
	printf("%c", mid);
	for (int i = 0; i < 20; i++)
		printf("%c", line);
	printf("%c", mid);
	for (int i = 0; i < 5; i++)
		printf("%c", line);
	printf("%c", mid);
	for (int i = 0; i < 8; i++)
		printf("%c", line);
	printf("%c", mid);
	for (int i = 0; i < 30; i++)
		printf("%c", line);
	printf("%c", end);
}