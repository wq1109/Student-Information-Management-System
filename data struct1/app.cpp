#include	<iostream>
#include 	<fstream>
#include	<string>
#include	<cstdlib>
#include    <cstring>
#include	"List.h"
#include	"Student.h"

using namespace std;

bool CreateStuList(const char*, List*);
bool DeleteStudent(List*, char*);
bool PrintList(List, int);
bool InsertExamResult(char*, List*);
bool PrintStatistic(List);
bool FilterStudent(List, List*, char*, int, int);
bool UpdateIDandPhone(List*);
bool FindPotentialFirstClass(List, List*, char*);
int menu();

using namespace std;

bool openFile(const char*, ifstream&);
bool isDuplicate(List*, const string);
bool isValidID(const char[]);
bool ExamExist(Node*, char[12], int, int, int&);
bool isEmptyLine(char[12]);
bool sortExam(List* list);
bool validCourse(List , char [3]);
int trackCourseNum(List list, char [3]);
void returnOrExit(int&);
bool sortExam(List*);



int main() {

    string option;
    char filename[20];
    int menuChoice,minCHr;
    bool valid,updated=false,insertedExam=false;
    List *stuList = new List();  

    do
    {
        system("cls");
        cout << "FICT STUDENT INFORMATION MANAGEMENT SYSTEM\n";
        menuChoice = menu();

        if (menuChoice == 1)
        {
            if (CreateStuList("student.txt", stuList)) {
                cout << "\n<CREATE STUDENT LIST>";
                cout << "\nStudent list successfully created!" << endl;
            }

            else
                cout << "Failed to create student list! Please check student.txt" << endl;
        }

        else if (menuChoice == 2)
        {
            char del_id[8];

            if (stuList->empty())
            {
                cout << "\nStudent List is empty.\n";
            }
            else
            {
                do {
                    cout << "\n<DELETE STUEDNT>\n";
                    cout << "Enter the Student ID to delete: ";
                    cin >> del_id;

                    while (!isValidID(del_id)) {
                        cout << "Invalid ID! Please enter exactly 7 digits: ";
                        cin >> del_id;

                        if (cin.fail())
                        {
                            cin.clear();
                            cin.ignore(1000, '\n');
                        }
                    }

                    cin.clear();
                    cin.ignore();

                    if (DeleteStudent(stuList, del_id)) {
                        cout << "Student " << del_id << " deleted successfully!\n";
                    }
                    else {
                        cout << "Student ID " << del_id << " not found.\n";
                    }


                    do //input validation
                    {
                        cout << "Do you want to delete another student? (y/n): ";
                        getline(cin, option);

                        if (option != "y" && option != "Y" && option != "n" && option != "N")
                            cout << "\nInvalid Option. Please try again\n";

                    } while (option != "y" && option != "Y" && option != "n" && option != "N");

                } while (option == "y" || option == "Y");
            }

            
        }

        else if (menuChoice == 3)
        {
            int source;
            cout << "\n<PRINT STUDENT LIST>\n";
            do
            {
                cout << "Please choose a source(1-Print to Screen/2-Print to File): ";
                cin >> source;

                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(1000,'\n');
                }

                if (source != 1 && source != 2)
                    cout << "Invalid Option. Please try again.\n";

            } while (source != 1 && source != 2);

            if (!PrintList(*stuList, source))
                cout << "\nStudent List is empty. Please ensure list is not empty before printing.\n";

            cin.ignore();
        }

        else if (menuChoice == 4)
        {
            cout << "\n<INSERT EXAM RESULT>\n";
            if (insertedExam)
                cout << "The exam result had been inserted previously\n.";

            else
            {
                if (stuList->empty())
                    cout << "\nStudent List is empty. Please try again.\n";

                else
                {
                    strcpy(filename, "exam.txt");
                    
                    if (!InsertExamResult(filename, stuList))
                        cout << endl << filename << " is empty. Please Try Again.";

                    else
                        cout << "All exam record had been inserted successfully\n ";

                    insertedExam = true;
                }
            }
        }

        else if (menuChoice == 5)
        {
            cout << "\n<PRINT STUDENT STATISTIC>";
            if (!PrintStatistic(*stuList))
                cout << "\nThe student list is empty. Please Try Again";
        }

        else if (menuChoice == 6)
        {
            
            List* filteredList = new List();
            char filterCrs[3];
            int  filterYear;
    
            cout << "\n<STUDENT FILTER>";
            if (stuList->empty())
                cout << "\nStudent List is empty. Please Try Again.\n";

            else
            {
               
                cout << "\nPlease Enter the following information to be filtered";
                cout << "\nCourse (CS/CN/CT/IA/IB): ";
                cin >> filterCrs;


                do {
                    valid = true;
                    if (cin.fail())
                    {
                        cout << "\nInvalid Course. Please Try Again.";
                        valid = false;
                        cin.clear();
                        cin.ignore(1000, '\n');
                    }

                    for (int i = 0; i < 2; i++)
                        filterCrs[i] = toupper(filterCrs[i]);

                    if (strcmp(filterCrs, "CS") != 0 && strcmp(filterCrs, "CT") != 0 && strcmp(filterCrs, "CN") != 0 && strcmp(filterCrs, "IA") != 0 && strcmp(filterCrs, "IB") != 0)
                    {
                        cout << "\nInvalid Course. Please Try Again.";
                        valid = false;
                    }

                    if (!valid)
                    {
                        cout << "\nLLLLLCourse (CS/CN/CT/IA/IB): ";
                        cin >> filterCrs;
                    }

                } while (!valid);

                cout << "\nYear: ";
                cin >> filterYear;

                do {
                    valid = true;
                    if (cin.fail())
                    {
                        cout << "\nInvalid Year. Please Try Again.";
                        valid = false;
                        cin.clear();
                        cin.ignore();
                    }

                    else if (filterYear > 2025)
                    {
                        cout << "\nInvalid Year. Please Try Again.";
                        valid = false;
                    }

                    if (!valid)
                    {
                        cout << "\nYear: ";
                        cin >> filterYear;
                    }

                } while (!valid);

                cout << "\nMinimum Total Credit Hour: ";
                cin >> minCHr;

                do {
                    valid = true;
                    if (cin.fail())
                    {
                        cout << "\nInvalid Credit Hour. Please Try Again.";
                        valid = false;
                        cin.clear();
                        cin.ignore();
                    }

                    else if (minCHr < 0)
                    {
                        cout << "\nInvalid Year. Please Try Again.";
                        valid = false;
                    }

                    if (!valid)
                    {
                        cout << "\nMinimum Total Credit Hour: ";
                        cin >> minCHr;
                    }
                } while (!valid);

                if (!FilterStudent(*stuList, filteredList, filterCrs, filterYear, minCHr))
                    cout << "\nNo matched student found.";

                PrintList(*filteredList, 1);
                cin.ignore();
            }

        }

        else if (menuChoice == 7)
        {
            cout << "\n<UPDATE STUDENT INFORMATION's FORMAT>";
            if (updated)
                cout << "\nStudent ID and Phone Number is in updated format already.";

            else
            {
                if (!UpdateIDandPhone(stuList))
                    cout << "\nStudent List is empty. Please Try Again.\n";

                else
                {
                    PrintList(*stuList, 1);
                    updated = true;
                }
            }
        }

        else if (menuChoice == 8)
        {
      
            List *firstclass = new List();
            char crs[3];

            cout << "\n<POTENTIAL FIRST CLASS STUDENT FINDER>\n";
            if (stuList->empty())
                cout << "Student List is empty. Please Try Again.";

            else

            {
                do
                {
                    cout << "\nWhich course's Potential First Class are you looking for? ";
                    cout << "\nCourse (CS/CN/CT/IA/IB): ";
                    cin >> crs;

                    do {
                        valid = true;
                        if (cin.fail())
                        {
                            cout << "\nInvalid Course. Please Try Again.";
                            valid = false;
                            cin.clear();
                            cin.ignore(1000, '\n');
                        }

                        for (int i = 0; i < 2; i++)
                            crs[i] = toupper(crs[i]);

                        if (strcmp(crs, "CS") != 0 && strcmp(crs, "CT") != 0 && strcmp(crs, "CN") != 0 && strcmp(crs, "IA") != 0 && strcmp(crs, "IB") != 0)
                        {
                            cout << "\nInvalid Course. Please Try Again.";
                            valid = false;
                        }

                        if (!valid)
                        {
                            cout << "\nCourse (CS/CN/CT/IA/IB): ";
                            cin >> crs;
                        }
                        cin.clear();
                        cin.ignore(1000, '\n');

                    } while (!valid);

                    if (FindPotentialFirstClass(*stuList, firstclass, crs))
                    {
                        PrintList(*firstclass, 1);
                        Node *cur = firstclass->head;
                        cout << "\n<First Class Potential Summary>" << endl;

                        cout << "Potential First Class (" << crs<< ")" << endl;
                        cout << "Total " << firstclass->count <<" students." << endl<<endl;
                        for (int i = 0; i < firstclass->count; i++)
                        {
                            cout << "Student " << i + 1 << endl;
                            cout << "Name: " << cur->item.name << endl;
                            cout << "ID: " << cur->item.id << endl;
                            cout << "CGPA: " << cur->item.current_cgpa << endl;
                            cout << endl ;
                        }
                    }
                    else
                        cout << "\nThere is no student in " << crs << "that has potential to get first class.\n";

                    do //input validation
                    {
                        cout << "Do you want to check another course? (y/n): ";
                        getline(cin, option);

                        if (option != "y" && option != "Y" && option != "n" && option != "N")
                            cout << "\nInvalid Option. Please try again\n";

                    } while (option != "y" && option != "Y" && option != "n" && option != "N");

                } while (option == "y" || option == "Y");
            }
        }

        if (menuChoice != 9)
         returnOrExit(menuChoice);

    } while (menuChoice != 9);

    cout << "EXITING PROGRAM........................";
    return 0;
}

