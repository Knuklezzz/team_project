#include "annualreport.h"

////////////////методы класса AnnualReport/////////////////
//Конструктор
AnnualReport::AnnualReport(RevenueRecord* pRR, ExpenseRecord* pER) : ptrRR(pRR), ptrER(pER)
{ /* пусто */
}
//---------------------------------------------------------
void AnnualReport::display()
{
    cout << "Annual report\n--------------\n" << endl;
    cout << "Incomes\n" << endl;
    cout << "\tSales revenue:\t\t";
    revenues = ptrRR->getSumOfRevenues();
    cout << revenues << endl;

    cout << "Expenses\n" << endl;
    expenses = ptrER->displaySummary();
    cout << "Expences total:\t\t";
    cout << expenses << endl;
    // вычисляем прибыльность
    cout << "\nBalance:\t\t\t" << (revenues - expenses) << endl;
}
