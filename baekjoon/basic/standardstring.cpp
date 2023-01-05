#include <iostream>
#include <string>


class Employee {
    std::string name;
    int age;

    std::string position;
    int rank;

    public:
    Employee(std::string name, int age, std::string position, int rank)
    : name(name), age(age), position(position), rank(rank) {}

    Employee(const Employee& employee) {
        name = employee.name;
        age = employee.age;
        position = employee.position;
        rank = employee.rank;
    }

    Employee() {}

    void print_info() {
        std::cout << name << " (" << position 
        << " , " << age << ") ==>" 
        << calculate_pay() << "K Won"
        << std::endl;
    }
    int calculate_pay() {return 200 + rank * 50; }
};

class Manager {
    std::string name;
    int age;

    std::string position;
    int rank;
    int year_of_service;

    public:
    Manager(std::string name, int age, std::string position, int rank, int year_of_service)
    : year_of_service(year_of_service),
      name(name),
      age(age),
      position(position),
      rank(rank) {}
    
    Manager(const Manager& manager) {
        name = manager.name;
        age = manager.age;
        position = manager.position;
        rank = manager.rank;
        year_of_service = manager.year_of_service;
    }

    Manager() {}

    int calculate_pay() {return 200 + rank * 50 + 5 * year_of_service; }
    void print_info() {
        std::cout << name << " (" << position << " , " << age <<", "
                  << year_of_service << "years) ==> " << calculate_pay() << "K Won"
                  << std::endl;
    }
};

class EmployeeList {
    int alloc_employee;

    int current_employee;
    int current_manager;
    Employee** employee_list;
    Manager** manager_list;

    public:
    EmployeeList(int alloc_employee) : alloc_employee(alloc_employee) {
        employee_list = new Employee*[alloc_employee];
        current_employee = 0;
    }
    void add_employee(Employee* employee) {
        employee_list[current_employee] = employee;
        current_employee++;
    }
    int current_employee_num() { return current_employee; }

    void print_employee_info() {
        int total_pay = 0;
        for (int i = 0; i < current_employee; i++) {
            employee_list[i]->print_info();
            total_pay += employee_list[i]->calculate_pay();
        }
        std::cout << "Total pay : " << total_pay << "K Won" << std::endl; 
    }
    ~EmployeeList() {
        for (int i = 0; i < current_employee; i++) {
            delete employee_list[i];
        }
        delete[] employee_list;
    }
};




int main() {
    EmployeeList emp_list(10);
    emp_list.add_employee(new Employee("Mr. No", 34, "Plain", 1));
    emp_list.add_employee(new Employee("Mr. Ha", 34, "Plain", 1));
    emp_list.add_employee(new Employee("Mr. Yoo", 41, "Head", 7));
    emp_list.add_employee(new Employee("Mr. Jung", 43, "Sect", 4));
    emp_list.add_employee(new Employee("Mr. Park", 34, "Deputy", 5));
    emp_list.add_employee(new Employee("Mr. JungHD", 36, "Assist", 2));
    emp_list.add_employee(new Employee("Mr. Gil", 36, "Intern", -2));
    emp_list.print_employee_info();

    return 0;
}