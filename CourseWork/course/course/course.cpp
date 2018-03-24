#include "stdafx.h"
#include <cstdlib>
#include <cstring>
#include <string>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>
#include "List.h"
#include "CirclesSigned.h"

#define M_PI 3.14159265358979323846

int checkMenu(void);

// Ввід
CircleSquare input(CircleSquare& obj);

// Статистична характеристика
template <typename T>
T statistics(T* arr, int length);


int main(void)
{
	int choice, correct = 0;

	List q(CircleSquare(11.11, 15, 0.5));

	List list;
	CircleSquare lst_1(11.11, 15, 0.5);
	CircleSquare lst_2(44.61, 1, 4);
	CircleSquare lst_3(21.51, 21, 10);
	CircleSquare lst_4(14.41, 3.2, 13.6);
	CircleSquare lst_5(10.21, 22.2, 25.3);
	CircleSquare lst_6(111.1, 52.93, 33.35);
	CircleSquare lst_7(11.11, 22.22, 33.33);
	CircleSquare lst_8(1.11, 42.12, 83.13);
	CircleSquare lst_9(190.1, 26.6, 73.8);
	CircleSquare lst_10;

	list.addCircleSquare(lst_1);
	list.addCircleSquare(lst_2);
	list.addCircleSquare(lst_3);
	list.addCircleSquare(lst_4);
	list.addCircleSquare(lst_5);
	list.addCircleSquare(lst_6);
	list.addCircleSquare(lst_7);
	list.addCircleSquare(lst_8);
	list.addCircleSquare(lst_9);
	list.addCircleSquare(lst_10);

	CirclesSigned cssList;
	CircleSigned cl_1(1.11, 1.35, 6.57, "Hello");
	CircleSigned cl_2(14.41, 3.2, 13.6, "#One");
	CircleSigned cl_3(190.1, 26.6, 73.8, "Love");
	CircleSigned cl_4(21.51, 21, 10, "Four");
	CircleSigned cl_5(44.61, 1, 4, "I");
	CircleSigned cl_6;

	cssList.addCircleSigned(cl_1);
	cssList.addCircleSigned(cl_2);
	cssList.addCircleSigned(cl_3);
	cssList.addCircleSigned(cl_4);
	cssList.addCircleSigned(cl_5);
	cssList.addCircleSigned(cl_6);

	// Меню
	do {
		choice = checkMenu();
		switch (choice)
		{
		case 1:
		{
			std::cout << std::endl << "Vvedit danni:" << std::endl;
			CircleSquare new_lst;
			new_lst = input(new_lst);

			list.addCircleSquare(new_lst);
			correct++;
			break;
		}
		case 2:
		{
			std::cout << std::endl << "Vivid dannih:" << std::endl << list;
			break;
		}
		case 3:
		{
			std::string dir = "D:/Study/OOP/";
			ofstream textFile(dir);
			bool check = false;
			char answer;
			do {
				std::cout << std::endl << "Vvoditi direktoriyu? (y/n)";
				std::cin >> answer;
				if (answer == 'y' || answer == 'Y') {
					std::cout << "Vvedit direktoriyu(disk:/[folder/])" << std::endl;
					std::string newdir;
					std::cin >> newdir;
					dir = newdir;
					std::cout << "Direktoriya  " << dir << std::endl;
					check = true;
				}
				else if (answer == 'n' || answer == 'N') {
					std::cout << "Vikoristannia direktorii za zamovchuvaniam (D:/Study/OOP/)" << std::endl;
					check = true;
				}
				else
					check == false;
			} while (!check);

			textFile.open(dir + std::string("textFile.txt"), ios::trunc);
			if (!textFile)
				throw ("Nemozhlivo vidkriti file\n");
			else {
				textFile << list;
				std::cout << "Uspishno" << std::endl;

				list.printBinary(dir);
			}
			textFile.close();
			break;
		}
		case 4:
		{
			char answer;
			char answer_dir;
			std::string dir = "D:/Study/OOP/";
			do
			{
				std::cout << std::endl << "Zchitati z textovogo, abo binarnogo file? (t/b)" << std::endl;
				std::cin >> answer;
			} while (!(answer == 't' || answer == 'T' || answer == 'b' || answer == 'B'));

			std::cout << std::endl << "Vvoditi direktoriyu? (y/n)";
			std::cin >> answer_dir;
			if (answer_dir == 'n' || answer_dir == 'N')
				std::cout << "Vikoristannia direktorii za zamovchuvaniam (D:/Study/OOP/)" << std::endl;
			else if (answer_dir == 'y' || answer_dir == 'Y')
			{
				std::cout << "Vvedit direktoriyu(disk:/[folder/])" << std::endl;
				std::string newdir;
				std::cin >> newdir;
				dir = newdir;
				std::cout << "Direktoriya  " << dir;
			}

			if (answer == 't' || answer == 'T') {
				std::string line;
				ifstream itext(dir + std::string("textFile.txt"));
				if (itext.is_open()) {
					std::cout << "Text vidkrito uspishno" << std::endl;
					while (getline(itext, line))
						std::cout << line << std::endl;
					itext.close();
				}
				else
					std::cout << "Pomilka pri vidkritti file" << std::endl;
			}
			else if (answer == 'b' || answer == 'B') {
				list.readBinary(dir);
			}
			break;
		}
		case 5:
		{
			char answer;
			do
			{
				std::cout << std::endl << "Shukatu po number, abo po char? (n/c)" << std::endl;
				std::cin >> answer;
			} while (!(answer == 'n' || answer == 'N' || answer == 'c' || answer == 'C'));

			if (answer == 'n' || answer == 'N') {
				double rad;

				std::cout << std::endl << "Vvedit radius:" << std::endl;
				std::cin >> rad;
				bool check = false;
				for (int i = 0; i < list.getListLength(); i++) {
					if (list[i].getRadius() == rad)
					{
						std::cout << std::endl << "Uspishno" << endl;
						std::cout << list[i];
						check = true;
						break;
					}
				}
				if (!check)
					std::cout << std::endl << "Ne znaideno" << std::endl;
			}
			else if (answer == 'c' || answer == 'C') {
				char* text = new char[64];

				std::cout << std::endl << "Vvedit napis:" << std::endl;
				std::cin >> text;
				bool check = false;
				for (int i = 0; i < cssList.getListLength(); i++) {
					if (!strcmp(cssList[i].getSign(), text))
					{
						std::cout << std::endl << "Uspishno\n";
						std::cout << cssList[i];
						check = true;
						break;
					}
				}
				if (!check)
					std::cout << std::endl << "Ne znaideno" << std::endl;
			}
			else
				throw("Ne isnuye takoi optsii\n");
			break;
		}
		case 6:
		{
			double* stat = new double[list.getListLength()];
			double* stat1 = new double[cssList.getListLength()];

			for (int i = 0; i < list.getListLength(); i++) stat[i] = list[i].getRadius();
			double average = statistics(stat, list.getListLength());

			for (int i = 0; i < cssList.getListLength(); i++) stat1[i] = cssList[i].getRadius();
			double average1 = statistics(stat1, cssList.getListLength());

			std::cout << std::endl << "Statistichna harakteristika" << std::endl;

			std::cout << "Seredne znachennia plosch kil: " << average << std::endl;
			std::cout << "Seredne znachennia plosch kil z napisom: " << average1 << std::endl;
			std::cout << "Seredne znachennia kil: " << list.getListLength() << std::endl << std::endl;
			delete[] stat;
			break;
		}
		case 0:
			std::cout << std::endl << "Zavershennia programi" << std::endl;
			break;
		default:
			throw("Ne isnuye takoi optsii\n");
		}
	} while (choice != 0);
	return (0);
}

