const express = require('express');
const path = require('path')
const db = require('./assets/db/db_connection');
const bodyParser = require('body-parser');


const PORT = process.env.PORT || 5000;
const app = express();

app.use(bodyParser.json());
app.use(express.json());
app.use(express.urlencoded({ extended: true }));

const apiRoute = require('./assets/routes/apiRoute');
app.use('/api', apiRoute);

app.get('/' , (req, res)=> {
    res.sendFile(path.join(__dirname+'/assets/front/index.html'));
})
app.listen(5000 , () => console.log(`Express server is ready for requests on : ${PORT}`) );

