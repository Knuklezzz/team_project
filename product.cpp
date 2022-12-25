#include "product.h"
////////////////методы класса Product///////////////////////
//в конструкторе задаём название товара, артикул и цену
Product::Product(string n, int art, float pr) : name(n), article(art), price(pr)
{
    /* тут пусто */
}
//---------------------------------------------------------
Product::~Product() // деструктор
{
    /* тут тоже пусто */
}
//---------------------------------------------------------
string Product::getName() //геттер возвращает название товара
{
    return name;
}

int Product::getArticle() //геттер возвращает артикул товара
{
    return article;
}

float Product::getPrice() //геттер возвращает цену товара
{
    return price;
}

