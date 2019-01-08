#include <string>
#include "MergeSort.h"

/**
 * Constructor.
 * @param name the name of the algorithm.
 */
MergeSort::MergeSort(string name) : ListSorter(name) {}

/**
 * Destructor.
 */
MergeSort::~MergeSort() {}

/**
 * Run the mergesort algorithm.
 * @throws an exception if an error occurred.
 */
void MergeSort::run_sort_algorithm() throw (string)
{
    // Defensive programming: Make sure we end up
    // with the same size list after sorting.
    int size_before = data.get_size();

    mergesort(data);

    // Check sizes.
    int size_after = data.get_size();
    if (size_before != size_after)
    {
        string message = "***** Size mismatch: before " +
                         to_string(size_before) + ", size after " +
                         to_string(size_after);
        throw message;
    }
}

/**
 * The mergesort algorithm recursively splits and merges data lists.
 * @param list the list of data to sort.
 */
void MergeSort::mergesort(LinkedList& list)
{

	int size = list.get_size();
	if(size > 1)
	{
		LinkedList l1, l2;
		list.split(l1, l2);
		//list.clear();
		mergesort(l1);
		mergesort(l2);
		merge(list, l1, l2);
	}

    /***** Complete this member function. *****/
}

/**
 * Merge two sublists back into a single list.
 * @param list the merged list.
 * @param sublist1 the first sublist.
 * @param sublist2 the second sublist.
 */
void MergeSort::merge(LinkedList& list, LinkedList& sublist1, LinkedList& sublist2)
{
//	Node* ptr1 = sublist1.get_head();
//	Node* ptr2 = sublist2.get_head();
//
//	while(ptr1 != nullptr && ptr2 != nullptr)
//	{
//		if(ptr1->element.get_value() <= ptr2->element.get_value())
//		{
//			list.add(ptr1);
//			ptr1 = ptr1->next;
//		}
//		else
//		{
//			list.add(ptr2);
//			ptr2 = ptr2->next;
//		}
//
//	}
//
//	if(ptr1 == nullptr)
//	{
//		while(ptr2 != nullptr)
//		{
//			list.add(ptr2);
//			ptr2 = ptr2->next;
//		}
//	}
//	else
//	{
//		while(ptr1 != nullptr)
//		{
//			list.add(ptr1);
//			ptr1 = ptr1->next;
//		}
//	}
    Node *node1 = sublist1.get_head();
    Node *node2 = sublist2.get_head();

    list.reset();

    // Choose the head node from one sublist to add to the merged list.
    while ((node1 != nullptr) && (node2 != nullptr))
    {
        // Choose form the first sublist.
        if (node1->element.get_value() <= node2->element.get_value())
        {
            list.add(sublist1.remove_head());
            node1 = sublist1.get_head();
        }

        // Choose from the second sublist.
        else
        {
            list.add(sublist2.remove_head());
            node2 = sublist2.get_head();
        }

        move_count++;
        compare_count++;
    }

    // Concatenate the rest of the first sublist to the merged list.
    if (node1 != nullptr)
    {
        list.concatenate(sublist1);
        move_count++;
    }

    // Concatenate the rest of the second sublist to the merged list.
    if (node2 != nullptr)
    {
        list.concatenate(sublist2);
        move_count++;
    }

    /***** Complete this member function. *****/
}

/**
 * Clear the data.
 */
void MergeSort::clear() { data.clear(); }