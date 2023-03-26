﻿#include <iostream>
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
        if (nutritional_status < 50) {
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
    void health_check() {
        health_situation -= 5;
    }
    void Show_Information() {
        cout << "type: " << type << endl;
        cout << "age: " << age << endl;
        cout << "Health Situation: " << health_situation << endl;
        cout << "Nutritional Status: " << nutritional_status << endl;
        cout << "Milk Yield: " << milk_yield << endl;
        disease_control();
        hunger_control();
        thirst_control();
        void Show_Information(); {
            cout << "type: " << type << endl;
            cout << "age: " << age << endl;
            cout << "Health Situation: " << health_situation << endl;
            cout << "Nutritional Status: " << nutritional_status << endl;
            cout << "milk yield: " << milk_yield << endl;
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
        void food() {
            nutritional_status += 5;
        }
        void health_check() {
            health_situation -= 2;
        }
        void Show_Information() {
            cout << "type: " << type << endl;
            cout << "age: " << age << endl;
            cout << "Health Situation: " << health_situation << endl;
            cout << "Nutritional Status: " << nutritional_status << endl;
            cout << "number of eggs: " << Number_of_Eggs << endl;
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

    class Harvester : public AgricultureTool {
    private:
        int harvest_status;
    public:
        Harvester(int year_) : AgricultureTool("Harvester", year_) {
            harvest_status = 0;
        }
        void show_information() {
            cout << "type: " << type << endl;
            cout << "year: " << year << endl;
            
        }
        void refuel(int amount) {
            cout << "refueled." << endl;
        }
        void plow_soil() {
            cout << "plow soil." << endl;
        }