#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <cctype>
#include "PersonalInfoList.h"

using namespace std;

PersonalInfoList::PersonalInfoList()
{
    head = nullptr;
}

PersonalInfoList::~PersonalInfoList()
{
    PersonalInfoNode* nodePtr = nullptr;
    PersonalInfoNode* nextNode = nullptr;
    nodePtr = head;
    while (nodePtr != nullptr)
    {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

void PersonalInfoList::readInfo(string info)
{
    PersonalInfoNode* nodePtr = nullptr;
    PersonalInfoNode* newNode;

    newNode = new PersonalInfoNode;
    newNode->personalInfo = info;
    newNode->next = nullptr;
    if (!head)
    {
        head = newNode;
    }
    else
    {
        nodePtr = head;
        while (nodePtr->next)
        {
            nodePtr = nodePtr->next;
        }
        nodePtr->next = newNode;
    }
}

void PersonalInfoList::displayInfo()
{
    PersonalInfoNode* nodePtr = nullptr;
    if (!head)
    {
        cout << "There is nothing to display." << endl;
    }
    else
    {
        int personalInfoCnt = 0;
        string personalInfoArr[] = { "Name: ", "IC / Passport: ", "Gender: ", "Email: ", "Address: ", "Country: ", "Birthday: ", "Phone number: " };
        nodePtr = head;
        while (nodePtr != nullptr)
        {
            cout << personalInfoArr[personalInfoCnt] << nodePtr->personalInfo << '\n';
            nodePtr = nodePtr->next;
            personalInfoCnt++;
        }
        cout << endl;
    }
}

void PersonalInfoList::removeAllPersonalInfo()
{
    PersonalInfoNode* nodePtr = nullptr;
    PersonalInfoNode* nextNode = nullptr;
    if (!head)
    {
        cout << "There is no personal information to delete." << endl;
    }
    else
    {
        nodePtr = head;
        while (nodePtr != nullptr)
        {
            nextNode = nodePtr->next;
            delete nodePtr;
            nodePtr = nextNode;
            head = nodePtr;
        }
    }
}

void PersonalInfoList::writePersonalInfoIntoFile(ofstream& outputFile)
{
    PersonalInfoNode* nodePtr = nullptr;
    if (!head)
    {
        cout << "There is no information here." << endl;
    }
    else
    {
        nodePtr = head;
        while (nodePtr != nullptr)
        {
            outputFile << nodePtr->personalInfo;

            nodePtr = nodePtr->next;
            if (nodePtr != nullptr)
            {
                outputFile << '\t';
            }
            else
            {
                outputFile << '\n';
            }
        }
    }
}
