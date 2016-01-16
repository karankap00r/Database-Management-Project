//___________________________________________________________________________
/*___________________________________________________________________________
			       By - Karan Kapoor
				    Aditya Gupta
_____________________________________________________________________________
       //*************-CRUISE TRAVEL MANAGEMENT-*****************
____________________________________________________________________________
___________________________________________________________________________*/

		   /****************************
		    *INCLUDING THE HEADER FILES*
		    ****************************/
#include<iostream.h>       //for input/output stream functions
#include<conio.h>          //for functions like clrscr(),getch() etc.
#include<stdio.h>          //for functions like gets()
#include<process.h>        //for functions like exit()
#include<fstream.h>        //for file handling.
#include<ctype.h>          //for functions like gotoxy(x,y)
#include<iomanip.h>        //for functions like setw()
#include<dos.h>            //for functions like delay()
#include<string.h>         //for functions like strcmp()
//___________________________________________________________________________
//___________________________________________________________________________
		   /*****************************
		    *GLOBAL VARIABLES..........**
		    *****************************/
long int code;

//___________________________________________________________________________
		   /*********************************************
		    *CLASS DECLARATIONS AND DEFINITIONS........**
		    ********************************************/
//___________________________________________________________________________
		   /*****************************
		    *CLASS 1...................**
		    *****************************/


class persdetails     //class for collecting the personal details.
{
 private:             //private data members.
  int trvlcode;
  int  age[20];
  char name[20][20];
  char add[50];
  char phnum[15];
  char sex[20];
  char passnum[10][10];
  char familyname[30];
  int num;
  int numppl;

 public:               //public functions.

  void p_input(int cd) //function for accepting basic personal information.
  {                    //input function of class 1.
   trvlcode=cd;
   num=0;
   clrscr();
   cout<<"\n\n\t:::::::::::::::::::::: PERSONAL DETAILS :::::::::::::::::";
   cout<<":::::\n";
   cout<<"\t\t\t\t~~~~~~~~~~~~~~\n";
   cout<<"\n\t\t* Please fill in the details:\n\n\n\t\t\t1.Family Name: ";
   gets(familyname);
   cout<<"\n\t\t\t2.Address: ";
   gets(add);
   cout<<"\n\t\t\t3.Contact Number(10 Digit Mobile Number) : ";
   gets(phnum);
   cout<<"\n\n\n\t\tEnter The No of People Travelling: ";
   cin>>numppl;

   clrscr();

   if(numppl>0)
   {
    cout<<"\n\t\tPlease Enter The Details of each Member/Members: "<<endl;
    cout<<"\t\t\n";
    for(int i=0;i<numppl;i++)
    {
     clrscr();
     cout<<endl<<"\n\t\tMember "<<i+1;
     cout<<"\n\t\t~~~~~~~~";
     cout<<"\n\n\t\tFirst Name: ";
     gets(name[i]);
     cout<<"\n\t\tAge: ";
     cin>>age[i];
     cout<<"\n\t\tSex (M/F): ";
     cin>>sex[i];
     cout<<"\n\t\tPassport Number: ";
     gets(passnum[i]);
     if(age[i]>5)
     {
      num++;           //to calculate no of travellers below 5 yrs
     }
    }
   }
  }

  void p_output()      //function for output of personal information
  {                    //output function of class 1.
   clrscr();
   cout<<"\n\n\t******************** PERSONAL DETAILS ************";
   cout<<"********"<<endl;
   cout<<"\n\n\t\t\tFamily Name:\t "<<familyname<<endl;
   cout<<"\t\t\tAddress:\t "<<add<<endl;
   cout<<"\t\t\tPhone Number:\t "<<phnum<<endl;
   cout<<"\n\n\tName\t\tAge\t\tSex\t\tPassport Number\n"<<endl;
   for(int i=0;i<numppl;i++)
   {
    cout<<"\t"<<name[i]<<"\t\t"<<age[i]<<"\t\t"<<sex[i]<<"\t\t";
    cout<<passnum[i]<<endl;
   }
   getch();
  }

  void givefam()       //function for writing family name whenever needed.
  {
   cout<<familyname;
  }

  int givecode()       //function for returning travel code.
  {                    //NOTE:travel code is unique for each family.
   return trvlcode;
  }

  int give()           //function to return number of travellers below
  {                    //age of five so that it can be used in computing the
   return num;         //requisite amount in the bill.
  }

  void p1_output()      //function for output of personal information
  {                    //output function of class 1.(for query (of administrator.))
   clrscr();
   cout<<"\n\n\t\t\tFamily Name:\t "<<familyname<<endl;
   cout<<"\t\t\tAddress:\t "<<add<<endl;
   cout<<"\t\t\tPhone Number:\t "<<phnum<<endl;
   cout<<"\n\n\tName\t\tAge\t\tSex\t\tPassport Number\n"<<endl;
   for(int i=0;i<numppl;i++)
   {
    cout<<"\t"<<name[i]<<"\t\t"<<age[i]<<"\t\t"<<sex[i]<<"\t\t";
    cout<<passnum[i]<<endl;
   }
   getch();
  }



 }pob;                 //class item "pob" i.e. on which class
		       //"personal details" will be implemented.
