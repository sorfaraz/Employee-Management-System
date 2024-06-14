#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // For exit()
#include <ctime>   // For sleep

using namespace std;

#define ll long long int

class node
{
public:
    string firstName, lastName, contact, employeeID, department, gender, address, salary, joiningDate;
    node *next;
    node(string iFirstName, string iLastName, string ContactNumber, string EmployeeId, string Department, string Gender, string Address, string Salary, string JoiningDate)
    {
        firstName = iFirstName;
        lastName = iLastName;
        contact = ContactNumber;
        employeeID = EmployeeId;
        department = Department;
        gender = Gender;
        address = Address;
        salary = Salary;
        joiningDate = JoiningDate;

        next = NULL;
    }
};
typedef node *nodePtr;

void writeInTheFile(nodePtr &head)
{
    ofstream file("finalProjectFile.txt");
    if (!file.is_open())
    {
        cerr << "Error: Unable to open file for writing." << endl;
        exit(1);
    }
    nodePtr temp;
    temp = head;
    while (temp != NULL)
    {
        file << temp->firstName << " ";
        file << temp->lastName << " ";
        file << temp->contact << " ";
        file << temp->employeeID << " ";
        file << temp->department << " ";
        file << temp->gender << " ";
        file << temp->address << " ";
        file << temp->salary << " ";
        file << temp->joiningDate << endl;

        temp = temp->next;
    }
    file.close();
}

int checkid(string uid)
{
    ifstream file("finalProjectFile.txt");
    string iFirstName, iLastName, ContactNumber, EmployeeId, Department, Gender, Address, Salary, JoiningDate;
    while (file >> iFirstName >> iLastName >> ContactNumber >> EmployeeId >> Department >> Gender >> Address >> Salary >> JoiningDate)
    {
        if (uid == EmployeeId)
        {
            file.close();
            return 0;
        }
    }
    file.close();
    return 1;
}

void addEmployee(nodePtr &head)
{
    string iFirstName, iLastName, ContactNumber, EmployeeId, Department, Gender, Address, Salary, JoiningDate;
    cout << endl
         << endl
         << "\t\tEnter Firstname-> ";
    cin >> iFirstName;
    cout << "\t\tEnter Lastname-> ";
    cin >> iLastName;
    cout << "\t\tEnter Contact Number-> ";
    cin >> ContactNumber;
    cout << "\t\tEnter Employee ID-> ";
    cin >> EmployeeId;
    cout << "\t\tEnter Department-> ";
    cin >> Department;
    cout << "\t\tEnter Gender-> ";
    cin >> Gender;
    cout << "\t\tEnter Address-> ";
    cin >> Address;
    cout << "\t\tEnter Salary-> ";
    cin >> Salary;
    cout << "\t\tEnter Joining Date-> ";
    cin >> JoiningDate;

    if (checkid(EmployeeId) == 0)
    {
        cout << endl
             << endl
             << "\t\tID Already Exists!!" << endl;
        return;
    }

    nodePtr newNode = new node(iFirstName, iLastName, ContactNumber, EmployeeId, Department, Gender, Address, Salary, JoiningDate);
    if (head == NULL)
    {
        head = newNode;
        writeInTheFile(head);
        cout << endl
             << endl
             << "\t\tEmployee Added Successfully" << endl;
        return;
    }
    nodePtr temp;
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    writeInTheFile(head);
    cout << endl
         << endl
         << "\t\tEmployee Added Successfully" << endl;
}

void display(nodePtr head)
{
    if (head == NULL)
    {
        cout << endl
             << endl
             << "\t\tNo Employees Found" << endl;
        return;
    }
    ifstream file("finalProjectFile.txt");
    string iFirstName, iLastName, ContactNumber, EmployeeId, Department, Gender, Address, Salary, JoiningDate;
    cout << endl
         << "\t\tEmployee List" << endl
         << endl;
    cout << "\t-----------------------------------" << endl;
    while (file >> iFirstName >> iLastName >> ContactNumber >> EmployeeId >> Department >> Gender >> Address >> Salary >> JoiningDate)
    {
        cout << endl
             << "\t\tName : " << iFirstName << " " << iLastName << endl;
        cout << "\t\tContact Number : " << ContactNumber << endl;
        cout << "\t\tEmployee ID : " << EmployeeId << endl;
        cout << "\t\tDepartment : " << Department << endl;
        cout << "\t\tGender : " << Gender << endl;
        cout << "\t\tAddress : " << Address << endl;
        cout << "\t\tSalary : " << Salary << endl;
        cout << "\t\tJoining Date : " << JoiningDate << endl
             << endl
             << endl;
    }
    file.close();
}

int main()
{
    nodePtr head = NULL;

    ll enter;
    string aUsername = "admin", aPassword = "admin";
    do
    {
        cout << endl
             << endl;
        cout << "\t\t\t1. Admin Login" << endl;
        cout << "\t\t\t0. Exit" << endl
             << endl;
        cout << "\t\tEnter Choice-> ";
        cin >> enter;
        if (enter == 1)
        {
            string username, password;
            cout << endl
                 << "\t\tEnter Username-> ";
            cin >> username;
            cout << "\t\tEnter Password-> ";
            cin >> password;
            if (username == aUsername && password == aPassword)
            {
                cout << endl
                     << "\t\tLogin Successfully" << endl;
                ll choice;
                do
                {
                    cout << endl
                         << endl
                         << "\t\t\*******************DASHBOARD**********************" << endl;
                    cout << endl
                         << endl
                         << "\t\t\t1. Add Employee" << endl;
                    cout << "\t\t\t2. View List Of Employee" << endl;
                    cout << "\t\t\t3. Exit" << endl
                         << endl
                         << endl;
                    cout << "\t\tEnter choice-> ";
                    cin >> choice;
                    switch (choice)
                    {
                    case 1:
                        addEmployee(head);
                        break;
                    case 2:
                        display(head);
                        break;
                    case 3:
                        exit(0);
                    default:
                        cout << "\t\tInvalid choice!" << endl;
                    }
                } while (choice != 3);
            }
            else
            {
                cout << endl
                     << "\t\tPlease Enter Correct Credentials!!" << endl;
            }
        }
        else if (enter == 0)
        {
            break;
        }
        else
        {
            cout << endl
                 << endl
                 << "\t\t\tInvalid choice" << endl;
        }
    } while (enter != 0);

    return 0;
}

