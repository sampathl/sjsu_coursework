#include "Node.h"
#include "Element.h"

/***** Complete this class. *****/
Node::Node() : element(0), next(nullptr) {}

Node::Node(Element e) : element(e), next(nullptr) {}

Node::~Node() {}