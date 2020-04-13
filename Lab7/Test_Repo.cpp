#include"Test_Repo.h"
#include"Repo.h"
#include"Product.h"
#include"Repo_File.h"
#include<assert.h>
#include<cstring>
#include<vector>

void test_load_from_file_entity(){
    Product p1(1, "milka", 3.5);
    Product p2(2, "pufuleti", 2);
    Product p3(3, "apa", 2.5);
    Product p4(4, "mar", 1);
    vector<Product> products;
    products.push_back(p1);
    products.push_back(p2);
    products.push_back(p3);
    products.push_back(p4);

    Repo_File<Product> repo;
    repo.set_file_name_entities("products_test.txt");
	repo.load_from_file_entity();
	for (int i = 0; i < repo.get_size(); i++)
        assert(repo.get_all()[i] == products[i]);
}

void test_save_to_file_entity(){
    Product p1(1, "milka", 3.5);
    Product p2(2, "pufuleti", 2);
    Product p3(3, "apa", 2.5);
    Product p4(4, "mar", 1);
    Product p5(5, "aer", 100);
    vector<Product> products;
    products.push_back(p1);
    products.push_back(p2);
    products.push_back(p3);
    products.push_back(p4);
    products.push_back(p5);

    Repo_File<Product> repo;
    repo.set_file_name_entities("products_test.txt");
    repo.load_from_file_entity();
    int initial_len = repo.get_size();
    Product p(5, "aer", 100);
    repo.add_entity(p);
    repo.save_to_file_entity();
    repo.load_from_file_entity();
    for(int i = 0; i < initial_len + 1; i++)
        assert(repo.get_all()[i] == products[i]);
    repo.delete_entity_by_id(5);
    repo.save_to_file_entity();
}

void test_get_all(){
    Product p1(1, "milka", 3.5);
    Product p2(2, "pufuleti", 2);
    Product p3(3, "apa", 2.5);
    Product p4(4, "mar", 1);
    vector<Product> products;
    products.push_back(p1);
    products.push_back(p2);
    products.push_back(p3);
    products.push_back(p4);

    Repo_File<Product> repo;
    repo.set_file_name_entities("products_test.txt");
	repo.load_from_file_entity();
	for (int i = 0; i < repo.get_size(); i++)
        assert(repo.get_all()[i] == products[i]);
}

void test_add_product(){
    Repo_File<Product> repo;
    repo.set_file_name_entities("products_test.txt");
    repo.load_from_file_entity();
    int initial_len = repo.get_size();
    Product p(5, "aer", 100);
    repo.add_entity(p);

    assert(repo.get_all()[initial_len].get_id() == 5);
    assert(strcmp(repo.get_all()[initial_len].get_name(), "aer") == 0);
    assert(abs(repo.get_all()[initial_len].get_price()-100) < 0.0001);

    repo.delete_entity_by_id(5);
    repo.save_to_file_entity();
}

void test_get_size(){
    Repo_File<Product> repo;
    repo.set_file_name_entities("products_test.txt");
    repo.load_from_file_entity();

    assert(repo.get_size() == 4);
}

void test_delete_by_id(){
    Repo_File<Product> repo;
    repo.set_file_name_entities("products_test.txt");
    repo.load_from_file_entity();
    int initial_len = repo.get_size();
    repo.delete_entity_by_id(4);

    assert(repo.get_size() == initial_len - 1);
    assert(repo.get_all()[initial_len - 2].get_id() == 3);

    Product p4(4, "mar", 1);
    repo.add_entity(p4);
    repo.save_to_file_entity();
}

void test_read_by_id(){
    Repo_File<Product> repo;
    repo.set_file_name_entities("products_test.txt");
    repo.load_from_file_entity();
    Product p(2, "pufuleti", 2);

    assert(repo.read_entity_by_id(2) == p);
}

void test_update_by_id(){
    Repo_File<Product> repo;
    repo.set_file_name_entities("products_test.txt");
    repo.load_from_file_entity();
    int initial_len = repo.get_size();
    Product p1(2, "capsuni", 10);
    Product p2(2, "pufuleti", 2);
    repo.update_entity_by_id(2, p1);

    assert(repo.read_entity_by_id(2) == p1);

    repo.update_entity_by_id(2, p2);
    repo.save_to_file_entity();
}

void test_all_repo(){
    test_load_from_file_entity();
    test_save_to_file_entity();
    test_get_all();
    test_add_product();
    test_delete_by_id();
    test_get_size();
    test_update_by_id();
    test_read_by_id();
}
