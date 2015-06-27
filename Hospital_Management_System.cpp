#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
#include<cstdlib>
#include<fstream>
#include<time.h>

using namespace std;

struct globalID                         //Global variables for auto-assigning of patient's IDs
{
	int value;
}gin,gout;

struct roomclass                        //Global variable for holding values of patients in rooms
{
    int value;
}room[101];

struct checks                           //Global variables for checking if user has inputted atleast 1 in & out patient
{
    char value;
}checkip,checkop;

struct dateclass                        //struct dateclass created
{
    int d,m,y;
    char rep;

    void systime()                      //For getting computer's clock values
    {
        time_t t = time(NULL);
        tm* timePtr = localtime(&t);
        d=timePtr->tm_mday;
        m=timePtr->tm_mon+1;
        y=timePtr->tm_year+1900;
    }
    void clear()                        //For resetting the values of date to 0
    {
        d=0;m=0;y=0;
    }
    void input()                        //For getting input of date
    {
        againy:
        cout<<"\nEnter year[IN YYYY FORMAT]:";
        cin>>y;
        if(y<2000)
        {
            cout<<"\nAre you sure of the year "<<y<<"? [Y/N]:";
            cin>>rep;
            if(rep!='y')
                goto againy;
        }
        againm:
        cout<<"\nEnter month[IN MM FORMAT]:";
        cin>>m;
        if(m>12)
        {
            cout<<"\nInvalid month entered... try again...\n";
            goto againm;
        }
        againd:
        cout<<"\nEnter date[IN DD FORMAT]:";
        cin>>d;
        switch(m)
        {
            case 1:if(d>31)
            {
              cout<<"\nInvalid date entered... try again...\n";
              goto againd;
            }
            break;
            case 2:if(y%4)
            {if(d>28)
                {
                    cout<<"\nInvalid date entered... try again...\n";
                    goto againd;
                }}
                   else
            {if(d>29)
                {
                    cout<<"\nInvalid date entered... try again...\n";
                    goto againd;
                }}
            break;
            case 3:if(d>31)
            {
              cout<<"\nInvalid date entered... try again...\n";
              goto againd;
            }
            break;
            case 4:if(d>30)
            {
              cout<<"\nInvalid date entered... try again...\n";
              goto againd;
            }
            break;
            case 5:if(d>31)
            {
              cout<<"\nInvalid date entered... try again...\n";
              goto againd;
            }
            break;
            case 6:if(d>30)
            {
              cout<<"\nInvalid date entered... try again...\n";
              goto againd;
            }
            break;
            case 7:if(d>31)
            {
              cout<<"\nInvalid date entered... try again...\n";
              goto againd;
            }
            break;
            case 8:if(d>31)
            {
              cout<<"\nInvalid date entered... try again...\n";
              goto againd;
            }
            break;
            case 9:if(d>30)
            {
              cout<<"\nInvalid date entered... try again...\n";
              goto againd;
            }
            break;
            case 10:if(d>31)
            {
              cout<<"\nInvalid date entered... try again...\n";
              goto againd;
            }
            break;
            case 11:if(d>30)
            {
              cout<<"\nInvalid date entered... try again...\n";
              goto againd;
            }
            break;
            case 12:if(d>31)
            {
              cout<<"\nInvalid date entered... try again...\n";
              goto againd;
            }
            break;
        }

    }
    void output()                       //For displaying date
    {
        cout<<d<<"/"<<m<<"/"<<y;
    }
}sysdate;
class inpatient                         //class inpatient created
{
 int id;
 dateclass dadmin;
 dateclass ddisch;
 int roomno;
 char name[20];
 char doctor[20];
 int age;
 char address[200];
 char gender;
 char problem[20];
 char medicine[20];
 char diet[100];
 char test[20];
 char status[20];
 char health[20];
 int roomfee;
 int labfee;
 int medicinefee;
 int testfee;
 int total;
 int used;
 protected:

