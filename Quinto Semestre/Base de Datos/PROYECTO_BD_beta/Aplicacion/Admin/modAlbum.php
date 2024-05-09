<?php include "../Templates/headerAdmin.html" ?>

<!-- informacion del album elegido -->
<div class="container position-relative mt-5 align-items-center">
    <div class="row">
        <!-- Coloca la informacion del album -->
        <?php 
            $enlace = mysqli_connect("localhost", "root", "", "proyectobd");

            if (!$enlace) {
                echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
                echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
                exit;
            }

            if(isset($_GET['id'])){
                $id = $_GET['id'];
                $query = "SELECT * FROM album WHERE ID LIKE $id";
        
                if ($result = $enlace->query($query)){
                    while($r = $result->fetch_assoc()){
                        $nombre = $r['Nombre'];
                        $descripcion = $r['Descripcion'];
                        $img_src = $r['Portada'];
            
                        echo "<div class='col-lg-2'><img src='$img_src' class='card-img-top' alt='music'></div>";

                        echo '<div class="col-lg-8">
                        <form class="form-control form-control-lg" action="modAlbum.php?id=',$id,'" method="post">
                                <div class="col">
                                    <input class="form-control" type="text" name="nombre" placeholder="Nombre" value="',$nombre,'">
                                    <textarea class="form-control" name="descripcion" rows="3" placeholder="Descripcion">',$descripcion,'</textarea>
                                </div>
                                <div class="input-group">
                                    <input type="file" class="form-control" id="formFile" aria-describedby="inputGroupFileAddon04" aria-label="Upload" value="',$img_src,'" name="modPortada">
                                </div>
                                <input class="btn btn-primary" type="submit" name="modificar" value="Modificar">
                            </form>
                                    
                        </div>';
                    }//fin while filas
                }//fin query

            }//fin if isset
        
            
            mysqli_close($enlace);
        ?>
    </div>

    <div class="container position-relative mt-5 align-items-center">
                <br>
                <div class="container-lg-8 overflow-y-auto align-items-center">
                    <table class="table">
                        <thead>
                            <tr>
                            <th scope="col">Titulo</th>
                            <th scope="col">Artista</th>
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

                                if(isset($_GET['id'])){
                                    $id_album = $_GET['id'];

                                    $query = "SELECT canciones.*
                                    FROM canciones
                                    JOIN cancionesxalbum ON canciones.id = cancionesxalbum.FKIDCancion
                                    WHERE cancionesxalbum.FKIDAlbum = '$id_album';";

                                    if ($result = $enlace->query($query)){
                                        while($r = $result->fetch_assoc()){
                                            $id = $r['ID'];
                                            $nombre = $r['Nombre'];
                                            $dMin = $r['DuracionMin'];
                                            $dSeg = $r['DuracionSeg'];

                                            //buscar artistas en las canciones
                                            $artistas = 'Desconocido';
                                            $q_artista = "SELECT artistas.*
                                            FROM artistas
                                            JOIN artistasxcancion ON artistas.ID = artistasxcancion.FKIDArtista
                                            WHERE artistasxcancion.FKIDCancion = '$id'";
        
                                            if ($r_art = $enlace->query($q_artista)){
                                                $artistas = '';
                                                while($r_artista = $r_art->fetch_assoc()){
                                                    $artistas = $r_artista['Nombre'].' , '.$artistas;
                                                }//fin while
                                                $artistas = substr($artistas,0,-2);
                                            }//fin if buscar artistas en cancion
    
                                            echo '<tr>';
                                            echo '<th scope="row">',$nombre,'</th>';
                                            echo '<td>',$artistas,'</td>';
                                            echo '<td>',$dMin,':',$dSeg,'</td>';
    
                                            echo '<td>';
                                                    //al momento de dirigirse a la pagina siempre este disponible el id del album
                                                    if(isset($_GET['id'])){
                                                        $id_album = $_GET['id'];
                                                        echo "<form action='modAlbum.php?id=$id_album' method='post'>";
                                                    }
                                                echo "<input type='hidden' name='id' value='",$r['ID'],"'>";
                                                echo "<input class='btn btn-danger ms-3' type='submit' name='eliminar_cancion' value='Quitar'>";
                                                echo "</form>";
                                            echo '</td>';
    
                                            echo '</tr>';
                                        }//fin while filas
                                    }
                                }//fin if get id
                                    mysqli_close($enlace);
                            ?>
                        </tbody>
                    </table>
                </div>
    </div>

    <!-- Apartado para anadir canciones-->
    <div class="container position-relative mt-5 align-items-center">
        <h3>Canciones de la biblioteca</h3>
        <br>
            <!--form para buscador-->
            <?php
            //al momento de dirigirse a la pagina siempre este disponible el id del album
                if(isset($_GET['id'])){
                    $id = $_GET['id'];
                    echo "<form action='modAlbum.php?id=$id' method='post'>";
                }
            ?>
                <input type="text" name="busqueda" placeholder="Buscar">
                <input type="submit" name="buscar" value="Ir">
            </form>
                <br>
                <div class="container-lg-8 overflow-y-auto align-items-center">
                    <table class="table">
                        <thead>
                            <tr>
                            <th scope="col">Titulo</th>
                            <th scope="col">Artista</th>
                            <th scope="col">Duracion</th>
                            </tr>
                        </thead>
                        <tbody>
                            <!--Muestra canciones en la biblioteca-->
                            <?php 
                                $enlace = mysqli_connect("localhost", "root", "", "proyectobd");

                                if (!$enlace) {
                                    echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
                                    echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
                                    exit;
                                }

                                if(isset($_GET['id'])){

                                    $id_album = $_GET['id'];
                                    $query = "SELECT canciones.*
                                    FROM canciones
                                    LEFT JOIN cancionesxalbum ON canciones.ID = cancionesxalbum.FKIDCancion AND cancionesxalbum.FKIDAlbum = $id_album WHERE cancionesxalbum.FKIDCancion IS NULL ORDER BY Nombre ASC"; 

                                    //$id es el id del album en este fragmento
                                    //-----BUSCADOR------
                                    if(isset($_POST['busqueda']) && isset($_POST['buscar'])){
                                        $busqueda = $_POST['busqueda'];
                                        if(strlen($busqueda)>0){$query = "SELECT * FROM canciones WHERE Nombre LIKE '$busqueda' AND NOT EXISTS (
                                            SELECT 1
                                            FROM cancionesxalbum
                                            WHERE cancionesxalbum.FKIDCancion = canciones.ID
                                            AND cancionesxalbum.FKIDAlbum = $id_album
                                        )"; }//que no este vacio
                                    }//fin if

                                    if ($result = $enlace->query($query)){
                                        while($r = $result->fetch_assoc()){
                                            $id = $r['ID'];
                                            $nombre = $r['Nombre'];
                                            $dMin = $r['DuracionMin'];
                                            $dSeg = $r['DuracionSeg'];

                                            //buscar artistas en las canciones
                                            $artistas = 'Desconocido';
                                            $q_artista = "SELECT artistas.*
                                            FROM artistas
                                            JOIN artistasxcancion ON artistas.ID = artistasxcancion.FKIDArtista
                                            WHERE artistasxcancion.FKIDCancion = '$id'";
        
                                            if ($r_art = $enlace->query($q_artista)){
                                                $artistas = '';
                                                while($r_artista = $r_art->fetch_assoc()){
                                                    $artistas = $r_artista['Nombre'].' , '.$artistas;
                                                }//fin while
                                                $artistas = substr($artistas,0,-2);
                                            }//fin if buscar artistas en cancion

                                            echo '<tr>';
                                            echo '<th scope="row">',$nombre,'</th>';
                                            echo '<td>',$artistas,'</td>';
                                            echo '<td>',$dMin,':',$dSeg,'</td>';

                                            echo '<td>';
                                                    //al momento de dirigirse a la pagina siempre este disponible el id del album
                                                    if(isset($_GET['id'])){
                                                        $id_album = $_GET['id'];
                                                        echo "<form action='modAlbum.php?id=$id_album' method='post'>";
                                                    }
                                                echo "<input type='hidden' name='id' value='",$r['ID'],"'>";
                                                echo "<input class='btn btn-primary ms-3' type='submit' name='anadir' value='Añadir'>";
                                                echo "</form>";
                                            echo '</td>';

                                            echo '</tr>';
                                        }//fin while filas
                                    }
                                }
                                mysqli_close($enlace);
                            ?>
                        </tbody>
                    </table>
                </div>
    </div>
