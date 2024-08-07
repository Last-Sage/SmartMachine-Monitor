const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<style>

</style>
<body>

<div>
  <h1>Parameters</h1>
</div>

<div id="Value" class="parameters">
  <h2>Voltage : <span id="volt">0</span></h2>
  <h2>Current : <span id="amp">0</span></h2>  
  <h2>Temperature : <span id="deg">0</span></h2>
  <button id="button" onclick="onOff()" style = "background-color:green;">ON</button>
</div>

 
<script>
setInterval(function() {
  // Call a function repetatively with 1 Second interval
  getData();
}, 1000); //1000mSeconds update rate

function getData() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
        var recived_data = this.responseText.split('|');
        var volt = recived_data[0];
        var amp = recived_data[1];
        var deg = recived_data[2];
        console.log(recived_data);
        document.getElementById("volt").innerHTML = volt;
        document.getElementById("amp").innerHTML = amp;
        document.getElementById("deg").innerHTML = deg;
      }
    
  };
  xhttp.open("GET", "readADC", true);
  xhttp.send();
}

function onOff(){
  var xhttp = new XMLHttpRequest();
  xhttp.open("GET", "onoff", true);
  xhttp.send();
  if (document.getElementById("button").innerHTML == "ON") {
      document.getElementById("button").innerHTML = "OFF";
      document.getElementById("button").style.backgroundColor="red";
  } else {
      document.getElementById("button").innerHTML = "ON";
      document.getElementById("button").style.backgroundColor="green";
  }
  }

</script>
</body>
</html>
)=====";
