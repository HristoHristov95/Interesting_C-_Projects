#include<iostream>
#include<fstream>
#include<string>
#include<list>
#include<cstdlib>
using namespace std;
class ElectricalComponents;
class SpecificComponent;
enum Unit { pF, oM, unknown };
const int maxLetters = 50;
const char* fileName = "ThisIsATest.txt";
list<ElectricalComponents*> allElectricalComponents;
list<SpecificComponent*> allSpecificComponents;
class ElectricalComponents {
	long itemNumber; //номенклатурен номер
	char* name; // име на компонент
	int nameLenght;
	int capacity; // стойност 
	Unit unit;
public:
	ofstream fout;
	ifstream fin;
	ElectricalComponents();
	ElectricalComponents(long, char*, int, int, Unit);
	ElectricalComponents(const ElectricalComponents&);
	~ElectricalComponents();
	long getItemNumber() const;
	int getNameLenght() const;
	char* getName() const;
	int getCapacity() const;
	Unit getUnit() const; 
	void readFromFile();
	void printToFile();
	virtual void printInfo();
	virtual void add();
	void findCapacitor();
	void deleteElement();
	friend ostream& operator<<(ostream& variable, ElectricalComponents& obj);
	friend ofstream& operator<<(ofstream& variable, ElectricalComponents& obj);
};
class SpecificComponent : public ElectricalComponents {
	char* country; // страна в която е произведен
	int countryLenght;
	char* manufacturer; // производител (марка)
	int manLenght;
	double price; // цена
public:
	SpecificComponent();
	SpecificComponent(long, char*, int, int, Unit, char*, int, char*, int, double);
	SpecificComponent(const SpecificComponent&);
	~SpecificComponent();
	char* getCountry() const;
	char* getManufacturer() const;
	double getPrice() const;
	void printInfo();
	void add();
	friend ostream& operator<<(ostream& variable, SpecificComponent& obj);
	friend ofstream& operator<<(ofstream& variable, SpecificComponent& obj);
};
SpecificComponent::SpecificComponent() : ElectricalComponents() {
	country = new char[maxLetters];
	strcpy(country, " ");
	manufacturer = new char[maxLetters];
	strcpy(manufacturer, " ");
	price = -1;
	countryLenght = 1;
	manLenght = 1;
}
SpecificComponent::SpecificComponent(long itemNumber, char* name, int lenght, int capacity, Unit u, char* country, int lenght1, char* manufacturer, int lenght2, double price) : ElectricalComponents(itemNumber, name, lenght, capacity, u) {
	this->country = new char[maxLetters];
	if (lenght1 > maxLetters) {
		cout << "Invalid lenght of word !\n";
		exit(1);
	}
	else {
		strcpy(this->country, country);
	}
	countryLenght = lenght1;
	this->manufacturer = new char[maxLetters];
	if (lenght2 > maxLetters) {
		cout << "Invalid lenght of word !\n";
		exit(1);
	}
	else {
		strcpy(this->manufacturer, manufacturer);
	}
	manLenght = lenght2;
	this->price = price;
}
SpecificComponent::SpecificComponent(const SpecificComponent& obj) : ElectricalComponents(obj.getItemNumber(), obj.getName(), obj.getNameLenght(), obj.getCapacity(), obj.getUnit()) {
	this->country = new char[maxLetters];
	strcpy(this->country, obj.country);
	this->manufacturer = new char[maxLetters];
	strcpy(this->manufacturer, obj.manufacturer);
	this->price = obj.price;
}
SpecificComponent::~SpecificComponent() {
	if (country) {
		delete[] country;
	}
	if (manufacturer) {
		delete[] manufacturer;
	}
}
char* SpecificComponent::getCountry() const {
	return this->country;
}
char* SpecificComponent::getManufacturer() const {
	return this->manufacturer;
}
double SpecificComponent::getPrice() const{
	return this->price;
}
void SpecificComponent::printInfo() {
	cout << *this;
}
void SpecificComponent::add() {
	readFromFile();
	long number;
	char* name = new char[maxLetters];
	int capacity;
	int unit;
	Unit s;
	char* country = new char[maxLetters];
	char* manufacturer = new char[maxLetters];
	double price;
	cout << "Enter item number: ";
	cin >> number;
	cout << '\n';
	cout << "Enter item name: ";
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.getline(name, maxLetters);
	cout << '\n';
	cout << "Enter capacity: ";
	cin >> capacity;
	cout << '\n';
	cout << "Enter unit: (0,1)";
	cin >> unit;
	s = (Unit)unit;
	cout << '\n';
	cout << "Enter country: ";
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.getline(country, maxLetters);
	cout << '\n';
	cout << "Enter manufacturer: ";
	cin.clear(0);
	cin.getline(manufacturer, maxLetters);
	cout << '\n';
	cout << "Enter price: ";
	cin >> price;
	cout << '\n';
	allSpecificComponents.push_back(new SpecificComponent(number, name, strlen(name), capacity, s, country, strlen(country), manufacturer, strlen(manufacturer), price));
	printToFile();
	cout << "Successfuly added component !\n";
	allElectricalComponents.erase(allElectricalComponents.begin(), allElectricalComponents.end());
	allSpecificComponents.erase(allSpecificComponents.begin(), allSpecificComponents.end());
	delete[] name;
	delete[] country;
	delete[] manufacturer;
	system("PAUSE");
}
ElectricalComponents::ElectricalComponents() {
	itemNumber = -1;
	this->name = new char[maxLetters];
	strcpy(name, " ");
	nameLenght = 0;
	capacity = -1;
	unit = unknown;
}
ElectricalComponents::ElectricalComponents(long itemNumber, char* name, int lenght, int capacity, Unit u) {
	this->itemNumber = itemNumber;
	this->name = new char[maxLetters];
	if (!this->name) {
		cout << "Error allocating memory!\n";
		exit(1);
	}
	if (lenght > maxLetters) {
		cout << "Name is too long ! (max 50 symbols!)\n";
		exit(1);
	}
	strcpy(this->name, name);
	nameLenght = lenght;
	this->capacity = capacity;
	this->unit = u;
}
ElectricalComponents::ElectricalComponents(const ElectricalComponents& obj) {
	this->itemNumber = obj.itemNumber;
	this->name = new char[maxLetters];
	strcpy(this->name, obj.name);
	this->nameLenght = obj.nameLenght;
	this->capacity = obj.capacity;
	this->unit = obj.unit;
}
ElectricalComponents::~ElectricalComponents() {
	if (name) {
		delete[] name;
	}
	else
	{
		cout << "Error memory is NULL!\n";
		exit(1);
	}
}
long ElectricalComponents::getItemNumber() const {
	return itemNumber;
}
char* ElectricalComponents::getName() const {
	return name;
}
int ElectricalComponents::getCapacity() const {
	return capacity;
}
Unit ElectricalComponents::getUnit() const {
	return unit;
}
int ElectricalComponents::getNameLenght() const {
	return nameLenght;
}
void ElectricalComponents::printInfo() {
	cout << *this;
}
void ElectricalComponents::readFromFile()
{
	char* str = new char[maxLetters];
	int a = -1;
	fin.open(fileName);
	if (fin.is_open()) {
		while (!fin.eof()) {
			fin.getline(str, maxLetters);
			if (strcmp(str, "")==0) {
				break;
			}
			itemNumber = atoi(str);
			fin.getline(str, maxLetters);
			strcpy(name, str);
			fin.getline(str, maxLetters);
			capacity = atoi(str);
			fin.getline(str, maxLetters);
			a = atoi(str);
			unit = (Unit)a;
			fin.getline(str, maxLetters);
			if (strcmp(str, "*") == 0) {
				allElectricalComponents.push_back(new ElectricalComponents(itemNumber, name,strlen(name), capacity, unit));
			}
			else {
				char* country = new char[maxLetters];
				strcpy(country, str);
				fin.getline(str, maxLetters);
				char* manufacturer = new char[maxLetters];
				strcpy(manufacturer, str);
				fin.getline(str, maxLetters);
				double price = atoi(str);
				allSpecificComponents.push_back(new SpecificComponent(itemNumber,name,strlen(name),capacity,unit,country,strlen(country),manufacturer,strlen(manufacturer),price));
				fin.getline(str, maxLetters);
				delete[] country;
				delete[] manufacturer;
			}
		}
	}
	else {
		cout << "Opening file to read from ERROR!\n";
		exit(1);
	}
	delete[] str;
	fin.close();
}
void ElectricalComponents::printToFile() {
	fout.open(fileName);
	if (fout.is_open()) {
		list<ElectricalComponents*>::iterator p = allElectricalComponents.begin();
		list<SpecificComponent*>::iterator p2 = allSpecificComponents.begin();
		for (int i = 0; i < allElectricalComponents.size(); i++) {
			fout << (*p)->getItemNumber() << '\n';
			fout << (*p)->getName() << '\n';
			fout << (*p)->getCapacity() << '\n';
			fout << (*p)->getUnit() << '\n';
			fout << "*" << '\n';
			p++;
		}
		for (int i = 0; i < allSpecificComponents.size(); i++) {
			fout << (*p2)->getItemNumber() << '\n';
			fout << (*p2)->getName() << '\n';
			fout << (*p2)->getCapacity() << '\n';
			fout << (*p2)->getUnit() << '\n';
			fout << (*p2)->getCountry() << '\n';
			fout << (*p2)->getManufacturer() << '\n';
			fout << (*p2)->getPrice() << '\n';
			fout << "*" << '\n';
			p2++;
		}
	}
	else {
		cout << "Opening file to write ERROR!\n";
		exit(1);
	}
	fout.close();
}
void ElectricalComponents::add() {
	readFromFile();
	long number;
	char* name1 = new char[maxLetters];
	int capacity;
	int unit;
	Unit s;
	cout << "Enter item number: ";
	cin >> number;
	cout << '\n';
	cout << "Enter item name: ";
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.getline(name1, maxLetters);
	cout << '\n';
	cout << "Enter capacity: ";
	cin >> capacity;
	cout << '\n';
	cout << "Enter unit: (0,1)";
	cin >> unit;
	s = (Unit)unit;
	allElectricalComponents.push_back(new ElectricalComponents(number, name1, strlen(name1), capacity, s));
	printToFile();
	cout << "Successfuly added component !\n";
	allElectricalComponents.erase(allElectricalComponents.begin(), allElectricalComponents.end());
	allSpecificComponents.erase(allSpecificComponents.begin(), allSpecificComponents.end());
	delete[] name1;
	system("PAUSE");
}
void ElectricalComponents::deleteElement() {
	readFromFile();
	char* str = new char[maxLetters];
	list<ElectricalComponents*>::iterator p = allElectricalComponents.begin();
	list<SpecificComponent*>::iterator p2 = allSpecificComponents.begin();
	cout << "Enter element name to be deleted: ";
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.getline(str, maxLetters);
	for (int i = 0; i < allElectricalComponents.size(); i++) {
		if (strcmp((*p)->getName(), str) == 0) {
			allElectricalComponents.erase(p);
			printToFile();
			allElectricalComponents.erase(allElectricalComponents.begin(), allElectricalComponents.end());
			allSpecificComponents.erase(allSpecificComponents.begin(), allSpecificComponents.end());
			cout << "Success!\n";
			delete[] str;
			system("PAUSE");
			return;
		}
		p++;
	}
	for (int i = 0; i < allSpecificComponents.size(); i++) {
		if (strcmp((*p2)->getName(), str) == 0) {
			allSpecificComponents.erase(p2);
			printToFile();
			allElectricalComponents.erase(allElectricalComponents.begin(), allElectricalComponents.end());
			allSpecificComponents.erase(allSpecificComponents.begin(), allSpecificComponents.end());
			cout << "Success!\n";
			delete[] str;
			system("PAUSE");
			return;
		}
		p2++;
	}
	cout << "Element not found !\n";
	system("PAUSE");
}
void ElectricalComponents::findCapacitor() {
	readFromFile();
	int min, max;
	cout << "Please enter minimum value: ";
	cin >> min;
	cout << '\n';
	cout << "Please enter maximum value: ";
	cin >> max;
	cout << '\n';
	list<ElectricalComponents*>::iterator p = allElectricalComponents.begin();
	list<SpecificComponent*>::iterator p2 = allSpecificComponents.begin();
	for (int i = 0; i < allElectricalComponents.size(); i++) {
		if (((*p)->getCapacity() > min) && ((*p)->getCapacity() < max)) {
			(*p)->printInfo();
		}
		p++;
	}
	for (int i = 0; i < allSpecificComponents.size(); i++) {
		if (((*p2)->getCapacity() > min) && ((*p2)->getCapacity() < max)) {
			(*p2)->printInfo();
		}
		p2++;
	}
	allElectricalComponents.erase(allElectricalComponents.begin(),allElectricalComponents.end());
	allSpecificComponents.erase(allSpecificComponents.begin(),allSpecificComponents.end());
	system("PAUSE");
}
ostream& operator<<(ostream& variable, ElectricalComponents& obj) {
	variable << "Item number: " << obj.itemNumber << '\n';
	variable << "Item name: " << obj.name << '\n';
	variable << "Item capacity: " << obj.capacity << '\n';
	variable << "Item unit: " << obj.unit << '\n';
	variable << '\n';
	return variable;
}
ostream& operator<<(ostream& variable, SpecificComponent& obj) {
	variable << "Item number" << obj.getItemNumber() << '\n';
	variable << "Item name: " << obj.getName() << '\n';
	variable << "Item capacity: " << obj.getCapacity() << '\n';
	variable << "Item unit: " << obj.getUnit() << '\n';
	variable << "Item country: " << obj.getCountry() << '\n';
	variable << "Item manufacturer: " << obj.getManufacturer() << '\n';
	variable << "Item price: " << obj.getPrice() << '\n';
	variable << "\n";
	return variable;
}
ofstream& operator<<(ofstream& variable, ElectricalComponents& obj) {
	variable << obj.getItemNumber() << '\n';
	variable << obj.getName() << '\n';
	variable << obj.getCapacity() << '\n';
	variable << obj.getUnit() << '\n';
	variable << "*" << '\n';
	return variable;
}
ofstream& operator<<(ofstream& variable, SpecificComponent& obj) {
	variable << obj.getItemNumber() << '\n';
	variable << obj.getName() << '\n';
	variable << obj.getCapacity() << '\n';
	variable << obj.getUnit() << '\n';
	variable << obj.getCountry() << '\n';
	variable << obj.getManufacturer() << '\n';
	variable << obj.getPrice() << '\n';
	variable << "*" << '\n';
	return variable;
}
int main() {
	char ch='-1';
	ElectricalComponents* pointer=NULL;
	ElectricalComponents objUseE;
	SpecificComponent objUseS;
	pointer = &objUseE;
	do {
		cout << "1. Add electrical component to file.\n";
		cout << "2. Add specific electrical component to file.\n";
		cout << "3. Delete element from file.\n";
		cout << "4. Find capacitor within minimum and maximum values.\n";
		cout << "0. Exit program. \n";
		cin >> ch;
		switch (ch) {
		case '1': { pointer = &objUseE; pointer->add(); break; }
		case '2': { pointer = &objUseS; pointer->add(); break; }
		case '3': { pointer->deleteElement(); break; }
		case '4': { pointer = &objUseE; pointer->findCapacitor(); break; }
		case '0' : break;
		default: 
			cout << "Error you have entered invalid command !\n\n"; system("PAUSE"); break;
		}
		system("CLS");
	} while (ch != '0');
	pointer = NULL;
	return 0;
}


