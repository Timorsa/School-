

#include "database.h"



MySQL :: MySQL()
{
    connect = mysql_init(NULL);
    if ( !connect )
    {
        cout << "MySQL Initialization Failed";
    }   

    connect = mysql_real_connect(connect, SERVER, USER, PASSWORD, DATABASE, 0,NULL,0);
    
    if ( connect )
    {
        cout << "Connection Succeeded\n";
    }
    
    else
    {
        cout << "Connection Failed\n";
    }
}


void MySQL :: ShowTables()
{
    /** Add MySQL Query */
    mysql_query (connect,"show tables");                              
                                                                          
    i = 0;
                                                                         
    res_set = mysql_store_result(connect);                              
                                                                          
    unsigned int numrows = mysql_num_rows(res_set);                   
                                                                          
    cout << " Tables in " << DATABASE << " database " << endl;        
                                                                         
    while (((row=mysql_fetch_row(res_set)) != NULL))
    {                                                                 
        cout << row[i] << endl;                                       
    }
}


// Option 1
void MySQL::findSpecificBook()
{
   mysql_query(connect, "SELECT  stock FROM `bookstore-project-db`.books inner join `bookstore-project-db`.inventory where `bookstore-project-db`.books.inventory_id = `bookstore-project-db`.inventory.id and `bookstore-project-db`.books.title = 'Harry Potter' ");
   res_set = mysql_store_result(connect);

   cout << "Harry Potter Stock Status  :";

   while (((row = mysql_fetch_row(res_set)) != NULL))
   {
       if (*row[0] == '1')
          cout << "in stock" << endl;
       else cout << "not in stock" << endl;
   }

}

// Option 2
void MySQL::oldestCostumer()
{
    mysql_query(connect, "SELECT fist_name, last_name  FROM `bookstore-project-db`.customers ORDER BY created_at ASC LIMIT 1"); 
    res_set = mysql_store_result(connect);

    cout << "The Oldest Costumer In Our Store is  :" << endl;
    
    while (((row = mysql_fetch_row(res_set)) != NULL))
    {
        cout << "Full Name : " << row[0] << "  " <<row[1] <<  endl;
    }
    

}
// option 3
void MySQL::oldestBookInStok() {
    mysql_query(connect, "SELECT title, date FROM `bookstore-project-db`.books inner join `bookstore-project-db`.inventory where `bookstore-project-db`.books.inventory_id = `bookstore-project-db`.inventory.id and `bookstore-project-db`.inventory.stock = 1 ORDER BY `bookstore-project-db`.inventory.date ASC LIMIT 1 ");
    res_set = mysql_store_result(connect);

    while (((row = mysql_fetch_row(res_set)) != NULL))
    {
        cout << "The Oldest Book is  : " << row[0] << "  and it is in stock since : " << row[1] << endl;
    }
}
// option 4
// number of rows 
void MySQL::currOrderList() {
    
    mysql_query(connect, "SELECT orders_id,order_type,  status, date  FROM `bookstore-project-db`.delivery inner join `bookstore-project-db`.orders  where `bookstore-project-db`.delivery.orders_id = `bookstore-project-db`.orders.id and `bookstore-project-db`.delivery.status != 'delivered'  ORDER BY `bookstore-project-db`.orders.date ASC  ");
    res_set = mysql_store_result(connect);

    cout << "Orders Left To be Delieverd" << endl;
    unsigned int numrows = mysql_num_rows(res_set);

    
    while (((row = mysql_fetch_row(res_set)) != NULL))
    {
        cout << "The Order : " << row[0] << "  Order Type : " << row[1] << " is Status : " <<row[2] << " created at : " << row[3] << endl;
    }
}
// option 5
void MySQL::soldCountOfBook() {
   ;
    mysql_query(connect, " SELECT COUNT(*) FROM `bookstore-project-db`.orders_has_books inner join `bookstore-project-db`.books  where `bookstore-project-db`.orders_has_books.book_id = `bookstore-project-db`.books.id and `bookstore-project-db`.books.title = 'Harry Potter'");
    res_set = mysql_store_result(connect);

    while (((row = mysql_fetch_row(res_set)) != NULL))
    {
        cout << "The Book Harry Potter Have Been Sold  : " << row[0]  << " Times ." << endl;
    }

}
// option 6
void MySQL::mostReadWriter() {

    mysql_query(connect, " SELECT  name, COUNT(*) AS magnitude  FROM `bookstore-project-db`.writers_has_books inner join `bookstore-project-db`.writers  where `bookstore-project-db`.writers_has_books.writer_id = `bookstore-project-db`.writers.id ORDER BY magnitude DESC LIMIT 1");
     res_set = mysql_store_result(connect);

    while (((row = mysql_fetch_row(res_set)) != NULL))
    {
        cout << "The Most Readed Writer : " << row[0] << endl;
    }
}


