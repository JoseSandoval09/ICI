<?php include "../Templates/headerAdmin.html" ?>

    <h1>Gestionar Album</h1>

    <!-- Buscador -->
    <div class="container position-relative mt-5 align-items-center">
        <form action="gAlbum.php" method="get">
            <input type="text" name="busqueda" placeholder="Buscar">
            <input type="submit" name="buscar" value="Ir">
        </form>
        <br>
        <!-- Button trigger modal -->
        <button type="button" class="btn btn-primary" data-bs-toggle="modal" data-bs-target="#nuevoAlbum">
            Crear un album
        </button>
    </div>

    <!--Modal para registrar album-->   

            <!-- Modal -->
    <div class="modal fade" id="nuevoAlbum" tabindex="-1" aria-labelledby="exampleModalLabel" aria-hidden="true">
        <div class="modal-dialog">
            <div class="modal-content">
                <div class="modal-header">
                    <h1 class="modal-title fs-5" id="exampleModalLabel">Insertar cancion</h1>
                    <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Cerrar"></button>
                </div>
                <div class="modal-body">
                    
                <!--form para album-->
                <form action="gAlbum.php" method="post" >
                    <input type="text" name="nombre" placeholder="Nombre">
                    <input type="text" name="anio" placeholder="Año">
                    <input type="text" name="descripcion" placeholder="Descripcion">
                    <input type="submit" name="registrarAlbum" value="nuevoAlbum">
                </form>

                </div>
                    <div class="modal-footer">
                    <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Cerrar</button>
                </div>
            </div>
        </div>
    </div><!--Fin modal-->

<!-- despliega los albums en tarjetas -->
    <div class="container position-relative mt-5 align-items-center">

    <?php
                $enlace = mysqli_connect("localhost", "root", "", "proyectobd");

                if (!$enlace) {
                    echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
                    echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
                    exit;
                }

                $query = "SELECT * FROM album ORDER BY Nombre ASC"; 
                //-----BUSCADOR------
                if(isset($_GET['busqueda']) && isset($_GET['buscar'])){
                    $busqueda = $_GET['busqueda'];
                    if(strlen($busqueda)>0){$query = "SELECT * FROM album WHERE Nombre LIKE '$busqueda'"; }//que no este vacio
                }//fin if
            
                if ($result = $enlace->query($query)){

                        $num_tar = 4;
                        $tar = 0; //cuenta el numero de tarjetas por fila
                        $num_letras_titulo = 25;//el limite de letras del titulo

                    $res_busqueda = false; //comprueba si hay resultado
                    while($r = $result->fetch_assoc()){
                        $id = $r['ID'];
                        $nombre = $r['Nombre'];
                        $anio = $r['Anio'];
                        $src_img = $r['Portada'];
                        $res_busqueda = true;
            
                        if($tar==0){
                            echo '<div class="row mt-2">';
                        }//if solo 4 tarjetas por fila
                        echo '<div class="col-lg-3">';
                            echo '<div class="card cards border-4">';
                                echo '<div class="card-header fw-bold">';

                                //tuve que limitar la longitud de los titulos para resolver el problema 
                                //de la altura de cada tarjeta
                                $nombre_lg = intval(strlen($nombre));
                                    if($nombre_lg>$num_letras_titulo){
                                        for($i=0;$i<$num_letras_titulo;$i++){
                                            echo $nombre[$i];
                                        }//fin for cadena
                                        echo '...';
                                    }//fin if acortar titulos
                                    else{ echo $nombre;}//si es menor

                                echo '</div>';

                                echo '<img src="',$src_img,'" class="card-img-top" alt="music">';

                                echo '<div class="card-body">';

                                    
                                    echo '<h5 class="card-title">',$anio,'</h5>';

                                    // parte de botones para cada tarjeta
                                    echo '<div class="container">';
                                        echo '<div class="row">';
                                            echo '<div class="col">';
                                            echo "<a class='btn btn-primary' href='modAlbum.php?id=$id'>+</a>";
                                            echo '</div>';

                                            echo '<div class="col">';
                                                echo "<form action='gAlbum.php' method='delete'>";
                                                    echo "<input type='hidden' name='id' value='",$r['ID'],"'>";
                                                    echo "<input class='btn btn-danger' type='submit' name='delete' value='Eliminar'>";
                                                echo "</form>";
                                            echo '</div>';

                                        echo '</div>';
                                    echo '</div>';


                                echo '</div>';

                            echo '</div>';
                        echo '</div>';
                        if($tar==$num_tar-1){
                            echo '</div>'; 
                            $tar=0;
                        }//if tarjetas por fila
                        else{ $tar++; }
                    }//fin while filas

                    if($res_busqueda==false){ echo "<p>No se encontraron resultados.</p>"; }

                    if($tar!=$num_tar-1){
                        echo '</div>'; 
                    }
                }//fin query
                mysqli_close($enlace);
            ?>
    </div>

</body>
</html>

<!-- Registrar nuevo album-->
<?php 
  $enlace = mysqli_connect("localhost", "root", "", "proyectobd");

  if (!$enlace) {
      echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
      echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
      exit;
  }

  if(isset($_POST['nombre']) && isset($_POST['anio']) && isset($_POST['descripcion']) && isset($_POST['registrarAlbum'])){
      $nombre = $_POST['nombre'];
      $anio = $_POST['anio']; 
      $descripcion = $_POST['descripcion']; 

      $sql = "INSERT INTO album (Nombre,Anio,Descripcion) VALUES ('$nombre', '$anio','$descripcion')";

      if (!$resultado = $enlace->query($sql)) {
          echo "Lo sentimos, este sitio web está experimentando problemas.";
          exit;
      }

          echo "<p>Album registrado.</p> <script>window.location.href = 'gAlbum.php'</script>";
  }//fin if

  mysqli_close($enlace);

?>


<!--Borrar album-->
<?php
  $enlace = mysqli_connect("localhost", "root", "", "proyectobd");

  if (!$enlace) {
      echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
      echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
      exit;
  }

  if (isset($_GET['delete'])) {
      $id = $_GET['id'];
      $sql = "DELETE FROM album WHERE id = $id";

      if (!$resultado = $enlace->query($sql)) {
          echo "Lo sentimos, este sitio web está experimentando problemas.";
          exit;
      }

      echo "<script>window.location.href = 'gAlbum.php';</script>";
  }

  mysqli_close($enlace);

?>


