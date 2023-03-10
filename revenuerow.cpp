#include "revenuerow.h"
//---------------------------------------------------------
/////////////////методы класса RevenueRow/////////////////////

RevenueRow::RevenueRow(int ar) : art(ar) //конструктор
{ //Алгоритм fill() помещает копию значения value (у нас это 0)
//в каждый элемент диапазона, ограниченного парой итераторов [first,last).
//Т.е. в конструкторе просто инициализируем массив значениями 0.
    fill(&revenue[0], &revenue[12], 0);
}
//---------------------------------------------------------
void RevenueRow::setRevenue(int m, int am, float pr) // сеттер выручка за месяц m, выручка - am * pr
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





