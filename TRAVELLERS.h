#include <iostream>//for basic input output
#include <cmath>//for rounding up function
#include <string.h>//for string compare and strings
#include <fstream>//for file handling
#include <stdio.h>//for getch
#include <conio.h>//for seek 
#include <ctime>//for calculating diffrence in time

using namespace std;


//customer class and function  by Hardik

class Customer
{
protected:
    
   char name[25], email[15], city[10], phone_no[10], gender[5], address[20];
    int age,DOB;
    

public:
int userid;//User id (MAIN)
    
    //USER DETAILS FUNCTION
    
    void Cust_det() //loading values from user
    {
        cout << "\t\t\tName: " << name << endl;
        cout << "\t\t\tAge: " << age << endl;
        cout << "\t\t\tPhone Number: " << phone_no << endl;
        cout << "\t\t\tAddress: " << address << endl;
        cout << "\t\t\tGender: " << gender << endl;
    }
    
    int getuserid() // acessor function
    {
        return userid;
    }

   
    void getuserdetails(void) //entering values from user
    {
       int use;
        cout << "\n\t\t\tEnter your Name :- ";
        cout<<"\n\n\t\t\t";
        cin.ignore();
        cin.getline(name,50);
        cout<<"\n";
        cout << "\t\t\tEnter your Phone Number :- ";
        cout<<"\n\n\t\t\t";
        cin.ignore();
        cin>>phone_no;
        cout<<"\n";
        cout << "\t\t\tEnter your gender(M/F) :- ";
        cout<<"\n\n\t\t\t";
        cin.ignore();
        cin.getline(gender,5);
        cout<<"\n";
        cout << "\t\t\tEnter your E-mail :- ";
        cout<<"\n\n\t\t\t";
        cin.ignore();
        cin.getline(email,15);
        cout<<"\n";
        cout << "\t\t\tEnter your age :- ";
        cout<<"\n\n\t\t\t";
        cin >> age;
        cout << "\t\t\tEnter your Address :-";
        cout<<"\n\n\t\t\t";
        cin.ignore();
        cin.getline(address,20);
        cout<<"\n";
        cout<<"\t\t\tEnter your Date of Birth (in DDMMYYYY) :-";
        cout<<"\n\n\t\t\t";
        cin>>DOB;
        cout<<"\n";
        userid=DOB/10000;
        // userid=itoa(DOB/10000);
        
        // userid=static_cast<char>(use);
        cout<<"\t\t\tYour user id generated is "<<userid<<endl;
        cout<<"\t\t\tUse the coupon code \"HEK10\" for your first flight booking and get 10% discount";
        cout<<"\t\t\t\nPress any key....";
        // getch();

        //  createfile_c(Customer cs);
    }

    // void usd(int y)  // acessor function
    // {
    //     userid=y;
    // }

    //PAYMENT

    void payment(void)
    {
        int  expiry_date, choice1, bank,bank_user_id;
        char password[50],card[16],cvv[3];
        cout <<"\n\n\n\t\t\tHow would you like to pay?:\n";
        cout <<"\n\t\t\t(1)Debit Card"; 
        cout<<"\n\t\t\t(2)Credit Card\n"; 
        cout<<"\n\t\t\t(3)Net Banking\n";
        cout <<"\n\t\t\tEnter your choice";
        cout<<"\n\t\t\t";
        cin >> choice1;
        switch (choice1) //switch case
        {
        case 1: //condition
            cout << "\n\t\t\tEnter card no.:";
            cout<<"\n\n\t\t\t";
            cin >> card;
            cout << "\n\t\t\tEnter expiry date:";
            cout<<"\n\n\t\t\t";
            cin >> expiry_date;
            cout << "\n\t\t\tEnter CVV no.:";
            cout<<"\n\n\t\t\t";
            cin >> cvv;
            cout << "\n\t\t\tTransaction Successful\n";
            cout << "\t\t\tDon't worry!\n Your Data is not saved by us.";
            break;
        case 2: //condition
            cout << "\n\t\t\tEnter card no.:";
            cout<<"\n\n\t\t\t";
            cin >> card;
            cout<<"\n";
            cout << "\n\t\t\tEnter expiry date:";
            cout<<"\n\n\t\t\t";
            cin >> expiry_date;
             cout<<"\n";
            cout << "\n\t\t\tEnter password:";
            cout<<"\n\n\t\t\t";
            cin >> password;
             cout<<"\n";
            cout << "\n\t\t\tTransaction Successful\n";
            cout << "\t\t\tDon't worry!\n Your Data is not saved by us.";
            break;
        case 3: //condition
            cout << "\t\t\tBanks Available: \n1.West Pac Bank(1) \n2.Nabil Bank(2) \n3.Standard Chartered Bank(3) \n4.AMP Bank(4) \n5.Others(5)";
            cout << "\n\t\t\tSelect your bank:";
            cout<<"\n\n\t\t\t";
            cin >> bank;
             cout<<"\n";
            cout << "\n\t\t\tYou have selected:" << bank;
            cout << "\n\t\t\tEnter user id:";
            cout<<"\n\n\t\t\t";
            cin >> bank_user_id;
             cout<<"\n";
            cout << "\n\t\t\tEnter password:";
            cout<<"\n\n\t\t\t";
            cin >> password;
             cout<<"\n";
            cout << "\n\t\t\tTransaction Successful\n";
            cout << "\t\t\tDon't worry!\n Your Data is not saved by us.";
            break;
        default: //condition
            cout << "\n\t\t\tWrong input entered.\nTry again\n\n";
            return payment();
        }
    }

