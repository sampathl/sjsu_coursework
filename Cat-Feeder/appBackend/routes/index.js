var express = require('express');
var router = express.Router();


/*Status check*/
router.get('/', function(req, res) {
    //res.send({ping:'hello this is server and I am alive!'});
    res.sendStatus(200);
});


// /* POST feed data to mongo */
// router.post('/feedcat', function(req, res) {
//     //res.send({ping:'hello this is server and I am alive!'});
//
//   //  res.render('index',{body:"Posting data"});
//     res.status(200).send('Getting past feed data.')
// });
//
// /* GET last feed details from DB. */
// router.get('/getfeedreport', function(req, res){
//   //res.render('index', {body: 'Here is data from database.'});
//   res.status(200).send('Getting past feed data.')
//
// })

module.exports = router;
