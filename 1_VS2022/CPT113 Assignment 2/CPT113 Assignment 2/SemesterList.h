#pragma once
#ifndef SEMESTERLIST_H
#define SEMESTERLIST_H
#include "CourseList.h"

using namespace std;

class CourseList;

//A list of semesters of a student
class SemesterList
{
private:
    //Each semester node has its own linked list of courses
    struct SemesterNode
    {
        string time;

        //Composition
        CourseList courseTaken;

        SemesterNode* next;
    };

    SemesterNode* head;
public:

    // Constructor
    SemesterList();

    // Destructor
    ~SemesterList();

    //To read the semesters of each student from text file
    void readSem(string sem);

    //To display all the semesters of each student from the linked lists
    void displaySem(int& key);

    //To display specific semester
    void displaySpecificSem(string sem);

    //To pass the information of courses to the readCourses function
    void passCourseInfo(string courseInfo, string semesterInfo);

    //To display the information of courses by calling the function displayCourses
    void displayCourseInfoList(string semesterInfo);

    // To modify and get a correct calculation and modify the cgpa based on the semester's results
    void editCourseInfoList(string semesterInfo, float& tgpa);

    //To pass the information of specific courses of a student to be deleted
    void passDeleteCourseInfo(string semesterInfo, string courseCode);

    //To remove all semesters of a student
    void removeAllSemesters();

    //To write the information of all the semesters of a student into a text file
    void writeSemIntoFile(ofstream& outputFile);
};

#endif
