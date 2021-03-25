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

	fout.open("access_vec.txt");

	for (unsigned long long int size = 10000; size <= 10000000; size += 10000)
	{
		vector<unsigned long long int> vec;
		vec.resize(10000000);

		for (unsigned long long int i = 0; i < size; i++)
		{
			vec.push_back(i);
		}
	
		for (int i = 0; i < 100; i++)
		{

			unsigned long long int rand_place = rand()%(size);

			auto begin = chrono::high_resolution_clock::now();
			unsigned long long int a = vec[rand_place];
			auto end = chrono::high_resolution_clock::now();

			fout << chrono::duration_cast<chrono::nanoseconds>(end-begin).count() << endl;
		}

		fout << endl;
	}
	
	fout.close();

/*----------------------------------------/SUBVECTOR/----------------------------------------*/

	fout.open("access_subvec.txt");

	for (unsigned long long int size = 10000; size <= 10000000; size += 10000)
	{
		subvector subvec;
		subvec.resize(10000000);

		for (unsigned long long int i = 0; i < size; i++)
		{
			subvec.push_back(i);
		}
	
		for (int i = 0; i < 100; i++)
		{

			unsigned long long int rand_place = rand()%(size);

			auto begin = chrono::high_resolution_clock::now();
			subvec.get_element(rand_place);
			auto end = chrono::high_resolution_clock::now();

			fout << chrono::duration_cast<chrono::nanoseconds>(end-begin).count() << endl;
		}

		fout << endl;
	}
	
	fout.close();

/*--------------------------------------------------------------------------------------------*/
	return 0;

}
