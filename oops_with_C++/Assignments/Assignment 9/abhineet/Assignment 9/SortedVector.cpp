#include <iostream>
#include <iterator>
#include "SortedVector.h"

using namespace std;

SortedVector::SortedVector() {
	Node::reset();
}

SortedVector::~SortedVector() {
	Node::reset();
}

int SortedVector::size() const {
	return data.size();
}

bool SortedVector::check() const {
	if (data.size() == 0)
		return true;

	vector<Node>::const_iterator it = data.begin();
	vector<Node>::const_iterator prev = it;

	it++;

	// Ensure that each node is greater than the previous node.
	while ((it != data.end()) && (*it > *prev)) {
		prev = it;
		it++;
	}
	return it == data.end();  // Good if reached the end.
}

void SortedVector::prepend(const long value) {
	/***** Complete this function. *****/
	Node node(value);
	data.insert(data.begin(), node);
}

void SortedVector::append(const long value) {
	/***** Complete this function. *****/
	Node node(value);
	data.insert(data.end(), node);
}

void SortedVector::remove(const int index) {
	/***** Complete this function. *****/

		data.erase(data.begin() + index);

}

void SortedVector::insert(const long value) {
	/***** Complete this function. *****/
	vector<Node>::const_iterator it = data.begin();
	Node node (value);
	int begin(0), end(data.size() - 1);
	int indextoInsert = -1;
	int mid;
	if (!data.empty()){
	while (begin <= end) {  // using  binary insert to reduce complexity
		mid = (begin + end) / 2;
		if (data[mid] == value) {
			indextoInsert = mid;
			break;
		} else if (data[mid] > value) {
			end = mid - 1;
			indextoInsert = mid; // careful its mid not end here
				// reason why its mid here is because when anything inserted in the array or vector,
			   // shifts the element to the right so suppose element to be inserted is less than
			  // element at index 3,so if end = mid-1 is calculated index becomes 2 now if element is inserted
			 // at 2 it will be an error because the element at 2 will go to three, but what we wanted
			//is it gets inserted after 2nd element.
		} else {
			begin = mid + 1;
		    indextoInsert = begin;
		}
	}
	}
	else {
		indextoInsert =0;
	}
	data.insert(data.begin() +indextoInsert,node);
}

Node SortedVector::at(const int index) const {
	/***** Complete this function. *****/
	return data[index];
}