void returnOrExit(int &choice)
{
    string option;
    do
    {
        cout << "\nReturn to main menu? (y-Yes/n-Exit Program): ";
        getline(cin, option);

        if (option == "n" || option == "N")
        {
            choice = 9;
            break;
        }

        else if (option == "y" || option == "Y")
        {
            break;
        }

        else
            cout << "\nInvalid option. Please try again.";

    } while (true);
}

//---------------------------------------------------------------------------------

bool openFile(const char* filename, ifstream& file)
{
    file.open(filename);

    if (!file)  // Check if the file opened successfully
    {
        cout << "ERROR: Unable to open " << filename << endl;
        return false;
    }

    return true;
} 

//check duplicate id
bool isDuplicate(List* list, string id) 
{
    Node* cur = list->head;
    while (cur != nullptr) {
        if (strcmp(cur->item.id, id.c_str()) == 0) {
            return true;  //have duplicate ID
        }
        cur = cur->next;
    }
    return false;  //no duplicate 
} 

//q1---------------------------------------------------------------------------------

bool CreateStuList(const char* filename, List* list) {
    ifstream rfile;
    if (!openFile(filename, rfile)) {
        return false;  //can"t open file 
    }

    string id, name, course, phone, temp;
    while (getline(rfile, temp)) {
        if (temp.find("Student Id") != string::npos) 
        {
            id = temp.substr(temp.find("=") + 2);
            getline(rfile, temp);
            name = temp.substr(temp.find("=") + 2);
            getline(rfile, temp);
            course = temp.substr(temp.find("=") + 2);
            getline(rfile, temp);
            phone = temp.substr(temp.find("=") + 2);

            if (!isDuplicate(list,id)) {
                Student newStudent;

                strcpy(newStudent.id, id.c_str());
                strcpy(newStudent.name, name.c_str());
                strcpy(newStudent.course, course.c_str());
                strcpy(newStudent.phone_no, phone.c_str());

                list->insert(newStudent);
            }
            else {
                cout << "Duplicate found: " << id << " - Skipping\n";
            }
        }
    }

    rfile.close();
    return true;
}

