#include<bits/stdc++.h>
using namespace std;


void showMenu() {
    cout << "===== Student DB =====" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Delete student" << endl;
    cout << "3. Update student" << endl;
    cout << "4. List students" << endl;
    cout << "0. Exit" << endl;
}
void addStudent()
{
    cout<<"The relevant function will be developed"<<endl;
}
void deleteStudent()
{
    cout<<"The relevant function will be developed"<<endl;
}
void updateStudent()
{
    cout<<"The relevant function will be developed"<<endl;
}
void listStudents()
{
    cout<<"The relevant function will be developed"<<endl;
}

int main()
{
    int choice;
    while(choice)
    {
        showMenu();
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"\n[Add Student] Selected"<<endl;
                addStudent();
                break;
            case 2:
                cout << "\n[Delete Student] Selected"<<endl;
                deleteStudent();
                break;
            case 3:
                cout << "\n[Update Student] Selected"<<endl;
                updateStudent();
                break;
            case 4:
                cout << "\n[List Students] Selected"<<endl;
                listStudents();
                break;
            case 0:
                cout<<"\n[Exit] Thank you for using Student DB!"<<endl;
                break;
            default:
                cout<<"\n[Error] Invalid choice! Please enter 0-4."<<endl;
                break;
         }
    }

    return 0;
}