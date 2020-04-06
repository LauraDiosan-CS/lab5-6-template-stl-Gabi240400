#pragma once
#include "Repo.h"
#include "Product.h"
#include <vector>

using namespace std;

class Service {
private:
	Repo<Product> repo;
public:
    Service();
	Service(Repo<Product>& repo);
	~Service();

	int get_size_repo();
	vector<Product> get_all();
	void add_product(int id, char* name, float price);
	void update_product_by_id(int id, char* new_name, float new_price);
	void delete_product_by_id(int id);
	Product read_product_by_id(int id);
};
