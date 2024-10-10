#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Spider.h"
#include <fstream>
#include <iomanip>

using namespace std;


int main(){
    vector<Spider*> spiderCollection;
    bool loaded = false;
    cout << "=====Welcome to The Dynamic Spider Managment Company!=====" << endl;
    char choice;
    do{
        cout << "\nWhat would you like to do today?" << endl;
        cout << "A - Add a spider" << endl;
        cout << "T - Alter an existing spider" << endl;
        cout << "P - See your collection" << endl;
        cout << "F - Add a feeding record" << endl;
        cout << "S - Save your collection" << endl;
        cout << "L - Load your collection" << endl;
        cout << "X - Exit" << endl;
        cin >> choice;
        cin.ignore();

        if(choice == 'A' || choice == 'a'){
            string name, speices, coloration, sex;
            float size;
            int age;
            cout << "\nEnter the name of the spider: ";
            getline(cin, name);
            cout << "\nEnter the species of the spider: ";
            getline(cin, speices);
            cout << "\nEnter the coloration of the spider: ";
            getline(cin, coloration);
            cout << "\nEnter the sex of the spider: ";
            getline(cin, sex);
            cout << "\nEnter the size of the spider: ";
            cin >> size;
            cout << "\nEnter the age of the spider: ";
            cin >> age;
            cin.ignore();
            Spider* newSpiderPtr = new Spider(name, speices, sex, coloration, size, age);
            spiderCollection.push_back(newSpiderPtr);
        }
        else if(choice == 'P' || choice == 'p'){
            cout << "\nYour collection: " << endl;
            for(size_t i = 0; i < spiderCollection.size(); i++){
                cout << "Spider " << i+1 << endl;
                spiderCollection[i]->displaySpiderInfo();
                cout << endl;
            }
        }
        else if(choice == 'F' || choice == 'f'){
            string name;
            string food;
            string date;
            bool found = false;
            while(!found){
                cout << "Enter the name of the spider: ";
                cin >> name;
                for(size_t i = 0; i < spiderCollection.size(); i++){
                    if(spiderCollection[i]->getName() == name){
                        found = true;
                        cout << "Enter the food: ";
                        cin >> food;
                        cout << "Enter the date: ";
                        cin >> date;
                        spiderCollection[i]->addFeedingToRecord(date, food);
                    }
                }
                if(!found){
                    cout << "Spider not found!" << endl;
                }
            }
        }
        else if (choice == 'T' || choice == 't'){
            string name = "";
            cout << "Enter the name of the spider you want to alter: ";
            cin >> name;
            for(size_t i = 0; i < spiderCollection.size(); i++){
                if (spiderCollection[i]->getName() == name){
                    string newName, newSpecies, newColoration, newSex;
                    float newSize;
                    int newAge;
                    cout << "Enter the new name of the spider: ";
                    cin >> newName;
                    cout << "Enter the new species of the spider: ";
                    cin >> newSpecies;
                    cout << "Enter the new coloration of the spider: ";
                    cin >> newColoration;
                    cout << "Enter the new sex of the spider: ";
                    cin >> newSex;
                    cout << "Enter the new size of the spider: ";
                    cin >> newSize;
                    cout << "Enter the new age of the spider: ";
                    cin >> newAge;
                    spiderCollection[i]->setName(newName);
                    spiderCollection[i]->setSpecies(newSpecies);
                    spiderCollection[i]->setColoration(newColoration);
                    spiderCollection[i]->setSex(newSex);
                    spiderCollection[i]->setSize(newSize);
                    spiderCollection[i]->setAge(newAge);
                }
            }
        }
        else if(choice == 'S' || choice == 's'){
            cout << "Saving your collection..." << endl;
            ofstream outFile("spiderCollection.txt");
            for(Spider* spider: spiderCollection){
                spider->saveToFile(outFile);
            }
            outFile.close();
            cout << "Collection saved!" << endl;
        }
        else if(choice == 'L' || choice == 'l'){
            if(loaded){
                cout << "Collection already loaded!" << endl;
            }else{
                cout << "Loading your collection..." << endl;
                string fileName = "spiderCollection.txt";
                spiderCollection = Spider::loadSpidersFromFile(fileName);  // Use the Spider class scope
                loaded = true;
            }
        }

    }while(choice != 'x');

    for (auto spider : spiderCollection){
        delete spider;
    }
    return 0;
}