#pragma once
#include <string>
using namespace std;
//////////////////// класс Product (товары/услуги) /////////////////
//Он хранит имя товара/услуги, артикул и цену
//В последующих комментариях "товар/услуга" будет сокращено до "товар"
//для повышения читабельности
class Product
{
private:
    string name; // название товара
    int article; // артикул товара
    float price;
public:
    Product(string n, int art, float pr);
    ~Product();
    int getArticle(); //возвращает артикул товара
    float getPrice(); //возращает цену товара
    string getName(); //возвращает название товара
};
