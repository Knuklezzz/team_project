#include "revenuerecord.h"

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
void RevenueRecord::insertRevenue(int art, int month, int amount, float prc)
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





