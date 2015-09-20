#ifndef VIDEO_H
#define VIDEO_H

#include <string>

class Video {
    public:
        Video(std::string title, int id);
        Video();
        void SetTitle(std::string title);
        void SetID(int id);
        std::string GetTitle() const;
        int GetID() const;
        void PrintInfo() const;
    private:
        std::string title;
        int id;
};
#endif // VIDEO_H