//q2---------------------------------------------------------------------------------

//check if the id format correct or not 
bool isValidID(const char input[]) {
    if (strlen(input) != 7 && strlen(input) !=10) {
        cin.ignore();
        return false;
    }
    return true;
}

bool DeleteStudent(List* list, char* id) {

    Node* cur;
    char newID[12];

    cur = list->head;
    // Search for the student with the given ID
    for (int i = 1; i <= list->count; i++) 
    {
        strncpy(newID, cur->item.id + 3, 7);
        newID[7] = '\0';
        
        if (strcmp(cur->item.id, id ) == 0 || strcmp(newID, id) == 0)
        {
            // Found the student, delete it
            list->remove(i);
            return true;
        }
        cur = cur->next;
         
    }

    return false;  // Student not found

}

//q3---------------------------------------------------------------------------------

bool PrintList(List list, int source)
{

    ofstream outFile;
    Node* cur;
    char trimester[4];

    if (list.empty())
        return false;

    /*if (!sortExam(&list))
        cout << "\n\nFailed to sort order of Exam\n\n";*/

    cur = list.head;
    if (source == 1)
    {
        system("cls");
        cout << "\nPRINTING STUDENT LIST TO SCREEN....................\n";
        for (int i = 0; i < list.count; i++) //iterate thru every students
        {
            cout << "******************************************************STUDENT " << (i + 1) << "******************************************************";
            cout << "\nName:  " << cur->item.name;
            cout << "\nId: " << cur->item.id;
            cout << "\nCourse: " << cur->item.course;
            cout << "\nPhone No: " << cur->item.phone_no;
            cout << "\nCurrent CGPA: " << cur->item.current_cgpa;
            cout << "\nTotal Credits Earned: " << cur->item.totalCreditsEarned;
            cout << "\nExam Count: " << cur->item.exam_cnt;
            cout << endl ;

            if (cur->item.exam_cnt == 0)
                cout << "\n<STUDENT HAVEN'T TAKEN ANY EXAM YET>\n";

            for (int x = 0; x < cur->item.exam_cnt; x++)//
            {
                if (cur->item.exam[x].trimester == 1)
                    strcpy(trimester, "Jan");
                else if (cur->item.exam[x].trimester == 5)
                    strcpy(trimester, "May");
                else if (cur->item.exam[x].trimester == 10)
                    strcpy(trimester, "Oct");

                cout << "--------------------------------------------------PAST EXAM RESULT "<< x+1 <<":-------------------------------------------------- ";
                cout << endl;
                cout << trimester << " " << cur->item.exam[x].year << " Exam Results : ";
                cout << endl;
                cout << cur->item.exam[x].numOfSubjects << " subjects taken." << endl;
                cout << "_____________________________________________________________________________________________________________________" << endl;
                cout << "Subject Code	Subject Name                                                      Credit Hours	  Grade   Grade Point" << endl;
                cout << "_____________________________________________________________________________________________________________________" << endl;
                for (int y = 0; y < cur->item.exam[x].numOfSubjects; y++)
                {
                    cout << left << setw(16) << cur->item.exam[x].sub[y].subject_code << left << setw(71) << cur->item.exam[x].sub[y].subject_name << left << setw(13)
                        << cur->item.exam[x].sub[y].credit_hours << left << setw(8) << cur->item.exam[x].sub[y].getGrade() << fixed << setprecision (2) << cur->item.exam[x].sub[y].getGradePoint() <<setprecision(5) << endl;
                }
                cout << "GPA: " << cur->item.exam[x].gpa << endl << endl;

            }
            
            cout << endl << endl;
            cur = cur->next;
        }
    }
    else if (source == 2)
    {
        outFile.open("student_result.txt");

        system("cls");
        cout << "\nPRINTING STUDENT LIST TO FILE....................\n";
        for (int i = 0; i < list.count; i++) //iterate thru every students
        {
            outFile << "******************************************************STUDENT " << (i + 1) << "******************************************************";
            outFile << "\n\n\n";
            outFile << "Name:  " << cur->item.name;
            outFile << "\nId: " << cur->item.id;
            outFile << "\nCourse: " << cur->item.course;
            outFile << "\nPhone No: " << cur->item.phone_no;
            outFile << "\nCurrent CGPA: " << cur->item.current_cgpa;
            outFile << "\nTotal Credits Earned: " << cur->item.totalCreditsEarned;
            outFile << endl;

            if (cur->item.exam_cnt == 0)
                outFile << "\n<STUDENT HAVEN'T TAKEN ANY EXAM YET>\n";

            for (int x = 0; x < cur->item.exam_cnt; x++)//
            {
                if (cur->item.exam[x].trimester == 1)
                    strcpy(trimester, "Jan");
                else if (cur->item.exam[x].trimester == 5)
                    strcpy(trimester, "May");
                else if (cur->item.exam[x].trimester == 10)
                    strcpy(trimester, "Oct");
                else
                {
                    outFile << "Invalid Trimester" << endl;
                    return false;
                }


                outFile << "--------------------------------------------------PAST EXAM RESULT:-------------------------------------------------- ";
                outFile << endl;
                outFile << trimester << " " << cur->item.exam[x].year << " Exam Results : ";
                outFile << endl;
                outFile << cur->item.exam[x].numOfSubjects << " subjects taken." << endl;
                outFile << "_____________________________________________________________________________________________________________________" << endl;
                outFile << "Subject Code	Subject Name                                                      Credit Hours	  Grade   Grade Point" << endl;
                outFile << "_____________________________________________________________________________________________________________________" << endl;
                for (int y = 0; y < cur->item.exam[x].numOfSubjects; y++)
                {
                    outFile << left << setw(16) << cur->item.exam[x].sub[y].subject_code << left << setw(71) << cur->item.exam[x].sub[y].subject_name << left << setw(13)
                        << cur->item.exam[x].sub[y].credit_hours << left << setw(8) << cur->item.exam[x].sub[y].getGrade() << fixed << setprecision(2) << cur->item.exam[x].sub[y].getGradePoint() << setprecision(5) << endl;
                }
                outFile << "GPA: " << cur->item.exam[x].gpa << endl << endl;

            }
         
            outFile << endl;
            cur = cur->next;
        }

        cout << "\nThe student list had been printed to file (student_result.txt) successfully!\n";
        outFile.close();
    }
}

