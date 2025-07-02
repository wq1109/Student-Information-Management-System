//#include	<iostream>
//#include 	<fstream>
//#include	<string>
//#include	<cstdlib>
//#include    <cstring>
//#include	"List.h"
//#include	"Student.h"
//
//using namespace std;
//
//bool CreateStuList(const char*, List*);
//bool DeleteStudent(List*, char*);
//bool PrintList(List, int);
//bool InsertExamResult(char*, List*);
//bool PrintStatistic(List);
//bool FilterStudent(List, List*, char*, int, int);
//bool UpdateIDandPhone(List*);
//bool FindPotentialFirstClass(List, List*, char*);
//int menu();
//
//
//List dummy();
//
//using namespace std;
//
//
////bool openFile(const char*, ifstream);
////bool isDuplicate(List*, const string);
//
//bool isValidID(const char input[]);
//
//
//int main() {
//    List stuList;  // Create a List object
//
//
//    if (/*CreateStuList("student.txt", &stuList)*/ true) {
//        stuList = dummy();
//        cout << "Student list successfully created!" << endl;
//
//        char file[9] = "exam.txt";
//        List* list = &stuList;
//
//        InsertExamResult(file, list);
//        PrintList(stuList, 1);
//
//
//        //-------------------------------CHECK--------------------------------------
//                // ✅ PRINT LINKED LIST MANUALLY
//        Node* cur = stuList.head;  // Access head directly
//        if (stuList.empty())
//            cout << "The student list is empty." << endl;
//
//        else {
//
//            // PrintList(stuList, 2);
//            while (cur != nullptr) {
//                cout << "ID: " << cur->item.id
//                    << ", Name: " << cur->item.name
//                    << ", Course: " << cur->item.course
//                    << ", Phone: " << cur->item.phone_no << endl;
//                cur = cur->next;  // Move to the next node
//            }
//        }
//    }
//    //----------------------------------------------------------------------------
//
//    else {
//        cout << "Failed to create student list!" << endl;
//    }
//
//
//    //q2
//    char del_id[8];
//    char choice;
//
//    do {
//        cout << "Enter the 7-digit student ID to delete: ";
//        cin.getline(del_id, 8);
//
//        while (!isValidID(del_id)) {
//            cout << "Invalid ID! Please enter exactly 7 digits: ";
//            cin.getline(del_id, 8);
//        }
//
//        if (DeleteStudent(&stuList, del_id)) {
//            cout << "Student " << del_id << " deleted successfully!\n";
//        }
//        else {
//            cout << "Student ID " << del_id << " not found.\n";
//        }
//
//        cout << "Do you want to delete another student? (Y/N): ";
//        cin >> choice;
//        cin.ignore();
//
//    } while (toupper(choice) == 'Y');
//
//
//    //-------------------------------CHECK--------------------------------------
//        // ✅ PRINT LINKED LIST MANUALLY
//    Node* cur = stuList.head;  // Access head directly
//    if (cur == nullptr)
//        cout << "The student list is empty." << endl;
//
//    else {
//        while (cur != nullptr) {
//            cout << "ID: " << cur->item.id
//                << ", Name: " << cur->item.name
//                << ", Course: " << cur->item.course
//                << ", Phone: " << cur->item.phone_no << endl;
//            cur = cur->next;  // Move to the next node
//        }
//    }
//    //----------------------------------------------------------------------------
//
//
//
//    system("pause");
//    return 0;
//}
//
//List dummy()
//{
//    Student student1;
//    strcpy(student1.name, "Liang Tim Lok");
//    strcpy(student1.id, "2301094");
//    strcpy(student1.phone_no, "123-4567");
//    strcpy(student1.course, "CS");
//    student1.current_cgpa = 3.75;
//    /*student1.totalCreditsEarned = 19;
//    student1.exam_cnt = 3;
//    student1.exam[0].trimester = 1;
//    student1.exam[0].year = 2024;
//    student1.exam[0].gpa = 3.75;
//    student1.exam[1].gpa = 3.75;
//    student1.exam[2].gpa = 3.75;
//    student1.exam[0].numOfSubjects = 1;
//    student1.exam[1].numOfSubjects = 1;
//    student1.exam[2].numOfSubjects = 1;
//    strcpy(student1.exam[0].sub[0].subject_code, "1200233");
//    strcpy(student1.exam[0].sub[0].subject_name, "EXAM1");
//    strcpy(student1.exam[0].sub[1].subject_name, "EXAM2");
//    strcpy(student1.exam[0].sub[2].subject_name, "EXAM3");
//    student1.exam[0].sub[0].credit_hours = 12;
//    student1.exam[1].sub[0].credit_hours = 12;
//    student1.exam[2].sub[0].credit_hours = 12;
//    student1.exam[0].sub[0].marks = 100;*/
//
//
//    Student student2;
//    strcpy(student2.name, "Wong Wei Qi");
//    strcpy(student2.id, "2302302");
//    strcpy(student2.course, "CS");
//    strcpy(student2.phone_no, "659-8776");
//    student2.current_cgpa = 4.0;
//    student2.totalCreditsEarned = 25;
//    student2.exam_cnt = 5;
//    student2.exam[0].trimester = 5;
//    student2.exam[0].year = 2024;
//    student2.exam[0].gpa = 3.75;
//    student2.exam[1].gpa = 3.74;
//    student2.exam[2].gpa = 3.75;
//    student2.exam[3].gpa = 3.74;
//    student2.exam[4].gpa = 3.67;
//    strcpy(student2.exam[0].sub[0].subject_code, "1200233");
//    strcpy(student2.exam[0].sub[0].subject_name, "PROGRAMMING_CONCEPTS_AND_DESIGN");
//    student2.exam[0].sub[0].credit_hours = 12;
//    student2.exam[1].sub[0].credit_hours = 12;
//    student2.exam[2].sub[0].credit_hours = 12;
//    student2.exam[3].sub[0].credit_hours = 12;
//    student2.exam[4].sub[0].credit_hours = 12;
//
//    Student student3;
//    strcpy(student3.name, "Ali Malou");
//    strcpy(student3.course, "CN");
//    strcpy(student3.id, "1010101");
//    strcpy(student3.phone_no, "456-7776");
//    student3.current_cgpa = 2.3;
//    student3.totalCreditsEarned = 23;
//    student3.exam_cnt = 1;
//    student3.exam[0].trimester = 10;
//    student3.exam[0].year = 2024;
//    student3.exam[0].gpa = 3.67;
//    student3.exam[0].numOfSubjects = 3;
//    strcpy(student3.exam[0].sub[0].subject_code, "1200233");
//    strcpy(student3.exam[0].sub[0].subject_name, "PROGRAMMING_CONCEPTS_AND_DESIGN");
//    student3.exam[0].sub[0].credit_hours = 5;
//    student3.exam[0].sub[0].marks = 100;
//
//    Node* head = new Node(student1);
//    List list;
//    list.insert(1, student1);
//    list.insert(2, student2);
//    list.insert(3, student3);
//
//    return list;
//}
////---------------------------------------------------------------------------------
//
//
////function for q1
//
//
////open file
//bool openFile(const char* filename, ifstream& file)
//{
//    file.open(filename);
//
//    if (!file)  // Check if the file opened successfully
//    {
//        cout << "ERROR: Unable to open " << filename << endl;
//        return false;
//    }
//
//    return true;
//}
//
//
////check duplicate id
//bool isDuplicate(List* list, const string& id) {
//    Node* cur = list->head;
//    while (cur != nullptr) {
//        if (strcmp(cur->item.id, id.c_str()) == 0) {
//            return true;  //have duplicate ID
//        }
//        cur = cur->next;
//    }
//    return false;  //no duplicate 
//}
//
//
////--------------------------------------------------------------------------------
//
////q1
//bool CreateStuList(const char* filename, List* list) {
//    ifstream rfile;
//    if (!openFile(filename, rfile)) {
//        return false;  //can't open file 
//    }
//
//    string id, name, course, phone, temp;
//    while (getline(rfile, temp)) {
//        if (temp.find("Student Id") != string::npos) {
//            id = temp.substr(temp.find("=") + 2);
//            getline(rfile, temp);
//            name = temp.substr(temp.find("=") + 2);
//            getline(rfile, temp);
//            course = temp.substr(temp.find("=") + 2);
//            getline(rfile, temp);
//            phone = temp.substr(temp.find("=") + 2);
//
//            if (!isDuplicate(list, id)) {
//                Student newStudent;
//
//                strcpy(newStudent.id, id.c_str());
//                strcpy(newStudent.name, name.c_str());
//                strcpy(newStudent.course, course.c_str());
//                strcpy(newStudent.phone_no, phone.c_str());
//
//                list->insert(newStudent);
//            }
//            else {
//                cout << "Duplicate found: " << id << " - Skipping\n";
//            }
//        }
//    }
//
//    rfile.close();
//    return true;
//}
//
//
//
////------------------------------------------------------------------------------
//
//
////function for q2
//
//
////check if the id format correct or not 
//bool isValidID(const char input[]) {
//    if (strlen(input) != 7) {
//        return false;
//    }
//
//    // Check if all characters are digits
//    for (int i = 0; i < 7; i++) {
//        if (!isdigit(input[i])) {
//            return false;  // Found a non-digit character
//        }
//    }
//    return true;
//}
//
//
////------------------------------------------------------------------------------------
//
////q2
//bool DeleteStudent(List* list, char* id) {
//
//    if (list->head == nullptr) {
//        return false;  // List is empty
//    }
//
//    Node* cur = list->head;
//    Node* pre = nullptr;
//
//    // Search for the student with the given ID
//    while (cur != nullptr) {
//        if (strcmp(cur->item.id, id) == 0) {
//            // Found the student, delete it
//            if (pre == nullptr) {
//                // The node to be deleted is the head
//                list->head = cur->next;
//            }
//            else {
//                pre->next = cur->next;
//            }
//
//            delete cur;  // Free the memory
//            return true;  // Successfully deleted
//        }
//
//        pre = cur;
//        cur = cur->next;
//    }
//
//    return false;  // Student not found
//
//}
//
//
////--------------------------------------------------------------------------------
//
//
////q3
//bool PrintList(List list, int source)
//{
//
//    ofstream outFile;
//    Node* cur;
//    char trimester[4];
//
//    if (list.empty())
//        return false;
//
//    cur = list.head;
//    if (source == 1)
//    {
//        for (int i = 0; i < list.count; i++) //iterate thru every students
//        {
//            cout << "******************************************************STUDENT " << (i + 1) << "******************************************************";
//            cout << "\n\n";
//            cout << "Name:  " << cur->item.name;
//            cout << "\nId: " << cur->item.id;
//            cout << "\nCourse: " << cur->item.course;
//            cout << "\nPhone No: " << cur->item.phone_no;
//            cout << "\nCurrent CGPA: " << cur->item.current_cgpa;
//            cout << "\nTotal Credits Earned: " << cur->item.totalCreditsEarned;
//            cout << endl;
//
//            for (int j = 0; j < cur->item.exam_cnt; j++)//
//            {
//                if (cur->item.exam->trimester == 1)
//                    strcpy(trimester, "Jan");
//                else if (cur->item.exam->trimester == 5)
//                    strcpy(trimester, "May");
//                else if (cur->item.exam->trimester == 10)
//                    strcpy(trimester, "Oct");
//                else
//                {
//                    cout << "Invalid Trimester" << endl;
//                    return false;
//                }
//
//
//                cout << "--------------------------------------------------PAST EXAM RESULT:-------------------------------------------------- ";
//                cout << endl;
//                cout << trimester << " " << cur->item.exam->year << " Exam Results : ";
//                cout << endl;
//                cout << cur->item.exam->numOfSubjects << " subjects taken." << endl;
//                cout << "_____________________________________________________________________________________________________________________" << endl;
//                cout << "Subject Code	Subject Name                                                      Credit Hours	  Grade   Grade Point" << endl;
//                cout << "_____________________________________________________________________________________________________________________" << endl;
//                //UCCD1004	PROGRAMMING CONCEPTS AND DESIGN                                         4	    B + 3.33000
//                for (int x = 0; x < cur->item.exam->numOfSubjects; x++)
//                {
//                    cout << left << setw(16) << cur->item.exam->sub[x].subject_code << left << setw(71) << cur->item.exam->sub[x].subject_name << left << setw(13)
//                        << cur->item.exam->sub[x].credit_hours << left << setw(8) << cur->item.exam->sub[x].getGrade() << cur->item.exam->sub[x].getGradePoint() << endl;
//                }
//                cout << "GPA: " << cur->item.exam->gpa << endl << endl;
//
//            }
//            cur = cur->next;
//        }
//    }
//    else if (source == 2)
//    {
//        outFile.open("student_result.txt");
//
//        for (int i = 0; i < list.count; i++) //iterate thru every students
//        {
//            outFile << "******************************************************STUDENT " << (i + 1) << "******************************************************";
//            outFile << "\n\n\n";
//            outFile << "Name:  " << cur->item.name;
//            outFile << "\nId: " << cur->item.id;
//            outFile << "\nCourse: " << cur->item.course;
//            outFile << "\nPhone No: " << cur->item.phone_no;
//            outFile << "\nCurrent CGPA: " << cur->item.current_cgpa;
//            outFile << "\nTotal Credits Earned: " << cur->item.totalCreditsEarned;
//            outFile << endl;
//
//            for (int j = 0; j < cur->item.exam_cnt; j++)//
//            {
//                if (cur->item.exam->trimester == 1)
//                    strcpy(trimester, "Jan");
//                else if (cur->item.exam->trimester == 5)
//                    strcpy(trimester, "May");
//                else if (cur->item.exam->trimester == 10)
//                    strcpy(trimester, "Oct");
//                else
//                {
//                    outFile << "Invalid Trimester" << endl;
//                    return false;
//                }
//
//
//                outFile << "--------------------------------------------------PAST EXAM RESULT:-------------------------------------------------- ";
//                outFile << endl;
//                outFile << trimester << " " << cur->item.exam->year << " Exam Results : ";
//                outFile << endl;
//                outFile << cur->item.exam->numOfSubjects << " subjects taken." << endl;
//                outFile << "_____________________________________________________________________________________________________________________" << endl;
//                outFile << "Subject Code	Subject Name                                                      Credit Hours	  Grade   Grade Point" << endl;
//                outFile << "_____________________________________________________________________________________________________________________" << endl;
//                //UCCD1004	PROGRAMMING CONCEPTS AND DESIGN                                         4	    B + 3.33000
//                for (int x = 0; x < cur->item.exam->numOfSubjects; x++)
//                {
//                    outFile << left << setw(16) << cur->item.exam->sub[x].subject_code << left << setw(71) << cur->item.exam->sub[x].subject_name << left << setw(13)
//                        << cur->item.exam->sub[x].credit_hours << left << setw(8) << cur->item.exam->sub[x].getGrade() << cur->item.exam->sub[x].getGradePoint() << endl;
//                }
//                outFile << "GPA: " << cur->item.exam->gpa << endl << endl;
//
//            }
//            cur = cur->next;
//        }
//        outFile.close();
//    }
//}
//
////q4
//bool InsertExamResult(char* filename, List* list)
//{
//    ifstream inFile;
//    Node* cur;
//
//    int Trimester, Year, subjectNum, creditHr, lineCount = 0;
//    double GPA, marks;
//    char subjectCode[10], subjectName[256], studID[12];
//    string line;
//
//    inFile.open(filename);
//    if (!inFile)
//    {
//        cout << filename << " cannot be open!" << endl;
//        return false;
//    }
//    else
//        cout << "File Opened";
//
//    while (getline(inFile, line))
//        lineCount++;
//
//    inFile.clear();
//    inFile.seekg(0, std::ios::beg);
//
//    for (int i = 0; i < (lineCount / 2); i++)
//    {
//        getline(inFile, line);
//        cout << endl;
//        inFile >> studID;
//        inFile >> Trimester;
//        inFile >> Year;
//
//        cout << studID << endl;
//        cout << Trimester << endl;
//        cout << Year << endl;
//
//        if (Year > 2025)
//            cout << "Invalid Exam Year detected, Please ensure every exam year in " << filename << " does not exceed 2025.";
//
//        inFile >> subjectNum;
//
//        for (int x = 0; x < subjectNum; x++)
//        {
//            inFile >> subjectCode;
//            inFile >> subjectName;
//            inFile >> creditHr;
//            inFile >> marks;
//
//            cout << subjectCode << endl;
//            cout << subjectName << endl;
//            cout << creditHr << endl;
//            cout << marks << endl;
//
//
//            cur = list->head;
//            while (cur != nullptr)
//            {
//                if (strcmp(cur->item.id, studID) == 0)
//                {
//                    if (cur->item.exam_cnt == 0)
//                    {
//                        strcpy(cur->item.exam[0].sub[0].subject_code, subjectCode);
//                        strcpy(cur->item.exam[0].sub[0].subject_code, subjectCode);
//                        cur->item.exam[0].sub[0].credit_hours = creditHr;
//                        cur->item.exam[0].sub[0].marks = marks;
//
//                        cur->item.exam[0].numOfSubjects++;
//                        cur->item.exam_cnt++;
//
//                        cout << "\nSuccess +1" << endl;
//                    }
//
//                    else
//                    {
//                        //check whether exam year exists
//                        for (int j = 0; j < cur->item.exam_cnt; j++) // loop to iterate every exam
//                        {
//                            cout << "exam count:" << cur->item.exam_cnt;
//
//                            if (subjectNum + cur->item.exam[j].numOfSubjects > 6)
//                                cout << "\nThe number of subject taken by student " << cur->item.name << "(" << cur->item.id << ")  in year " << cur->item.exam[j].year << "had exceeded 6. Please check the details again.";
//
//                            else if (cur->item.exam_cnt > 10)
//                                cout << "\nThe number of exam taken by student " << cur->item.name << "(" << cur->item.id << ") had exceeded 10. Please check the details again.";
//
//                            else if (Year > 2025)
//                                cout << "Invalid Exam Year detected, Please ensure every exam year in " << filename << " does not exceed 2025.";
//
//                            else if (cur->item.exam->year == Year) // if exam year exist,add to subject num+1
//                            {
//                                int curSubjectCount = cur->item.exam[j].numOfSubjects;
//                                strcpy(cur->item.exam->sub[curSubjectCount + 1].subject_code, subjectCode);
//                                strcpy(cur->item.exam->sub[curSubjectCount + 1].subject_name, subjectName);
//                                cur->item.exam->sub[curSubjectCount + 1].credit_hours = creditHr;
//                                cur->item.exam->sub[curSubjectCount + 1].marks = marks;
//
//                                cur->item.exam[j].numOfSubjects++;
//
//                                cout << "\nSuccess +1" << endl;
//                            }
//
//                            else  //if exam year does not exists, add new exam year
//                            {
//                                cout << "\here" << endl;
//                                int curExamCount = cur->item.exam_cnt;
//                                strcpy(cur->item.exam[curExamCount + 1].sub[0].subject_code, subjectCode);
//                                strcpy(cur->item.exam[curExamCount + 1].sub[0].subject_code, subjectCode);
//                                cur->item.exam[curExamCount + 1].sub[0].credit_hours = creditHr;
//                                cur->item.exam[curExamCount + 1].sub[0].marks = marks;
//
//                                cur->item.exam[curExamCount + 1].numOfSubjects++;
//                                cur->item.exam_cnt++;
//
//                                //cout << "\nSuccess +1" << endl;
//
//                            }
//                        }
//                    }
//
//                }
//                //else
//                    //cout << "\nThe Student ID " << studID << " cannot be found. Please Check again.";
//
//
//                cur = cur->next;
//            }
//        }
//
//
//    }
//    cout << "\n\nAll exam record had been inserted successfully\n\n ";
//
//}
//
//
