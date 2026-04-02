#include <iostream>
#include <string>

class NegativeAgeException {
public:
    const char* message() const {
        return "Age cannot be negative.";
    }
};

class Person {
public:
    std::string name;
    int age;

    Person() : name("Unknown"), age(0) {
        std::cout << "Person constructor executed" << std::endl;
    }

    Person(const std::string& n, int a) : name(n), age(a) {
        if (a < 0) {
            throw NegativeAgeException();
        }
        std::cout << "Person constructor executed" << std::endl;
    }

    virtual void displayInfo() {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }

    virtual void getRole() {
        std::cout << name << " is a person." << std::endl;
    }

    virtual ~Person() {}
};

class Student : virtual public Person {
public:
    std::string major;

    Student() : major("Undeclared") {
        std::cout << "Student constructor executed" << std::endl;
    }

    Student(const std::string& n, int a, const std::string& m) : major(m) {
        name = n;
        age = a;
        std::cout << "Student constructor executed" << std::endl;
    }

    void getRole() override {
        std::cout << name << " is a student majoring in " << major << "." << std::endl;
    }
};

class Employee : virtual public Person {
public:
    std::string position;

    Employee() : position("Unassigned") {
        std::cout << "Employee constructor executed" << std::endl;
    }

    Employee(const std::string& n, int a, const std::string& p) : position(p) {
        name = n;
        age = a;
        std::cout << "Employee constructor executed" << std::endl;
    }

    void getRole() override {
        std::cout << name << " is an employee working as " << position << "." << std::endl;
    }
};

class TeachingAssistant : public Student, public Employee {
public:
    TeachingAssistant(const std::string& n, int a, const std::string& m, const std::string& p)
        : Person(n, a), Student(n, a, m), Employee(n, a, p) {
        std::cout << "TeachingAssistant constructor executed" << std::endl;
    }

    void getRole() override {
        std::cout << name << " is a teaching assistant, major: " << major
                  << ", position: " << position << "." << std::endl;
    }
};

void testDiamondProblem() {
    std::cout << "Testing Diamond ." << std::endl;
    TeachingAssistant ta("Areeb", 22, "Computer Science", "Lab Assistant");
    ta.displayInfo();
    ta.getRole();
}

int main() {
    Person* p = new Student("Hina", 20, "Software Engineering");
    p->displayInfo();
    p->getRole();
    delete p;

    testDiamondProblem();

    std::cout << "\nTesting exception for negative age:" << std::endl;
    try {
        Person invalidPerson("Sara", -5);
    } catch (const NegativeAgeException& ex) {
        std::cout << "Exception caught: " << ex.message() << std::endl;
    }

    return 0;
}
