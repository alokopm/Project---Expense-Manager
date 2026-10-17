
#include <iostream>
#include <limits>
#include "ExpenseManager.h"
#include "FileManager.h"
using namespace std;

int main() {
    ExpenseManager em;
    FileManager fm;

    fm.loadTransactions(em);

    int choice;

    while (true) {
        cout << "\n=== Expense Manager ===\n";
        cout << "1. Add transaction\n";
        cout << "2. View transactions\n";
        cout << "3. Delete transaction\n";
        cout << "4. Search transaction\n";
        cout << "5. Filter by category\n";
        cout << "6. Sort by amount\n";
        cout << "7. Financial summary\n";
        cout << "8. Category-wise expenses\n";
        cout << "9. Save and exit\n";
        cout << "Enter choice: ";

        cin >> choice;
        while(cin.fail()){
            cout << "Invalid input! Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter choice: ";
            cin >> choice;
        }
        switch (choice) {
            case 1:{
                // add the transaction
                int id;
                double amount;
                string date,type,category,description;
                cout<<"Id :";
                cin>>id;


                while (cin.fail() ||id<=0|| !em.checkDuplicate(id)) {
                    if (cin.fail()) {
                        cout << "Invalid input! Please enter a number.\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }else if(id<=0){
                        cout<<"Only positive values are allowed.\n";
                    } else {
                        cout << "This ID already exists. Please enter a unique ID.\n";
                    }
                    cout << "Id: ";
                    cin >> id;
                }
                cout<<"Date(format - dd/mm/yyyy) :";
                cin>>date;
                cout<<"Type :";
                cin>>type;
                while(type!= "expense"&&type != "income"){
                    cout<<"Only 'income' and 'expense' types are allowed\n";
                    cout<<"Type :";
                    cin>>type;
                }
                cout<<"Category :";
                cin>>category;
                cout<<"Amount :";
                cin>>amount;
                while(cin.fail()||amount<=0){
                    if(cin.fail()){
                        cout << "Invalid input! Please enter a number.\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }else{
                        cout<<"Please enter a positive amount!! \n";
                    }
                    cout<<"Amount :";
                    cin>>amount;
                }
                cout<<"Description :";
                cin.ignore();
                getline(cin,description);
                Transaction t(id,date,type,category,amount,description);
                em.addTransaction(t);
                cout<<"Transaction added successfully.\n";
                break;
            }
            case 2:{
                //view all transactions
                em.viewTransactions();
                break;
            }
            case 3:{
                //delete by id 
                cout<<"Please provide the Id of the Transaction, you want to delete :";
                int id;
                cin>>id;
                while (cin.fail() || id <= 0) {
                    cout << "Invalid ID! Enter a positive integer: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> id;
                }
                em.deleteTransaction(id);
                break;
            }
            case 4:{
                // search by the id
                int id;
                cout<<"Id :";
                cin>>id;
                while (cin.fail() || id <= 0) {
                    cout << "Invalid ID! Enter a positive integer: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> id;
                }
                em.searchTransaction(id);
                break;
            }
            case 5:{
                // filter by category
                string category;
                cout<<"Category :";
                cin>>category;
                em.filterByCategory(category);
                break;
            }
            case 6:{
                // transaction sort
                em.sortByAmount();
                cout << "Transactions sorted.\n";
                break;
            }
            case 7:{
                // Show financial summary
                cout<<"Total Income :";
                cout<<em.getTotalIncome()<<'\n';
                cout<<"Total Expense :";
                cout<<em.getTotalExpenses()<<'\n';
                cout<<"Balance :";
                cout<<em.getBalance()<<'\n';
                cout<<"Highest Expense :";
                cout<<em.getHighestExpense()<<'\n';
                break;
            }
            case 8:{
                //category-wise expenses
                map<string ,double> categoryExpense = em.getCategoryWiseExpenses();
                for(auto[s,n] : categoryExpense){
                    cout<<s<<' '<<':'<<n<<'\n';
                }
                break;
            }
            case 9:{
                fm.saveTransactions(em);
                cout << "Data saved. Goodbye!\n";
                return 0;
            }
            default:{
                cout << "Invalid choice. Try again.\n";
            }
        }
    }
}
