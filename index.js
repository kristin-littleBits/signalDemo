var express = require('express'),
	app = express(),
	request = require ('request'),
	bodyParser = require('body-parser'),
	twilio = require('twilio'),
	cloudBit = require('littlebits-cloud-http').defaults({ access_token: '8b7ec3855893e311a375b2f802d11d25d734af45b4ca80e98cf8ad7389cae353' });
	
cloudBit = cloudBit.defaults({ device_id: '243c200ccfc0' })
	
app.set('port', (process.env.PORT || 5000));
app.use(express.static(__dirname + '/public'));
app.use(bodyParser.urlencoded({ extended: true }));


app.get('/', function(req, res){
	res.send('hello world! this app is up and running.');
	cloudBit.output({ percent: 100, duration_ms: 5000 });
});


app.post('/sms', function(req, res){
	// get body of sms
	var smstext = req.body.Body;
	console.log(smstext);
	
	// respond to say we received the text
	var smsresp = new twilio.TwimlResponse();
	smsresp.message("got it!");
	res.send(smsresp.toString());
	
	// parse the text message and send cloudBit output
	console.log("parsing text to twilio number");
	parse_sms(smstext);
});


app.listen(app.get('port'), function() {
  console.log('Node app is running on port', app.get('port'));
});


function parse_sms( text ) {
	var re1 = new RegExp("email");
	var re2 = new RegExp("flashinglights");
	var re3 = new RegExp("pacman");
	if(re1.test(text)){
    		console.log("Display email address");
		cloudBit.output({ percent: 30, duration_ms: -1 });
		console.log("output to cloudbit sent!");
	}
	else if (re2.test(text)){
		console.log("Display cool light show");
		cloudBit.output({ percent: 60, duration_ms: -1 });
		console.log("output to cloudbit sent!");
	}
	else if(re3.test(text)){
		console.log("Display pacman");
		cloudBit.output({ percent: 90, duration_ms: -1 });
		console.log("output to cloudbit sent!");
	}
	else{
		console.log("There was no match, display logo");
		cloudBit.output({ percent: 10, duration_ms: -1 });
		console.log("output to cloudbit sent!");
	}
}

