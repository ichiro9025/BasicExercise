/*
 * sort.h
 *
 *  Created on: 2018¦~5¤ë13¤é
 *      Author: ichiro-lin
 */

#ifndef INCLUDE_BASICEXERCISE_SORT_H_
#define INCLUDE_BASICEXERCISE_SORT_H_
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Sort{
public:
	static void swap(vector<double>& vec, int i, int j){
		int tmp = vec.at(i);
		vec.at(i) = vec.at(j);
		vec.at(j) = tmp;
	}
	static void inorder(vector<double>& vec){
		for(vector<double>::iterator iter = vec.begin(); iter < vec.end(); iter++)
			printf("%f, ", *iter);
		printf("\n");
	}
	virtual void sort(vector<double>&) = 0;
//	virtual ~Sort();
protected:

};

class InsertionSort : public Sort {
public:
	void sort(vector<double>&);
};

class SelectionSort : public Sort {
public:
	void sort(vector<double>&);
};

class BubbleSort : public Sort {
public:
	void sort(vector<double>&);
};

class ShellSort : public Sort {
public:
	void sort(vector<double>&);
};

class ShakerSort : public Sort {
public:
	void sort(vector<double>&);
};

class QuickSort : public Sort {
public:
	void sort(vector<double>&);
	void rec_sort(vector<double>&, int start, int end);
};

class MergeSort : public Sort {
public:
	void sort(vector<double>&);
	vector<double> merge(vector<double>, vector<double>);
	vector<double> rec_sort(vector<double>);
};

class HeapSort : public Sort {
public:
	void sort(vector<double>&);
	void heapify(vector<double>&, int root, int length);
};

class RadixSort : public Sort {
public:
	void sort(vector<double>&);
};

#endif /* INCLUDE_BASICEXERCISE_SORT_H_ */
