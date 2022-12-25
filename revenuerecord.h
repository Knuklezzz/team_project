#pragma once
#include <iostream>
#include <list>
#include <iomanip>
#include "revenuerow.h"

//////////////////// класс RevenueRecord ///////////////////////
//класс RevenueRecord. Он хранит непосредственно записи о выручке.
//С ним будет взаимодействовать экран добавления количества продаж.
class RevenueRecord
{
private:
    list <RevenueRow*> setPtrsRR; // список указателей на объекты класса RevenueRow
    list <RevenueRow*>::iterator iter;
public:
    ~RevenueRecord();
    void insertRevenue(int, int, int, float); // добавить выручку
    void display(); // отобразить все строки с выручками
    float getSumOfRevenues(); // подсчитать сумму всех выручек всех жильцов
};