//___________________________________________________________________________
		   /*****************************
		    *CLASS 2...................**
		    *****************************/

 class travdetails     //class which holds the travel details.
 {
  private:             //private data members.
   long int gttl;
   int trvtcode;
   int day;
   int month;
   int year;
   int num1;
   int bdg_pt;
   int go_pt;
   int deck;
   int cabin;
   int pool;
   int gym;
   int sports;
   int salon;
   int spa;
   int theatre;

  public:              //public functions and data members.


   void initial()      //function for initialising the different facilities
   {                   //in the ship.
    pool=gym=theatre=sports=salon=0;
   }

   void t_input(int cd)//function for accepting the basic travel information.
   {                   //input function of class 2.
    tob.initial();     //in this function, different facilities that can be
    trvtcode=cd;       //availed for have been asked by the user.
    int i=1,opt;
    clrscr();
    do
    {
     clrscr();
     cout<<endl;       //heading and instructions.
     cout<<"\n\n\t\t\t\t_||__TRAVEL DETAILS__";
     cout<<"\n\t\t\t\t\\___________________/";
     cout<<"\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~";
     cout<<"\n\n\t\tPlease enter the following details for your journey:";
     cout<<"\n\n\t\t*Note:Options marked with '*' are compulsory.";
     cout<<"\n\t\t\tPlease do select them.";
     cout<<"\n\n\n\t\t\t\t*1.Boarding Point\n\t\t\t\t";
     cout<<"*2.Destination\n\t\t\t\t";
     cout<<"*3.Date of Departure\n\t\t\t\t";
     cout<<"*4.Deck\n\t\t\t\t";
     cout<<" 5.Cabin\n\t\t\t\t";
     cout<<" 6.Swimming Pool\n\t\t\t\t";
     cout<<" 7.Gymnasuim\n\t\t\t\t";
     cout<<" 8.Sports\n\t\t\t\t";
     cout<<" 9.Salon\n\t\t\t\t";
     cout<<" 10.Spa\n\t\t\t\t";
     cout<<" 11.Theatre\n\t\t\t\t";
     cout<<" 12.Back\n\n\t\t\t\t ";
     cin>>opt;         //asking for choice in the travel details.
		       //(eg: boarding pt.,saloon, swimming pool etc.)

     switch(opt)       //"switch/case" has been used for different actions
     {                 //to be taken for different choices.
      case 1:clrscr();
	     cout<<"\n\n\n\t\t\tSelect Boarding point:";
	     cout<<"\n\n\t\t\t1.Mumbai\n\n\t\t\t";
	     cout<<"2.Cochin\n\n\t\t\t";
	     cout<<"3.Chennai\n\n\t\t\t ";
	     cin>>bdg_pt;
	     break;

      case 2:clrscr();
	     cout<<"\n\n\t\t\t****** Select Destination ******\n\n\n";
	     cout<<"\t 1.New York\t\t6.Dubai\t\t\t11.Antananariv";
	     cout<<"\n\n\t 2.Miami\t\t7.Lisbon\t\t12.Cairo\n\n";
	     cout<<"\t 3.Rio De Janeiro\t8.London\t\t13.Perth";
	     cout<<"\n\n\t 4.Colombo\t\t9.Copenhagen\t\t14.Sydney";
	     cout<<"\n\n\t 5.Hong Kong\t\t";
	     cout<<"10.Cape Town\t\t15.Wellington\n\n\n\n\n\t\t\t\t  ";
	     cin>>go_pt;
	     break;

      case 3:clrscr();
	     cout<<"\n\n\t Date of Departure ";
	     cout<<"\n\n   * Note:Format for entering:";
	     cout<<"Day(press enter)Month(press enter)Year *";
	     cout<<"\n\n\t\tEnter your preferred date of departure: ";
	     cin>>day;
	     gotoxy(59,7);  //to create a particular format for entry
	     cout<<"/";
	     cin>>month;
	     gotoxy(62,7);
	     cout<<"/";
	     cin>>year;
	     break;

      case 4:clrscr();
	     cout<<"\n\n\t\t\tEnter The Choice OF Deck\n\n\t\t\t";
	     cout<<"1.Top Deck\n\n\t\t\t";
	     cout<<"2.Middle Decks\n\n\t\t\t3.Bottom Deck\n\n\t\t\t ";
	     cin>>deck;
	     break;

      case 5:clrscr();
	     cout<<"\n\n\t\t\tEnter The Choice Of Cabin\n\n\t\t\t";
	     cout<<"1.AC\n\n\t\t\t2.Non AC\n\n\t\t\t ";
	     cin>>cabin;
	     break;

      case 6:clrscr();
	     cout<<"\n\n\t\tDo You Like To Avail ";
	     cout<<"The Facility Of A Swimming Pool";
	     cout<<"\n\n\t\t\t1.No\n\n\t\t\t2.Yes\n\n\t\t\t ";
	     cin>>pool;
	     pool--;
	     break;

      case 7:clrscr();
	     cout<<"\n\n\t\tDo You Like To Avail ";
	     cout<<"The Facility Of A Gymnasium";
	     cout<<"\n\n\t\t\t1.No\n\n\t\t\t2.Yes\n\n\t\t\t ";
	     cin>>gym;
	     gym--;
	     break;

      case 8:clrscr();
	     cout<<"\n\n\t\tDo You Like To Avail The Sports";
	     cout<<" Facilities Offered\n\n\t\t\t1";
	     cout<<".No\n\n\t\t\t2.Yes\n\n\t\t\t ";
	     cin>>sports;
	     sports--;
	     break;

      case 9:clrscr();
	     cout<<"\n\n\t\tDo You Like To Avail ";
	     cout<<"The Facility Of Beauty Salon\n\n\t";
	     cout<<"\t\t1.No\n\n\t\t\t2.Yes\n\n\t\t\t ";
	     cin>>salon;
	     salon--;
	     break;

     case 10:clrscr();
	     cout<<"\n\n\tDo You Like To Avail ";
	     cout<<"The Facility Of Spa and Ayurvedic ";
	     cout<<"Treatment\n\n\t\t\t1.No\n\n\t\t\t2.Yes\n\n\t\t\t ";
	     cin>>spa;
	     spa--;
	     break;

     case 11:clrscr();
	     cout<<"\n\n\t\tDo You Like To Avail The";
	     cout<<" Facility Of Amphitheatre\n\n\t";
	     cout<<"\t\t1.No\n\n\t\t\t2.Yes\n\n\t\t\t ";
	     cin>>theatre;
	     theatre--;
	     break;

     case 12:i=0;      //"i" has been assigned 0 to end the loop.
	     break;
     }
    }while(i==1);      //loop continues if the loop executer variable "i" is
   }                   //equal to its initially initialised value i.e. 1.

   void t_output()     //function to display the travel details.
   {
    clrscr();
    cout<<"\n\n\t******************* TRAVEL DETAILS ********";
    cout<<"*************";
    cout<<"\n\n\t\tBoarding Point: ";
    boardpt(bdg_pt);
    cout<<"\n\n\t\tDestination: ";
    dest(go_pt);
    cout<<"\n\n\t\tDate of departure: ";
    cout<<day<<"/"<<month<<"/"<<year;
    cout<<"\n\n\t\tDeck: ";
    switch(deck)
    {
     case 1:cout<<"Top Deck";
	    break;
     case 2:cout<<"Middle Deck";
	    break;
     case 3:cout<<"Bottom Deck";
	    break;
    }
    cout<<"\n\n\t\tCabin: ";
    switch(cabin)
    {
     case 1:cout<<"AC cabin";
	    break;
     case 2:cout<<"Non-AC cabin";
	    break;
    }
    cout<<"\n\n\n\tFacilities availed for are:";
    if(pool==1)
    cout<<"\n\t\t\t\t    Swimming Pool";
    if(gym==1)
    cout<<"\n\t\t\t\t    Gymnasuim";
    if(sports==1)
    cout<<"\n\t\t\t\t    Sports Facilities";
    if(spa==1)
    cout<<"\n\t\t\t\t    Spa and Ayurvedic Treatment";
    if(salon==1)
    cout<<"\n\t\t\t\t    Beauty Salon";
    if(theatre==1)
    cout<<"\n\t\t\t\t    Theatre";
    getch();
   }

   void compute()      //calculation of bill.
   {
    gttl=0;
    long int hr;
    long int dcst;
    long int dck;
    long int cabn;
    long int swpool=5000;
    long int gm=2000;
    long int spfts=7500;
    long int slon=6000;
    long int sp=20000;
    long int ttr=500;
    switch(go_pt)
    {
     case 1:;
     case 2:;
     case 3:hr=30*24;  //calculating the number of hours.
	    dcst=250000;
	    break;
     case 4:;
     case 5:;
     case 6:hr=7*24;
	    dcst=75000;
	    break;
     case 7:;
     case 8:;
     case 9:hr=24*24;
	    dcst=130000;
	    break;
    case 10:;
    case 11:;
    case 12:hr=15*24;
	    dcst=100000;
	    break;
    case 13:;
    case 14:;
    case 15:hr=12*24;
	    dcst=120000;
	    break;
   }
   switch(deck)
   {
    case 1:dck=7500;
	   break;
    case 2:dck=5000;
	   break;
    case 3:dck=1000;
   }
   switch(cabin)
   {
    case 1:cabn=5000;
	   break;
    case 2:cabn=2000;
	   break;
   }
   clrscr();
   cout<<"\n\n\t\t:::::::::::::::::::::: BILL ::::::::::::::::::::::::::";
   cout<<"\n\n\t\tBoarding point:\t\t ";
   boardpt(bdg_pt);
   cout<<"\n\n\t\tDestination:\t\t ";
   dest(go_pt);
   cout<<"\n\n\t\tDate of Departure: ";
   cout<<day<<"/"<<month<<"/"<<year;
   hr=hr/24;           //to calculate date of arrival
   day=day+hr;         //conversion of day ----->month &month----->year
		       //if exceeds.
   if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
   {
    if(day>31)
    {
     month=month+1;
     day=day%31;
    }
   }
   if(month==4||month==6||month==9||month==11)
   {
    if(day>30)
    {
     month=month+1;
     day=day%30;
    }
   }
   if(month==2)
   {
    if(day>28)
    {
     month=month+1;
     day=day%28;
    }
   }
   if(month==13)
   {
    month=1;
    year++;
   }
   cout<<"\n\n\t\tDate of Arrival: ";
   cout<<day<<"/"<<month<<"/"<<year;
   cout<<"\n\n\t\tSubject\t\tCost(for 1)\tNo of ppl\tTotal";
   cout<<"\n\n\t\tTravel\t\t"<<dcst<<"\t\t   "<<num1<<"\t\t"<<num1*dcst;
   gttl+=num1*dcst;
   cout<<"\n\t\tDeck\t\t"<<dck<<"\t\t   "<<num1<<"\t\t"<<dck*num1;
   gttl+=dck*num1;
   cout<<"\n\t\tCabin\t\t"<<cabn<<"\t\t   "<<num1<<"\t\t"<<cabn*num1;
   gttl+=cabn*num1;
   if(pool==1)
   {
    cout<<"\n\t\tSwimming Pool\t"<<swpool<<"\t\t   "<<num1<<"\t\t";
    cout<<swpool*num1;
    gttl+=swpool*num1;
   }
   if(gym==1)
   {
    cout<<"\n\t\tGym\t\t"<<gm<<"\t\t   "<<num1<<"\t\t"<<gm*num1;
    gttl+=gm*num1;
   }
   if(sports==1)
   {
    cout<<"\n\t\tSports\t\t"<<spfts<<"\t\t   "<<num1<<"\t\t"<<spfts*num1;
    gttl+=spfts*num1;
   }
   if(salon==1)
   {
    cout<<"\n\t\tSalon\t\t"<<slon<<"\t\t   "<<num1<<"\t\t"<<slon*num1;
    gttl+=slon*num1;
   }
   if(spa==1)
   {
    cout<<"\n\t\tSpa\t\t"<<sp<<"\t\t   "<<num1<<"\t\t"<<sp*num1;
    gttl+=dcst*num1;
   }
   if(theatre==1)
   {
    cout<<"\n\t\tTheatre\t\t"<<ttr<<"\t\t   "<<num1<<"\t\t"<<ttr*num1;
    gttl+=ttr*num1;
   }
   cout<<"\n\n\n\t\t\t Grand Total:Rs ";
   if(gttl>100000)     //to provide comma's for grandtotal
   {
    cout<<gttl/100000<<",";
    gttl=gttl%100000;
   }
   if(gttl>1000)
   {
    cout<<gttl/1000<<",";
    gttl=gttl%1000;
   }
   cout<<gttl;
   if(gttl<10)
   cout<<"00";
   cout<<" ";
   cout<<"\n\n\t! All Travellers below the age of 5 hav";
   cout<<"e not been charged !";
   getch();
  }

  int returnbill()     //function to return amount collected
  {
   return gttl;
  }

  int gtcode()         //function to return the travel code.
  {
   return trvtcode;
  }

  void accept(int c)   //function for assigning actual no. of travellers.
  {
   num1=c;
  }


 int returnday()             //function to return the day
  {
   return day;
  }


 int returnmonth()             //function to return the month
  {
   return month;
  }


 int returnyear()             //function to return the year
  {
   return year;
  }

 }tob;                 //"tob" is item of class "travel details".

