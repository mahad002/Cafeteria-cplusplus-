#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <conio.h>
//#include <windows.h>
#include <iomanip>
#include <string>
#include <cmath>
#include <time.h>
#include <cctype>

using namespace std;

struct Salary{
    int fixedSalary = 15000; //Rs. 15000
    double comission; //2% of sale price of all sales

};

struct Sales_Person{
    int emp_ID;
    string emp_Name;
    Salary salary1;
    double Sales;
};



struct Customer{
    int cust_No;
    int C_Gender;
    int age;

};

struct FoodItem{
    int id; //1-fastfood, 2-regularfood, 3-packedfood
    string itemName;
    int price;
    int count;
};

struct salesData{
    Customer c;
    int itemOrdered;
    FoodItem* f;
    Sales_Person s;

};


int totalSales(int n, Sales_Person Sales_P[])
{
    int TotalS=0;
    for(int i=0; i<n; i++)
    {
        TotalS = TotalS + Sales_P[i].Sales;
    }
    return TotalS;
}

void totalSalesBySalesPerson(Sales_Person* Sales_P)
{
    int person;
    cout<<"------------------------------\n";
    cout<<"Enter Sales Person(1/2/3): \n";
    cin>>person;
    cout<<"------------------------------\n";
    cout<<"ID: "<<Sales_P[person-1].emp_ID<<endl;
    cout<<"Name: "<<Sales_P[person-1].emp_Name<<endl;
    cout<<"Sales: "<<Sales_P[person-1].Sales<<endl;
}

void topSalesPerson(Sales_Person* Sales_P, int n) //List of sorted sales person along with the total sales done by them
{
    Sales_Person Temp;
    bool nomoreswaps = false;
    while(nomoreswaps==false)
    {
        nomoreswaps = true;
        for(int i=0; i<n; i++)
        {
            if(Sales_P[i].Sales>Sales_P[i+1].Sales)
            {
                Temp=Sales_P[i];
                Sales_P[i] = Sales_P[i+1];
                Sales_P[i+1] = Temp;
                nomoreswaps = false;
            }
        }
    }
    cout<<"------------------------------\n";
    cout<<"         Sales Person\n";
    cout<<"------------------------------\n";
    for(int i=0; i<n; i++)
    {
        cout<<"ID: "<<Sales_P[i].emp_ID<<endl;
        cout<<"Name: "<<Sales_P[i].emp_Name<<endl;
        cout<<"Sales: "<<Sales_P[i].Sales<<endl;
        cout<<"------------------------------\n";
    }
}

void commissionSalesPerson(Sales_Person* Sales_P, int n) //Calculate commission of a sales person
{
    cout<<"----------------------------------\n";
    cout<<"Commission Sales\n";
    cout<<"----------------------------------\n";
    for(int i=0; i<n; i++)
    {
        Sales_P[i].salary1.comission = (Sales_P[i].Sales) * (2/100);
        cout<<"ID: "<<Sales_P[i].emp_ID<<endl;
        cout<<"Name: "<<Sales_P[i].emp_Name<<endl;
        cout<<"Commission: $"<<Sales_P[i].salary1.comission<<endl;
        cout<<"------------------------------\n";

    }
}

double commissionCal(Sales_Person* Sales_P, int n)
{
    return ((Sales_P[n].Sales) * (2/100));
}

void totalSalary(Sales_Person* Sales_P, int n) //Calculate the amount that the owner has to pay to all sales person
{
    cout<<"---------------------------------------\n";
    cout<<"Salaries\n";
    cout<<"---------------------------------------\n";
    double commission=0, Total=0, AllTotal=0;
    for(int i=0; i<n; i++)
    {
        commission = commissionCal(Sales_P,i);
        Total=static_cast<double>(Sales_P[i].salary1.fixedSalary) + commission;
        AllTotal+=Total;
        cout<<"ID: "<<Sales_P[i].emp_ID<<endl;
        cout<<"Name: "<<Sales_P[i].emp_Name<<endl;
        cout<<"Salary: $"<<Total<<endl;
        cout<<"---------------------------------------\n";
    }
    cout<<endl<<endl;
    cout<<"Amount The Owner Has To Pay: $"<<AllTotal<<endl;
    cout<<"---------------------------------------\n";
}

