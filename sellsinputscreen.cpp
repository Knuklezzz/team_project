#include "sellsinputscreen.h"
#include "ritual.h"
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




