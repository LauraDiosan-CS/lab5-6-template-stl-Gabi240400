#pragma once
#include "Repo_File.h"
#include "Money.h"
#include "Product.h"
#include <vector>

using namespace std;

class Service {
private:
	Repo_File<Product> repo;
	Money money;
public:
    Service();
	Service(Repo_File<Product>& repo, Money money);
	~Service();

	int get_size_repo();
	vector<Product> get_all();
	void add_product(int id, char* name, float price);
	void update_product_by_id(int id, char* new_name, float new_price);
	void delete_product_by_id(int id);
	Product read_product_by_id(int id);

	void save_to_file_entity();

	void save_to_file_money(int no_50_bani, int no_1_ron, int no_5_ron, int no_10_ron);
	void buy_product(int id, float& input_sum);
	void get_change(float& input_sum);
};
