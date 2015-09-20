#ifndef RENTVIDEO_H
#define RENTVIDEO_H

#include "video.h"
#include "customer.h"

class RentedVideo : public Video {
    public:
        RentedVideo(std::string title, int id, CustomerInfo customer);
        RentedVideo();
        void SetCustomer(CustomerInfo customer);
        CustomerInfo GetCustomer() const;
        void PrintInfo() const;
    private:
        CustomerInfo customer;
};
#endif // RENTVIDEO_H