//__________________________________________________________________________

		    /*********************************************
		    *CLASS DEFINITIONS AND DECLARATIONS END HERE.*
		    *********************************************/
//___________________________________________________________________________
		    /***************************************
		    *SOME FUNCTIONS NOT PART OF THE CLASSES*
		    ****************************************/

		   /*THE FUNCTIONS BELOW ARE FOR :
		     -->INCREASING THE EASE OF INPUT/OUTPUT FOR THE PROGRAMMER
		     -->CHECKING THE EXISTENCE OF A PARTICULAR RECORD.
		     -->DELETION OF RECORDS.
		     -->EDITION OF RECORDS.*/
//___________________________________________________________________________
		    /******************************
		    *FIRST OUTSIDE CLASS FUNCTION *
		    ******************************/

 void boardpt(int c)   //function to increase the ease of input/output.
 {
  if(c==1)
  cout<<"Mumbai\t";
  if(c==2)
  cout<<"Cochin\t";
  if(c==3)
  cout<<"Chennai\t";
 }
//___________________________________________________________________________
		    /******************************
		    *SECOND OUTSIDE CLASS FUNCTION*
		    ******************************/

 void dest(int d)      //function to increase the ease of input/output.
 {
  switch(d)
  {
    case 1:cout<<"New York";
	    break;
    case 2:cout<<"Miami";
	    break;
    case 3:cout<<"Rio De Janero";
	    break;
    case 4:cout<<"Colombo";
	    break;
    case 5:cout<<"Hong Kong";
	    break;
    case 6:cout<<"Dubai";
	    break;
    case 7:cout<<"Lisbon";
	    break;
    case 8:cout<<"London";
	    break;
    case 9:cout<<"Copenhagen";
	    break;
    case 10:cout<<"Cape Town";
	    break;
    case 11:cout<<"Antananriv";
	    break;
    case 12:cout<<"Cairo";
	    break;
    case 13:cout<<"Perth";
	    break;
    case 14:cout<<"Sydney";
	    break;
    case 15:cout<<"Willington";
	    break;
  }
 }

