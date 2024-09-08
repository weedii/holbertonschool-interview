#!/usr/bin/node

const request = require("request");

const movieId = process.argv[2];
const movieURL = `https://swapi-api.hbtn.io/api/films/${movieId}`;

request(movieURL, async (err, res, body) => {
  if (err) {
    console.log(err);
  }

  const characters = JSON.parse(body).characters;

  for (const charURL of characters) {
    await new Promise((resolve, reject) => {
      request(charURL, (err, res, body) => {
        if (err) {
          reject(err);
        }

        charName = JSON.parse(body).name;
        console.log(charName);
        resolve();
      });
    });
  }
});
