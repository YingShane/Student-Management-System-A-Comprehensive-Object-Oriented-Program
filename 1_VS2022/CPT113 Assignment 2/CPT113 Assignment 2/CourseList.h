#pragma once
#ifndef COURSELIST_H
#define COURSELIST_H
using namespace std;

//A list of courses according to each semester of a student
class CourseList
{
private:

    struct CourseNode
    {
        string course;
        CourseNode* next;
    };

    float gpa;
    CourseNode* head;

public:

    // Constructor
    CourseList();

    // Destructor
    ~CourseList();

    //To read and append the information of each course according to each semester of a student from the text file
    void readCourses(string courseInfo);

    //To display the information of each course according to each semester of a student from the CourseList linked list 
    void displayCourses();

    //To edit and update the CGPA of each student
    void editGrade(float& tgpa);

    //To calculate the GPA of a particular semester based on the credits and grades
    float calculateGPA(string grades[], int credits[], int courseNo);

    //To remove specific courses taken by a student
    void deleteCourse(string courseCode);

    //To remove all courses taken by a student
    void removeAllCourses();

    //To calculate the size of an array
    void calcArrSize(int& arrSize);

    //To write all the course information of a student into a text file
    void writeCourseIntoFile(ofstream& outputFile);
};

#endif