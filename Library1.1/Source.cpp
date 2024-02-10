#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <vector>
#include <stdio.h>
#include <stddef.h>

using namespace std;

////// Global Variables
string bookName;
bool mode;

//////Menu Function
int menu();


///////// ClassA 

class classA
{
public:
	classA();				//constructor
	~classA();				//destructor
	virtual void get() = 0;			//pure virtual function
	virtual void show() = 0;		//pure virtual function

};

classA::classA()
{
	if (mode == 0)
		cout << " classA - Constructor\n";
}

classA::~classA()
{
	if (mode == 0)
		cout << " classA - Destructor\n";
}

////////// Class info

class info :public classA
{
public:
	info();			//constructor
	~info();		//destructor

	int age=0;		
	long int contact=0;
	string name, memID, email;
	void get()			//Member function to get user inputs for enrolling members
	{
		system("cls");
		if (mode == 0)
			cout << "\n info - get()\n\n";
		cin.sync();
		cout << "\nMembership ID : ";
		cin >> memID;
		cout << "\nName : ";
		cin >> name;
		cout << "\nAge : ";
		cin >> age;
		cout << "\nE-mail : ";
		cin >> email;
		cout << "\nContact no. : ";
		cin >> contact;
	}
	void show()			//Member function to display saved member information
	{
		if (mode == 0)
			cout << "\n info - show()\n\n";
		cout << "\nMembership ID : " << memID;
		cout << "\nName : " << name;
		cout << "\nAge : " << age;
		cout << "\nE-mail : " << email;
		cout << "\nContact no. : " << contact;
		cout << "\n\n";
	}
};

info::info()
{
	if (mode == 0)
		cout << " info - Constructor\n";
}

info::~info()
{
	if (mode == 0)
		cout << " info - Destructor\n";
}

////////////////////// Class Student members

class student :public info
{
public:
	student();			//constructor
	~student();			//destructor

	info a1;			//creating object
	void get()
	{
		system("cls");
		if (mode == 0)
			cout << "\n student - get()\n\n";

		a1.get();

		/////////////////Saving student member information to a text file

		ofstream stu("studentMember.txt", ios::app | ios::binary);
		stu << "\nMembership ID : " << a1.memID;
		stu << "\nName : " << a1.name;
		stu << "\nAge : " << a1.age;
		stu << "\nE-mail : " << a1.email;
		stu << "\nContact no. : " << a1.contact;
		stu << "\n\n";
		stu.close();
		cout << "\n\nMember Entry has been saved\n";
		cout << "\n\n\t\t\t";
		system("pause");
		menu();
	}
	void show()
	{
		system("cls");
		if (mode == 0)
			cout << "\n student - show()\n\n";

		//////////////////Dsiplaying the content in studentMember text file

		string str1;
		ifstream inStu("studentMember.txt");
		if (!inStu)
		{
			cout << "\n\nNo Data in the file ";
			cout << "\n\n\t\t\t";
			system("pause");
			menu();
		}
		else
		{
			while (!inStu.eof())
			{
				getline(inStu, str1);
				cout << str1 << endl;
			}
			inStu.close();
			cout << "\n\n\t\t\t";
			system("pause");
			menu();
		}
	}
};

student::student()
{
	if (mode == 0)
		cout << " student - Constructor\n";
}

student::~student()
{
	if (mode == 0)
		cout << " student - Destructor\n";
}


/////////////////// Class Fac staff members

class facStaff :public info
{
public:
	facStaff();			//constructor
	~facStaff();		//destructor

