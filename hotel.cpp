#include<iostream>
#include<conio.h>
#include<fstream>
#include<direct.h>  //dos.h in some ide
#include<stdlib.h>
#include<string.h>
using namespace std;
class ht
{   int room_no;
    char name[30];
    char address[50];
    char phone[15];

    public:
    void logo();//to display hotel logo
    void add();        //to book a room
    void display();    //to display the customer
    void rooms();    //to display alloted rooms
    void edit();    //to edit the customer record
    int check(int);    //to check room status
    void modify(int);    //to modify the record
    void delete_rec(int);    //to delete the record

};
class hotel:public ht//main class
{
public:
void main_menu();
};

void hotel::main_menu()
{
    int choice;

    while(choice!=5)
    {   system("cls");
        logo();
        cout<<"\n\t\t\t\t**************** MAIN MENU *******************";
        cout<<"\n\t\t\t\t**********************************************";
        cout<<"\n\t\t\t\t************ 1.Book A Room *******************";
        cout<<"\n\t\t\t\t************ 2.Status of Room ****************";
        cout<<"\n\t\t\t\t************ 3.Rooms Allotted ****************";
        cout<<"\n\t\t\t\t************ 4.Edit Record *******************";
        cout<<"\n\t\t\t\t************ 5.Exit **************************";
        cout<<"\n\t\t\t\t**********************************************";
        cout<<"\n\t\t\t\t**********************************************";
        cout<<"\n\t\t\t\t**********************************************";
        cout<<"\n\n\t\t\tEnter Your Choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1: system("cls");add();
                    break;
            case 2: system("cls");display();
                    break;
            case 3: system("cls");rooms();
                    break;
            case 4: system("cls");edit();
                    break;
            case 5: exit(0);break;
            default:
                    {
                        cout<<"\n\n\t\t\tWrong choice!!!";
                        cout<<"\n\t\t\tPress any key to continue!!";
                        _getch();
                    }
        }
    }
}
void ht::logo()
{

cout<<"\n\t\t\t████████╗ █████╗      ██╗      ██╗  ██╗ ██████╗ ████████╗███████╗██╗";
cout<<"\n\t\t\t╚══██╔══╝██╔══██╗     ██║      ██║  ██║██╔═══██╗╚══██╔══╝██╔════╝██║";
cout<<"\n\t\t\t   ██║   ███████║     ██║█████╗███████║██║   ██║   ██║   █████╗  ██║";
cout<<"\n\t\t\t   ██║   ██╔══██║██   ██║╚════╝██╔══██║██║   ██║   ██║   ██╔══╝  ██║";
cout<<"\n\t\t\t   ██║   ██║  ██║╚█████╔╝      ██║  ██║╚██████╔╝   ██║   ███████╗███████╗";
cout<<"\n\t\t\t   ╚═╝   ╚═╝  ╚═╝ ╚════╝       ╚═╝  ╚═╝ ╚═════╝    ╚═╝   ╚══════╝╚══════╝";
}
void ht::add()
{

    int r,flag;
    ofstream fout("Record.txt",ios::app);
    logo();
    cout<<"\n Enter Customer Detalis";
    cout<<"\n **********************";
    cout<<"\n\n Room no: ";
    cin>>r;
    flag=check(r);

    if(flag)
        cout<<"\n Sorry..!!!Room is already booked";
    else
    {
        room_no=r;
        cout<<" Name: ";
        cin>>name;
        cout<<" Address: ";
        cin>>address;
        cout<<" Phone No: ";
        cin>>phone;
        fout.write((char*)this,sizeof(hotel));
        cout<<"\n Room is booked!!!";
    }

    cout<<"\n Press any key to continue!!";
    _getch();
    fout.close();
}

