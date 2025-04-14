#include <bits/stdc++.h>
using namespace std;

map<string, float> gradeToPoint={
    {"A+",4.0}, {"A",4.0}, {"A-",3.7},
    {"B+",3.3}, {"B",3.0}, {"B-",2.7},
    {"C+",2.3}, {"C",2.0}, {"C-",1.7},
    {"D",1.0}, {"F",0.0}
};

struct Course{
    string name;
    int creditHours;
    string letterGrade;
};

int main() {
    int numCourses;
    cout <<"Enter the number of courses: ";
    cin >> numCourses;

    vector<Course> courses(numCourses);
    float totalCredits = 0, totalGradePoints = 0;

    for (int i = 0; i < numCourses; ++i) {
        cout << "\nEnter details for course " << i + 1 << ":\n";
        cout << "Course name: ";
        cin.ignore();
        getline(cin, courses[i].name);
        cout << "Credit hours: ";
        cin >> courses[i].creditHours;
        cout << "Letter grade (e.g. A, B+, C-): ";
        cin >> courses[i].letterGrade;

        transform(courses[i].letterGrade.begin(), courses[i].letterGrade.end(), courses[i].letterGrade.begin(), ::toupper);

        if (gradeToPoint.find(courses[i].letterGrade) == gradeToPoint.end()) {
            cout << "Invalid grade entered! Try again.\n";
            --i;
            continue;
        }

        totalCredits += courses[i].creditHours;
        totalGradePoints += courses[i].creditHours * gradeToPoint[courses[i].letterGrade];
    }

    float cgpa = totalGradePoints / totalCredits;

    cout << fixed << setprecision(2);
    cout << "\n--- CGPA Report ---\n";
    for (auto& c : courses) {
        cout << "Course: " << c.name
             << " | Credit Hours: " << c.creditHours
             << " | Grade: " << c.letterGrade << endl;
    }

    cout << "Total Credits: " << totalCredits << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << "CGPA: " << cgpa << endl;

    return 0;
}


