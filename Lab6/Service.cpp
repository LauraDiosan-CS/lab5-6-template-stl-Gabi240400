#include "Service.h"

Service::Service(){
}

Service::Service(Repo<Product>& repo){
    this->repo = repo;
}


Service::~Service(){
}

int Service::get_size_repo() {
	return this->repo.get_size();
}


vector<Product> Service::get_all(){
    return this->repo.get_all();
}


void Service::add_product(int id, char* name, float price) {
	Product p(id, name, price);
	this->repo.add_entity(p);
}

void Service::update_product_by_id(int id, char* new_name, float new_price) {
    Product p(id, new_name, new_price);
	this->repo.update_entity_by_id(id, p);
}


void Service::delete_product_by_id(int id) {
	this->repo.delete_entity_by_id(id);
}


Product Service::read_product_by_id(int id){
    return this->repo.read_entity_by_id(id);
}
