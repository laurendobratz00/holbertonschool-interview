#!/usr/bin/node

const request = require('request');
const process = require('process');
request.get('https://swapi-api.hbtn.io/api/films/' + process.argv[2] + '/', function (err, response, body) {
  if (err) {
    console.log(err);
  }
  const characters = JSON.parse(body).characters;
  const dict = {};
  const x = JSON.parse(body);
  for (const c of x.characters) {
    request.get(c, function (error, response, body) {
      const i = JSON.parse(body);
      if (error) {
        console.log(error);
      } else {
        const names = i.name;
        dict[c] = names;
      }
      if (Object.values(dict).length === characters.length) {
        characters.forEach(c => {
          console.log(dict[c]);
        });
      }
    });
  }
});