    void Updateuser(int U) //function to update the user deatials
   {

       Customer C;
       char nname[15], nphone[10], nadd[20], nemail[25];
       int key, found = 0;//variables for switch and flag
       fui://goto statment
       fstream fbin("Customer.dat", ios::binary | ios::in | ios::out | ios::app);
       fbin.seekg(0);//start from the top of file
       while (fbin)
       {
           fbin.read((char *)&C, sizeof(C));
           if (C.userid == U)//if userid matches
           {
               fbin.seekp(-sizeof(C), ios::cur);//going one object back to the file
               cout << "\t\t\tEnter the option in which you would like to update" << endl;
               cout << "\t\t\t1. Change the Name of User" << endl;
               cout << "\t\t\t2. Change the Phone number of User" << endl;
               cout << "\t\t\t3. Change the Email of User" << endl;
               cout << "\t\t\t4. Change the Address of User" << endl;
               cout<<"\n\n\t\t\t";
               cin >> key;
                cout<<"\n";
               switch (key)
               {
               case 1:
               {
                   cout << "\t\t\tEnter the name to which you want to update";
                   cout<<"\n\n\t\t\t";
                   cin.ignore();
                   cin.getline(nname,15);
                    cout<<"\n";
                   strcpy(C.name,nname);
                   break;
               }

               case 2:
               {
                   cout << "\t\t\tEnter the Phone number to which you want to change\n";
                   cout<<"\n\n\t\t\t";
                   cin >> nphone;
                    cout<<"\n";
                  strcpy(C.phone_no,nname);
                   break;
               }
               case 3:
               {
                   cout << "\t\t\tEnter the Email to which you want to change\n";
                   cout<<"\n\n\t\t\t";
                   cin >> nemail;
                    cout<<"\n";
                   strcpy(C.email,nemail);
                   break;
               }
               case 4:
               {
                   cout << "\t\t\tEnter the Email to which you want to change\n";
                   cout<<"\n\n\t\t\t";
                   cin >> nadd;
                    cout<<"\n";
                   strcpy(C.address,nadd);
                   break;
               }
               default:
                   cout << "\t\t\tInvaild option\n" << endl;
                   break;
                   goto fui;
               }
               fbin.write((char *)&C, sizeof(C));
               found++;

               break;
           }
           {
               if (found == 0)
               {
                   cout << "\t\t\tRecord not found\n";
                   break;
               }
               else
               {
                   cout << "\t\t\tRecord updated\n";
                   break;
               }
           }
       }
       fbin.close();//closing of file
       cout<<"\n\n\t\t\t";
       cout << "\n\t\t\tPress any key..\n";
       getch();
   }
};

class Flight : public Customer//inheritance of customer class to flight
{
private:
    int dates, flight_fare, infare,fuid,user_no;
    char intial_city[15], final_city[15], Class[10];

public:
    // friend void finduser(); // FRIEND funCTION FOR PRINTING USER
    // friend void checkout(); // FRIEND funCTION FOR  USER EXIT
    //    void flightcancel();
    //  void flightupdate();
    //  void createfile_f();
    //Done by Hardik
    void flight_det()//loading user details
    {
        cout << "\t\t\tDate of your Journey: " << dates << endl;
        cout << "\t\t\tCity from which you are flying: " << intial_city << endl;
        cout << "\t\t\tCity to which you are flying: " << final_city << endl;
        cout << "\t\t\tClass of your flight: " << Class << endl;
        cout << "\t\t\tYour total flight charges : " << flight_fare << endl;
        // cout << "Your total charges of inflight services : \t" << infare << endl;
    }

    int getinfare()// acessor function
    {
        return infare;
    }

