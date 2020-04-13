#pragma once
#include <vector>
#include <iostream>
using namespace std;

template <class T> class Repo{
protected:
    vector<T> entities;
public:
    Repo(){
        ;
    }

    ~Repo() {
        this->entities.clear();
    }

    void add_entity(T& t){
        for (int i = 0; i < get_size(); i++ )
            if (this->entities[i].get_id() == t.get_id()){
                cout << "Objects can't have the same id!";
                return;
            }
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