//---------------------------------q4------------------------------------------------

bool ExamExist(Node* current, char studentID[12], int year, int sem,int &examIdx)
{
    int Trimester[3] = { 1,5,10 };

    for (int j = 0; j < current->item.exam_cnt; j++)
    {
        if (current->item.exam[j].year == year)
        {
            if (current->item.exam[j].trimester == sem)
            {
                examIdx = j;
                return true;
            }
        }
    }

    return false;
}

bool isEmptyLine(char line[12])
{
    if (strcmp(line, "") == 0)
        return true;

    return false;
}

bool InsertExamResult(char* filename, List* list)
{
    ifstream inFile;
    Node* cur;

    int Trimester, Year, subjectNum, creditHr, lineCount = 0, examIdx, curSubNum, curExNum;
    double GPA, marks;
    char subjectCode[10], subjectName[256], studID[12],updatedID[12];
    string line;

    inFile.open(filename);
    if (!inFile)
    {
        cout << filename << " cannot be open!" << endl;
        return false;
    }

   while (getline(inFile, line))
            lineCount++;


    inFile.clear();
    inFile.seekg(0, std::ios::beg);

    for (int i = 0; i < (lineCount); i++)
    {
        strcpy(studID, "");
        inFile >> studID;

        if (!isEmptyLine(studID))
        {
            inFile >> Trimester;
            inFile >> Year;

            inFile >> subjectNum;
            inFile >> subjectCode;
            inFile >> subjectName;
            inFile >> creditHr;
            inFile >> marks;

            if (Year > 2025)
                cout << "Invalid Exam Year detected, Please ensure every exam year in " << filename << " does not exceed 2025.";

            cur = list->head;
            while (cur != nullptr)
            {
                strncpy(updatedID, cur->item.id + 3, 7);
                updatedID[7] = '\0';

                if (strcmp(cur->item.id, studID) == 0 || strcmp(updatedID, studID) == 0)
                {
                    for (int x = 0; x < subjectNum; x++)
                    {

                        if (cur->item.exam_cnt == 0)
                        {
                            strcpy(cur->item.exam[0].sub[0].subject_code, subjectCode);
                            strcpy(cur->item.exam[0].sub[0].subject_name, subjectName);
                            cur->item.exam[0].sub[0].credit_hours = creditHr;
                            cur->item.exam[0].sub[0].marks = marks;
                            cur->item.exam[0].year = Year;
                            cur->item.exam[0].trimester = Trimester;
                            cur->item.exam_cnt++;
                            cur->item.exam[0].numOfSubjects++;

                            if (!cur->item.exam[0].calculateGPA())
                                cout << "Invalid number of subject in exam " << cur->item.exam[0].printTrimester() << Year << "of student" << studID << endl << endl;

                        }

                        else if (ExamExist(cur, studID, Year, Trimester, examIdx))
                        {
                            curSubNum = cur->item.exam[examIdx].numOfSubjects;
                            strcpy(cur->item.exam[examIdx].sub[curSubNum].subject_code, subjectCode);
                            strcpy(cur->item.exam[examIdx].sub[curSubNum].subject_name, subjectName);
                            cur->item.exam[examIdx].sub[curSubNum].credit_hours = creditHr;
                            cur->item.exam[examIdx].sub[curSubNum].marks = marks;
                            cur->item.exam[examIdx].numOfSubjects++;

                            if (!cur->item.exam[examIdx].calculateGPA())
                                cout << "Invalid number of subject in exam " << cur->item.exam[examIdx].printTrimester() << Year << "of student" << studID << endl << endl;
                        }

                        else if (!ExamExist(cur, studID, Year, Trimester, examIdx))
                        {
                            curExNum = cur->item.exam_cnt;
                            strcpy(cur->item.exam[curExNum].sub[0].subject_code, subjectCode);
                            strcpy(cur->item.exam[curExNum].sub[0].subject_name, subjectName);
                            cur->item.exam[curExNum].sub[0].credit_hours = creditHr;
                            cur->item.exam[curExNum].sub[0].marks = marks;
                            cur->item.exam[curExNum].year = Year;
                            cur->item.exam[curExNum].trimester = Trimester;
                            cur->item.exam_cnt++;
                            cur->item.exam[curExNum].numOfSubjects++;

                            if (!cur->item.exam[curExNum].calculateGPA())
                                cout << "Invalid number of subject in exam " << cur->item.exam[curExNum].printTrimester() << Year << "of student" << studID << endl << endl;
                        }
                        if (x != subjectNum - 1)
                        {
                            inFile >> subjectCode;
                            inFile >> subjectName;
                            inFile >> creditHr;
                            inFile >> marks;
                        }

                    }
                    cur->item.calculateCurrentCGPA();
                }


                cur = cur->next;
            }

        }
    }

    return true;
}

