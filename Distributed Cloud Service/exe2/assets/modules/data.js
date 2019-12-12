const fs = require('fs');
const EventEmitter = require('events');
const User = require('./user');
const Order = require('./order');

// this module contains all data and data manipulation that we do

class Data extends EventEmitter {
    
    constructor() {
        super();
        this.users = [];
        this.orders = [];
        this.ticketsLeft=10;  
        this.logs = '';
        this.idCounter = 0;
        this.orderCounter =0;
        this.loadData();
    }

    loadData(){
        let rawData;

        fs.readFile('assets/data/users.json' , (err , data)=> {
            if (err) throw err;
            rawData = JSON.parse(data);
            rawData.forEach( user =>  this.users.push( new User(user.name , user.password , user.type)) );
            
        });
      
        fs.readFile('assets/data/orders.json' , (err , data)=> {
            if (err) throw err;
            rawData = JSON.parse(data);
            rawData.forEach( order =>  {this.orders.push( new Order(order.id , order.orderNumber , order.user , order.date ));
                                        this.idCounter++;
                                        this.orderCounter++; 
                                        this.ticketsLeft--;
                                    });
        });

        fs.readFile ('assets/data/logs.txt' , (err , data) => {
            if (err) throw err;
            this.logs += data;
        });
    
        this.ticketsLeft = 10 - this.orders.length;
        this.emit('Data Loaded');
    }

    updateData() {
        let updatedData;
        
        updatedData = JSON.stringify(this.users);
        fs.writeFile('assets/data/users.json', updatedData , err => {
            if (err) throw err;
            this.emit('Users data is updated');
        });
       
        updatedData = JSON.stringify(this.orders);
        fs.writeFile('assets/data/orders.json', updatedData, err => {
            if (err) throw err;
            this.emit('Orders data is updated');
        });

        fs.appendFile('assets/data/logs.txt', this.logs , err => {
            if (err) throw err;
            this.emit('log saved');
        });

        this.logs+= `${Date().toString()} - Data have been updated \n`;
    }

    creatOrder(name , quantity) {
        if(0 < this.ticketsLeft){
            console.log(name + 'ansdasdasdasdd ' + quantity);
            console.log("dakjhsdbkjashdbask");
            const newOrder = new Order(++this.idCounter , ++this.orderCounter , name , quantity );
            this.orders.push(newOrder);
            this.ticketsLeft--;
            this.logs += `${Date().toString()} - a new order have been made bu ${name} order id: ${this.idCounter+1} \n`;
            this.emit('Creat Order' , newOrder);
            this.updateData();
        } else {
                    this.logs +=  `${Date().toString()} - failed order attemp , reason : no more tickets. \n`
                    this.emit ('Creat Order' , false );
                }
    };

    deleteOrder(id) {
        const order = this.orders.find( order => order.id === id);
        if (order)  {
            this.orders = this.orders.filter(order => order.id != id);
            this.logs += `${Date().toString()} - order ${order.id} have been deleted \n`;
            this.updateData();
            this.emit('Delete Order', true);
            return true;

        } else {
                    this.logs += `${Date().toString()} - Attempt to delete order failed , reason : order not found`;
                    this.updateData();
                    this.emit('Delete Order' , false);
                }
    }

    updateOrder(orderNumber , quantity){
        const order = this.orders.find( order => order.orderNumber === orderNumber);
        const index = this.orders.indexOf(order);
        if(order){
            if(0 < quantity) {
                this.orders[index]= new Order(order.id , order.orderNumber , order.name , quantity);
                this.updateData();
                this.emit('Order Updated' , this.orders[index]);

            } else { this.deleteOrder(order.id);
                     this.emit('Order Updated' , false);
            }
        }

    }

    //amin only 
    showOrders(){
        this.log += `${Date().toString()} - Show all orders was requested by Admin \n`;
        this.updateData();
        this.emit('Show All Orders');
        return this.orders;
    }

    //admin only
    resetOrders() {
        this.orders =[];
        this.ticketsLeft =10;
        this.logs += `${Date().toString()} - Orders were reset by Admin \n`;
        this.updateData();
        this.emit('Reset Orders');
    }

    //admin only
    getLogs() {
        this.emit("Get Logs");
        this.logs += `${Date().toString()} - Logs were requested by Admin\n`;
        return this.logs;
    }

    getUser(name, password){
      const user= this.users.find(user => user.authenticate(name , password));
        if  (user){
            return user;
       } else return false;
    }

    
}

const data = (new Data()).on('Data Loaded' , () => console.log('Data Loaded Succesfully') )
                         .on('Users data is updated' , ()=> console.log('Users data is updated'))
                         .on('Orders data is updated', ()=> console.log('Orders data is updated'))
                         .on('log saved', ()=> console.log('log saved'))
                         .on('Creat Order', (order)=>{
                              if (order) {  
                                console.log(`Your Order Created  , your Order number : ${order.orderNumber}`);
                              } else console.log ('failed order attemp , reason : no more tickets');
                            })
                         .on('Delete Order', (status )=>{
                              if(status) { 
                                  console.log('Order Deleted');
                                } else console.log('Couldnt Delete Order');})
                         .on('Order Updated', (order)=> {
                               if (order) {
                                  console.log (`Order Number ${order.orderNumber} have been updated`);
                                }else console.log('Couldnt update order');
                            })
                         .on( 'Show All Orders', ()=> console.log('Sending All Orders'))
                         .on( 'Reset Orders', ()=> console.log('All Orders Have Been Reseted'))
                         .on( 'Get Logs' , ()=> console.log(' logs sent'));
                    
module.exports = data;
