#!/usr/bin/node

const request = require('request');
const movieId = process.argv[2];

if (!movieId) {
  console.error('Usage: ./0-starwars_characters.js <Movie ID>');
  process.exit(1);
}

// Get film data
const url = `https://swapi.dev/api/films/${movieId}/`;

request(url, (error, response, body) => {
  if (error) return console.error(error);

  const film = JSON.parse(body);
  const characters = film.characters;

  // Loop through characters in order and fetch each one
  characters.forEach((characterUrl) => {
    request(characterUrl, (err, res, characterBody) => {
      if (!err) {
        const character = JSON.parse(characterBody);
        console.log(character.name);
      }
    });
  });
});
