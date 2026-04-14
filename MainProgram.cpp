#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// ================================
// CLASS DEFINITIONS
// ================================

class Student {
private:
    string name;
    int id;
    double gpa;

public:
    // ----- Constructors & Destructor -----

    Student() {
        name = "Unknown";
        id = 0;
        gpa = 0.0;
    }

    Student(string n, int i, double g) {
        name = n;
        id = i;
        gpa = g;
    }

    Student(const Student& other) {
        name = other.name;
        id = other.id;
        gpa = other.gpa;
    }

    ~Student() {
        cout << "Student " << name << " destroyed" << endl;
    }

    // ----- Getters -----

    string getName() const {
        return name;
    }

    int getId() const {
        return id;
    }

    double getGpa() const {
        return gpa;
    }

    // ----- Setters -----

    void setName(string n) {
        if (!n.empty()) {
            name = n;
        }
    }

    void setGpa(double g) {
        if (g >= 0.0 && g <= 4.0) {
            gpa = g;
        }
    }

    // ----- String Operation -----

    string getFormattedName() const {
        string temp = name;

        for (int i = 0; i < temp.length(); i++) {
            temp[i] = toupper(temp[i]);
        }

        return temp;
    }

    // ----- Operator Overloading -----

    bool operator==(const Student& other) const {
        return id == other.id;
    }

    bool operator<(const Student& other) const {
        return gpa < other.gpa;
    }

    friend ostream& operator<<(ostream& os, const Student& s) {
        os << "Student(" << s.name
           << ", ID: " << s.id
           << ", GPA: " << s.gpa << ")";
        return os;
    }
};

// ================================
// FUNCTION OVERLOADING
// ================================

// Two students
Student findBestStudent(const Student& a, const Student& b) {
    return (a < b) ? b : a;
}

// Array version
Student findBestStudent(Student arr[], int size) {
    Student best = arr[0];

    for (int i = 1; i < size; i++) {
        if (best < arr[i]) {
            best = arr[i];
        }
    }

    return best;
}

// ================================
// MAIN
// ================================

int main() {

    Student s1;
    cout << "Default: " << s1 << endl;

    Student s2("Ali", 101, 3.5);
    Student s3("Ayse", 102, 3.8);

    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3 << endl;

    Student s4(s2);
    cout << "Copy of s2: " << s4 << endl;

    cout << "s3 name: " << s3.getName() << endl;
    cout << "s3 GPA: " << s3.getGpa() << endl;

    s2.setGpa(5.0);
    cout << "s2 after invalid setGpa(5.0): " << s2 << endl;

    s2.setGpa(3.9);
    cout << "s2 after valid setGpa(3.9): " << s2 << endl;

    cout << "Formatted: " << s3.getFormattedName() << endl;

    cout << "s2 == s4? " << (s2 == s4 ? "Yes" : "No") << endl;
    cout << "s2 < s3? " << (s2 < s3 ? "Yes" : "No") << endl;

    Student best2 = findBestStudent(s2, s3);
    cout << "Best of two: " << best2 << endl;

    Student roster[] = {s1, s2, s3, s4};
    Student bestAll = findBestStudent(roster, 4);
    cout << "Best of all: " << bestAll << endl;

    return 0;
}
