#include "productlist.h"
//---------------------------------------------------------
////////////////методы класса ProductList///////////////////
ProductList::~ProductList() // деструктор
{
    while (!setPtrsProd.empty()) // удаление всех товаров, пока список товаров не пуст
    { // удаление указателей из контейнера
        iter = setPtrsProd.begin(); // итератор на начало списка
        delete* iter; //освобождение памяти

        setPtrsProd.erase(iter); //удаление элемента с текущей позиции итератора erase()
    }
}
//---------------------------------------------------------
void ProductList::insertProduct(Product* ptrP)
{
    setPtrsProd.push_back(ptrP); // вставка нового указателя на класс товара в конец списка
}
//---------------------------------------------------------
int ProductList::getArt(string pName) // получить артикул по названию товара
{
    int art;
    iter = setPtrsProd.begin();		//итератор на начало списка товаров
    while (iter != setPtrsProd.end())	// пока не конец списка
    { // поиск товара в списке (достаем у каждого товара его артикул)
        art = (*iter)->getArticle();	//в переменную заносится артикул по объекту, на котором стоит итератор
        if (pName == ((*iter)->getName())) // сравниваем по названиям и
        {
            // если получившаяся пара совпадает - значит,
            //мы нашли запись об этом товаре в списке, в этом случае
            return art; // возвращаем его артикул
        }
        iter++;
    }
    return -1; // если нет - возвращаем -1
}
//--------------------------------------------------------

float ProductList::getPrc(string pName) // получить цену товара по его названию
{
    float prc;
    iter = setPtrsProd.begin();		//итератор на начало списка товаров
    while (iter != setPtrsProd.end())	// пока не конец списка
    { // поиск товара в списке (достаем у каждого товара его цену)
        prc = (*iter)->getPrice();	//в переменную заносится значение цены по объекту, на котором стоит итератор
        if (pName == ((*iter)->getName())) // сравниваем по названиям и
        {
            // если получившаяся пара совпадает - значит,
            //мы нашли запись об этом товаре в списке, в этом случае
            return prc; // возвращаем его цену
        }
        iter++;
    }
    return -1; // если нет - возвращаем -1
}
//--------------------------------------------------------

void ProductList::display() // вывод списка товаров
{
    cout << setw(10) << left << "\nArticle" << setw(20) << left << "Product name" << setw(10) << left << "Price\n";
    if (setPtrsProd.empty()) // если список товаров пуст
        cout << "ERROR:Products have not been added yet\n" << endl; // выводим запись, что он пуст)
    else
    {
        iter = setPtrsProd.begin();
        while (iter != setPtrsProd.end()) // выводим список всех товаров
        {
            cout << "\n" << setw(10) << left << (*iter)->getArticle() << setw(20) << left << (*iter)->getName() << setw(10) << left << (*iter)->getPrice() << endl;
            *iter++;
        }
    }
}
