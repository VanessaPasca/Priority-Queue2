#include "Tests.h"
#include <assert.h>
#include <iostream>
using namespace std;

void testAddCase(Controller & controller) {
	/*
	Tests the add case functionality
	In the same time checks how the tree grows in size while adding new cases with NEW priorities
	*/
	assert(controller.nrOfCases() == 0);
	
	controller.addController("Jason", "gunshot - wound");
	assert(controller.nrOfCases() == 1);
	assert(controller.getQueue().getSet().size() == 1);
	
	controller.addController("Annie", "paper cut");
	assert(controller.getQueue().getSet().size() == 2);
	
	controller.addController("Manuel", "broken leg");
	assert(controller.getQueue().getSet().size() == 3);
	assert(controller.getHead()->info == "Jason");
	
	controller.addController("Carla", "broken rib");
	
	controller.addController("Clark", "nausea");
	assert(controller.nrOfCases() == 5);
	assert(controller.getHead()->info == "Jason");
	
	controller.addController("James", "gunshot-wound");
	assert(controller.getHead()->info == "James");
	
	controller.addController("Priscilla", "gunshot-wound");
	controller.addController("George", "broken neck");
	controller.addController("Julia", "paper cut");
	assert(controller.nrOfCases() == 9);
	
	controller.addController("Tarek", "gunshot-wound");
	controller.addController("Amir", "paper cut");
	assert(controller.nrOfCases() == 11);
}

void testTreatPerson(Controller & controller) {
	/*
	Tests if the treating person functionality works
	*/
	assert(controller.getHead()->info == "Tarek");
	controller.treatPerson();
	assert(controller.nrOfCases() == 10);
	assert(controller.getHead()->info == "Priscilla");
	controller.treatPerson();
	assert(controller.nrOfCases() == 9);
	assert(controller.getHead()->info == "James");
	controller.treatPerson();
	assert(controller.nrOfCases() == 8);
	assert(controller.getHead()->info == "Jason");

	controller.treatPerson();
	assert(controller.nrOfCases() == 7);
	assert(controller.getHead()->info == "George");
	controller.treatPerson();
	assert(controller.nrOfCases() == 6);
	assert(controller.getHead()->info == "Carla");
	controller.treatPerson();
	assert(controller.nrOfCases() == 5);
	assert(controller.getHead()->info == "Manuel");
	controller.treatPerson();
	assert(controller.nrOfCases() == 4);
	assert(controller.getHead()->info == "Amir");
	controller.treatPerson();
	assert(controller.nrOfCases() == 3);
	assert(controller.getHead()->info == "Julia");
	controller.treatPerson();
	assert(controller.nrOfCases() == 2);
	assert(controller.getHead()->info == "Clark");
	controller.treatPerson();
	assert(controller.nrOfCases() == 1);
	assert(controller.getHead()->info == "Annie");
	controller.treatPerson();
	assert(controller.nrOfCases() == 0);
	assert(controller.getHead()== NULL);



}
void testIsEmpty(Controller & controller) {
	/*
	Tests the isEmpty() function of the queue
	*/
	assert(controller.getQueue().isEmpty() == true);
}

void testNumberOfPriorities(Controller & controller) {
	assert(controller.getQueue().getMap().size() == 3);
}
void testAll() {
	PriorityQueue queue{};
	Controller controller(queue);
	testAddCase(controller);
	testNumberOfPriorities(controller);
	testTreatPerson(controller);
	testIsEmpty(controller);

}