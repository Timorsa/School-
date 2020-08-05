

#include "header.h"
#include "database-detail.h"



class MySQL
{
    protected:
        /** MySQL connectivity Variables */
        MYSQL *connect;
        MYSQL_RES *res_set;
        MYSQL_ROW row;

        unsigned int i;

    public:
        /** MySQL Constructor */
        MySQL();

        /** Function to show tables in database */
        void ShowTables();

		// option 1
		void findSpecificBook();
		// option 2
		void oldestCostumer();
		// option 3
		void oldestBookInStok();
		// option 4
		void currOrderList();
		// option 5
		void soldCountOfBook();
		// option 6
		void mostReadWriter();
		// option 7
		void mostTranslatedWriter();
		// option 7
		void best3Costumers();
		// option 8
		void mostTranslatedBook();
		// option 9
		void costumerPurchaseHistory();
		// option 10
		// need to check how to call it
		// option 11
		void calculateCostOfShipment();
		// option 12
		void costumerSplitOrders();
		// option 13
		void deliveryStatus();
		// option 14
		void sumOfDeliveryCostByExpress();
		// option 15
		void sumBitTransactions();
		// option 16
		void mostProfitableOrders();
		// option 17
		void amountOfDeliveriesByVendor();
		// option 18
		void numOfBooksTwoVersions();
		// option 19
		void notBuyingCustomers();
		// option 20
		void booksInInventory();
		// option 21
		void amountOfBooksInStock();
		// option 22
		void noBookTake();
		// option 23
		void yearlySale();
		// option 24
		void workerSalary();
		// option 25
		void bestSalesMan();

        /** MySQL Destructor */
        ~MySQL();
};
