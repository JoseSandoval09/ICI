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
<br><br><br><br>
<div class="pacientes">  
<p class="big">
    <font color="#FF669D">P</font>
    <font color="#FF685C">A</font>
    <font color="#FF8B00">C</font>
    <font color="#FFD301">I</font>
    <font color="#05B189">E</font>
    <font color="#78CCCC">N</font>
    <font color="#FF669D">T</font>
    <font color="#FF685C">E</font>
    <font color="#FF8B00">S&nbsp;</font>
    <font color="#FFD301">&nbsp;R</font>
    <font color="#05B189">E</font>
    <font color="#78CCCC">G</font>
    <font color="#FF669D">I</font>
    <font color="#FF685C">S</font>
    <font color="#FF8B00">T</font>
    <font color="#FFD301">R</font>
    <font color="#05B189">A</font>
    <font color="#78CCCC">D</font>
    <font color="#FF669D">O</font>
    <font color="#FF685C">S</font>
</p>
</div>
<div class="tabla">
            <table class="table table-striped-columns">
                <br>
                    <tbody>
                        <tr>
                            <th scope="col"> ID</th> 
                            <th scope="col"> BEBÉ</th> 
                            <th scope="col"> FECHA DE NACIMIENTO</th>
                            <th scope="col"> TUTOR </th>
                            <th scope="col"> TELÉFONO </th>
                            <th scope="col"> DIRECCIÓN </th>
                            <th scope="col"> ALERGIAS </th>
                            <th scope="col"> TRATAMIENTO MÉDICO </th>
                            <th scope="col"> OTRO CENTRO DE ESTIMULACIÓN </th>
                            <th scope="col"> OBJETIVO </th>
                        </tr>
                        <?php
                            $link = mysqli_connect('localhost', 'root', '' , 'little');
                            if (!$link) {
                                echo ('Could not connect: ' . mysqli_connect_error());
                                
                            }else{
                                $query = "SELECT * FROM pacientes";
                                if($result = mysqli_query($link,$query)){
                                    $rows = $result->num_rows;
                                    for($j=1;$j<=$rows;$j++){
                                        $fila = mysqli_fetch_array($result);
                                        echo"<tr>";
                                        for($i=0;$i<14;$i++){
                                                if($i==0){
                                                    echo "<td>$fila[0]</td>";//ID
                                                }
                                                if($i==1){
                                                    echo "<td>$fila[1]</td>";//bebe
                                                }
                                                if($i==2){
                                                    echo "<td>$fila[2]</td>";//fecha
                                                }
                                                if($i==3){
                                                    echo "<td>$fila[3]</td>";//tutor
                                                }
                                                if($i==4){
                                                    echo "<td>$fila[4]</td>";//telefono
                                                }
                                                if($i==5){
                                                    echo "<td>$fila[5]</td>";//direccion
                                                }
                                                if($i==7){
                                                    echo "<td>$fila[7]</td>";//alergias
                                                }
                                                if($i==9){
                                                    echo "<td>$fila[9]</td>";//tratamiento
                                                }
                                                if($i==11){
                                                    echo "<td>$fila[11]</td>";//otro
                                                }
                                                if($i==13){
                                                    if($fila[13]==1){
                                                        echo "<td>Recreativo</td>";//objetivo
                                                    }
                                                    if($fila[13]==2){
                                                        echo "<td>Aprendizaje</td>";//objetivo
                                                    }
                                                    if($fila[13]==3){
                                                        echo "<td>Estimulación</td>";//objetivo
                                                    }
                                                }
                                        }
                                    echo"</tr>";
                                    }
                                 }
                             }
                            mysqli_close($link);
                        ?>
                    </tbody>
        </table>
</div>
<br><br>
<div class="editar">
<br>
    <div class="eliminar">
    <p class="title">
        <font color="#FF669D">E</font>
        <font color="#FF685C">l</font>
        <font color="#FF8B00">i</font>
        <font color="#FFD301">m</font>
        <font color="#05B189">i</font>
        <font color="#78CCCC">n</font>
        <font color="#FF669D">a</font>
        <font color="#FF685C">r</font>
    </p>
    <p class="textbig">
        Ingresa el ID del usuario que deseas eliminar:
        <input class="form-control" name="IDeliminar" type="number">
    </p>
    <button type="button" class="boton" style="background-color: rgb(255,104,92)" name="eliminar" value="true">&nbsp; Eliminar &nbsp;</button>
    </div>

    <div class="modificar">
    <p class="title">
        <font color="#FF669D">M</font>
        <font color="#FF685C">o</font>
        <font color="#FF8B00">d</font>
        <font color="#FFD301">i</font>
        <font color="#05B189">f</font>
        <font color="#78CCCC">i</font>
        <font color="#FF669D">c</font>
        <font color="#FF685C">a</font>
        <font color="#FF8B00">r</font>
    </p>
    <p class="textbig">
        Ingresa el ID del usuario que deseas modificar:
        <input class="form-control" name="IDmod" type="number">
    </p>
    <button type="button" class="boton" style="background-color: rgb(255,104,92)" name="modificar" value="true">&nbsp; Modificar &nbsp;</button>
    </div>
</div>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha3/dist/js/bootstrap.bundle.min.js"></script>
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.6.3/jquery.min.js"></script> 
    <?php
        $eliminar =!empty($_POST['eliminar']) ? $_POST['eliminar'] : null; //eliminar
        if($eliminar){
            $conn = mysqli_connect('localhost', 'root', '' , 'little');
        if (!$conn) {
            echo ('Could not connect: ' . mysqli_connect_error());
            
        }else{
           // get the post records
           $IDeliminar =!empty($_POST['IDeliminar']) ? $_POST['IDeliminar'] : null; //eliminar
                if($IDeliminar){
                    $sql = "DELETE FROM pacientes WHERE ID= $IDeliminar";
                    if ($conn->query($sql) === TRUE) {
                        echo "Eliminado correctamente";
                      } else {
                        echo "Error: " . $conn->error;
                      }
                }else{
                    echo '<script>alert("El ID ingresado no es valido")</script>';
                }
        }
        echo 'Connected successfully';
        echo "Informacion del host " .mysqli_get_host_info($conn). PHP_EOL;
        $conn->close();
        }
    ?>
    
</body>
</html>