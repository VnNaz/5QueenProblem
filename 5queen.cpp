// 5queen.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
const int N = 8; // table size

int** createTable() {
	int** table = new int* [N];
	// create arr
	table[0] = new int[N*N];
	for (int i = 1; i < N; i++)
	{
		table[i] = table[i-1] + N;
	}
	// init val
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			table[i][j] = 0;
		}
		cout << endl;
	}
	return table;
}
void deleteTable(int** table) {
	delete[] table[0];
	delete[] table;
}
void printTable(int ** table) {
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (table[i][j] > 10)
				cout << " * ";
			else
				cout << " . ";
		}
		cout << endl;
	}
}
bool checkRow(int** table, int row) {
	for (int i = 0; i < N; i++)
	{
		if (table[row][i] != 0)
			return true;
	}
	return false;
}
bool isFill(int** table) {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (table[i][j] == 0)
				return false;
		}
	}
	return true;
}
void putQueen(int** table, int x, int y)
{
	for (int i = 0; i < N; i++)
	{
		table[i][y]++;
		table[x][i]++;

		if (x - i >= 0)
		{
			if (y - i >= 0)
				table[x - i][y - i]++;
			if(y+i < N)
				table[x - i][y + i]++;
		}
		if (x + i < 8)
		{
			if (y - i >= 0)
				table[x + i][y - i]++;
			if (y + i < N)
				table[x + i][y + i]++;
		}
	}
	table[x][y] += 10;
}
void removeQueen(int** table, int x, int y) {
	for (int i = 0; i < N; i++)
	{
		table[i][y]--;
		table[x][i]--;

		if (x - i >= 0)
		{
			if (y - i >= 0)
				table[x - i][y - i]--;
			if (y + i < N)
				table[x - i][y + i]--;
		}
		if (x + i < 8)
		{
			if (y - i >= 0)
				table[x + i][y - i]--;
			if (y + i < N)
				table[x + i][y + i]--;
		}
	}
	table[x][y] -= 10;
}
bool solve(int** table, int level = 0)
{	
	if (level == 5) {
		if (isFill(table)) {
			printTable(table);
			return true;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (table[i][j] == 0)
			{
				putQueen(table,i, j);
				if (solve(table, level + 1)) 
					return true;
				removeQueen(table, i, j);
			}
		}
	}
}

int main()
{
	auto table = createTable();
	solve(table);
	deleteTable(table);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