//___________________________________________________________________________
		    /******************************
		    *THIRD OUTSIDE CLASS FUNCTION *
		    ******************************/

 void family(int c,int&flag)  //function to display family name and
 {                            // to check for record.
  flag=0;
  clrscr();
  ifstream ifl("PersonalDetails.txt",ios::binary);
  if(!ifl)
  cout<<"\nError";
  ifl.read((char*)&pob,sizeof(pob));
  while(!ifl.eof())
  {
   if(pob.givecode()==c)
   {
    flag=1;
    break;
   }
   ifl.read((char*)&pob,sizeof(pob));
  }
  if(flag==1)
  {
   cout<<"\n\n\t\t ****** ";
   pob.givefam();
   cout<<"'s FAMILY DATABASE ******";
  }
  else
  {
   cout<<"\nError in locating record!!";
  }
  ifl.close();
 }
//___________________________________________________________________________
		    /******************************
		    *FOURTH OUTSIDE CLASS FUNCTION*
		    ******************************/

 void editp(int c)     //function to edit personal information.
 {
  ofstream ofl2("temp1.txt",ios::binary);
  if(!ofl2)
  cout<<"Error While Opening File";
  ifstream ifl4("PersonalDetails.txt",ios::binary);
  if(!ifl4)
  cout<<"Error While Opening File";
  ifl4.read((char*)&pob,sizeof(pob));
  while(!ifl4.eof())
  {
   if(pob.givecode()==c)
   {
    clrscr();
    cout<<"Please Enter the New details of the record"<<endl;
    pob.p_input(c);
    ofl2.write((char*)&pob,sizeof(pob));
    cout<<"\n\t\t\tModification Succesful!!!";
    ifl4.read((char*)&pob,sizeof(pob));
   }
   else
   {
    ofl2.write((char*)&pob,sizeof(pob));
    ifl4.read((char*)&pob,sizeof(pob));
   }
  }
  remove("PersonalDetails.txt");
  rename("temp1.txt","PersonalDetails.txt");
  ifl4.close();
  ofl2.close();
  getch();
 }
//___________________________________________________________________________
		    /******************************
		    *FIFTH OUTSIDE CLASS FUNCTION *
		    ******************************/

 void editt(int c)  //function to edit travel details.
 {
  ofstream ofl2("temp1.txt",ios::binary);
  if(!ofl2)
  cout<<"Error While Opening File";
  ifstream ifl4("TravelDetails.txt",ios::binary);
  if(!ifl4)
  cout<<"Error While Opening File";
  ifl4.read((char*)&tob,sizeof(tob));
  while(!ifl4.eof())
  {
   if(tob.gtcode()==c)
   {
    clrscr();
    cout<<"Please Enter the New details of the record"<<endl;
    tob.t_input(c);
    ofl2.write((char*)&tob,sizeof(tob));
    cout<<"\n\t\t\tModification Succesful!!!";
    ifl4.read((char*)&tob,sizeof(tob));
   }
   else
   {
    ofl2.write((char*)&tob,sizeof(tob));
    ifl4.read((char*)&tob,sizeof(tob));
   }
  }
  remove("TravelDetails.txt");
  rename("temp1.txt","TravelDetails.txt");
  ifl4.close();
  ofl2.close();
  getch();
 }
