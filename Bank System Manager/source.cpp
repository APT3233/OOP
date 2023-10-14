#include <iostream>
#include <string>
#include <vector>
#include "head.h"
using namespace std;

//Customer
void Customer::setCustomerID()
{
    cout << "Enter ID: ";
    getline(cin >> ws, m_strCustomerID);
}
string Customer::getCustomerID()
{
    return m_strCustomerID;
}
void Customer::setName()
{
    cout << "Enter FullName: ";
    getline(cin >> ws, m_strName);
}
string Customer::getName()
{
    return m_strName;
}
void Customer::setAge()
{
    cout << "Age: ";
    cin >> m_inAge;
}
int Customer::getAge()
{
    return m_inAge;
}
void Customer::setAddress()
{
    cout << "Address: ";
    getline(cin >> ws, m_strAddress);
}
string Customer::getAddress()
{
    return m_strAddress;
}
void Customer::setPhoneNumber()
{
    cout << "PhoneNumber: ";
    cin>> m_inPhoneNumber;
}
void Customer::setSex()
{
    cout<< "Sex Male(0) | Female(1): ";
    cin >> sex;
}
bool Customer::getSex()
{
    return sex;
}
void Customer::getAllInf()
{
    cout << "Customer ID: " << m_strCustomerID << endl;
    cout << "Name: " << m_strName << endl;
    cout << "Age: " << m_inAge << endl;
    cout << "Address: " << m_strAddress << endl;
    cout << "PhoneNumber: "  << m_inPhoneNumber << endl;
    if(sex == 1) {cout << "Sex: Male\n";}
    else {cout << "Sex: Female\n";}
}

/*1. Trong mỗi vòng lặp, chúng ta kiểm tra xem account (tài khoản hiện tại đang 
       được xem xét) có thuộc về khách hàng đang xét không, bằng cách gọi hàm isOwner(this) 
       trên tài khoản.
  2. Hàm isOwner(const Customer* customer) được triển khai trong lớp Account để kiểm tra xem một 
      khách hàng có phải là chủ sở hữu của tài khoản hay không. Nếu account thuộc sở hữu của khách hàng 
      (nghĩa là account->isOwner(this) trả về true), thì tài khoản này được thêm vào danh sách customerAccounts.*/
vector<Account*> Customer::getAccounts() const  
{
    std::vector<Account*> customerAccounts;  //lưu trữ tk khách hàng sỡ hữu

    for (Account* account : Account_list) 
    {
        if (account->isOwner(this)) 
        {
            customerAccounts.push_back(account);
        }
    }
    return customerAccounts;
}
bool Account::isOwner(const Customer* customer) const 
{
    return (owner == customer);
}


//ACCOUNT
void Account::setAccountID()
{   
    cout << "Enter Number Card: "; getline(cin >> ws, m_strAccountID);
}
string Account::getAccountID()
{
    return m_strAccountID;
}
void Account::setAccountType()
{
    cout << "Saving | Personal Account | Fixed Account\n" << endl;
    cout << "Enter: "; getline(cin >>ws, m_strAccountType);
}
string Account::getAccountType()
{
    return m_strAccountType;
}
void Account::setOwner(Customer* customer)
{
    owner = customer;
}
void Account::setBlance()
{
    m_doBlance = 0.0;
}


//BankService
BankService* BankService::getManager()
{
    if(manager == NULL)
    {
        manager = new BankService();
    }
    return manager;
}

void Account::deposit(double amount)
{
    if(amount > 0  && amount <= 500000000)
    {
        m_doBlance += amount;
    } else
    {
        cout << "Invalid amount for deposit.\n";
    }
}

//Check số dư để đủ đ/k chuyển tiền ko
bool Account::canTransfer(double amount) const
{
    return amount > 0 && amount <= m_doBlance;
}

// Trong hàm Account::transfer
void Account::transfer(BankService* bankService, const string& targetAccountID, double amount)
{
    // Thay vì truy cập trực tiếp vào biến thành viên private Account_list của BankService,
    // bạn sẽ sử dụng phương thức getAccountList() để truy cập danh sách tài khoản.
    const vector<Account*>& accountList = bankService->getAccountList();

    for (Account* account : accountList)
    {
        if (account->getAccountID() == targetAccountID)
        {
            targetAccountID = account;
            break;
        }
    }
    
    if (targetAccountID == nullptr)
    {
        cout << "Target account not found." << endl;
        return;
    }

    if (canTransfer(amount))
    {
        m_doBlance -= amount;
        targetAccountID->m_doBlance += amount;
        cout << "Transfer of " << amount << " successfully made. New balance: " << getBlance() << endl;
    }
    else
    {
        cout << "Invalid amount for transfer." << endl;
    }

}


