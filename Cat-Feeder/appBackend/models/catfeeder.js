const mongoose = require('mongoose');
const Schema = mongoose.Schema;

//creating the feeder schema.
// const feedSchema = new Schema({
//   feedtime: {type: Date, default: Date.now },
//   feedwt: {type: Number, max:100 },   //food dispensed b/w 5 to 100gms.
// });

const catBistro = new Schema({
  feedername: {type: String, required: true },
  feedtime: {type: Date, default: Date.now},
  feedwt: {type: Number, max: 100},
  lastfeedtime: {type: Date},
  lastfoodwt: {type: Number},
  catwt: {type: Number}
});

//creating the feeder model. collection: CatFeeder
//const feedCat = mongoose.model('CatFeeder', feedSchema);
const feedCat = mongoose.model('CatFeeder', catBistro);

module.exports = feedCat;
