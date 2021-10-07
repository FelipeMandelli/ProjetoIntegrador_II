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
    	<!-- Link JS-->
    	<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.1/dist/js/bootstrap.bundle.min.js" integrity="sha384-/bQdsTh/da6pkI1MST/rWKFNjaCP5gBSY4sEBT38Q/9RBh9AH40zEOg7Hlq2THRZ" crossorigin="anonymous"></script>

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
							<a class="nav-link active" href="/Samiros/quem_somos.php">Quem somos!</a>
						</li>
						<li class="nav-item">
							<a class="nav-link" href="/Samiros/sobre_o_projeto.php">Sobre o Projeto!</a>
						</li>
						<li class="nav-item dropdown">
							<a class="nav-link dropdown-toggle" href="#" id="navbarDropdown" role="button" data-bs-toggle="dropdown" aria-expanded="false">
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
        
        <!--Lista de Integrantes-->
        <!--Felipe-->
        <div class="card lg-3" >
            <div class="row g-0">
                <div class="col-md-4">
                    <img src="/Samiros/img/felipe.jpeg" class="img-fluid rounded-start img-thumbnail" alt="...">
                </div>
                <div class="col-md-8">
                <div class="card-body">
                    <h5 class="card-title">Felipe Mandeli</h5>
                    <p class="card-text">O piloto da equipe, não capota o carro por conta da faculdade de fisica</p>
                    <p class="card-text"><small class="text-muted">Last updated 3 mins ago</small></p>
                </div>
                </div>
            </div>
        </div>

        <br>

        <!--Natalia-->
        <div class="card lg-3" >
            <div class="row g-0">
                
                <div class="col-md-4">
                    <img src="/Samiros/img/natalia.jpeg" class="img-fluid rounded-start img-thumbnail" alt="...">
                </div>
                <div class="col-md-8">
                <div class="card-body">
                    <h5 class="card-title">Natalia Pereira</h5>
                    <p class="card-text">Ela literalmente tem tudo que você precisar sobre a aula, e temos a representante da sala com a gente, kkkkkk</p>
                    <p class="card-text"><small class="text-muted">Last updated 3 mins ago</small></p>
                </div>
                </div>
            </div>
        </div>

        <br>

        <!--Samir-->
        <div class="card lg-3" >
            <div class="row g-0">
                <div class="col-md-4">
                    <img src="/Samiros/img/samir.jpeg" class="img-fluid rounded-start img-thumbnail" alt="...">
                </div>
                <div class="col-md-8">
                <div class="card-body">
                    <h5 class="card-title">Samir Ferreira</h5>
                    <p class="card-text">O sumido da escola que não sabe oque esta acontecendo mas tenta fazer as lições</p>
                    <p class="card-text"><small class="text-muted">Last updated 3 mins ago</small></p>
                </div>
                </div>
            </div>
        </div>
	
	</body>
	
</html>