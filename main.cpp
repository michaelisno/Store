#include "RetailStore.h"
#include "ServiceStore.h"
#include "User.h"
#include <iostream>

using namespace std;

int main() 
{
    vector<Store*> stores;

    RetailStore petStore("Pet Store");
    petStore.AddProduct(Product("Dog Food", 4.89, 318));
    petStore.AddProduct(Product("Cat Food", 3.39, 343));
    petStore.AddProduct(Product("Fish", 5.10, 128));
    petStore.AddProduct(Product("Rabbit", 15.30, 813));
    stores.push_back(&petStore);

    RetailStore videoGameStore("Video Game Store");
    videoGameStore.AddProduct(Product("Black Ops 6", 69.99, 292));
    videoGameStore.AddProduct(Product("Cyberpunk 2077", 39.99, 129));
    videoGameStore.AddProduct(Product("Controller", 29.19, 109));
    videoGameStore.AddProduct(Product("Headset", 49.99, 592));
    stores.push_back(&videoGameStore);
    
    ServiceStore carGarage("Car Repair Garage");
    carGarage.AddProduct(Product("MOT", 24.99, 203));
    carGarage.AddProduct(Product("Service", 89.99, 144));
    carGarage.AddProduct(Product("Tyre Change", 65, 827));
    stores.push_back(&carGarage);

    User user("Steve", 200);

    bool shopping = true;

    cout << "Welcome to The Mall, " << user.GetName() << "!" << endl;

    while (shopping) 
    {
        cout << "You have: £" << user.GetMoney() << endl << endl;
        cout << "Which store would you like to visit?" << endl << endl;

        for (int i = 0; i < stores.size(); i++)
        {
            cout << (i + 1) << ": " << stores[i]->GetName() << endl;
        }

        cout << "4: Exit" << endl << endl;

        cout << ">> ";

        int option;
        cin >> option;

        cout << endl;

        Store* currentStore = nullptr;

        switch (option) 
        {
        case 1: 
            currentStore = &petStore; 
            break;
        case 2: 
            currentStore = &videoGameStore; 
            break;
        case 3: 
            currentStore = &carGarage; 
            break;
        case 4:
            shopping = false;

            cout << "Thanks for visiting, " << user.GetName() << "!" << endl;
            cout << "You Have: £" << user.GetMoney();

            user.DisplayInventory();

            continue;
        default:
            std::cout << "Error: Invalid choice. Please try again." << endl;
            continue;
        }

        if (currentStore) 
        {
            currentStore->DisplayProducts();

            cout << "Enter the number of the product to buy, or 0 to return to the main menu: ";

            int choice;
            std::cin >> choice;

            if (choice == 0) 
                continue;

            currentStore->BuyProduct(choice, user);
            user.GetMoney();
        }
    }

    return 0;
}