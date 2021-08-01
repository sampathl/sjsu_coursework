var MongoClient = require('mongodb').MongoClient;
var db;
var connected = false;
var url = "mongodb://54.241.150.45:27017/catBistro";
const serial = "Patio-2";

var sys = require('sys')
var exec = require('child_process').exec;

 
MongoClient.connect(url, function(err, _db){
  
  if (err) { 
  	throw new Error('Could not connect: '+err); 
  }
  else{
  	var getdata = function(){
  		setTimeout(function(){
			_db.collection('catfeeders').find({"feedername": serial, "isScheduled": 0}).toArray(function(err, data){
				if(err){
					console.log(err);
					getdata();
				}
				else{
					if(data.length > 0){
						
						// Set Chronjob which will be executed on feeding time
						var d = new Date(data[0].feedtime);
						console.log("d", d)						
						var TIME_TO_FEED = d.getUTCHours() + ":" + d.getUTCMinutes() + " " + (d.getMonth()+1) +"/" +d.getDate() + "/" + d.getFullYear();
						console.log(TIME_TO_FEED);
						exec( "echo 'python /home/pi/project/Project-Team-16/raspberryPi/catBistro.py' " + data[0].feedwt + " | at " + TIME_TO_FEED, function(err, stdout, stdin){
							console.log('stderr', err);
							console.log('stdout', stdout);
						});
						_db.collection('catbistro').updateOne({"feedername": serial, "isScheduled": 0}, {$set: {"isScheduled": 1}}, function(err, res){
							console.log(err);
							console.log(res);	
						});

						
						
						console.log(data);
						getdata();
					}
					else{
						console.log("No update");
						getdata();						
					}
				}
			});
		}, 1000);
  	}
  	getdata();
  }
});
