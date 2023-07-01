const express = require('express');
const session = require('express-session');
const app = express();

// views
app.set('view engine', 'ejs'); 

// Express body parser
app.use(express.urlencoded({ extended: false }));

// sets the directory for static client-side files
app.use(express.static(__dirname + '/public'));

// Express session
app.use(
  session({
    secret: 'secret',
    resave: false,
    saveUninitialized: true
  })
);

// Route them to dashboard.ejs
app.use('/', require('./index.js').router);

const PORT = 2000;
app.listen(PORT, console.log(`Server running on  ${PORT}`));