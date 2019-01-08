#include <string>
#include "SortedVector.h"
#include "SortedList.h"
#include "Node.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

// How many times to do gets.
const int GETS_COUNT = 10000;

void vector_prepends(SortedVector& sv, const int size)
{
    /***** Complete this function. *****/
	int count = size;
	for (int i =0 ; i<size ;i++) {
		sv.prepend(--count);
	}

}

void list_prepends(SortedList& sl, const int size)
{
    /***** Complete this function. *****/
	int count = size;
		for (int i =0 ; i<size ;i++) {
			sl.prepend(--count);
		}

}

void vector_appends(SortedVector& sv, const int size)
{
    /***** Complete this function. *****/
	for (int i =0 ; i<size ;i++) {
		sv.append(i);
			}
}

void list_appends(SortedList& sl, const int size)
{
    /***** Complete this function. *****/
	for (int i =0 ; i<size ;i++) {
		sl.append(i);
				}

}

void vector_gets(SortedVector& sv, const int size) throw (string)
{
    // First fill the vector data.
    vector_appends(sv, size);
    Node::reset();

    // Loop to access nodes at random positions.
    for (int i = 0; i < GETS_COUNT; i++)
    {
        int index =  rand()%size;
        Node temp =	 sv.at(index);
        long value = temp.get_value();

        /***** Complete this function. *****/

        // Make sure we got the correct node.
        if (index != value) throw string("Vector data mismatch!");
    }
}

void list_gets(SortedList& sl, const int size) throw (string)
{
    // First fill the list data.
    list_appends(sl, size);
    Node::reset();

    // Loop to access nodes at random positions.
    for (int i = 0; i < GETS_COUNT; i++)
    {
        int index = rand()%size;
        Node temp = sl.at(index);
        long value = temp.get_value();

        /***** Complete this function. *****/

        // Make sure we got the correct node.
        if (index != value) throw string("List data mismatch!");
    }
}

void vector_removes(SortedVector& sv, const int size)
{
    // First fill the vector data.
    vector_appends(sv, size);
    Node::reset();

    // Loop to remove a node at a random position
    // one at a time until the nodes are all gone.
    while (sv.size() > 0)
    {
        int index = rand()%size;
        sv.remove(index);
        /***** Complete this function. *****/
    }
}

void list_removes(SortedList& sl, const int size)
{
    // First fill the list data.
    list_appends(sl, size);
    Node::reset();

    while (sl.size() > 0)
    {
        int index = rand()%size;
        sl.remove(index);

        /***** Complete this function. *****/
    }
}

void vector_inserts(SortedVector& sv, const int size)
{
        /***** Complete this function. *****/
	for (int i =0 ; i<size;i++){
		sv.insert(rand());
	}


}

void list_inserts(SortedList& sl, const int size)
{
        /***** Complete this function. *****/
	for (int i =0 ; i<size;i++){
		sl.insert(rand());
		}

}
