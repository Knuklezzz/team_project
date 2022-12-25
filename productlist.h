#pragma once
#include "product.h"
#include <list>
#include <iostream>
#include <iomanip>
///////////////////класс ProductList////////////////////////
//класс ProductList — список всех товаров.
//Он содержит множество указателей на класс Product
//и оперирует ими при выводе
class ProductList
{
private:
    // установить указатели на товары
    list <Product*> setPtrsProd; // указатели на класс Product
    list <Product*>::iterator iter; //итератор
public:
    ~ProductList(); // деструктор (удаление товаров)
    void insertProduct(Product*); // добавить товар в список
    int getArt(string); // возвращает артикул товара
    float getPrc(string); //возращает цену товара
    void display(); // вывод списка товаров
};
