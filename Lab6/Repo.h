/*#pragma once
#include <vector>
#include "Product.h"

class Repo {
private:
	vector<Product> products;
public:
	Repo();
	~Repo();

	void add_product(Product& p);
	vector<Product> get_all();
	void delete_product_by_id(int id);
	void update_product_by_id(int id, Product& p);
	Product read_product_by_id(int id);
	int get_size();
};
*/

#pragma once
#include <vector>
using namespace std;

template <class T> class Repo{
private:
    vector<T> entities;
public:
    Repo(){
    }

    ~Repo() {
        this->entities.clear();
    }

    void add_entity(T& t){
        this->entities.push_back(t);
    }

    int get_size(){
        return this->entities.size();
    }

    vector<T> get_all(){
        return this->entities;
    }

    void delete_entity_by_id(int id){
        int nr_elements = this->entities.size();
        for (int i = 0; i < nr_elements; i++)
            if (this->entities[i].get_id() == id){
                this->entities.erase(this->entities.begin() + i);
                return;
            }
    }

    void update_entity_by_id(int id, T& t){
        for(int i = 0; i <= this->entities.size(); i++)
        if(this->entities[i].get_id() == id){
            this->entities[i] = t;
            return;
        }
    }

    T read_entity_by_id(int id){
        for(int i = 0; i <= this->entities.size(); i++)
        if(this->entities[i].get_id() == id)
            return entities[i];
    }
};
