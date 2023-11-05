#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

class component
{
private:
    string itemName;
    string itemCode;
    string itemDescription;
    float itemPrice;

public:
    component()
    {
        itemName = "N/A"; /* N/A (Not Allocated) */
        itemCode = "N/A";
        itemDescription = "N/A";
        itemPrice = 0;
    }

    /* setter functions */
    void setItemName(string name)
    {
        itemName = name;
    }
    void setItemCode(string code)
    {
        itemCode = code;
    }
    void setItemDescription(string description)
    {
        itemDescription = description;
    }
    void setItemPrice(float price)
    {
        itemPrice = price;
    }

    // Function to display the component details
    void displayDetail()
    {
        int columnWidth = 30;
        char fillChar = ' ';
        // Print the data
        cout << left << setw(columnWidth) << setfill(fillChar) << itemName;
        cout << left << setw(columnWidth) << setfill(fillChar) << itemCode;
        cout << left << setw(columnWidth) << setfill(fillChar) << itemDescription;
        cout << left << setw(columnWidth) << setfill(fillChar) << itemPrice << endl;
        cout << "-------------------------------------------------------------------------------------------------------\n\n";
    }

    /* getter functions */
    string getItemName()
    {
        return itemName;
    }
    string getItemCode()
    {
        return itemCode;
    }
    string getItemDescription()
    {
        return itemDescription;
    }
    float getItemPrice()
    {
        return itemPrice;
    }
};

// Function to display the menu of computer components
void displayMenu(component Component[], int NoOfComponents)
{
    int columnWidth = 30;
    char fillChar = ' ';

    cout << "\n-----------------------------------------------------------------------------------------------------\n";
    cout << left << setw(columnWidth) << setfill(fillChar) << "Component";
    cout << left << setw(columnWidth) << setfill(fillChar) << "Item Code";
    cout << left << setw(columnWidth) << setfill(fillChar) << "Description";
    cout << left << setw(columnWidth) << setfill(fillChar) << "Item Price" << endl;
    cout << endl;

    for (int i = 0; i < NoOfComponents; i++)
    {
        // Print the data
        cout << left << setw(columnWidth) << setfill(fillChar) << Component[i].getItemName();
        cout << left << setw(columnWidth) << setfill(fillChar) << Component[i].getItemCode();
        cout << left << setw(columnWidth) << setfill(fillChar) << Component[i].getItemDescription();
        cout << left << setw(columnWidth) << setfill(fillChar) << Component[i].getItemPrice() << endl;
        cout << "-----------------------------------------------------------------------------------------------------\n"
             << endl;
    }
}

// Function to search for an item in the component list
int serachItem(component Component[], int originPoint, int MenuLimit, string itemCode)
{
    for (int i = originPoint; i < MenuLimit; i++)
    {
        if (Component[i].getItemCode() == itemCode)
        {
            return i;
        }
    }
    return -1;
}

// Function to display the bill
void generateBill(component selectedComponents[], int NoOfChosenElements, float totalAmount, int additionalItems)
{
    int columnWidth = 30;
    char fillChar = ' ';

    // Print the table header for the bill
    cout << "\n\n\t\t*************************** Bill ***************************\n"
         << endl;
    cout << left << setw(columnWidth) << setfill(fillChar) << "Component";
    cout << left << setw(columnWidth) << setfill(fillChar) << "Item Code";
    cout << left << setw(columnWidth) << setfill(fillChar) << "Description";
    cout << left << setw(columnWidth) << setfill(fillChar) << "Item Price" << endl;
    cout << "-----------------------------------------------------------------------------------------\n\n";
    // Print the selected components in the bill
    for (int i = 0; i < NoOfChosenElements; i++)
    {
        selectedComponents[i].displayDetail();
    }
    // Calculate discount based on the number of additional items
    float discount = 0.0;
    if (additionalItems == 1)
    {
        discount = totalAmount * 0.05; // 5% discount for one additional item
    }
    else if (additionalItems >= 2)
    {
        discount = totalAmount * 0.10; // 10% discount for two or more additional items
    }

    cout << "\n------------------------------------------------------------------\n"
         << endl;
    cout << left << setw(columnWidth) << setfill(fillChar) << "Total Amount:";
    cout << left << setw(columnWidth) << setfill(fillChar) << "";
    cout << left << setw(columnWidth) << setfill(fillChar) << totalAmount << "\n"
         << endl;
    cout << left << setw(columnWidth) << setfill(fillChar) << "Discount:";
    cout << left << setw(columnWidth) << setfill(fillChar) << "";
    cout << left << setw(columnWidth) << setfill(fillChar) << discount << "\n"
         << endl;
    // Calculate the new total amount after discount
    totalAmount -= discount;
    cout << left << setw(columnWidth) << setfill(fillChar) << "After Discount:";
    cout << left << setw(columnWidth) << setfill(fillChar) << "";
    cout << left << setw(columnWidth) << setfill(fillChar) << totalAmount << "\n"
         << endl;
    cout << "\n\n\t\t*************************************************************\n\n";
}

