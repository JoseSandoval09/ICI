<?php include "../Templates/headerUser.html" ?>


<!-- informacion de PLAYLIST elegido -->
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

            if(isset($_GET['pl'])){
                $id = $_GET['pl'];
                $query = "SELECT * FROM playlist WHERE ID LIKE $id";
        
                if ($result = $enlace->query($query)){
                    while($r = $result->fetch_assoc()){
                        $nombre = $r['Nombre'];
                        $descripcion = $r['Descripcion'];
            
                        echo "<div class='col-lg-2'><img src='../Source/Portadas/default.png' class='card-img-top' alt='music'></div>";

                        echo '<div class="col-lg-8">
                        <form class="form-control form-control-lg" action="modPlaylist.php?pl=',$id,'" method="post">
                                <div class="col">
                                    <input class="form-control" type="text" name="nombre" placeholder="Nombre" value="',$nombre,'">
                                    <textarea class="form-control" name="descripcion" rows="3" placeholder="Descripcion">',$descripcion,'</textarea>
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
                <h2>Canciones en la playlist</h2>
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

                                if(isset($_GET['pl'])){
                                    $id_playlist = $_GET['pl'];

                                    $query = "SELECT canciones.*
                                    FROM canciones
                                    JOIN cancionesxplaylist ON canciones.id = cancionesxplaylist.FKIDCancion
                                    WHERE cancionesxplaylist.FKIDPlaylist = '$id_playlist';";

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
                                            echo '<th scope="row"><a href="verCancion.php?id=',$id,'">',$nombre,'</a></th>';
                                            echo '<td>',$artistas,'</td>';
                                            echo '<td>',$dMin,':',$dSeg,'</td>';
    
                                            echo '<td>';
                                                    //al momento de dirigirse a la pagina siempre este disponible el id del album
                                                    if(isset($_GET['pl'])){
                                                        $id_playlist = $_GET['pl'];
                                                        echo "<form action='modPlaylist.php?pl=$id_playlist' method='post'>";
                                                    }
                                                echo "<input type='hidden' name='id' value='",$id,"'>";
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
                if(isset($_GET['pl'])){
                    $id = $_GET['pl'];
                    echo "<form action='modPlaylist.php?pl=$id' method='post'>";
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

                                if(isset($_GET['pl'])){

                                    $id_playlist = $_GET['pl'];
                                    $query = "SELECT canciones.*
                                    FROM canciones
                                    LEFT JOIN cancionesxplaylist ON canciones.ID = cancionesxplaylist.FKIDCancion AND cancionesxplaylist.FKIDPlaylist = $id_playlist WHERE cancionesxplaylist.FKIDCancion IS NULL ORDER BY Nombre ASC"; 

                                    //$id es el id del album en este fragmento
                                    //-----BUSCADOR------
                                    if(isset($_POST['busqueda']) && isset($_POST['buscar'])){
                                        $busqueda = $_POST['busqueda'];
                                        if(strlen($busqueda)>0){$query = "SELECT * FROM canciones WHERE Nombre LIKE '$busqueda' AND NOT EXISTS (
                                            SELECT 1
                                            FROM cancionesxplaylist
                                            WHERE cancionesxplaylist.FKIDCancion = canciones.ID
                                            AND cancionesxplaylist.FKIDPlaylist = $id_playlist
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
                                                    if(isset($_GET['pl'])){
                                                        $id_playlist = $_GET['pl'];
                                                        echo "<form action='modPlaylist.php?pl=$id_playlist' method='post'>";
                                                    }
                                                echo "<input type='hidden' name='id' value='",$id,"'>";
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

</body>
</html>


<!--Modificar playlist-->
<?php
  $enlace = mysqli_connect("localhost", "root", "", "proyectobd");

  if (!$enlace) {
      echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
      echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
      exit;
  }
  
  if (isset($_GET['pl']) && isset($_POST['modificar']) && isset($_POST['nombre']) && isset($_POST['descripcion'])) {
    $id = $_GET['pl'];
    $nombre = $_POST['nombre'];
    $descripcion= $_POST['descripcion'];

      $sql = "UPDATE playlist SET Nombre = '$nombre', Descripcion = '$descripcion' WHERE ID = $id";
  
      if (!$resultado = $enlace->query($sql)) {
          echo "Lo sentimos, este sitio web está experimentando problemas.";
          exit;
      }
  
      echo "<script>window.location.href = 'modPlaylist.php?pl=$id';</script>";
  
  }
  
  mysqli_close($enlace);
?>


<!--Insertar canciones en playlist-->
<?php

$enlace = mysqli_connect("localhost", "root", "", "proyectobd");

    if (!$enlace) {
        echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
        echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
        exit;
    }

    if (isset($_POST['anadir']) && isset($_GET['pl'])) {
        $id = $_POST['id']; //id de la cancion 
        $id_playlist = $_GET['pl']; //id del album

        $sql = "INSERT INTO cancionesxplaylist (FKIDPlaylist,FKIDCancion) VALUES ('$id_playlist','$id')";

        if (!$resultado = $enlace->query($sql)) {
            echo "Lo sentimos, este sitio web está experimentando problemas.";
            exit;
        }

        echo "<script>window.location.href = 'modPlaylist.php?pl=$id_playlist';</script>";
    }
    mysqli_close($enlace);
?>


<!-- Quitar cancion de playlist -->
<?php
  $enlace = mysqli_connect("localhost", "root", "", "proyectobd");

  if (!$enlace) {
      echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
      echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
      exit;
  }

  if (isset($_POST['eliminar_cancion']) && isset($_GET['pl'])) {
      $id = $_POST['id'];
      $id_playlist = $_GET['pl'];
      $sql = "DELETE FROM cancionesxplaylist WHERE FKIDCancion = $id AND FKIDPlaylist = $id_playlist";

      if (!$resultado = $enlace->query($sql)) {
          echo "Lo sentimos, este sitio web está experimentando problemas.";
          exit;
      }

      echo "<script>window.location.href = 'modPlaylist.php?pl=$id_playlist';</script>";
  }

  mysqli_close($enlace);

?>
