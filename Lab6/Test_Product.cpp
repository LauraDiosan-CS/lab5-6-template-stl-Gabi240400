#include "Test_Product.h"
#include "Product.h"
#include <assert.h>
#include <cstring>
#include <cmath>

void test_getter(){
	char* name1 = new char[10];

	strcpy(name1, "Milka");
	Product p1(1, name1, 3.5);

	assert(p1.get_id() == 1);
	assert(abs(p1.get_price() - 3.5) < 0.0001);
	assert(strcmp(p1.get_name(), "Milka") == 0);

	delete[] name1;
	name1 = NULL;
}

void test_setter(){
	char* name1 = new char[10];

	strcpy(name1, "Milka");
	Product p1(1, name1, 2.5);

	p1.set_id(2);
	assert(p1.get_id() == 2);

    p1.set_price(1.5);
    assert(abs(p1.get_price() - 1.5) < 0.0001);

    p1.set_name("7 days");
    assert(strcmp(p1.get_name(), "7 days") == 0);

    delete[] name1;
    name1 = NULL;
}

void test_eq(){
	char* name1 = new char[10];
	char* name2 = new char[10];

	strcpy(name1, "Milka");
	Product p1(1, name1, 3.5);

	strcpy(name2, "Milka");
	Product p2(1, name2, 3.5);

	assert(p1 == p2);
	delete[] name2;
	name2 = NULL;
	delete[] name1;
	name1 = NULL;
}

void test_assignment(){
    char* name1 = new char[10];
    strcpy(name1, "Milka");
    Product p1(1, name1, 3.5);
    Product p2;
    p2 = p1;

    assert(p2.get_id() == 1);
    assert(abs(p2.get_price() - 3.5) < 0.0001);
    assert(strcmp(p2.get_name(), "Milka") == 0);

    delete[] name1;
    name1 = NULL;
}

void test_all_domain(){
    test_getter();
    test_setter();
    test_eq();
    test_assignment();
}
