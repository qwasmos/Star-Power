const express = require('express');
const router = express.Router();

// Ryan's spotify API app credentials
const clientID = "0274b2536517436d9fd4dc9d6a1f4b80";
const clientSecret = "1fac84b070cc4c39986e6b50f0fee93a";

var songs = "";

// uses the above credentials to create a temporary access token for the client
const getAuthToken = async() => {
  const result = await fetch('https://accounts.spotify.com/api/token', {
    method: 'POST',
    headers: {
      'Content-Type': 'application/x-www-form-urlencoded',
      'Authorization': 'Basic ' + btoa(clientID + ':' + clientSecret)
    },
    body: 'grant_type=client_credentials'
  })
  const data = await result.json();
  return data.access_token;
}

async function fetchWebApi(endpoint, method, body) {
  const token = await getAuthToken();
  try {
  const res = await fetch(`https://api.spotify.com/${endpoint}`, {
    headers: {
      Authorization: `Bearer ${token}`,
    },
    method,
    body:JSON.stringify(body)
  });
  return await res.json();
} catch (err){
  console.log("hey");
}
}

// runs when client tries to visit webpage
router.get('/', (req, res) =>{
    res.render('dashboard.ejs',{
      songs: songs
    })
})

// runs when they submit a song
router.post('/', async (req, res) => {
    const { songName } = req.body;
    const topTracks = await fetchWebApi('v1/me/top/tracks?time_range=short_term&limit=5', 'GET').items;
    console.log(
      topTracks?.map(
        ({name, artists}) =>
          `${name} by ${artists.map(artist => artist.name).join(', ')}`
      )
    );
    res.render('dashboard.ejs', {
      songs: songs
    })
})
module.exports = {router}