 void giveroom(int i)                  //Function for giving room to In-Patients
 {
   for(int j=1;j<101;j++)
   {
     if(room[j].value==0)
     {
       roomno=j;
       room[j].value=i;
       cout<<"\nRoom number "<<roomno<<" has been alloted to patient number "<<i;
       break;
     }
   }
 }
 void giveid(int i)                          // Function for giving ID to In-Patients
 {
     id=i;
     gin.value=id+2;
 }
 void billdisplay()                     // Function for displaying Bill Receipt  for discharged In-Patients
 {
   system("cls");
   cout<<"\t\t\t\tWE CARE HOSPITAL PVT.LTD.\nDate:";sysdate.output();cout<<"\t\t\t\t\t\tbill no:"<<id<<"\n\t\t\tBILL RECEIPT\n";
   cout<<"Date of Admission:";dadmin.output();cout<<"\t\t\tDate of Discharge:";ddisch.output();
   cout<<"\nPatient No:"<<id<<"\nPatient Name:"<<name<<"\nConsultation fee: 500\t\tRoom fee:"<<roomfee<<"\t\tMedicine Fee:"<<medicinefee<<"\nLab fee:"<<labfee<<"\t\tTest fee:"<<testfee<<"\nTotal Bill:"<<total<<endl;
   system("pause");
 }
 void billamount()                      // Function for inputting Bill amount  for discharged In-Patients
 {
   system("cls");
   cout<<"Enter the Room fees:";cin>>roomfee;
   cout<<"\n\nEnter the Lab fees:";cin>>labfee;
   cout<<"\n\nEnter the Medicine fees:";cin>>medicinefee;
   cout<<"\n\nEnter the Test fees:";cin>>testfee;
   total=labfee+roomfee+medicinefee+testfee+500;
   cout<<"\nPress any key to continue to get your Bill Receipt...";
   getch();
   billdisplay();
 }
 void dischargedisplay()                // Function for displaying Detailed History of discharged In-Patients
 {
   system("cls");
   cout<<"\t\t\t\tWE CARE HOSPITAL PVT.LTD.\nDate:";sysdate.output();cout<<"\n\t\t\tDETAIL HISTORY OF PATIENT WHILE DISCHARGE\n";
   cout<<"Date of Admission:";dadmin.output();cout<<"\t\tDate of Discharge:";ddisch.output();
   cout<<"\n\nPatient No:"<<id<<"\n\nPatient Name:"<<name<<"\n\nAdmitted with problem:"<<problem<<"\n\nDiagonised by doctor:"<<doctor<<"\n\nPrescribed Medicine:"<<medicine;
   cout<<"\n\nDiet Prescribed:"<<diet<<"\n\nState of health of Patient at time of discharge:"<<health<<"\n\nFollow up action to be taken: As instructed by the doctor\n\nNext Consultation appointment on:";
   if(strcmpi(health,"healthy")==0)
   cout<<"not needed";
   else
   cout<<"Two days later";
   cout<<"\n\nPress any key to continue to input bill details...";
   getch();
   billamount();
 }

