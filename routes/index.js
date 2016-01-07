var express = require('express');
var router = express.Router();
var net = require('net');

var host = 'localhost';
var port = 7001;



/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index', { title: 'Jake Reynolds' });
});

function runClient() {
	var client = new net.Socket();
	client.connect(port, host, function() {
		console.log('CONNECTED TO: ' + host + ':' + port);
	    // Write a message to the socket as soon as the client is connected, the server will receive it as message from the client 
	    client.write("1");
	})
	
	// Add a 'data' event handler for the client socket
	// data is what the server sent to this socket
	client.on('data', function(data) {
	    
	    console.log('DATA: ' + data);
	    // Close the client socket completely
	    client.destroy();
	    
	});
	
	// Add a 'close' event handler for the client socket
	client.on('close', function() {
	    console.log('Connection closed');
	});
}

router.post('/sendRequest', function (req, res, next) {
	console.log('received message: ' + req.body.data);
	runClient();
	res.end();
})

module.exports = router;