    int getflight_fare()// acessor function
    {
        return flight_fare;
    }
    //Done by Hardik
    void flightBook()//flight booking function
    {
//        Flight f5;
//        cout<<f5.userid;
        int n,user_no;
        char code, p;
        char f;
        string coupon_code = "HEK10", user_code;
        int l, z;//variables use for selection
        cout << "**********************************Welcome to HEK Airlines***************************" << endl;
        cout << "**************************We provide the best in class services************************";
        cout << "\n\n\n ";
        // int i;
        // cout<<"Enter user id to proceed further\n";
        // cin>>i;
        // ifstream fin("Customer.dat", ios::binary | ios::in);
        // if (!fin)
        // {
        //     cout << "Error in opening file";
        // }
        // else
        // {
        //     while (fin)
        //     {
        //         fin.read((char *)&cs, sizeof(cs));
        //         if (cs.getuserid()==id)
        //         {
        //             cout << "User exists\n";
        //             cout << "Welcome ";
        //             cs.getname();
        //             cout << "!!\n";
        //             break;
        //         }
        //     }
        // }
        // fin.close();
       
        // string intial_city, final_city;
        cout << "\t\t\tChoose the City from which you are flying" << endl;
        cout << " \t\t\t1. Mumbai" << endl;
        cout << " \t\t\t2. Delhi" << endl;
        cout << " \t\t\t3. Kolkata" << endl;
        cout << " \t\t\t4. Chennai" << endl;
        cout << " \t\t\t5. Bangalore" << endl;
        cout << " \t\t\t6. Goa" << endl;
        cout<<"\n\n\t\t\t";
        cin >> l;
         cout<<"\n";

          if (l == 1)
        {
            strcpy(intial_city , "Mumbai");
            cout << "\t\t\tChoose your flight destination"<<endl;
        }
        else if (l == 2)
        {
         strcpy(intial_city , "Delhi");
            cout << "\t\t\tChoose your flight destination"<<endl;
        }
        else if (l == 3)
        {
            strcpy(intial_city , "kolkata");
            cout << "\t\t\tChoose your flight destination"<<endl;
        }
        else if (l == 4)
        {
          strcpy(intial_city , "Chennai");
            cout << "\t\t\tChoose your flight destination"<<endl;
        }
        else if (l == 5)
        {
            strcpy(intial_city , "Banglore");
            cout << "\t\t\tChoose your flight destination"<<endl;
        }
        else if (l == 6)
        {
            strcpy(intial_city , "Goa");
            cout << "\t\t\tChoose your flight destination"<<endl;
        }
        else
        {
            cout << "\t\t\tWrong input" << endl;
        }

    gst://goto function
        cout << " \t\t\t1. Mumbai" << endl;
        cout << " \t\t\t2. Delhi" << endl;
        cout << " \t\t\t3. Kolkata" << endl;
        cout << " \t\t\t4. Chennai" << endl;
        cout << " \t\t\t5. Bangalore" << endl;
        cout << " \t\t\t6. Goa" << endl;
        cout<<"\n\n\t\t\t";
        cin >> z;
         cout<<"\n";

        if (z == l)//checking if the user have entered the same city
        {
            cout << "\t\t\tYou cannot choose a one way flight to the same diresction.\n";
            cout << "\t\t\tChoose different option\n";
            goto gst;
        }
       else if (z == 1)
        {
             strcpy(final_city , "Mumbai");
        }
        else if (z == 2)
        {
             strcpy(final_city , "Delhi");
        }
        else if (z == 3)
        {
             strcpy(final_city , "Kolkata");
        }
        else if (z == 4)
        {
             strcpy(final_city , "Chennai");
        }
        else if (z == 5)
        {
            strcpy(final_city , "Bangalore");
        }
        else if (z == 6)
        {
             strcpy(final_city , "Goa");
        }

        else
        {
            cout << "\t\t\tWrong input" << endl;
        }

        int C, fare, tax;
        cout << "\t\t\tSelct your date of travel(in DDMMYYYY format)" << endl;
        cout << "\t\t\tPlease enter correct date" << endl;
        cout<<"\n\n\t\t\t";
        cin >> dates;
         cout<<"\n";
        cout << "\t\t\tSelect the class which you want to book" << endl;
        cout << "\t\t\t(1)First Class" << endl;
        cout << "\t\t\t(2)Economy Class" << endl;
        cout << "\t\t\t(3)Business Class" << endl;
        cout<<"\n\n\t\t\t";
        cin >> C;
         cout<<"\n";
        {
            if (C == 2)
            {
                strcpy(Class , "Economy");
                fare = 3500;
                tax = 5;
            }
            else if (C == 3)
            {
                strcpy(Class , "Business");
                fare = 5000;
                tax = 10;
            }
            else if (C == 1)
            {
                strcpy(Class , "First");
                fare = 8000;
                tax = 12;
            }
        }
        
        
        // int userno;
        cout << "\t\t\tAre you travelling with someone(Y/N)" << endl;
        cout<<"\n\n\t\t\t";
        cin >> f;
         cout<<"\n";
        {
            if (f == 'Y' || f == 'y')
            {
                int j=0;
                cout << "\t\t\tGive number of tickets to be added\n";
                cout<<"\n\n\t\t\t";
                cin >> j;
                 cout<<"\n";
                user_no=1;
                user_no+=j;
                fare *= user_no;
            }
            else if (f == 'N' || f == 'n')
            {
                cout << "\t\t\tWe will now show you your total cost."<<endl;
            }
        }
       
        cout << "\t\t\tFlight Charges= " << fare << endl;
        cout << "\t\t\tFlight tax= " << tax << "%" << endl;
        flight_fare = (fare * tax) / 100 + fare;
        cout<<"\t\t\tYour total flight fare is "<<flight_fare<<endl;
        cout << "\t\t\tDo you have a coupon code(Y/N)" << endl;
        cout<<"\n\n\t\t\t";
        cin>>code;
         cout<<"\n";
        if (code == 'Y' || code == 'y')
        {
            cout << "\t\t\tEnter the coupon code\n";
            cout<<"\n\n\t\t\t";
            cin >> user_code;
             cout<<"\n";
            if (coupon_code.compare(user_code) == 0)
            {
                cout << "\t\t\tYou got 10% discount!!" << endl;
                flight_fare = flight_fare - (flight_fare / 10);
                cout << "\t\t\tYour total charges are :- " << round(flight_fare);
            }
            else
            {
                cout << "\t\t\tInvalid Code";
            }
        }
        cout<<"\n\n\t\t\t";
        cout<<"\n\n\t\t\tPress any key....";
        getch();
        //   cout<<"Do you want to pay now(Y/N)";
        //   cin>>p;
        // if(p=='Y' || p=='y'){
        // 	return payment();
    }
    //			else{
    //				return main();
    //			}

