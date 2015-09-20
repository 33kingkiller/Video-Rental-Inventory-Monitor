#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class CustomerInfo {
    public:
        CustomerInfo(std::string name, int id, int age);
        CustomerInfo();
        void SetName(std::string);
        void SetID(int id);
        void SetAge(int age);
        std::string GetName() const;
        int GetID() const;
        int GetAge() const;
        void PrintInfo() const;
    private:
        std::string name;
        int id;
        int age;
};
#endif // CUSTOMER_H