void ht::display()
{
    logo();
    ifstream fin("Record.txt",ios::in);
    int r,flag;
    cout<<"\n Enter room no: ";
    cin>>r;

    while(!fin.eof())
    {
        fin.read((char*)this,sizeof(hotel));
        if(room_no==r)
        {

            cout<<"\n Customer Details";
            cout<<"\n ****************";
            cout<<"\n\n Room no: "<<room_no;
            cout<<"\n Name: "<<name;
            cout<<"\n Address: "<<address;
            cout<<"\n Phone no: "<<phone;
            flag=1;
            break;
        }
    }

    if(flag==0)
        cout<<"\n Sorry Room no. not found or vacant!!";

    cout<<"\n\n Press any key to continue!!";
    _getch();
    fin.close();
}

void ht::rooms()
{

    ifstream fin("Record.txt",ios::in);
    logo();
    cout<<"\n\t\t\tList Of Rooms Allotted";
    cout<<"\n\t\t\t*********************";
    cout<<"\n\n Room No.\tName\t\tAddress\t\tPhone No.\n";

    /*while(!fin.eof())
    {
        fin.read((char*)this,sizeof(hotel));
        cout<<"\n\n "<<room_no<<"\t\t"<<name<<"\t\t"<<address<<"\t\t"<<phone;
    }*/
    while(true)
    {
        if(!fin.read((char*)this,sizeof(hotel)))
        break;
        cout<<"\n\n "<<room_no<<"\t\t"<<name<<"\t\t"<<address<<"\t\t"<<phone;
    }

    cout<<"\n\n\n\t\t\tPress any key to continue!!";
    _getch();
    fin.close();
}

void ht::edit()
{

    int choice,r;
logo();
    cout<<"\n EDIT MENU";
    cout<<"\n *********";
    cout<<"\n\n 1.Modify Customer Record";
    cout<<"\n 2.Delete Customer Record";

    cout<<"\n Enter your choice: ";
    cin>>choice;


    cout<<"\n Enter room no: ";
    cin>>r;

    switch(choice)
    {
        case 1: modify(r);
                break;
        case 2: delete_rec(r);
                break;
        default: cout<<"\n Wrong Choice!!";
    }

    cout<<"\n Press any key to continue!!!";
    _getch();
}

int ht::check(int r)
{
    int flag=0;
    ifstream fin("Record.txt",ios::in);
    while(!fin.eof())
    {
        fin.read((char*)this,sizeof(hotel));
        if(room_no==r)
        {
            flag=1;
            break;
        }
    }

    fin.close();
    return(flag);
}

void ht::modify(int r)
{
    long pos,flag=0;
    fstream file("Record.txt",ios::in|ios::out|ios::binary);

    while(!file.eof())
    {
        pos=file.tellg();
        file.read((char*)this,sizeof(hotel));
        if(room_no==r)
        {
            cout<<"\n Enter New Details";
            cout<<"\n *****************";
            cout<<"\nName: ";
            cin>>name;
            cout<<"Address: ";
            cin>>address;
            cout<<"Phone no: ";
            cin>>phone;

            file.seekg(pos);
            file.write((char*)this,sizeof(hotel));
            cout<<"\n Record is modified!!";
            flag=1;
            break;
        }
    }

    if(flag==0)
        cout<<"\n Sorry Room no. not found or vacant!!";

    file.close();
}

void ht::delete_rec(int r)
{
    int flag=0;
    char ch;
    ifstream fin("Record.txt",ios::in);
    ofstream fout("temp.txt",ios::out);

    while(!fin.eof())
    {
        fin.read((char*)this,sizeof(hotel));
        if(room_no==r)
        {
            cout<<"\n Name: "<<name;
            cout<<"\n Address: "<<address;
            cout<<"\n Phone No: "<<phone;
            cout<<"\n\n Do you want to delete this record(y/n): ";
            cin>>ch;

            if(ch=='n')
            fout.write((char*)this,sizeof(hotel));

            flag=1;
        }
        else
            fout.write((char*)this,sizeof(hotel));
    }

    fin.close();
    fout.close();

    if(flag==0)
        cout<<"\n Sorry room no. not found or vacant!!";
    else
    {
        remove("Record.txt");
        rename("temp.txt","Record.txt");
    }
}

