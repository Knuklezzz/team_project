#pragma once
#include "expenserecord.h"
////////////////класс ExpenseInputScreen///////////////////
//Класс для ввода расходов
class ExpenseInputScreen
{
private:
    ExpenseRecord* ptrExpenseRecord; // запись о расходах
public:
    ExpenseInputScreen(ExpenseRecord*);
    void setExpense();
};
