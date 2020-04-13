#pragma once
#include <ostream>
#include <cmath>
using namespace std;

class Product {
private:
	char* name;
	int id;
	float price;
public:
	Product();
	Product(int id, char*name, float price);
	Product(const Product& p);
	~Product();

	char* get_name();
	int get_id();
	float get_price();

	void set_name(char* name);
	void set_id(int id);
	void set_price(float price);

	Product& operator=(const Product& p);
	bool operator==(const Product& p);
	bool operator!();
	friend ostream& operator<<(ostream& os, const Product& p);
    friend istream& operator>>(istream& is, Product& p);
};
