const url = require('url');
const Data = require('./data');
const handler = require ('./handler');





module.exports = (req, res) =>{
    
    const urlObject = url.parse(req.url ,true , false);
    req.urlObject = urlObject;

    switch (req.method) {
        case "GET":
          if (urlObject.path.startsWith("/showOrders")) {
            handler.showOrders(req, res);
            break;
          } else if (urlObject.path.startsWith("/getLogs")) {
            handler.getLogs(req, res);
            break;
          } else if (urlObject.path === "/") {
            handler.Home(req, res);
            break;
          }
        case "POST":
          if (urlObject.path.startsWith("/creatOrder")) {
            handler.creatOrder(req, res);
            break;
          }
          //todo
        case "PUT":
          if (urlObject.path.startsWith("/updateOrder")) {
            if (urlObject.query.id && urlObject.query.quantity) {
              handler.updateOrder(req, res);
              break;
            }
          }
        case "DELETE":
          if (urlObject.path.startsWith("/resetOrders")) {
            handler.resetOrders(req, res);
            break;
          } else if (urlObject.path.startsWith("/deleteOrder")) {
            handler.deleteOrder(req, res);
            break;
          }
        default:
            handler.badRequest(req, res);
      }
};