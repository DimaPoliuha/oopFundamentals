#include "stdafx.h"
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>



//Base Class
class Date {
protected:
	int	day;
	int month;
	int year;

public:
	virtual void Show() {
		printf("Date\t\t\t\t\t\t\t%3i/%02i/%4i\n", day, month, year);
	}
	Date(); //Constructor by Default
	Date(int, int, int); //Initializing Constructor
	Date(const Date &Date); //Copying Constructor
	~Date() {}; //Destructor
};

Date::Date() {
	day = 22;
	month = 10;
	year = 2009;
}

Date::Date(int dday, int dmonth, int dyear) {
	this->day = dday;
	this->month = dmonth;
	this->year = dyear;
}

Date::Date(const Date &Date) {
	this->day = Date.day;
	this->month = Date.month;
	this->year = Date.year;
}



//Base Class
class Bus {
protected:
	char* model;
	int seats;
	float consumption;

public:
	virtual void Show() {
		printf("Bus:\n");
		printf("Model\t\t\t\t\t\t%17s\n", model);
		printf("Seats\t\t\t\t\t\t\t%3i\n", seats);
		printf("Consumption\t\t\t\t\t\t%6.2f\n", consumption);
	}
	Bus(); //Constructor by Default
	Bus(char*, int, float); //Initializing Constructor
	Bus(const Bus &Bus); //Copying Constructor
	~Bus(); //Destructor
};

Bus::Bus() {
	model = new char[strlen("Icarus") + 1];
	strcpy(model, "Icarus");
	seats = 26;
	consumption = 20.9;
}

Bus::Bus(char* mmodel, int sseats, float cconsumption) {
	this->model = new char[strlen(mmodel) + 1];
	strcpy(model, mmodel);
	this->seats = sseats;
	this->consumption = cconsumption;
}

Bus::Bus(const Bus &Bus) {
	this->model = new char[strlen(Bus.model) + 1];
	strcpy(model, Bus.model);
	this->seats = Bus.seats;
	this->consumption = Bus.consumption;
}

Bus::~Bus()
{
	if (!model)
		delete[] model;
}



/////////
class Person : public Date { //virtual public date
protected:
	char* name;
	char* surname;
public:
	void Show() {
		printf("\nPerson:\n");
		printf("Name\t\t\t\t\t\t%13s\n", name);
		printf("Surname\t\t\t\t\t\t%14s\n", surname);
		Date::Show();
	}
	Person(); //Constructor by Default
	Person(int, int, int, char*, char*); //Initializing Constructor
	Person(const Person &person); //Copying Constructor
	~Person(); //Destructor
};

Person::Person() : Date(12, 7, 1988) {
	this->name = new char[strlen("Yann") + 1];
	this->name = strcpy(name, "Yann");
	this->surname = new char[strlen("Martel") + 1];
	this->surname = strcpy(surname, "Martel");
}

Person::Person(int pday, int pmonth, int pyear, char* tpname, char* tpsurname) : Date(pday, pmonth, pyear) {
	this->name = new char[strlen(tpname) + 1];
	this->name = strcpy(name, tpname);
	this->surname = new char[strlen(tpsurname) + 1];
	this->surname = strcpy(surname, tpsurname);
}

Person::Person(const Person &person) : Date(person) {
	this->name = new char[strlen(person.name) + 1];
	this->name = strcpy(name, person.name);
	this->surname = new char[strlen(person.surname) + 1];
	this->surname = strcpy(surname, person.surname);
}

Person::~Person() {
	if (!name)
		delete[] name;
	if (!surname)
		delete[] surname;
}



//Base Class
class Category {
protected:
	int rank;
	float salary;

public:
	virtual void Show() {
		printf("Category:\n");
		printf("Rank\t\t\t\t\t\t\t%2i\n", rank);
		printf("Salary\t\t\t\t\t\t\t%8.2f\n", salary);
	}
	Category(); //Constructor by Default
	Category(int, float); //Initializing Constructor
	Category(const Category &Category); //Copying Constructor
	~Category() {}; //Destructor
};

Category::Category() {
	rank = 2;
	salary = 2078.94;
}

Category::Category(int rrank, float ssalary) {
	this->rank = rrank;
	this->salary = ssalary;
}

Category::Category(const Category &Category) {
	this->rank = Category.rank;
	this->salary = Category.salary;
}



/////////
class Driver : public Person, public Category {
public:
	void Show() {
		printf("Driver:");
		Person::Show();
		Category::Show();
	}
	Driver(); //Constructor by Default
	Driver(int, int, int, char*, char*, int, float); //Initializing Constructor
	Driver(const Driver &Driver); //Copying Constructor
	~Driver() {}; //Destructor
};

Driver::Driver() : Person(), Category() {
}

Driver::Driver(int pday, int pmonth, int pyear, char* tpname, char* tpsurname, int rrank, float ssalary) : Person(pday, pmonth, pyear, tpname, tpsurname),
Category(rrank, ssalary) {
}

Driver::Driver(const Driver &Driver) : Person(Driver), Category(Driver) {
}



