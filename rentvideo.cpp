#include "rentvideo.h"
#include <iostream>

RentedVideo::RentedVideo(std::string ttl, int iD, CustomerInfo cstmr) : Video(ttl, iD) {
    customer = cstmr;
}

RentedVideo::RentedVideo() {
    customer.SetAge(-1);
    customer.SetName("Anonymous");
    customer.SetID(-1);
}

void RentedVideo::SetCustomer(CustomerInfo cstmr) {
    customer = cstmr;
}

CustomerInfo RentedVideo::GetCustomer() const {
    return customer;
}

void RentedVideo::PrintInfo() const {
    Video::PrintInfo();
    std::cout << ", ";
    customer.PrintInfo();
}
