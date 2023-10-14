#include <string>
#include <vector>
using namespace std;

class Account;
class BankService;
class Customer
{
public:
    void setCustomerID();
    string getCustomerID();
    void setName();
    string getName();
    void setAge();
    int getAge();
    void setAddress();
    string getAddress();
    void setPhoneNumber();
    int getPhoneNumber();
    void setSex();
    bool getSex();
    void getAllInf();
    vector<Account*> getAccounts() const;
private:
    string m_strCustomerID;
    string m_strName;
    int m_inAge;
    string m_strAddress;
    int m_inPhoneNumber;
    bool sex;    
    vector<Account*> Account_list;
};

class Account : public Customer
{
public:
    void setAccountID();
    string getAccountID();
    void setAccountType();
    string getAccountType();
    void setOwner(Customer* customer);
    Customer getOwner();
    double getBlance();
    void setBlance();
    bool isOwner(const Customer* customer) const;

    void deposit(double amount);
    bool canTransfer(double amount) const;
    void transfer(BankService* bankService, 
                    const string& targetAccountID, double amount);
private:
    string m_strAccountID;
    string m_strAccountType;
    const Customer* owner;
    double m_doBlance;
};

class Transaction
{
public:
    string getTransactionId();
    string getTransactionType();
    double getAmount();
    string getTransactionDate();
    Account* getAccountForm();
    Account* getAccountTo();
    void getALL();

private:
    string m_strTransactionID;
    string m_strTransactionType;
    double m_douAmount;
    string m_strTransactionDate;
    Account* m_AccountForm;
    Account* m_AccountTO;
};

class BankService
{
public:
    static BankService* getManager();
    void addCustomer();
    void removeCustomer();
    void findCustomer();
    void addAccount();
    void removeAccount();
    void findAccount();
    void Deposit();
    void Withdraw();
    //void DisplayAllInf();
    
    const vector<Account*>& getAccountList() const;
private:
    string m_strBankName;
    vector<Account*> Account_list;
    vector<Customer*> Customer_list;
    vector<Transaction*> Transaction_list;
    static BankService* manager;
    BankService() {}
};

class APP_Bank
{
public:
    void AppBank();
private:
    BankService* app;
};

