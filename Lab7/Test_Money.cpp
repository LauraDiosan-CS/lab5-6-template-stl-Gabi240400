#include "Test_Money.h"
#include "Money.h"
#include <assert.h>


void test_get(){
    Money money("money_test.txt");

    assert(money.get_no_50_bani() == 1);
    assert(money.get_no_1_ron() == 33);
    assert(money.get_no_5_ron() == 3);
    assert(money.get_no_10_ron() == 6);
}

void test_set(){
    Money money("money_test.txt");

    money.set_no_50_bani(2);
    money.set_no_1_ron(3);
    money.set_no_5_ron(5);
    money.set_no_10_ron(10);
    money.save_to_file_money();

    assert(money.get_no_50_bani() == 2);
    assert(money.get_no_1_ron() == 3);
    assert(money.get_no_5_ron() == 5);
    assert(money.get_no_10_ron() == 10);

    money.set_no_50_bani(1);
    money.set_no_1_ron(33);
    money.set_no_5_ron(3);
    money.set_no_10_ron(6);
    money.save_to_file_money();
}

void test_save_to_file_money(){
    Money money("money_test.txt");
    money.set_no_50_bani(2);
    money.set_no_1_ron(3);
    money.set_no_5_ron(5);
    money.set_no_10_ron(10);
    money.save_to_file_money();
    money.load_from_file_money();

    assert(money.get_no_50_bani() == 2);
    assert(money.get_no_1_ron() == 3);
    assert(money.get_no_5_ron() == 5);
    assert(money.get_no_10_ron() == 10);

    money.set_no_50_bani(1);
    money.set_no_1_ron(33);
    money.set_no_5_ron(3);
    money.set_no_10_ron(6);
    money.save_to_file_money();
}

void test_all_money(){
    test_get();
    test_set();
    test_save_to_file_money();
}
