#include "ShellSortSuboptimal.h"

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
ShellSortSuboptimal::ShellSortSuboptimal(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
ShellSortSuboptimal::~ShellSortSuboptimal() {}

/**
 * Run the suboptimal shellsort algorithm.
 * @throws an exception if an error occurred.
 */
void ShellSortSuboptimal::run_sort_algorithm() throw (string)
{
	//vector<Element> v = VectorSorter::data;
	//int size = VectorSorter::data.size();
//	for(int gap = (size-1)/2; gap > 0; gap /= 2)
//	{
//		for(int i = gap; i < size; i++)
//		{
////			while(i-gap >= 0)
////			{
////				compare_count++;
////				i = i-gap;
////			}
//
//			for(int j = i - gap; j >= 0; j-=gap)
//			{
//				compare_count++;
//				if(data[j] > data[j+gap])
//				{
//					swap(j, j+gap);
//				}
////				temp = v[j];
////				v[j] = v[j + gap];
////				v[j + gap] = temp;
//			}
//		}
//	}
    for (int h = size/2; h >= 1; h /= 2)
    {
        // Perform an insertion sort with elements that are h apart.
        for (int pass = h; pass < size; pass++)
        {
            Element tmp = data[pass];  // next data element to check
            int j = pass;

            // The next data element drifts into its proper place
            // by comparing elements that are h apart.
            while ((j >= h) && (tmp < data[j-h]))
            {
                data[j] = data[j-h];
                move_count++;
                compare_count++;
                j -= h;
            }

            if (j >= h) compare_count++;

            // Move the next element into its proper place
            // if it isn't already there.
            if (pass != j) {
                data[j] = tmp;
                move_count++;
            }
        }
    }
}