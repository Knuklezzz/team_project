#include "ritual.h"
void getaLine(string& inStr) // получение строки текста
{
    char temp[22];
    cin.get(temp, 21, '\n'); //cin.get не закончит ввод при нажатии пробела при вводе названий товаров,
    // состоящих из 2 и более слов
    cin.ignore(21, '\n'); //число пропускаемых символов и символ разделения, cin.ignore дает ввести определенное кол-во символов
    inStr = temp;
}
//---------------------------------------------------------
char getaChar() // получение символа
{
    char ch = cin.get();
    cin.ignore(80, '\n'); //число пропускаемых символов и символ разделения
    return ch;
}



//---------------------------------------------------------
/////////////////методы класса SellsInputScreen/////////////
void SellsInputScreen::setSells()
{
    cout << "Enter the name of the product/service: ";
    getaLine(productName);
    // получить артикул и стоимость по названию товара
    art = ptrProductList->getArt(productName);
    prc = ptrProductList->getPrc(productName);
    if (art > 0) // если товар найден -
    { // получить количество продаж
        cout << "Enter the month number (1-12): " << endl;
        cin >> month;
        cin.ignore(80, '\n');
        month--; // внутренняя нумерация 0-11, тк используется массив
        cout << "Enter the volume of sales in this month (10): " << endl;
        cin >> amountSold; // вводим количество продаж
        cin.ignore(80, '\n');

         // вставляем данные для подсчета выручки
        ptrRevenueRecord->insertRevenue(art, month, amountSold, prc);

    }
    else
        cout << "No such product has been added yet\n" << endl;
}




//---------------------------------------------------------
//////////////////методы класса ExpenseRecord//////////////
ExpenseRecord::~ExpenseRecord() // деструктор
{ // удалить объекты expense
// удалить указатели на вектор
    while (!vectPtrsExpenses.empty())
    {
        iter = vectPtrsExpenses.begin();
        delete* iter;
        vectPtrsExpenses.erase(iter);
    }
}
//--------------------------------------------------------
void ExpenseRecord::insertExp(Expense* ptrExp)
{

    vectPtrsExpenses.push_back(ptrExp);
}
//---------------------------------------------------------
void ExpenseRecord::display() // распечатываем все расходы
{
    cout << "\nDate\tRecipient\tSum\tCategory\n"
        << "----------------------------------------\n" << endl;
    if (vectPtrsExpenses.size() == 0) // В контейнере нет расходов
        cout << "***There are no expenses***\n" << endl;
    else
    {
        iter = vectPtrsExpenses.begin();
        while (iter != vectPtrsExpenses.end())
        { // распечатываем все расходы
            cout << (*iter)->month << '/' << (*iter)->day << '\t' << (*iter)->payee << '\t' << '\t';
            cout << (*iter)->amount << '\t' << (*iter)->category << endl;
            iter++;
        }
        cout << endl;
    }
}




//--------------------------------------------------------
// используется при составлении годового отчета
float ExpenseRecord::displaySummary()
{
    float totalExpenses = 0; // Сумма по всем категориям расходов
    if (vectPtrsExpenses.size() == 0)
    {
        cout << "\tAll categories\t0\n";
        return 0;
    }
    iter = vectPtrsExpenses.begin();
    while (iter != vectPtrsExpenses.end())
    {
        //выводим на экран категории расходов
        cout << '\t' << ((*iter)->category) << '\t' << ((*iter)->amount) << endl;
        totalExpenses += (*iter)->amount; //подсчитываем все расходы
        iter++;
    }
    return totalExpenses;
}





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





//---------------------------------------------------------
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





//---------------------------------------------------------
////////////////методы класса userInterface//////////////
UserInterface::UserInterface()
{
    ptrProductList = new ProductList;
    ptrRevenueRecord = new RevenueRecord;
    ptrExpenseRecord = new ExpenseRecord;
}
//---------------------------------------------------------
UserInterface::~UserInterface()
{
    delete ptrProductList;
    delete ptrRevenueRecord;
    delete ptrExpenseRecord;
}
//---------------------------------------------------------
void UserInterface::interact()
{
    while (true)
    {
        cout << "To enter data, press 'i', \n"
            << "To output the report, press 'd', \n"
            << "To exit, press 'q': \n";
        ty = getaChar();
        if (ty == 'i') // ввод данных
        {
            cout << "Press 'p' to add the product, \n"
                << "Press 'r' to record the amount of sales, \n"
                << "Press 'e' to record expenses: \n";
            ty = getaChar();
            switch (ty)
            {
                //экраны ввода существуют только во время их
                //использования
            case 'p': ptrProductInputScreen =
                new ProductInputScreen(ptrProductList);
                ptrProductInputScreen->setProduct();
                delete ptrProductInputScreen;
                break;

            case 'r': ptrSellsInputScreen =
                new SellsInputScreen(ptrProductList, ptrRevenueRecord);
                ptrSellsInputScreen->setSells();
                delete ptrSellsInputScreen;
                break;
            case 'e': ptrExpenseInputScreen =
                new ExpenseInputScreen(ptrExpenseRecord);
                ptrExpenseInputScreen->setExpense();
                delete ptrExpenseInputScreen;
                break;
            default: cout << "Unknown function\n";
                break;
            } // конец секции switch
        } // конец условия if
        else if (ty == 'd') // вывод данных
        {
            cout << "Press 'p' to output products, \n"
                << "Press 'r' to output revenue, \n"
                << "Press 'e' to output expenses, \n"
                << "Press 'a' to output the annual report: \n";
            ty = getaChar();
            switch (ty)
            {
            case 'p': ptrProductList->display();
                break;
            case 'r': ptrRevenueRecord->display();
                break;
            case 'e': ptrExpenseRecord->display();
                break;
            case 'a':
                ptrAnnualReport = new AnnualReport(ptrRevenueRecord, ptrExpenseRecord);
                ptrAnnualReport->display();
                delete ptrAnnualReport;
                break;
            default: cout << "Unknown output function\n";
                break;
            } // конец switch
        } // конец elseif
        else if (ty == 'q')
            return; // выход
        else
            cout << "Unknown function. Press only 'i', 'd' or 'q'\n";
    } // конец while
} // конец interact()
