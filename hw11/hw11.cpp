// hw11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <string>
#include <iostream>
using namespace std;

//Разработка приложения для предметной области «Учёт товаров в магазине»
//Разработать приложение, позволяющее собирать и накапливать сведения о поступлении и реализации товаров некоторого магазина.
// Структура приложения обязательно должна включать следующие классы : товар, производитель, документ, поступление товара, 
// реализация товара и др. 


class Product // товар 
{
protected:
    string name =" ", mnfctd=" ";
    float price=0;
    int id=0;

public:
    Product()
    {
        cout << " ";
    }

    int getId() { return id; }
    void setId(int _id) { id = _id; }

    string getName() { return name; }
    void setName(string _name) { name = _name; }

    string getMnfctd() { return mnfctd; }
    void setMnfctd(string _mnfctd) { name = _mnfctd; }

    float getPrice() { return price; }
    void setPrice(float _price) { price = _price; }

    Product(string mnfctd, int id, string name, float price)
    {
        this->mnfctd = mnfctd;
        this->id = id;
        this->name = name;
        this->price = price;

    }

    void get_info_product()
    {
        cout << "\nBarcode " << id << ", " << mnfctd << ". " << name << " - " << price << '$';
    }

};

class Purchase : public Product // ннформация о поступившем товаре
{
protected:
    Product* all_products = new Product[10]   // массив поступившего
    {
         Product("Manufactory 1", 1, "Milk", 2),
         Product("Manufactory 1", 2, "Bread", 0.99),
         Product("Manufactory 2", 3, "Tomatoes 1 kg", 1.99),
         Product("Manufactory 2", 4, "Cucumbers 1 kg", 2.50),
         Product("Manufactory 2", 5, "Avocado 1 kg", 4.90),
         Product("Manufactory 2", 6, "Juice", 1.25),
         Product("Manufactory 2", 7, "Water", 0.25),
         Product("Manufactory 2", 8, "Bacon", 4.50),
         Product("Manufactory 3", 9, "Cheese", 10.90),
         Product("Manufactory 3", 10, "Sausage", 14.75),
    };
};

class Sale : public  Purchase, public Product// информация о проданном товаре
{
protected:
    Product* sale_products = new Product[5]  // массив проданного
    {
         Product("Manufactory 1", 1, "Milk", 2),
         Product("Manufactory 1", 2, "Bread", 0.99),
         Product("Manufactory 2", 6, "Juice", 1.25),
         Product("Manufactory 2", 8, "Bacon", 4.50),
         Product("Manufactory 3", 10, "Sausage", 14.75),
    };
};

class Document : public Sale, public  Purchase, public Product // документы обо всех операциях с товарами
{
public:

    void print_purchase()
    {
        cout << "\tЧек \n";
        cout << "Продуктов поставлено: \n";
        for (int i = 0; i < 10; i++)
        {
            Purchase::all_products[i].Product::get_info_product();
        }
    }

    void print_sale()
    {
        cout << "\n\tЧек \n";
        cout << "Продуктов продано: \n";
        for (int i = 0; i < 5; i++)
        {
            sale_products[i].get_info_product();
        }
    }

    void print_rest()
    {
        cout << "\n\tЧек \n";
        cout << "Продуктов на складе: \n";
        for (int i = 0; i < sizeof(Purchase::all_products); i++)
        {
            for (int i = 0; i < 5; i++)
            {
                if (Purchase::all_products[i].getId() != sale_products[i].getId())
                {
                    sale_products[i].get_info_product();

                }
            }
        }
    }
};

class Admin : public Document // админ, которому поступает весь учёт, просто для имитации работы магазина
{
public:

    Admin()
    {
        cout << " ";
    }

    void admin_print_purchase()
    {
        print_purchase();
    }

    void admin_print_sale()
    {
        print_sale();
    }

    void admin_print_rest()
    {
        print_rest();
    }
};

int main()
{
    setlocale(LC_ALL, "ru");

    Admin admin;
    admin.admin_print_purchase();
    cout << endl;
    admin.admin_print_sale();
}