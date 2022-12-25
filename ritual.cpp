#include "ritual.h"
void getaLine(string& inStr) // получение строки текста
{
    char temp[22];
    cin.get(temp, 21, '\n'); //cin.get не закончит ввод при нажатии пробела при вводе названий товаров,
    // состоящих из 2 и более слов
    cin.ignore(21, '\n'); //число пропускаемых символов и символ разделения, cin.ignore дает ввести определенное кол-во символов
    inStr = temp;
}
//---------------------------------------------------------
char getaChar() // получение символа
{
    char ch = cin.get();
    cin.ignore(80, '\n'); //число пропускаемых символов и символ разделения
    return ch;
}

//---------------------------------------------------------
////////////////методы класса userInterface//////////////
UserInterface::UserInterface()
{
    ptrProductList = new ProductList;
    ptrRevenueRecord = new RevenueRecord;
    ptrExpenseRecord = new ExpenseRecord;
}
//---------------------------------------------------------
UserInterface::~UserInterface()
{
    delete ptrProductList;
    delete ptrRevenueRecord;
    delete ptrExpenseRecord;
}
//---------------------------------------------------------
void UserInterface::interact()
{
    while (true)
    {
        cout << "To enter data, press 'i', \n"
            << "To output the report, press 'd', \n"
            << "To exit, press 'q': \n";
        ty = getaChar();
        if (ty == 'i') // ввод данных
        {
            cout << "Press 'p' to add the product, \n"
                << "Press 'r' to record the amount of sales, \n"
                << "Press 'e' to record expenses: \n";
            ty = getaChar();
            switch (ty)
            {
                //экраны ввода существуют только во время их
                //использования
            case 'p': ptrProductInputScreen =
                new ProductInputScreen(ptrProductList);
                ptrProductInputScreen->setProduct();
                delete ptrProductInputScreen;
                break;

            case 'r': ptrSellsInputScreen =
                new SellsInputScreen(ptrProductList, ptrRevenueRecord);
                ptrSellsInputScreen->setSells();
                delete ptrSellsInputScreen;
                break;
            case 'e': ptrExpenseInputScreen =
                new ExpenseInputScreen(ptrExpenseRecord);
                ptrExpenseInputScreen->setExpense();
                delete ptrExpenseInputScreen;
                break;
            default: cout << "Unknown function\n";
                break;
            } // конец секции switch
        } // конец условия if
        else if (ty == 'd') // вывод данных
        {
            cout << "Press 'p' to output products, \n"
                << "Press 'r' to output revenue, \n"
                << "Press 'e' to output expenses, \n"
                << "Press 'a' to output the annual report: \n";
            ty = getaChar();
            switch (ty)
            {
            case 'p': ptrProductList->display();
                break;
            case 'r': ptrRevenueRecord->display();
                break;
            case 'e': ptrExpenseRecord->display();
                break;
            case 'a':
                ptrAnnualReport = new AnnualReport(ptrRevenueRecord, ptrExpenseRecord);
                ptrAnnualReport->display();
                delete ptrAnnualReport;
                break;
            default: cout << "Unknown output function\n";
                break;
            } // конец switch
        } // конец elseif
        else if (ty == 'q')
            return; // выход
        else
            cout << "Unknown function. Press only 'i', 'd' or 'q'\n";
    } // конец while
} // конец interact()
