#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <cctype>
#include "StudentList.h"

using namespace std;

StudentList::StudentList()
{
    head = nullptr;
}

StudentList::~StudentList()
{
    StudentNode* nodePtr = nullptr;
    StudentNode* nextNode = nullptr;
    nodePtr = head;
    while (nodePtr != nullptr)
    {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

void StudentList::readMatricNum(int info)
{
    StudentNode* nodePtr = nullptr;
    StudentNode* newNode;

    newNode = new StudentNode;
    newNode->matricNum = info;
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

void StudentList::insertMatricNum(int num)
{
    StudentNode* nodePtr = nullptr;
    StudentNode* trailNode = nullptr;
    StudentNode* newNode;

    newNode = new StudentNode;
    newNode->matricNum = num;
    newNode->next = nullptr;

    if (!head) {
        head = newNode;
    }
    else {
        nodePtr = head;
        while (nodePtr != nullptr && nodePtr->matricNum < num) {
            trailNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        if (trailNode == nullptr) {
            head = newNode;
            newNode->next = nodePtr;
        }
        else {
            trailNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}

void StudentList::passPersonalInfo(string info, int num)
{
    StudentNode* nodePtr = head;

    if (!head)
    {
        cout << "There is no matching matric number." << endl;
    }
    else if (head->matricNum == num)
    {
        nodePtr->personalInfo.readInfo(info);
    }
    else
    {
        while (nodePtr != nullptr && nodePtr->matricNum != num)
        {
            nodePtr = nodePtr->next;
        }
        if (nodePtr)
        {
            nodePtr->personalInfo.readInfo(info);
        }
        else
        {
            cout << "There is no matching matric number." << endl;
        }
    }
}

void StudentList::passStudentSem(string sem, int num)
{
    StudentNode* nodePtr = head;
    if (head->matricNum == num)
    {
        nodePtr->semesterTaken.readSem(sem);

    }
    else
    {
        while (nodePtr != nullptr && nodePtr->matricNum != num)
        {
            nodePtr = nodePtr->next;
        }
        if (nodePtr)
        {
            nodePtr->semesterTaken.readSem(sem);
        }
    }
}

void StudentList::passStudentCourse(string course, string semester, int num)
{
    StudentNode* nodePtr = head;

    if (head->matricNum == num)
    {
        nodePtr->semesterTaken.passCourseInfo(course, semester);
    }
    else
    {
        while (nodePtr != nullptr && nodePtr->matricNum != num)
        {
            nodePtr = nodePtr->next;
        }
        if (nodePtr)
        {
            nodePtr->semesterTaken.passCourseInfo(course, semester);
        }
        else
        {
            cout << "There is no matching matric number." << endl;
        }
    }
}

void StudentList::displayStudentList()
{
    StudentNode* nodePtr = nullptr;
    if (!head)
    {
        cout << "There is nothing to display" << endl;
    }
    else
    {
        nodePtr = head;
        while (nodePtr != nullptr)
        {
            cout << nodePtr->matricNum << '\t';
            nodePtr = nodePtr->next;
        }
    }
}

void StudentList::displayPersonalInfoList(int num)
{
    StudentNode* nodePtr = head;

    if (head->matricNum == num)
    {
        nodePtr->personalInfo.displayInfo();
    }
    else
    {
        while (nodePtr != nullptr && nodePtr->matricNum != num)
        {
            nodePtr = nodePtr->next;
        }
        if (nodePtr)
        {
            nodePtr->personalInfo.displayInfo();
        }
        else
        {
            cout << "There is no information of this student." << endl;
        }
    }
}

void StudentList::obtainSemester(int num, int& key)
{
    StudentNode* nodePtr = head;

    if (head->matricNum == num)
    {
        nodePtr->semesterTaken.displaySem(key);
    }
    else
    {
        while (nodePtr != nullptr && nodePtr->matricNum != num)
        {
            nodePtr = nodePtr->next;

        }
        if (nodePtr)
        {
            nodePtr->semesterTaken.displaySem(key);
        }
    }
}

void StudentList::displayCourseList(int num, string sem)
{
    StudentNode* nodePtr = head;

    if (head->matricNum == num)
    {
        nodePtr->semesterTaken.displayCourseInfoList(sem);

    }
    else
    {
        while (nodePtr != nullptr && nodePtr->matricNum != num)
        {
            nodePtr = nodePtr->next;
        }
        if (nodePtr)
        {
            nodePtr->semesterTaken.displayCourseInfoList(sem);
        }
    }
}

void StudentList::editCourseList(int num, string sem, float& tgpa)
{
    StudentNode* nodePtr = head;
    if (head->matricNum == num)
    {
        nodePtr->semesterTaken.editCourseInfoList(sem, tgpa);
    }
    else
    {
        while (nodePtr != nullptr && nodePtr->matricNum != num)
        {
            nodePtr = nodePtr->next;
        }
        if (nodePtr)
        {
            nodePtr->semesterTaken.editCourseInfoList(sem, tgpa);
        }
    }
}

void StudentList::displayEverything(int num, string sem)
{
    StudentNode* nodePtr = nullptr;
    if (!head)
    {
        cout << "There is nothing to display." << endl;
    }
    else
    {
        nodePtr = head;
        if (head->matricNum == num)
        {
            nodePtr->semesterTaken.displaySpecificSem(sem);
            nodePtr->semesterTaken.displayCourseInfoList(sem);
        }
        else
        {
            while (nodePtr != nullptr && nodePtr->matricNum != num)
            {
                nodePtr = nodePtr->next;
            }
            if (nodePtr)
            {
                nodePtr->semesterTaken.displaySpecificSem(sem);
                nodePtr->semesterTaken.displayCourseInfoList(sem);
            }
            else
            {
                cout << "There is no information of this student." << endl;
            }
        }
    }
}

bool StudentList::validateMatricNum(int num)
{
    StudentNode* nodePtr = head;

    if (!head)
    {
        return false;
    }
    else if (head->matricNum == num)
    {
        return true;
    }
    else
    {
        while (nodePtr != nullptr && nodePtr->matricNum != num)
        {
            nodePtr = nodePtr->next;
        }
        if (nodePtr)
        {
            return true;
        }
    }
    return false;
}

void StudentList::passDeleteCourseData(int num, string semester, string course)
{
    StudentNode* nodePtr = head;

    if (!head)
    {
        cout << "Error passing course data." << endl;
    }
    else if (head->matricNum == num)
    {
        nodePtr->semesterTaken.passDeleteCourseInfo(semester, course);
    }
    else
    {
        while (nodePtr != nullptr && nodePtr->matricNum != num)
        {
            nodePtr = nodePtr->next;
        }
        if (nodePtr)
        {
            nodePtr->semesterTaken.passDeleteCourseInfo(semester, course);
        }
        else
        {
            cout << "No matching matric number." << endl;
        }
    }
}

void StudentList::removeStudent(int num)
{
    StudentNode* nodePtr = nullptr;
    StudentNode* previousNode = nullptr;

    nodePtr = head;
    if (!head)
    {
        cout << "There is no student with matching matric number to remove." << endl;
    }
    else if (head->matricNum == num)
    {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
        cout << "You have successfully dropped out from the School of Computer Science of USM." << endl;
    }
    else
    {
        while (nodePtr != nullptr && nodePtr->matricNum != num)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        if (nodePtr)
        {
            nodePtr->personalInfo.removeAllPersonalInfo();
            nodePtr->semesterTaken.removeAllSemesters();
            previousNode->next = nodePtr->next;
            delete nodePtr;
            cout << "You have successfully dropped out from the School of Computer Science of USM." << endl;
        }
        else
        {
            cout << "There is no student with matching matric number to remove." << endl;
        }
    }
}

void StudentList::readCgpa(int num, double cgpaVal)
{
    StudentNode* nodePtr = nullptr;

    if (!head)
    {
        cout << "There is no information of any student in the system currently." << endl;
    }
    else if (head->matricNum == num)
    {
        head->cgpa = cgpaVal;
    }
    else
    {
        nodePtr = head;
        while (nodePtr != nullptr && nodePtr->matricNum != num)
        {
            nodePtr = nodePtr->next;
        }
        if (nodePtr)
        {
            nodePtr->cgpa = cgpaVal;
        }
        else
        {
            cout << "There is no matching matric number of student." << endl;
        }
    }
}

void StudentList::displayCgpa(int num)
{
    StudentNode* nodePtr = nullptr;

    if (!head)
    {
        cout << "There is no information of any student in the system currently." << endl;
    }
    else if (head->matricNum == num)
    {
        cout << setprecision(2) << fixed << "CGPA until latest semester: " << head->cgpa << endl;
    }
    else
    {
        nodePtr = head;
        while (nodePtr != nullptr && nodePtr->matricNum != num)
        {
            nodePtr = nodePtr->next;
        }
        if (nodePtr)
        {
            cout << setprecision(2) << fixed << "CGPA until latest semester: " << nodePtr->cgpa << endl;
        }
        else
        {
            cout << "There is no matching matric number of student." << endl;
        }
    }
}

void StudentList::calcCgpa(int num, int sem, float gpa)
{
    float cumCgpa;
    StudentNode* nodePtr = nullptr;

    if (!head)
    {
        cout << "There is no information of any student in the system currently." << endl;
    }
    else if (head->matricNum == num)
    {
        cumCgpa = (gpa)+(head->cgpa) * (sem - 1);
        cumCgpa = cumCgpa / sem;
        head->cgpa = cumCgpa;
    }
    else
    {
        nodePtr = head;
        while (nodePtr != nullptr && nodePtr->matricNum != num)
        {
            nodePtr = nodePtr->next;
        }
        if (nodePtr) {
            cumCgpa = (gpa)+(nodePtr->cgpa) * (sem - 1);
            cumCgpa = cumCgpa / sem;
            nodePtr->cgpa = cumCgpa;
        }
        else
        {
            cout << "There is no matching matric number of student." << endl;
        }
    }
}

void StudentList::writeAllIntoFile(ofstream& outputFile)
{
    StudentNode* nodePtr = nullptr;
    if (!head)
    {
        return;
    }
    else
    {
        nodePtr = head;
        while (nodePtr != nullptr)
        {
            outputFile << nodePtr->matricNum << '\t';
            nodePtr->personalInfo.writePersonalInfoIntoFile(outputFile);
            nodePtr->semesterTaken.writeSemIntoFile(outputFile);
            outputFile << "CGPA" << '\n' << setprecision(2) << fixed << nodePtr->cgpa;
            nodePtr = nodePtr->next;
            if (nodePtr != nullptr)
            {
                outputFile << '\n';
            }
        }
    }
}