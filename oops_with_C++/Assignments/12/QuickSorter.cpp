#include <iostream>
#include "QuickSorter.h"
using namespace std;

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
QuickSorter::QuickSorter(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
QuickSorter::~QuickSorter() {}

/**
 * Run the quicksort algorithm.
 * @throws an exception if an error occurred.
 */
void QuickSorter::run_sort_algorithm() throw (string)
{
    quicksort(0, size-1);
}

/**
 * The quicksort algorithm recursively sorts data subranges.
 * @param left the left index of the subrange to sort.
 * @param right the right index of the subrange to sort.
 */
void QuickSorter::quicksort(const int left, const int right)
{
//	Element& pivot = choose_pivot(left, right);
//	int i, j;
//	if(pivot == data[left])
//	{
//		i = 0;
//	}
//	else
//	{
//		i = left + (left+right)/2;
//	}
//
//	int p_index = partition(left, right, pivot);
//
//
//	if(data.size()%2 == 0)
//	{
//		j = p_index;
//	}
//	else
//	{
//		j = p_index-1;
//	}
//
//	if(p_index >= j && !(data[p_index] < pivot))
//	{
//		swap(p_index, i);
//	}
//
//	if(left < j)
//	{
//		quicksort(left, p_index-1);
//	}
//	//sorting the values after the pivotal value.
//	if(p_index < right)
//	{
//		quicksort(p_index+1, right);
//	}
    if (left <= right)
    {
        // Choose the pivot and partition this subrange.
        Element& pivot = choose_pivot(left, right);
        int p = partition(left, right, pivot);

        quicksort(left, p-1);  // Sort elements <  pivot
        quicksort(p+1, right); // Sort elements >= pivot
    }
}

/**
 * Choose the pivot according to a pivot strategy.
 * The chosen pivot will be moved temporarily to the right end.
 * @param left the left index of the partition to sort.
 * @param right the right index of the partition to sort.
 * @return the pivot value.
 */
Element& QuickSorter::choose_pivot(const int left, const int right)
{
    return choose_pivot_strategy(left, right);
}

/**
 * Partition the subrange by moving data elements < pivot to the left
 * and data elements > pivot to the right.
 * @param left the left index of the partition to sort.
 * @param right the right index of the partition to sort.
 * @param pivot the pivot value.
 */
int QuickSorter::partition(const int left, const int right, const Element& pivot)
{
//	int i = left;
//	int j = right-1;
//
//	Element temp;
//
//	while(i < j)
//	{
//		while(data[i] < pivot)
//		{
//			compare_count += 1;
//			i++;
//		}
//		if(!(data[i] < pivot) && (i < j))
//		{
//			while(!(data[j] < pivot))
//			{
//				compare_count += 1;
//				j--;
//			}
//			if((data[j] < pivot) && (i < j))
//			{
//				swap(i, j);
//				i++;
//				j--;
//			}
//		}
//	}
    int i = left-1;  // index of the left side, moves to the right
    int j = right;   // index of the right side, moves to the left.

    //cout << endl << endl;

    // Loop until the indexes cross.
    while (i < j) {

        // Move i to the right as long as data[i] < pivot.
        do
        {
            i++;
            compare_count++;
            /*
            cout << "i = " << i << ", right = " << right
                 << ", data[i] = " << data[i] << ", pivot = " << pivot
                 << ", compare_count = " << compare_count << endl;
            */
        } while ((i <= right) && (data[i] < pivot));

        // Move j to the left as long as data[j] > pivot.
        do
        {
            j--;
            compare_count++;
            /*
            cout << "j = " << j << ", left = " << left
                 << ", data[j] = " << data[j] << ", pivot = " << pivot
                 << ", compare_count = " << compare_count << endl;
            */
        } while ((j >= left) && (data[j] > pivot));

        // Swap values if necessary after both i and j stop moving.
        if (i < j) swap(i, j);
    }

    swap(i, right);  // restore the pivot

	//Swapping the pivotal value.

	return i;
}