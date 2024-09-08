#!/usr/bin/node

const request = require("request");

const movieId = process.argv[2];
console.log("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
console.log(movieId);
console.log("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");

const movieUrl = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

request(movieUrl, (error, res, body) => {
  if (error) {
    console.error(`Error while fetching movie:${movieId}`, error);
    return;
  }

  const movie = JSON.parse(body);
  const characters = movie.characters;

  characters.forEach((characterURL) => {
    request(characterURL, (err, res, characterBody) => {
      if (err) {
        console.error(`Error while fetching character:${characterURL}`, err);
        return;
      }

      const character = JSON.parse(characterBody);
      console.log(character.name);
    });
  });
});
