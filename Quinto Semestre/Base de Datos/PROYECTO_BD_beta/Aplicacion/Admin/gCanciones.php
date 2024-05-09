<?php include "../Templates/headerAdmin.html" ?>

<div class="container position-relative mt-5 align-items-center">
    <!--Modal para registrar cancion-->   
        <!-- Button trigger modal -->
        <button type="button" class="btn btn-primary" data-bs-toggle="modal" data-bs-target="#nuevaCancion">
            Ingresar una cancion
        </button>

        <!-- Modal -->
            <div class="modal fade" id="nuevaCancion" tabindex="-1" aria-labelledby="exampleModalLabel" aria-hidden="true">
                <div class="modal-dialog">
                    <div class="modal-content">
                        <div class="modal-header">
                        <h1 class="modal-title fs-5" id="exampleModalLabel">Insertar cancion</h1>
                        <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Cerrar"></button>
                    </div>
                    <div class="modal-body">
                       <!--form para cancion-->
                        <form action="gCanciones.php" method="post" >
                            <input type="text" name="nombre" placeholder="Nombre">
                            <input type="text" name="dMin" placeholder="00">
                            <input type="text" name="dSeg" placeholder="00">
                            <input type="textarea" name="letra" placeholder="Ingrese letra de la cancion">
                            <input type="submit" name="registrarCancion" value="nuevaCancion">
                        </form>
                    </div>
                    <div class="modal-footer">
                      <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Cerrar</button>
                    </div>
                </div>
            </div>   
</div>

<div class="container position-relative mt-5 align-items-center">
    <h2>Canciones en la bibliteca</h2>
    <div class="container-lg-8 overflow-y-auto align-items-center">
        <table class="table">
            <thead>
                <tr>
                    <th scope="col">Titulo</th>
                    <th scope="col">Duracion</th>
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

                    $query = "SELECT * FROM canciones ORDER BY Nombre ASC";

                        if ($result = $enlace->query($query)){
                            while($r = $result->fetch_assoc()){
                                $id = $r['ID'];
                                $nombre = $r['Nombre'];
                                $dMin = $r['DuracionMin'];
                                $dSeg = $r['DuracionSeg'];
                                $disponibilidad = $r['Disponibilidad'];
                                
                                echo '<tr>';
                                    echo '<th scope="row">',$nombre,'</th>';
                                        echo '<td>',$dMin,':',$dSeg,'</td>';
                                        echo '<td>';
                                            //al momento de dirigirse a la pagina siempre este disponible el id del album
                                            echo "<form action='gCanciones.php' method='post'>";
                                            echo "<a class='btn btn-light' href='modCanciones.php?id=","$id","'>*</a>";
                                            echo "<input type='hidden' name='id' value='",$r['ID'],"'>";
                                            echo "<input type='hidden' name='disponibilidad' value='",$disponibilidad,"'>";
                                            if($disponibilidad==0){ echo "<input class='btn btn-danger ms-3' type='submit' name='c_disponibilidad' value='No disponible'>"; }
                                            else{ echo "<input class='btn btn-primary ms-3' type='submit' name='c_disponibilidad' value='Disponible'>";}
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


<!-- Registrar nueva cancion-->
<?php 
  $enlace = mysqli_connect("localhost", "root", "", "proyectobd");

  if (!$enlace) {
      echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
      echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
      exit;
  }

  if(isset($_POST['nombre']) && isset($_POST['dMin']) && isset($_POST['dSeg']) && isset($_POST['letra']) && isset($_POST['registrarCancion'])){
      $nombre = $_POST['nombre'];
      $dMin = $_POST['dMin']; 
      $dSeg = $_POST['dSeg']; 
      $letra = $_POST['letra'];
      $duracion_ok = false;

      if($dMin<60 && $dMin>=0){
        if($dMin==0){
          if($dSeg>0 && $dSeg<60){ $duracion_ok = true; }
        }//fin if minuto = 0
        else if($dSeg>=0 && $dSeg<60){ $duracion_ok = true; }

      }//fin if minuto

          if($duracion_ok == true){
              
              $sql = "INSERT INTO canciones (Nombre,DuracionMin,DuracionSeg,Letra) VALUES ('$nombre', '$dMin','$dSeg','$letra')";

              if (!$resultado = $enlace->query($sql)) {
                  echo "Lo sentimos, este sitio web está experimentando problemas.";
                  exit;
              }

          }//fin if correcto
          else{
            echo "<script>window.location.href = 'gCanciones.php';</script>";
          }
    }//fin if isset

  mysqli_close($enlace);

?>


<!--Modificar disponibilidad de cancion-->
<?php
  $enlace = mysqli_connect("localhost", "root", "", "proyectobd");

  if (!$enlace) {
      echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
      echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
      exit;
  }
  
  if (isset($_POST['id']) && isset($_POST['c_disponibilidad'])) {
    $id = $_POST['id'];
    $disponibilidad = $_POST['disponibilidad'];

    if($disponibilidad==0){ $disponibilidad=1; }
    else{ $disponibilidad=0; }

      $sql = "UPDATE canciones SET Disponibilidad = '$disponibilidad' WHERE ID = $id";
  
      if (!$resultado = $enlace->query($sql)) {
          echo "Lo sentimos, este sitio web está experimentando problemas.";
          exit;
      }
  
      echo "<script>window.location.href = 'gCanciones.php';</script>";
  
  }
  
  mysqli_close($enlace);
?>
