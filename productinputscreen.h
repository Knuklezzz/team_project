#pragma once
#include "productlist.h"
////////////////класс ProductInputScreen////////////////////
//класс ProductInputScreen. Это класс, отвечающий за отображение «экрана»,
//куда пользователь может ввести данные о новом товаре:
class ProductInputScreen

{
private:
    ProductList* ptrProductList;
    string pName;
    int art;
    float prc;
public:
    ProductInputScreen(ProductList* ptrPL) : ptrProductList(ptrPL)
    {
        /* тут пусто */
    }
    void setProduct(); // добавить данные о товаре
};
