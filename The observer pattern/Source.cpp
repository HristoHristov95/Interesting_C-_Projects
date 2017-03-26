#include<iostream>
#include<vector>
using namespace std;
class AllObservableObjects;
class Observer;
class ChangeHolder;
class ShopsExample;

class Observer {
public:
	Observer() {}
	~Observer() {}
	virtual void update(int somethingImportantToBeSetToAllObjects) = 0;
};


class  AllObservableObjects{
	static string* stateFlag;
	vector<ObjectExample*> allObjects;
public:
	AllObservableObjects() {}
	~AllObservableObjects() {}
	void add(ShopsExample* newObject);
	void remove(ShopsExample* oldObject);
	void notifyObjects(int somethingImportantToBeSetToAllObjects);
	string* getState();
};
string* AllObservableObjects::stateFlag = 0;
void AllObservableObjects::add(ShopsExample* newObject) {
	this->allObjects.push_back(newObject);
}
void AllObservableObjects::remove(ShopsExample* oldObject) {
	for (int i = 0; i < this->allObjects.size(); i++)
	{
		if (this->allObjects[i] == oldObject)
		{
			this->allObjects.erase(this->allObjects.begin() + i);
			return;
		}
	}
}
void AllObservableObjects::notifyObjects(int somethingImportantToBeSetToAllObjects) {
	for (int i = 0; i < this->allObjects.size(); i++)
	{
		allObjects[i]->update(somethingImportantToBeSetToAllObjects);
	}
}
string* AllObservableObjects::getState() {
	return stateFlag;
}


class ChangeHolder :public AllObservableObjects {
public:
	void changeEveryObjectInVectorStartPoint(int newNumber){ notifyObjects(newNumber); }
};



class  ObjectExample : public Observer {
	string name;
	float importantNumber;
public:
	ObjectExample(string name,float number) : Observer() {
		this->name = name;
		this->importantNumber = number;
	}
	void update(int number);
};
void  ObjectExample::update(int number) {
	this->importantNumber = number;
	cout << "Number has changed in ObjectExample !" << endl;
}


int main() {

	return 0;
}