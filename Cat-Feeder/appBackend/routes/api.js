var express = require('express');
var router = express.Router();
var MongoClient = require('mongodb').MongoClient;
  assert = require('assert');
//var url = "mongodb://localhost:27017/catBistro";
const url = 'mongodb://54.241.150.45:27017,13.56.58.166:27018,54.215.228.194:27019/catBistro?replicaSet=logdb-replica-set';
//const feedCat = require('../models/catfeeder.js');
const catBistro = require('../models/catfeeder.js');

/****
Data from web app to mongo.
{
"feedername": "Patio-1",
"feedtime" : "2012-04-23T18:25:43.511Z",
"feedwt": 23,
}

Data from pi to Mongo (after feed)
{
"feedername": "Patio-1",
"feedtime" : "2012-04-23T18:25:43.511Z",
"feedwt": 23,
"lastfeedtime": "2012-04-23T18:25:43.511Z",
"lastfoodwt": 10,
"catwt": 17
}
/


/* POST feed data to mongo */
router.post('/feedcat', function(req, res, next) {

  MongoClient.connect(url, function(err, db) {
  if (err) throw err;
  db.collection("catfeeders").insertOne(req.body, function(err, result) {
    if (err) throw err;
    //res.send('sucess');
    res.send(result);
    db.close();
  });
});

  //console.log(req.body);
  //  res.render('index',{body:"Posting data"});

  // var feedit = new feedCat(req.body);
  // feedit.save(); //saving the object.

  //create(): does both the above statements.

  //Using promise and returning error via custom err handler.
  // catBistro.create(req.body).then(function(err, data){
  //     if (err) throw err;
  //     res.send(data);
  // }).catch(err => {
  //   //console.log(err);
  //   res.status(400).send({"errormsg":err.errors.feedwt.message});
  //   // res.status(400).send({"errormsg":err});
  //   //res.send(err);
  // });

  //Using error handler middleware.
  // catBistro.create(req.body).then(function(err, data, next){
  //   console.log(data);
  //   //res.render('index',{body:data});
  // }).catch(next);

  // res.status(200).send({
  //   msg: 'Psoting to db',
  //   feedtime: req.body.feedtime,
  //   feedwt: req.body.feedwt
  // })





});



/* GET all feed details from DB. */
router.get('/getData', function(req, res, next){

  res.setHeader('Access-Control-Allow-Origin', '*');
  res.setHeader('Access-Control-Allow-Methods', 'GET, POST, OPTIONS, PUT, PATCH, DELETE'); // If needed
  res.setHeader('Access-Control-Allow-Headers', 'X-Requested-With,contenttype'); // If needed
  res.setHeader('Access-Control-Allow-Credentials', true);
  //res.render('index', {body: 'Here is data from database.'});
  //res.status(200).send('Getting past feed data.')

  MongoClient.connect(url , function(err, db){
    assert.equal(null, err);
    //console.log("Successfully connected to the db server");

    db.collection('catfeeders').find({}).toArray(function(err, docs){

      //console.log(docs);
      var msg = [];

      docs.forEach(function(doc){
        //msg.push(doc.feedername);
        //msg.push(doc.lastfeedtime);
        //msg.push(doc.lastfoodwt);
        //msg.push(doc.catwt);
        msg.push(doc);

      });
      db.close();
      res.json(msg);
    });
    console.log("Called find()");
  });


})




/* GET last feed details from DB. */
router.get('/getfeedreport', function(req, res, next){

  res.setHeader('Access-Control-Allow-Origin', '*');
  res.setHeader('Access-Control-Allow-Methods', 'GET, POST, OPTIONS, PUT, PATCH, DELETE'); // If needed
  res.setHeader('Access-Control-Allow-Headers', 'X-Requested-With,contenttype'); // If needed
  res.setHeader('Access-Control-Allow-Credentials', true);
  //res.render('index', {body: 'Here is data from database.'});
  //res.status(200).send('Getting past feed data.')

//   MongoClient.connect(url, function(err, db) {
//   if (err) throw err;
//   //db.collection("catfeeders").findOne({"catwt":{$exists : true, $ne:''}}, function(err, result) {
//     db.collection("catfeeders").findOne({"catwt":{$exists : true}}, function(err, result) {
//     if (err) throw err;
//     console.log(result);
//     db.close();
//   });
// });

MongoClient.connect(url , function(err, db){
  assert.equal(null, err);
  //console.log("Successfully connected to the db server");

  db.collection('catfeeders').find({"catwt":{$exists : true, $ne:''}}).toArray(function(err, docs){

    console.log(docs);
    var msg = [];

    docs.forEach(function(doc){
      //msg.push(doc.feedername);
      //msg.push(doc.lastfeedtime);
      //msg.push(doc.lastfoodwt);
      //msg.push(doc.catwt);
      msg.push(doc);

    });
    res.json(msg);
    db.close();

  });
  console.log("Called find()");
});

})

module.exports = router;