 public:

int retused()                               //Function for returning value of used
{
    return used;
}
void getname()                              // Function for displaying the name of In-Patients
 {
     cout<<name;
 }
 void getid()                                   // Function for displaying the ID of In-Patients
 {
     cout<<id;
 }
 void empty()                         // Function for resetting the values of all datamembers of inpatient
 {
 used=0;
 emptyrooms();
 id=0;
 dadmin.clear();
 ddisch.clear();
 roomno=0;
 strcpy(name," ");
 strcpy(doctor," ");
 age=0;
 strcpy(address," ");
 gender=' ';
 strcpy(problem," ");
 strcpy(medicine," ");
 strcpy(diet," ");
 strcpy(test," ");
 strcpy(status," ");
 strcpy(health," ");
 roomfee=0;
 labfee=0;
 medicinefee=0;
 testfee=0;
 total=0;
 }
 void emptyrooms()                      //Function for resetting values of all rooms to 0
 {
  for(int i=0;i<101;i++)
    room[i].value=0;
 }
 int retroom(int i)                     //Function for returning the values of the room array
 {
   return room[i].value;
 }
 void input(int i)                           //Function for getting the input for an In-Patient
 {
   used=1;
   cout<<"\nEnter date of admission as follows:";
   dadmin.input();
   cin.ignore();
   cout<<"\nEnter patient name:";
   gets(name);
   cout<<"\nEnter patient age:";
   cin>>age;
   cin.ignore();
   cout<<"\nEnter patient address:";
   gets(address);
   cout<<"\nEnter patient gender [M/F]:";
   cin>>gender;
   cin.ignore();
   cout<<"\nEnter patient problem:";
   gets(problem);
   cout<<"\nEnter the name of Doctor consulted:";
   gets(doctor);
   giveid(i);
   giveroom(i);
 }

 void details()                         // Function for displaying the details of In-Patients
 {
  system("cls");
  cout<<"\t\t\t\tWE CARE HOSPITAL PVT.LTD.\nDate:";sysdate.output();cout<<"\n\t\t\tDETAIL HISTORY OF PATIENT\n";
  cout<<"Date of Admission:";dadmin.output();
  cout<<"\nPatient No:"<<id;
  if(strcmp(status,"discharged")==0)
    cout<<"\t\tRoom no: Was occupying room number "<<roomno;
  else
    cout<<"\t\tRoom no: "<<roomno;
  cout<<"\n\nPatient Name:"<<name<<"\t\tAge:"<<age<<"\t\tGender:";
  if(gender=='m')
    cout<<"Male";
  else if(gender=='f')
    cout<<"Female";
  cout<<"\n\nAddress:"<<address<<"\n\nAdmitted with problem:"<<problem<<"\n\nDiagonised by doctor:"<<doctor<<"\n\nStatus:";
  if(strcmp(status,"discharged")==0)
    cout<<"DISCHARGED";
  else
    cout<<"NOT DISCHARGED";
  if(strcmp(status,"discharged")==0)
  {
      cout<<"\n\nDiagonised Problem:"<<problem<<"\n\nPrescribed Medicine:"<<medicine;
      cout<<"\n\nDiet Prescribed:"<<diet<<"\n\nTest Taken:"<<test;
  }
  else
  {
      cout<<"\n\nDiagonised Problem: N/A"<<"\n\nPrescribed Medicine: N/A";
      cout<<"\n\nDiet Prescribed: N/A"<<"\n\nTest Taken: N/A";
  }
  cout<<endl;system("pause");
 }
 void discharge()                       //Function for Discharging an In-Patient
 {
   system("cls");
   cout<<"\nEnter date of discharge as follows:";
   ddisch.input();
   cin.ignore();
   cout<<"\nEnter the Medicine prescribed by the Doctor:";
   gets(medicine);
   cout<<"\nEnter the Diet prescribed by the Doctor:";
   gets(diet);
   cout<<"\nEnter the Test to be taken:";
   gets(test);
   cout<<"\nEnter the State of health of the patient [HEALTHY/NOT HEALTHY]:";
   gets(health);
   room[roomno].value=0;
   strcpy(status,"discharged");
   cout<<"Patient number "<<id<<" has been discharged and room number "<<roomno<<" is now vacant";
   cout<<"\nPress any key to continue to the discharge report...";
   getch();
   dischargedisplay();
 }
};                                      //class inpatient ends
class outpatient                        //class outpatient created
{
 int id;
 dateclass dvisit;
 char name[20];
 int age;
 char address[200];
 char gender;
 char problem[20];
 char medicine[20];
 int used;

 public:

