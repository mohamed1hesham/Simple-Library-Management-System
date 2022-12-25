#include <iostream>
#include<fstream>
#include <conio.h>
using namespace std;
class libraryManagementSystem{
public:
    libraryManagementSystem(){

        ofstream file;
        file.open("d:\\books.txt",ios_base::app);
        file.close();
    }
string adminUser="admin",adminPass="123",ad,ps,myText;
string bookId,bookName,bookAuthor,bookPages;
int choice;
void start();
bool IsLoggedIn();
void registration();
void IamAdmin();
void user();
void exploreBooksUser();
void exploreBooksAdmin();
void addBook();
};
void libraryManagementSystem::start(){
     system("cls");

     cout<<"\n\t*********** Welcome To LIBRARY MANAGEMENT SYSTEM ***********\n";
     cout<<"\n\t\t1.Login\n\n\t\t2.Register\n\n\t\t3.admin\n\n\t\t4.Exit from the Library\n";
     cout<<"\n\t\tEnter your choice: ";
     cin>>choice;
     if(choice==1){
        system("cls");
         cout<<"\n\t*********** Welcome To LIBRARY MANAGEMENT SYSTEM ***********\n";
        bool status=IsLoggedIn();
        if(!status){
            cout<<"\n\t\tUsername Or Password Wrong Try Again\n";
            getch();
            start();
        }else{
        user();
        }
     }else if(choice==2){
        registration();
     }else if(choice==3){
         cout <<"\n\t\tEnter Admin UserName: ";
         cin>>ad;
         cout<<"\n\t\tEnter Admin Password: ";
         cin>>ps;
         if(ad==adminUser&&ps==adminPass){
            IamAdmin();
         }else{
          cout<<"\n\t\tAdmin Username or Admin Password Wrong Enter any key to try again ";
            getch();
            system("CLS");
            start();
         }

     }else if(choice==4){
        exit(0);
     }else{
     cout<<"\n\t\tWrong Choice press enter to try again";
            getch();
            system("CLS");
            start();
     }
}
bool libraryManagementSystem::IsLoggedIn(){
    string username,password,un,pw;
    cout <<"\n\t\tEnter UserName: ";
    cin>>username;
    cout<<"\n\t\tEnter Password: ";cin>>password;
    ifstream read("d:\\"+username+".txt");
    getline(read,un);
    getline(read,pw);
    if(un==username && pw==password){
    return true;
    }else{
    return false;
    }
    }
void libraryManagementSystem::registration(){
string username,password;
    cout<<"\n\t\tselect a username: ";cin>>username;
    cout<<"\n\t\tselect a password: ";cin>>password;
    ofstream file;
    file.open("d:\\"+username+".txt");
    file<<username<<endl<<password;
    file.close();
    cout<<"\n\t\tuser created press Enter to go to home page.";
    getch();
    start();}
void libraryManagementSystem::IamAdmin(){
    system("cls");
cout<<"\n\t*********** Welcome To LIBRARY MANAGEMENT SYSTEM ***********\n";
cout<<"\n\t\twelcome to Administration page ";
cout<<"\n\n\t\t\t1.ADD Books\n\n\t\t\t2.Explore Books\n\n\t\t\t3.LOGOUT";
cout<<"\n\n\t\t\tEnter your choice: ";
cin>>choice;
if(choice==1){
addBook();
}else if(choice==2){
exploreBooksAdmin();
}else if(choice==3){
start();
}else{
cout<<"\n\t\tWrong Choice press enter to try again";
            getch();
            system("CLS");
            user();
}
};
void libraryManagementSystem::user(){
system("cls");
cout<<"\n\t*********** Welcome To LIBRARY MANAGEMENT SYSTEM ***********\n";
cout<<"\n\t\t\tWelcome To User Page ";
cout<<"\n\n\t\t\t1.Explore Books\n\n\t\t\t2.LOGOUT";
cout<<"\n\n\t\t\tEnter your choice: ";
cin>>choice;
if(choice==1){
exploreBooksUser();
}else if(choice==2){
start();
}else{
cout<<"\n\t\tWrong Choice press enter to try again";
            getch();
            system("CLS");
            user();
}
}
void libraryManagementSystem::exploreBooksUser(){
    ifstream MyReadFile("d:\\books.txt");
    while (getline (MyReadFile, myText)) {
    cout << myText<<endl;
}
MyReadFile.close();
cout << "press any button to back"<<endl;
getch();
user();
}
void libraryManagementSystem::exploreBooksAdmin(){
    ifstream MyReadFile("d:\\books.txt");
    while (getline (MyReadFile, myText)) {
    cout << myText<<endl;
}
MyReadFile.close();
cout << "press any button to back"<<endl;
getch();
IamAdmin();
}
void libraryManagementSystem::addBook(){
        cout<<"\n\t\t\tEnter the book id: ";cin>>bookId;
        cout<<"\n\t\t\tEnter the book Name: ";cin>>bookName;
        cout<<"\n\t\t\tEnter the book Author: ";cin>>bookAuthor;
        cout<<"\n\t\t\tEnter the number of book Pages: ";cin>>bookPages;
        ofstream file;
        file.open("d:\\books.txt",ios_base::app);
        file<<"\nBookID: "<<bookId;
        file<<"\nBook Name: "<<bookName;
        file<<"\nBook Author: "<<bookAuthor;
        file<<"\nBook Pages: "<<bookPages<<endl;
        file.close();
        cout<<"\n\t\t\tBook ADDED";
        getch();
        IamAdmin();
}
  int main() {
libraryManagementSystem library;
library.start();
}
