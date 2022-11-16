const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">

<head>
	<title>ESP</title>
	<meta charset="UTF-8">
	<meta http-equiv="X-UA-Compatible" content="IE=edge">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bulma@0.9.4/css/bulma.min.css">
  <style>
section{
  overflow-y: hidden; /* Hide vertical scrollbar */
}
  </style>
</head>

<body>

	<section class="hero is-fullheight is-success " id="hero">
		<div class="hero-body">
			<div class="container has-text-centered content is-large">
				<h1 class="title is-1" id="distance">Not Full</h1>
				<p class="subtitle is-3">
					<span id="Ultrasonic">0</span> cm Left
				</p>
			</div>
		</div>
	</section>
	<script>
		setInterval(function () {
			// Call a function repetatively with 2 Second interval
			getData();
		}, 500); //500mSeconds update rate

		function getData() {
			var xhttp = new XMLHttpRequest();
			xhttp.onreadystatechange = function () {
				if (this.readyState == 4 && this.status == 200) {
          if (this.responseText < 3){
            document.getElementById("distance").innerHTML = "FULL";
            let cName = document.getElementById("hero");
			      cName.className = `hero is-fullheight is-danger`;            
          }
          else{
            document.getElementById("distance").innerHTML = "Not Completely Full";
            let cName = document.getElementById("hero");
			      cName.className = `hero is-fullheight is-success`;            
          }
					document.getElementById("Ultrasonic").innerHTML =
						this.responseText;
				}
			};
			xhttp.open("GET", "Ultrasonic", true);
			xhttp.send();
		}
	</script>
</body>

</html>
)=====";