	info a1;			//creating object
	void get()
	{
		system("cls");
		if (mode == 0)
			cout << "\n facStaff - get()\n\n";

		a1.get();

		/////////////////Saving faculty staff member information to a text file

		ofstream fac("facStaffMember.txt", ios::app | ios::binary);
		fac << "\nMembership ID : " << a1.memID;
		fac << "\nName : " << a1.name;
		fac << "\nAge : " << a1.age;
		fac << "\nE-mail : " << a1.email;
		fac << "\nContact no. : " << a1.contact;
		fac << "\n\n";
		fac.close();
		cout << "\n\nMember Entry has been saved";
		cout << "\n\n\t\t\t";
		system("pause");
		menu();
	}
	void show()
	{
		string str2;
		system("cls");
		if (mode == 0)
			cout << "\n facStaff - show()\n\n";

		//////////////////Dsiplaying the content in facStaffMember text file

		ifstream inFac("facStaffMember.txt");
		if (!inFac)
		{
			cout << "\n\nNo Data in the file ";
			cout << "\n\n\t\t\t";
			system("pause");
			menu();
		}
		else
		{
			while (!inFac.eof())
			{
				getline(inFac, str2);
				cout << str2 << endl;
			}
			inFac.close();
			cout << "\n\n\t\t\t";
			system("pause");
			menu();
		}
	}
};

facStaff::facStaff()
{
	if (mode == 0)
		cout << " facStaff - Constructor\n";
}

facStaff::~facStaff()
{
	if (mode == 0)
		cout << " facStaff - Destructor\n";
}

////////////////// Class Other members (Outside members)

class outside_member :public info
{
public:
	outside_member();			//constructor
	~outside_member();			//destructor

	info a1;			//creating object
	string address;
	void get()
	{
		system("cls");
		if (mode == 0)
			cout << "\n outside_member - get()\n\n";

		a1.get();
		cout << "\nAddress : ";
		cin >> address;

		/////////////////Saving outside member information to a text file

		ofstream others("outsideMember.txt", ios::app | ios::binary);
		others << "\nMembership ID : " << a1.memID;
		others << "\nName : " << a1.name;
		others << "\nAge : " << a1.age;
		others << "\nE-mail : " << a1.email;
		others << "\nContact no. : " << a1.contact;
		others << "\nAddress : " << address;
		others << "\n\n";
		others.close();
		cout << "\n\nMember Entry has been saved";
		cout << "\n\n\t\t\t";
		system("pause");
		menu();
	}
	void show()
	{
		system("cls");
		if (mode == 0)
			cout << "\n outside_member - show()\n\n";
		string str3;

		//////////////////Dsiplaying the content in outsideMember text file

		ifstream inOthers("outsideMember.txt");
		if (!inOthers)
		{
			cout << "\n\nNo Data in the file ";
			cout << "\n\n\t\t\t";
			system("pause");
			menu();
		}
		else
		{
			while (!inOthers.eof())
			{
				getline(inOthers, str3);
				cout << str3 << endl;
			}
			inOthers.close();
			cout << "\n\n\t\t\t";
			system("pause");
			menu();
		}
	}
};

outside_member::outside_member()
{
	if (mode == 0)
		cout << " outside_member - Constructor\n";
}

outside_member::~outside_member()
{
	if (mode == 0)
		cout << " outside_member - Destructor\n";
}

class bookInformation :public classA
{
public:
	bookInformation();			//constructor
	~bookInformation();			//destructor

	string bookdetails, bookTitle, bookID, author;
	int rackNo=0, copies=0;

	void get()
	{
		////////////Getting book information from the user

		system("cls");
		if (mode == 0)
			cout << "\n bookInformation - get()\n\n";
		cout << "\nEnter Title of the Book : ";
		cin >> bookTitle;
		cout << "\nEnter Author : ";
		cin >> author;
		cout << "\nEnter Book ID : ";
		cin >> bookID;
		cout << "\nEnter Number of Copies of the Book : ";
		cin >> copies;
		cout << "\nEnter rack Number : ";
		cin >> rackNo;

		////////////Saving book information to a text file

		ofstream book1("bookInfo.txt", ios::app);
		book1 << "\nBook Title : " << bookTitle;
		book1 << "\nNo. of Copies : " << copies;
		book1 << "\nBook ID : " << bookID;
		book1 << "\nAuthor : " << author;
		book1 << "\nRack no. : " << rackNo;
		book1 << "\n\n";

		book1.close();
		cout << "\n\nBook Information has been saved";
		cout << "\n\n\t\t\t";
		system("pause");
;		menu();
	}
	void show()
	{

		//////////////Displaying content in bookInfo text

		system("cls");
		if (mode == 0)
			cout << "\n bookInformation - show()\n\n";
		ifstream inBook1("bookInfo.txt");
		if (!inBook1)
		{
			cout << "\n\nNo Data in the file ";
			cout << "\n\n\t\t\t";
			system("pause");
			menu();
		}
		while (!(inBook1.eof()))
		{
			getline(inBook1, bookdetails);
			cout << bookdetails << endl;
		}
		inBook1.close();
		cout << "\n\n\t\t\t";
		system("pause");
		menu();
	}
};

