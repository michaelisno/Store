#pragma once
#include "Store.h"
#include "Product.h"
#include <vector>

using namespace std;

class RetailStore : public Store 
{
public:
    RetailStore(string name);

    void DisplayProducts() override;
    bool BuyProduct(int index, User& user) override;

};