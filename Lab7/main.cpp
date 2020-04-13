#include <iostream>
#include "Test_Product.h"
#include "Test_Repo.h"
#include "Test_Money.h"
#include "Test_Service.h"
#include "UI.h"

using namespace std;

int main()
{test_all_domain();
test_all_money();
test_all_repo();
test_all_service();

Repo_File<Product> repo("products.txt");
Money money("money.txt");
Service service(repo, money);
Console c(service);
c.run_console();
}