 int retused()                                //Function for returning value of used
 {
     return used;
 }
 void getname()                              //Function for displaying the name of Out-Patients
 {
     cout<<name;
 }
 void getid()                                 //Function for displaying the ID of Out-Patients
 {
     cout<<id;
 }
 void empty()                              // Function for resetting the values of all datamembers of outpatient
 {
  used=0;
  id=0;
  dvisit.clear();
  strcpy(name," ");
  age=0;
  strcpy(address," ");
  gender=' ';
  strcpy(problem," ");
  strcpy(medicine," ");
 }
 void giveid(int i)                          // Function for giving ID to Out-Patients
 {
     id=i;
     gout.value=id+2;
     cout<<"\nPatient has been given ID number of "<<id;
 }
 void input(int i)                           //Function for getting the input for an Out-Patient
 {
   used=1;
   cout<<"\nEnter date of visit as follows:";
   dvisit.input();
   cin.ignore();
   cout<<"\nEnter patient name:";
   gets(name);
   cout<<"\nEnter patient age:";
   cin>>age;
   cin.ignore();
   cout<<"\nEnter patient address:";
   gets(address);
   cout<<"\nEnter patient gender [M/F]:";
   cin>>gender;
   cin.ignore();
   cout<<"\nEnter patient problem:";
   gets(problem);
   cout<<"\nEnter suggested medicine:";
   gets(medicine);
   giveid(i);
 }
 void details()                         // Function for displaying the details of Out-Patients
 {
   system("cls");
   cout<<"\t\t\t\tWE CARE HOSPITAL PVT.LTD.\nDate:";sysdate.output();cout<<"\n\t\t\tDETAIL HISTORY OF PATIENT\n";
   cout<<"Date of Admission:";dvisit.output();
  cout<<"\n\nPatient No:"<<id<<"\n\nPatient Name:"<<name<<"\t\tAge:"<<age<<"\t\tGender:";
  if(gender=='m')
    cout<<"Male";
  else if(gender=='f')
    cout<<"Female";
  cout<<"\n\nAddress:"<<address<<"\n\nProblem:"<<problem<<"\n\nPrescribed Medicine:"<<medicine<<endl;
  system("pause");
 }
};                                      //class outpatient ends

