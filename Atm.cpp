#include<iostream>
#include<conio.h>
#include<string>
using namespace std;

/*Mini Project - ATM
   *Check balance
   *Cash withdrwal
   *User details
   *Update mobile no.
*/

class atm                                              // class atm
{                                                 
    private: long int account_no;                         //private member variables
     string name;
     int PIN;
     long int balance;
     string mobile_no;

 public:                                              //public memeber fuctions

      // setData function is setting the data into the private member variables
 
    void setData( long int account_no_a, string name_a, int PIN_a ,double balance_a, string mobile_no_a)
   {
     account_no = account_no_a;
     name=name_a;
     PIN=PIN_a;                           //assigning the formal arguments to private memeber variables
     balance=balance_a;
     mobile_no=mobile_no_a;
    }

   //get Functions are used to return the values stored in memeber variables
    long int getAccountNo()
   {
     return account_no;
     }

   string getName()
  {
     return name;
     }

  int getPIN()
  {
     return PIN;
     }

   long int getBalance()
   {
     return balance;
     }

   string getMobileNO()
   {
      return mobile_no;
     }

   //setMobile function is to update the user Mobile no.
    void setMobile(string mob_prev, string mob_new)
   {
      if(mob_prev==mobile_no)              
       {
         mobile_no=mob_new;
         cout<<"Successfully updated Mobile no."<<endl;
         getch();
        }
        else
        {
         cout<<"Incorrect !!! Old Mobile No."<<endl;
         getch();
         }
    }



  //cashWithdraw function is to withdraw cash from the atm
 void cashWithDraw(int amount_a)
  { 
     if(amount_a > 0 && amount_a < balance)           //checks entered amount validity
     {
         balance = balance-amount_a;            
         cout<<"Please collect your cash"<<endl;
         cout<<"Available Balance :"<<balance<<endl;
         getch();                                      //getch()holds the screen until user presses any key
         }
     else
        {

         cout<<"Invali Input or Insufficient Balance";
         getch();
    
        }
    }

};


//////////////////////////////////////////
int main()

{
    int choice=0; int enterPIN;
    long int accountNo;

    system("cls");
    
    atm user1;                             //created user(object)
    //set user details into object  (default value)
    user1.setData(1234567,"Irshad",4567,50000000.00,"6361233148");


    do
    {
        system("cls");
     cout<<"*****WELCOME TO ATM*****"<<endl;
     cout<<"Enter your account no."<<endl;
     cin>>accountNo;

      cout<<"Enter your PIN"<<endl;
      cin>>enterPIN;


      if(accountNo==user1.getAccountNo() && enterPIN==user1.getPIN())
       {    
         do {
        
             int amount =0;
             string oldMobileNo, newMobileNo;

             system("cls");
             cout<<"*****WELCOME TO ATM*****"<<endl;
             cout<<"Select Options"<<endl;
             cout<<"1. Check Balance"<<endl;
             cout<<"2. Cash Withdrawl"<<endl;
             cout<<"3. Show User Details"<<endl;
              cout<<"4. Update Mobile No."<<endl;
             cout<<"5. Exit"<<endl;
             cin>>choice;                                 //taking users choice


             switch(choice)                                //switch statement
               {
                 case 1: cout<<"Your bank balance is :"<<user1.getBalance()<<endl;
                 getch();
                 break;                                         //getBalance gives users balance
    
                 case 2: cout<<"Enter the amount :"<<endl;
                 cin>>amount;
                  user1.cashWithDraw(amount);                       //calling withDrwaw function
                 break;                                            //passing withdrwa amount
       
                 case  3: cout<<"****User Details are****"<<endl;
                 cout<<"Account No."<<user1.getAccountNo()<<endl;
                 cout<<"Name:"<<user1.getName()<<endl;                //getting and printing user detauls
                 cout<<"Balance :"<<user1.getBalance()<<endl;
                 cout<<"Mobile No."<<user1.getMobileNO()<<endl;

                   getch();
                   break;

                 case 4: cout<<"Enter Old Mobile No."<<endl;
                 cin>>oldMobileNo;                                 //taking old no.

                 cout<<"Enter New Mobile No."<<endl;
                 cin>>newMobileNo;                                 //asking new no.

                 user1.setMobile(oldMobileNo,newMobileNo);
                 break;                                            //passing old and new to setMobile()
      
                 case 5: 
                  exit(0);                                        //exits application

                 default: cout<<"Enter Valid Data!!"<<endl;
                 }  
             } while(1);
            
       
        }
        else
        {
            cout<<"User Details are Invalid"<<endl;
            getch();
        }
    
    } while(1);   
    
 return 0;
}