    //
   //done by Kartik
    void inflights()//inflight services funtion
    {
        int i1, j1, j2, j3, j4;//variables for selection
        int price = 0;
        char flag1 = 'y';
        cout << "\t\t\tWelcome to the In-flight service option \n";
        cout << "\t\t\tWe proivide the following In-flight services : \n";
        //  Customer cs;
        // 	fstream fbin("Customer.",ios::binary | ios::in |ios::out);
        //	filetop1:;
        //	fbin.seekg(0);
        //	if(!fbin)
        //	{
        //	cout<<"Error in opening file";
        //    }
        //
        //	  else
        //       {while(fbin.read((char*)&cs,sizeof(cs)))
        //        {
        //	 	if(ifsuserid==userid)
        //	 	{

        do
        {
            cout << "\t\t\t1.Drinks \n";
            cout << "\t\t\t2.Food and snacks \n";
            cout << "\t\t\t3.Upgrade seat \n";
            cout << "\t\t\t4.Exclusive services \n";
        topin:; //goto statement
        cout<<"\n\n\t\t\t";
            cin >> i1;
             cout<<"\n";
            switch (i1)
            {
            case 1:
            {
                cout << "\t\t\tYou have selected the drinks option \n";
                cout << "\t\t\tPlease select the option \n";
                cout << "\t\t\t1.Alcoholic drinks(Price=500) \n";
                cout << "\t\t\t2.Non-Alcoholic drinks(Price=300) \n";
                cout << "\t\t\t3.Packed Water(Price=80) \n";
            topd: //goto statement
            cout<<"\n\n\t\t\t";
                cin >> j1;
                 cout<<"\n";
                switch (j1)
                {
                case 1:
                    price += 500;
                    break;
                case 2:
                    price += 300;
                    break;
                case 3:
                    price += 80;
                    break;
                default:
                    cout << "\t\t\tInvaild option,please select the correct option \n";
                    goto topd;
                }
                break;
            }
            case 2:
            {

                cout << "\t\t\tYou have selected the food option \n";
                cout << "\t\t\tPlease select the option \n";
                cout << "\t\t\t1.Non-veg items(Price=500) \n";
                cout << "\t\t\t2.Veg items(Price=300) \n";
                cout << "\t\t\t3.Snacks(Price=150)";
            topf:; //goto statement
            cout<<"\n\n\t\t\t";
                cin >> j2;
                 cout<<"\n";
                switch (j2)
                {
                case 1:
                    price += 500;
                    break;
                case 2:
                    price += 300;
                    break;
                case 3:
                    price += 150;
                    break;
                default:
                    cout << "\t\t\tInvaild option,please select the correct option \n";
                    goto topf;
                }
                break;
            }
            case 3:
            {
                cout << "\t\t\tYou have selected upgrade your seat option \n";
                cout << "\t\t\tPlease select the option \n";
                cout << "\t\t\t1.Executive Class(Price=1500) \n";
                cout << "\t\t\t2.Buisness Class(Price=1000) \n";
            topu:; //goto statement
            cout<<"\n\n\t\t\t";
                cin >> j3;
                 cout<<"\n";
                switch (j3)
                {
                case 1:
                    price += 1500;
                    break;
                case 2:
                    price += 1000;
                    break;
                default:
                    cout << "\t\t\tInvaild option,please select the correct option \n";
                    goto topu;
                }
                break;
            }
            case 4:
            {

                cout << "\t\t\tYou have selected Exclusive services option \n";
                cout << "\t\t\tPlease select the option \n";
                cout << "\t\t\t1.Wifi(Price=200) \n";
                cout << "\t\t\t2.Media content(Netflix,Amzon,Movies)(Price=150) \n";
            topex:; //goto statement
            cout<<"\n\n\t\t\t";
                cin >> j4;
                 cout<<"\n";
                switch (j4)
                {
                case 1:
                    price += 200;
                    break;
                case 2:
                    price += 150;
                    break;
                default:
                    cout << "\t\t\tInvaild option,please select the correct option \n";
                    goto topex;
                }
                break;
            }
            default:
                cout << "\t\t\tInvaild option,please select the correct option \n";
                goto topin;
            }
            infare = price;
            cout << "\t\t\tYour in-flight services price is" << infare << endl;
            cout << "\t\t\tDo You want to perform more task?(y/n)" << endl;
            cout<<"\n\n\t\t\t";
            cin >> flag1;
             cout<<"\n";

        } while (flag1 == 'y' || flag1 == 'Y'); 
        //whie the user wants to add more iteams
          //	 }
         //	 	    fbin.seekp(-sizeof(cs),ios::cur);
                                                //		 	fbin.write((char*)&cs,sizeof(cs));
                                                //	 else
                                                //	 {
                                                //	 cout<<"Invail user id,Please enter a vail user id(reneter the user id)\n";
                                                //	 cin>>ifsuserid;
                                                //	 goto filetop1;
        //above goto if the user enters a invaaild user id;
    }
    //Done  by Hardik
    void flightupdate(int U)
    {

        Flight f9;
        int key, new_date, found = 0, fdate;
        char fcity[10];
    ful:

        fstream fbin("Flight.dat", ios::binary|ios::app|ios::in|ios::out);
        fbin.seekg(0);
        while (fbin)
        {
            fbin.read((char *)&f9, sizeof(f9));
            if (f9.getuserid() == U)
            {
                fbin.seekp(-sizeof(f9), ios::cur);
                cout << "\t\t\tEnter the option in which you would like to update\n";
                cout << "\t\t\t1. Change the date of flight" << endl;
                cout << "\t\t\t2. Change the destination of flight" << endl;
                cout<<"\n\n\t\t\t";
                cin >> key;
                 cout<<"\n";
                switch (key)
                {
                case 1:
                {
                    cout << "\t\t\tEnter the date to which you want to update\n";
                    cout<<"\n\n\t\t\t";
                    cout<<"\n\n\t\t\t";
                    cin >> fdate;
                     cout<<"\n";
                    f9.dates = fdate;
                    fbin.write((char *)&f9, sizeof(f9));
                    break;
                }

                case 2:
                {
                    cout << "\t\t\tEnter the city to which you want to change\n";
                    cout<<"\n\n\t\t\t";
                    cin >> fcity;
                     cout<<"\n";
                    strcpy(f9.final_city , fcity);
                    fbin.write((char *)&f9, sizeof(f9));
                    break;
                }
                default:
                    cout << "\t\t\tInvaild option" << endl;
                    goto ful;
                }
                fbin.write((char *)&f9, sizeof(f9));
                found++;
            }
            
                
        
        }
              
                if (found == 0)
                {
                    cout << "\t\t\tRecord not found";
                }
                else
                {
                    cout << "\t\t\tRecord updated";
                }
                
        
        fbin.close();
        cout << "\n\t\t\tPress any key..";
        getch();
    }
};
//Class and all the functions by Kartik
class Taxi : public Customer//inheritance of the class customer as public
{
private:
    int taxino, taxiprice;

public:
    //  void createfile(Taxi t);
    //  void canceltaxi(int x);
    

    int gettaxiprice()// acessor function
    {
        return taxiprice;
    }
    int gettaxino()// acessor function
    {
         return taxino;
    }

