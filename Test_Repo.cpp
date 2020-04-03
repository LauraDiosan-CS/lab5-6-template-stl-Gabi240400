#include"Test_Repo.h"
#include"Repo.h"
#include"Product.h"
#include<assert.h>
#include<cstring>
#include<vector>

void test_get_all(){
	char* name1 = new char[10];
	char* name2 = new char[10];

	strcpy(name1, "milka");
	Product p1(1, name1, 3.5);

	strcpy(name2, "apa");
	Product p2(1, name2, 2);

	Repo r;
	r.add_product(p1);
	r.add_product(p2);

    assert(r.get_all()[0] == p1);
    assert(r.get_all()[1] == p2);

    delete[] name2;
    name2 = NULL;
    delete[] name1;
    name1 = NULL;
}

void test_add_product(){
    char* name1 = new char[10];

	strcpy(name1, "milka");
	Product p1(1, name1, 3.5);

	Repo r;
	r.add_product(p1);

    assert(r.get_all()[0] == p1);
    assert(r.get_all()[0].get_id() == 1);
    assert(strcmp(r.get_all()[0].get_name(), name1) == 0);
    assert(abs(r.get_all()[0].get_price() - 3.5) < 0.0001);

    delete[] name1;
    name1 = NULL;
}

void test_all_repo(){
    test_get_all();
    test_add_product();
}
