#include <iostream>
#include <string>
using namespace std;

void showMainMenu()
{
    cout<<"========================================" << endl;
    cout<<"        LIBRARY MANAGEMENT SYSTEM" << endl;
    cout<<"========================================" << endl;
    cout<<"1_ Add Book"<< endl;
    cout<<"2_ Show All Books"<< endl;
    cout<<"3_search for Book"<<endl;
    cout<<"4_Display Book Information"<<endl;
    cout<<"5_Borrow Book"<<endl;
    cout<<"6_Return Book"<<endl;
    cout<<"7_Show Available Books"<<endl;
    cout<<"8_Show Borrowed Books "<<endl;
    cout<<"9_ Exit" <<endl;
    cout<<"Enter your choice: ";
}

void addBook(int id[], string title[], string author[], double price[], bool available[], int& bookcount)
{
    cout << "Enter Book ID: ";
    cin >> id[bookcount];

    cin.ignore();

    cout << "Enter Book Title: ";
    getline(cin,title[bookcount]);
    
    cout << "Enter Author Name: ";
    getline(cin,author[bookcount]);
   
    cout << "Enter Book Price: ";
    cin >> price[bookcount];

    available[bookcount] = true;

    bookcount++;
    cout<<"----------------------------------------------------"<<endl;
    cout << "====Book added successfully!====" << endl;
    cout<<"----------------------------------------------------"<<endl;
}
void show_all_books(int id[],string title[],string author[],double price[],bool available[],int bookcount){
cout<<"=========ALL BOOKS========"<<endl;
for(int i=0;i<bookcount;i++){
    cout<<id[i]<<"|"<<title[i]<<"|"<<author[i]<<"|"<<price[i]<<"EGP"<<"|";
    if(available[i]){
        cout<<"Available"<<endl;
    }
    else{
        cout<<"Borrowed"<<endl;
    }
}


}


void search_for_book(int id[],string title[],string author[],double price[],bool available[],int bookcount){
 int choice;
 cout<<"search by: "<<endl;
 cout<<"1-Book ID"<<endl;
 cout<<"2-Book Title"<<endl;
 cout<<"Enter your choice :"<<endl;
 cin>>choice;

 if(choice==1){
    int search_id;
    cout<<"Enter Book ID :"<<endl;
    cin>>search_id;

    bool found=false;

    for(int i=0;i<bookcount;i++){
        if(search_id==id[i]){
            cout<<"========BOOK FOUND========"<<endl;
            cout<<"Book ID:"<<id[i]<<endl;
            cout<<"Title:"<<title[i]<<endl;
            cout<<"Author:"<<author[i]<<endl;
            cout<<"Price:"<<price[i]<<"EGP"<<endl;
            if(available[i]) cout<<"Status: Available"<<endl;
            else{
                cout<<"Status: Not Available"<<endl;
            }
        

            found =true;
            break;
        }
    }
          if(!found){
            cout<<"----------------------------------------------------"<<endl;
            cout<<"====BOOK NOT FOUND===="<<endl;
            cout<<"----------------------------------------------------"<<endl;
          }
 }
 else if(choice==2){
    string search_title;
    bool found =false;
    cout<<"Enter Book Title:"<<endl;
    cin.ignore(1000,'\n');
    getline(cin,search_title);

    for(int i=0;i<bookcount;i++){
        if(search_title==title[i]){
            cout<<"========BOOK FOUND========"<<endl;
            cout<<"Book ID:"<<id[i]<<endl;
            cout<<"Title:"<<title[i]<<endl;
            cout<<"Author:"<<author[i]<<endl;
            cout<<"Price:"<<price[i]<<"EGP"<<endl;
            if(available[i]) cout<<"Status: Available"<<endl;
            else{
                cout<<"Status: Not Available"<<endl;
            }
                

            found =true;
            break;
        }
    }
          if(!found){
            cout<<"----------------------------------------------------"<<endl;
            cout<<"====BOOK NOT FOUND===="<<endl;
            cout<<"----------------------------------------------------"<<endl;
          }
 }
       else{
        cout<<"Error!!!!"<<endl;
       }

        }
        void display_book_information(int id[], string title[], string author[],double price[], bool available[],string borrower[], int bookcount)
{
    int search_id;
    cout << "Enter Book ID:";
    cin >> search_id;

    bool found = false;

    for (int i = 0; i < bookcount; i++)
    {
        if (search_id == id[i])
        {
            cout << "======== BOOK INFORMATION ========" << endl;
            cout << "Book ID: " << id[i] << endl;
            cout << "Title: " << title[i] << endl;
            cout << "Author: " << author[i] << endl;
            cout << "Price: " << price[i] << " EGP" << endl;

            if (available[i])
            {
                cout << "Status: Available" << endl;
            }
            else
            {
                cout << "Status: Borrowed" << endl;
                cout << "Borrower: " << borrower[i] << endl;
            }

            found = true;
            break;
        }
    }

    if (found == false)
    {
        cout<<"----------------------------------------------------"<<endl;
        cout << "====BOOK NOT FOUND====" << endl;
        cout<<"----------------------------------------------------"<<endl;
    }
}


