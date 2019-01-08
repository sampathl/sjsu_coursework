#include "QuickSortOptimal.h"

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
QuickSortOptimal::QuickSortOptimal(string name) : QuickSorter(name) {}

/**
 * Destructor.
 */
QuickSortOptimal::~QuickSortOptimal() {}

/**
 * Choose a good pivot, the median-of-three:
 * The middle value of the leftmost, rightmost, and center elements.
 * This is a compromise since the most optimal pivot would be the
 * median of the subrange, but that's too expensive to compute.
 * @param left the left index of the subrange to sort.
 * @param right the right index of the subrange to sort.
 * @return the chosen pivot value.
 */
Element& QuickSortOptimal::choose_pivot_strategy(const int left, const int right)
{
//	int mid = left + (left+right)/2;
//	return data[mid];
    int center = (left + right)/2;

    // Order the left, center, and right elements.
    if (data[center] < data[left])   swap(left, center);
    if (data[right]  < data[left])   swap(left, right);
    if (data[right]  < data[center]) swap(center, right);
    compare_count += 3;

    // The pivot is the center element.
    // Swqp it to the rightmost position temporarily.
    swap(center, right);

    return data[right];
}