bool sortExam(List* list)
{
    Node* cur;
    Exam tmp, tmp2;
    cur = list->head;

    if (list->empty())
        return false;

    while (cur != nullptr)
    {
        for (int i = 0; i < cur->item.exam_cnt-1; i++)
        {
            for (int i = 0; i < cur->item.exam_cnt - 1; i++)
            {
                if (cur->item.exam[i].year < cur->item.exam[i + 1].year)
                {
                    tmp = cur->item.exam[i];
                    cur->item.exam[i] = cur->item.exam[i + 1];
                    cur->item.exam[i + 1] = tmp;
                }

                else if (cur->item.exam[i].year == cur->item.exam[i + 1].year)
                {
                    if (cur->item.exam[i].trimester < cur->item.exam[i + 1].trimester)
                    {
                        tmp = cur->item.exam[i];
                        cur->item.exam[i] = cur->item.exam[i + 1];
                        cur->item.exam[i + 1] = tmp;
                    }
                }
            }
        }
        cur = cur->next;
    }
    

    return true;
}

//----------------------------------q5-----------------------------------------------

bool validCourse(List list, char targetCourse[3])
{
    const int courseNum = 5;
    char courseType[5][3] = { "CS", "IA", "IB", "CN", "CT" };

    for (int i = 0; i < 2; i++)
        targetCourse[i] = toupper(targetCourse[i]);

    for (int i = 0; i < courseNum; i++)
    {
        if (strcmp(courseType[i], targetCourse) == 0)
            return true;
    }

    return false;
}

