#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <cstdio>
using namespace std;
class pass
{
public:
    char p[20];
    void password(int x)
    {
        if (x == 1234)
        {
            cout << "\nEnter password(less than 10 characters)";
            cin.ignore();
            cin.getline(p, 20);
            fstream wr;
            wr.open("pass.txt", ios::out);
            wr.write((char *)this, sizeof(pass));
            wr.close();
        }
        else
        {
            cout << "\n Error 404";
        }
    }
} obj1;
class hotel
{
public:
    int room_no;
    char date[15];
    char date1[15];
    char name[30];
    char mob[15];
    char adr[15];
    char adress[50];

    void accept()
    {
        cin.ignore();
        cout << "\nEnter date ";
        cin.getline(date, 15);
        cout << "\nEnter full name ";
        cin.getline(name, 30);
        cout << "\nEnter mobile number ";
        cin.getline(mob, 15);
        cout << "\nEnter adhar card number ";
        cin.getline(adr, 15);
        cout << "\nEnter address ";
        cin.getline(adress, 50);
    }
    void display()
    {
        cout << "\nRoom number:       " << room_no;
        cout << "\nName:              " << name;
        cout << "\nMobile number:     " << mob;
        cout << "\nAdhar card number: " << adr;
        cout << "\nAddress:           " << adress;
        cout << "\n----------------------------";
    }
} obj;
int check(int r)
{
    int flag = 1;
    fstream rd;
    rd.open("record.txt", ios::in);
    rd.seekg(0, ios::end);
    int n = rd.tellg();
    n = n / sizeof(obj);
    
    rd.seekg(0, ios::beg);
    for (int i = 1; i <= n; i++)
    {
        rd.read((char *)&obj, sizeof(obj));
        if (r == obj.room_no)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}
void alotroom()
{
    int r, c;
    cout << "\nEnter room number ";
    cin >> r;
    c = check(r);
    if (c == 0)
    {
        cout << "\nROOM ALREADY BOOKED";
    }
    else
    {
        obj.room_no = r;
        obj.accept();
        fstream wr;
        wr.open("record.txt", ios::app);
        wr.write((char *)&obj, sizeof(obj));
    }
}
//void roomstatus()
//{
//    char p1[20];
//    fstream rdp;
//    rdp.open("pass.txt", ios::in);
//    rdp.read((char *)&obj1, sizeof(pass));
//    cout << "\nEnter password ";
//    for (int i = 0; i < strlen(obj1.p); i++)
//    {
//        p1[i] = getch();
//        cout << "*";
//    }
//    p1[strlen(obj1.p)] = '\0';
//    if (stricmp(p1, obj1.p) == 0)
//    {
//        fstream rd;
//        rd.open("record.txt", ios::in);
//        rd.seekg(0, ios::end);
//        int n = rd.tellg();
//        n = n / sizeof(obj);
//        rd.seekg(0, ios::beg);
//        for (int i = 1; i <= n; i++)
//        {
//            rd.read((char *)&obj, sizeof(obj));
//            obj.display();
//        }
//    }
//    else
//    {
//        cout << "\nPassword Mismatch";
//    }
//}
void rstatus()
{
    fstream rd;
    rd.open("record.txt", ios::in);
    rd.seekg(0, ios::end);
    int n = rd.tellg();
    cout<<n<<endl<<sizeof(obj)<<endl;
    n = n / sizeof(obj);
    cout<<n<<endl;
    if(n == 0)
    {
    	cout<<"\n\n!!! ALL ROOMS ARE EMPTY !!!";
    	return;
	}
    rd.seekg(0, ios::beg);
    for (int i = 1; i <= n; i++)
    {
        rd.read((char *)&obj, sizeof(obj));
        cout << "\nRoom number       " << obj.room_no;
        cout << "\nName              " << obj.name;
        cout << "\nMobile number     " << obj.mob;
        cout << "\n----------------------------";
    }
    rd.close();
}
void edit()
{
    int rno;
    cout << "\nEnter room number";
    cin >> rno;
    fstream wr, rd;
    rd.open("record.txt", ios::in);
    wr.open("temp.txt", ios::out);
    rd.seekg(0, ios::end);
    int n = rd.tellg();
    n = n / sizeof(obj);
    if(n == 0)
    {
    	cout<<"\n\n!!! ALL ROOMS ARE EMPTY !!!";
    	return;
	}
    rd.seekg(0, ios::beg);
    for (int i = 1; i <= n; i++)
    {
        rd.read((char *)&obj, sizeof(obj));
        if (obj.room_no == rno)
        {
            cout << "\nEnter new room number ";
            cin >> rno;
            obj.room_no = rno;
            obj.accept();
            wr.write((char *)&obj, sizeof(obj));
        }
        else
        {
            wr.write((char *)&obj, sizeof(obj));
        }
    }
    rd.close();
    wr.close();
    remove("record.txt");
    rename("temp.txt", "record.txt");
}
void roominfo()
{
    int r;
    cout << "\nEnter room number";
    cin >> r;
    fstream rd;
    rd.open("record.txt", ios::in);
    rd.seekg(0, ios::end);
    int n = rd.tellg();
    n = n / sizeof(obj);
    if(n == 0)
    {
    	cout<<"\n\n!!! ALL ROOMS ARE EMPTY !!!";
    	return;
	}
    rd.seekg(0, ios::beg);
    for (int i = 1; i <= n; i++)
    {
        rd.read((char *)&obj, sizeof(obj));
        if (r == obj.room_no)
        {
            cout << "\nRoom number       " << obj.room_no;
            cout << "\nName              " << obj.name;
            cout << "\nMobile number     " << obj.mob;
            cout << "\n----------------------------";
            return;
        }
    }
    cout << "\nSorry room empty";
}
void customerinfo()
{
    char na[30];
    cin.ignore();
    cout << "\nEnter name";
    cin.getline(na, 30);
    fstream rd;
    rd.open("record.txt", ios::in);
    rd.seekg(0, ios::end);
    int n = rd.tellg();
    n = n / sizeof(obj);
    if(n == 0)
    {
    	cout<<"\n\n!!! ALL ROOMS ARE EMPTY !!!";
    	return;
	}
    rd.seekg(0, ios::beg);
    for (int i = 1; i <= n; i++)
    {
        rd.read((char *)&obj, sizeof(obj));
        if (stricmp(obj.name, na) == 0)
        {
            cout << "\nRoom number       " << obj.room_no;
            cout << "\nName              " << obj.name;
            cout << "\nMobile number     " << obj.mob;
            cout << "\n----------------------------";
            return;
        }
    }
    cout << "\nSorry customer details not found";
}
void leaveroom()
{
    int rno;
    cout << "\nEnter room number ";
    cin >> rno;
    int varun = 0;
    fstream rd, wr, nwr;
    rd.open("record.txt", ios::in);
    wr.open("temp.txt", ios::app);
    nwr.open("prevreco.txt", ios::app);
    rd.seekg(0, ios::end);
    int n = rd.tellg();
    n = n / sizeof(obj);
    if(n == 0)
    {
    	cout<<"\n\n!!! ALL ROOMS ARE EMPTY !!!";
    	rd.close();
    	wr.close();
    	return;
	}
    rd.seekg(0, ios::beg);
    for (int i = 1; i <= n; i++)
    {
        rd.read((char *)&obj, sizeof(obj));
        if (obj.room_no == rno)
        {
			varun = 1;
            cin.ignore();
            cout << "\nEnter checkout date ";
            cin.getline(obj.date1, 15);
            nwr.write((char *)&obj, sizeof(obj));
            
        }
        else
        {
            wr.write((char *)&obj, sizeof(obj));
        }
    }
    rd.close();
    wr.close();
    remove("record.txt");
    rename("temp.txt", "record.txt");
    if(varun)
    {
    	cout<<"   \n Room left successfully   ";
	}
	else
    	cout<<"!!! THIS ROOM IS NOT OCCUPIED !!!";
    
}
void oldreco()
{
	char p1[100];
    
    cout << "\nEnter password ";
    for (int i = 0; i < strlen(obj1.p); i++)
    {
        p1[i] = getch();
        cout << "*";
    }
    p1[strlen(obj1.p)] = '\0';
    if (stricmp(p1, obj1.p) == 0)
    {
    	fstream rd;
	    rd.open("prevreco.txt", ios::in);
	    rd.seekg(0, ios::end);
	    int n = rd.tellg();
	    n = n / sizeof(obj);
	    if(n == 0)
	    {
	    	cout<<"\n\n!!! NO PREVIOUS RECORDS !!!";
	    	return;
		}
	    rd.seekg(0, ios::beg);
	    for (int i = 1; i <= n; i++)
	    {
	        rd.read((char *)&obj, sizeof(obj));
	        obj.display();
	        cout << "\nCheckout date " << obj.date1;
	    }
	}
	else
	{
		cout<<"\n\n!!! INCORRECT PASSWORD !!!";
	}
}
int main()
{
    int e = 1, x;
    cout << endl
         << endl
         << endl
         << endl
         << endl
         << "\t\t\t loading";
    cout << ".";
    Sleep(1000);
    cout << ".";
    Sleep(1000);
    cout << ".";
    Sleep(1000);
    cout << ".";

    while (e != 0)
    {
        system("cls");
        cout << "\n\t\tWELCOME to the Ritz \n \n\n";
        system("Color 06");
//        getchar();
		Sleep(1000);
        cout << "\n\t\t1.Press 1 to book a room              ";
        cout << "\n\t\t2.Press 2 to view all rooms status    ";
        cout << "\n\t\t3.Press 3 to view room information    ";
        cout << "\n\t\t4.Press 4 to view customer information";
        cout << "\n\t\t5.Press 5 to edit the data            ";
        cout << "\n\t\t6.Press 6 to leave the room           ";
//        cout << "\n\t\t7.Press 7 to view advance room status ";
        cout << "\n\t\t8.Enter 7 to view old record          ";
        cout << "\n\t\t9.Enter 8 to change password          ";
        cout << "\n\t\t10.Enter 0 to exit                    ";
        cout << "\n\t\t______________";
        cout << "\n              Select your choice : ";
        cin >> x;
        switch (x)
        {
        case 1:
        {
            alotroom();
            cout << "     Room alloted successfully     \n";
            break;
        }
        case 2:
        {
            rstatus();
            getchar();
            break;
        }
        case 3:
        {
            roominfo();
            getchar();
            break;
        }
        case 4:
        {
            customerinfo();
            getchar();
            break;
        }
        case 5:
        {
            edit();
            getchar();
            break;
        }
        case 6:
        {
            leaveroom();
            getchar();
            break;
        }
//        case 7:
//        {
//            roomstatus();
//            getchar();
//            break;
//        }
        case 7:
        {
            oldreco();
            getchar();
            break;
        }
        case 8:
        {
            int y;
            cout << "\nEnter passcode - ";
            cin >> y;
            obj1.password(y);
            break;
        }
        case 0:
        {
            e = 0;
            break;
        }
        default:
        {
            cout << "Invalid input" << endl;
            cout << "Enter correct input";
            break;
        }
        }
        cout << "\n      Press any key       ";
        getchar();
    }
    cout << "\n Thank You !!!";
}