//___________________________________________________________________________
		    /******************************
		    *SIXTH OUTSIDE CLASS FUNCTION.*
		    ******************************/

		    /******************************
		    *FUNCTION FOR DELETION........*
		    ******************************/

 void deletion(int c)
 {
  ofstream ofl2("temp1.txt",ios::binary);
  if(!ofl2)
  cout<<"Error While Opening File";
  ifstream ifl4("PersonalDetails.txt",ios::binary);
  if(!ifl4)
  cout<<"Error While Opening File";
  ifl4.read((char*)&pob,sizeof(pob));
  while(!ifl4.eof())
  {
   if(pob.givecode()!=c)
   {
    ofl2.write((char*)&pob,sizeof(pob));
   }
   ifl4.read((char*)&pob,sizeof(pob));
  }
  remove("PersonalDetails.txt");
  rename("temp1.txt","PersonalDetails.txt");
  ofl2.close();
  ifl4.close();
  ofstream ofl3("temp2.txt",ios::binary);
  if(!ofl3)
  cout<<"\nError While Opening File";
  ifstream ifl5("TravelDetails.txt",ios::binary);
  if(!ifl5)
  cout<<"\nError While Opening File";
  ifl5.read((char*)&tob,sizeof(tob));
  while(!ifl5.eof())
  {
   if(tob.gtcode()!=c)
   {
    ofl3.write((char*)&tob,sizeof(tob));
   }
   ifl5.read((char*)&tob,sizeof(tob));
  }
  ofl3.close();
  ifl5.close();
  remove("TravelDetails.txt");
  rename("temp1.txt","TravelDetails.txt");
  cout<<"\n\n\t\tDeletion Completed!";
  getch();
 }
//___________________________________________________________________________
		    /***********************************
		    *OUTSIDE CLASS FUNCTIONS END HERE..*
		    ***********************************/
