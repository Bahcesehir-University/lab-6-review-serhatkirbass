// ============================================================
// Lab W7: C++ OOP Review - Classes, Encapsulation, Strings,
//         Copy Constructors, Operator Overloading
// Course: Object-Oriented Programming
// Duration: 40 minutes
// ============================================================
// SINGLE FILE IMPLEMENTATION - No header files allowed
// ============================================================

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// ================================
// CLASS DEFINITIONS
// ================================

// -----------------------------------------------------------
// Class: Student
// Represents a university student with name, ID, and GPA.
// This class reviews:
//   - Encapsulation (private data, public interface)
//   - Constructors (default, parameterized)
//   - Destructor
//   - Copy Constructor
//   - Operator Overloading (<<, ==, <)
//   - String operations
// -----------------------------------------------------------
class Student {
private:
    string name;
    int id;
    double gpa;

public:
    // ----- Task 1: Constructors & Destructor -----

    // TODO 1a: Default constructor
    // Set name to "Unknown", id to 0, gpa to 0.0
    Student() {
        name="Unknown";
        id=0;
        gpa=0.0;
        // YOUR CODE HERE
    }

    // TODO 1b: Parameterized constructor
    // Initialize all three member variables from parameters
    Student(string n, int i, double g) {
     name=n;
     id=i;
     gpa=g;
        // YOUR CODE HERE
    }

    // TODO 1c: Copy constructor
    // Create a deep copy of another Student object
    Student(const Student& other) {
          name= other.name;
          id= other.id;
          gpa= other.gpa;
        // YOUR CODE HERE
    }

    // TODO 1d: Destructor
    // Print: "Student [name] destroyed"
    ~Student() {
        cout<< "Student " << name<< " destroyed"<<endl;
        // YOUR CODE HERE
    }

    // ----- Task 2: Getters (Encapsulation) -----

    // TODO 2a: Getter for name
    string getName() const {
        // YOUR CODE HERE
        return name;
    }

    // TODO 2b: Getter for id
    int getId() const {
        // YOUR CODE HERE
        return id;
    }

    // TODO 2c: Getter for gpa
    double getGpa() const {
        // YOUR CODE HERE
        return gpa;
    }

    // ----- Task 3: Setters with Validation -----

    // TODO 3a: Setter for name
    // Name must not be empty. If empty, keep current name.
    void setName(string n) {
        if(!n.empty()){
            name=n;
        }
        
    }

    // TODO 3b: Setter for GPA
    // GPA must be between 0.0 and 4.0 (inclusive).
    // If out of range, keep current GPA.
    void setGpa(double g) {
        if(gpa<4.0 && gpa>0.0){
            gpa=g;
        }
        
        // YOUR CODE HERE
    }

    // ----- Task 4: String Operation -----

    // TODO 4: getFormattedName()
    // Return the name in UPPERCASE
    // Hint: loop through each character and use toupper()
    string getFormattedName() const { 
        
        string temp=name;

        for(int i=0; i<=name.length(); i++){
            temp[i]=toupper(temp[i]);
           
        }
    
        
    
        // YOUR CODE HERE
        return temp;
    }
   

    // ----- Task 5: Operator Overloading -----

    // TODO 5a: Equality operator (==)
    // Two students are equal if they have the same id
    bool operator==(const Student& other) const {
        // YOUR CODE HERE
        return id == other.id;
    }


    // TODO 5b: Less-than operator (<)
    // Compare by GPA (lower GPA = "less than")
    bool operator<(const Student& other) const {
        // YOUR CODE HERE
        return gpa<other.gpa;
    }

    // TODO 5c: Stream insertion operator (<<)
    // Format: "Student(name, ID: id, GPA: gpa)"
    // Example: "Student(Ali, ID: 101, GPA: 3.5)"
    friend ostream& operator<<(ostream& os, const Student& s) {
    os << "Student("<<s.name<<" , ID: "<<s.id<<", GPA: "<<s.gpa<<")";
    return os;
}
};

// ================================
// STANDALONE FUNCTION
// ================================

// TODO 6: Function Overloading - findBestStudent
// Version 1: Takes two Student references, returns the one with higher GPA
Student findBestStudent(const Student& a, const Student& b) {
    // YOUR CODE HERE
    if(b<a){
        return a ;

    }
    return b;
}

// Version 2: Takes an array of Students and its size, returns the one with highest GPA
Student findBestStudent(Student arr[], int size) {
    Student best= arr[0];
    for(int i= 1 ; i < size ; i++){
        if(best < arr[i]){
            best = arr[i];
        }
    }
    // YOUR CODE HERE
    return best;
}

// ================================
// MAIN FUNCTION
// ================================
int main() {
    // --- Demo: Default Constructor ---
    Student s1;
    cout << "Default: " << s1 << endl;

    // --- Demo: Parameterized Constructor ---
    Student s2("Ali", 101, 3.5);
    Student s3("Ayse", 102, 3.8);
    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3 << endl;

    // --- Demo: Copy Constructor ---
    Student s4(s2);
    cout << "Copy of s2: " << s4 << endl;

    // --- Demo: Encapsulation (Getters) ---
    cout << "s3 name: " << s3.getName() << endl;
    cout << "s3 GPA: " << s3.getGpa() << endl;

    // --- Demo: Setter Validation ---
    s2.setGpa(5.0);  // Invalid, should not change
    cout << "s2 after invalid setGpa(5.0): " << s2 << endl;

    s2.setGpa(3.9);  // Valid
    cout << "s2 after valid setGpa(3.9): " << s2 << endl;

    // --- Demo: String Operation ---
    cout << "Formatted: " << s3.getFormattedName() << endl;

    // --- Demo: Operator Overloading ---
    cout << "s2 == s4? " << (s2 == s4 ? "Yes" : "No") << endl;
    cout << "s2 < s3? " << (s2 < s3 ? "Yes" : "No") << endl;

    // --- Demo: Function Overloading ---
    Student best2 = findBestStudent(s2, s3);
    cout << "Best of two: " << best2 << endl;

    Student roster[] = {s1, s2, s3, s4};
    Student bestAll = findBestStudent(roster, 4);
    cout << "Best of all: " << bestAll << endl;

    return 0;
}
