# include <string>
# include "Node.h"

using std::string;

Node::Node() : data(), next(nullptr) {
	// TODO: implement this function
}

Node::Node(string id, int year, int month, double temperature) : data(id, year, month, temperature), next(nullptr){
	// TODO: implement this function
	
}

bool Node::operator<(const Node& b) {
	// TODO: implement this function

	return data < b.data;

}
