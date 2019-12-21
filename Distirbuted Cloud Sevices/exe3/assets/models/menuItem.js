const {Schema , model} = require('mongoose');

const schema = {
    name: { type : String , index: 1 , require: true}, 
    description: { type: String , require: true }, 
    price: { type: Number , require: true },
    category: { type: String, default : "other" }
};

const menuItem_schema = new Schema(schema ,  {collection: 'menuItems'} );
const MenuItem = model('menuItems' , menuItem_schema);


module.exports = MenuItem;