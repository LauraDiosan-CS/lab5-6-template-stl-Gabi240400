#include "UI.h"
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

Console::Console(){
}

Console::Console(Service service){
    this->service = service;
}


Console::~Console(){
};

void Console::print_menu(){
    cout << "Choose an option:" << endl;
    cout << "01  -> Add product" << endl;
    cout << "02  -> Delete a product by id" << endl;
    cout << "03  -> Update a product by id" << endl;
    cout << "04  -> Print a product by id" << endl;
    cout << "05  -> Print all products" << endl;
    cout << "Write anything else to exit" << endl;
}

void Console::run_console(){
    int option = 0;
    print_menu();
    cin >> option;
    while (option >= 1 && option <= 5){
        if (option == 1)
            handle_add_product();
        else if(option == 2)
            handle_delete_product_by_id();
        else if(option == 3)
            handle_update_product_by_id();
        else if(option == 4)
            handle_read_product_by_id();
        else if(option == 5)
            handle_print_all_products();
        else
            return;
        print_menu();
        cin >> option;
    }
}

void Console::handle_add_product(){
    char* name = new char[10];
    int id;
    float price;
    cout << "Write id: ";
    cin >> id;
    cout << "Write name: ";
    cin >> name;
    cout << "Write price: ";
    cin >> price;
    this->service.add_product(id, name, price);
    delete[] name;
}

void Console::handle_delete_product_by_id(){
    int id;
    cout << "Write the id of the product you want to be deleted: ";
    cin >> id;
    this->service.delete_product_by_id(id);
}

void Console::handle_update_product_by_id(){
    char* new_name = new char[10];
    int id;
    float new_price;
    cout << "Write the id of the product you want to update: ";
    cin >> id;
    cout << "Write new name: ";
    cin >> new_name;
    cout << "Write new price: ";
    cin >> new_price;
    this->service.update_product_by_id(id, new_name, new_price);
    delete[] new_name;
}

void Console::handle_read_product_by_id(){
    int id;
    cout << "Write the id of the product you want to see: ";
    cin >> id;
    cout << this->service.read_product_by_id(id) << endl;
}

void Console::handle_print_all_products(){
    int nr_products = this->service.get_size_repo();
    for (int i = 0; i < nr_products; i++)
        cout << this->service.get_all()[i] << endl;
}





