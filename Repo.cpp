#include "Repo.h"
#include "Product.h"

Repo::Repo() {
}

Repo::~Repo() {
	this->products.clear();
}

void Repo::add_product(Product& p) {
	this->products.push_back(p);
}

vector<Product> Repo::get_all(){
    return this->products;
}
