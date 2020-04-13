#pragma once
#include <vector>
#include <cstring>
#include <fstream>
#include <iostream>
#include <cmath>
#include "Repo.h"
using namespace std;

class Money {
private:
    char* file_name_money;
    int no_50_bani;
    int no_1_ron;
    int no_5_ron;
    int no_10_ron;
public:
    Money(){
        this->file_name_money = NULL;
    }

    Money(const char* file_name_money){
        this->file_name_money = new char[strlen(file_name_money) + 1];
        strcpy(this->file_name_money, file_name_money);
        this->load_from_file_money();
    }

    ~Money(){
        ;
    }

    void set_file_name_money(const char* file_name_money){
        if (this->file_name_money != NULL)
            delete[] this->file_name_money;
        this->file_name_money = new char[strlen(file_name_money) + 1];
        strcpy(this->file_name_money, file_name_money);
    }

    void load_from_file_money(){
        if (this->file_name_money != NULL){
            ifstream f(this->file_name_money);
            int no_money = 0;
            int type_money = 0;
            while(f >> type_money){
                if (type_money == 50)
                    f >> this->no_50_bani;
                else if (type_money == 1)
                    f >> this->no_1_ron;
                else if (type_money == 5)
                    f >> this->no_5_ron;
                else if (type_money == 10)
                    f >> this->no_10_ron;
            }
        }
    }

    void save_to_file_money(){
        if (this->file_name_money != NULL){
            ofstream f(this->file_name_money);
            f << 50 << " " << this->no_50_bani << endl;
            f << 1 << " " << this->no_1_ron << endl;
            f << 5 << " " << this->no_5_ron << endl;
            f << 10 << " " << this->no_10_ron;
        }
    }

    int get_no_50_bani(){
        return this->no_50_bani;
    }

    int get_no_1_ron(){
        return this->no_1_ron;
    }

    int get_no_5_ron(){
        return this->no_5_ron;
    }

    int get_no_10_ron(){
        return this->no_10_ron;
    }

    void set_no_50_bani(int no_50_bani){
        this->no_50_bani = no_50_bani;
    }

    void set_no_1_ron(int no_1_ron){
        this->no_1_ron = no_1_ron;
    }

    void set_no_5_ron(int no_5_ron){
        this->no_5_ron = no_5_ron;
    }

    void set_no_10_ron(int no_10_ron){
        this->no_10_ron = no_10_ron;
    }
};