void borrow_book(int id[], string title[], string author[],double price[], bool available[],string borrower[], int bookcount)
{
    int search_id;
    cout << "Enter Book ID:";
    cin >> search_id;

    bool found = false;

    for (int i = 0; i < bookcount; i++)
    {
        if (search_id == id[i])
        {
            found = true;

            if (available[i] == true)
            {
                cout << "Enter Borrower Name: ";
                cin.ignore(1000,'\n');
                getline(cin,borrower[i]);

                available[i] = false;
                cout<<"----------------------------------------------------"<<endl;
                cout << "Book borrowed successfully!" << endl;
                cout<<"----------------------------------------------------"<<endl;
            }
            else
            {
                cout<<"----------------------------------------------------"<<endl;
                cout << "This book is already borrowed." << endl;
                cout<<"----------------------------------------------------"<<endl;
            }

            break;
        }
    }

    if (found == false)
    {
        cout<<"----------------------------------------------------"<<endl;
        cout << "====BOOK NOT FOUND====" << endl;
        cout<<"----------------------------------------------------"<<endl;
    }
}

void returnBook(int id[], string borrower[], bool available[], int bookcount)
{
    int bookId;

    cout << "Enter Book ID: ";
    cin >> bookId;

    for (int i = 0; i < bookcount; i++)
    {
        if (id[i] == bookId)
        {
            if (available[i] == true)
            {
                cout<<"----------------------------------------------------"<<endl;
                cout << "This book is already available." << endl;
                cout<<"----------------------------------------------------"<<endl;
            }
            else
            {
                available[i] = true;
                borrower[i] = "";
                cout<<"----------------------------------------------------"<<endl;
                cout << "Book returned successfully!" << endl;
                cout << "The book is now available." << endl;
                cout<<"----------------------------------------------------"<<endl;
            }

            return;
        }
    }

    cout << "Book not found." << endl;
}
void showAvailableBooks(int id[], string title[], bool available[], int bookcount)
{
    cout << "========== AVAILABLE BOOKS ==========" << endl;

    bool found = false;

    for (int i = 0; i < bookcount; i++)
    {
        if (available[i] == true)
        {
            cout << id[i] << " | "
                 << title[i] << " | Available" << endl;

            found = true;
        }
    }

    if (found == false)
    {
        cout<<"----------------------------------------------------"<<endl;
        cout << "====No available books====" << endl;
        cout<<"----------------------------------------------------"<<endl;
    }

}

void showborrowedbooks(int id[],string title[],string borrower[],bool available[],int bookcount)  
 {
    cout<<"========== BORROWED BOOKS =========="<<endl;
    bool found=false;

 for(int i=0;i<bookcount;i++){    
  if(available[i]==false){
      cout<<"book id:"<<id[i]<<endl;
      cout<<"title:"<<title[i]<<endl;
      cout<<"borrower:"<<borrower[i]<<endl;
      
      found=true;
      
     } 
  }
  if(found==false){
    cout<<"----------------------------------------------------"<<endl;
    cout<<"====No borrowed books!===="<<endl;
    cout<<"----------------------------------------------------"<<endl;
  }
  
}





int main(){
int id[1000];
string title[1000];
string author[1000];
string borrower[1000];
double price[1000];
bool available[1000];


int bookcount=0;
    int choice;

    do
    {
        showMainMenu();
        cin >> choice;
        cin.ignore(1000,'\n');

        if (choice == 1)
        {
            addBook(id,title,author,price,available,bookcount);
        }
        else if(choice==2){
            show_all_books(id,title,author,price,available,bookcount);
        }
        else if(choice==3){
           search_for_book(id,title,author,price,available,bookcount); 
        }
         else if(choice==4){
            display_book_information(id,title,author,price,available, borrower,bookcount);
        }

        else if(choice==5){
            borrow_book(id,title,author,price,available,borrower,bookcount);
        }
        else if(choice==6){
            returnBook(id,borrower,available,bookcount);
        }
        else if(choice==7){
            showAvailableBooks(id,title,available,bookcount);
        }
        else if(choice==8){
            showborrowedbooks(id,title,borrower,available,bookcount);
        }
       
    } while (choice !=9);


return 0;

}