// option 7
void MySQL::best3Costumers() {
    mysql_query(connect, "SELECT  fist_name, last_name, COUNT(customer_id)  as orderNumber FROM `bookstore-project-db`.customers_has_order inner join `bookstore-project-db`.customers where `bookstore-project-db`.customers_has_order.customer_id = `bookstore-project-db`.customers.id  group by customer_id order by orderNumber desc limit 3");

    res_set = mysql_store_result(connect);

    unsigned int numrows = mysql_num_rows(res_set);

    
    cout << "Our 3 best customers are" << endl;

    while (((row = mysql_fetch_row(res_set)) != NULL))
    {
        cout << row[0] << row[1] << endl;
    }

}


// option 8
void MySQL::mostTranslatedWriter() {

    mysql_query(connect, " SELECT  name, COUNT(*) AS magnitude  FROM `bookstore-project-db`.writers_has_books inner join `bookstore-project-db`.writers  where `bookstore-project-db`.writers_has_books.writer_id = `bookstore-project-db`.writers.id ORDER BY magnitude DESC LIMIT 1");
    res_set = mysql_store_result(connect);

    while (((row = mysql_fetch_row(res_set)) != NULL))
    {
        cout << "The Most Translated Writer : " << row[0] << endl;
    }
}
// option 9
void MySQL::costumerPurchaseHistory() {
    mysql_query(connect, "SELECT title, date FROM  `bookstore-project-db`.customers_has_order inner join `bookstore-project-db`.orders inner join `bookstore-project-db`.orders_has_books inner join `bookstore-project-db`.books where `bookstore-project-db`.customers_has_order.customer_id = 1 and `bookstore-project-db`.orders.id = `bookstore-project-db`.orders_has_books.order_id group by `bookstore-project-db`.orders_has_books.book_id");
    res_set = mysql_store_result(connect);

    unsigned int numrows = mysql_num_rows(res_set);


    cout << "Purchase History of Timor Safadi  : " << endl;

    while (((row = mysql_fetch_row(res_set)) != NULL))
    {
        cout <<"Purchased Book : " <<  row[0] << "at Date : " << row[1] << endl;
    }
}
// option 10
// need to check how to call it
// option 11
void MySQL::calculateCostOfShipment() {
    mysql_query(connect, "SELECT SUM(weight) FROM `bookstore-project-db`.books where `bookstore-project-db`.books.id = 1 or `bookstore-project-db`.books.id = 2 or `bookstore-project-db`.books.id = 3");
    res_set = mysql_store_result(connect);



    while (((row = mysql_fetch_row(res_set)) != NULL))
    {
        cout << "Total Weight of Delivery :  " << row[0] << "  Kg" << endl;

        cout << "Cost of Delivery  if fulfilled by express:     " << 2.100000023841858 * 24 << "$" << endl;
        cout << "Cost of Delivery  if fulfilled by Il - POST:   " << 2.100000023841858 * 15 << "$" << endl;
    }
}
// option 12
void MySQL::costumerSplitOrders() {

}
// option 13
void MySQL::deliveryStatus() {
    mysql_query(connect, "SELECT status FROM `bookstore-project-db`.delivery where id = 3");
    res_set = mysql_store_result(connect);

    cout << "The Status of Delivery #3 is : " << endl;

    while (((row = mysql_fetch_row(res_set)) != NULL))
    {
        cout << row[0] << endl;
    }
}
// option 14
void MySQL::sumOfDeliveryCostByExpress() {
    mysql_query(connect, "SELECT sum(cost) FROM `bookstore-project-db`.delivery where vendor='express'");
    res_set = mysql_store_result(connect);

    cout << "Amount of money we payd express  : " << endl;

    while (((row = mysql_fetch_row(res_set)) != NULL))
    {
        cout << row[0] << endl;
    }
}
// option 15
void MySQL::sumBitTransactions() {
    mysql_query(connect, "SELECT sum(cost) FROM `bookstore-project-db`.orders where payment='bit'");
    res_set = mysql_store_result(connect);

    cout << "Amount of money we got throught BIT  : " << endl;

    while (((row = mysql_fetch_row(res_set)) != NULL))
    {
        cout << row[0] << endl;
    }
}
// option 16
void MySQL::mostProfitableOrders() {

    mysql_query(connect, "SELECT id, cost FROM `bookstore-project-db`.orders ORDER BY `bookstore-project-db`.orders.cost desc limit 1");
    res_set = mysql_store_result(connect);

    cout << "most profitable order : " << endl;

    while (((row = mysql_fetch_row(res_set)) != NULL))
    {
        cout << "order : " << row[0] << " profit : " << row[1] <<  endl;
    }


}
// option 17
void MySQL::amountOfDeliveriesByVendor() {
    mysql_query(connect, " SELECT vendor, COUNT(vendor) as numberOfDeliveries FROM `bookstore-project-db`.delivery group by vendor");
    res_set = mysql_store_result(connect);


    unsigned int numrows = mysql_num_rows(res_set);


    cout << "Delivery vendors : " << endl;

    while (((row = mysql_fetch_row(res_set)) != NULL))
    {
        cout << "Vendor : "<<  row[0]<< " Sent : " << row[1] << "  Deliveries" << endl;
    }

}