int trackCourseNum(List list, char targetCourse[3])
{
    const int courseNum = 5;
    char courseType[5][3] = { "CS", "IA", "IB", "CN", "CT" };
    int courseTypeNum[5] = { 0,0,0,0,0 };
    Node* cur;
    bool courseFound = false;

    if (validCourse(list, targetCourse))
    {
        cur = list.head;
        for (int i = 0; i < list.count; i++)
        {
            for (int j = 0; j < courseNum; j++)
            {
                if (strcmp(courseType[j], cur->item.course) == 0)
                {
                    courseTypeNum[j]++;
                    break;
                }
            }
            cur = cur->next;
        }

        for (int i = 0; i < courseNum; i++)
        {
            if (strcmp(courseType[i], targetCourse) == 0)
                return courseTypeNum[i];
        }
    }

    else
    {
        cout << "Invalid course entered.";
    }
    return 0;
}

bool PrintStatistic(List list)
{
    Node* cur;
    const int courseNum = 5;
    char courseType[5][3] = { "CS", "IA", "IB", "CN", "CT" };
    double total_cgpa = 0, total_subject = 0, total_credit = 0, total_semester = 0;
    double avg_cgpa = 0, avg_subject = 0, avg_credit = 0;

    if (list.count == 0)
        return false;

    else
    {
        cout << "\nTotal Students: " << list.count << endl<<endl;
        for (int i = 0; i < courseNum; i++)
            cout << "   " << courseType[i] << " Students - " << trackCourseNum(list, courseType[i]) << endl;

        cur = list.head;
        while (cur != nullptr)
        {
            total_cgpa += cur->item.current_cgpa;
            total_credit += cur->item.totalCreditsEarned;
            total_subject += cur->item.exam->numOfSubjects;
            total_semester += cur->item.exam_cnt;
            cur = cur->next;
        }

        if (total_semester == 0 && total_credit == 0 && total_subject == 0 && total_cgpa == 0)
            cout << "\nExam Result for student list is not inserted. Please try again.";

        else
        {
            avg_cgpa = total_cgpa / total_semester;
            avg_subject = total_subject / total_semester;
            avg_credit = total_credit / total_semester;

            cout << fixed << setprecision(5) << "\nAverage CGPA: " << avg_cgpa;
            cout << fixed << setprecision(2) << "\nAverage Subjects Taken Per Semester: " << avg_subject;
            cout << fixed << setprecision(2) << "\nAverage Credits Earned Per Semester: " << avg_credit;
        }
    
    }

    cout << endl;

    return true;
}

