# Star-Power

this is kind of me (Ryan) just messing around, we might end up scrapping all of this so don't feel pressured to understand it yet.


to run on local host:

1. make sure you have node.js installed and added to PATH
2. in the terminal run "npm install" to install all the dependencies listed in the package.json file
3. run "npm run go" to start the server. Then go to your browser and navigate to http://localhost:2000
4. you can now see the webpage, and every time you save changes to the server code locally it will restart and update your webpage automatically

- the "dashboard.ejs" file is where you can edit the webpage. EJS stands for "embedded JavaScript", and an EJS file is just a regular HTML file that you can put javascript code into pretty easily. The main reason I use it is because it makes it easy to input data from the server (i.e. the song data we get from the spotify API) into the HTML page, but we can change this later if needed.

- the "node_modules" folder is created automatically when installing dependencies. You can ignore it

- another option is to scrap doing our own local webpage and just make an app with C++. That might be easier if we want to do some decent visuals

- app.js is the file that the server starts from. 

- There's some broken code in the index.js file that I'm trying to get to interact with the spotify API.

to-do:
- we might need to store the spotify auth token in the client
- figure out what data 