    #include <iostream>
#include <fstream>

using namespace std;
void writing();
void deleting();
void searching();
void view();
void editing();
void borrowed();

struct item
 {

string name;
long int item_ID;
string category;
int item_count;
string Allocated_to;
 };


int main()
{     int opt;
do{

  cout << "\nPlease Enter an option number to continue:\n ";
  cout << "\nPress 1 for New item insertion";
  cout << "\nPress 2 for item deletion";
  cout << "\nPress 3 for Searching a item";
  cout << "\nPress 4 for Updating a item";
  cout << "\nPress 5 for viewing inventory item";
  cout << "\nPress 6 for editing a Item";
  cout << "\nPress 7 for viewing the borrowed list";
  cout << "\nEnter option Number or -1 to exit: ";

  cin >> opt;

  switch (opt)
  {
  case 1:
  {
    writing();
    break;
  }

  case 2:
  {
    deleting();
    break;
  }

  case 3:
  {
    searching();
    break;
  }
  case 4:
  {
    deleting();
    writing();
    cout << "Inventory has been updated! ";
    break;

  }
  case 5:
     {
         view();
         break;
     }
  case 6:
    {
        editing();
        break;
    }
  case 7:
    {
       borrowed();
       break;
    }}

} while(opt!=-1);
    }

void view()
{
    ifstream file("record.txt");
    char ch ;
    while(!file.eof())
    {
        file.get(ch);
        cout << ch;
    }

}

void writing()
{

  item  xyz;
  cout << "Enter The name of the item: ";
    cin >> xyz.name;

    cout << "Enter the Item ID: ";
    cin >>
    xyz.item_ID;
    cout << "Enter the Category: ";
    cin >>
    xyz.category;
    cout << "Enter  Item Count: ";
    cin >>
    xyz.item_count ;
    cout << "Enter Item Allocated to: ";
      // getline(cin,xyz.Allocated_to);
      cin >> xyz.Allocated_to;
  ofstream myfile;
  myfile.open("record.txt", ios::app | ios::out);
  myfile << endl << xyz.name << endl;
  myfile << xyz.item_ID << endl;
  myfile << xyz.category << endl << xyz.item_count << endl << xyz.Allocated_to <<endl;
  myfile.close();
}

void deleting()
{

  string line, name;
  cout << "Please Enter the name of item you want to delete: ";
  cin >> name;
  ifstream myfile;
  ofstream temp;
  myfile.open("record.txt");
  temp.open("temp.txt");
  int skip = 0;
while (getline(myfile, line)) {
    if ((line != name) && !(skip > 0)) {
       temp << line << endl;
    }
    else {
      if(skip == 0) {
          skip = 4; // Skip the next four lines
      }
      else {
          --skip;
      }
   }
}
  cout << "The item with the name " << name << " has been deleted if it exsisted" << endl;
  myfile.close();
  temp.close();
  remove("record.txt");
  rename("temp.txt", "record.txt");
}

void searching()
{
  ifstream fileInput;
  fileInput.open("record.txt");
  string s, searchitem;
  cout << "Please enter the term to search: ";
  cin >> searchitem;
  int skip=0;
  while(!fileInput.eof())
  {

           fileInput >> s;

       if (s == searchitem)  {

      for(int i=0 ; i<5;i++){
       cout << s << endl;
        fileInput >>  s;

    }}


  }
}
void editing()
{
     ifstream fileInput;
     int cou;
    ofstream temp("temp.txt");
  fileInput.open("record.txt");
  string searchitem;
  cout << "Please enter the term to search: ";
  cin >> searchitem;
  cout << "New Count: ";
  cin >> cou;
  int skip=0;
    item abc;
  while(!fileInput.eof())
  {

          fileInput >> abc.name;
             if(fileInput.eof()) break; //for stopping the loop if there is end of the file
        temp << endl<<abc.name << endl;
         fileInput >> abc.item_ID ;
         temp << abc.item_ID << endl;
          fileInput >> abc.category;
         temp << abc.category << endl;
          fileInput >> abc.item_count;
            if(abc.name==searchitem)
        {
         abc.item_count= abc.item_count+cou;
               temp << abc.item_count << endl;
        }
     else
        {temp << abc.item_count << endl;
        }
         fileInput >>abc.Allocated_to ;

     temp << abc.Allocated_to << endl;

    }
fileInput.close();
temp.close();
remove("record.txt");
rename("temp.txt", "record.txt");
}
void borrowed()
{

 ifstream fileInput;
  fileInput.open("record.txt");
  string s, searchitem;
  cout << "Please enter the term to search: ";
  cin >> searchitem;
    item  abc;
  while(!fileInput.eof())
  {

          fileInput >> s;
    if(fileInput.eof()) break;
       if (s == searchitem)  {
            cout << s  << " is Allocated To: "<< endl;
       //fileInput >> abc.name;
         fileInput >> abc.item_ID ;
          fileInput >> abc.category;
          fileInput >> abc.item_count;
       fileInput >> abc.Allocated_to;
     cout << abc.Allocated_to << endl;

    }}}


