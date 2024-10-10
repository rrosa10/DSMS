// Spider.cpp
#include "Spider.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <sstream>


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

// Copy constructor
Spider::Spider(const Spider& spider) {
    name = spider.name;
    species = spider.species;
    sex = spider.sex;
    coloration = spider.coloration;
    size = spider.size;
    age = spider.age;
    feedingHistory = spider.feedingHistory;
    diet = spider.diet;
}

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

// Save spider information to file
void Spider::saveToFile(ofstream& file) const {
    file << name << ", " << species << ", " << sex << "," << coloration << ", " << size << ", " << age << "\n";
}

// read line from file which respresents a spider 
// should there a return type? 
std::vector<Spider*> Spider::loadSpidersFromFile(const std::string& filename) {
    vector<Spider*> spiders; // Create a vector of Spider objects
    ifstream file(filename); // Open the file
    
    if(!file.is_open()){ // Check if the file is open
        cout << "Error opening file!" << endl;
        return spiders; // Return an empty vector if the file cannot be opened
    }

    string line; // Create a string to store each line of the file
    while(getline(file, line)){ // Read each line of the file
        stringstream ss(line); // Creat a stringstream object to parse the line. 
        string name, species, sex, coloration; // Create variables to store the data
        float size;
        int age;
        getline(ss, name, ','); // Parse the line using the comma as a delimiter
        getline(ss, species, ',');
        getline(ss, sex, ',');
        getline(ss, coloration, ',');
        ss >> size;
        ss.ignore();
        ss >> age;
        ss.ignore();
        spiders.push_back(new Spider(name, species, sex, coloration, size, age));

    }
    file.close(); // Close the file
    return spiders; // Return the vector of Spider objects
}