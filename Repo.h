#pragma once
#include <vector>
#include "Product.h"

class Repo {
private:
	vector<Product> products;
	int n;
public:
	Repo();
	~Repo();

	void add_product(Product& p);
	vector<Product> get_all();
};
