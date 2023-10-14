
/***********************************Hello AnhNguyen******************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <limits>
#include "head.h"
using namespace std;

// Student
Student::Student() { count++; }
Student::~Student() { count--; }
int Student::getCount() { return count; }
void Student::setInforStudent() // input
{
    cout << "\tEnter a new Student ID: ";
    getline(cin >> ws, p_strStudentID);
    setStudentID(p_strStudentID);

    cout << "\tEnter Fullname: ";
    getline(cin >> ws, m_strName);
    setName(m_strName);

    cout << "\tEnter Age: ";
    cin >> m_intAge;
    setAge(m_intAge);

    cout << "\tClass: ";
    getline(cin >> ws, m_strClass);
    setClass(m_strClass);

    cout << "\tEnter PhoneNumber: ";
    getline(cin >> ws, m_strPhoneNumber);
    setPhoneNumber(m_strPhoneNumber);

    cout << "\tEnter Place: ";
    getline(cin >> ws, m_strPlace);
    setPlace(m_strPlace);
}
void Student::getInforStudent() // output
{
        cout << left;
        cout  << setw(max_title) << p_strStudentID << setw(max_name) << m_strName << setw(max_age) << m_intAge
            << setw(max_class) << m_strClass << setw(max_phonenumber) << m_strPhoneNumber << setw(max_hometown) << m_strPlace
            << setw(max_point) << p_floMath << setw(max_point) << p_floVietnamese << setw(max_point) << p_floEnglish << setw(max_point) << p_floAveragePoint;
    
}
void Student::setStudentID(string &id)
{
    p_strStudentID = id;
}
void Student::setName(string &newName)
{
    m_strName = newName;
}
void Student::setAge(int &newAge)
{
    m_intAge = newAge;
}
void Student::setClass(string &newClass)
{
    m_strClass = newClass;
}
void Student::setPlace(string &newPlace)
{
    m_strPlace = newPlace;
}
void Student::setPhoneNumber(string &newPhoneNumber)
{
    m_strPhoneNumber = newPhoneNumber;
}

string Student::getStudentID() { return p_strStudentID; }
string Student::getName() { return m_strName; }
int Student::getAge() { return m_intAge; }
string Student::getClass() { return m_strClass; }
string Student::getPlace() { return m_strPlace; }
string Student::getPhoneNumber() { return m_strPhoneNumber; }

void Student::setPoint()
{
    cout << "\n\tEnter scores in math, Vietnamese, and English respectively: ";
    cin >> p_floMath >> p_floVietnamese >> p_floEnglish;
}
float Student::getAveragePoint()
{
    p_floAveragePoint = (p_floMath + p_floVietnamese + p_floEnglish) / 3;
    return p_floAveragePoint;
}
int Student::count = 0;

// Manager
StudentManager *StudentManager::manager = NULL;
StudentManager *StudentManager::getManager()
{
    if (manager == NULL)
        manager = new StudentManager();
    return manager;
}

void StudentManager::addStudent()
{
    Student *newStudent = new Student();
    newStudent->setInforStudent();
    newStudent->setPoint();
    Student_List.push_back(newStudent);
    cout << "\tAdd Successful------->\n\n";
}
void StudentManager::removeStudent()
{
    cout << "Enter Student ID to remmove: ";
    string id;
    getline(cin >> ws, id);

    for (auto x = Student_List.begin(); x != Student_List.end(); x++)
    {
        if ((*x)->getStudentID() == id)
        {
            delete *x;
            Student_List.erase(x);
            cout << "Removed Successful---->\n\n";
            break;
        }
        else
            cout << "No Inf\n";
    }
}
void StudentManager::findStudent()
{
    cout << "Enter Student ID to find: ";
    string id;
    getline(cin >> ws, id);

    bool found = false; // Sử dụng biến này để kiểm tra xem có sinh viên nào khớp không.

    for (const auto &find : Student_List)
    {
        if (find->getStudentID() == id)
        {
            if (!found) {
                cout << left;
                cout << "\t" << setw(max_title) << "Student ID" << setw(max_name) << "Full Name"
                    << setw(max_age) << "Age" << setw(max_class) << "Class" << setw(max_phonenumber) << "Phone Number"
                    << setw(max_hometown) << "Hometown" << setw(max_point) << "Math" << setw(max_point) << "Vietnamese"
                    << setw(max_point) << "English" << setw(max_point) << "Total\n";
            }

            cout << left;
            find->getInforStudent();
            found = true;
        }
    }

    if (!found) {
        cout << "No student found with ID: " << id << "\n";
    }

    cout << endl;
}



void StudentManager::changeStudent()
{
    cout << "Enter Student ID to change: ";
    string id;
    getline(cin >> ws, id);
    
    for (auto find = Student_List.begin(); find != Student_List.end(); find++)
    {
        if ((*find)->getStudentID() != id)
        {
            cout << "No Inf\n"; 
        }
    }

    for (auto change = Student_List.begin(); change != Student_List.end(); change++)
    {
        if ((*change)->getStudentID() == id)
        {
            while (true)
            {
                int index, newAge;
                string newName, newClass, newPhone, newPlace;
                cout << "\n\t1. Name\n";
                cout << "\t2. Age\n";
                cout << "\t3. Class\n";
                cout << "\t4. Place\n";
                cout << "\t5. Phone Number\n";
                cout << "\t0. No change. Exit !\n";
                cout << "Enter the number you want to change information for: ";
                cin >> index;

                switch (index)
                {
                case 0:
                    return;
                case 1:
                    cout << "New Name: ";
                    getline(cin >> ws, newName);
                    (*change)->setName(newName);
                    cout << "Changed Successful---->\n";
                    break;
                case 2:
                    cout << "New Age: ";
                    cin >> newAge;
                    (*change)->setAge(newAge);
                    cout << "Changed Successful---->\n";
                    break;
                case 3:
                    cout << "New Class: ";
                    getline(cin >> ws, newClass);
                    (*change)->setClass(newClass);
                    cout << "Changed Successful---->\n";
                    break;
                case 4:
                    cout << "New Place: ";
                    getline(cin >> ws, newPlace);
                    (*change)->setPlace(newPlace);
                    cout << "Changed Successful---->\n";
                    break;
                case 5:
                    cout << "New PhoneNumber: ";
                    getline(cin >> ws, newPhone);
                    (*change)->setPhoneNumber(newPhone);
                    cout << "Changed Successful---->\n";
                    break;
                default:
                    break;
                }
            }
        }
    }
}
void StudentManager::displayAllStudent()
{
    cout << left;
    cout << setw(max_title) << "Student ID" << setw(max_name) << "Full Name"
               << setw(max_age) << "Age" << setw(max_class) << "Class" << setw(max_phonenumber) << "Phone Number"
               << setw(max_hometown) << "Hometown" << setw(max_point) << "Math" << setw(max_point) << "Vietnamese"
               << setw(max_point) << "English" << setw(max_point) << "Total\n";
   for(const auto& student : Student_List)
   {
       student->getInforStudent();
       cout << endl;
    }   
}
// arrange
bool StudentManager::compareStudentID(Student *s1, Student *s2)
{
    string id1 = s1->getStudentID();
    string id2 = s2->getStudentID();

    // Loại bỏ ký tự không phải số
    id1.erase(remove_if(id1.begin(), id1.end(), [](char c)
                        { return !isdigit(c); }),
              id1.end());

    id2.erase(remove_if(id2.begin(), id2.end(), [](char c)
                        { return !isdigit(c); }),
              id2.end());

    // Chuyển đổi thành số nguyên và so sánh
    int num1 = stoi(id1);
    int num2 = stoi(id2);

    return num1 < num2;
}
void StudentManager::arrangeById()
{
    sort(Student_List.begin(), Student_List.end(), StudentManager::compareStudentID);
}

// The Rate is quite good
void StudentManager::theRateIsQuiteGood()
{
    // Data Processing
    int count_1 = 0;
    int count_2 = 0;
    int count_3 = 0;
    int count_4 = 0;

    for (const auto &student : Student_List)
    {
        float avgPoint = student->getAveragePoint();
        if (avgPoint >= 9.0)
            count_1++;
        else if (avgPoint >= 8.0)
            count_2++;
        else if (avgPoint >= 5.0)
            count_3++;
        else
            count_4++;
    }
    float totalS = static_cast<int>(getCount()) - 1.0;
    float exe = (count_1 / totalS) * 100;
    float good = (count_2 / totalS) * 100;
    float aver = (count_3 / totalS) * 100;
    float poor = (count_4 / totalS) * 100;

    cout << "\n------The rate is quite good--------\n";
    cout << setw(max_static) << "Excellent" << exe << "%\n"
         << setw(max_static) << "Good" << good << "%\n"
         << setw(max_static) << "Average" << aver << "%\n"
         << setw(max_static) << "Poor" << poor << "%\n\n\n";
}

// Best member
void StudentManager::theBestMem()
{
    cout << "--------THE BEST MEMBER WITH THE HIGHEST SCORE---------\n";

    float point = 0.0;
    Student *bestStudent = NULL;
    for (const auto &best : Student_List)
    {
        if (best->getAveragePoint() > point)
        {
            point = best->getAveragePoint();
            bestStudent = best;
        }
    }
    if (bestStudent)
    {
        cout << left;
        cout << setw(max_title) << "Student ID" << setw(max_name) << "Full Name"
               << setw(max_age) << "Age" << setw(max_class) << "Class" << setw(max_phonenumber) << "Phone Number"
               << setw(max_hometown) << "Hometown" << setw(max_point) << "Math" << setw(max_point) << "Vietnamese"
               << setw(max_point) << "English" << setw(max_point) << "Total\n";
        bestStudent->getInforStudent();
        cout << endl;
    }
    else
        cout << "No Student found ! \n";
    cout << "----------------------\n\n";
}

void App::RUN()
{
    while (true)
    {
        cout << left;
        cout << " _________________MENU___________________\n";
        cout << setw(max_menu) << "|" << "|\n";
        cout << setw(max_menu) << "| 1. Add Student" << "|\n";
        cout << setw(max_menu) << "| 2. Remove Student" << "|\n";
        cout << setw(max_menu) << "| 3. Find Student" << "|\n";
        cout << setw(max_menu) << "| 4. Change INF " << "|\n";
        cout << setw(max_menu) << "| 5. Static" << "|\n";
        cout << setw(max_menu) << "| 6. Arrange By ID" << "|\n";
        cout << setw(max_menu) << "| 7. Best Member" << "|\n";
        cout << setw(max_menu) << "| 8. Display Student Information" << "|\n";
        cout << setw(max_menu) << "| 0. Exit" << "|\n";
        cout << "|_______________________________________" << "|\n";

        int choice, index;
        cout << "\n    ENTER(1, 2, 3,... or 0): ";
        cin >> choice;

        // Xử lý lỗi khi người dùng nhập chữ
         if (cin.fail()) 
         {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << " ";
            cout << "Invalid input. Please enter a number.\n";
            cout << endl;
            continue; // Quay lại vòng lặp
        }

        if (choice == 1)
        {   
            
            cout << "-------------ADD STUDENT--------------\n";
            
            cout << "\tHow many Student do you want to add: "; cin >> index;   
            if (cin.fail()) 
            {                
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\t";
                cout << "Invalid input. Please enter a number.\n";
                cout << endl;
                continue; // Quay lại vòng lặp
            }

            for(int i = 1; i <= index; i++)
            {   cout << "\tEnter student " << i << "---->\n";
                app->StudentManager::getManager()->addStudent();  
            }
        }
        else if (choice == 2)
        {
            app->StudentManager::getManager()->removeStudent();
        }
        else if (choice == 3)
        {
            app->StudentManager::getManager()->findStudent();
        }
        else if (choice == 4)
        {
            app->StudentManager::getManager()->changeStudent();
        }
        else if (choice == 5)
        {
            app->StudentManager::getManager()->theRateIsQuiteGood();
        }
        else if (choice == 6)
        {
            app->StudentManager::getManager()->arrangeById();
        }
        else if(choice == 7)
        {
            app->StudentManager::getManager()->theBestMem();
        }
        else if (choice == 8)
        {
            cout << "\t---------------------------------------------INFORMATION---------------------------------------------\n";   
            app->StudentManager::getManager()->displayAllStudent();
            cout << "\n\n\n";
        }
        else if (choice == 0)
        {
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}


