#arduinoServer

Currently only set up for a local server.  Working on making it connect to my home network.

#Structure

The app is built on a node.js server with express and jade.  Felt like trying a couple new languages this time.<br>
When the button on the webpage is pressed it sends a signal to the node.js backend.  This then connects as a TCP client to the C server, and sends the data to it.<br>
Upon receiving the data the C server writes to the arduino, notifying it to blink the light

#Setting up the arduino

Set up the arduino with a single led in the breadboard, receiving power from pin 2.<br>
Then plug it into your computer and "cd arduinoApp/arduinoCode" and download lights.ino to your arduino

#Setting up the webpage

To run, download the files and 'cd arduinoApp'.<br>
In one terminal window type "npm start" (you have to have npm installed)<br>
In another terminal type "cd arduinoApp/homeServer" and run "./server 7001" (check arduinoApp/routes/index.js the port variable to verify)<br>
Then go to "localhost:3000" in a web browser.
