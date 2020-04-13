#include"Test_Service.h"
#include"Service.h"
#include"Product.h"
#include<assert.h>
#include<cstring>
#include<vector>

void test_get_all_s(){
	char* name1 = new char[10];
	char* name2 = new char[10];

	strcpy(name1, "milka");
	strcpy(name2, "apa");
	Product p1(1, name1, 3.5);
	Product p2(2, name2, 2);

	Service s;
	s.add_product(1, name1, 3.5);
	s.add_product(2, name2, 2);

    assert(s.get_all()[0] == p1);
    assert(s.get_all()[1] == p2);

    delete[] name2;
    name2 = NULL;
    delete[] name1;
    name1 = NULL;
}

void test_add_product_s(){
    char* name1 = new char[10];

	strcpy(name1, "milka");
	Product p1(1, name1, 3.5);

	Service s;
	s.add_product(1, name1, 3.5);

    assert(s.get_all()[0] == p1);
    assert(s.get_all()[0].get_id() == 1);
    assert(strcmp(s.get_all()[0].get_name(), name1) == 0);
    assert(abs(s.get_all()[0].get_price() - 3.5) < 0.0001);

    delete[] name1;
    name1 = NULL;
}

void test_get_size_repo(){
    char* name1 = new char[10];
	char* name2 = new char[10];

	strcpy(name1, "milka");
	strcpy(name2, "apa");

	Service s;

	s.add_product(1, name1, 3.5);
	assert(s.get_size_repo() == 1);
	s.add_product(2, name2, 2);
	assert(s.get_size_repo() == 2);

    delete[] name2;
    name2 = NULL;
    delete[] name1;
    name1 = NULL;
}

void test_delete_by_id_s(){
    char* name1 = new char[10];
	char* name2 = new char[10];

	strcpy(name1, "milka");
	strcpy(name2, "apa");

	Service s;

	s.add_product(1, name1, 3.5);
	s.add_product(2, name2, 2);
	s.delete_product_by_id(1);

	assert(s.get_size_repo() == 1);
	Product p2(2, name2, 2);
	assert(s.get_all()[0] == p2);

    delete[] name2;
    name2 = NULL;
    delete[] name1;
    name1 = NULL;
}

void test_update_by_id_s(){
    char* name1 = new char[10];
	char* name2 = new char[10];

	strcpy(name1, "milka");
	strcpy(name2, "apa");

	Service s;

	s.add_product(1, name1, 3.5);
	s.update_product_by_id(1, name2, 2);

	assert(s.get_size_repo() == 1);
	Product p2(1, name2, 2);
	assert(s.get_all()[0] == p2);

    delete[] name2;
    name2 = NULL;
    delete[] name1;
    name1 = NULL;
}

void test_read_by_id_s(){
    char* name1 = new char[10];
	char* name2 = new char[10];

	strcpy(name1, "milka");
	Product p1(1, name1, 3.5);

	strcpy(name2, "apa");
	Product p2(2, name2, 2);

	Service s;

	s.add_product(1, name1, 3.5);
	s.add_product(2, name2, 2);

	assert(s.get_size_repo() == 2);
	assert(s.read_product_by_id(1) == p1);
	assert(s.read_product_by_id(2) == p2);

    delete[] name2;
    name2 = NULL;
    delete[] name1;
    name1 = NULL;
}

void test_get_change(){
    Money money("money_test.txt");
    Repo_File<Product> repo;
    Service s(repo, money);

    float credit = 0.5;
    s.get_change(credit);

    assert(credit == 0);

    money.load_from_file_money();
    assert(money.get_no_50_bani() == 0);

    money.set_no_50_bani(1);
    money.save_to_file_money();
}

void test_all_service(){
    test_get_all_s();
    test_add_product_s();
    test_delete_by_id_s();
    test_get_size_repo();
    test_update_by_id_s();
    test_read_by_id_s();

    test_get_change();
}


