<?php include "../Templates/headerAdmin.html" ?>

<h1>Gestionar Artistas</h1>

<!-- Buscador -->
<div class="container position-relative mt-5 align-items-center">
        <form action="gArtistas.php" method="post">
            <input type="text" name="busqueda" placeholder="Buscar">
            <input type="submit" name="buscar" value="Ir">
        </form>
        <br>
        <!-- Button trigger modal -->
        <button type="button" class="btn btn-primary" data-bs-toggle="modal" data-bs-target="#nuevoArtista">
            Registrar Artista
        </button>
</div>
    <!--Modal para registrar artista-->   
    <!-- Modal -->
    <div class="modal fade" id="nuevoArtista" tabindex="-1" aria-labelledby="exampleModalLabel" aria-hidden="true">
        <div class="modal-dialog">
            <div class="modal-content">
                <div class="modal-header">
                    <h1 class="modal-title fs-5" id="exampleModalLabel">Ingresar artista</h1>
                    <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Cerrar"></button>
                </div>
                <div class="modal-body">
                    
                    <!--form para artista-->
                    <form action="gArtistas.php" method="post" >
                          <input type="text" name="nombre" placeholder="Nombre">
                          <input type="text" name="nac_ano" placeholder="NacAno">
                          <input type="text" name="nac_mes" placeholder="NacMes">
                          <input type="text" name="nac_dia" placeholder="NacDia">

                            <!--Lista de paises-->
                            <select class="form-select" aria-label="Default select example" name="pais">
                              <option selected>Pais</option>
                              <div class="overflow-y-auto">
                              <?php
                                $enlace = mysqli_connect("localhost", "root", "", "proyectobd");

                                if (!$enlace) {
                                    echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
                                    echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
                                    exit;
                                }
                            
                                $query = "SELECT * FROM pais";
                            
                                if ($result = $enlace->query($query)){
                                    while($r = $result->fetch_assoc()){
                                        $id = $r['ID'];
                                        $nombre = $r['Nombre'];
                                        echo '<option value=',$id,'>',$nombre,'</option>';
                                    }//fin while opciones
                                }
                                mysqli_close($enlace);
                              ?>
                            </div>
                            </select>
                          
                          <input type="submit" name="registrarArtista" value="nuevoArtista">

                </div>
                    <div class="modal-footer">
                    <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Cerrar</button>
                </div>
            </div>
        </div>
    </div><!--Fin modal-->

    <!-- Mostrar artistas registrados -->
<div class="container position-relative mt-5 align-items-center">
                <br>
                <div class="container-lg-8 overflow-y-auto align-items-center">
                    <table class="table table-hover">
                        <thead>
                            <tr>
                            <th scope="col">Nombre</th>
                            <th scope="col">Nacimiento</th>
                            <th scope="col">Pais</th>
                            </tr>
                        </thead>
                        <tbody>
                            <!--Muestra canciones en el album-->
                            <?php 
                                $enlace = mysqli_connect("localhost", "root", "", "proyectobd");

                                if (!$enlace) {
                                    echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
                                    echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
                                    exit;
                                }

                                $query = "SELECT * FROM artistas";
                                //-----BUSCADOR------
                                if(isset($_POST['busqueda']) && isset($_POST['buscar'])){
                                    $busqueda = $_POST['busqueda'];
                                    if(strlen($busqueda)>0){$query = "SELECT * FROM artistas WHERE Nombre LIKE '$busqueda'"; }//que no este vacio
                                }//fin if

                                    if ($result = $enlace->query($query)){
                                        while($r = $result->fetch_assoc()){
                                            $id = $r['ID'];
                                            $nombre = $r['Nombre'];
                                            $nAno = $r['NacAno'];
                                            $nMes = $r['NacMes'];
                                            $nDia = $r['NacDia'];
                                            $id_pais = $r['FKIDPais'];
                                            $pais;
                                            //que se te ocurra como obtener el nombre del pais

                                            //query para obtener pais
                                            $q_pais = "SELECT * FROM pais WHERE ID = '$id_pais'";
                                            if ($res_pais = $enlace->query($q_pais)){
                                                while($rp = $res_pais->fetch_assoc()){
                                                    $pais = $rp['Nombre'];
                                                }//fin while pais
                                            }//fin if pais

    
                                            echo '<tr>';
                                            echo '<th scope="row">',$nombre,'</th>';
                                            echo '<td>',"$nDia/$nMes/$nAno",'</td>';
                                            echo '<td>',$pais,'</td>';
    
                                            echo '<td>';
                                                echo "<form action='gArtistas.php' method='post'>";
                                                echo "<input type='hidden' name='id' value='",$r['ID'],"'>";
                                                echo "<button><a href='modArtista.php?id=","$id","'>*</a></button>";
                                                echo "<input class='btn btn-danger ms-3' type='submit' name='eliminar' value='Eliminar'>";
                                                echo "</form>";
                                            echo '</td>';
    
                                            echo '</tr>';
                                        }//fin while filas
                                    }
                                    mysqli_close($enlace);
                            ?>
                        </tbody>
                    </table>
                </div>
    </div>