int main()                              //main function begins
{
 system("cls");
 fstream fh,fr,fg,fc,fcheck;
 inpatient ip[101];
 outpatient op[101];
 char ch,rep;
 checkip.value='n';checkop.value='n';
 int number,n,i,back=0;
 sysdate.systime();
 fr.open("ROOMS.DAT",ios::in);                          //Restoring previous room status values from file
    if(!fr)
    {
         ip[0].emptyrooms();
    }
    else
    {
        for(int a=1;a<101;a++)
        fr.read((char*)&room[a],sizeof(room[a]));
    }
 fr.close();
 fg.open("GLOBALVAR.DAT",ios::in);              //Restoring previous global variable values from file
    if(!fg)
    {
         gin.value=1;
         gout.value=2;
    }
    else
    {
        fg.read((char*)&gin,sizeof(gin));
        fg.read((char*)&gout,sizeof(gout));
    }
 fg.close();
 fh.open("HOSPITAL.DAT",ios::in|ios::binary);     //Restoring previously written patient data from file
   if(!fh)
   {
       checkip.value='n';
       checkop.value='n';
   }
   else
   {
       fc.open("CHECKS.DAT",ios::in|ios::binary);              //Restoring check values
           fc.read((char*)&checkip,sizeof(checkip));
           fc.read((char*)&checkop,sizeof(checkop));
       fc.close();
       for(i=1;i<101;i++)
        {
            if(i%2)
                fh.read((char*)&ip[i],sizeof(ip[i]));
            else
                fh.read((char*)&op[i],sizeof(op[i]));
        }
   }
   if((ip[1].retused()!=1)&&(op[2].retused()!=1))                  //Checking if no data has been writtten on file
   {
       checkip.value='n';
       checkop.value='n';
       remove("HOSPITAL.DAT");
       remove("GLOBALVAR.DAT");
       remove("ROOMS.DAT");
       remove("CHECKS.DAT");
   }
  fh.close();
 do
 {
     if(checkip.value=='y'||checkop.value=='y')
        {
           fh.open("HOSPITAL.DAT",ios::in|ios::binary);
           for(i=1;i<101;i++)
            {
                if(i%2)
                    fh.read((char*)&ip[i],sizeof(ip[i]));
                else
                    fh.read((char*)&op[i],sizeof(op[i]));
            }
            fh.close();
            fr.open("ROOMS.DAT",ios::in|ios::binary);
                for(int a=1;a<101;a++)
                    fr.read((char*)&room[a],sizeof(room[a]));
            fr.close();
            fg.open("GLOBALVAR.DAT",ios::in|ios::binary);
                fg.read((char*)&gin,sizeof(gin));
                fg.read((char*)&gout,sizeof(gout));
            fg.close();
            fc.open("CHECKS.DAT",ios::in|ios::binary);
                fc.read((char*)&checkip,sizeof(checkip));
                fc.read((char*)&checkop,sizeof(checkop));
            fc.close();
       }
 redo:
 i=0;back=0;
 system("cls");
 cout<<"Hello! Today is:";sysdate.output();
 cout<<"\n\n\t\t****** Welcome to WE CARE HOSPITALS! ******\n\n Which of the following would you like to do?";
 cout<<"\n\n1.Register In-Patients";
 cout<<"\n2.Register Out-Patients";
 cout<<"\n3.Discharge a Patient";
 cout<<"\n4.View Reports of In-Patients";
 cout<<"\n5.View Reports of Out-Patients";
 cout<<"\n6.Search and view rooms and occupants";
 cout<<"\n7.Backup current Database to file";
 cout<<"\n8.Restore previously backed up database";
 cout<<"\n9.Empty the Database";
 cout<<"\n10.Exit\n\nYour Choice:\t";
 cin>>n;
   if(n==1)
   {
	    do
	    {
	        for(i=gin.value;i<101;i+=2)
                if(ip[i].retused()!=1)
                   break;
            system("cls");
            checkip.value='y';                        //this says that atleast one in-patient is now registered
	        ip[i].input(i);
	        cout<<"\nRegister more in-patients? [Y/N]:";
	        cin>>ch;
	    }while(ch=='y'||ch=='Y');
   }
   else if(n==2)
   {
         do
         {
             for(i=gout.value;i<101;i+=2)
                 if(op[i].retused()!=1)
                    break;
             system("cls");
             checkop.value='y';                 //this says that atleast one out-patient is now registered
	         op[i].input(i);
	         cout<<"\nRegister more out-patients? [Y/N]:";
	         cin>>ch;
	         i+=2;
         }while(ch=='y'||ch=='Y');
   }
   else if(n==3)
   {
	    do
	    {
	        if(checkip.value=='y')
            {
                system("cls");
                cout<<"Reports of patients available:\n\n";
                for(i=1;i<gin.value;i+=2)
                {ip[i].getid();cout<<" -> ";ip[i].getname();if(i%2)cout<<"\t";else cout<<endl;}
                cout<<"\nEnter the ID number of the in-patient to be discharged: ";
	            cin>>number;
	            ip[number].discharge();
	            cout<<"\nDischarge more in-patients? [Y/N]:";
	            cin>>ch;
	        }
	        else
            {
                system("cls");
                cout<<"\nRegister an In-Patient first to discharge them!!\n\n****** Returning to Main Menu ******\n\n";
                system("pause");
                goto redo;
            }
	    }while(ch=='y'||ch=='Y');
   }
   else if(n==4)
   {
	    do
	    {
	        if(checkip.value=='y')
            {
                system("cls");
                cout<<"Reports of patients available:\n\n";
                for(i=1;i<gin.value;i+=2)
                {ip[i].getid();cout<<" -> ";ip[i].getname();if(i%2)cout<<"\t";else cout<<endl;}
                cout<<"\n\nEnter the ID number of the in-patient to see the report: ";
	            cin>>number;
	            ip[number].details();
	            cout<<"\nView reports for more patients? [Y/N]:";
	            cin>>ch;
            }
            else
            {
                system("cls");
                cout<<"\nRegister an In-Patient first to view their details!!\n\n****** Returning to Main Menu ******\n\n";
                system("pause");
                goto redo;
            }
	    }while(ch=='y');
   }
   else if(n==5)
   {
	    do
	    {
	        if(checkop.value=='y')
            {
                system("cls");
                cout<<"Reports of patients available:\n\n";
                for(i=2;i<gout.value;i+=2)
                {op[i].getid();cout<<" -> ";op[i].getname();if(i%2)cout<<endl;else cout<<"\t";}
                cout<<"\n\nEnter the ID number of the out-patient to see the report: ";
	            cin>>number;
	            op[number].details();
	            cout<<"\nView reports for more patients? [Y/N]:";
	            cin>>ch;
            }
            else
            {
                system("cls");
                cout<<"\nRegister an Out-Patient first to view their details!!\n\n****** Returning to Main Menu ******\n\n";
                system("pause");
                goto redo;
            }
	    }while(ch=='y');
   }
   else if(n==6)
   {
       do
       {
           if(checkip.value=='y')
           {
               system("cls");cout<<"Legend: Room number -> Patient ID number\n\n";
               for(int m=1;m<101;m++){cout<<m<<" -> "<<room[m].value;if(m%8){cout<<"  ";}else{cout<<endl<<endl;}}
               cout<<"\n\nEnter the Room number to view its details: ";
               cin>>number;
               if(ip[0].retroom(number)==0)
                   cout<<"\nRoom number "<<number<<" is empty";
               else
               {
                   cout<<"Room number "<<number<<" is occupied by Patient number "<<ip[0].retroom(number)<<"\n\nView Details of this Patient? [Y/N]:";
                   cin>>ch;
                   if(ch=='y')
                      ip[ip[0].retroom(number)].details();
               }
               cout<<"\n\nView details for more rooms? [Y/N]:";
               cin>>ch;
           }
           else
           {
               system("cls");
               cout<<"\nRegister an In-Patient first to view their room details!!\n\n****** Returning to Main Menu ******\n\n";
               system("pause");
               goto redo;
           }

        }while(ch=='y');
    }
   else if(n==7)
   {
    if(checkip.value=='y'||checkop.value=='y')
      {
       system("cls");
       fh.open("HOSPITALBACKUP.DAT",ios::out|ios::binary);
       for(i=1;i<101;i++)
       {
           if(i%2)
            fh.write((char*)&ip[i],sizeof(ip[i]));
           else
            fh.write((char*)&op[i],sizeof(op[i]));
       }
       fh.close();
       fr.open("ROOMSBACKUP.DAT",ios::out);
        for(int a=1;a<101;a++)
            fr.write((char*)&room[a],sizeof(room[a]));
       fr.close();
       fg.open("GLOBALVARBACKUP.DAT",ios::out);
        fg.write((char*)&gin,sizeof(gin));
        fg.write((char*)&gout,sizeof(gout));
       fg.close();
       fc.open("CHECKSBACKUP.DAT",ios::out|ios::binary);
           fc.write((char*)&checkip,sizeof(checkip));
           fc.write((char*)&checkop,sizeof(checkop));
       fc.close();
       cout<<"\n\n\t\t****** Backup Successfully Created ******\n\n";
       system("pause");
      }
    else
        {system("cls");cout<<"\n\n\t\t*** CURRENT DATABASE IS EMPTY!! ***\n\n\tCREATE A DATABASE BEFORE TRYING TO BACK IT UP!!\n\n";}
   }
   else if(n==8)
   {
    system("cls");
    fcheck.open("HOSPITALBACKUP.DAT",ios::in|ios::binary);
    if(!fcheck)
    {
        cout<<"\n\n\t\t*** NO PREVIOUSLY BACKED UP FILE FOUND!! ***\n\n\tCREATE A BACKUP FILE FIRST BEFORE TRYING TO RESTORE IT!!\n\n";fcheck.close();
    }
    else
    {
       fcheck.close();
       i=1;
       cout<<"\n\n\t\t*** WARNING!! ***\n\nTHIS WILL REPLACE YOUR CURRENT DATABASE WITH THE DATABASE STORED ON THE BACKUP FILE!\n\n\tTHE BACKUP FILE WILL BE DELETED WHEN RESTORE IS FINISHED!!\n\nDo you want to continue? [Y/N]:";
       cin>>ch;
       if(ch=='y')
       {
            remove("GLOBALVAR.DAT"); rename("GLOBALVARBACKUP.DAT","GLOBALVAR.DAT");
            remove("HOSPITAL.DAT"); rename("HOSPITALBACKUP.DAT","HOSPITAL.DAT");
            remove("ROOMS.DAT"); rename("ROOMSBACKUP.DAT","ROOMS.DAT");
            remove("CHECKS.DAT"); rename("CHECKSBACKUP.DAT","CHECKS.DAT");
            checkip.value='y';
            checkop.value='y';
            for(i=1;i<101;i++)
             {
                ip[i].empty();
                op[i].empty();
             }
             back=1;
            cout<<"\n\n\t\t****** Database Successfully Restored ******\n\n";
            system("pause");
        }
    }
   }
   else if(n==9)
   {
       system("cls");
       fcheck.open("HOSPITAL.DAT",ios::in|ios::binary);
     if(!fcheck)
      {cout<<"\n\n\t\t*** NO DATABASE FOUND!! ***\n\n";fcheck.close();}
     else
      {
       cout<<"\n\n\t\t*** WARNING!! ***\n\nTHIS WILL REMOVE YOUR CURRENT DATABASE AND ALSO THE DATABASE STORED ON THE FILE!\nHowever, the Backup file will still remain intact\n\nDo you want to continue? [Y/N]:";
       cin>>ch;
       if(ch=='y')
       {
           fcheck.close();
           remove("HOSPITAL.DAT");
           remove("GLOBALVAR.DAT");
           remove("ROOMS.DAT");
           remove("CHECKS.DAT");
           for(i=1;i<101;i++)
           {
               ip[i].empty();
               op[i].empty();
               room[i].value=0;
           }
           gin.value=1;
           gout.value=2;
           checkip.value='n';
           checkop.value='n';
           cout<<"\n\n\t\t****** Database Successfully Erased ******\n\n";
           system("pause");
       }
      }
   }
   else if(n==10)
   {
       exit(0);
   }
   else
   {
       system("cls");
	    cout<<"\nEnter a proper choice!!";
   }
    if(checkip.value=='y'||checkop.value=='y')
        {
        if(back==0)
           {
            fh.open("HOSPITAL.DAT",ios::out|ios::binary);
            for(i=1;i<101;i++)
             {
                 if(i%2)
                     fh.write((char*)&ip[i],sizeof(ip[i]));
                 else
                     fh.write((char*)&op[i],sizeof(op[i]));
             }
             fh.close();
             fr.open("ROOMS.DAT",ios::out);
                 for(int a=1;a<101;a++)
                     fr.write((char*)&room[a],sizeof(room[a]));
             fr.close();
             fg.open("GLOBALVAR.DAT",ios::out);
                fg.write((char*)&gin,sizeof(gin));
                fg.write((char*)&gout,sizeof(gout));
             fg.close();
             fc.open("CHECKS.DAT",ios::out|ios::binary);
                fc.write((char*)&checkip,sizeof(checkip));
                fc.write((char*)&checkop,sizeof(checkop));
             fc.close();
           }
        }
 cout<<"\n\n--------------------------------------------------------------------------------\n\nReturn to main menu? [Y/N]:";
 cin>>rep;
 }while(rep=='y'||rep=='Y');
return 0;
}
