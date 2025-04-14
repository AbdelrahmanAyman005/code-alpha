#include <iostream>
#include <vector>
#include <iomanip> // for setprecision

using namespace std;

struct Course {
    string name;
    int creditHours;
    float gradePoint;
};

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    vector<Course> courses(numCourses);
    float totalCredits = 0;
    float totalGradePoints = 0;

    for (int i = 0; i < numCourses; ++i) {
        cout << "\nEnter details for course " << i + 1 << ":\n";
        cout << "Course name: ";
        cin.ignore(); // Clear the input buffer
        getline(cin, courses[i].name);
        cout << "Credit hours: ";
        cin >> courses[i].creditHours;
        cout << "Grade point (e.g. 4.0, 3.7, etc.): ";
        cin >> courses[i].gradePoint;

        totalCredits += courses[i].creditHours;
        totalGradePoints += courses[i].creditHours * courses[i].gradePoint;
    }

    float cgpa = totalGradePoints / totalCredits;

    cout << fixed << setprecision(2);
    cout << "\n--- CGPA Report ---\n";
    for (int i = 0; i < numCourses; ++i) {
        cout << "Course: " << courses[i].name
             << " | Credit Hours: " << courses[i].creditHours
             << " | Grade Point: " << courses[i].gradePoint << endl;
    }
    cout << "Total Credits: " << totalCredits << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << "CGPA: " << cgpa << endl;

    return 0;
}

