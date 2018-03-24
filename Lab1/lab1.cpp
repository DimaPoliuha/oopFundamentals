#include "stdafx.h"
#include "cstdlib" 
#include <math.h>
#include <time.h>
#include <iostream>

#define PARAMETERS_ARR_LENGTH 5
#define SYMBOL 0xB2
#define A 70
#define DELTA 0.15

typedef struct {
	double* paramsPtr;//массив
	double** resultsPtr;//указатель на массив
} progData;


void clearFile();

void parInput(double param[]);

int wrongPar(double param[]);

void handleErrors(double param[], int error);

int size_of_array(double param[], double** resultsPtr);

void printPtr(progData data);

void function(double parameters[], double* results);

double functionForm(double a, double b, double x);

int *normalizeArray(double oldResults[], int size);

void printHistogram(int* normArray, int size);

double* randArray(double* results, int size);

double* smooth(double* arr, int size);

void fileWrite(double* array1, double* array2, int size);




int main()
{
	clearFile();

	double parameters[PARAMETERS_ARR_LENGTH];

	parInput(parameters);

	double* results;
	int sizeResults = size_of_array(parameters, &results);
	results = new double[sizeResults];
	progData var15 = { parameters, &results };

	printPtr(var15);

	function(parameters, results);
	int* normArray = normalizeArray(results, sizeResults);

	printHistogram(normArray, sizeResults);

	double* randomArray = randArray(results, sizeResults);
	double* smoothArray = smooth(randomArray, sizeResults);

	fileWrite(randomArray, smoothArray, sizeResults);
	system("pause");
	return 0;
}

void clearFile() //очистка txt-файла
{
	FILE* file;
	if ((file = fopen("C:\\Lab1Var15\\Var15.txt", "w")) == NULL) {
		printf("Couldn't open file\n");
	}
	else {
		fclose(file);
	}
}

void parInput(double param[]) //ввод параметров
{

	char* symbol_param[PARAMETERS_ARR_LENGTH] = { "a", "b", "x1", "x2 (> x1)", "dx (< 1)" };

	for (int i = 0; i < PARAMETERS_ARR_LENGTH; i++) {
		printf("Enter parameter %s : ", symbol_param[i]);
		scanf_s("%lf", &param[i]);
	}

	int error = wrongPar(param);
	if (error) {
		handleErrors(param, error);
	}

}

int	wrongPar(double param[]) //проверка правильности ввода параметров
{
	double b = param[1],
		x_1 = param[2],
		x_2 = param[3],
		dx = param[4];

	int error = 0;

	if ((x_1 > 0 || x_2 > 0) && (x_1 == 0 || x_2 == 0)) {
		error = 1;
	}
	if (x_1 > x_2) {
		error = 2;
	}
	if (dx <= 0 || dx > 1) {
		error = 3;
	}

	return error;
}

void handleErrors(double param[], int error) //сообщение о ошибке при вводе параметров
{
	printf("Error: ");
	if (error == 3) {
		printf("step < 0.\n");
		system("pause");
		exit(1);
	}
	if (error == 2) {
		printf("x1 > x2.\n");
		system("pause");
		exit(1);
	}
	if (error == 1) {
		printf("x can not be 0.\n");
		system("pause");
		exit(1);
	}
}

int size_of_array(double param[], double** resultsPtr) //определ€ет кооличество пам€ти дл€ массива с результатами
{
	int count = 0;
	double x_1 = param[2];
	double x_2 = param[3];
	double step = param[4];

	double i;
	for (i = x_1; i < x_2; i += step) {
		count++;
	}
	if (i != x_2) {
		count++;
	}

	return count;
}

void printPtr(progData data) //выводит на экран адреса указателей и их значени€ в структуре
{
	printf("%s%p\n%s%p\n%s%p\n%s%p\n\n\n",
		"Adress of parameters array: ", data.paramsPtr,//адрес указател€ который указывает на начало массива paramsPtr
		"Adress of results array: ", data.resultsPtr,//адрес указател€ который указывает на указатель который €вл€етс€ началом массива resultsPtr
		"Value of pointer of parameters array: ", &(data.paramsPtr),//указатель на 1-е(берем по адресу)
		"Value of pointer of results array: ", &(data.resultsPtr));//указатаель на 2-е(берем по адресу)
}

