#pragma once
#include <set>
#include <unordered_map>
using namespace std;
class Node {
public:
	std::string info;
	Node* next;
};

class PriorityQueue {
private:
	unordered_map<int, Node*> map;
	// a map<key,value> , where the keys are the priorities and the value is a pointer to a SLL, which holds
	//all the pacients with the corresponding priority
	set<int> priorities;
	//a set which holds the order of the priorities

public:
	PriorityQueue() {};
	//constructor for the queue

	void enqueue(string name, int priority) {
		/*
		In:
			name- the name of the pacient to be enqueued
			priority- it's priority
		It adds the "pacient" to the queue.
		Complexity:
				Inserting in the map has complexity O(1)
				However, inserting in the tree has complexity O(m), where m is the nr of elements in the tree
				Therefore,
				O(log(m)) is our complexity

		*/
		Node *newNode = new Node();
		newNode->info = name;
		newNode->next = NULL;
		auto it = map.find(priority);
		if (it == map.end()) {
			map.insert({ priority,newNode });
			priorities.insert(priority);
		}
		else
		{
			newNode->next = it->second;
			it->second = newNode;
		}
}

	Node *dequeue() {
		/*
		It returns the next "pacient" to be treated, the one with
		the highest priority
		Complexity:
		 O(log(m)) , where m is the nr of priorities
		which comes from the erasing from the tree set
		*/
		if (map.size() == 0)
		{
			return NULL;
		}
		auto first = priorities.begin();
		int priority = *first;
		Node *element = map[priority];
		Node *dequeued;
		if (element->next == NULL) {
			dequeued = element;
			element = NULL;
			priorities.erase(first);
			map.erase(priority);
		}
		else
		{
			dequeued = element;
			element = element->next;
			map[priority] = element;
		}
		return dequeued;
	}

	Node *getFirst() {
		/*
		Returns the first pacient to be treated, the one with the highest priority
		Complexity: O(log(m))
					because of the function begin() which computes a log(m) time alg on the tree set
		*/
		if (this->map.size() > 0) {
			auto first = this->priorities.begin();
			int priority = *first;
			Node *element = this->map[priority];
			return element;
		}
		else
		{
			return NULL;
		}
	}

	int length() {
		/*
		Returns the number of cases in the queue
		Complexity: O(n) , where n is the number of  cases in the queue
		*/
		Node *currentNode;
		int sum = 0;
		int counter;
		for (auto member : map) {
			currentNode = member.second;
			counter = 0;
			while (currentNode != NULL) {
				counter++;
				currentNode = currentNode->next;
			}

			sum += counter;

		}
		return sum;
	}
	unordered_map<int,Node*> getMap() {
		/*
		returns the map from the queue
		Complexity: O(1)
		*/
		return this->map;

	}

	set<int> getSet() {
		/*
		returns the Set of priorities
		Complexity: O(1)
		*/
		return this->priorities;
	}

	bool isEmpty() {
		/*
		Returns:
		true, if the queue is empty
		false otherwise
		Complexity: O(1)
		*/
		return this->getMap().size()==0;
	}
};