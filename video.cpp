#include "video.h"
#include <iostream>
#include <string>

Video::Video(std::string ttl, int iD) {
    title = ttl;
    id = iD;
}

Video::Video() {
    title = "UNDEFINED";
    id = -1;
}

void Video::SetTitle(std::string ttl) {
    title = ttl;
}

void Video::SetID(int iD) {
    id = iD;
}

std::string Video::GetTitle() const {
    return title;
}

int Video::GetID() const {
    return id;
}

void Video::PrintInfo() const {
    std::cout << "TITLE: " << title << ", ID: " << id;
}
