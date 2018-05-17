/*
 * SelectionSort.cpp
 *
 *  Created on: 2018年5月13日
 *      Author: ichiro-lin
 */

#include "../include/BasicExercise/Sort.h"

/* Time Complexity:
 * Best Case：Ο(n2)
 * Worst Case：Ο(n2)
 * Average Case：Ο(n2)
 * Space Complexity:
 * θ(1)
 * Unstable
 * */
void SelectionSort::sort(vector<double>& vec){
	int len = vec.size();
	double tempmin = 0;
	int swap_idx = 0;
	for(int i = 0 ; i < len-1; i++){
		tempmin = vec.at(i);
		swap_idx = i;
		for(int j = i+1; j < len; j++){
			if(tempmin > vec.at(j)){
				tempmin = vec.at(j);
				swap_idx = j;
			}
		}
		Sort::swap(vec, i, swap_idx);
	}
}

/* Time Complexity:
 * Best Case：Ο(n)
 * Worst Case：Ο(n2)
 * Average Case：Ο(n2)
 * Space Complexity:
 * θ(1)
 * stable
 * */
void InsertionSort::sort(vector<double>& vec){
	int len = vec.size();
	double tmp = 0;
	int j = 0;
	for(int i = 1 ; i < len; i++){
		tmp = vec.at(i);
		for( j = i; j > 0 && tmp < vec.at(j-1); j--)
			vec.at(j) = vec.at(j-1);
		vec.at(j) = tmp;
	}
}

/* Time Complexity:
 * Best Case：Ο(n)
 * Worst Case：Ο(n2)
 * Average Case：Ο(n2)
 * Space Complexity:
 * θ(1)
 * stable
 * */
void BubbleSort::sort(vector<double>& vec){
	int len = vec.size();
	bool flag = true;
	int j = 0;
	for(int i = 0 ; i < len-1 && flag; i++){
		flag = false;
		for( j = 0; j < len-i-1 ; j++){
			if(vec.at(j+1) < vec.at(j)){
				Sort::swap(vec, j+1, j);
				flag = true;
			}
		}
	}
}

/* Time Complexity:
 * Best Case：Ο(n)
 * Worst Case：Ο(n1.5~n2)
 * Average Case：Ο(n1.25)
 * Space Complexity:
 * θ(1)
 * unstable
 * */
void ShellSort::sort(vector<double>& vec){
	int len = vec.size();
	int gap = len/2;
	int j = 0;
	double tmp = 0;
	while(gap > 0){
		for(int i = gap; i < len ; i++){
			tmp = vec.at(i);
			for( j = i; j >= gap && tmp < vec.at(j-gap); j-=gap)
				vec.at(j) = vec.at(j-gap);
			vec.at(j) = tmp;
		}
		gap /= 2;
	}
}

/* Time Complexity:
 * Best Case：Ο(n)
 * Worst Case：Ο(n2)
 * Average Case：Ο(n2)
 * Space Complexity:
 * θ(1)
 * stable
 * */
void ShakerSort::sort(vector<double>& vec){
	int right = vec.size()-1;
	int left = 0;
	int ptr = 0;
	while(left < right){
		for(int i = left; i < right ; i++){
			if(vec.at(i+1) < vec.at(i)){
				Sort::swap(vec, i, i+1);
				ptr = i;
			}
		}
		right = ptr;
		for(int i = right; i > left ; i--){
			if(vec.at(i-1) > vec.at(i)){
				Sort::swap(vec, i, i-1);
				ptr = i;
			}
		}
		left = ptr;
	}
}

/* Time Complexity:
 * Best Case：Ο(nlogn)
 * Worst Case：Ο(n2)
 * Average Case：Ο(nlogn)
 * Space Complexity:
 * θ(logn)~O(n)
 * unstable
 * */
void QuickSort::sort(vector<double>& vec){
	rec_sort(vec, 0, vec.size()-1);
}

void QuickSort::rec_sort(vector<double>& vec, int start, int end){

	if(start < end){
		double pivot = vec.at(start);
		int size = vec.size();
		int lptr  = start+1;
		int rptr = end;
		while(true){
			for(; lptr < size && vec.at(lptr) < pivot; lptr++){}
			for(; rptr > -1 && vec.at(rptr) > pivot; rptr--){}
			if(lptr < rptr){
				Sort::swap(vec, lptr, rptr);
				printf("pivot: %f, left: %d, right: %d\n", pivot, lptr, rptr);
			}else
				break;
		}
		Sort::swap(vec, rptr, start);
		rec_sort(vec, start, rptr-1);
		rec_sort(vec, rptr+1, end);
	}
}

/* Time Complexity:
 * Best Case：Ο(nlogn)
 * Worst Case：Ο(nlogn)
 * Average Case：Ο(nlogn)
 * Space Complexity:
 * θ(n)
 * stable
 * */
