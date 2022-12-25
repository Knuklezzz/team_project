#include "expenseinputscreen.h"
#include "ritual.h"
//--------------------------------------------------------
//////////////методы класса ExpenseInputScreen/////////////

// конструктор
ExpenseInputScreen::ExpenseInputScreen(ExpenseRecord* per) : ptrExpenseRecord(per)
{
    /*пусто*/
}
//------------------------------------------------------
void ExpenseInputScreen::setExpense()
{
    int month, day;
    string category, payee;
    float amount;
    cout << "Enter the month (1-12): ";
    cin >> month;
    cin.ignore(80, '\n');
    cout << "Enter the day (1-31): ";
    cin >> day;
    cin.ignore(80, '\n');
    cout << "Enter the expense category (Repairs, Taxes): ";
    getaLine(category);
    cout << "Enter the recipient (OOO VarovComp): ";
    getaLine(payee);
    cout << "Enter the sum (39.95): ";
    cin >> amount;
    cin.ignore(80, '\n');
    // создаем новый расход
    Expense* ptrExpense = new Expense(month, day, category, payee, amount);
    // вставляем расход в список всех расходов
    ptrExpenseRecord->insertExp(ptrExpense);
}
