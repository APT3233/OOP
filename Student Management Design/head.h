 
/***************************************Hello AnhNguyen*********************************/
 
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
 
using namespace std;
//set distance
const int max_title = 16;
const int max_name = 26;
const int max_age = 8;
const int max_class = 10;
const int max_phonenumber = 17;
const int max_hometown = 21;
const int max_point = 14;
const int max_menu = 40;
const int max_static = 13;

class Student{
public:
    Student();
    ~Student();
    static int getCount();

    void setInforStudent();
    void getInforStudent();
    void setPoint();
    float getAveragePoint();

    void setStudentID(string& id);
    void setName(string& newName);
    void setAge(int& newAge);
    void setClass(string& newClass);
    void setPlace(string& newPlace);
    void setPhoneNumber(string& newPhoneNumber);

    string getStudentID();
    string getName();
    string getClass();
    string getPlace();
    string getPhoneNumber();
    int getAge();

protected:
    string p_strStudentID;
    float p_floAveragePoint;
    float p_floMath;
    float p_floVietnamese;
    float p_floEnglish;
private:
    string m_strName;
    int m_intAge;
    string m_strClass;
    string m_strPhoneNumber;
    string m_strPlace;
    static int count;
   
};


class StudentManager : public Student{
public:
    static StudentManager* getManager();
    void addStudent();
    void removeStudent();
    void findStudent();
    void changeStudent();
    void displayAllStudent();
    
    static bool compareStudentID(Student* s1, Student* s2);
    void arrangeById();

    void theRateIsQuiteGood();
    void theBestMem();

private:
    vector<Student*> Student_List;
    static StudentManager* manager; //only one
    StudentManager() {}
};

class App  
{
public:
    void RUN();
    //void saveFile();
private:
    StudentManager* app;
};