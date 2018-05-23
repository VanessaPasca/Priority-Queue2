#include "Controller.h"
#include <string.h>
using namespace std;

Controller::Controller(PriorityQueue _queue) {
	//constructor for the controller
	this->queue = _queue;
}

int Controller::transform(string disease)  //O(1)
{
	/*
	Transforms the diseases into coresponding priority
	In: string disease- name of the disease
	Out: int- the corr. priority integer
	Complexity: O(1)
	*/
	if (disease.find("gunshot") <disease.length())
		return 1;
	if (disease.find("broken") <disease.length())
		return 2;
	else return 3;
}

void Controller::addController(string name, string disease)  //O(log(m)) -> inherited from the PriorityQueue
{
	/*
	Adds the person with the name "name" and with the disease "disease" to the queue
	*/
	int p = transform(disease);
	this->queue.enqueue(name, p);
}

Node *Controller::getNext() { //O(log(m))
	/*
	Returns the first element from the queue
	*/
	Node *nextOne= this->queue.dequeue();
	return nextOne;
}

string Controller::treatPerson()   //O(1)
{
	/*
	Treats the 1st person in the queue
	Returns the name of the treated person
	*/
	Node *chosen = getNext();
	string name = chosen->info;
	delete chosen;
	return name;


}

int Controller::nrOfCases() {   //O(1)
	/*
	Returns the nr of cases in the queue
	*/
	return this->queue.length();
}

Node *Controller::getHead() {   //O(1)
	/*
	Returns the first element in the queue, without dequing it
	*/
	if (this->queue.length() > 0)
	{
		return this->queue.getFirst();
	}
	else
	{
		return NULL;
	}
}

Controller::~Controller() {
	/*
	Destructor for the controller
	it deletes all the nodes in the hash map's singly linked lists, dequing one by one
	*/
	while (this->queue.length() > 0) {
		Node *node = queue.dequeue();
		delete node;
	}
}

PriorityQueue Controller::getQueue() {
	//Returns the queue in the controller
	return this->queue;
}