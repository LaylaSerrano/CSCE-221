# include <iostream>
# include <string>
# include <sstream>
# include "LinkedList.h"
# include "Node.h"

using std::string, std::ostream;

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

LinkedList::~LinkedList() {
	clear();
}

LinkedList::LinkedList(const LinkedList& source) : head(nullptr), tail(nullptr) {
	// TODO: implement this function
	
	Node* tohead = source.head;
	while (tohead != nullptr ){
		Node* tocopy = new Node(tohead->data.id, tohead->data.year, tohead->data.month, tohead->data.temperature);
		if (tail == nullptr){
			head = tocopy;
			tail = tocopy;
		} else {
			tail->next = tocopy;
			tail = tocopy;
		}
		tohead = tohead->next;
	}


}

LinkedList& LinkedList::operator=(const LinkedList& source) {
	// TODO: implement this function
	if (this == &source){
		return *this;
	}
	Node* tohead = source.head;
	while (tohead != nullptr ){
		Node* tocopy = new Node(tohead->data.id, tohead->data.year, tohead->data.month, tohead->data.temperature);
		if (tail == nullptr){
			head = tocopy;
			tail = tocopy;
		} else {
			tail->next = tocopy;
			tail = tocopy;
		}
		tohead = tohead->next;
	}

	return *this;
}

void LinkedList::insert(string location, int year, int month, double temperature) {
	// TODO: implement this function
	Node* nodeToInsert = new Node(location, year, month, temperature);
	Node* currNode = head;
	Node* prevNode = nullptr;

	while(currNode != nullptr && *currNode < * nodeToInsert){
		prevNode = currNode;
		currNode = currNode -> next;
	}

	if (prevNode == nullptr){
		nodeToInsert -> next = head;
		head = nodeToInsert;
	} else{
		prevNode -> next = nodeToInsert;
		nodeToInsert -> next = currNode;
	}

	if (currNode == nullptr){
		tail = nodeToInsert;
	}else if (currNode == head){
		tail = head;
	}

}

void LinkedList::clear() {
	// TODO: implement this function

	Node* temp;

	while (head!= nullptr){
		temp = head-> next;
		delete head;
		head = temp;
		
	}
	tail = nullptr;

}

Node* LinkedList::getHead() const {
	// TODO: implement this function, it will be used to help grade other functions
	return head;
}

string LinkedList::print() const {
	// TODO: implement this function

	std::stringstream ss;
	Node* curr = head;
	while (curr != nullptr){
		ss << curr->data.id << " " << curr->data.year << " " << curr->data.month << " " << curr->data.temperature << std::endl;
		curr = curr-> next;
	}

	return ss.str();
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	os << ll.print();
	return os;
}
