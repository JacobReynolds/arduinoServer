#arduinoServer

Currently only set up for a local server.  Working on making it connect to my home network.

#Setting up the arduino

Set up the arduino with a single led in the breadboard, receiving power from pin 2.<br>
Then plug it into your computer and "cd arduinoApp/arduinoCode" and download lights.ino to your arduino

#Setting up the webpage

To run, download the files and 'cd arduinoApp'.<br>
In one terminal window type "npm start" (you have to have npm installed)<br>
In another terminal type "./server 7001" (check arduinoApp/routes/index.js the port variable to verify)<br>
Then go to "localhost:3000" in a web browser.
