#!/usr/bin/node

const request = require('request');
const movieId = process.argv[2];

if (!movieId) {
  console.error('Usage: ./0-starwars_characters.js <Movie ID>');
  process.exit(1);
}

const movieUrl = `https://swapi.dev/api/films/${movieId}/`;

request(movieUrl, (err, res, body) => {
  if (err) return;

  const film = JSON.parse(body);
  const characters = film.characters;

  printCharactersInOrder(characters, 0);
});

function printCharactersInOrder(characters, index) {
  if (index >= characters.length) return;

  request(characters[index], (err, res, body) => {
    if (!err) {
      const character = JSON.parse(body);
      console.log(character.name);
      printCharactersInOrder(characters, index + 1);
    }
  });
}