int checkMenu(void)
{
	fflush(stdin);
	bool check = true;
	int answer, incorrect;
	char *input = new char[10];
	do {
		incorrect = 0;
		std::cout << std::endl << "\tOberit optsiyu:" << std::endl;
		std::cout << "  1.Vvid dannih" << std::endl;
		std::cout << "  2.Vivid dannih" << std::endl;
		std::cout << "  3.Zapis dannih u file(text/bin)" << std::endl;
		std::cout << "  4.Zchituvannia dannih z file" << std::endl;
		std::cout << "  5.Poshuk v masivi obiektiv" << std::endl;
		std::cout << "  6.Statistichna harakteristika" << std::endl;
		std::cout << "  0.Vihid" << std::endl << std::endl;
		std::cin >> input;
		for (int i = 0; i < strlen(input); i++)
			if (!isdigit(input[i]))
				incorrect++;
		answer = atoi(input);
		if ((incorrect != 0) || (strlen(input) == 0))
			std::cout << "Pomilka" << std::endl;
		else if ((answer == 0) || (answer == 1) || (answer == 2) || (answer == 3) || (answer == 4) || (answer == 5) || (answer == 6))
			check = false;
		else
			std::cout << "Pomilka" << std::endl;
	} while (check);

	delete[] input;
	return answer;
}

CircleSquare input(CircleSquare& obj)
{
	obj.inputX();
	obj.inputY();
	obj.inputRadius();

	return obj;
}

template <typename T>
T statistics(T* arr, int length)
{
	T area = 0;
	for (int i = 0; i < length; i++)
		area += M_PI * arr[i] * arr[i];
	return area / length;
}