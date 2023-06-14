#pragma once
#ifndef STUDENTLIST_H
#define STUDENTLIST_H
#include "PersonalInfoList.h"
#include "SemesterList.h"
using namespace std;

class PersonalInfoList;
class SemesterList;

//A list students differentiated by their matric numbers
class StudentList
{
private:
    //Each student node has its own linked lists of semesters and personal information
    struct StudentNode {
        int matricNum;
        double cgpa;

        //Composition
        SemesterList semesterTaken;
        PersonalInfoList personalInfo;

        StudentNode* next;
    };

    StudentNode* head;

public:
    // Constructor
    StudentList();

    // Destructor
    ~StudentList();

    //Read the matric number of each student into a linked list from the text file
    void readMatricNum(int info);

    //insert matric num 
    void insertMatricNum(int num);

    //Pass the personal information of each student to the readInfo function
    void passPersonalInfo(string info, int num);

    //Pass the semesters of each student to the readSem function
    void passStudentSem(string sem, int num);

    //Pass the courses of each student to the passCourseInfo function
    void passStudentCourse(string course, string semester, int num);

    //Display matric number of every student from the linked list
    void displayStudentList();

    //Display all the personal information of student according to the matric number of that student
    void displayPersonalInfoList(int num);

    //Call the displaySem function according to the matric number of a student
    void obtainSemester(int num, int& key);

    //Call the displayCourseInfoList function according to the matric number of a student
    void displayCourseList(int num, string sem);

    //Call the editCourseInfoList function according to the matric number of the student
    void editCourseList(int num, string sem, float& tgpa);

    //Display all the semesters and courses that a student takes accordingly
    void displayEverything(int num, string sem);

    //To validate the existence of a matric number in the linked list of StudentList
    bool validateMatricNum(int num);

    //To pass the information of specific courses of a student to be deleted
    void passDeleteCourseData(int num, string semester, string course);

    //To remove a student entirely from the student linked list according to matric number
    void removeStudent(int num);

    void readCgpa(int num, double cgpaVal);

    //Display the CGPA of a particular student
    void displayCgpa(int num);

    //Calculate the CGPA of a particular student
    void calcCgpa(int num, int sem, float gpa);

    //To write all the information of linked list into the text file
    void writeAllIntoFile(ofstream& outputFile);
};

#endif