</body>
</html>


<!-- Registrar un nuevo artista-->
<?php 
  $enlace = mysqli_connect("localhost", "root", "", "proyectobd");

  if (!$enlace) {
      echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
      echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
      exit;
  }

  if(isset($_POST['nombre']) && isset($_POST['nac_ano']) && isset($_POST['nac_mes']) && isset($_POST['nac_dia']) && isset($_POST['pais']) && isset($_POST['registrarArtista'])){
      $nombre = $_POST['nombre'];
      $nacAno = $_POST['nac_ano']; 
      $nacMes = $_POST['nac_mes'];
      $nacDia = $_POST['nac_dia'];
      $pais = $_POST['pais'];
      $fecha = false;

      //comprueba fecha

      switch($nacMes){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
          if($nacDia>=1 && $nacDia<=31){
            $fecha = true;
          }//fin if
          break;
        case 4:
        case 6:
        case 9:
        case 11:
          if($nacDia>=1 && $nacDia<=30){
            $fecha = true;
          }//fin if
          break;
        case 2:
          if($nacAno%4!=0){
            if($nacDia>=1 && $nacDia<=28){
              $fecha = true;
            }//fin if  
          }//fin if ano
          else{
            if($nacDia>=1 && $nacDia<=29){
              $fecha = true;
            }//fin if 
          }
          break;
      }

          if($fecha == true){
              
              $sql = "INSERT INTO artistas (Nombre,nacAno,nacMes,nacDia,FKIDPais) VALUES ('$nombre', '$nacAno','$nacMes','$nacDia',$pais)";

              if (!$resultado = $enlace->query($sql)) {
                  echo "Lo sentimos, este sitio web está experimentando problemas.";
                  exit;
              }

              echo "<script>window.location.href = 'gArtistas.php';</script>";
          }//fin if correcto
          else{
            echo '<p>La fecha ingresada no es valida.</p>';
          }
      }//fin if

  mysqli_close($enlace);

?>

<!--Borrar artista-->
<?php
  $enlace = mysqli_connect("localhost", "root", "", "proyectobd");

  if (!$enlace) {
      echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
      echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
      exit;
  }

  if (isset($_POST['eliminar'])) {
      $id = $_POST['id'];

      $query = "SELECT * FROM artistasxcancion WHERE FKIDArtista LIKE $id";

      $tiene_canciones = false;
    if ($result = $enlace->query($query)){
        while($r = $result->fetch_assoc()){
            $tiene_canciones = true;
        }
    }//fin buscar si no tiene canciones


    if($tiene_canciones==false){
        $sql = "DELETE FROM artistas WHERE id = $id";

        if (!$resultado = $enlace->query($sql)) {
            echo "Lo sentimos, este sitio web está experimentando problemas.";
            exit;
        }

        echo "<script>window.location.href = 'gArtistas.php';</script>";
    }//no tiene canciones
    else{ echo "El artista no debe estar incluido en canciones para poder ser eliminado"; }

  }

  mysqli_close($enlace);

?>