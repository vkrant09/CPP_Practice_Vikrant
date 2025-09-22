#include <iostream>
#include <string>

class Invoice {
private:
    std::string partNumber;
    std::string partDescription;
    int quantity;
    int pricePerItem;

public:
    // constructor with validation
    Invoice(const std::string& pNum, const std::string& pDesc, int qty, int price) {
        partNumber = pNum;
        partDescription = pDesc;
        quantity = (qty > 0) ? qty : 0;
        pricePerItem = (price > 0) ? price : 0;
    }

    // setters
    void setPartNumber(const std::string& pNum) { partNumber = pNum; }
    void setPartDescription(const std::string& pDesc) { partDescription = pDesc; }
    void setQuantity(int qty) { quantity = (qty > 0) ? qty : 0; }
    void setPricePerItem(int price) { pricePerItem = (price > 0) ? price : 0; }

    // getters
    std::string getPartNumber() const { return partNumber; }
    std::string getPartDescription() const { return partDescription; }
    int getQuantity() const { return quantity; }
    int getPricePerItem() const { return pricePerItem; }

    // calculate invoice amount
    int getInvoiceAmount() const {
        return quantity * pricePerItem;
    }
};

int main() {
    // create 2 invoice objects
    Invoice inv1("A101", "Hammer", 5, 20);
    Invoice inv2("B202", "Screwdriver", -3, 15); // invalid qty -> set to 0

    // show invoice amounts
    std::cout << "Invoice 1: " << inv1.getPartNumber()
              << " " << inv1.getPartDescription()
              << " | Qty: " << inv1.getQuantity()
              << " | Price: " << inv1.getPricePerItem()
              << " | Total: " << inv1.getInvoiceAmount() << "\n";

    std::cout << "Invoice 2: " << inv2.getPartNumber()
              << " " << inv2.getPartDescription()
              << " | Qty: " << inv2.getQuantity()
              << " | Price: " << inv2.getPricePerItem()
              << " | Total: " << inv2.getInvoiceAmount() << "\n";

    // update invoice 2 properly
    inv2.setQuantity(10);
    inv2.setPricePerItem(5);
    std::cout << "Invoice 2 updated total: " << inv2.getInvoiceAmount() << "\n";

    return 0;
}