void salesByType(FoodItem* Food)
{
    int Type, Sale;
    cout<<"----------------------------\n";
    cout<<"Enter Type: ";
    cin>>Type;
    cout<<"\n----------------------------\n";
    Sale = (Food[Type].count)*(Food[Type].price);
    cout<<"Type: "<<Type<<endl;
    cout<<"Food: "<<Food[Type].itemName<<endl;
    cout<<"Total Sales: "<<Sale<<endl;
    cout<<"----------------------------\n";

}

void customer_id()
{

}

int main()
{
    int X=0, Y=0, last_id=1, option, b=0;
    Sales_Person* Sales_P = new Sales_Person[10];
    FoodItem* Food = new FoodItem[20];
    Customer TCus[100];

    Sales_P[0].emp_ID=1;
    Sales_P[0].emp_Name="S1";
    Sales_P[0].Sales=0.0;
    Sales_P[1].emp_ID=2;
    Sales_P[1].emp_Name="S2";
    Sales_P[1].Sales=0.0;
    Sales_P[2].emp_ID=3;
    Sales_P[2].emp_Name="S3";
    Sales_P[2].Sales=0.0;

    Food[0].id=1;
    Food[0].itemName="ChipsS";
    Food[0].price=20;
    Food[1].id=2;
    Food[1].itemName="ChipsL";
    Food[1].price=50;
    Food[2].id=3;
    Food[2].itemName="Coke";
    Food[2].price=50;
    Food[3].id=4;
    Food[3].itemName="Milk";
    Food[3].price=60;
    Food[4].id=5;
    Food[4].itemName="ChoclateS";
    Food[4].price=50;
    Food[5].id=6;
    Food[5].itemName="ChoclateL";
    Food[5].price=100;
    Food[6].id=7;
    Food[6].itemName="Candies";
    Food[6].price=10;
    Food[7].id=8;
    Food[7].itemName="Brownie";
    Food[7].price=80;
    Food[8].id=9;
    Food[8].itemName="ChoclateDIp";
    Food[8].price=100;
    Food[9].id=10;
    Food[9].itemName="IceCream";
    Food[9].price=70;


    //int i=0;
    int fc=10, sc=3;
    char a='y';
        while (X==0)
        {
            Customer cus;

            cout<<"--------------------------------------------\n               FAST CAFETRIA\n--------------------------------------------\n";
            cout<<"Number: \n";
            cus.cust_No=last_id;
            cout<<last_id++<<endl;
            cout<<"Enter your Gender: \n";
            cin>>cus.C_Gender;
            cout<<"Enter your Age: \n";
            cin>>cus.age;
            cin.clear();
            cin.ignore();
            cout<<"--------------------------------------------\n";
            cout<<"                   MENU\n--------------------------------------------\n";

            for (int i=0; i<fc; i++)
            {
                cout<<" "<<i+1<<". "<<Food[i].itemName<<endl;
            }
            cin>>X;
            cout<<"--------------------------------------------\n";

            //cin.clear();
            //cin.ignore();
            TCus[b]=cus;
            b++;
            Food[X-1].count++;
            //i++;
            cout<<"Enter 0 to continue! \n";
            cin>>X;
        }
        X=0;
        while(X==0)
        {
            cout<<"--------------------------------------\n";
            cout<<"            Management";
            cout<<"--------------------------------------\n";
            cout<<" 1.Total Sales\n 2.Total Sales By Person\n 3.Top Sales Person\n 4.Commission\n 5.Total Salary\n 6.Sales By Type\n Any Other Number To Exit!\n";
            cin>>option;
            switch (option)
            {
                case 1:
                    cout<<totalSales(3,Sales_P);
                    break;
                case 2:
                    totalSalesBySalesPerson(Sales_P);
                    break;
                case 3:
                    topSalesPerson(Sales_P,3);
                    break;
                case 4:
                    commissionSalesPerson(Sales_P,3);
                    break;
                case 5:
                    totalSalary(Sales_P,3);
                    break;
                case 6:
                    salesByType(Food);
                    break;
                default:
                    break;
            }
            cout<<"Do you want to Get More Data? Press '0' for Yes!\n";
            cin>>X;

        }

    delete[] Sales_P;
    delete[] Food;

    return 0;
}











