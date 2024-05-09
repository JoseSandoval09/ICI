<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Proyecto Final Lenguajes</title>
    <link rel="stylesheet" href="estilo.css"/>
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.0/jquery.min.js"></script>

    <!--JQUERY UI-->
    <link rel="stylesheet" href="//code.jquery.com/ui/1.13.2/themes/base/jquery-ui.css">
    <link rel="stylesheet" href="/resources/demos/style.css">
    <script src="https://code.jquery.com/jquery-3.6.0.js"></script>
    <script src="https://code.jquery.com/ui/1.13.2/jquery-ui.js"></script>

    <!-- Bootstrap-->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha3/dist/css/bootstrap.min.css" rel="stylesheet"/>
    <link href="https://getbootstrap.com/docs/5.3/assets/css/docs.css" rel="stylesheet"/>
</head>

<body>


     <!---tipo de navbar-->
        <nav class="navbar navbar-expand-lg fixed-top navbar-light" style="background-color: rgb(120,204,204)">
            <div class="container-fluid">
                    <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarNavDropdown" aria-controls="navbarNavDropdown" aria-expanded="false" aria-label="Toggle navigation">
                    <span class="navbar-toggler-icon">
                    </span>
                    </button>

                    <a class="navbar-brand" href="#">
                        <img src="icono.png" width="40" height="40">
                    </a>

                    <div class="collapse navbar-collapse" id="navbarTogglerDemo03">
                    <ul class="navbar-nav mr-auto mt-2 mt-lg-0">
                        <li class="nav-item active">
                            <a class="nav-link" href="proyectofinal.php">
                            <button type="button" class="boton" style="background-color: rgb(255,102,157)" > &nbsp; Inicio  &nbsp;</button>
                            </a>
                        </li>
                        <li class="nav-item">
                            <a class="nav-link" href="agregar.php">
                            <button type="button" class="boton" style="background-color: rgb(255,139,0)">&nbsp; Agregar &nbsp;</button>
                        </a>   
                        </li>
                        <li class="nav-item">
                            <a class="nav-link" href="archivo.php">
                            <button type="button" class="boton" style="background-color: rgb(255,104,92)">&nbsp; Archivo &nbsp;</button>
                        </a>   
                        </li>
                    </ul>
            </div>
        </nav>
    <br>
    <div class="titulo">  
        <img src="estimulacion.png" width="400" height="400">
    </div>
    <div class="container">
    </div>
    <div class="quien"><p class="big">
        <font color="#FF669D">¿</font>
        <font color="#FF685C">Q</font>
        <font color="#FF8B00">U</font>
        <font color="#FFD301">Í</font>
        <font color="#05B189">E</font>
        <font color="#78CCCC">N</font>
        <font color="#FF669D">E</font>
        <font color="#FF685C">S</font>
    <br>
        <font color="#FF8B00">&nbsp;S</font>
        <font color="#FFD301">O</font>
        <font color="#05B189">M</font>
        <font color="#78CCCC">O</font>
        <font color="#FF669D">S</font>
        <font color="#FF685C">?</font>
    </p> 
    <p class="text">Somos un centro de estimulación acuática temprana y atención a bebés de 5 meses a 3 años.</p>
    </div>
    <div class="buscamos"><p class="big">
    <font color="#FF669D">¿</font>
        <font color="#FF685C">Q</font>
        <font color="#FF8B00">U</font>
        <font color="#FFD301">É</font>
    <br>
        <font color="#05B189">B</font>
        <font color="#78CCCC">U</font>
        <font color="#FF669D">S</font>
        <font color="#FF685C">C</font>
        <font color="#FFD301">A</font>
        <font color="#05B189">M</font>
        <font color="#78CCCC">O</font>
        <font color="#FF669D">S</font>
        <font color="#FF685C">?</font>
    </p> 
    <p class="text">Crear un espacio seguro y divertido donde se desarrolle el bebé y sus habilidades acuáticas.</p>
    </div>
        <div id="carouselExample" class="carousel slide">
        <div class="carousel-inner">
            <div class="carousel-item active">
            <img src="1.jpeg" class="d-block w-100" alt="..." width="20%" height="10%">
            </div>
            <div class="carousel-item">
            <img src="2.jpeg" class="d-block w-100" alt="..." width="20%" height="10%">
            </div>
            <div class="carousel-item">
            <img src="3.jpeg" class="d-block w-100" alt="..." width="20%" height="10%"">
            </div>
            <div class="carousel-item">
            <img src="4.jpeg" class="d-block w-100" alt="..." width="20%" height="10%"">
            </div>
            <div class="carousel-item">
            <img src="5.jpeg" class="d-block w-100" alt="..." width="20%" height="10%"">
            </div>
        </div>
        <button class="carousel-control-prev" type="button" data-bs-target="#carouselExample" data-bs-slide="prev">
            <span class="carousel-control-prev-icon" aria-hidden="true"></span>
            <span class="visually-hidden">Previous</span>
        </button>
        <button class="carousel-control-next" type="button" data-bs-target="#carouselExample" data-bs-slide="next">
            <span class="carousel-control-next-icon" aria-hidden="true"></span>
            <span class="visually-hidden">Next</span>
        </button>
        </div>
    <div class="wha">
        <p class="big"> 
        <font color="#FF669D">W</font>
        <font color="#FF685C">h</font>
        <font color="#FF8B00">a</font>
        <font color="#FFD301">t</font>
        <font color="#05B189">s</font>
        <font color="#78CCCC">A</font>
        <font color="#FF669D">p</font>
        <font color="#FF685C">p</font>
    <br>
    <p class="textbig">(686) 606-58-80</p>
        </p>
        <p class="big"> 
        <font color="#FF669D">I</font>
        <font color="#FF685C">n</font>
        <font color="#FF8B00">s</font>
        <font color="#FFD301">t</font>
        <font color="#05B189">a</font>
        <font color="#78CCCC">g</font>
        <font color="#FF669D">r</font>
        <font color="#FF685C">a</font>
        <font color="#FF8B00">m</font>
    <br>
    <p class="textbig">@little_sharks_mxli</p>
        </p>
    </div>
    <div class="insta">
    <p class="big"> 
        <font color="#FF669D">U</font>
        <font color="#FF685C">b</font>
        <font color="#FF8B00">i</font>
        <font color="#FFD301">c</font>
        <font color="#05B189">a</font>
        <font color="#78CCCC">c</font>
        <font color="#FF669D">i</font>
        <font color="#FF685C">ó</font>
        <font color="#FF8B00">n</font>
    <br>
    <p class="textbig">Calle B #192 Local 2 Col.Segunda Sección</p>
        </p>
        <p class="big"> 
        <font color="#FF669D">C</font>
        <font color="#FF685C">o</font>
        <font color="#FF8B00">r</font>
        <font color="#FFD301">r</font>
        <font color="#05B189">e</font>
        <font color="#78CCCC">o</font>
    <br>
    <p class="textbig">little.sharks.mxli@gmail.com</p>
        </p>
    </div>

    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha3/dist/js/bootstrap.bundle.min.js"></script>
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.6.3/jquery.min.js"></script> 
    
</body>
</html>