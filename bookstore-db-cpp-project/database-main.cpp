 
#include "database.h"

int main(void)
{
    MySQL Mysql;
	//Mysql.ShowTables();
    
	int select = 99;

	cout << "\n Welcome to our BookStore." << endl;
	cout << "\n\n Please select one of the following queries: \n\n"
		<< "1  ---> |Check if book Harry Potter is in stock. " << endl
		<< "2  ---> |Who is our oldest customer." << endl
		<< "3  ---> |Which is our oldest book." << endl
		<< "4  ---> |List of orders by date." << endl
		<< "5  ---> |How much Harry potter books we have sold." << endl
		<< "6  ---> |Who is our most selled writer" << endl
		<< "7  ---> |List of the 3 costumers who bought the biggest quantity of books." << endl
		<< "8  ---> |Which writer is the most translated in stock." << endl
		<< "9  ---> |Purchase history of customer Timor Safadi" << endl
		<< "10 ---> |????" << endl
		<< "11 ---> |Calculate price of delivery." << endl
		<< "12 ---> |???" << endl
		<< "13 ---> |Status of delivery id : 3" << endl
		<< "14 ---> |What is the total cost of deliveries done by Xpress " << endl
		<< "15 ---> |Sum of money transfered to store by Bit app." << endl
		<< "16 ---> |List of orders which made more profit than average in the past year." << endl
		<< "17 ---> |How much delievers were done by IsraelPost and Xpress in the past year." << endl
		<< "18 ---> |Delivery info of orders which contained at least two editions of the same book." << endl
		<< "19 ---> |List of all the costumers with at least one order which didnt make any orders in the past 2 years." << endl
		<< "20 ---> |Books in inventory" << endl
		<< "21 ---> |Number of diffrent books we have in stock." << endl
		<< "22 ---> |How many books have the store baught between the dates DD/MM/YYYY and DD/MM/YYYY and how much did it pay for them.." << endl
		<< "23 ---> |Sale Yearly" << endl
		<< "24 ---> |The salary of employee Jhonny Week in may" << endl
		<< "25 ---> |Best Sales Man" << endl
		<< "26 ---> |Quit" << endl;

	while (select != 27) {

		// DB interaction options 


		cout << "\nplease enter your selection : ";
		cin >> select;


		switch (select) {

		case 1: {
			cin.clear();
			Mysql.findSpecificBook();
			cin.ignore(10000, '\n');
			break;
		}

		case 2: {
			cin.clear();
			Mysql.oldestCostumer();
			cin.ignore(10000, '\n');
			break;
		}

		case 3: {
			cin.clear();
			Mysql.oldestBookInStok();
			cin.ignore(10000, '\n');
			break;
		}

		case 4: {
			cin.clear();
			Mysql.currOrderList();
			cin.ignore(10000, '\n');
			break;
		}

		case 5: {
			cin.clear();
			Mysql.soldCountOfBook();
			cin.ignore(10000, '\n');
			break;
		}

		case 6: {
			cin.clear();
			Mysql.mostReadWriter();
			cin.ignore(10000, '\n');
			break;
		}

		case 7: {
			cin.clear();
			Mysql.best3Costumers();
			cin.ignore(10000, '\n');
			break;
		}

		case 8: {
			cin.clear();
			Mysql.mostTranslatedWriter();
			cin.ignore(10000, '\n');
			break;
		}

		case 9: {
			cin.clear();
			Mysql.costumerPurchaseHistory();
			cin.ignore(10000, '\n');
			break;
		}

		case 10: {
			cin.clear();
			break;
		}

		case 11: {
			cin.clear();
			Mysql.calculateCostOfShipment();
			cin.ignore(1000, '\n');
			break;
		}
		case 12: {
			cin.clear();
			break;
		}

		case 13: {
			cin.clear();
			Mysql.deliveryStatus();
			cin.ignore(10000, '\n');
			break;
		}

		case 14: {
			cin.clear();
			Mysql.sumOfDeliveryCostByExpress();
			cin.ignore(10000, '\n');
			break;
		}

		case 15: {
			cin.clear();
			Mysql.sumBitTransactions();
			cin.ignore(10000, '\n');
			break;
		}
		case 16: {
			cin.clear();
			Mysql.mostProfitableOrders();
			cin.ignore(10000, '\n');
			break;
		}
		case 17: {
			cin.clear();
			Mysql.amountOfDeliveriesByVendor();
			cin.ignore(10000, '\n');
			break;
		}

		case 18: {
			cin.clear();
			Mysql.numOfBooksTwoVersions();
			cin.ignore(10000, '\n');
			break;
		}

		case 19: {
			cin.clear();
			Mysql.numOfBooksTwoVersions();
			cin.ignore(10000, '\n');
			break;
		}

		case 20: {
			cin.clear();
			Mysql.numOfBooksTwoVersions();
			cin.ignore(10000, '\n');
			break;
		}

		case 21: {
			cin.clear();
			Mysql.amountOfBooksInStock();
			cin.ignore(10000, '\n');
			break;
		}
		case 22: {
			cin.clear();
			Mysql.numOfBooksTwoVersions();
			cin.ignore(10000, '\n');
			break;
		}

		case 23: {
			cin.clear();
			Mysql.yearlySale();
			cin.ignore(10000, '\n');
			break;
		}

		case 24: {
			cin.clear();
			Mysql.workerSalary();
			cin.ignore(10000, '\n');
			break;
		}

		case 25: {
			cin.clear();
			Mysql.bestSalesMan();
			cin.ignore(10000, '\n');
			break;
		}
		case 26: {

			cout << "Bye!" << endl;
			exit(0);
		}

		default: {
			cout << "\ninvalid choice" << endl;
			select = 42;
			cin.clear();
			cin.ignore(10000, '\n');
			break;
		}

		}

	}
    return 0;
}
