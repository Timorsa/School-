const express = require('express');
const router = express.Router();
const apiCtrl =require('../controllers/apiController')

router.get('/' , apiCtrl.getAllMenu);
router.get('/:name' , apiCtrl.getItem);
router.put('/:name' , apiCtrl.editItemPrice);
router.post('/' , apiCtrl.addItem);
router.delete('/:name', apiCtrl.removeItem);
   
module.exports = router;