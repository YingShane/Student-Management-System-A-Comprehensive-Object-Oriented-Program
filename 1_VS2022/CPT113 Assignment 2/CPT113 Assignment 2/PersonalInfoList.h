#pragma once
#ifndef PERSONALINFOLIST_H
#define PERSONALINFOLIST_H
using namespace std;

//A list of personal information of a student
class PersonalInfoList
{
private:
    struct PersonalInfoNode
    {
        string personalInfo;
        PersonalInfoNode* next;
    };

    PersonalInfoNode* head;

public:
    //Constructor
    PersonalInfoList();

    //Destructor
    ~PersonalInfoList();

    //To read and append the personal information of each student into a linked list from the text file
    void readInfo(string info);

    //To display the personal information of each student
    void displayInfo();

    //To remove all personal informations of a student
    void removeAllPersonalInfo();

    //To write all the personal information of a student into a text file
    void writePersonalInfoIntoFile(ofstream& outputFile);
};

#endif