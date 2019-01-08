#include "InsertionSort.h"
#include <vector>

/**
 * Constructor.
 * @param name the name of the algorithm.
 */
InsertionSort::InsertionSort(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
InsertionSort::~InsertionSort() {}

/**
 * Run the insertion sort algorithm.
 * @throws an exception if an error occurred.
 */
void InsertionSort::run_sort_algorithm() throw (string)
{
	//vector<Element> v = data;
	//int size = VectorSorter::data.size();
//	for(int i = 0; i < size-1; i++)
//	{
//		compare_count++;
//		if(data[i] > data[i+1])
//		{
//			swap(i, i+1);
//
//			for(int j = i; j > 0; j--)
//			{
//				compare_count++;
//				if(data[j] < data[j-1])
//				{
//					swap(j, j-1);
//				}
//			}
//		}
//	}
    for (int pass = 0; pass < size-1; pass++)
    {
        int i = pass + 1;
        Element tmp = data[i];  // the next data element to check
        int j = i;

        // ... the next data element drifts into
        // its proper place in the sorted portion
        // by comparing adjacent elements.
        while ((j > 0) && (tmp < data[j-1]))
        {
            data[j] = data[j-1];
            move_count++;
            compare_count++;
            j--;
        }

        if (j > 0) compare_count++;

        // Move the next element into its proper place
        // if it isn't already there.
        if (i != j)
        {
            data[j] = tmp;
            move_count++;
        }
    }
}