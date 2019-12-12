
class Order {

    constructor(id=0 ,orderNumber ,name , quantity , time=  Date().toString()) {
        this.id = id ; 
        this.orderNumber = orderNumber;
        this.name = name ;
        this.time = time ;
        this.quantity = quantity;
    }
    
}

module.exports = Order;