#pragma once
//заголовочный файл содержит объявления классов и т.п.
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <numeric> //для accumulate()
#include <iomanip>
#include "productlist.h"
#include "productinputscreen.h"
#include "revenuerow.h"
#include "revenuerecord.h"
#include "sellsinputscreen.h"
using namespace std;


//////////////////// глобальные методы //////////////////////
void getaLine(string& inStr); // получение строки текста
char getaChar(); // получение символа



///////////////////////класс Expense///////////////////////
//Класс затрат
class Expense
{
public:
    int month, day; // месяц и день уплаты расходов
    string category; // категория расходов (газ, свет, ремонт и тд)
    string payee; // кому платим (поставщики газа, света, сервисный центр...)
    float amount; // сколько платим
    Expense()
    { }
    Expense(int m, int d, string c, string p, float a) :
        month(m), day(d), category(c), payee(p), amount(a)
    {
        /* тут пусто! */
    }
};



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



//////////////////класс AnnualReport///////////////////////
//Класс годового отчета
class AnnualReport
{
private:
    RevenueRecord* ptrRR; // записи выручек
    ExpenseRecord* ptrER; // записи расходов
    float expenses, revenues; // суммы выручек и расходов
public:
    AnnualReport(RevenueRecord*, ExpenseRecord*);
    void display(); // отображение годового отчета
};



//////////////////Класс UserInterface//////////////////////
//Главный класс для запуска приложения:
//этот класс определяет взаимодействие пользователя с программой.
class UserInterface
{
private:
    ProductList* ptrProductList;
    ProductInputScreen* ptrProductInputScreen;
    RevenueRecord* ptrRevenueRecord;
    SellsInputScreen* ptrSellsInputScreen;
    ExpenseRecord* ptrExpenseRecord;
    ExpenseInputScreen* ptrExpenseInputScreen;
    AnnualReport* ptrAnnualReport;
    char ty;
public:

    UserInterface();
    ~UserInterface();
    void interact();
}; // конец класса userInterface
