<?php
	include("includes/bd_connect.php");

	$consulta = "SELECT * FROM tab_info";

	$con = $mysqli->query($consulta) or die($mysqli->error);		

?>

<!doctype html>

<html lang="pt">

  	<head>

		<meta charset="utf-8">

		<meta name="viewport" content="width=device-width, initial-scale=1">
		
		<!-- Link CSS -->
		<link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.1/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-F3w7mX95PdgyTmZZMECAngseQB83DfGTowi0iMjiWaeVhAn4FJkqJByhZMI3AhiU" crossorigin="anonymous">
		
		<!-- Titulo da página -->
		<title>Samiros</title>
  	</head>

	<body>
    	<!-- Link JS bootstrap-->
    	<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.1/dist/js/bootstrap.bundle.min.js" integrity="sha384-/bQdsTh/da6pkI1MST/rWKFNjaCP5gBSY4sEBT38Q/9RBh9AH40zEOg7Hlq2THRZ" crossorigin="anonymous"></script>
        
        <!--Link JS Google Maps-->
        <script
            src="https://maps.googleapis.com/maps/api/js?key=AIzaSyCgbSiOrswb72udIRwlm2FF00_sZhIlkhw&callback=initMap&libraries=&v=weekly"
            async
        ></script>
        

		<!--Barra superior-->
		<nav class="navbar col-12 fixed-top navbar-expand-lg navbar-light bg-light" style="z-index: 999;">
			<div class="container-fluid col-11">
				<a class="navbar-brand" href="#">Samiros</a>
				<button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
				<span class="navbar-toggler-icon"></span>
				</button>
				<div class="collapse navbar-collapse" id="navbarSupportedContent">
					<ul class="navbar-nav me-auto mb-2 mb-lg-0">
						<li class="nav-item">
							<a class="nav-link" aria-current="page" href="/Samiros/index.php">Home</a>
						</li>
						<li class="nav-item">
							<a class="nav-link" href="/Samiros/quem_somos.php">Quem somos!</a>
						</li>
						<li class="nav-item">
							<a class="nav-link" href="/Samiros/sobre_o_projeto.php">Sobre o Projeto!</a>
						</li>
						<li class="nav-item dropdown">
							<a class="nav-link active dropdown-toggle" href="#" id="navbarDropdown" role="button" data-bs-toggle="dropdown" aria-expanded="false">
								Informações
							</a>
							<ul class="dropdown-menu" aria-labelledby="navbarDropdown">
								<li><a class="dropdown-item" href="/Samiros/sensores.php">Leitura dos Sensores</a></li>
								<li><a class="dropdown-item" href="/Samiros/gps.php">GPS</a></li>
							</ul>
						</li>
						<li class="nav-item">
							<a class="nav-link disabled">Disabled</a>
						</li>
					</ul>
					<form class="d-flex">
						<input class="form-control me-2" type="search" placeholder="Search" aria-label="Search">
						<button class="btn btn-outline-success" type="submit">Search</button>
					</form>
				</div>
			</div>
		</nav>

        <br>
        <br>
        <br>

        <div class="ratio ratio-16x9 center img-thumbnail" id="map"></div>

        <script type="text/javascript">
		var lat
		var lon
		alert(lon)
		lat = 23
		alert(lat)
		lon = 24
		alert(lon)
            function getLocation(){
                if(!navigator.geolocation)
                    return null;
                navigator.geolocation.getCurrentPosition((pos)=>{
                    document.getElementById("lat").innerText = pos.coords.latitude;
                    document.getElementById("lon").innerText = pos.coords.longitude;
                });
            }


			function initMap() {
				// The location of Uluru
				const uluru = { lat: lat, lng: lon };
				// The map, centered at Uluru
				const map = new google.maps.Map(document.getElementById("map"), {
					zoom: 4,
					center: uluru,
				});
				// The marker, positioned at Uluru
				const marker = new google.maps.Marker({
					position: uluru,
					map: map,
				});
			}
        </script>
        
	
	</body>
	
</html>
