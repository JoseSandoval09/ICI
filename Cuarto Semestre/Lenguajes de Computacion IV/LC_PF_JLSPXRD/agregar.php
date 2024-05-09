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
    <img src="little.png" width="300" height="300">
</div>
    <div class="conteiner">
    <p class="title">FORMATO DE INSCRIPCIÓN<p>
    <div class="datos">
        <form class="row g-2" method="post">
            <p class="subtitle"> Datos personales</p> 

            <div class="col-md-8">
            <label class="form-label"> Nombre del bebé: </label>
            <input class="form-control" name="nameB" type="text">
            </div>

            <div class="col-md-3">
            <label class="form-label">&nbsp; Fecha de nacimiento: </label>
            <input class="form-control" name="birthD" type="date">
            </div>
            <div class="col-md-8">
            <label class="form-label">Nombre del papá o tutor: </label>
            <input class="form-control" name="nameD" type="text">
            </div>
            <div class="col-md-3">
            <label class="form-label">&nbsp; Teléfono de contacto: </label>
            <input class="form-control" name="phone" type="tel">
            </div>
            <div class="col-md-10">
            <label class="form-label">Dirección: </label>
            <input class="form-control"  name="adress" type="text">
            <br><br><br></div>
            
            <p class="subtitle"> Datos necesarios para el fisioterapeuta </p>
            <div class="col-md-5">
            <label class="form-label">¿Es alérgico/a? : &nbsp;</label>
                <select class="form-select form-select-sm" aria-label=".form-select-lg example" name="alergies">
                    <option selected>Selecciona una opción</option>
                    <option value="1"> Sí </option>
                    <option value="2"> No </option>
                </select>
            </div>
            <div class="col-md-8"> <label class="form-label">¿A qué? : &nbsp;</label>
            <input class="form-control"  name="alergiesW"  type="text"> <br></div>


            <div class="col-md-8">
            <label class="form-label">¿Se encuentra en tratamiento médico? : &nbsp;</label>
               <select class="form-select form-select-sm" aria-label=".form-select-lg example" name="treat">
                    <option selected>Selecciona una opción</option>
                    <option value="1"> Sí </option>
                    <option value="2"> No </option>
                </select>
            </div>
            <div class="col-md-6"><label class="form-label">Específique, por favor :  &nbsp;</label>
            <input class="form-control"  name="treatW" type="text">
            <br></div>
            

            <div class="col-md-8">
            <label class="form-label">¿Actualmente acude a otro centro de estímulación? : &nbsp;</label>
                <select class="form-select form-select-sm" aria-label=".form-select-lg example" name="other">
                    <option selected>Selecciona una opción</option>
                    <option value="1"> Sí </option>
                    <option value="2"> No </option>
                </select>
            </div>
            <div class="col-md-6"><label class="form-label">¿A cuál? : &nbsp;</label>
            <input class="form-control" name="otherW" type="text"> 
            <br></div>
           
            <div class="col-md-10">
            <label class="form-label">¿Ha acudido anteriormente a algún centro de estimulación o clases de natación? : &nbsp;</label>
                <select class="form-select form-select-sm" aria-label=".form-select-lg example" name="otherC">
                    <option selected>Selecciona una opción</option>
                    <option value="1"> Sí </option>
                    <option value="2"> No </option>
                </select>
                <br></div>
            <br><br>
            <div class="col-md-8">
            <label class="form-label">¿Qué objetivo busca en Little Sharks? : &nbsp;</label>
            <select name="objective">
                    <option selected>Selecciona una opción</option>
                    <option value="1"> Recreativo  </option>
                    <option value="2"> Aprendizaje </option>
                    <option value="3"> Estimulación </option>
                </select>
            <br>
            </div>
            <br> <br> <br>
            <div class="col-md-10"> <input type="checkbox" required>
            <label class="form-check-label" for="validCheck3">
            Aceptar términos y condiciones
            </label></div>

            <button type="submit" class="enviar" name="subir" value="true">Enviar</button>
        </form>
        </div>
    </div>
            <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha3/dist/js/bootstrap.bundle.min.js"></script>
            <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.6.3/jquery.min.js"></script> 
        <?php
        $subir =!empty($_POST['subir']) ? $_POST['subir'] : null; //subir
        if($subir){
            $link = mysqli_connect('localhost', 'root', '' , 'little');
        if (!$link) {
            echo ('Could not connect: ' . mysqli_connect_error());
            
        }else{
           // get the post records
           $nameB =!empty($_POST['nameB']) ? $_POST['nameB'] : null; //namebebe
           $birthD = !empty($_POST['birthD']) ? $_POST['birthD']:null; //datebday
           $nameD = !empty($_POST['nameD']) ? $_POST['nameD']:null; //namedad
           $phone = !empty($_POST['phone']) ? $_POST['phone']:null; //tel
           $adress = !empty($_POST['adress']) ? $_POST['adress']:null; //dire
           $alergies = !empty($_POST['alergies']) ? $_POST['alergies']:null; //alerg
           $alergiesW = !empty($_POST['alergiesW']) ? $_POST['alergiesW']:null; //alergW
           $treat = !empty($_POST['treat']) ? $_POST['treat']:null; //medicT
           $treatW = !empty($_POST['treatW']) ? $_POST['treatW']:null; //medicTW
           $other = !empty($_POST['other']) ? $_POST['other']:null; //center
           $otherW = !empty($_POST['otherW']) ? $_POST['otherW']:null; //centerW
           $otherC = !empty($_POST['otherC']) ? $_POST['otherC']:null; //acenter
           $objective = !empty($_POST['objective']) ? $_POST['objective']:null; //obje
   
                if($nameB){
                    // database insert SQL code
                    $sql = "INSERT INTO pacientes(namebebe, datebday, namedad, tel, dire, alerg, alergW, medicT, medicTW, center, centerW, acenter, obje) VALUES ('$nameB', '$birthD', '$nameD', '$phone', ' $adress', '$alergies', '$alergiesW', '$treat', '$treatW', '$other', '$otherW', '$otherC', '$objective')";
                    // insert in database 
                    mysqli_query($link,$sql);
                    echo "listo";
                }
                
        }
        echo 'Connected successfully';
        echo "Informacion del host " .mysqli_get_host_info($link). PHP_EOL;
        mysqli_close($link);
        }
        ?>
</body>
</html>