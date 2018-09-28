$("#lighton").click(function(){
  var apikey = $("apikey").val();
  var url = "https://api.thingspeak.com/update?api_key="+apikey+"&field1=1";
  $.getJSON(url, function(data) {
  console.log(data);
  });
});
$("#lightoff").click(function(){
  var apikey = $("apikey").val();
  var url = "https://api.thingspeak.com/update?api_key="+apikey+"&field1=0";
  $.getJSON(url, function(data) {
  console.log(data);
  });
});