void MergeSort::sort(vector<double>& vec){
	vector<double> rst = rec_sort(vec);
	vec = rst;
}

vector<double> MergeSort::rec_sort(vector<double> array){
	int len = array.size();
	if(len == 1)
		return array;
	else{
		int mid = len/2;
		vector<double> splitAry1(mid,0);
		vector<double> splitAry2(len-mid,0);
		for(int i = 0; i < mid; i++)
			splitAry1[i] = array[i];
		for(int i = 0; i < len-mid; i++)
			splitAry2[i] = array[i+mid];

		return merge(rec_sort(splitAry1), rec_sort(splitAry2));
	}
}

vector<double> MergeSort::merge(vector<double> ary1, vector<double> ary2){
	int len1 = ary1.size();
	int len2 = ary2.size();
	vector<double> mergeAry(len1+len2,0);

	int idx1 = 0;
	int idx2 = 0;
	for(int i = 0 ; i < len1+len2; i++){
		if(idx1 == len1){
			mergeAry[i] = ary2[idx2++];
		}else if(idx2 == len2){
			mergeAry[i] = ary1[idx1++];
		}else if(ary1[idx1] < ary2[idx2]){
			mergeAry[i] = ary1[idx1++];
		}else
			mergeAry[i] = ary2[idx2++];
	}
	return mergeAry;
}


/* Time Complexity:
 * Best Case：Ο(nlogn)
 * Worst Case：Ο(nlogn)
 * Average Case：Ο(nlogn)
 * Space Complexity:
 * θ(nlogn)
 * unstable
 * */
void HeapSort::sort(vector<double>& vec){
	int len = vec.size();
	for(int i = len/2-1; i >-1; i-- )
		heapify(vec, i, len);

//	printf("NaxHeap:\n");
//	Sort::inorder(vec);
	for(int i = len-1; i > 0; i--){
		Sort::swap(vec, 0, i);
		heapify(vec, 0, i);
	}
}

void HeapSort::heapify(vector<double>& vec, int root, int end){
	int left = root*2+1;
	int right = root*2+2;
	int maxnode = root;
	if(right < end && vec.at(root) < vec.at(right))
		maxnode = right;
	if(left < end && vec.at(maxnode) < vec.at(left))
		maxnode = left;

	if(maxnode != root){
		Sort::swap(vec, root, maxnode);
		heapify(vec, maxnode, end);
	}
//	Sort::inorder(vec);
}

/* Time Complexity:
 * Best Case：Ο(d × (n+r))
 * Worst Case：Ο(d × (n+r))
 * Average Case：Ο(d × (n+r))
 * Space Complexity:
 * θ(n × r)
 * unstable
 * */
void RadixSort::sort(vector<double>& vec){
	int len = vec.size();
	int radix = 10;
	vector<vector<double> > bucket(radix,vector<double>(len,-1));
	vector<int> countVec(radix,0);
	bool _isEnd = false;
	int ratio = 0, base = 10, loop = 0, index = 0;

	while(!_isEnd){
		_isEnd = true;
		base = pow(10,loop++);
		for(int i =0; i < len; i++){
			ratio = vec.at(i)/base;
			if(ratio != 0)
				_isEnd = false;
			index = ratio%radix;
			bucket.at(index).at(countVec.at(index)) = vec.at(i);
			countVec.at(index) +=1;
		}
		index = 0;
		for(int i =0; i < radix; i++){
			for(int j = 0; j < countVec.at(i); j++)
				vec.at(index++) = bucket.at(i).at(j);
			countVec.at(i) = 0;
		}
	}

}

int main(int argc, char* argv[]){
	double array[] = {3,1,5,2,9,4,0,7,8,6};
	vector<double> v(10,0); // {0,0,0,0,0,0,0,0,0,0}
	v.assign(array, array+10); // 複製 array 前10個元素到 v1

	SelectionSort selectsort;
	selectsort.sort(v);
	Sort::inorder(v);

	v.assign(array, array+10);
	InsertionSort insertsort;
	insertsort.sort(v);
	Sort::inorder(v);

	v.assign(array, array+10);
	BubbleSort bubblesort;
	bubblesort.sort(v);
	Sort::inorder(v);

	v.assign(array, array+10);
	ShellSort shellsort;
	shellsort.sort(v);
	Sort::inorder(v);

	v.assign(array, array+10);
	ShakerSort shakersort;
	shakersort.sort(v);
	Sort::inorder(v);

	v.assign(array, array+10);
	QuickSort quicksort;
	quicksort.sort(v);
	Sort::inorder(v);

	v.assign(array, array+10);
	MergeSort mergesort;
	mergesort.sort(v);
	Sort::inorder(v);

	v.assign(array, array+10);
	HeapSort heapsort;
	heapsort.sort(v);
	Sort::inorder(v);

	v.assign(array, array+10);
	RadixSort Radixsort;
	Radixsort.sort(v);
	Sort::inorder(v);

	return 0;
}
