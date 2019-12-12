const data = require('./data');

class Handler {
   badRequest  (req, res) {
       console.log(`url ${req.urlObject.path} not exist!`);
       res.writeHeader(404);
       res.write('Bad request');
       res.end();
    }

    showOrders (req, res) {
        const user = data.getUser(req.urlObject.query.name , req.urlObject.query.password);
        if (user.type === 'admin'){
            const orders = JSON.stringify(data.showOrders());
            res.writeHeader(200);
            res.end(orders);
        } else if (user){
                res.writeHeader(401);
                res.end('You have no autherisation');
                 } else { 
                    res.writeHeader(404);
                    res.end('User is not found');
                }
    }

    creatOrder (req , res) {
        let body='';
        req.on('data', chunk => {
            body += chunk.toString();
        });
        req.on('end', () => {
           const loadBody = JSON.parse(body);
           if (loadBody) {
               if(data.creatOrder(loadBody.name, loadBody.quantity)){
                    res.writeHeader(200);
                    res.end('Order created succefully');
                } else { 
                    res.writeHeader(404);
                    res.end('User is not found');
                }
           } 
        });
    }

        // edit order
    updateOrder (req , res) {
        if (data.updateOrder(parseInt(req.urlObject.query.orderNumber), parseInt(req.urlObject.query.quantity))) {
            res.end(`Order have been updated`);
        } else {
            res.writeHeader(404);
            res.end(`Sorry order wasn't found`);
        }
    }
    
    resetOrders (req , res) {
        const user = data.getUser(req.urlObject.query.name , req.urlObject.query.password);
        if (user.type === 'admin'){
            data.resetOrders();
            res.writeHeader(200);
            res.end('Orders reseted');
        } else if (user){
            res.writeHeader(401);
            res.end('You have no autherisation');
             } else { 
                res.writeHeader(404);
                res.end('User is not found');
            }
    
    }
 
    deleteOrder (req ,res) {
        if (data.deleteOrder(parseInt(req.urlObject.query.id))) {
            res.writeHeader(200);
            res.end ('Order have been deleted');    
            } else {
                res.writeHeader(404);
                res.end('User is not found');  
                }
    }

    getLogs (req , res) {
            const user = data.getUser(req.urlObject.query.name , req.urlObject.query.password);
            if (user.type === 'admin'){
                res.writeHeader(200);
                res.end(data.getLogs());
            }else if (user){
                res.writeHeader(401);
                res.end('You have no autherisation');
                 } else { 
                    res.writeHeader(404);
                    res.end('User is not found');
                }
    }

    // check option for home
    Home (req , res) {
        res.writeHeader(200);
        res.end("Wellcome to GaGa show ticket system");
    }


}
    
const handler = new Handler();
module.exports = handler;