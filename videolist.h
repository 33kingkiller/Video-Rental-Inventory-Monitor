#ifndef VIDEOLIST_H
#define VIDEOLIST_H

#include "video.h"

class VideoList {
    public:
        VideoList(const Video videoList[], int length);
        VideoList(int length);
        VideoList();
        void SortByID();
        void AddVideo(Video video);
        void RemoveVideo(Video video);
        bool IsFull() const;
        bool IsEmpty() const;
        bool IsPresent(Video video) const;
        int GetLength() const;
        void GetArray(Video videoList[500]) const;
        void PrintList() const;
        void InputFromFile(int length);
        void OutputToFile() const;
    private:
        Video videoList[500];
        int length;
        bool IsSame(Video vid1, Video vid2) const;
};
#endif // VIDEOLIST_H
