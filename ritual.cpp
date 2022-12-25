#include <iostream>
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

////////////////методы класса Product///////////////////////
//в конструкторе задаём название товара, артикул и цену
Product::Product(string n, int art, int pr) : name(n), article(art), price(pr)
{
    /* тут пусто */
}
//---------------------------------------------------------
Product::~Product() // деструктор
{
    /* тут тоже пусто */
}
//---------------------------------------------------------
string Product::getName() //геттер возвращает название товара
{
    return name;
}

int Product::getArticle() //геттер возвращает артикул товара
{
    return article;
}

int Product::getPrice() //геттер возвращает цену товара
{
    return price;
}
//--------------------------------------------------------





//---------------------------------------------------------
///////////метод класса ProductInputScreen//////////////////
void ProductInputScreen::setProduct() // добавить данные о товаре
{
    cout << "Enter the name of the product/service: " << endl;
    getaLine(pName);
    cout << "Enter the article number (1234): " << endl;
    cin >> art;
    cin.ignore(80, '\n');
    cout << "Enter the price (5000): " << endl;
    cin >> prc;
    cin.ignore(80, '\n');
    Product* ptrProduct = new Product(pName, art, prc); // создать товар
    ptrProductList->insertProduct(ptrProduct); // занести в список товаров
}





//---------------------------------------------------------
////////////////методы класса ProductList///////////////////
ProductList::~ProductList() // деструктор
{
    while (!setPtrsProd.empty()) // удаление всех товаров, пока список товаров не пуст
    { // удаление указателей из контейнера
        iter = setPtrsProd.begin(); // итератор на начало списка
        delete* iter; //освобождение памяти

        setPtrsProd.erase(iter); //удаление элемента с текущей позиции итератора erase()
    }
}
//---------------------------------------------------------
void ProductList::insertProduct(Product* ptrP)
{
    setPtrsProd.push_back(ptrP); // вставка нового указателя на класс товара в конец списка
}
//---------------------------------------------------------
int ProductList::getArt(string pName) // получить артикул по названию товара
{
    int art;
    iter = setPtrsProd.begin();		//итератор на начало списка товаров
    while (iter != setPtrsProd.end())	// пока не конец списка
    { // поиск товара в списке (достаем у каждого товара его артикул)
        art = (*iter)->getArticle();	//в переменную заносится артикул по объекту, на котором стоит итератор
        if (pName == ((*iter)->getName())) // сравниваем по названиям и
        {
            // если получившаяся пара совпадает - значит,
            //мы нашли запись об этом товаре в списке, в этом случае
            return art; // возвращаем его артикул
        }
        iter++;
    }
    return -1; // если нет - возвращаем -1
}
//--------------------------------------------------------

int ProductList::getPrc(string pName) // получить цену товара по его названию
{
    int prc;
    iter = setPtrsProd.begin();		//итератор на начало списка товаров
    while (iter != setPtrsProd.end())	// пока не конец списка
    { // поиск товара в списке (достаем у каждого товара его цену)
        prc = (*iter)->getPrice();	//в переменную заносится значение цены по объекту, на котором стоит итератор
        if (pName == ((*iter)->getName())) // сравниваем по названиям и
        {
            // если получившаяся пара совпадает - значит,
            //мы нашли запись об этом товаре в списке, в этом случае
            return prc; // возвращаем его цену
        }
        iter++;
    }
    return -1; // если нет - возвращаем -1
}
//--------------------------------------------------------

void ProductList::display() // вывод списка товаров
{
    cout << setw(10) <<left <<"\nArticle" << setw(20) <<left << "Product name"<< setw(10)<< left<<  "Price\n" ;
    if (setPtrsProd.empty()) // если список товаров пуст
        cout << "ERROR:Products have not been added yet\n" << endl; // выводим запись, что он пуст)
    else
    {
        iter = setPtrsProd.begin();
        while (iter != setPtrsProd.end()) // выводим список всех товаров
        {
            cout << "\n" << setw(10) << left << (*iter)->getArticle() << setw(20) << left << (*iter)->getName() << setw(10) << left << (*iter)->getPrice() << endl;
            *iter++;
        }
    }
}