// option 18
void MySQL::numOfBooksTwoVersions() {
    mysql_query(connect, "SELECT  title,  count(title) as versions FROM `bookstore-project-db`.books  group by title  order by versions desc limit 1");
    res_set = mysql_store_result(connect);
    while (((row = mysql_fetch_row(res_set)) != NULL))
    {
        if (*row[1] == '1')
            cout << "no book with more than 1 version" << endl;
        else  cout << "The book : " << row[0] << " has " << row[1] << "versions" << endl;
    }
}
// option 19
void MySQL::notBuyingCustomers() {

}
// option 20
void MySQL::booksInInventory() {
    mysql_query(connect, "SELECT count(*) FROM `bookstore-project-db`.inventory where stock='1'");
    res_set = mysql_store_result(connect);
    while (((row = mysql_fetch_row(res_set)) != NULL))
    {
        cout << "All the diffrent kind of books that we have in stock : " << row[0] << endl;
    }
}
// option 21 
void MySQL::amountOfBooksInStock() {
    mysql_query(connect, "SELECT COUNT(*) FROM `bookstore-project-db`.inventory where stock ='1' ;");
    res_set = mysql_store_result(connect);
    while (((row = mysql_fetch_row(res_set)) != NULL))
    {
        cout << "All the diffrent kind of books that we have in stock : " << row[0] << endl;
    }
}

// option 22
void MySQL::noBookTake() {}
// option 23
void MySQL::yearlySale() {
    mysql_query(connect, "SELECT SUM(COST) AS revenue FROM `bookstore-project-db`.orders where YEAR(date) = '2010'");
    res_set = mysql_store_result(connect);
    while (((row = mysql_fetch_row(res_set)) != NULL))
    {
        cout << "The revinue in the year 2010 is  " << row[0] << endl;
    }

}
// option 24
void MySQL::workerSalary() {
    mysql_query(connect, "SELECT first_name, last_name ,hours, hours * 36 as salary   FROM `bookstore-project-db`.working_hours inner join `bookstore-project-db`.employees where `bookstore-project-db`.employees.id = `bookstore-project-db`.working_hours.employees_user_id");
    res_set = mysql_store_result(connect);
    while (((row = mysql_fetch_row(res_set)) != NULL))
    {
        cout << "The Salay of " << row[0] << " " << row[1] << "  for the month on 05 where he worked " << row [2] << " is " << row[3]<<  endl;
    }

}
// option 25
void MySQL::bestSalesMan() {
    mysql_query(connect, "SELECT Count(employees_id) as sales , first_name, last_name FROM `bookstore-project-db`.orders inner join `bookstore-project-db`.employees where `bookstore-project-db`.orders.employees_id = `bookstore-project-db`.employees.id group by employees_id  order by sales desc limit 1");
    res_set = mysql_store_result(connect);
    while (((row = mysql_fetch_row(res_set)) != NULL))
    {
        cout << "The number salesman of the year is " << row[1] << " " << row[2] << "  who have sold  " << row[0] << endl;
    }
}


 

MySQL :: ~MySQL()
{
    mysql_close (connect);
}
