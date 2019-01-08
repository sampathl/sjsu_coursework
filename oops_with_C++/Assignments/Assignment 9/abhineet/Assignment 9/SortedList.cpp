#include <iostream>
#include <iterator>
#include "SortedList.h"

using namespace std;

SortedList::SortedList()
{
    Node::reset();
}

SortedList::~SortedList()
{
    Node::reset();
}

int SortedList::size() const { return data.size(); }

bool SortedList::check()
{
    if (data.size() == 0) return true;
    list<Node>::iterator it = data.begin();
    list<Node>::iterator prev = it;

    it++;
    // Ensure that each node is greater than the previous node.
    while ((it != data.end()) && (*it > *prev))
    {
        prev = it;
        it++;
    }
    return it == data.end();  // Good if reached the end.
}

void SortedList::prepend(const long value)
{
    /***** Complete this function. *****/
	Node node (value);
	data.insert(data.begin(),node);
}

void SortedList::append(const long value)
{
    /***** Complete this function. *****/
	Node node (value);
	data.insert(data.end(),node);
}

void SortedList::remove(const int index)
{
	 list<Node>::iterator it = data.begin();
	  advance (it,index);
	  if (index<data.size())
	      data.erase(it);
    /***** Complete this function. *****/
}

void SortedList::insert(const long value)
{
   Node node (value);
   list<Node>::iterator it = data.begin();
   if (data.empty()){
	   data.insert(it,node);
	} else {
		while (it != data.end()) {
			if (node >*it ) {
				it++;
				if (it == data.end()) {
				data.insert(it, node);
				}
			} else {
				data.insert(it, node);
				break;
			}
		}
	}
    /***** Complete this function. *****/
}

Node SortedList::at(const int index)
{
    /***** Complete this function. *****/
	list<Node>::iterator it = data.begin();
	advance(it,index);
     return *it;
}