/////////
class Application : public Date {
protected:
	char* destination;
	float length;
public:
	void Show() {
		printf("Application:\n");
		printf("Destination\t\t\t\t%21s\n", destination);
		printf("Length\t\t\t\t\t\t\t%6.1f\n", length);
		Date::Show();
	}
	Application(); //Constructor by Default
	Application(int, int, int, char*, float); //Initializing Constructor
	Application(const Application &Application); //Copying Constructor
	~Application(); //Destructor
};

Application::Application() : Date() {
	this->destination = new char[strlen("Kyiv") + 1];
	this->destination = strcpy(destination, "Kyiv");
	this->length = 456.8;
}

Application::Application(int pday, int pmonth, int pyear, char* ddestination, float llength) : Date(pday, pmonth, pyear) {
	this->destination = new char[strlen(ddestination) + 1];
	this->destination = strcpy(destination, ddestination);
	this->length = llength;
}

Application::Application(const Application &Application) : Date(Application) {
	this->destination = new char[strlen(Application.destination) + 1];
	this->destination = strcpy(destination, Application.destination);
	this->length = Application.length;
}

Application::~Application() {
	if (!destination)
		delete[] destination;
}



/////////
class Trip : public Application, public Driver, public Bus, public Date {
protected:
	float totalConsumption;
public:
	void Show() {
		printf("Trip:\n");
		printf("Total consumption\t\t\t\t\t%5.1f\n", totalConsumption);
		Application::Show();
		Driver::Show();
		Bus::Show();
		Date::Show();
	}
	Trip(); //Constructor by Default
	Trip(int, int, int, char*, float,
		int, int, int, char*, char*, int, float,
		char*, int, float,
		int, int, int,
		float); //Initializing Constructor
	Trip(const Trip &Trip); //Copying Constructor
	~Trip() {}; //Destructor
};

Trip::Trip() : Application(), Driver(), Bus(), Date() {
	this->totalConsumption = 45.9;
}

Trip::Trip(int pday, int pmonth, int pyear, char* ddestination, float llength,
	int dday, int dmonth, int dyear, char* tpname, char* tpsurname, int rrank, float ssalary,
	char* mmodel, int sseats, float cconsumption,
	int ddday, int ddmonth, int ddyear,
	float ttotalConsumption) :
	Application(pday, pmonth, pyear, ddestination, llength),
	Driver(dday, dmonth, dyear, tpname, tpsurname, rrank, ssalary),
	Bus(mmodel, sseats, cconsumption),
	Date(ddday, ddmonth, ddyear) {
	this->totalConsumption = ttotalConsumption;
}

Trip::Trip(const Trip &Trip) : Application(Trip), Driver(Trip), Bus(Trip), Date(Trip) {
	this->totalConsumption = Trip.totalConsumption;
}



/////////
class List : public Trip {
private:
	Trip* tripList;
	int size;
public:
	void Show() {
		printf("List ");
		for (size_t i = 0; i < size; i++)
		{
			tripList[i].Trip::Show();
			printf("\n\n\n");
		}
	}
	List(); //Constructor by Default
	List(Trip* arr, int s); //Initializing Constructor
	List(const List &List); //Copying Constructor
	~List(); //Destructor
};

List::List(Trip* arr, int lenght) {
	tripList = new Trip[lenght];
	size = lenght;

	for (size_t i = 0; i < lenght; i++) {
		tripList[i] = arr[i];
	}
}
List::List(const List & List) {
	tripList = new Trip[List.size];
	size = List.size;

	for (size_t i = 0; i < size; i++) {
		tripList[i] = List.tripList[i];
	}
}
List::~List() {
	delete[] tripList;
}




int main()
{
	//initializing
	Trip t1(14, 3, 2011, "Lviv", 564.3,
		26, 6, 1987, "John", "Stone", 1, 4207.34,
		"Mercedes", 18, 16.4,
		18, 3, 2011,
		72.2);
	printf("\t\t<<INITIALIZED TRIP>>\n\n");
	t1.Show();

	//default
	Trip t2;
	printf("\n\n\t\t");
	printf("<<TRIP BY DEFAULT>>\n\n");
	t2.Show();

	//copying
	Trip t3(t1);
	printf("\n\n\t\t");
	printf("<<COPIED TRIP>>\n\n");
	t3.Show();

	printf("\n\n\n\n\t\t");
	printf("<<LIST OF TRIPS>>\n\n");
	Trip arr[3] = { t1, t2, t3 };

	List main(arr, 3);
	main.List::Show();

	printf("\n\n\t\tSIZES OF CLASSES:\n");
	printf("Date \t\t\t\t\t %i\n", sizeof(Date));
	printf("Bus \t\t\t\t\t %i\n", sizeof(Bus));
	printf("Person \t\t\t\t\t %i\n", sizeof(Person));
	printf("Category \t\t\t\t %i\n", sizeof(Category));
	printf("Driver \t\t\t\t\t %i\n", sizeof(Driver));
	printf("Application \t\t\t\t %i\n", sizeof(Application));
	printf("Trip \t\t\t\t\t %i\n", sizeof(Trip));
	printf("List \t\t\t\t\t %i", sizeof(List));

	printf("\n\n\t\t");
	printf("[Press Enter to exit]\n");
	getchar();
	return (0);
}