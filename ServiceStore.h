#pragma once
#include "Store.h"
#include "Product.h"
#include <vector>

using namespace std;

class ServiceStore : public Store 
{
public:
    ServiceStore(string name);

    void DisplayProducts() override;
    bool BuyProduct(int index, User& user) override;

};