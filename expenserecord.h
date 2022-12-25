#pragma once
#include "expense.h"
#include <vector>
#include <iostream>
///////////////////класс ExpenseRecord/////////////////////
//Класс записей о затратах
class ExpenseRecord
{
private:
    vector<Expense*> vectPtrsExpenses; //вектор указателей на расходы
    vector<Expense*>::iterator iter;
public:
    ~ExpenseRecord();

    void insertExp(Expense*);
    void display();
    float displaySummary(); // нужно для годового отчета
};