</div>

</body>
</html>


<!--Modificar album-->
<?php
  $enlace = mysqli_connect("localhost", "root", "", "proyectobd");

  if (!$enlace) {
      echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
      echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
      exit;
  }
  
  if (isset($_GET['id']) && isset($_POST['modificar']) && isset($_POST['nombre']) && isset($_POST['descripcion']) && isset($_POST['modPortada'])) {
    $id = $_GET['id'];
    $nombre = $_POST['nombre'];
    $descripcion= $_POST['descripcion'];
    $portada = $_POST['modPortada'];

    //agregamos la extension de Source
    if(strlen($portada)==0){ 
        $q_portada = "SELECT * FROM album WHERE ID LIKE $id";
        if ($result = $enlace->query($q_portada)){
            while($rp = $result->fetch_assoc()){
                $portada = $rp['Portada'];
            }//fin while
        }//fin if consulta portada
    }//si no se elige otro archivo
    else{ $portada = '../Source/Portadas/'.$portada; }

      $sql = "UPDATE album SET Nombre = '$nombre', Descripcion = '$descripcion', Portada = '$portada' WHERE ID = $id";
  
      if (!$resultado = $enlace->query($sql)) {
          echo "Lo sentimos, este sitio web está experimentando problemas.";
          exit;
      }
  
      echo "<script>window.location.href = 'modAlbum.php?id=$id';</script>";
  
  }
  
  mysqli_close($enlace);
