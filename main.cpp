#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Spider.h"

using namespace std;


int main(){
    vector<Spider*> spiderCollection;
    cout << "=====Welcome to The Dynamic Spider Managment Company!=====" << endl;
    char choice;
    do{
        cout << "\nWhat would you like to do today?" << endl;
        cout << "A - Add a spider" << endl;
        cout << "T - Alter an existing spider" << endl;
        cout << "P - See your collection" << endl;
        cout << "F - Add a feeding record" << endl;
        cout << "X - Exit" << endl;
        cin >> choice;

        if(choice == 'A' || choice == 'a'){
            string name, speices, coloration, sex;
            float size;
            int age;
            cout << "\nEnter the name of the spider: ";
            cin >> name;
            cout << "\nEnter the species of the spider: ";
            cin >> speices;
            cout << "\nEnter the coloration of the spider: ";
            cin >> coloration;
            cout << "\nEnter the sex of the spider: ";
            cin >> sex;
            cout << "\nEnter the size of the spider: ";
            cin >> size;
            cout << "\nEnter the age of the spider: ";
            cin >> age;
            Spider newSpider(name, speices, sex, coloration, size, age);
            Spider* newSpiderPtr = new Spider(name, speices, sex, coloration, size, age);
            spiderCollection.push_back(newSpiderPtr);
        }else if(choice == 'P' || choice == 'p'){
            for(int i = 0; i < spiderCollection.size(); i++){
                spiderCollection[i]->displaySpiderInfo();
                cout << endl;
            }
        }else if(choice == 'F' || choice == 'f'){
            string name;
            string food;
            string date;
            bool found = false;
            while(!found){
                cout << "Enter the name of the spider: ";
                cin >> name;
                for(int i = 0; i < spiderCollection.size(); i++){
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

    }while(choice != 'x');

    for (auto spider : spiderCollection){
        delete spider;
    }
    return 0;
}