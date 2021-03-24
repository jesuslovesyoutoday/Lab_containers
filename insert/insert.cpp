#include <iostream>
#include <vector>
#include "subvector.cpp"
#include <chrono>
#include <cmath>
#include <fstream>

using namespace std;

int main()
{

/*-----------------------------------------/VECTOR/-------------------------------------------*/
	ofstream fout;

	fout.open("insert_vec.txt");

	for (int size = 10000; size <= 500000; size += 10000)
	{
		vector<int> vec;

		for (int i = 0; i < size; i++)
		{
			vec.push_back(i);
		}
	
		for (int i = 0; i < 100; i++)
		{

			int rand_place = rand()%(size);

			auto begin = chrono::high_resolution_clock::now();
			vec.insert(vec.begin() + rand_place, 0);
			auto end = chrono::high_resolution_clock::now();
			
			vec.pop_back();

			fout << chrono::duration_cast<chrono::microseconds>(end-begin).count() << endl;
		}

		fout << endl;
	}
	
	fout.close();

/*----------------------------------------/SUBVECTOR/----------------------------------------*/

	fout.open("insert_subvec.txt");

	for (int size = 10000; size <= 500000; size += 10000)
	{
		subvector subvec;

		for (int i = 0; i < size; i++)
		{
			subvec.push_back(i);
		}
	
		for (int i = 0; i < 100; i++)
		{

			int rand_place = rand()%(size);

			auto begin = chrono::high_resolution_clock::now();
			subvec.insert(0, rand_place);
			auto end = chrono::high_resolution_clock::now();
			
			subvec.pop_back();

			fout << chrono::duration_cast<chrono::microseconds>(end-begin).count() << endl;
		}

		fout << endl;
	}
	
	fout.close();

/*--------------------------------------------------------------------------------------------*/
	return 0;

}
