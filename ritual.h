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
using namespace std;
//////////////////// глобальные методы //////////////////////
void getaLine(string& inStr); // получение строки текста
char getaChar(); // получение символа


////////////////////класс RevenueRow//////////////////////////
//класс, хранящий одну табличную строку выручки
// одна строка таблицы прибыли: артикул и 12 выручек по месяцам
class RevenueRow
{
private:
    int art; // артикул товара
    float revenue[12]; // месяцы
    float prc; //стоимость товара
public:
    RevenueRow(int); // конструктор с одним параметром
    void setRevenue(int, int, float); // подсчитать выручку за месяц
    float getSumOfRow(); //подсчитать сумму выручек с одного товара за год
    int getArt(); //Запрос артикула товара
    float getRevenueM(int); //Запрос выручки за определенный месяц
};




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
