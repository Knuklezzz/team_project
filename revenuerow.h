#pragma once
#include <numeric>
#include <iomanip>
using namespace std;

////////////////////класс RevenueRow//////////////////////////
//класс, хранящий одну табличную строку выручки
// одна строка таблицы прибыли: артикул и 12 выручек по месяцам
class RevenueRow
{
private:
    int art; // артикул товара
    int ar;
    float revenue[12]; // месяцы
    float prc; //стоимость товара
public:
    RevenueRow(int); // конструктор с одним параметром
    void setRevenue(int, int, float); // подсчитать выручку за месяц
    float getSumOfRow(); //подсчитать сумму выручек с одного товара за год
    int getArt(); //Запрос артикула товара
    float getRevenueM(int); //Запрос выручки за определенный месяц
};
