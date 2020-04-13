#pragma once
#include <vector>
#include <cstring>
#include <fstream>
#include <iostream>
#include <cmath>
#include "Repo.h"
using namespace std;

template <class T> class Repo_File : public Repo <T> {
private:
    char* file_name_entities;
public:
    Repo_File() : Repo<T>(){
        this->file_name_entities = NULL;
    }

    Repo_File(const char* file_name_entities){
        this->file_name_entities = new char[strlen(file_name_entities) + 1];
        strcpy(this->file_name_entities, file_name_entities);
        this->load_from_file_entity();
    }

    ~Repo_File(){
        ;
    }

    void set_file_name_entities(const char* file_name_entities){
        if (this->file_name_entities != NULL)
            delete[] this->file_name_entities;
        this->file_name_entities = new char[strlen(file_name_entities) + 1];
        strcpy(this->file_name_entities, file_name_entities);
    }

    void load_from_file_entity(){
        if (this->file_name_entities != NULL){
            this->entities.clear();
            ifstream f(this->file_name_entities);
            T element;
            while (f >> element)
                if(!!element)
                    this->add_entity(element);
            f.close();
        }
    }

    void save_to_file_entity(){
        if (this->file_name_entities != NULL){
            ofstream f(this->file_name_entities);
            for (int i = 0; i < this->entities.size(); i++)
                f << this->entities[i] << endl;
            f.close();
        }
    }
};