    void taxi_det()//loading details of the user
    {
        cout<< "\t\t\tTaxiprice : "<<taxiprice;
        cout<< "\t\t\tTaxi Number : "<<taxino;
    }
    void taxiselect()//selection function for the user
    {
        int i;//variable for swtich
        int Taxiprice = 0,tuser_no=1;
        cout<<"\t\t\tNumber of passengers";
        cout<<"\n\n\t\t\t";
        cin>>tuser_no;
         cout<<"\n";
         cout<<"\t\t\tCreate  your personlize taxi no";
         cout<<"\n\n\t\t\t";
         cin>>taxino;
         cout<<"\n";
        cout << "\t\t\tSelect the taxi type you select \n";
        cout << "\t\t\t1. Limozine(Price=1000) \n";
        cout << "\t\t\t2. Sedan(Price=800) \n";
        cout << "\t\t\t3. SUV(Price=600) \n";
        cout << "\t\t\t4. 4X4(Price=400) \n";
        cout << "\t\t\t5. Standard car(Price=250) \n";
        cout<<"\n\n\t\t\t";
        cin >> i;
         cout<<"\n";
        switch (i)
        {
        case 1:
            Taxiprice = 1000 * tuser_no;
            break;
        case 2:
            Taxiprice = 800 * tuser_no;
            break;
        case 3:
            Taxiprice = 600 * tuser_no;
            break;
        case 4:
            Taxiprice = 400 * tuser_no;
            break;
        case 5:
            Taxiprice = 250 * tuser_no;
            break;
        default:
            cout << "\t\t\tInvail option,Please re-enter the value \n";
            return taxiselect();
        }
        cout << "\t\t\tTaxi fare is: " << Taxiprice<<endl;
        getch();
    }
};

// start of hotelclass
//Class and functions by Esha
class Hotel : public Customer//Inheritance of class customer as public
{
private:
    int price, room_no;
    int t_hotelprice, srvprice, xbed;
    int day1, month1, year1, day2, month2, year2,huser_no;
    //int user_no;
    int i, year, year4;
    // double days;
    double sum ;
    double addf ;
//    double sum1;

public:
Hotel()
        {
                xbed=200;
                sum=0;
                addf=0;
        }
    //    	void addHotel();
    //		void services(int);
    //    void display();
    //    	void cancel_rec();
    //    	int check_leap_year(int year);

    //  	void t_hotelprice();

    int getroom_no()// acessor function
    {
        return room_no;
    }
    double getsrvprice()// acessor function
    {
        return srvprice;
    }
    double gett_hotelprice()// acessor function
    {
        return t_hotelprice;
    }

    void hotel_det()//loading details of the user
    {
        cout<<"\t\t\tRoom Number: "<<room_no<<endl;
        cout<<"\t\t\tHotel Price: "<<t_hotelprice<<endl;
       // cout<<"Service Price: "<<srvprice<<endl;
    }

    void addHotel()//function for booking for the user
    {
        Hotel h5;
        system("cls");
        int r, flag, p;
        cout << "\t\t\t\n Room no:";
        cout << "\t\t\t\n Total no of rooms:100";
        cout << "\t\t\t\n Single rooms (standard):1-20";
        cout << "\t\t\t\n Double rooms (standard):21-40";
        cout << "\t\t\t\n Queen rooms (deluxe):41-60";
        cout << "\t\t\t\n Suites (deluxe):61-80";
        cout << "\t\t\t\n Appartments (deluxe):81-100";
        cout << "\t\t\t\n Enter the room you want to choose:" << endl;
        cout<<"\n\n\t\t\t";
        cin >> r;
        ifstream fk("Record.dat",ios::binary|ios::in);
        while(fk.eof()){
            fk.read((char*)&h5,sizeof(h5));
            if(h5.getroom_no()==r){
                cout<<"Room not available";
                return addHotel();
            }
        }
        fk.close();
         cout<<"\n";
        // cout << "Enter the number of tenants" << endl;
        // cin >> user_no;
        cout << "\t\t\tEnter the check in date:\n\n" << endl;
        room_no=r;
        cout<<"\t\t\t";
        cin >> day1; 
        cout<<"\t\t\t";
        cin>> month1 ;
        cout<<"\t\t\t";
        cin>> year1;
         cout<<"\n";
        year = year1 - 1900;
        system("cls");
        cout << day1 << "/" << month1 << "/" << year1 << endl;
        cout << "\t\t\tEnter your check out date" << endl;
        cout<<"\t\t\t";
        cin >> day2 ;
        cout<<"\t\t\t";
        cin>> month2;
        cout<<"\t\t\t";
        cin>> year2;
        
         cout<<"\n";
        year4 = year2 - 1900;
        double days = date(day1, month1, year, day2, month2, year4, room_no);
		cout<<"\t\t\tEnter the number of tenants\n";
        cout<<"\n\n\t\t\t";
        cin>>huser_no;
         cout<<"\n";

        if  (huser_no <= 2 && huser_no > 0)
        {
        	
            if (room_no >= 1 && room_no<= 20)
            {
            	
                sum += 100;
                for (i = 2; i <= days; i++)
                {
                    sum += 70;
                }
            }
			
            else if (room_no >= 21 && room_no<= 40)
            {
                sum += 200;
                for (i = 2; i <= days; i++)
                {
                    sum += 150;
                }
            }
            else if (room_no >= 41 && room_no<= 60)
            {
                sum += 300;
                for (i = 2; i <= days; i++)
                {
                    sum += 180;
                }
            }
            else if (room_no >= 61 && room_no<= 80)
            {
                sum += 400;
                for (i = 2; i <= days; i++)
                {
                    sum += 210;
                }
                {
                }
            }
            else if (room_no >= 81 && room_no<= 100)
            {
                sum += 500;
                for (i = 2; i <= days; i++)
                {
                    sum += 250;
                }
                {
                }
            }
        }
       else if  (huser_no <= 5 && huser_no > 2)
            {
                if (room_no >= 1 && room_no<= 20)
                {
                    sum += 150;
                    for (i = 2; i <= days; i++)
                    {
                        sum += 120;
                    }
                }

                else if (room_no >= 21 && room_no<= 40)
                {
                    sum += 300;
                    for (i = 2; i <= days; i++)
                    {
                        sum += 200;
                    }
                }
                else if (room_no >= 41 && room_no<= 60)
                {
                    sum += 450;
                    for (i = 2; i <= days; i++)
                    {
                        sum += 280;
                    }
                }
                else if (room_no >= 61 && room_no<= 80)
                {
                    sum += 600;
                    for (i = 2; i <= days; i++)
                    {
                        sum += 330;
                    }
                }
                else if (room_no >= 81 && room_no<= 100)
                {
                    sum += 750;
                    for (i = 2; i <= days; i++)
                    {
                        sum += 390;
                    }
                }
            }
    	else if  (huser_no <= 8 && huser_no > 5)
            {
                if (room_no >= 1 && room_no<= 20)
                {
                    sum += 250;
                    for (i = 2; i <= days; i++)
                    {
                        sum += 150;
                    }
                }

                else if (room_no >= 21 && room_no<= 40)
                {
                    sum += 400;
                    for (i = 2; i <= days; i++)
                    {
                        sum += 250;
                    }
                }
                else if (room_no >= 41 && room_no<= 60)
                {
                    sum += 580;
                    for (i = 2; i <= days; i++)
                    {
                        sum += 380;
                    }
                }
                else if (room_no >= 61 && room_no<= 80)
                {
                    sum += 700;
                    for (i = 2; i <= days; i++)
                    {
                        sum += 500;
                    }
                }
                else if (room_no >= 81 && room_no<= 100)
                {
                    sum += 810;
                    for (i = 2; i <= days; i++)
                    {
                        sum += 620;
                    }
                }
            }
//            cout << sum << endl;
//            // system("cls");
        

        else
        {
            cout << "\t\t\tRoom not found";
        }
		
        char f;
        // int xbed;
        cout << "\t\t\tDo you want an extra bed(Y/N)" << endl;
        cout<<"\n\n\t\t\t";
        cin >> f;
         cout<<"\n";
        t_hotelprice = sum;
        {
            if (f == 'Y' || f == 'y')
            {
                cout << "\t\t\tGive number of beds to be added";
                cout<<"\n\n\t\t\t";
                cin >> xbed;
                 cout<<"\n";
                t_hotelprice *= xbed;
            }
            // else if (f == 'N' || f == 'n')
            // {
            //     cout << "We will now show you your total cost";
            //     cout << t_hotelprice;
            // }
        }
        //t_hotelprice=sum1;
         cout << "\t\t\tWe will now show you your total cost - ";
               cout << t_hotelprice;
        

        cout<<"\n\n\t\t\t";
        cout << "\n \t\t\tPress any key to continue...";
        getch();
    }

