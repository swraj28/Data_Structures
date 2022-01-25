#include <bits/stdc++.h>
using namespace std;

//Unordered Map does not contain a hash function for any custom made class or custom datatype like pair,vector.It has for int, string, etc,
//So if we want to hash a custom class or custom datatype then we have to explicitly provide it with a hash function that can hash a custom class.
class Student {
public:
    string firstname;
    string lastname;
    string rollno;

    Student(string f, string l, string no) {
        firstname = f;
        lastname  = l;
        rollno = no;
    }

    // If two students have the same name then comaprison will be done on the basis of roll no.(i.e if two keys are equal)
    // This (==) operator has been defined to avoid collisions.
    bool operator==(const Student &s)const {
        return rollno == s.rollno ? true : false;
    }
};

class HashFn {
public:

    size_t operator()(const Student &s) const {
        return s.firstname.length() + s.lastname.length();
    }
};


int main() {

    unordered_map<Student, int, HashFn> student_map;

    Student s1("Prateek", "Narang", "010");
    Student s2("Rahul", "Kumar", "023");
    Student s3("Prateek", "Gupta", "030");
    Student s4("Rahul", "Kumar", "120");

    student_map[s1] = 100;
    student_map[s2] = 120;
    student_map[s3] = 11;
    student_map[s4] = 45;

    // to get the marks of a particular student
    cout << student_map[s3] << endl;

    for (auto s : student_map) {
        cout << s.first.firstname << " " << s.first.rollno << endl << "Marks" << s.second << endl;
    }

    return 0;
}


// Implement a HashFunction for pairs,vectors.