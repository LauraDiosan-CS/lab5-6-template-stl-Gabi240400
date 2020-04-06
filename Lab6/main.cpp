#include <iostream>
#include "Test_Product.h"
#include "Test_Repo.h"
#include "Test_Service.h"
#include "UI.h"

using namespace std;

int main()
{test_all_domain();
test_all_repo();
test_all_service();

Console c;
c.run_console();
}