    void services()//function for the extra services for the user
    {

        int price = 0;
        char flag2 = 'y';
        do{
        cout << "\t\t\tWelcome to the hotel services option \n";
        cout << "\t\t\tWe provide the following hotel services : \n";
        // Hotel h;
        //	fstream fbin("Record.dat",ios::binary | ios::in |ios::out);
        //	filetop1:;
        //	fbin.seekg(0);
        //	if(!fbin)
        //	{
        //		cout<<"Error in opening file";                                            // user id in hotel
        //	}

        //	   else
        //      {while(fbin.read((char*)&h,sizeof(h)))
        //       {
        ////	 	if(ifsuserid==userid)
        ////	 	{
        //		while(flag1=='y'|| flag1=='Y')// IF the user wants to add more iteams
        {
            int i;
            cout << "\t\t\t1.Dining \n";
            cout << "\t\t\t2.Parking \n";
            cout << "\t\t\t3.Exclusive service \n";
        topin1: //goto statement
        cout<<"\n\n\t\t\t";
            cin >> i;
             cout<<"\n";
            int j;
            switch (i)
            {
            case 1:
            {
                cout << "\t\t\tYou have selected the Dining option \n";
                cout << "\t\t\tPlease select the option \n";
                cout << "\t\t\t1.Buffet(Price=1000) \n";
                cout << "\t\t\t2.Hotel restaurent(Price=800) \n";
            topd1:; //goto statement
            cout<<"\n\n\t\t\t";
                cin >> j;
                 cout<<"\n";
                switch (j)
                {
                case 1:
                    price += 1000;
                    cout << "\t\t\tBuffet has been added for- 1000";
                    break;
                case 2:
                    price += 800;
                    cout << "\t\t\tRestaurant food  has been added for- 1000";
                    break;

                default:
                    cout << "\t\t\tInvaild option,please select the correct option \n";
                    goto topd1;
                }
                break;
            }
            case 2:
            {
                j = 0;
                cout << "\t\t\tYou have selected the parking option \n";
                cout << "\t\t\tPlease select the option \n";
                cout << "\t\t\t1.Self parking(Price=500) \n";
                cout << "\t\t\t2.Vallet parking(Price=300) \n";

            topf1:; //goto statement
            cout<<"\n\n\t\t\t";
                cin >> j;
                 cout<<"\n";
                switch (j)
                {
                case 1:
                    price += 500;
                    cout << "\t\t\tSelf parking added for- 500";
                    break;
                case 2:
                    price += 300;
                    cout << "\t\t\tvallet parking added for- 300";
                    break;

                default:
                    cout << "\t\t\tInvaild option,please select the correct option \n";
                    goto topf1;
                }
                break;
            }
            case 3:
            {
                cout << "\t\t\tExclusive service\n";
                cout << "\t\t\tPlease select the option \n";
                cout << "\t\t\t1.Hotel wifi(Price=200) \n";
                cout << "\t\t\t2.Hotel lounge-access 24*7(Price=1000) \n";
            topex1:; //goto statement
            cout<<"\n\n\t\t\t";
                cin >> j;
                 cout<<"\n";
                switch (j)
                {
                case 1:
                    price += 200;
                    cout << "\t\t\tWifi has been added for 200\n";
                    break;
                case 2:
                    price += 1000;
                    cout << "\t\t\tLounge has been added for 1000\n";
                    break;

                default:
                    cout << "\t\t\tInvaild option,please select the correct option \n";
                    goto topex1;
                }
                break;
            }
        default:cout<<"\t\t\tInvaild option,please select the correct option \n";
        goto topin1;
            }
            srvprice = price;
            //	 	    fbin.seekp(-sizeof(h),ios::cur);
            //		 	fbin.write((char*)&h,sizeof(h));
        }
         cout << "\t\t\tYour hotel services price is = " << srvprice << endl;
        cout << "\t\t\tDo You want to perform more task?(y/n)" << endl;
        cout<<"\n\n\t\t\t";
        cin >> flag2;
         cout<<"\n";
        }while(flag2=='y' || flag2=='Y');

    }
    //	if
    //	{
    //		 cout<<"Invail user id,Please enter a vail user id(reneter the user id)\n";
    //	     cin>>ifsuserid;
    //	     goto filetop1;
    //	 //above goto if the user enters a invaaild user id;
    //	 }

