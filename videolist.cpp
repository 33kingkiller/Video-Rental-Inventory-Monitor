#include "videolist.h"
#include <iostream>
#include <fstream>

VideoList::VideoList(const Video vidList[], int lngth) {
    for(int i = 0; i < lngth; i++) {
        videoList[i] = vidList[i];
    }
    length = lngth;
}

VideoList::VideoList(int lngth) {
    length = lngth;
}

VideoList::VideoList() {
    length = 0;
}

void VideoList::SortByID() {
    Video tmp;
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

void VideoList::AddVideo(Video item) {
    if(!IsFull()) {
        videoList[length] = item;
        length++;
    }else {
        std::cout << "The video list is full. Your request to add a video has been denied.";
    }
}

void VideoList::RemoveVideo(Video item) {
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

bool VideoList::IsFull() const {
    if(length == 500) {
        return true;
    }else {
        return false;
    }
    return false;
}

bool VideoList::IsEmpty() const {
    if(length < 1) {
        return true;
    }else {
        return false;
    }
    return false;
}

bool VideoList::IsPresent(Video item) const {
    for(int i = 0; i < length; i++) {
        if(IsSame(videoList[i], item)) {
            return true;
        }
    }
    return false;
}

int VideoList::GetLength() const {
    return length;
}

void VideoList::GetArray(Video vidList[500]) const {
    for(int i = 0; i < length; i++) {
        vidList[i] = videoList[i];
    }
}

void VideoList::PrintList() const {
    for(int i = 0; i < length; i++) {
        videoList[i].PrintInfo();
        std::cout << std::endl;
    }
}

bool VideoList::IsSame(Video vid1, Video vid2) const {
    if(vid1.GetID() == vid2.GetID() && vid1.GetTitle() == vid2.GetTitle()) {
        return true;
    }
    return false;
}

void VideoList::InputFromFile(int lngth) {
    std::ifstream input;
    std::string title;
    int id;
    if(length != lngth) {
        length = lngth;
    }
    input.open("returnedlist_i.dat");
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

void VideoList::OutputToFile() const {
    std::ofstream output;
    output.open("returnedlist_o.dat");
    for(int i = 0; i < length; i++) {
        output << videoList[i].GetTitle() << " " << videoList[i].GetID();
        if(i != length - 1) {
            output << std::endl;
        }
    }
    output.close();
}
