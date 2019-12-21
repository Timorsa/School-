const MenuItem = require('../models/menuItem');


module.exports = {
    async getAllMenu(req, res, next){
        try {
            const items = await MenuItem.find();
            res.status(200).json(items);
            console.log(items);
        }catch(err) {
            res.status(500).json({message : err});
            console.log('ERROR : cannot get menu items');
        }
    },
    async getItem(req, res, next) {
        try{
            const item = await MenuItem.find({name: req.params.name});
            res.status(200).json(item);
        }catch (err) {
            res.json(404).json({ messege : err});
            console.log('ERROR : cannot find menu item')
        }
    },
    async addItem(req, res, next) {
        const item = new MenuItem ({
            name: req.body.name ,
            description: req.body.description,
            price: req.body.price,
            category : req.body.category
        });
        
        const savedItem = await item.save()
                                    .then(data => res.status(200).json(data))
                                    .catch(err => res.status(500).json({messege: err}));
    },
    async editItemPrice(req, res, next) {
        try {
            const updatedItem = await MenuItem.updateOne(
                {name : req.params.name},
                { $set : { price : req.body.price }}
            );
            res.status(200).json(updatedItem);
        } catch (err){
            res.status(500).json({ message : err })
            console.log('ERROR : couldnt update price')
        }
    },
    async removeItem(req, res, next) {
        try {
            const removedItem = await MenuItem.remove({ name: req.params.name });
            res.status(200).json(removedItem);
        } catch(err) {
            res.status(500).json({ message : err });
            
        }
    }
}