?>

<!--Insertar canciones en album-->
<?php

$enlace = mysqli_connect("localhost", "root", "", "proyectobd");

    if (!$enlace) {
        echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
        echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
        exit;
    }

    if (isset($_POST['anadir']) && isset($_GET['id'])) {
        $id = $_POST['id']; //id de la cancion 
        $id_album = $_GET['id']; //id del album
        $nombre_cancion;
        $nombre_album;

        //obtener nombre del album
        $query = "SELECT * FROM album WHERE ID LIKE '$id_album'"; 
        if ($result = $enlace->query($query)){
            while($r = $result->fetch_assoc()){
                $nombre_album = $r['Nombre'];
            }//fin while 
        }

        //obtener nombre del cancion
        $query = "SELECT * FROM canciones WHERE ID LIKE '$id'"; 
        if ($result = $enlace->query($query)){
            while($r = $result->fetch_assoc()){
                $nombre_cancion = $r['Nombre'];
            }//fin while 
        }

        $sql = "INSERT INTO cancionesxalbum (FKIDAlbum,NombreAlbum,FKIDCancion,NombreCancion) VALUES ('$id_album','$nombre_album','$id','$nombre_cancion')";

        if (!$resultado = $enlace->query($sql)) {
            echo "Lo sentimos, este sitio web está experimentando problemas.";
            exit;
        }

        echo "<script>window.location.href = 'modAlbum.php?id=$id_album';</script>";
    }
    mysqli_close($enlace);
?>

<!-- Quitar cancion del album -->
<?php
  $enlace = mysqli_connect("localhost", "root", "", "proyectobd");

  if (!$enlace) {
      echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
      echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
      exit;
  }

  if (isset($_POST['eliminar_cancion']) && isset($_GET['id'])) {
      $id = $_POST['id'];
      $id_album = $_GET['id'];
      $sql = "DELETE FROM cancionesxalbum WHERE FKIDCancion = $id AND FKIDAlbum = $id_album";

      if (!$resultado = $enlace->query($sql)) {
          echo "Lo sentimos, este sitio web está experimentando problemas.";
          exit;
      }

      echo "<script>window.location.href = 'modAlbum.php?id=$id_album';</script>";
  }

  mysqli_close($enlace);

?>