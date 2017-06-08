#include <iostream>
#include <vector>
#include <functional>
#include <queue>
#include <ctime>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <chrono>
#include "recursion.cpp"
#include "iterative.cpp"


using namespace std;
using namespace std::chrono;
vector<vector<int>> map;
int N, M;
BetterSolution betterSolution;
WorseSolution worseSolution;

int read_input()
{
	int input = -1;
	bool valid = false;
	do
	{
		cin >> input;
		if (cin.good())
		{
			valid = true;
		}
		else
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Jeszcze raz" << endl;
		}
	} while (!valid);
	return (input);
}

void generateMap() {
	map.clear();
	vector <int> row;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			row.push_back(rand() % 10 + 1);
		map.push_back(row);
		row.clear();
	}
}
void printMap() {
	for (int ii = 0; ii < N; ii++) {
		for (int j = 0; j < M; j++)
		{
			cout << setw(4) << left << map[ii][j]; 
		}
		cout << endl;
	}
}

void loadFromFile(string fileName) {
	vector <int> rows;
	ifstream myfil2e;
	map.clear();
	myfil2e.open(fileName);
	while (!myfil2e.eof()) {
		string str;
		getline(myfil2e, str);

		stringstream ss(str);
		int xxx;
		int i = 0;
		int j = 0;
		while (ss >> xxx) {
			rows.push_back(xxx);
		}
		map.push_back(rows);
		rows.clear();
	}
	myfil2e.close();
	return;
}
void saveToFile() {
	ofstream myfile;
	myfile.open("test.txt", ofstream::trunc);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			myfile << setw(4) << left << map[i][j];

		}
		myfile << endl;
	}
	myfile.close();
}

void test1() {
	loadFromFile("test1.txt");
	BetterSolution betterSolution1;
	WorseSolution worseSolution1;

	int x = betterSolution1.trapRainWater(map);
	int y = worseSolution1.trapRainWater(map);
	if (x == 5 && y == 5)
		cout << "I test - macierz 4x4 - OK" << endl;
}
void test2() {
	loadFromFile("test2.txt");
	BetterSolution betterSolution1;
	WorseSolution worseSolution1;
	int x = betterSolution1.trapRainWater(map);
	int y = worseSolution1.trapRainWater(map);
	if (x == 2 && y == 2)
		cout << "II test - macierz 5x5 - OK" << endl;
}
void test3() {
	loadFromFile("test3.txt");
	BetterSolution betterSolution1;
	WorseSolution worseSolution1;
	int x = betterSolution1.trapRainWater(map);
	int y = worseSolution1.trapRainWater(map);
	if (x == 32 && y == 32)
		cout << "III test - macierz 6x6 - OK" << endl;
}
void test4() {
	loadFromFile("test4.txt");
	BetterSolution betterSolution1;
	WorseSolution worseSolution1;
	int x = betterSolution1.trapRainWater(map);
	int y = worseSolution1.trapRainWater(map);
	if (x == 102 && y == 102)
		cout << "IV test - macierz 10x10 - OK" << endl;
}
int main() {
	srand(time(NULL));
	int choice = 2;
	N = 0;
	M = 0;
	while (1) {
		cout << "Aby wybrac testy wpisz 1, wygeneruj i wypisz macierz - 2, wygreneruj macierz do pliku - 3" << endl;
		map.clear();
		cin >> choice;
		switch (choice) {

		case 1:
		{
			test1();
			test2();
			test3();
			test4();
			break;
		}
		case 2:
		{
			cout << "Podaj N" << endl;
			N = read_input();
			cout << "Podaj M" << endl;
			M = read_input();
			cout << "Liczy..." << endl;
			generateMap();
			printMap();
			high_resolution_clock::time_point t1 = high_resolution_clock::now();
			int x = betterSolution.trapRainWater(map);
			high_resolution_clock::time_point t2 = high_resolution_clock::now();

			cout << "Pierwszy algorytm potrzebowal: " << duration_cast<microseconds>(t2 - t1).count() << " mikrosekund." << endl;
			t1 = high_resolution_clock::now();
			int z = worseSolution.trapRainWater(map);
			t2 = high_resolution_clock::now();

			cout << "Drugi algorytm potrzebowal: " << duration_cast<microseconds>(t2 - t1).count() << " mikrosekund." << endl;
			cout << "Pierwszy algorytm: zebrano: " << x << " jednostek wody." << endl;
			cout << "Drugi algorytm: zebrano: " << z << " jednostek wody." << endl;
			break;
		}
		default:
		{

			cout << "Podaj N" << endl;
			N = read_input();
			cout << "Podaj M" << endl;
			M = read_input();
			cout << "Liczy..." << endl;
			generateMap();
			

			high_resolution_clock::time_point t1 = high_resolution_clock::now();
			int x = betterSolution.trapRainWater(map);
			high_resolution_clock::time_point t2 = high_resolution_clock::now();

			cout << "Pierwszy algorytm potrzebowal: " << duration_cast<microseconds>(t2 - t1).count() << " mikrosekund." << endl;
			t1 = high_resolution_clock::now();
			int z = worseSolution.trapRainWater(map);
			t2 = high_resolution_clock::now();

			cout << "Drugi algorytm potrzebowal: " << duration_cast<microseconds>(t2 - t1).count() << " mikrosekund." << endl;
			cout << "Pierwszy algorytm: zebrano: " << x << " jednostek wody." << endl;
			cout << "Drugi algorytm: zebrano: " << z << " jednostek wody." << endl;

			break;

		}
	
		
		}
		
	}
	system("pause");
	return 0;
}