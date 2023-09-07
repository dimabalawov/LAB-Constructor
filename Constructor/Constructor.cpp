#include <iostream>
using namespace std;
class Student
{
private:
    char* name;
    char* email;
    int age;
public:
    Student()
    {
        cout << "Constructor by default" << endl;
        name = nullptr;
        email = nullptr;
        age = 0;
    }
    Student(const char* n, const char* e, int a)
    {
        name = new char[strlen(n) + 1];
        strcpy_s(name, strlen(n) + 1, n);
        email = new char[strlen(e) + 1];
        strcpy_s(email, strlen(e) + 1, e);
        age = a;
        cout << "Constructor with 3 params" << endl;
    }
    ~Student()
    {
        delete[]name;//явно освобождаем память при уничтожении объекта
        delete[]email;//явно освобождаем память при уничтожении объекта
        cout << "Destructor" << endl;
    }
    void setEmail(const char* e)
    {
        if (email != nullptr)
        {
            cout << "Delete -> " << email << "..." << endl;
            delete[]email;
        }
        email = new char[strlen(e) + 1];
        strcpy_s(email, strlen(e) + 1, e);
    }
    void setName(const char* n)
    {
        if (name != nullptr)
        {
            cout << "Delete -> " << name << "..." << endl;
            delete[]name;
        }
        name = new char[strlen(n) + 1];
        strcpy_s(name, strlen(n) + 1, n);
    }
    void setAge(int a)
    {
        age = a;
    }
    char* getEmail()
    {
        return email;
    }
    char* getName()
    {
        return name;
    }
    int getAge()
    {
        return age;
    }
    void input()
    {
        char buff[20];
        cout << "Enter name: " << endl;
        cin >> buff;
        if (name != nullptr)
        {
            cout << "Delete -> " << name << "..." << endl;
            delete[]name;
        }
        name = new char[strlen(buff) + 1];
        strcpy_s(name, strlen(buff) + 1, buff);
        cout << "Enter email: " << endl;
        cin >> buff;
        if (email != nullptr)
        {
            cout << "Delete -> " << email << "..." << endl;
            delete[]email;
        }
        email = new char[strlen(buff) + 1];
        strcpy_s(email, strlen(buff) + 1, buff);
        cout << "Enter age:";
        cin >> age;
    }
    void print()
    {
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "Age: " << age << endl;
    }
};
int main()
{
    Student b("Dima","dimabalawov@gmail.com", 20);
    b.print();
}