//------------------------------------q6---------------------------------------------

bool FilterStudent(List list1, List* list2, char* course, int year, int totalcredit)
{
    const int courseNum = 5;
    char courseType[5][3] = { "CS", "IA", "IB", "CN", "CT" };

    Node* cur;
    cur = list1.head;
    int valid = 0;
    char f2id[2];
    int F2id, Year;

    Year = year % 100;

    for (int i = 0; i < list1.count; i++)
    {
        for (int j = 0; j < courseNum; j++)
        {
            if (strcmp(cur->item.course, course) == 0)
            {
                valid++;
                break;
            }
        }

        if(isdigit(cur->item.id[0]))
            //copy the first 2 char of id can convert into int
            strncpy(f2id, cur->item.id, 2);

        else
            strncpy(f2id, cur->item.id+3, 2);

        if (atoi(f2id) == Year)
            valid++;

        if (cur->item.totalCreditsEarned > totalcredit || cur->item.totalCreditsEarned == totalcredit)
            valid++;


        if (valid == 3)
            list2->insert(cur->item);

        valid = 0;
        cur = cur->next;
    }

    if (list2->count == 0)
        return false;

    return true;
}

//----------------------------------q7-----------------------------------------------

bool UpdateIDandPhone(List* list)
{
    char newPhoneNo[10] = "", newID[12] = "";
    Node* cur;
    char prefix[12] = "B", course[3], phoneNumFront[4], phoneNumBack[5], phoneNo[10] = "";
    int firstDigit;

    if (list->empty())
        return false;

    cur = list->head;
    for (int i = 0; i < list->count; i++)
    {
        //Updating ID
        strcpy(course, cur->item.course);
        strcat(prefix, course); //e.g. prefix = BCS
        strcat(newID, prefix); //e.g. newID = BCS
        strcat(newID, cur->item.id); // newID = BCS2301094
        strcpy(cur->item.id, newID);

        //Updating Phone Numbers
        for (int i = 0; i < 3; i++)
            phoneNumFront[i] = cur->item.phone_no[i]; //0,1,2

        phoneNumFront[3] = '\0';

        for (int i = 0; i < 4; i++)
            phoneNumBack[i] = cur->item.phone_no[i + 4];

        phoneNumBack[4] = '\0';

        strcat(phoneNo, phoneNumFront);
        strcat(phoneNo, phoneNumBack);
        strcpy(cur->item.phone_no, phoneNo);
        //cout << cur->item.phone_no << endl;


        firstDigit = int(phoneNo[0]) - 48;
        if (firstDigit % 2 == 0)
            strcat(newPhoneNo, "02");
        else
            strcat(newPhoneNo, "01");

        strcat(newPhoneNo, phoneNo);

        strcpy(cur->item.phone_no, newPhoneNo);

        //initialise the variable
        strcpy(newID, "");
        strcpy(prefix, "B");
        strcpy(course, "");
        strcpy(phoneNumFront, "");
        strcpy(phoneNumBack, "");
        strcpy(phoneNo, "");
        strcpy(newPhoneNo, "");
        cur = cur->next;
    }

    return true;
}