//___________________________________________________________________________
		    /**********************************
		    *VOID MAIN FUNCTION...............*
		    **********************************/

 void main()
 {
  clrscr();            //welcome screen.
  int choice,k,ch,dd,mm,yy,ch2;
  int sum;
  unsigned long int max=0;
  int code1,code2,count;
  char str[30];
  cout<<"\n\n\n\n\n";
  cout<<"              **      :::::::  !!!!!!!!           \n";
  cout<<"           _____  **      ::       !!    !!         _____  \n";
  cout<<"                **      ::       !!    !!                \n";
  cout<<"              ******  :::::::  !!!!!!!!            \n";
  cout<<"\n\n\n\n\n";
  cout<<"	      ~	__  ~ __  ~ __                  \n";
  cout<<"	       |==|  |==|  |==|                 \n";
  cout<<"	     __|__|__|__|__|__|_                \n";
  cout<<"	  __|___________________|___            \n";
  cout<<"       __|__[]__[]__[]__[]__[]__[]__|___         CRUISE DATABASE MANAGEMENT\n";
  cout<<"      |............................o.../ \n";
  cout<<"      \\.............................../ \n";
  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
  cout<<" ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ \n";
  cout<<"  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~\n";
  cout<<"    ~    ~     ~    ~    ~    ~    ~    ~    ~  \n";
  cout<<"     ~    ~      ~    ~     ~    ~    ~      ~\n";
//___________________________________________________________________________
		       //welcome screen ends.
//___________________________________________________________________________

  ifstream fl("INITIALL.txt",ios::binary); //initialisation of code
  if(!fl)
  cout<<"\nError";
  fl.read((char*)&code,sizeof(code));
  fl.close();
  int opt,opt1,opt2,opt3,opt4;
  int acceptcode,flag;
  getch();

//___________________________________________________________________________
		    /**********************************
		    *LOGIN SCREEN.....................*
		    **********************************/
  clrscr();
  bm1:;                                    //bm1=bookmark1.
  cout<<"\n\n\n\n\t\t\tPlease enter your identity:-";
  cout<<"\n\n\t\t\t\t1.Administrator";
  cout<<"\n\n\t\t\t\t2.Passenger";
  cout<<"\n\n\t\t\t\tChoice  :";
  cin>>choice;
  clrscr();
  if(choice==1)
  {
   pass:;
   cout<<"\n\n\tKindly enter your password\n";
   cout<<"\n\t\tThe password entered should be in small letters. :\t";
   str[0]=getch();
   cout<<"*";
   str[1]=getch();
   cout<<"*";
   str[2]=getch();
   cout<<"*";
   str[3]=getch();
   cout<<"*";
   str[4]=getch();
   cout<<"*";
   str[5]='\0';
   cout<<"*";
   if(strcmp(str,"admin")==0)
   {
    cout<<"\n\n\n\t\tPLEASE WAIT WHILE\n\t\tTHE REQUISITE DATABASE IS LOADING";
    delay(150);
    cout<<".";
    delay(150);
    cout<<".";
    delay(150);
    cout<<".";
    delay(150);
    cout<<".";
    delay(150);
    cout<<".";
    delay(150);
    cout<<".";
    delay(150);
    cout<<".";
    delay(150);
    cout<<".";
    delay(150);
    cout<<".";
    delay(150);
    cout<<".";
    delay(200);
    goto bm3;
   }
   else
   {
    cout<<"\n\n\t\t\t Ooop's wrong password \n";
    getch();
    k++;
    if(k==3)
    {
     cout<<"\nGoing back to the main screen.\n";
     goto bm1;
     getch();
    }
    goto pass;
   }
  }
  else
  {
   goto bm5;
  }                             //bm5=bookmark5

//___________________________________________________________________________
//___________________________________________________________________________
//PROVIDING INFORMATION ABOUT THE SOFTWARE...................................
//___________________________________________________________________________
//___________________________________________________________________________

  clrscr();
  bm2:;
  cout<<"\n\t\t\t\t";
  cout<<"\n\t\t\tWELCOME";
  cout<<"\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  cout<<"\n\n\n";
  cout<<"\tWELCOME TO THE 'QUEEN OF THE OCEAN'\n";
  cout<<"\tTHIS SHIP OFFERS YOU SEVERAL OPPORTUNITIES TO UNRAVEL THE SECRETS";
  cout<<"\n\tHIDDEN IN THE OCEAN AND HAVE FUN AT THE CRUISE........";
  cout<<"\n\tTHERE ARE VERY SIMPLE THINGS WHICH YOU HAVE TO DO";
  cout<<"\n\tENTER YOUR DETAILS .DON'T WORRY! THEY WILL BE KEPT CONFIDENTIAL.";
  cout<<"\n\tENTER YOUR PERSONAL DETAILS AND YOUR TRAVEL DETAILS ";
  cout<<"\n\tAND WE HELP YOU REACH THERE HAVING A GOOD TIME WITH YOUR NEAR ONES";
  cout<<"\n\tWE HOPE THAT YOU WILL BE SATISFIED WITH OUR SERVICE.";
  cout<<"\n\n\nIN CASE OF ANY FURTHER INFORMATION REQUIRED YOU CAN CONTACT OUR MANGER:";
  cout<<"\n\n\t                            MR. ADITYA GUPTA";
  cout<<"\n\t\t                    CONTACT NUMBER:9990586869";
  cout<<"\n\n\t                            MR. KARAN KAPOOR";
  cout<<"\n\t\t                    CONTACT NUMBER:9910050639";
  getch();
//____________________________________________________________________________
//____________________________________________________________________________
//OPTIONS FOR ADMINISTRATOR
//____________________________________________________________________________
//____________________________________________________________________________
  bm3:;
  clrscr();
  do
  {
   clrscr();
   cout<<"\n    \t\t         \n";
   cout<<"\t\t  ADMINISTRATOR  \n";
   cout<<"\t\t         \n\n";
   cout<<"\t\t         \n";
   cout<<"\t\t MAIN MENU \n";
   cout<<"\t\t         \n\n";
   cout<<"\n\t\t\tPlease select an action to opeerate.\n\n\t\t";
   cout<<"1.See existing database.\n\n\t\t";
   cout<<"2.Delete records before a certain date.\n\n\t\t";
   cout<<"3.Know amount collected on a certain date.\n\n\t\t";
   cout<<"4.Count total no of people to whom no amount has been charged\n\n\t\t";
   cout<<"5.See the details of the family with maximum bill amount.\n\n\t\t";
   cout<<"6.Exit\n\n\t\t";
   cout<<"Please enter your choice.     :";
   cin>>ch;
   switch(ch)
   {
    case 1:{
	    clrscr();
	    cout<<"\n\n\n\tEnter date whose database is to be displayed.\n";
	    cout<<"\t\tEnter day(dd) :";
	    cin>>dd;
	    cout<<"\n\t\tEnter month(mm) :";
	    cin>>mm;
	    cout<<"\n\t\tEnter year(yy) :";
	    cin>>yy;
	    clrscr();
	    ifstream fin1("TravelDetails.txt",ios::binary);
	    ifstream ifl("PersonalDetails.txt",ios::binary);
	    if(!ifl)
	    cout<<"\nError";
	    ifl.read((char*)&pob,sizeof(pob));
	    while(!ifl.eof())
	    {
	     fin1.read((char*)&tob,sizeof(tob));
	     if(tob.returnyear()==yy)
	     {
	      if(tob.returnmonth()==mm)
	      {
	       if(tob.returnday()==dd)
	       {
		cout<<"\n\n\t******************** PERSONAL DETAILS ************";
		cout<<"********"<<endl;
		pob.p1_output();
	       }
	      }
	     }
	     ifl.read((char*)&pob,sizeof(pob));
	    }
	    ifl.close();
	    fin1.close();
	    getch();
	   }
	   break;
    case 2:{                  //not working properly............
	    clrscr();

	    cout<<"\n\n\n\t";
	    cout<<"Enter the date before which records are to be deleted.\n";
	    cout<<"\t\tEnter day(dd) :";
	    cin>>dd;
	    cout<<"\n\t\tEnter month(mm) :";
	    cin>>mm;
	    cout<<"\n\t\tEnter year(yy) :";
	    cin>>yy;

	    ifstream fin1("TravelDetails.txt",ios::binary);
	    ofstream fout("temp10.txt",ios::binary);
	    while(!fin1.eof())
	    {
	     fin1.read((char*)&tob,sizeof(tob));
	     fout.write((char*)&tob,sizeof(tob));
	    }
	    fin1.close();
	    fout.close();

	    ifstream fin("temp10.txt",ios::binary);
	    if(!fin)
	    cout<<"\nError While Opening File";
	    while(!fin.eof())
	    {
	     fin.read((char*)&tob,sizeof(tob));
	     if(tob.returnyear()<=yy)
	     {
	      if(tob.returnmonth()<=mm)
	      {
	       if(tob.returnday()<=dd)
	       {
		deletion(tob.gtcode());
	       }
	      }
	     }
	    }
	    fin.close();
	    getch();
	   }
	   break;
    case 3:{
	    clrscr();
	    sum=0;
	    cout<<"\n\n\n\tEnter date on which total amount collected is to be displayed.\n";
	    cout<<"\t\tEnter day(dd) :";
	    cin>>dd;
	    cout<<"\n\t\tEnter month(mm) :";
	    cin>>mm;
	    cout<<"\n\t\tEnter year(yy) :";
	    cin>>yy;
	    clrscr();
	    ifstream fin1("TravelDetails.txt",ios::binary);
	    while(!fin1.eof())
	    {
	     fin1.read((char*)&tob,sizeof(tob));
	     sum+=tob.returnbill();
	    }
	    cout<<"\n\n\n\tTotal amount collected is :"<<sum;
	    fin1.close();
	    getch();
	   }
	   break;
    case 4:{
	    clrscr();
	    count=0;
	    ifstream fin100("PersonalDetails.txt",ios::binary);
	    while(!fin100.eof())
	    {
	     fin100.read((char*)&pob,sizeof(pob));
	     count=count+pob.give();
	    }
	    cout<<"\n\n\n\tTotal no of people to whom no amount has been charged is :"<<count;
	    fin100.close();
	    getch();
	   }
	   break;
    case 5:{
	    clrscr();
	    ifstream fin1("TravelDetails.txt",ios::binary);
	    ifstream ifl("PersonalDetails.txt",ios::binary);
	    if(!ifl)
	    cout<<"\nError";
	    ifl.read((char*)&pob,sizeof(pob));
	    while(!ifl.eof())
	    {
	     fin1.read((char*)&tob,sizeof(tob));
	     if(tob.returnbill()>max)
	     {
	      max=tob.returnbill();
	      code1=tob.gtcode();
	      code2=pob.givecode();
	     }
	     ifl.read((char*)&pob,sizeof(pob));
	    }
	    ifl.close();
	    fin1.close();

		    //view personal details.

	    ifstream fin20("PersonalDetails.txt",ios::binary);
	    if(!fin20)
	    cout<<"\nError";
	    fin20.read((char*)&pob,sizeof(pob));
	    while(!fin20.eof())
	    {
	     if(pob.givecode()==code1)
	     {
	      break;
	     }
	    fin20.read((char*)&pob,sizeof(pob));
	    }
	    pob.p_output();
	    fin20.close();

		//view travel details.

	    ifstream ifl40("TravelDetails.txt",ios::binary);
	    if(!ifl40)
	    cout<<"\nError";
	    ifl40.read((char*)&tob,sizeof(tob));
	    while(!ifl40.eof())
	    {
	     if(tob.gtcode()==code2)
	     {
	      break;
	     }
	     ifl40.read((char*)&tob,sizeof(tob));
	    }
	    tob.t_output();
	    ifl40.close();
	    getch();
	   }
	   break;
    case 6:{
	    goto bm4;
	   }
	   break;
    default:
	   {
	    cout<<"\n\n\n\t\tInvalid input.";
	    goto bm4;
	   }
   }
   getch();
  }while(ch!=6);
//____________________________________________________________________________
//____________________________________________________________________________
  clrscr();
  do
  {
   bm5:;                 //main menu.
   clrscr();
   cout<<"\n\n\t\t\n";
   cout<<"\t\t ....WELCOME TO THE CRUISE DATABASE SYSTEM....\n";
   cout<<"\t\t\n\n\n";
   cout<<"\t\t         \n";
   cout<<"\t\t MAIN MENU \n";
   cout<<"\t\t         \n\n";
   cout<<"\n\t\t\tPlease select a kind of user:";
   cout<<"\n\n\t\t\t\t1.New User\n\n\t\t\t\t2.Existing User\n\n\t\t\t\t";
   cout<<"3.Exit";
   cout<<"\n\n\t\t\t\t ";
   cin>>opt;
   switch(opt)         //different actions as per different choices.
   {
    case 1:do          //for new user.
	   {
	    clrscr();
	    cout<<"\n\n\n\t\t\t\t    NEW USER\n";
	    cout<<"\t\t\t\t    ********\n\n";
	    cout<<"\n\n\t\t\tChoose the type of details you want to enter:";
	    cout<<"\n\n\t\t\t\t1.Personal Details\n\n\t\t\t";
	    cout<<"\t2.Travel Details\n\n\t\t\t\t3.Back\n\n\t\t\t\t ";
	    cin>>opt1;

	    switch(opt1)        //different actions as per different choices.
	    {
		 case 1:code++; //for personal information.
			pob.p_input(code);
			ofstream ofl("PersonalDetails.txt",ios::binary|ios::app);
			if(!ofl)
			cout<<"\n\n\t\tSorry.The Fi";
			cout<<"le Cannot Be Opened For Writing"<<endl;
			ofl.write((char*)&pob,sizeof(pob));
			ofl.close();
			break;

		 case 2:tob.t_input(code);//for travel information.
			ofstream ofl1("TravelDetails.txt",ios::binary|ios::app);
			if(!ofl1)
			cout<<"\n\n\t\tSorry.The File Cannot Be Opened For Writing"<<endl;
			ofl1.write((char*)&tob,sizeof(tob));
			ofl1.close();
			clrscr();
			cout<<"\n\n\n\n!!!!!Your Details Have Been Registered.Please Make A Note Of This Code: "<<code;
			cout<<"\n\n* For modifications,Please visit 'existing user' section in the main screen";
			getch();
			break;

	    }
	   }while(opt1!=3);//loop continues till exit is not selected.
	   break;

    case 2:clrscr();   //for existing user.
	   cout<<"\n\n\t\t\t***** EXISTING USER *****\n\n\t\tPlease Enter The Travel Code That Was Given To You\n\n\t\t\t ";
	   cin>>acceptcode;

	   if(acceptcode>code)
	   {
	    cout<<"\nNo such record has been created!";
	    break;
	   }

	   family(acceptcode,flag);
	   cout<<endl<<endl<<"\t\t\t\tCode no:"<<acceptcode;

	   getch();

	   if(flag==1)
	   {
	    do         //information centre.
	    {
	     clrscr();
	     cout<<"\n\n\t\t\t@@@@@@@@@ Information Centre @@@@@@@@@";
	     cout<<"\n\t\t\t\t  ~~~~~~~~~~~~~~~~~";
	     cout<<"\n\n\tPlease select the type of operation that";
	     cout<<" you would like to perform:";
	     cout<<"\n\n\t\t\t1.View Personal ";
	     cout<<"Details\n\n\t\t\t2.";
	     cout<<"View Travel Details\n\n\t\t\t3";
	     cout<<".Edit Details\n\n\t\t\t";
	     cout<<"4.Compute Bill\n\n\t\t\t5.Back\n\n\t\t\t ";
	     cin>>opt2;
	     switch(opt2)
	     {
	      case 1:  //view personal details.
		     ifstream ifl("PersonalDetails.txt",ios::binary);
		     if(!ifl)
		     cout<<"\nError";
		     ifl.read((char*)&pob,sizeof(pob));
		     while(!ifl.eof())
		     {
		      if(pob.givecode()==acceptcode)
		      {
		       break;
		      }
		      ifl.read((char*)&pob,sizeof(pob));
		     }
		     pob.p_output();
		     ifl.close();
		     break;

	      case 2://view travel details.
		     ifstream ifl1("TravelDetails.txt",ios::binary);
		     if(!ifl1)
		     cout<<"\nError";
		     ifl1.read((char*)&tob,sizeof(tob));
		     while(!ifl1.eof())
		     {
		      if(tob.gtcode()==acceptcode)
		      {
		       break;
		      }
		      ifl1.read((char*)&tob,sizeof(tob));
		     }
		     tob.t_output();
		     ifl1.close();
		     break;

	      case 3://edition.
		     do
		     {
		      clrscr();
		      cout<<"\n\n\n\t Edit Details ";
		      cout<<"\n\n\t\tPlease select from among the editing options:\n\n";
		      cout<<"\t\t\t\t1.Modify\n\n\t\t\t\t2.Delete\n\n\t\t\t\t3.Back\n\n\t\t\t\t ";
		      cin>>opt3;
		      switch(opt3)
		      {
		       case 1:do    //modification.
			      {
			       clrscr();
			       cout<<"\n\n\t\t Modificaton \n";
			       cout<<"\t\t               ~~~~~~~~~~~";
			       cout<<"\n\n\tChoose The Type Of Details You Want To Modify:\n\n\t\t\t1.Personal Details\n\n\t\t\t2.Travel Details\n\n\t\t\t3.Back\n\n\t\t\t ";
			       cin>>opt4;
				switch(opt4)
				{
				 case 1:editp(acceptcode);
					break;
				 case 2:editt(acceptcode);
					break;
				 case 3:break;
				}
			       }while(opt4!=3);
			       break;

		       case 2:deletion(acceptcode);  //deletion.
			      opt3=3;
			      opt2=5;
			      break;

		       case 3:break;                 //back to main menu.
		      }
		     }while(opt3!=3);
		     break;

	      case 4://computation of bill.
		     ifstream ifl3("PersonalDetails.txt",ios::binary);
		     if(!ifl3)
		     cout<<"\nError";
		     ifl3.read((char*)&pob,sizeof(pob));
		     while(!ifl3.eof())
		     {
		      if(pob.givecode()==acceptcode)
		      {
		       break;
		      }
		      ifl3.read((char*)&pob,sizeof(pob));
		     }
		     ifstream ifl2("TravelDetails.txt",ios::binary);
		     if(!ifl2)
		     cout<<"\nError";
		     ifl2.read((char*)&tob,sizeof(tob));
		     while(!ifl2.eof())
		     {
		      if(tob.gtcode()==acceptcode)
		      {
		       break;
		      }
		      ifl2.read((char*)&tob,sizeof(tob));
		     }
		     tob.accept(pob.give());
		     tob.compute();
		     ifl2.close();
		     break;

	      case 5:break;       //for exit.
	     }
	    }while(opt2!=5);
	   }
	   break;

    case 3:            //exit from the output screen.
	   bm4:;
	   ofstream fil("INITIALL.txt",ios::binary); //storing code value
	   if(!fil)
	   cout<<"\nError";
	   fil.write((char*)&code,sizeof(code));
	   fil.close();
	   clrscr();
	   cout<<"\n\n";
	   cout<<"	         _/_/_/_/_/  _/                            _/            \n";
	   cout<<"	            _/      _/_/_/      _/_/_/  _/_/_/    _/  _/         \n";
	   cout<<"	           _/      _/    _/  _/    _/  _/    _/  _/_/            \n";
	   cout<<"	          _/      _/    _/  _/    _/  _/    _/  _/  _/           \n";
	   cout<<"	         _/      _/    _/    _/_/_/  _/    _/  _/    _/          \n";
	   cout<<"                                                                  \n";
	   cout<<"                                                                  \n";
	   cout<<"                                                                  \n";
	   cout<<"		         _/     _/                                       \n";
	   cout<<"		          _/  _/    _/_/    _/    _/                     \n";
	   cout<<"		            _/    _/    _/  _/    _/                     \n";
	   cout<<"		            _/    _/    _/  _/    _/                     \n";
	   cout<<"		           _/      _/_/      _/_/_/                     \n\n";
	   cout<<"\t    |===|						~~\n";
	   cout<<"   	   _|   |____________________________________________|| ||___	";
	   cout<<"\t\t    |_|_|_|_\__()____()____()______()______()_____()__||_||__/"<<endl;
	   cout<<"\t    `.==---------|_|----|_|-----|_|----|_|-----------------/"<<endl;
	   cout<<"\t      `.__________________________________________________/"<<endl;
	   cout<<"..........oOoOo~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	   cout<<".........oOoOo~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	   cout<<".........oooo~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	   getch();
	   exit(0);
   }
   getch();
  }while(1);           //Infinite loop till exit selected.
 }
		    /***********************************
		    *VOID MAIN FUNCTION ENDS HERE......*
		    ***********************************/
//___________________________________________________________________________
//___________________________________________________________________________
		    /*****************************
		    *PROGRAM ENDS HERE...........*
		    ******************************/
//___________________________________________________________________________
//___________________________________________________________________________
