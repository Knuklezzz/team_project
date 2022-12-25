#include "productinputscreen.h"
#include "ritual.h"

//---------------------------------------------------------
///////////метод класса ProductInputScreen//////////////////
void ProductInputScreen::setProduct() // добавить данные о товаре
{
    cout << "Enter the name of the product/service: " << endl;
    getaLine(pName);
    cout << "Enter the article number (1234): " << endl;
    cin >> art;
    cin.ignore(80, '\n');
    cout << "Enter the price (499.99): " << endl;
    cin >> prc;
    cin.ignore(80, '\n');
    Product* ptrProduct = new Product(pName, art, prc); // создать товар
    ptrProductList->insertProduct(ptrProduct); // занести в список товаров
}