//---------------------------------------------------------
/////////////////методы класса RevenueRow/////////////////////

RevenueRow::RevenueRow(int ar) : art(ar) //конструктор
{ //Алгоритм fill() помещает копию значения value (у нас это 0)
//в каждый элемент диапазона, ограниченного парой итераторов [first,last).
//Т.е. в конструкторе просто инициализируем массив значениями 0.
    fill(&revenue[0], &revenue[12], 0);
}
//---------------------------------------------------------
void RevenueRow::setRevenue(int m, float am, int pr) // сеттер выручка за месяц m, выручка - am * pr
{
    revenue[m] = am * pr; // привязываем оплату к месяцу
}
//---------------------------------------------------------
int RevenueRow::getArt() // геттер запрос артикула
{
    return art;
}
//---------------------------------------------------------
float RevenueRow::getRevenueM(int month) //Геттер запрос выручки за месяц month
{
    return revenue[month];
}
//---------------------------------------------------------
float RevenueRow::getSumOfRow() // cумма выручек в строке
{ //По умолчанию алгоритм accumulate() суммирует элементы.
 //Нужно указать точку старта, конечную точку и значение от которого начинаем прибавлять.
 //Чаще всего это ноль, но может быть и результат других вычислений.
    return accumulate(&revenue[0], &revenue[12], 0);
}





//---------------------------------------------------------
/////////////////методы класса RevenueRecord//////////////////
RevenueRecord::~RevenueRecord() // деструктор
{ // удалить строки с выручками,
// удалить указатели из множества.
    while (!setPtrsRR.empty())
    {
        iter = setPtrsRR.begin();
        delete* iter;
        setPtrsRR.erase(iter);
    }
}
//---------------------------------------------------------
void RevenueRecord::insertRevenue(int art, int month, float amount, int prc)
{

    iter = setPtrsRR.begin(); // Инициализация итератора
    while (iter != setPtrsRR.end()) // условие выхода
    { // если текущий объект совпадает с созданным для поиска,
        if (art == (*iter)->getArt())
        { // заносим выручку в список
            (*iter)->setRevenue(month, amount, prc);
            return;
        }
        else
            iter++;
    } // если не нашли строку - создаем новую
    RevenueRow* ptrRow = new RevenueRow(art);
    ptrRow->setRevenue(month, amount, prc); // заносим данные для подсчета выручки
    setPtrsRR.push_back(ptrRow); // заносим строку в список
}
//---------------------------------------------------------
void RevenueRecord::display() // отобразить все строки с выручками
{
    cout << setw(10) << left << "\nArticle" << setw(8) << left << "Jan" << setw(8) << left << "Feb"
        << setw(8) << left << "Mar" << setw(8) << left << "Apr" << setw(8) << left << "May"
        << setw(8) << left << "June" << setw(8) << left << "July" << setw(8) << left << "Aug"
        << setw(8) << left << "Sep" << setw(8) << left << "Oct" << setw(8) << left << "Nov"
        << setw(8)<< left << "Dec" << "\n" << endl
        << "----------------------------------------------------------------------------------------------------\n" << endl;
    if (setPtrsRR.empty())
        cout << "***No recorded sales***\n" << endl;
    else
    {
        iter = setPtrsRR.begin(); //итератор на список с указателями на объекты RevenueRow
        while (iter != setPtrsRR.end())
        {
            cout << setw(9) << left << (*iter)->getArt(); // вывести артикул товара
            for (int j = 0; j < 12; j++) // вывести 12 значений выручки
            {
                if (((*iter)->getRevenueM(j)) == 0)
                    cout << setw(8) << left << "0";
                else
                    cout << setw(7) << left << (*iter)->getRevenueM(j) << " ";
            }
            cout << endl;
            iter++;
        }
        cout << endl;
        cout << endl;
    }
}
//---------------------------------------------------------
float RevenueRecord::getSumOfRevenues() // сумма всех выручек всех товаров
{
    float sumRevenues = 0.0;
    iter = setPtrsRR.begin();

    while (iter != setPtrsRR.end())
    {
        sumRevenues += (*iter)->getSumOfRow();	//суммирование выручек за все месяцы с разных товаров
        iter++;
    }
    return sumRevenues;
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
