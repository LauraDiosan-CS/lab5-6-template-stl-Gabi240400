#pragma once
#include "Service.h"

class Console {
private:
    Service service;
public:
    Console();
	Console(Service service);
	~Console();

    void print_menu();
    void run_console();

    void handle_add_product();
    void handle_delete_product_by_id();
    void handle_update_product_by_id();
    void handle_read_product_by_id();
    void handle_print_all_products();

    void buy_product_menu();
    void handle_buy_product();
};
