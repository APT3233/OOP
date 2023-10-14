
+---------------------------------+
|            Customer             |
+---------------------------------+
| - customerId: string            |
| - fullName: string              |
| - address: string               |
| - phoneNumber: string           |
+---------------------------------+
| + getCustomerId(): string       |
| + getFullName(): string         |
| + getAddress(): string          |
| + getPhoneNumber(): string      |
+---------------------------------+

         |
         |
         v

+---------------------------------+
|            Account              |
+---------------------------------+
| - accountId: string             |
| - accountType: string           |
| - balance: double               |
| - owner: Customer               |
+---------------------------------+
| + getAccountId(): string        |
| + getAccountType(): string      |
| + getBalance(): double          |
| + getOwner(): Customer          |
+---------------------------------+
         |
         |
         v

+---------------------------------+
|          BankService             |
+---------------------------------+
| - bankName: string              |
| - accounts: vector<Account*>    |
| - customers: vector<Customer*>  |
| - transactions: vector<Transaction*> |
+---------------------------------+         
| + addCustomer()                 |
| + removeCustomer()              |
| + findCustomer()                |
| + addAccount()                  |
| + removeAccount()               |
| + findAccount()                 |
| + deposit()                     |   Gửi tiền vào tài khoản 
| + withdraw()                    |   Rút tiền 
| + transfer()                    |   Chuyển khoản
+---------------------------------+
         |
         |
         v

+---------------------------------+
|          Transaction             |
+---------------------------------+
| - transactionId: string         |
| - transactionType: string       |
| - amount: double                |
| - transactionDate: string       |
| - accountFrom: Account*         |
| - accountTo: Account*           |
+---------------------------------+
| + getTransactionId(): string    |   Mã GD
| + getTransactionType(): string  |   Kiểu GD
| + getAmount(): double           |   Số tiền liên quan đến giao dịch
| + getTransactionDate(): string  |   Ngày 
| + getAccountFrom(): Account*    |   Trả về tk nguồn (ID)
| + getAccountTo(): Account*      |   Trả về tk đích (ID)
| + getALL()                      |
+---------------------------------+