void BankService::addCustomer()
{
    Customer* any = new Customer(); 
    cout << "How many customer do you want to ADD ?\n";
    cout << "Enter: ";
    int add; cin >> add;
    for(int i = 0; i < add; i++)
    {
        cout << "Customer " << i + 1 << "\n";
        any ->setCustomerID();
        any->setName();
        any->setAge();
        any->setAddress();
        any->setPhoneNumber();
        any->setSex();
        cout << "ADD 1 CUSTOMER SUCCESSFUL!\n";
        cout << "------------\n";
    }
    Customer_list.push_back(any);
}
void BankService::removeCustomer()
{
    bool found = false;
    cout << "Do you want to REMOVE CUSTOMER [yes(1) | no(0)]\n";
    cout << "Enter: "; int sel_remo; cin>>sel_remo; string id;
    if(sel_remo == 1)
    {
        for (auto del = Customer_list.begin(); del != Customer_list.end(); del++)
        {
            cout << "Enter Customer ID: "; getline(cin >> ws, id);
            if((*del)->getCustomerID() == id)
            {
                found = true;
                break;
            }
        }
        if(found)
        {
            for (auto del = Customer_list.begin(); del != Customer_list.end(); del++)
            {
                if ((*del)->getCustomerID() == id)
                {
                    delete *del; 
                    Customer_list.erase(del);
                    cout << "Removed Successful !" << endl;
                    break;
                }
            }
        }
        else
        {
             cout << "Customer with ID " << id << " not found." << endl;
        }
    }
}
void BankService::findCustomer()
{   
    string id; 
    cout << "Enter ID to find Customer: "; getline(cin >> ws, id);
    bool find = false;
    for(auto finds = Customer_list.begin(); finds != Customer_list.end(); finds++)
    {
        if((*finds)->getCustomerID() == id)
        {
            find = true;
            break;
        }
    }
    if(find)
    {
        cout << "Finded 1 result----->\n";
        for (auto finds = Customer_list.begin(); finds != Customer_list.end(); finds++)
        {
            if((*finds)->getCustomerID() == id)
            {
                //(*finds)->getCustomerID();
                (*finds)->getAllInf();
                cout << "\n";
            }
        }
    }
    else
    {
        cout << "NOT FOUND ! Please try again !\n";
    }
}
void BankService::addAccount()
{
    cout << "Choose a customer to add an account:\n";

    for (int i = 0; i < Customer_list.size(); i++)
    {
        cout << i + 1 << ". Customer ID: " << Customer_list[i]->Customer::getCustomerID()
             << ", Name: " << Customer_list[i]->Customer::getName() << endl;
    }

    int selectedCustomerIndex;
    cout << "Enter the number corresponding to the customer: ";
    cin >> selectedCustomerIndex;

    // Validate selectedCustomerIndex
    if (selectedCustomerIndex < 1 || selectedCustomerIndex > Customer_list.size())
    {
        cout << "Invalid selection." << endl;
        return;
    }

    Customer *selectedCustomer = Customer_list[selectedCustomerIndex - 1];

    Account *newAccount = new Account();

    // Set properties for the new account
    newAccount->setAccountID(); // You can implement your logic to generate account IDs
    newAccount->setAccountType(); // Set the account type
    newAccount->setOwner(selectedCustomer); // Assign the owner to the selected customer
    newAccount->setBlance(); // Initialize balance to 0

    // Add the new account to the accounts list
    Account_list.push_back(newAccount);

    cout << "Account added successfully!" << endl;
}
void BankService::removeAccount()
{   
    // Display Customer
    cout << "Choose a customer to delete ac account: \n";
    for(int i = 0; i < Customer_list.size(); i++)
    {
        cout << i+ 1 << ". Customer ID: " << Customer_list[i]->Customer::getCustomerID()
             << " , Name: " << Customer_list[i]->Customer::getName() << endl;
    }
    int selectedCustomerIndex;
    cout << "Enter the number corresponding to the customer: ";
    cin >> selectedCustomerIndex;
    
    // Check chỉ số khách hàng hợp lệ 
    if(selectedCustomerIndex < 1 || selectedCustomerIndex > Customer_list.size())
    {
        cout << "Invalid selection.\n";
        return;
    }
    // Tạo 1 con trỏ tới Customer dc c họn để tiếp tục công vc
    Customer* selectCustomer = Customer_list[selectedCustomerIndex - 1];
    
    // Lấy danh sách tk của khách đc chọn
    vector<Account*> accounts = selectCustomer->getAccounts();

    // Check xem Customer có acc ko 
    if (accounts.empty())
    {
        cout << "This customer doesn't have any accounts to remove. \n" << endl;
        return;
    }

    // Hiển thị danh sách tài khoản của khách hàng
    cout << " Account List of Customer:" << selectCustomer->getName() << ":" << endl;
    for (int i = 0; i < accounts.size(); i++)
    {
        cout << i + 1 << ". Account ID: " << accounts[i]->Account::getAccountID()
             << ", Account Type: " << accounts[i]->Account::getAccountType() << endl;
    }
    
    cout << "Choose an account to remove: \n";

    //Nhập acc muốn xóa 
    int selectedAccountIndex;
    cout << "Enter the number corresponding to the account: ";
    cin >> selectedAccountIndex;
    
    //Check nhập
    if (selectedAccountIndex < 1 || selectedAccountIndex > Account_list.size())
    {
        cout << "Invalid selection." << endl;
        return;
    }

    /*1. Tạo 1 con trỏ tới tk dc chọn để thực hiện các thao tác xóa 
      2. selectedAccountIndex - 1 được sử dụng để chuyển đổi chỉ số 
            do người dùng nhập vào(bắt đầu từ 1) thành chỉ số thích hợp 
            trong mảng Account_list (bắt đầu từ 0)                    */ 


    Account* selectAccount = accounts[selectedAccountIndex - 1];

    // Remove
    for(auto it = Account_list.begin(); it != Account_list.end(); it++)
    {
        if(*it == selectAccount)
        {
            delete *it;
            Account_list.erase(it);
            cout << " Remove Successfully ! \n";
            break;
        }
    }
}
void BankService::findAccount()
{
    string id;
    cout << "Enter Account ID to find: "; getline(cin >> ws, id);
    bool found = false;

    for (Account* account : Account_list)
    {
        if(account->Account::getAccountID() == id)
        {
            found = true;
            (account)->Customer::getAllInf();
            cout << "\n";
            break;
        }
    }
    if(!found)
    {
        cout << "Account with ID " << id << " not found. \n";
    }
}
void BankService::Deposit()
{
    cout << "\n<--------------DEPOSIT---------------->\n";
    
    //Chọn Customer
    cout << "Choose Customer to deposit\n";
    int index = 1;
    for (Customer *customer : Customer_list)
    {
        cout << index << ". " << customer->getName() <<endl;
        index++;
    }

    // Chọn tk
    int selectedCustomerIndex;
    cout << "Enter the number corresponding to the Customer.\n";
    cout << "Enter: "; cin >> selectedCustomerIndex;

    //
    if (selectedCustomerIndex >= 1 && selectedCustomerIndex <= Customer_list.size())
    {
        Customer* selectedCustomer = Customer_list[selectedCustomerIndex - 1]; //lấy khách hàng ở trong list -1 vì nhập vào bắt đầu từ 1 còn trong mảng là 0
                                                                                 // Ex: Customer* 2 = Customer_list[1];
        //lấy danh sách các tài khoản của khách hàng mà người dùng đã chọn                                                                       
        vector<Account*> accounts = selectedCustomer->getAccounts();

        // Hiện thị  
        cout << "Account List: \n";
        for (int i = 0; i < accounts.size(); i++)
        {
            cout << i + 1 << "Account ID: " << accounts[i]->getAccountID() << endl;
        }

        // Chọn tk để chuyển tiền
        int selectedAccountIndex;
        cout << "Enter the number corresponding to the account: ";
        cin >> selectedAccountIndex;

        // Nếu t/m thì bắt đầu chuyển tiền 
        if(selectedAccountIndex >= 1 && selectedAccountIndex <= accounts.size())
        { 
            //Trỏ đến tk muốn chuyển
            Account* selectedAccount = accounts[selectedAccountIndex - 1];

            double amount; string targetAccountID;
            cout << "Enter the amount to deposit: ";    cin >> amount;
            cout << "Enter the target account: "; getline(cin >> ws, targetAccountID);
            selectedAccount->deposit(amount);
            selectedAccount->canTransfer(amount);
            selectedAccount->transfer(this, targetAccountID, amount);
            cout << "(_____________Deposit Successful !_______________)\n";
        }
        else
        {
            cout << "Invalid account selection.\n";
        }

    }
    else
    {
        cout << "Invalid customer selection.\n";
        return;
    }
}
BankService* BankService::manager = NULL;

