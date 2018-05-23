#pragma once
#include "PriorityQueue.cpp"
#include <vector>
class Controller {
private:
	PriorityQueue queue;
public:
	Controller(PriorityQueue _queue);
	//Constructor
	Node *getNext();
	//the function which plays the role of the nurse, the one that chooses which patient will be treated next
	void addController(std::string name,std::string disease);
	// adds a new medical condition to the priority queue
	std::string treatPerson();
	//the function which plays the role of the doctor
	int transform(std::string disease);
	/*
	In: a string naming a disease
	Out: the priority number established by the statement
	*/
	int nrOfCases();
	/*
	Returns the nr of current cases
	*/
	Node *getHead();
	/*
	Returns the first element in the queue, the head
	*/
	~Controller();
	PriorityQueue getQueue();
};
