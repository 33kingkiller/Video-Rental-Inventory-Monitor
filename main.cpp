#include <iostream>
#include "rentvidlist.h"
#include "videolist.h"

using namespace std;

int main() {
    VideoList returnedList;
    RentedVideoList rentedList;
    char input;
    bool terminate = false;
    do{
        cout << "Monitor initialized. What would you like to do regarding the inventory?\n";
        cout << "Enter '0' to monitor/modify the \"Returned List\" or '1' to monitor/modify the\n\"Rented List.\"";
        cout << "Anything else will exit the program.\n";
        cin >> input;
        if(input == '0') {
            cout << "Now monitoring the \"Returned List.\" What would you like to do?\n";
            cout << "Enter '0' to input the list from file \"returnedlist_i.dat,\" '1' to output\nthe list to \"returnedlist_o.dat,\" '2' to sort the list by ID,\n";
            cout << "'3' to add a video to the list, '4' to remove a video from the list, or '5' to\n";
            cout << "print the list to the window. Anything else will exit the program.\n";
            cin >> input;
            switch(input) {
                case '0':
                    int length;
                    cout << "Ready to input from file. Enter the length of the list (from 1 to 500).\n";
                    cin >> length;
                    returnedList.InputFromFile(length);
                    cout << "List now received from file \"returnedlist_i.dat.\" If the list is still\n";
                    cout << "empty, chances are that there was no file named \"returnedlist_i.dat.\"\n";
                    break;
                case '1':
                    cout << "Outputting list to file \"returnedlist_o.dat\"...\n";
                    returnedList.OutputToFile();
                    cout << "Done.\n";
                    break;
                case '2':
                    cout << "Now sorting the list by ID...\n";
                    returnedList.SortByID();
                    cout << "Done.\n";
                    break;
                case '3':{
                    string title;
                    int id;
                    cout << "Ready to add a video to the list. Enter the video's title (use '_' for spaces).\n";
                    cin.ignore(1, '\n');
                    getline(cin, title);
                    cout << "Title processed. Enter the video's ID.\n";
                    cin >> id;
                    cout << "ID processed. Adding video...\n";
                    if(!returnedList.IsFull()) {
                        Video newVideo(title, id);
                        returnedList.AddVideo(newVideo);
                        cout << "Done.\n";
                    }else {
                        cout << "ERROR: Could not add video. The list is full.\n";
                    }
                    break;
                }
                case '4':{
                    int id;
                    cout << "Ready to remove video from the list. Enter the video's ID.\n";
                    cin >> id;
                    cout << "Now searching for video...\n";
                    int index;
                    Video videoList[500];
                    returnedList.GetArray(videoList);
                    if(!returnedList.IsEmpty()) {
                        bool found = false;
                        for(int i = 0; i < returnedList.GetLength(); i++) {
                            if(videoList[i].GetID() == id) {
                                index = i;
                                found = true;
                            }
                        }
                        if(!found) {
                            cout << "ERROR: Could not find video. The video is not in the list.\n";
                        }else {
                            cout << "Video found. Now removing...\n";
                            returnedList.RemoveVideo(videoList[index]);
                            cout << "Done.\n";
                        }
                    }else {
                        cout << "ERROR: Could not remove video. The list is empty.\n";
                    }
                    break;
                }
                case '5':
                    cout << "Printing list...\n\n";
                    returnedList.PrintList();
                    cout << "\nDone.\n";
                    break;
                default:
                    cout << "\nExiting program...\n\n";
                    terminate = true;
            }
        }else if(input == '1') {
            cout << "Now monitoring the \"Rented List.\" What would you like to do?\n";
            cout << "Enter '0' to input the list from file \"rentedlist_i.dat,\" '1' to output\nthe list to \"rentedlist_o.dat,\" '2' to sort the list by ID,\n";
            cout << "'3' to add a video to the list, '4' to remove a video from the list, or '5' to\n";
            cout << "print the list to the window. Anything else will exit the program.\n";
            cin >> input;
            switch(input) {
                case '0':
                    int length;
                    cout << "Ready to input from file. Enter the length of the list (from 1 to 500).\n";
                    cin >> length;
                    rentedList.InputFromFile(length);
                    cout << "List now received from file \"rentedlist_i.dat.\" If the list is still\n";
                    cout << "empty, chances are that there was no file named \"rentedlist_i.dat.\"\n";
                    break;
                case '1':
                    cout << "Outputting list to file \"rentedlist_o.dat\"...\n";
                    rentedList.OutputToFile();
                    cout << "Done.\n";
                    break;
                case '2':
                    cout << "Now sorting the list by ID...\n";
                    rentedList.SortByID();
                    cout << "Done.\n";
                    break;
                case '3':{
                    string title;
                    string customerName;
                    int id;
                    int customerAge;
                    int customerID;
                    cout << "Ready to add a video to the list. Enter the video's title (use '_' for spaces).\n";
                    cin.ignore(1, '\n');
                    getline(cin, title);
                    cout << "Title processed. Enter the video's ID.\n";
                    cin >> id;
                    cout << "ID processed. Enter the customer's name (format: \"last,first\").\n";
                    cin >> customerName;
                    cout << "Customer name processed. Enter the customer's age.\n";
                    cin >> customerAge;
                    cout << "Customer age processed. Enter the customer's ID.\n";
                    cin >> customerID;
                    cout << "Customer ID processed. Now adding video...\n";
                    if(!rentedList.IsFull()) {
                        CustomerInfo newCustomer(customerName, customerID, customerAge);
                        RentedVideo newVideo(title, id, newCustomer);
                        rentedList.AddVideo(newVideo);
                        cout << "Done.\n";
                    }else {
                        cout << "ERROR: Could not add video. The list is full.\n";
                    }
                    break;
                }
                case '4':{
                    int id;
                    cout << "Ready to remove video from the list. Enter the video's ID.\n";
                    cin >> id;
                    cout << "Now searching for video...\n";
                    int index;
                    RentedVideo videoList[500];
                    rentedList.GetArray(videoList);
                    if(!rentedList.IsEmpty()) {
                        bool found = false;
                        for(int i = 0; i < rentedList.GetLength(); i++) {
                            if(videoList[i].GetID() == id) {
                                index = i;
                                found = true;
                            }
                        }
                        if(!found) {
                            cout << "ERROR: Could not find video. The video is not in the list.\n";
                        }else {
                            cout << "Video found. Now removing...\n";
                            rentedList.RemoveVideo(videoList[index]);
                            cout << "Done.\n";
                        }
                    }else {
                        cout << "ERROR: Could not remove video. The list is empty.\n";
                    }
                    break;
                }
                case '5':
                    cout << "Printing list...\n\n";
                    rentedList.PrintList();
                    cout << "\nDone.\n";
                    break;
                default:
                    cout << "\nExiting program...\n\n";
                    terminate = true;
            }
        }else {
            cout << "\nExiting program...\n\n";
            terminate = true;
        }
    }while(!terminate);
    cout << "\nProgram terminating with status \"NO_ERROR.\" Push ENTER to continue.\n";
    cin.ignore(1, '\n');
    cin.get();
    return 0;
}