int main()
{
    int NoOfComponents = 17;             // Total number of components
    component Component[NoOfComponents]; // Array of all components of commputer

    component selectedComponents[NoOfComponents]; // Array that stores all the selected components
    int NoOfChosenElements = 0;                   // Total number of seleced components

    // Initializing the details of computer components
    Component[0].setItemName("Case");
    Component[0].setItemCode("A1");
    Component[0].setItemDescription("Compact");
    Component[0].setItemPrice(75.00);

    Component[1].setItemName("Case");
    Component[1].setItemCode("A2");
    Component[1].setItemDescription("Tower");
    Component[1].setItemPrice(150.00);

    Component[2].setItemName("RAM");
    Component[2].setItemCode("B1");
    Component[2].setItemDescription("8 GB");
    Component[2].setItemPrice(79.99);

    Component[3].setItemName("RAM");
    Component[3].setItemCode("B2");
    Component[3].setItemDescription("16 GB");
    Component[3].setItemPrice(149.99);

    Component[4].setItemName("RAM");
    Component[4].setItemCode("B3");
    Component[4].setItemDescription("32 GB");
    Component[4].setItemPrice(299.99);

    Component[5].setItemName("Main Hard Disk Drive");
    Component[5].setItemCode("C1");
    Component[5].setItemDescription("1 TB HDD");
    Component[5].setItemPrice(49.99);

    Component[6].setItemName("Main Hard Disk Drive");
    Component[6].setItemCode("C2");
    Component[6].setItemDescription("2 TB HDD");
    Component[6].setItemPrice(89.99);

    Component[7].setItemName("Main Hard Disk Drive");
    Component[7].setItemCode("C3");
    Component[7].setItemDescription("4 TB HDD");
    Component[7].setItemPrice(129.99);

    Component[8].setItemName("Solid State Drive");
    Component[8].setItemCode("D1");
    Component[8].setItemDescription("240 GB SSD");
    Component[8].setItemPrice(59.99);

    Component[9].setItemName("Solid State Drive");
    Component[9].setItemCode("D2");
    Component[9].setItemDescription("480 GB SSD");
    Component[9].setItemPrice(119.99);

    Component[10].setItemName("Second Hard Disk Drive");
    Component[10].setItemCode("E1");
    Component[10].setItemDescription("1 TB HDD");
    Component[10].setItemPrice(49.99);

    Component[11].setItemName("Second Hard Disk Drive");
    Component[11].setItemCode("E2");
    Component[11].setItemDescription("2 TB HDD");
    Component[11].setItemPrice(89.99);

    Component[12].setItemName("Second Hard Disk Drive");
    Component[12].setItemCode("E3");
    Component[12].setItemDescription("4 TB HDD");
    Component[12].setItemPrice(129.00);

    Component[13].setItemName("Optical Drive");
    Component[13].setItemCode("F1");
    Component[13].setItemDescription("DVD/Blu-Ray Player");
    Component[13].setItemPrice(50.00);

    Component[14].setItemName("Optical Drive");
    Component[14].setItemCode("F2");
    Component[14].setItemDescription("DVD/Blu-Ray Re-writer");
    Component[14].setItemPrice(100.00);

    Component[15].setItemName("Operating System");
    Component[15].setItemCode("G1");
    Component[15].setItemDescription("Standard Version");
    Component[15].setItemPrice(100.00);

    Component[16].setItemName("Operating System");
    Component[16].setItemCode("G2");
    Component[16].setItemDescription("Professional Version");
    Component[16].setItemPrice(175.00);
    char choice;
    do
    {
        int totalAmount = 0;
        cout << "\nAre you looking for a computer ? Type (Y/N) : ";
        cin >> choice;
        cout << endl;

        while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
        {
            cout << "\nPlease enter a valid input (Y/N) : ";
            cin >> choice;
            cout << endl;
        }
        if (choice == 'Y' || choice == 'y')
        {
            // Offering a basic set of components to the user
            cout << "\nComputer with a basic set of components costs $200. Would you like to buy it? (Y/N) : ";
            cin >> choice;

            while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
            {
                cout << "\nPlease enter a valid input (Y/N) : ";
                cin >> choice;
                cout << endl;
            }
            if (choice == 'Y' || choice == 'y')
            {
                totalAmount = totalAmount + 200;
                cout << "\nFrom the Menu please select Case for your computer : " << endl;
                displayMenu(Component, NoOfComponents);
                string itemCode;
                int indexNo = -1;
                do
                {
                    cout << "\nEnter the item-code of 'case' you want for your computer : ";
                    cin >> itemCode;
                    cout << endl;
                    indexNo = serachItem(Component, 0, 2, itemCode);
                    if (indexNo == -1)
                    {
                        cout << "\nPlease enter a valid item-code !" << endl;
                    }
                    else
                    {
                        cout << "\nComponent added in computer" << endl;
                        totalAmount += Component[indexNo].getItemPrice();
                        selectedComponents[NoOfChosenElements] = Component[indexNo];
                        NoOfChosenElements++;
                    }

                } while (indexNo == -1);

                do
                {
                    cout << "\nEnter the item-code of 'RAM' you want for your computer : ";
                    cin >> itemCode;
                    cout << endl;
                    indexNo = serachItem(Component, 2, 5, itemCode);
                    if (indexNo == -1)
                    {
                        cout << "\nPlease enter a valid item-code !" << endl;
                    }
                    else
                    {
                        cout << "\nComponent added in computer" << endl;
                        totalAmount += Component[indexNo].getItemPrice();
                        selectedComponents[NoOfChosenElements] = Component[indexNo];
                        NoOfChosenElements++;
                    }

                } while (indexNo == -1);

                do
                {
                    cout << "\nEnter the item-code of 'Hard Disk Drive' you want for your computer : ";
                    cin >> itemCode;
                    cout << endl;
                    indexNo = serachItem(Component, 5, 8, itemCode);
                    if (indexNo == -1)
                    {
                        cout << "\nPlease enter a valid item-code !" << endl;
                    }
                    else
                    {
                        cout << "\nComponent added in computer" << endl;
                        totalAmount += Component[indexNo].getItemPrice();
                        selectedComponents[NoOfChosenElements] = Component[indexNo];
                        NoOfChosenElements++;
                    }

                } while (indexNo == -1);
                system("cls");
                int additonalItem = 0;
                do
                {
                    // Ask the user if they want to buy additional components
                    cout << "\nDo you to buy other component for you computer ! Type(Y / N) : ";
                    cin >> choice;
                    while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
                    {
                        cout << "Please enter a valid input (Y/N): ";
                        cin >> choice;
                        cout << endl;
                    }
                    if (choice == 'Y' || choice == 'y')
                    {
                        displayMenu(Component, NoOfComponents);
                        int indexNo = -1;
                        do
                        {
                            string itemCode;
                            cout << "\nEnter the item-code you want for your computer : ";
                            cin >> itemCode;
                            indexNo = serachItem(Component, 0, NoOfComponents, itemCode);
                            if (indexNo == -1)
                            {
                                cout << "\nPlease enter a valid item-code !" << endl;
                            }
                            else
                            {
                                cout << "\nComponent added in computer" << endl;
                                totalAmount += Component[indexNo].getItemPrice();
                                selectedComponents[NoOfChosenElements] = Component[indexNo];
                                NoOfChosenElements++;
                                additonalItem++;
                            }
                        } while (indexNo == -1);
                    }
                    else if (choice == 'N' || choice == 'n')
                    {
                        cout << "As you wish !" << endl;
                    }
                } while (choice == 'Y' || choice == 'y');
                system("cls");
                // Generate and display the bill
                generateBill(selectedComponents, NoOfChosenElements, totalAmount, additonalItem);
            }
            else if (choice == 'N' || choice == 'n')
            {
                cout << "\nAs you wish, have a nice day!" << endl;
            }
        }
        else if (choice == 'N' || choice == 'n')
        {
            cout << "nAs you wish, have a nice day!" << endl;
        }
    } while (choice == 'Y' || choice == 'y');
    return 0;
}