    //fbin.close();

    // function for days
    int date(int day1, int month1, int year, int day2, int month2, int year4, int room)
    {
        int i;
        double difference;
        month1 -= 1;
        month2 -= 1;
        struct tm a = {0, 0, 0, day1, month1, year};
        struct tm b = {0, 0, 0, day2, month2, year4}; //104 = 2004
        time_t x = mktime(&a);
        time_t y = mktime(&b);
        int days;
     if ( x != (std::time_t)(-1) && y != (std::time_t)(-1) )
        {
            double difference = difftime(y, x) / (60 * 60 * 24);
            cout << ctime(&x);
            cout << ctime(&y);
            cout << "difference = " << difference << " days" << endl;
            days = difference;
        }

        cout << days << endl;
        return days;
    }
};



//
//
//
//
//
//
//
//
//
//
//
//
//file handling
//
//
//
//
//
//

void createfile_c(Customer cs)//for creating the file of the object customer
{
    ofstream fin("Customer.dat", ios::binary | ios::app |ios::out);
    fin.write((char *)&cs, sizeof(cs)); //writing to file
    fin.close();                        //closing file
}
void checkcustomer(int c1)//for the checking of the object existence and showing the details
{
    Customer c;
    int f = 0;
    ifstream fout("Customer.dat", ios::binary |ios::in); //opening file
    fout.read((char *)&c, sizeof(c));           //reading file
    while (fout)
    {
        if (c.getuserid() == c1)
        {
            c.Cust_det();
            f++; //incrementing f if onr found
            break;
        }
        fout.read((char *)&c, sizeof(c)); //reading another record from the same file
    }
    fout.close(); //closing file
    if (f == 0)   //if f==0, userid not found
        cout << "User id not found" << endl;
}

//
//
//
//
// Fle handling for flight class
void createfile_f(Flight f)//for creating the file of the  class object flight
{
    ofstream fin("Flight.dat", ios::binary | ios::app |ios::out);
    fin.write((char *)&f, sizeof(f)); //writing to file
    fin.close();                      //closing file
}

void createfile_h(Hotel h)//for creating the file of the  class object hotel
{
    ofstream fin("Record.dat", ios::binary | ios::app|ios::out);
    fin.write((char *)&h, sizeof(h)); //writing to file
    fin.close();                      //closing file
}

void flightcancel(int x)//for canceling the recored and removing the object from the file
{
    Flight f3;
    int f=0;
    ifstream fout("Flight.dat", ios::binary | ios::app |ios::in); 
    ofstream fin("ti1.dat", ios::binary | ios::app |ios::out);   
    fout.read((char *)&f3, sizeof(f3));                  
    while (!fout.eof())
    
    {
	
    
        fout.read((char *)&f3, sizeof(f3)); 
//        if(fout){
//            if(f3.{
//                f=1;
//                cout<<"The record is deleted";
//                f3.flight_det();
//            }
//            else{
//                fin.write((char*)&f3,sizeof(f3));
//            }
//        }


         if (f3.getuserid() != x)                
             fin.write((char *)&f3, sizeof(f3)); 
         else
        {
            

             f++; 
         }
         fout.read((char *)&f3, sizeof(f3)); 
}
    if (f == 0) 
        cout << "\n\t\t\tUser id not found\n";
    else
    {
        cout << "\t\t\tYour Above booking is cancelled\n";
    }
    
    fout.close();        
    fin.close();         
    remove("Flight.dat");
    rename("ti1.dat", "Flight.dat");
    cout<<"\n\n\t\t\t";
    cout << "\t\t\tPress any key...";
    getch();
}

void checkflight(int f)//for the checking of the object existence and showing the details

{
    Flight f2;
    int f1 = 0;
    
    ifstream fout("Flight.dat", ios::binary |ios::in); //opening file
    fout.read((char *)&f2, sizeof(Flight));       //reading file
    while (fout)
    {
        // cout<<f2.userid;
        if (f2.getuserid()==f)
        {
            f2.flight_det();
            f1++; //incrementing f if onr found
            break;
        }
         fout.read((char *)&f2,sizeof(f2));//reading another record from the same file
    }
    fout.close(); //closing file
    if (f1 == 0)  //if f==0, userid not found
    {
        cout << "\t\t\tUser id not found" << endl;
    }
   

}
//
///
//
//
//
//file handling for hotel

