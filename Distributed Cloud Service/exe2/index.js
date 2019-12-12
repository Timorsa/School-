const http = require('http');
const controller = require('./assets/modules/controller');

const PORT = process.env.PORT || 5000;

const server = http.createServer(controller)
                   .listen(PORT, ()=> console.log(`Server is running on port ${PORT}`));

