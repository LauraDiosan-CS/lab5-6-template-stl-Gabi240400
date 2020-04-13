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
    cout << "06  -> Buy a product" << endl;
    cout << "Write anything else to exit" << endl;
}

void Console::run_console(){
    int option = 0;
    print_menu();
    cin >> option;
    while (option >= 1 && option <= 6){
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
        else if(option == 6)
            handle_buy_product();
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
    this->service.save_to_file_entity();
}

void Console::handle_delete_product_by_id(){
    int id;
    cout << "Write the id of the product you want to be deleted: ";
    cin >> id;
    this->service.delete_product_by_id(id);
    this->service.save_to_file_entity();
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
    this->service.save_to_file_entity();
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

void Console::buy_product_menu(){
    cout << "What do you want to do with this money?" << endl;
    cout << "1  -> Buy a product." << endl;
    cout << "2  -> Get the change." << endl;
    cout << "3  -> Insert more money." << endl;
    cout << "4  -> Show credit." << endl;
    this->handle_print_all_products();
}

void Console::handle_buy_product(){
    int id, no_50_bani = 0, no_1_ron = 0, no_5_ron = 0, no_10_ron = 0;
    cout << "Insert the money: " << endl;
    cout << "How many 50 bani do you have? ";
    cin >> no_50_bani;
    cout << "How many 1 ron bills do you have? ";
    cin >> no_1_ron;
    cout << "How many 5 ron bills do you have? ";
    cin >> no_5_ron;
    cout << "How many 10 ron bills do you have? ";
    cin >> no_10_ron;
    this->service.save_to_file_money(no_50_bani, no_1_ron, no_5_ron, no_10_ron);
    float input_sum = 0;
    input_sum = 0.5 * no_50_bani + no_1_ron + 5 * no_5_ron + 10 * no_10_ron;

    while (input_sum != 0){
        this->buy_product_menu();
        int op;
        cin >> op;
        if (op == 1){
            cout << "Write the id of the product you want to buy: ";
            cin >> id;
            this->service.buy_product(id, input_sum);
        }
        else if(op == 2)
            this->service.get_change(input_sum);
        else if(op == 3){
            int new_no_50_bani, new_no_1_ron, new_no_5_ron, new_no_10_ron;
            cout << "How many 50 bani do you have? ";
            cin >> new_no_50_bani;
            cout << "How many 1 ron bills do you have? ";
            cin >> new_no_1_ron;
            cout << "How many 5 ron bills do you have? ";
            cin >> new_no_5_ron;
            cout << "How many 10 ron bills do you have? ";
            cin >> new_no_10_ron;
            this->service.save_to_file_money(new_no_50_bani, new_no_1_ron, new_no_5_ron, new_no_10_ron);
            input_sum += 0.5 * new_no_50_bani + new_no_1_ron + 5 * new_no_5_ron + 10 * new_no_10_ron;
        }
        else if(op == 4)
            cout << "Credit: " << input_sum << endl;
    }
}