void checkhotel(int x) //for the checking of the object existence and showing the details
{
    Hotel t;
    int f = 0;
    ifstream fout("Record.dat", ios::binary |ios::in); //opening file
    fout.read((char *)&t, sizeof(t));         //reading file
    while (fout)
    {
        if (t.getuserid() == x) //checking userid
        {
          t.hotel_det();
            f++; //incrementing f if onr found
            break;
        }
        fout.read((char *)&t, sizeof(t)); //reading another record from the same file
    }
    fout.close(); //closing file
    if (f == 0)   //if f==0 userid not found
        cout << "\t\t\tUser id not found" << endl;

}

void cancel_rec(int x)//for canceling the recored and removing the object from the file
{

    Hotel h3;

    int f = 0;
    ifstream fout("Record.dat", ios::binary | ios::app|ios::in); //opening file
    ofstream fin("t2.dat", ios::binary | ios::app |ios::out);      //writing to a new file
    fout.read((char *)&h3, sizeof(h3));                  //reading old file
    while (fout)
    {
        if (h3.getuserid() != x)                //checkin userid
            fin.write((char *)&h3, sizeof(h3)); //writing to new file;
        else
        {
            //         t.display()//display details

            f++; //incrementing f if userid found
        }
        fout.read((char *)&h3, sizeof(h3)); //reading another record from old file
    }
    if (f == 0) //if f==0,userid not found
        cout << "\n\t\t\tUser id not found\n";
    else
    {
        cout << "\t\t\tYour Above booking is cancelled";
    }
    fout.close();                   //closing file
    fin.close();                    //closing file
    remove("Record.dat");           //deleting old file
    rename("t2.dat", "Record.dat"); //renaming new file
}

//

//
//
//Taxi class file handling
//
//
//
//

void createfile(Taxi t)//for creating the file of the class object taxi
{
    ofstream fin("taxi.dat", ios::binary | ios::app);
    fin.write((char *)&t, sizeof(t)); //writing to file
    fin.close();                      //closing file
}

int canceltaxi(int x)//for canceling the recored and removing the object from the file
{
    Taxi t2;

    int f = 0;
    ifstream fout("taxi.dat", ios::binary | ios::app); //opening file
    ofstream fin("taxi1.dat", ios::binary | ios::app); //writing to a new file
    fout.read((char *)&t2, sizeof(t2));                //reading old file
    while (fout)
    {
        if (t2.getuserid()!= x)                //checking user
            fin.write((char *)&t2, sizeof(t2)); //writing to new file;
        else
        {
            //         t.display()//display details
            t2.taxi_det();
            cout << "Your Above booking is cancelled";
            f++; //incrementing f if userid found
        }
        fout.read((char *)&t2, sizeof(t2)); //reading another record from old file
    }
    if (f == 0) //if f==0,userid not found
        cout << "\nUser id not found\n";
    fout.close();                    //closing file
    fin.close();                     //closing file
    remove("taxi.dat");              //deleting old file
    rename("taxi1.dat", "taxi.dat"); //renaming new file
}

void checktaxi(int x) //for the checking of the object existence and showing the details

{
    Taxi t;
    int f = 0;
    ifstream fout("Taxi.dat", ios::binary); //opening file
    fout.read((char *)&t, sizeof(t));       //reading file
    while (fout)
    {
        if (t.getuserid() == x) //checking user
        {

            t.taxi_det();
            f++; //incrementing f if onr found
            break;
        }
        fout.read((char *)&t, sizeof(t)); //reading another record from the same file
    }
    fout.close(); //closing file
    if (f == 0)   //if f==0, userid not found
        cout << "User id not found" << endl;
}

//done by Kartik

int total(int c)//function used for taking the fare of all the function and adding them up and showing up the total amount
{
    Flight f6;
    Hotel h6;
    Taxi t6;
    int teratotal=0, flightka=0, inflightka=0, taxika=0, hotelka=0, hotelserviceka=0;

    {
        int f1 = 0;
        ifstream fout("Flight.dat", ios::binary); //opening file
        fout.read((char *)&f6, sizeof(f6));       //reading file
        while (fout)
        {
            if (f6.getuserid() == c)
            {
                flightka = f6.getflight_fare();
                inflightka = f6.getinfare();
                f1++; //incrementing f if onr found
                break;
            }
            fout.read((char *)&f6, sizeof(f6)); //reading another record from the same file
        }
        fout.close(); //closing file
        if (f1 == 0)  //if f==0, userid not found
            cout << "\t\t\tUser id not found" << endl;
    }

    {
        int f2 = 0;
        ifstream fu("Taxi.dat", ios::binary); //opening file
        fu.read((char *)&t6, sizeof(t6));     //reading file
        while (f2)
        {
            if (t6.getuserid() == c) //checking userid
            {
                taxika = t6.gettaxiprice();
                f2++; //incrementing f if onr found
                break;
            }
            fu.read((char *)&t6, sizeof(t6)); //reading another record from the same file
        }
        fu.close();  //closing file
        if (f2 == 0) //if f==0,userid not found
            cout << "\t\t\tUser id not found" << endl;
    }

    {
        int f3 = 0;
        ifstream fout("Record.dat", ios::binary); //opening file
        fout.read((char *)&h6, sizeof(h6));       //reading file
        while (fout)
        {
            if (h6.getuserid() == c) //checking userid
            {
                hotelka = h6.gett_hotelprice();
                hotelserviceka = h6.getsrvprice();
                f3++; //incrementing f if onr found
                break;
            }
            fout.read((char *)&h6, sizeof(h6)); //reading another record from the same file
        }
        fout.close(); //closing file
        if (f3 == 0)  //if f==0, userid not found
            cout << "\t\t\tUser id not found" << endl;
    }

    {
        teratotal = flightka + inflightka + taxika + hotelka + hotelserviceka;
        cout << "\t\t\tTotal fare =" << teratotal << endl;
        cout << "\t\t\tThank you for using our services...Now proceed for your payment menu" << endl;
        
        //      cout<<"Thank you for using HEK Travellers";
    }
}