bookInformation::bookInformation()
{
	if (mode == 0)
		cout << " bookInformation - Constructor\n";
}

bookInformation::~bookInformation()
{
	if (mode == 0)
		cout << " bookInformation - Destructor\n";
}


//////////////////// Class bookSearch 

class bookSearch :public bookInformation, public info
{
public:
	bookSearch();			//constructor	
	~bookSearch();			//destructor

	int select=0, count = 0;
	void updateCopies();
	void borrowBooks();
	void searchBook()
	{
		system("cls");

		////////////////Searching & Displaying a specific book from bookInfo text file

		cout << "\t\t\t\tSEARCHING A BOOK...... \n\n";
		ifstream inBook1("bookInfo.txt");
		if (!inBook1)
		{
			cout << "\n\nNo Data in the file ";
			cout << "\n\n\t\t\t";
			system("pause");
			menu();
		}
		cout << "Enter the Book Title : ";
		cin >> bookName;
		
		while (!(inBook1.eof()))
		{
			getline(inBook1, bookdetails);
			if (bookdetails == "Book Title : " + bookName)
			{
				count++;
				cout << "\nRequested book is found..\n\n";
				cout << bookdetails << endl;
				for (int i = 1; i <= 4; i++)
				{
					getline(inBook1, bookdetails);
					cout << bookdetails << endl;
				}

			}
		}
		if (count == 0)
		{
			cout << "\n\nSorry! Requested Book is not in the Library Database\n\n";
			cout << "\n\n\t\t\t";
			system("pause");
			menu();
		}

		inBook1.close();
		count = 0;
		cout << "\n\n\t\t\tPress 1 to Borrow Books Menu\n\t\t\tPress 2 to Main Menu\n\n\t\t\t>>>>>> ";
		cin >> select;

		switch (select)
		{
		case 1:			//////////////This leads for borrowing a book 
		{
			updateCopies();
			borrowBooks();
			break;
		}
		default:
			menu();
		}
	}
};

bookSearch::bookSearch()
{
	if (mode == 0)
		cout << " bookSearch - Constructor\n";
}

bookSearch::~bookSearch()
{
	if (mode == 0)
		cout << " bookSearch - Destructor\n";
}

////////////////////// Update Copies

void bookSearch::updateCopies()			//Updating number of copies of a book in library after borrowing or returning a book
{
	if (mode == 0)
		cout << "\n updateCopies()\n\n";

	int cop;
	cout << "\nUpdate Number of Copies : ";
	cin >> cop;
	cout << endl << endl;
	fstream readfile;
	readfile.open("bookInfo.txt");
	vector<string> lines;
	string L;

	while (getline(readfile, L))			//Storing lines of the text to a vector
		lines.push_back(L);

	readfile.close();

	ofstream writefile;
	writefile.open("bookInfo.txt");

	for (int i = 0; i < lines.size(); i++)
	{
		if (lines[i] != "Book Title : " + bookName)
			writefile << lines[i] << endl;
		else
		{
			writefile << lines[i] << endl;
			writefile << "No. of Copies : " << cop << endl;			
			i++;
		}

	}
	writefile.close();
}

////////////////////// Function borrowBooks

