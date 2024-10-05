// Spider.cpp
#include "Spider.h"

// Default constructor
Spider::Spider() {
    name = "No name";
    species = "No species";  // Fixed typo from "No speices" to "No species"
    sex = "No sex";          // Fixed "No name" to "No sex" for clarity
    coloration = "No coloration";
    size = 0;
    age = 0;
    feedingHistory = {};
    diet = {};
}

// Parameterized constructor
Spider::Spider(string spiderName, string spiderSpecies, string spiderSex, string spiderColoration, float spiderSize, int spiderAge)
    : name(spiderName), species(spiderSpecies), sex(spiderSex), coloration(spiderColoration), size(spiderSize), age(spiderAge) {}

// Setters
void Spider::setName(const string& spiderName) {
    name = spiderName;
}

void Spider::setSpecies(const string& spiderSpecies) {
    species = spiderSpecies;
}

void Spider::setSex(const string& spiderSex) {
    sex = spiderSex;
}

void Spider::setColoration(const string& spiderColoration) {
    coloration = spiderColoration;
}

void Spider::setSize(float spiderSize) {
    size = spiderSize;
}

void Spider::setAge(int spiderAge) {
    age = spiderAge;
}

// Display spider information
void Spider::displaySpiderInfo() const {
    cout << "Name: " << this->name << endl;
    cout << "Species: " << this->species << endl;
    cout << "Coloration: " << this->coloration << endl;
    cout << "Size: " << this->size << endl;
    cout << "Sex: " << this->sex << endl;
    cout << "Age: " << this->age << endl;
}

// Add feeding record
void Spider::addFeedingToRecord(const string& date, const string& prey) {
    if (feedingRecords.find(date) == feedingRecords.end()) {
        feedingRecords[date] = prey;
    } else {
        cout << "Feeding record already exists for this date!" << endl;
        cout << "Don't overfeed the spider!" << endl;
    }
}