void function(double parameters[], double* results) //вычисление значений ф-ции и вывод таблицы
{
	int step = 0;

	double k;
	for (k = parameters[2]; k < parameters[3]; k += parameters[4]) {
		step++;
	}

	printf("Step = %d\n", step + 1);
	double x = parameters[2];

	for (int i = 0; i < step; i++) {
		results[i] = functionForm(parameters[0], parameters[1], x);

		x += parameters[4];
	}

	char sign1 = 182, sign2 = 186, sign3 = 187, sign4 = 188, sign5 = 200, sign6 = 201, sign7 = 202, sign8 = 203, sign9 = 199, sign10 = 205, sign11 = 206, sign12 = 179, sign13 = 215, sign14 = 196;
	int j = 0;
	/*printf("%c", sign6);
	for (int i = 0; i < 10; i++)
	printf("%c", sign10);
	printf("%c", sign8);
	for (int i = 0; i < 10; i++)
	printf("%c", sign10);
	printf("%c", sign3);
	*/
	printf("\n");
	printf("%c x        %c f(x)     %c\n", sign2, sign2, sign2);

	for (double x = parameters[2]; x <= parameters[3]; x += parameters[4])
	{
		printf("%c", sign9);
		for (int i = 0; i < 10; i++)
			printf("%c", sign14);
		printf("%c", sign13);
		for (int i = 0; i < 10; i++)
			printf("%c", sign14);
		printf("%c\n", sign1);
		printf("%c", sign2);

		printf("%9.4lf ", x);
		printf("%c", sign2);

		printf("%9.3lf ", results[j]);
		printf("%c\n", sign2);

		j++;
	}

	if (x != parameters[3]) //последнее значение 5.0008, считаем и его
	{
		printf("%c", sign9);
		for (int i = 0; i < 10; i++)
			printf("%c", sign14);
		printf("%c", sign13);
		for (int i = 0; i < 10; i++)
			printf("%c", sign14);
		printf("%c\n", sign1);

		printf("%c", sign2);

		printf("%9.4lf ", x);
		printf("%c", sign2);

		printf("%9.3lf ", results[step] = functionForm(parameters[0], parameters[1], parameters[3]));
		printf("%c\n", sign2);
	}
	/*
	printf("%c", sign5);
	for (int i = 0; i < 10; i++)
	printf("%c", sign10);
	printf("%c", sign7);
	for (int i = 0; i < 10; i++)
	printf("%c", sign10);
	printf("%c\n", sign4);
	*/
}

double functionForm(double a, double b, double x) // обчисленн€ значенн€ функц≥й при заданому x
{
	if (x <= 1) {
		return (a * pow(x, 2) + b);
	}
	else {
		return ((b - 2) / x);
	}
}

int *normalizeArray(double oldResults[], int size) //нормализаци€ массива в некоторых пределах
{

	int* normArray = new int[size];
	double max = oldResults[0];
	double min = oldResults[0];

	for (int i = 1; i < size; i++) {
		if (oldResults[i] > max) {
			max = oldResults[i];
		}
		if (oldResults[i] < min) {
			min = oldResults[i];
		}
	}

	for (int i = 0; i < size; i++) {
		normArray[i] = round((oldResults[i] - min) / (max - min) * A);//round - returns the nearest integer value of the argument passed to this function
	}
	return normArray;
}

void printHistogram(int* normArray, int size) //друк г≥стограми
{
	printf("\nHistogram\n\n");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < normArray[i]; j++)
		{
			printf(" ");
		}
		printf("%c\n", SYMBOL);
	}
	printf("\nEnd of histogram\n\n");
}

double* randArray(double* results, int size) //создание массива рандомных чисел в диапазоне [S_min;S_max]
{
	double S_1 = 0;
	double S_2 = 0;
	int counter = 0;

	for (int i = 0; i < size; i++) {
		if (i % 2 == 0) {
			S_1 += results[i];
			counter++;
		}
	}
	if (counter != 0)
		S_1 = S_1 / counter;

	counter = 0;

	for (int i = 0; i < size; i++) {
		S_2 += pow(results[i], 2);
		counter++;
	}

	if (counter != 0)
		S_2 = S_2 / counter;

	double s_min, s_max;
	s_max = (S_1 > S_2) ? S_1 : S_2;
	s_min = (S_1 < S_2) ? S_1 : S_2;

	double step = fabs(DELTA * (s_min + s_max) / 2);

	printf("Step: %lf, S_min: %lf, S_max: %lf\n\n", step, s_min, s_max);

	double* randomArr = new double[size];
	srand(time(NULL));

	printf("Random Array:\n");
	for (int i = 0; i < size; i++) {
		randomArr[i] = (rand() % int((s_max - s_min) / step))*step + s_min;
		printf("%lf\n %2.2lf\n", randomArr[i], ((randomArr[i] - s_min) / step));
	}
	printf("End of random array\n");

	return randomArr;
}

double* smooth(double* arr, int size) //сглаживание массива
{
	double* smoothArray = new double[size];

	for (int i = 0; i < size; i++) {
		if (i == 0) {
			smoothArray[i] = (arr[i] + arr[i + 1]) / 2;
		}
		else if (i == size - 1) {
			smoothArray[i] = (arr[i] + arr[i - 1]) / 2;
		}
		else {
			smoothArray[i] = (arr[i - 1] + arr[i] + arr[i + 1]) / 3;
		}
	}
	return smoothArray;
}

void fileWrite(double* array1, double* array2, int size) //запись в файл 2-х гистограмм
{
	int* rand_mas = normalizeArray(array1, size);
	int* smooth_mas = normalizeArray(array2, size);

	FILE *file;

	if ((file = fopen("C:\\Lab1Var15\\Var15.txt", "wb")) == NULL)
	{
		printf("Can't open file\n");
		exit(1);
	}
	fprintf(file, "\nHistogram of random array:\r\n\n");

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < rand_mas[i]; j++)
		{
			fprintf(file, " ");
		}
		fprintf(file, "%c\r\n", SYMBOL);
	}
	fprintf(file, "\nHistogram of smooth array:\r\n");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < smooth_mas[i]; j++)
		{
			fprintf(file, " ");
		}
		fprintf(file, "%c\r\n", SYMBOL);
	}
	fclose(file);
}