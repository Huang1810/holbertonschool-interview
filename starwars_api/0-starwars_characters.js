#!/usr/bin/node

const request = require('request');
const movieId = process.argv[2];

if (!movieId) {
  console.error('Usage: ./0-starwars_characters.js <Movie ID>');
  process.exit(1);
}

const movieUrl = `https://swapi-api.alx-tools.com/api/films/${movieId}/`;

request(movieUrl, async (err, res, body) => {
  if (err) return;

  const film = JSON.parse(body);
  const characters = film.characters;

  for (const url of characters) {
    await new Promise((resolve, reject) => {
      request(url, (error, response, charBody) => {
        if (!error) {
          const character = JSON.parse(charBody);
          console.log(character.name);
          resolve();
        } else {
          reject(error);
        }
      });
    });
  }
});
