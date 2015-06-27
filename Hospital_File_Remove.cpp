#include<iostream>
#include<cstdlib>
#include<fstream>

using namespace std;

int main()
{
    fstream f;
    remove("HOSPITAL.DAT");
    remove("HOSPITALBACKUP.DAT");
    remove("GLOBALVAR.DAT");
    remove("GLOBALVARBACKUP.DAT");
    remove("ROOMS.DAT");
    remove("ROOMSBACKUP.DAT");
    remove("CHECKS.DAT");
    remove("CHECKSBACKUP.DAT");
    f.open("HOSPITAL.DAT",ios::binary|ios::in);
    if(!f)
        cout<<"Removed Hospital.dat\n";
    else
        cout<<"error";
    f.close();
    f.open("HOSPITALBACKUP.DAT",ios::binary|ios::in);
    if(!f)
        cout<<"\nRemoved HospitalBackup.dat\n";
    else
        cout<<"\nerror";
    f.close();
    f.open("GLOBALVAR.DAT",ios::binary|ios::in);
    if(!f)
        cout<<"\nRemoved GlobalVar.dat\n";
    else
        cout<<"\nerror";
    f.close();
    f.open("GLOBALVARBACKUP.DAT",ios::binary|ios::in);
    if(!f)
        cout<<"\nRemoved GlobalVarBackup.dat\n";
    else
        cout<<"\nerror";
    f.close();
    f.open("ROOMS.DAT",ios::binary|ios::in);
    if(!f)
        cout<<"\nRemoved Rooms.dat\n";
    else
        cout<<"\nerror";
    f.close();
    f.open("ROOMSBACKUP.DAT",ios::binary|ios::in);
    if(!f)
        cout<<"\nRemoved RoomsBackup.dat\n";
    else
        cout<<"\nerror";
    f.close();
    f.open("CHECKS.DAT",ios::binary|ios::in);
    if(!f)
        cout<<"\nRemoved Checks.dat\n";
    else
        cout<<"\nerror";
    f.open("CHECKSBACKUP.DAT",ios::binary|ios::in);
    if(!f)
        cout<<"\nRemoved ChecksBackup.dat\n";
    else
        cout<<"\nerror";
    cout<<endl;
    system("pause");
    return 0;
}