// Trong hàm BankService::getAccountList
const vector<Account*>& BankService::getAccountList() const
{
    return Account_list;
}


// App Bank
void APP_Bank::AppBank()
{
    while (true) {
        cout << "1. Add Customer\n";
        cout << "2. Remove Customer\n";
        cout << "3. Find Customer\n";
        cout << "4. Add Account\n";
        cout << "5. Remove Account\n";
        cout << "6. Find Account\n";
        cout << "7. Deposit\n";
        cout << "8. Withdraw\n";
        cout << "0. Display Information\n";
        cout << "99. Exit\n";
        int choice;
        cout << "ENTER(1, 2, 3, ..., 8, 0 or 99): ";
        cin >> choice;

        if (choice == 1) {
            cout << "-------------ME N U--------------\n";
            app->BankService::getManager()->addCustomer();
        }
        else if (choice == 2) {
            app->BankService::getManager()->removeCustomer();
        }
        else if (choice == 3) {
            app->BankService::getManager()->findCustomer();
        }
        else if (choice == 4){
            app->BankService::getManager()->addAccount();
        }
        else if (choice == 5) {
            app->BankService::getManager()->removeAccount();
        }
        else if (choice == 6) {
            app->BankService::getManager()->findAccount();        }
        else if (choice == 7) {
            app->BankService::getManager()->Deposit();     
        }
        else if (choice == 8) {
            app->BankService::getManager()->Withdraw();     
        }
        else if (choice == 0) {
            //app->BankService::getManager()->DisplayAllInf();
        }
        else if (choice == 99) {
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}