//-----------------------------------q8----------------------------------------------

bool FindPotentialFirstClass(List list1, List* list2, char* course)
{
    Node* current;
    Node* cur;
    int invalid, criteria;
    double semCreditHr = 0;

    cur = list1.head;
    while(cur != nullptr)
    {
        if (strcmp(cur->item.course, course) == 0)
        {
            invalid = 0;
            criteria = 0;

            if (cur->item.exam_cnt < 3)
                invalid++;

            else
            {
                //Check GPA >= 3.75 for at least 3 sem
                // iterate through every exam
                for (int j = 0; j < cur->item.exam_cnt; j++)
                {

                    semCreditHr = 0;
                    for (int x = 0; x < cur->item.exam[j].numOfSubjects; x++)
                        semCreditHr += cur->item.exam[j].sub[x].credit_hours;

                    if (cur->item.exam[j].gpa >= 3.75 && semCreditHr >= 12)
                        criteria++;
                    //if any sem"s gpa less than 3.5
                    else if (cur->item.exam[j].gpa < 3.5)
                        invalid++;

                    // less than 3 sem"s gpa >= 3.75
                }
                if (criteria < 3)
                    invalid++;

            }

            if (criteria >= 3 && invalid == 0)
                list2->insert(cur->item);
        }
        cur = cur->next;
    }

    if (list1.empty())
        return false;

    if (list2->empty())
        cout << "There is no student in " << course << " that has potential to get first class." << endl;

    
    return true;
}

//-----------------------------------q9----------------------------------------------

int menu()
{
    string option;
    int choice = {};
    bool valid;

    do
    {
        
        valid = false;
        cout << "\nPlease choose from the following option\n";
        cout << "(1) Create student list\n(2) Delete Student\n(3) Print student list\n(4) Insert exam result\n(5) Print Exam Statistic\n(6) Filter Student\n(7) Update Student ID and Phone\n(8) Find Potential First Class Student\n(9) Exit.\n";
        cout << "\n\nUser Option: ";
        getline(cin,option);

        if (option == " " || option == "\t")
        {
            system("cls");
            cout << "\n<Empty Option detected. Please enter again>\n";
            valid = false;
        }

        else if (option != "0" && option != "1" && option != "2" && option != "3" && option != "4" && option != "5" && option != "6" && option != "7" && option != "8" && option != "9")
        {
            system("cls");
            cout << "\n<Invalid Option. Please Choose again>\n";
            valid = false;
        }

        else
        {
            choice = stoi(option);
            if (choice >= 1 && choice <= 9)
                valid = true;

            else
            {
                system("cls");
                cout << "\n<Invalid Option. Please Choose again>\n";
                valid = false;
            }
        }
    } while (!valid);

    return choice;
}




