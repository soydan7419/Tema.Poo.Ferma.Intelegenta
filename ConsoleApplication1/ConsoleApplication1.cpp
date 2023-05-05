#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Animal {
protected:
    string type;
    int age;
    int health_situation;
    int nutritional_status;
    bool there_is_a_disease;
    bool there_is_hunger;
    bool there_is_thirst;
public:
    Animal(string type_, int age_) {
        type = type_;
        age = age_;
        health_situation = 100;
        nutritional_status = 100;
        there_is_a_disease = false;
        there_is_hunger = false;
        there_is_thirst = false;
    }
    virtual void feed() = 0;
    virtual void health_control() = 0;
    virtual void show_information() = 0;
    virtual void disease_control() {
        if (health_situation < 50) {
            there_is_a_disease = true;
            cout << "Patient: " << type << endl;
        }
        else {
            there_is_a_disease = false;
        }
    }
    virtual void hunger_control() {
        if (nutritional_status < 50) {
            there_is_hunger = true;
            cout << "Hungry: " << type << endl;
        }
        else {
            there_is_hunger = false;
        }
    }
    virtual void thirst_control() {
        if (there_is_thirst) {
            there_is_thirst = true;
            cout << "thirsty: " << type << endl;
        }
        else {
            there_is_thirst = false;
        }
    }
    virtual void to_cure() {
        if (there_is_a_disease) {
            health_situation += 10;
            cout << "to cure: " << type << endl;
        }
    }
    virtual void to_feed(int amount) {
        nutritional_status += amount;
        cout << "food was given: " << type << endl;
    }
    virtual void give_water(int amount) {
        nutritional_status += amount;
        cout << "water was given: " << type << endl;
    }
};

class Cow : public Animal {
private:
    int milk_yield;
public:
    Cow(int age_) : Animal("Cow", age_) {
        milk_yield = 0;
    }
    void feed() {
        nutritional_status += 10;
    }
    void health_control() {
        health_situation -= 5;
    }
    void show_information() {
        cout << "type: " << type << endl;
        cout << "age: " << age << endl;
        cout << "Health Situation: " << health_situation << endl;
        cout << "Nutritional Status: " << nutritional_status << endl;
        cout << "Milk Yield: " << milk_yield << endl;
        disease_control();
        hunger_control();
        thirst_control();
    }
};

class Chicken : public Animal {
private:
    int Number_of_Eggs;
public:
    Chicken(int age_) : Animal("Chicken", age_) {
        Number_of_Eggs = 0;
    }
    void feed() {
        nutritional_status += 5;
    }
    void health_control() {
        health_situation -= 2;
    }
    void show_information() {
        cout << "type: " << type << endl;
        cout << "age: " << age << endl;
        cout << "Health Situation: " << health_situation << endl;
        cout << "Nutritional Status: " << nutritional_status << endl;
        cout << "number of eggs: " <<
            Number_of_Eggs << endl;
        disease_control();
        hunger_control();
        thirst_control();
    }
    void collect_eggs() {
        Number_of_Eggs += 1;
        cout << "eggs were collected." << endl;
    }
};

class AgricultureTool {
protected:
    string type;
    int year;
public:
    AgricultureTool(string type_, int year_) {
        type = type_;
        year = year_;
    }
    virtual void show_information() = 0;
};

class tractor : public AgricultureTool {
private:
    int fuel_condition;
public:
    tractor(int year_) : AgricultureTool("tractor", year_) {
        fuel_condition = 100;
    }
    void show_information() {
        cout << "type: " << type << endl;
        cout << "year: " << year << endl;
        cout << "fuel_condition: " << fuel_condition << endl;
    }
    void refuel(int amount) {
        fuel_condition += amount;
        cout << "refueled." << endl;
    }
    void plow_soil() {
        cout << "plow soil." << endl;
    }
};

class Crop {
private:
    string type;
    int amount;
    int quality;
public:
    Crop(string type_, int amount_, int quality_) {
        type = type_;
        amount = amount_;
        quality = quality_;
    }
    string get_type() {
        return type;
    }
    int get_amount() {
        return amount;
    }
    int get_quality() {
        return quality;
    }
};


class Harvester : public AgricultureTool {
    
private:
    int harvest_status;
    int fuel_usage;

public:
    Harvester(int year_) : AgricultureTool("Harvester", year_) {
        harvest_status = 0;
        fuel_usage = 0;
    }
    void show_information() {
        cout << "type: " << type << endl;
        cout << "year: " << year << endl;
        cout << "harvest_status: " << harvest_status << endl;
    }
    void refuel(int amount) {
        cout << "refueled." << endl;
    }
    void harvest(vector<Crop>& crops) {
        cout << "harvesting crops." << endl;
        harvest_status = 100;

        int total_crop_amount = 0;
        int total_crop_quality = 0;
        for (int i = 0; i < crops.size(); i++) {
            total_crop_amount += crops[i].get_amount();
            total_crop_quality += crops[i].get_quality();
        }

        double payment = 0;
        if (total_crop_amount > 0) {
            double average_quality = (double)total_crop_quality / total_crop_amount;
            payment = total_crop_amount * average_quality * 0.1; // Calculation of amount payable
        }

        cout << "Payment: $" << payment << endl;
    }
    void use_fuel(int amount) {
        fuel_usage += amount;
    }
    int get_fuel_usage() {
        return fuel_usage;
    }
};

int main() {
    // Let's create a new Cow and Chicken object
    Cow myCow(3);
    Chicken myChicken(1);

    // Let's show the information
    myCow.show_information();
    myChicken.show_information();

    // Let's feed the animals
    myCow.feed();
    myChicken.feed();

    // Let's show the information again
    myCow.show_information();
    myChicken.show_information();

    // Let's collect chicken eggs
    myChicken.collect_eggs();
    myChicken.collect_eggs();
    myChicken.collect_eggs();

    // Let's create a new Harvester object
    Harvester myHarvester(2022);

    // Let's show the information
    myHarvester.show_information();

    // Let's use the tractor
    tractor myTractor(2021);

    // Let's show the information
    myTractor.show_information();

    // Let's use the tractor to plow the land
    myTractor.plow_soil();

    return 0;
}