void bookSearch::borrowBooks()
{
	if (mode == 0)
		cout << "\n borrowBooks()\n\n";

	//////////////Getting book borrowing details

	string book_title, book_id, mem_id, bor_date, due_date, refno;
	cout << "\nReference No. : ";
	cin >> refno;  //Reference number is unique for the book borrowing instance. This is entered by librarian by referring last borrow record.
	cout << "\nMember ID : ";
	cin >> mem_id;
	cout << "\nBook ID : ";
	cin >> book_id;
	cout << "\nBook Title : ";
	cin >> book_title;
	cout << "\nBorrow Date : ";
	cin >> bor_date;
	cout << "\nDue Date : ";
	cin >> due_date;
	cout << "\n\n";

	/////////////////Saving borrow book details to a text file

	ofstream borrowRec("Borrow_Records.txt", ios::app);

	borrowRec << "\nReference No. : " << refno << endl;
	borrowRec << "Member ID : " << mem_id << endl;
	borrowRec << "Book ID : " << book_id << endl;
	borrowRec << "Book Title: " << book_title << endl;
	borrowRec << "Borrow Date : " << bor_date << endl;
	borrowRec << "Due Date : " << due_date << endl;
	borrowRec.close();

	cout << "\n\n\t\t\t";
	system("pause");
	menu();
}

///////////////////// Class returnBook

class returnBook
{
private:
	string ref, recdetails, bookdetails1;
	int count1 = 0, count2 = 0;
	bool penalty=0;
public:
	returnBook();			//constructor
	~returnBook();			//destructor

	void returnBook_menu();
	void payFine();
};

returnBook::returnBook()
{
	if (mode == 0)
		cout << " returnBook - Constructor\n";
}

returnBook::~returnBook()
{
	if (mode == 0)
		cout << " returnBook - Destructor\n";
}


void returnBook::returnBook_menu()
{
	system("cls");
	if (mode == 0)
		cout << "\n returnBook_menu()\n\n";

	bookSearch updateC;				//creating object

	//////////////Getting details about returned book
	cout << "\nEnter Book Title : ";
	cin >> bookName;
	cout << "Enter Reference No. : ";
	cin >> ref;
	cout << endl;

	/////////////////Displaying number of copies left in the library

	ifstream inBook1("bookInfo.txt");
	if (!inBook1)
	{
		cout << "\nError! Recheck the Entered Data and try again..\n\n";
		cout << "\n\n\t\t\t";
		system("pause");
		menu();
	}
	while (!(inBook1.eof()))
	{
		getline(inBook1, bookdetails1);
		if (bookdetails1 == "Book Title : " + bookName)
		{
			count1++;
			getline(inBook1, bookdetails1);
			cout << bookdetails1 << " (left in the library)" << endl;
		}
	}
	if (count1 == 0)
	{
		cout << "\nError! Recheck the Entered Data and try again..\n\n";
		cout << "\n\n\t\t\t";
		system("pause");
		returnBook_menu();
	}
	inBook1.close();

	//////////////////Displaying borrow details

	cout << "\n\nBorrow Details of the entered Ref.no are displayed below..\n\n";
	ifstream borRec("Borrow_Records.txt");
	if (!borRec)
	{
		cout << "\nError! Recheck the Entered Data and try again..\n\n";
		cout << "\n\n\t\t\t";
		system("pause");
		menu();
	}

	while (!borRec.eof())
	{
		getline(borRec, recdetails);
		if (recdetails == "Reference No. : " + ref)
		{
			count2++;
			cout << recdetails << endl;
			for (int i = 1; i <= 6; i++)
			{
				getline(borRec, recdetails);
				cout << recdetails << endl;
			}
		}
	}
	if (count2 == 0)
	{
		cout << "\nError! Recheck the Entered Data and try again..\n\n";
		cout << "\n\n\t\t\t";
		system("pause");
		returnBook_menu();
	}
	borRec.close();
	count1 = 0;
	count2 = 0;
	updateC.updateCopies();					//Update copies after returning the book
	cout << "The Book is Received\n";

	//checking whether the due date is passed or not
	cout << "\nDue date has passed ? (press 1 if Yes, Press 0 if No) : ";		
	cin >> penalty;

	if (penalty)		//When due date is passed
	{
		payFine();			
	}
	else
	{
		cout << "\n\n\t\t\t";
		system("pause");
		menu();
	}
}

