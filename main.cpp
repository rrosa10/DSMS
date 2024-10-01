#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Spider {
private:
    string name;
    string species;
    string sex;
    string coloration;
    float size;
    int age;
    vector<string> feedingHistory;
    vector<string> diet;
    map<string, string> feedingRecords;

public:
    // Constructor
    Spider(string spiderName, string spiderSpecies, string spiderSex, string spiderColoration, float spiderSize, int spiderAge);
    Spider();
    // Getters
    string getName() const;
    string getSpecies() const;
    string getSex() const;
    string getColoration() const;
    float getSize() const;
    int getAge() const;

    // Setters
    void setName(const string& spiderName);
    void setSpecies(const string& spiderSpecies);
    void setSex(const string& spiderSex);
    void setColoration(const string& spiderColoration);
    void setSize(float spiderSize);
    void setAge(int spiderAge);

    // Additional functionalities
    void addFeedingToRecord(const string& date, const string& prey);
    void displaySpiderInfo() const;
};

Spider::Spider(){
    name = "No name";
    species = "No speices";
    sex = "No name";
    coloration = "No coloration";
    size = 0;
    age = 0;
    feedingHistory;
    diet;
}

Spider::Spider(string spiderName, string spiderSpecies, string spiderSex, string spiderColoration, float spiderSize, int spiderAge)
    : name(spiderName), species(spiderSpecies), sex(spiderSex), coloration(spiderColoration), size(spiderSize), age(spiderAge) {}

void Spider::displaySpiderInfo() const{
    cout << "Name: " << this->name << endl;
    cout << "Species: " << this->species << endl;
    cout << "Coloration: " << this->coloration << endl;
    cout << "Size: " << this->size << endl;
    cout << "Sex: " << this->sex << endl;
    cout << "Age: " << this->age << endl;
}

void Spider::addFeedingToRecord(const string& date, const string& prey){
    if(feedingRecords.find(date) == feedingRecords.end()){
        feedingRecords[date] = prey;
    }else{
        cout << "Feeding record already exists for this date!" << endl;
        cout << "Don't overfeed the spider!" << endl;
    }
}

int main(){
    vector<Spider> spiderCollection;
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
            spiderCollection.push_back(newSpider);
        }else if(choice == 'P' || choice == 'p'){
            for(int i = 0; i < spiderCollection.size(); i++){
                spiderCollection[i].displaySpiderInfo();
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
                    if(spiderCollection[i].getName() == name){
                        found = true;
                        cout << "Enter the food: ";
                        cin >> food;
                        cout << "Enter the date: ";
                        cin >> date;
                        spiderCollection[i].addFeedingToRecord(date, food);
                    }
                }
                if(!found){
                    cout << "Spider not found!" << endl;
                }
            }
        }

    }while(choice != 'x');


    return 0;
}