#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <cctype>
#include "CourseList.h"

using namespace std;

CourseList::CourseList()
{
    gpa = 0.00;
    head = nullptr;
}

CourseList::~CourseList()
{
    CourseNode* nodePtr = nullptr;
    CourseNode* nextNode = nullptr;
    nodePtr = head;
    while (nodePtr != nullptr)
    {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

void CourseList::readCourses(string courseInfo)
{
    CourseNode* nodePtr = nullptr;
    CourseNode* newNode;
    newNode = new CourseNode;
    newNode->course = courseInfo;
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

void CourseList::displayCourses()
{
    CourseNode* nodePtr = nullptr;
    if (!head)
    {
        cout << "There is nothing to display." << endl;
    }
    else
    {
        string courseInfoArr[4] = { " => ", "Number of units: ", "Type of course: ", "Grade obtained: " };
        cout << "Courses taken: " << endl;
        int courseCnt = 0;
        nodePtr = head;
        while (nodePtr != nullptr)
        {
            if (courseCnt == 0)
            {
                cout << nodePtr->course << courseInfoArr[courseCnt] << "\n";
                nodePtr = nodePtr->next;
                courseCnt++;
            }
            else
            {
                cout << courseInfoArr[courseCnt] << nodePtr->course << '\n';
                nodePtr = nodePtr->next;
                courseCnt++;
                if (courseCnt == 4)
                {
                    cout << "\n";
                    courseCnt = 0;
                }
            }
        }
    }
}

void CourseList::editGrade(float& tgpa)
{
    int courseNo = 0;
    int courseCnt = 0;
    string* arrGrade;
    int* arrCred;
    CourseNode* nodePtr = nullptr;
    if (!head)
    {
        cout << "There is nothing to display." << endl;
    }
    else
    {
        string courseInfoArr[4] = { " => ", "Number of units: ", "Type of course: ", "Grade obtained: " };
        cout << "Courses taken: " << endl;

        nodePtr = head;
        while (nodePtr != nullptr)
        {
            if (courseCnt == 0)
            {
                cout << nodePtr->course << courseInfoArr[courseCnt] << "\n";
                nodePtr = nodePtr->next;
                courseCnt++;
            }
            else
            {
                if (courseCnt == 3) {
                    bool logic = false;
                    string thing;
                    while (logic == false) {
                        cout << "Please enter your grade for this course, the grade must be capitalised (Be honest): ";
                        cin >> thing;
                        if (thing == "A" || thing == "A-" || thing == "B+" || thing == "B" || thing == "B-" || thing == "C+" || thing == "C" || thing == "C-" || thing == "D+" || thing == "D" || thing == "D-" || thing == "F") {
                            logic = true;
                        }
                        else {
                            cout << "Invalid grade!" << endl;
                        }
                    }
                    nodePtr->course = thing;
                    cout << courseInfoArr[courseCnt] << nodePtr->course << '\n';
                    nodePtr = nodePtr->next;
                    courseCnt++;
                }
                else if (courseCnt == 1 || courseCnt == 2) {
                    cout << courseInfoArr[courseCnt] << nodePtr->course << '\n';
                    nodePtr = nodePtr->next;
                    courseCnt++;
                }
                else if (courseCnt == 4)
                {
                    cout << "\n";
                    courseCnt = 0;
                    courseNo++;
                }
            }
        }
    }
    courseNo++;
    arrGrade = new string[courseNo];
    arrCred = new int[courseNo];
    courseCnt = 0;
    nodePtr = head;
    int i = 0;
    while (nodePtr != nullptr) {

        if (courseCnt % 4 == 1) {
            arrCred[i] = stoi(nodePtr->course);
        }
        if (courseCnt % 4 == 3) {
            arrGrade[i] = nodePtr->course;
            i++;
        }
        nodePtr = nodePtr->next;
        courseCnt++;
    }
    nodePtr = nullptr;
    tgpa = calculateGPA(arrGrade, arrCred, courseNo);
}

float CourseList::calculateGPA(string grades[], int credits[], int courseNo)
{
    int totcred = 0;
    float gpa = 0.00;
    for (int i = 0; i < courseNo; i++) {
        totcred += credits[i];
    }
    for (int i = 0; i < courseNo; i++) {
        if (grades[i] == "A") {
            gpa += 4.00 * credits[i] / totcred;
        }
        else if (grades[i] == "A-") {
            gpa += 3.67 * credits[i] / totcred;
        }
        else if (grades[i] == "B+") {
            gpa += 3.33 * credits[i] / totcred;
        }
        else if (grades[i] == "B") {
            gpa += 3.00 * credits[i] / totcred;
        }
        else if (grades[i] == "B-") {
            gpa += 2.67 * credits[i] / totcred;
        }
        else if (grades[i] == "C+") {
            gpa += 2.33 * credits[i] / totcred;
        }
        else if (grades[i] == "C") {
            gpa += 2.00 * credits[i] / totcred;
        }
        else if (grades[i] == "C-") {
            gpa += 1.67 * credits[i] / totcred;
        }
        else if (grades[i] == "D+") {
            gpa += 1.33 * credits[i] / totcred;
        }
        else if (grades[i] == "D") {
            gpa += 1.00 * credits[i] / totcred;
        }
        else if (grades[i] == "D-") {
            gpa += 0.67 * credits[i] / totcred;
        }
        else if (grades[i] == "F") {
            gpa += 0.00 * credits[i] / totcred;
        }
    }
    cout << "\n***************************************************************************************" << endl << endl;
    cout << "Your GPA for this semester: " << setprecision(2) << fixed << gpa << endl;
    return gpa;
}

void CourseList::deleteCourse(string courseCode)
{
    CourseNode* nodePtr = nullptr;
    CourseNode* previousNode = nullptr;

    if (!head)
    {
        cout << "You cannot drop this course as you have not taken it before." << endl;
    }
    else if (head->course == courseCode)
    {
        for (int i = 0; i < 4; i++)
        {
            nodePtr = head->next;
            delete head;
            head = nodePtr;
        }
        cout << "Course successfully deleted." << endl;
    }
    else
    {
        nodePtr = head;
        while (nodePtr != nullptr && nodePtr->course != courseCode)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        if (nodePtr)
        {
            for (int i = 0; i < 4; i++)
            {
                previousNode->next = nodePtr->next;
                delete nodePtr;
                nodePtr = previousNode->next;
            }
            cout << "Course successfully deleted." << endl;
        }
        else
        {
            cout << "No matching course code. Please only enter the course that you wish to drop in your latest semester." << endl;
        }
    }
}

void CourseList::removeAllCourses()
{
    CourseNode* nodePtr = nullptr;
    CourseNode* nextNode = nullptr;

    if (!head)
    {
        cout << "There is no course to delete" << endl;
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

void CourseList::calcArrSize(int& arrSize)
{
    CourseNode* nodePtr = nullptr;
    int cnt = 0;

    if (!head)
    {
        cout << "There is no information here." << endl;
    }
    else
    {
        nodePtr = head;
        while (nodePtr != nullptr)
        {
            cnt++;
            if (cnt == 1)
            {
                arrSize++;
            }
            else if (cnt == 4)
            {
                cnt = 0;
            }
            nodePtr = nodePtr->next;
        }
    }
}

void CourseList::writeCourseIntoFile(ofstream& outputFile)
{
    int arrSize = 0, arrCnt = 0, order = 0;
    calcArrSize(arrSize);

    string* courseCode = new string[arrSize];
    string* courseUnit = new string[arrSize];
    string* courseType = new string[arrSize];
    string* courseGrade = new string[arrSize];

    CourseNode* nodePtr = nullptr;

    if (!head)
    {
        return;
    }
    else
    {
        nodePtr = head;
        while (nodePtr != nullptr)
        {
            if (order == 0)
            {
                courseCode[arrCnt] = nodePtr->course;
                order++;
            }
            else if (order == 1)
            {
                courseUnit[arrCnt] = nodePtr->course;
                order++;
            }
            else if (order == 2)
            {
                courseType[arrCnt] = nodePtr->course;
                order++;
            }
            else if (order == 3)
            {
                courseGrade[arrCnt] = nodePtr->course;
                order++;
            }
            if (order == 4)
            {
                order = 0;
                arrCnt++;
            }
            nodePtr = nodePtr->next;
        }
    }

    int checkNum = 0;
    for (int i = 0; i < arrSize; i++)
    {
        if (checkNum == arrSize - 1)
        {
            outputFile << courseCode[i] << '\n';
        }
        else
        {
            outputFile << courseCode[i] << '\t';
            checkNum++;
        }
    }
    checkNum = 0;
    for (int i = 0; i < arrSize; i++)
    {
        if (checkNum == arrSize - 1)
        {
            outputFile << courseUnit[i] << '\n';
        }
        else
        {
            outputFile << courseUnit[i] << '\t';
            checkNum++;
        }
    }
    checkNum = 0;
    for (int i = 0; i < arrSize; i++)
    {
        if (checkNum == arrSize - 1)
        {
            outputFile << courseType[i] << '\n';
        }
        else
        {
            outputFile << courseType[i] << '\t';
            checkNum++;
        }
    }
    checkNum = 0;
    for (int i = 0; i < arrSize; i++)
    {
        if (checkNum == arrSize - 1)
        {
            outputFile << courseGrade[i] << '\n';
        }
        else
        {
            outputFile << courseGrade[i] << '\t';
            checkNum++;
        }
    }
    checkNum = 0;
}