void returnBook::payFine()
{
	if (mode == 0)
		cout << "\n payFine()\n\n";

	///////////////Structure to calculate fine that the member has to pay

	struct calFine
	{
		const int x = 10;
		int days=0;
		int calculate_fine()
		{
			if (mode == 0)
				cout << "\n calculate_fine()\n\n";

			return x * days;
		}
	};
	calFine fine;

	cout << "\nHow many days have passsed after the due date ? : ";
	cin >> fine.days;
	cout << "\nMember should pay Rs." << fine.calculate_fine() << " /= as a fine\n\n";

	cout << "\n\n\t\t\t";
	system("pause");
	menu();
}

///////////////////// Class librarian_information

class librarian_information
{
public:
	librarian_information();		//constructor
	~librarian_information();		//destructor

	void librarian_info()
	{
		system("cls");
		system("color F0");

		if (mode == 0)
		{
			cout << "\n librarian_info()\n\n";
		}

		cout << "\n======================================================================================\n";
		cout << "\t\t\t[LIBRARIAN AND LIBRARY STAFF INFORMATION]\n";
		cout << "======================================================================================\n";
		cout << "\n\t\tLibrarian :\n";
		cout << "\t\t\tMr.Sugath Kumara\n\n";
		cout << "\t\t\tAge : 55\n";
		cout << "\t\t\tE-mail : sugathkumara20@gmail.com\n";
		cout << "\t\t\tContact : 0714567892 / 0777123789\n";
		cout << "\t\t\tAddress : 510,Bakery Road, Ratmalana\n";
		cout << "----------------------------------------------------------------------------------------\n";
		cout << "\t\tLibrary Assistant 1 :\n";
		cout << "\t\t\tMr.Janaka Perera\n\n";
		cout << "\t\t\tAge : 38\n";
		cout << "\t\t\tE-mail : janakaperera65@gmail.com\n";
		cout << "\t\t\tContact : 0754578321 / 0774521096\n";
		cout << "\t\t\tAddress : 12/A,Temple Road, Mount Lavinia\n";
		cout << "----------------------------------------------------------------------------------------\n";
		cout << "\t\tLibrary Assistant 2 :\n";
		cout << "\t\t\tMrs.Nayomi Bandara\n\n";
		cout << "\t\t\tAge : 39\n";
		cout << "\t\t\tE-mail : nayomibandara@gmail.com\n";
		cout << "\t\t\tContact : 0712546781\n";
		cout << "\t\t\tAddress : 32,Church Road, Dehiwala\n";
		cout << "----------------------------------------------------------------------------------------\n";
		
		cout << "\n\n\t\t\t";
		system("pause");
		menu();
	}
};

librarian_information::librarian_information()
{
	if (mode == 0)
		cout << "\n\n information - Constructor\n";
}

librarian_information::~librarian_information()
{
	if (mode == 0)
		cout << " information - Destructor\n";
}

void enroll_mem()		//function to select enroll member type
{
	system("cls");
	int choice;
	cout << "\n\n\n\t\tPresss 1 for Student  \n\n\t\tPresss 2 for Faculty Staff  \n\n\t\tPresss 3 for Other(outside) \n\n";
	cout << ">>>>>>> ";
	cin >> choice;

	//creating objects
	classA* ptr;
	student s3;
	facStaff s4;
	outside_member s5;

	if (choice == 1)
	{
		ptr = &s3;
		ptr->get();
	}
	if (choice == 2)
	{
		ptr = &s4;
		ptr->get();
	}
	if (choice == 3)
	{
		ptr = &s5;
		ptr->get();
	}
	else
	{
		cout << "Sorry Invalid Choice ";
		cout << "\n\n\t\t\t";
		system("pause");
		menu();
	}
}

