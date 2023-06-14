#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <cctype>
#include "SemesterList.h"

using namespace std;

SemesterList::SemesterList()
{
    head = nullptr;
}

// Destructor
SemesterList::~SemesterList()
{
    SemesterNode* nodePtr = nullptr;
    SemesterNode* nextNode = nullptr;
    nodePtr = head;
    while (nodePtr != nullptr)
    {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

void SemesterList::readSem(string sem)
{
    SemesterNode* nodePtr = nullptr;
    SemesterNode* newNode;

    newNode = new SemesterNode;
    newNode->time = sem;
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

void SemesterList::displaySem(int& key)
{
    SemesterNode* nodePtr = nullptr;
    if (!head)
    {
        return;
    }
    else
    {
        nodePtr = head;
        while (nodePtr != nullptr)
        {
            nodePtr = nodePtr->next;

            //HEREEE
            key++;
        }
    }
}

void SemesterList::displaySpecificSem(string sem)
{
    SemesterNode* nodePtr = nullptr;
    if (!head)
    {
        cout << "There is nothing to display." << endl;
    }
    else
    {
        nodePtr = head;
        if (head->time == sem)
        {
            cout << "Semester: " << nodePtr->time << endl;
        }
        else
        {
            while (nodePtr != nullptr && nodePtr->time != sem)
            {
                nodePtr = nodePtr->next;
            }
            if (nodePtr)
            {
                cout << "Semester: " << nodePtr->time << endl;
            }
        }
    }
}

void SemesterList::passCourseInfo(string courseInfo, string semesterInfo)
{
    SemesterNode* nodePtr = head;

    while (nodePtr != nullptr && nodePtr->time != semesterInfo)
    {
        nodePtr = nodePtr->next;
    }
    if (nodePtr)
    {
        nodePtr->courseTaken.readCourses(courseInfo);
    }
}

void SemesterList::displayCourseInfoList(string semesterInfo)
{
    SemesterNode* nodePtr = head;

    if (head->time == semesterInfo)
    {
        nodePtr->courseTaken.displayCourses();

    }
    else
    {
        while (nodePtr != nullptr && nodePtr->time != semesterInfo)
        {
            nodePtr = nodePtr->next;
        }
        if (nodePtr)
        {
            nodePtr->courseTaken.displayCourses();
        }
    }
}

void SemesterList::editCourseInfoList(string semesterInfo, float& tgpa)
{
    SemesterNode* nodePtr = head;

    if (head->time == semesterInfo)
    {
        nodePtr->courseTaken.editGrade(tgpa);

    }
    else
    {
        while (nodePtr != nullptr && nodePtr->time != semesterInfo)
        {
            nodePtr = nodePtr->next;
        }
        if (nodePtr)
        {
            nodePtr->courseTaken.editGrade(tgpa);
        }
    }
}

void SemesterList::passDeleteCourseInfo(string semesterInfo, string courseCode)
{
    SemesterNode* nodePtr = head;

    if (head->time == semesterInfo)
    {
        nodePtr->courseTaken.deleteCourse(courseCode);
    }
    else
    {
        while (nodePtr != nullptr && nodePtr->time != semesterInfo)
        {
            nodePtr = nodePtr->next;
        }
        if (nodePtr)
        {
            nodePtr->courseTaken.deleteCourse(courseCode);
        }
        else
        {
            cout << "No information about the semester." << endl;
        }
    }
}

void SemesterList::removeAllSemesters()
{
    SemesterNode* nodePtr = nullptr;
    SemesterNode* nextNode = nullptr;
    if (!head)
    {
        cout << "There is no semester to delete." << endl;
    }
    else
    {
        nodePtr = head;
        while (nodePtr != nullptr)
        {
            nodePtr->courseTaken.removeAllCourses();
            nextNode = nodePtr->next;
            delete nodePtr;
            nodePtr = nextNode;
            head = nodePtr;
        }
    }
}

void SemesterList::writeSemIntoFile(ofstream& outputFile)
{
    SemesterNode* nodePtr = nullptr;
    if (!head)
    {
        return;
    }
    else
    {
        nodePtr = head;
        while (nodePtr != nullptr)
        {
            outputFile << nodePtr->time << '\n';
            nodePtr->courseTaken.writeCourseIntoFile(outputFile);
            nodePtr = nodePtr->next;
        }
    }
}
