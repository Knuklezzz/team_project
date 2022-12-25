#pragma once
#include "revenuerecord.h"
#include "productlist.h"
using namespace std;

////////////////////класс SellsInputScreen //////////////////
//Экран для добавления количества продаж
class SellsInputScreen
{
private:
    ProductList* ptrProductList; // список товаров
    RevenueRecord* ptrRevenueRecord; // список записей выручек
    string productName; // название товара, кол-во продаж которого фиксируем
    int amountSold; // кол-во продаж
    int month; // месяц, за который фиксируем количество продаж
    int art; // артикул товара, кол-во продаж которого фиксируем
    float prc; // цена товара, кол-во продаж которого фиксируем
public:
    SellsInputScreen(ProductList* ptrPL, RevenueRecord* ptrRR) : ptrProductList(ptrPL), ptrRevenueRecord(ptrRR)

    {
        /*тут пусто*/
    }
    void setSells(); // добавить количество продаж
};