int menu()			//Function of the main menu
{
	system("cls");
	system("color F0");
	cout << "\n";
	cout << "\t\t     **********************************************************  \n";
	cout << "\t\t                     LIBRARY MANAGEMENT SYSTEM                   \n";
	cout << "\t\t     **********************************************************  \n\n";
	cout << "\t\t         ``````````````````` MAIN MENU  ```````````````````      \n\n";

	cout << "\n\n\t\t\tPress 1 for Librarian & Library Staff Information\n\n";
	cout << "\t\t\tPress 2 for Enrolling New Member\n\n";
	cout << "\t\t\tPress 3 for Saving Book Information\n\n";
	cout << "\t\t\tPress 4 for Checking Member Information Menu\n\n";
	cout << "\t\t\tPress 5 for Checking Book Information Menu\n\n";
	cout << "\t\t\tPress 6 for Searching & Borrowing a Book\n\n";
	cout << "\t\t\tPress 7 for Receiving a Book & Calculating Fine\n\n";
	cout << "\t\t\tPress 8 to Terminate\n\n";
	cout << "----------------------------------------------------------------------------------------\n";
	cout << "Please Enter your choice : ";

	//creating objects

	librarian_information a1;
	classA* ptr;
	bookInformation a2;
	bookSearch req;
	returnBook retbook;
	outside_member outMem;
	student stuMem;
	facStaff facMem;

	int a;
	cin >> a;

	//checking inputs & Calling relevant functions accordingly
	if (a == 1)
	{
		a1.librarian_info();
	}
	else if (a == 2)
	{
		enroll_mem();
	}
	else if (a == 3)
	{
		ptr = &a2;
		ptr->get();
	}
	else if (a == 4)
	{
		cout << "\n\nChoose Member type(Student-1, Faculty Staff-2, Other(Outsider)-3) : ";
		int memType;
		cin >> memType;
		if (memType == 1)
			stuMem.show();
		else if (memType == 2)
			facMem.show();
		else if (memType == 3)
			outMem.show();
		else
			cout << "Error, Invalid choice" << endl;

	}
	else if (a == 5)
	{
		ptr = &a2;
		ptr->show();
	}
	else if (a == 6)
	{
		req.searchBook();
	}
	else if (a == 7)
	{
		retbook.returnBook_menu();
	}
	else if (a == 8)
	{
		return 0;
	}
	else
	{
		cout << "Sorry Invalid Choice ";
		cout << "\n\n\t\t\t";
		system("pause");
		menu();
	}
}

void password()			//Password function
{
	system("cls");
	system("color F0");
	if (mode == 0)
	{
		cout << "\n Type Password\n\n";
	}

	ifstream pass("password.txt");
	if (!pass)			//Creating a new password & Saving to a text file
	{
		string pswrd;
		ofstream createPass("password.txt");
		{
			cout << "\n\n\n\n\n\n\n\t\t\tEnter New Password : ";
			cin >> pswrd;
			createPass << pswrd;
		}
		createPass.close();
		cout << "\n\n\t\t\tYour Password has been saved";

		cout << "\n\n\t\t\t";
		system("pause");
		menu();
	}
	else
	{
		string a, b;
		cout << "\n\n\n\n\n\n\n\t\t\tEnter the Password : ";
		cin >> a;
		getline(pass, b);
		if (a == b)			//Checking whether the entered password is correct or not
		{
			menu();
		}
		else
		{
			cout << "\n\n\t\t\tIncorrect Password! Please Try Again\n";
			Sleep(1000);
			password();
		}
		pass.close();
	}
}

int main()
{
	cout << "\n\n\tPlease Choose the mode first\n\n";
	cout << "\t\tPress 1 for Regular Mode\n\t\tPress 0 for Education Mode\n\n\t\t>>>>>> ";
	cin >> mode;		//Selecting the mode
	password();

	return 0;

}


















