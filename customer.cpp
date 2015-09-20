#include "customer.h"
#include <iostream>

CustomerInfo::CustomerInfo(std::string nameAtBirth, int iD, int ageFromBirth) {
    name = nameAtBirth;
    id = iD;
    age = ageFromBirth;
}

CustomerInfo::CustomerInfo() {
    name = "Anonymous";
    id = -1;
    age = -1;
}

void CustomerInfo::SetName(std::string nameAtBirth) {
    name = nameAtBirth;
}

void CustomerInfo::SetID(int iD) {
    id = iD;
}

void CustomerInfo::SetAge(int ageFromBirth) {
    age = ageFromBirth;
}

std::string CustomerInfo::GetName() const {
    return name;
}

int CustomerInfo::GetID() const {
    return id;
}

int CustomerInfo::GetAge() const {
    return age;
}

void CustomerInfo::PrintInfo() const {
    std::cout << "CUSTOMER NAME: " << name << ", CUSTOMER ID: " << id << ", CUSTOMER AGE: " << age;
}
