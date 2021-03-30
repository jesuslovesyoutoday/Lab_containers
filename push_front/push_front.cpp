#include <iostream>
#include <vector>
#include "subforwardlist.h"
#include <forward_list>
#include <chrono>
#include <cmath>
#include <fstream>

using namespace std;

int main()
{

ofstream fout;

/*-----------------------------------------/FORWARD_LIST/-------------------------------------------*/

	fout.open("push_front_forwlist.txt");

	for (int size = 10000; size <= 500000; size += 10000)
	{
		forward_list<int> flist;
		
		for (int i = 0; i < size; i++)
		{
			flist.push_front(i);
		}
	
		for (int i = 0; i < 100; i++)
		{

			auto begin = chrono::high_resolution_clock::now();
			flist.push_front(0);
			auto end = chrono::high_resolution_clock::now();
			
			flist.pop_front();

			fout << chrono::duration_cast<chrono::nanoseconds>(end-begin).count() << endl;
		}

		fout << endl;
	}
	
	fout.close();

/*----------------------------------------/SUBFORWARD_LIST/----------------------------------------*/

	fout.open("push_front_subforwlist.txt");

	for (int size = 10000; size <= 500000; size += 10000) 
	{
		subforwardlist<int> sfl;

		for (int i = 0; i < size; i++)
		{
			sfl.push_forward(i);
		}
	
		for (int i = 0; i < 100; i++) // для усреднения
		{

			auto begin = chrono::high_resolution_clock::now();
			sfl.push_forward(0);
			auto end = chrono::high_resolution_clock::now();
			
			sfl.pop_back(); // для поддержания постоянного размера массива

			fout << chrono::duration_cast<chrono::nanoseconds>(end-begin).count() << endl;
		}

		fout << endl;
	}
	
	fout.close();

/*--------------------------------------------------------------------------------------------*/
	return 0;

}
