#include "Product.h"
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

Product::Product() {
    this->id = 0;
	this->price = 0.0;
	this->name = NULL;
}

Product::Product(int id, char* name, float price){
    this->id = id;
    this->price = price;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

Product::Product(const Product &p) {
	this->name = new char[strlen(p.name) + 1];
	strcpy(this->name, p.name);
	this->price = p.price;
	this->id = p.id;
}

Product::~Product() {
	if (this->name) {
		delete[] this->name;
		this->name = NULL;
	}
}

char* Product::get_name() {
	return this->name;
}

int Product::get_id(){
    return this->id;
}

float Product::get_price() {
	return this->price;
}

void Product::set_name(char* name)
{
	if (this->name) {
		delete[] this->name;
	}
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void Product::set_id(int id){
    this->id = id;
}

void Product::set_price(float price) {
	this->price = price;
}


Product& Product::operator=(const Product& p) {
	this->set_name(p.name);
	this->set_id(p.id);
	this->set_price(p.price);
	return *this;
}

bool Product:: operator==(const Product& p) {
	return strcmp(this->name, p.name) == 0 && this->id == p.id && abs(this->price - p.price) < 0.0001;
}

bool Product::operator!(){
	if (this->name == NULL || strlen(this->name) == 0)
		return true;
	return false;
}

ostream& operator<<(ostream& os, const Product& p){
	os << p.id <<" "<< p.name << " " <<p.price;
	return os;
}

istream& operator>>(istream& is, Product& p){
	char name[15];
	int id;
	float price;
	is >> id >> name >> price;
	p.set_id(id);
	p.set_name(name);
	p.set_price(price);
	return is;
}
