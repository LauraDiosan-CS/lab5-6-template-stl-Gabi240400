#include "Service.h"

Service::Service(){
}

Service::Service(Repo_File<Product>& repo, Money money){
    this->repo = repo;
    this->money = money;
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

void Service::save_to_file_entity(){
    this->repo.save_to_file_entity();
}

void Service::save_to_file_money(int no_50_bani, int no_1_ron, int no_5_ron, int no_10_ron){
    this->money.set_no_50_bani(this->money.get_no_50_bani() + no_50_bani);
    this->money.set_no_1_ron(this->money.get_no_1_ron() + no_1_ron);
    this->money.set_no_5_ron(this->money.get_no_5_ron() + no_5_ron);
    this->money.set_no_10_ron(this->money.get_no_10_ron() + no_10_ron);
    this->money.save_to_file_money();
}

void Service::buy_product(int id, float& input_sum){
    float product_price = 0;
    for (int i = 0; i < this->repo.get_size(); i++)
        if (this->repo.get_all()[i].get_id() == id){
            product_price = this->repo.get_all()[i].get_price();
            break;
        }
    if (input_sum >= product_price)
        input_sum = input_sum - product_price;
    else
        cout << "You don't have enough money to buy this product." << endl;
}

void Service::get_change(float& input_sum){
    if (this->money.get_no_50_bani() * 0.5 >= input_sum){
        int i = 0;
        while(abs(0.5 * i - input_sum) > 0.0001)
            i++;
        this->money.set_no_50_bani(this->money.get_no_50_bani() - i);
        input_sum = 0;
        this->money.save_to_file_money();
    }
    else
        cout << "The vending machine doesn't have enough money for your change." << endl;
}

