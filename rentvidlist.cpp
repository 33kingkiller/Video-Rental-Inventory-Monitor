#include "rentvidlist.h"
#include <iostream>

RentedVideoList::RentedVideoList(const RentedVideo vidList[], int lngth) {
    for(int i = 0; i < lngth; i++) {
        videoList[i] = vidList[i];
    }
    length = lngth;
}

RentedVideoList::RentedVideoList(int lngth) {
    length = lngth;
}

RentedVideoList::RentedVideoList() {
    length = 0;
}

void RentedVideoList::SortByID() {
    RentedVideo tmp;
    int smallestIndex;
    for(int i = 0; i < length - 1; i++) {
        smallestIndex = i;
        for(int k = i + 1; k < length; k++) {
            if(videoList[k].GetID() < videoList[i].GetID()) {
                smallestIndex = k;
            } //if
        } //for
    tmp = videoList[i];
    videoList[i] = videoList[smallestIndex];
    videoList[smallestIndex] = tmp;
    } //for
}

void RentedVideoList::SortByCustomerID() {
    RentedVideo tmp;
    int smallestIndex;
    for(int i = 0; i < length - 1; i++) {
        smallestIndex = i;
        for(int k = i + 1; k < length; k++) {
            if(videoList[k].GetCustomer().GetID() < videoList[i].GetCustomer().GetID()) {
                smallestIndex = k;
            } //if
        } //for
    tmp = videoList[i];
    videoList[i] = videoList[smallestIndex];
    videoList[smallestIndex] = tmp;
    } //for
}

void RentedVideoList::AddVideo(RentedVideo item) {
    if(!IsFull()) {
        videoList[length] = item;
        length++;
    }else {
        std::cout << "The video list is full. Your request to add a video has been denied.";
    }
}

void RentedVideoList::RemoveVideo(RentedVideo item) {
    if(!IsEmpty()) {
        for(int i = 0; i < length; i++) {
            if(IsSame(videoList[i], item)) {
                videoList[i] = videoList[length-1];
                length--;
                continue;
            } //if
        } //for
    }else {
        std::cout << "The video list is empty. Your request to remove a video has been denied.";
    }
}

bool RentedVideoList::IsFull() const {
    if(length == 500) {
        return true;
    }else {
        return false;
    }
    return false;
}

bool RentedVideoList::IsEmpty() const {
    if(length < 1) {
        return true;
    }else {
        return false;
    }
    return false;
}

bool RentedVideoList::IsPresent(RentedVideo item) const {
    for(int i = 0; i < length; i++) {
        if(IsSame(videoList[i], item)) {
            return true;
        }
    }
    return false;
}

void RentedVideoList::PrintList() const {
    for(int i = 0; i < length; i++) {
        videoList[i].PrintInfo();
        std::cout << std::endl;
    }
}

bool RentedVideoList::IsSame(RentedVideo vid1, RentedVideo vid2) const {
    if(vid1.GetID() == vid2.GetID() && vid1.GetTitle() == vid2.GetTitle() && vid1.GetCustomer().GetAge() == vid1.GetCustomer().GetAge() && vid1.GetCustomer().GetID() == vid1.GetCustomer().GetID() && vid1.GetCustomer().GetName() == vid1.GetCustomer().GetName()) {
        return true;
    }
    return false;
}

void RentedVideoList::InputFromFile() {
    std::ifstream input;
    std::string title;
    int id;
    input.open("rentedlist_i.dat");
    for(int i = 0; i < length; i++) {
        input >> title >> id;
        videoList[i].SetTitle(title);
        videoList[i].SetID(id);
        if(!input) {
            continue;
        }
    }
    input.close();
}

void RentedVideoList::OutputToFile() const {
    std::ofstream output;
    output.open("rentedlist_o.dat");
    for(int i = 0; i < length; i++) {
        output << videoList[i].GetTitle() << " " << videoList[i].GetID();
        if(i != length - 1) {
            output << std::endl;
        }
    }
    output.close();
}

