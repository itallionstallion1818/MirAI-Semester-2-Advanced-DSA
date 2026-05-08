#include <iostream>
#include <string>

using namespace std;

// ==========================================
// 1. THE BASE CLASS (Parent)
// ==========================================
class Employee {
protected:
    // We use 'protected' so child classes can access these directly!
    string name;
    int employeeID;
    double baseSalary;

public:
    // Base Class Constructor
    Employee(string n, int id, double salary) {
        name = n;
        employeeID = id;
        baseSalary = salary;
        cout << "[System] Employee " << name << " added to database.\n";
    }

    // A shared behavior that ALL employees have
    void clockIn() {
        cout << name << " (ID: " << employeeID << ") has clocked in for the day.\n";
    }

    // Base Destructor
    ~Employee() {
        cout << "[System] Employee " << name << " removed.\n";
    }
};

// ==========================================
// 2. THE DERIVED CLASS (Child 1)
// ==========================================
// Developer inherits EVERYTHING from Employee
class Developer : public Employee {
private:
    string programmingLanguage;

public:
    // Child Constructor
    // We MUST pass the core details up to the Employee constructor!
    Developer(string n, int id, double salary, string lang) 
        : Employee(n, id, salary) { 
        
        programmingLanguage = lang;
        cout << "   -> Assigned Role: Developer (" << lang << ")\n";
    }

    // Unique behavior only Developers have
    void writeCode() {
        cout << name << " is furiously typing " << programmingLanguage << " code...\n";
    }
};

// ==========================================
// 3. ANOTHER DERIVED CLASS (Child 2)
// ==========================================
class Manager : public Employee {
private:
    int teamSize;

public:
    Manager(string n, int id, double salary, int size) 
        : Employee(n, id, salary) {
        
        teamSize = size;
        cout << "   -> Assigned Role: Manager (Team size: " << teamSize << ")\n";
    }

    // Unique behavior only Managers have
    void holdMeeting() {
        cout << name << " is holding a meeting with " << teamSize << " team members.\n";
    }
};

// ==========================================
// DRIVER CODE
// ==========================================
int main() {
    cout << "--- ONBOARDING NEW HIRES ---\n";
    Developer dev1("Alice", 101, 80000, "C++");
    Manager mgr1("Bob", 102, 120000, 5);

    cout << "\n--- MORNING ROUTINE (Inherited Methods) ---\n";
    // Notice how dev1 and mgr1 can use clockIn() even though 
    // it was never written inside the Developer or Manager classes!
    dev1.clockIn();
    mgr1.clockIn();

    cout << "\n--- DAILY TASKS (Unique Methods) ---\n";
    dev1.writeCode();
    // dev1.holdMeeting(); // ❌ ERROR: Developers don't have this method!
    
    mgr1.holdMeeting();
    // mgr1.writeCode();   // ❌ ERROR: Managers don't have this method!

    cout << "\n--- END OF DAY ---\n";
    return 0;
}