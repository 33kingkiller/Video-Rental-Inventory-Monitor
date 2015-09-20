#ifndef RENTVIDLIST_H
#define RENTVIDLIST_H

#include <fstream>
#include "rentvideo.h"

const int MAX_LENGTH = 500;

class RentedVideoList {
    public:
        RentedVideoList(const RentedVideo rentVidList[], int length);
        RentedVideoList(int length);
        RentedVideoList();
        void SortByID();
        void SortByCustomerID();
        void AddVideo(RentedVideo video);
        void RemoveVideo(RentedVideo video);
        bool IsFull() const;
        bool IsEmpty() const;
        bool IsPresent(RentedVideo video) const;
        void PrintList() const;
        void InputFromFile();
        void OutputToFile() const;
    private:
        RentedVideo videoList[MAX_LENGTH];
        int length;
        bool IsSame(RentedVideo vid1, RentedVideo vid2) const;
};
#endif // RENTVIDLIST_H