int main()
{

    hotel h;

    cout<<"\n\t\t\t\t**********************************************";
    cout<<"\n\t\t\t\t******** HOTEL ROOM MANAGEMENT SYSTEM ********";
    cout<<"\n\t\t\t\t******************USING C++*******************";
    cout<<"\n\t\t\t\t**********************************************";
    cout<<"\n\t\t\t\t**************Created By MOHIT****************";
    cout<<"\n\t\t\t\t****************MCA 2nd Sem*******************";
    cout<<"\n\t\t\t\t**********************************************";
    cout<<"\n\t\t\t\t**********************************************";
    cout<<"\n\t\t\t\t*****************GUIDED BY********************";
    cout<<"\n\t\t\t\t**************MRS. SONAL CHAWLA***************";
    cout<<"\n\t\t\t\t**********************************************";

    cout<<"\n\t\t\t\t**********************************************";
    cout<<"\n\t\t\t\t**********************************************";
    cout<<"\n\t\t\t\t**********************************************";
    cout<<"\n\t\t\t\t**********************************************";

    cout<<"\n\n\n\n\n\t\t\t\t\tPress any key to continue!!";
    _getch();
    system("cls");
    char id[5],pass[7];
    login:

cout<<"\t\t\t\t────────────────────────────────────────────────";
cout<<"\n\t\t\t\t─██████████████──██████████████──────────██████─";
cout<<"\n\t\t\t\t─██░░░░░░░░░░██──██░░░░░░░░░░██──────────██░░██─";
cout<<"\n\t\t\t\t─██████░░██████──██░░██████░░██──────────██░░██─";
cout<<"\n\t\t\t\t─────██░░██──────██░░██──██░░██──────────██░░██─";
cout<<"\n\t\t\t\t─────██░░██──────██░░██████░░██──────────██░░██─";
cout<<"\n\t\t\t\t─────██░░██──────██░░░░░░░░░░██──────────██░░██─";
cout<<"\n\t\t\t\t─────██░░██──────██░░██████░░██──██████──██░░██─";
cout<<"\n\t\t\t\t─────██░░██──────██░░██──██░░██──██░░██──██░░██─";
cout<<"\n\t\t\t\t─────██░░██──────██░░██──██░░██──██░░██████░░██─";
cout<<"\n\t\t\t\t─────██░░██──────██░░██──██░░██──██░░░░░░░░░░██─";
cout<<"\n\t\t\t\t─────██████──────██████──██████──██████████████─";
cout<<"\n\t\t\t\t────────────────────────────────────────────────";
    cout<<"\n\t\t\t\t**********************************************";
    cout<<"\n\t\t\t\t**********************************************";
    cout<<"\n\t\t\t\t************ENTER LOGIN DETAILS***************";
    cout<<"\n\t\t\t\t**********************************************";
	cout<<"\n\t\t\t\t\tUSERNAME  => ";
	cin>>id;
	cout<<"\n\t\t\t\t\tPASSWORD => ";
	cin>>pass;
	cout<<"\n\t\t\t\t**********************************************";
	cout<<"\n\t\t\t\t**********************************************";
	cout<<"\n\t\t\t\t**********************************************";
	cout<<"\n\t";
	if(strcmp(id,"mohit")==0&&strcmp(pass,"123456")==0)
		{cout<<"\n\n\t\t\t\t\t!!!LOGIN SUCCESSFULL!!!\n\t\t\t\t\tPress any key to continue";
		_getch();
        }
	else {
		cout<<"\n\n\t\t\t\t!!!!USERNAME OR PASSWORD IS NOT CORRECT!!!!\n\t\t\t\t   !!!!Please Enter Credentials Again!!!!";
		_getch();
		system("cls");
		goto login;
		exit(-1);
	}
    h.main_menu();
}
