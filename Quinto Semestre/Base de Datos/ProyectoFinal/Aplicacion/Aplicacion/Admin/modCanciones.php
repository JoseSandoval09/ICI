<?php include "../Templates/headerAdmin.html" ?>
<div class="container position-relative mt-5 align-items-center">
    <div class="row">
        <?php
            $enlace = mysqli_connect("localhost", "root", "", "proyectobd");

            if (!$enlace) {
                echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
                echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
                exit;
            }
        if(isset($_GET['id'])){
            $id_cancion = $_GET['id'];
            $query = "SELECT * FROM canciones WHERE ID LIKE $id_cancion";
            if ($result = $enlace->query($query)){
                while($r = $result->fetch_assoc()){
                    $nombre = $r['Nombre'];
                    $dMin = $r['DuracionMin'];
                    $dSeg = $r['DuracionSeg'];
                    $letra = $r['Letra'];
                    $portada = '../Source/Portadas/default.png';


                    //para obtener la portada del album
                    $q_portada = "SELECT album.*
                    FROM album
                    JOIN cancionesxalbum ON album.ID = cancionesxalbum.FKIDAlbum
                    JOIN canciones ON canciones.ID = cancionesxalbum.FKIDCancion
                    WHERE cancionesxalbum.FKIDCancion = $id_cancion;";

                    if ($res = $enlace->query($q_portada)){
                        while($rp = $res->fetch_assoc()){
                            $portada = $rp['Portada'];
                        }
                    }//fin if de consulta portada
                    
                    echo "<div class='col-lg-2'><img src='$portada' class='card-img-top' alt='music'></div>";

                    echo "<div class='col-lg-7 m-2'>";
                        echo "<form class='form-control form-control-lg' action='modCanciones.php?id=$id_cancion' method='post'>";
                            echo "<input class='form-control' type='text' name='nombre' placeholder='Nombre' value='$nombre'>";
                                echo '<div class="w-50 input-group mb-3">';
                                    echo '<span class="input-group-text">Duracion</span>';
                                    echo "<input class='form-control' type='text' name='d_min' placeholder='00' value='$dMin'>";
                                    echo '<span class="input-group-text">:</span>';
                                    echo "<input class='form-control' type='text' name='d_seg' placeholder='00' value='$dSeg'>";
                                echo "</div>";
                                echo '<textarea class="form-control" name="letra" rows="12" placeholder="Letra">',$letra,'</textarea>';
                            echo "<input class='btn btn-primary ms-3' type='submit' name='modificar' value='Modificar'>";
                        echo "</form>"; 
                    echo "</div>";
                }//fin while opciones
            }
        }//din if id cancion      
            mysqli_close($enlace);
        ?>
    </div>
    <div class="row">
        <h2>Artistas en la cancion</h2>
        <div class="container-lg-8 overflow-y-auto align-items-center">
                    <table class="table">
                        <thead>
                            <tr>
                            <th scope="col">Nombre</th>
                            <th scope="col">Nacimiento</th>
                            <th scope="col">Pais</th>
                            </tr>
                        </thead>
                        <tbody>
                            <!--Muestra artistas en la cancion-->
                            <?php 
                                $enlace = mysqli_connect("localhost", "root", "", "proyectobd");

                                if (!$enlace) {
                                    echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
                                    echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
                                    exit;
                                }

                                if(isset($_GET['id'])){
                                    $id_cancion = $_GET['id'];

                                    $query = "SELECT artistas.*
                                    FROM artistas
                                    JOIN artistasxcancion ON artistas.ID = artistasxcancion.FKIDArtista
                                    WHERE artistasxcancion.FKIDCancion = '$id_cancion';";

                                    if ($result = $enlace->query($query)){
                                        while($r = $result->fetch_assoc()){
                                            $id = $r['ID'];
                                            $nombre = $r['Nombre'];
                                            $nAno = $r['NacAno'];
                                            $nMes = $r['NacMes'];
                                            $nDia = $r['NacDia'];
                                            $id_pais = $r['FKIDPais'];
                                            $pais;

                                                //query para obtener pais
                                                $q_pais = "SELECT * FROM pais WHERE ID = '$id_pais'";
                                                if ($res_pais = $enlace->query($q_pais)){
                                                    while($rp = $res_pais->fetch_assoc()){
                                                        $pais = $rp['Nombre'];
                                                    }//fin while pais
                                                }//fin if pais
    
                                            echo '<tr>';
                                            echo '<th scope="row">',$nombre,'</th>';
                                            echo '<td>',$nDia,'/',$nMes,'/',$nAno,'</td>';
                                            echo '<td>',$pais,'</td>';
                                            echo '<td>';
                                                    //al momento de dirigirse a la pagina siempre este disponible el id de la cancion
                                                    if(isset($_GET['id'])){
                                                        $id_cancion = $_GET['id'];
                                                        echo "<form action='modCanciones.php?id=$id_cancion' method='post'>";
                                                    }
                                                echo "<input type='hidden' name='id' value='",$r['ID'],"'>";
                                                echo "<input class='btn btn-danger ms-3' type='submit' name='eliminar' value='Quitar'>";
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
</div>

<div class="container position-relative mt-5 align-items-center">
    <h3>Agregar en la cancion</h3>
    <div class="container-lg-8 overflow-y-auto align-items-center">

            <!--form para buscador-->
            <?php
            //al momento de dirigirse a la pagina siempre este disponible el id del album
                if(isset($_GET['id'])){
                    $id = $_GET['id'];
                    echo "<form action='modCanciones.php?id=$id' method='post'>";
                }
            ?>
                <input type="text" name="busqueda" placeholder="Buscar">
                <input type="submit" name="buscar" value="Ir">
            </form>
                    <table class="table">
                        <thead>
                            <tr>
                            <th scope="col">Nombre</th>
                            <th scope="col">Nacimiento</th>
                            <th scope="col">Pais</th>
                            </tr>
                        </thead>
                        <tbody>
                            <!--Muestra artistas en la cancion-->
                            <?php 
                                $enlace = mysqli_connect("localhost", "root", "", "proyectobd");

                                if (!$enlace) {
                                    echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
                                    echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
                                    exit;
                                }

                                if(isset($_GET['id'])){
                                    $id_artista = $_GET['id'];

                                    $query = "SELECT artistas.*
                                    FROM artistas
                                    LEFT JOIN artistasxcancion ON artistas.ID = artistasxcancion.FKIDArtista AND artistasxcancion.FKIDCancion = $id_cancion
                                    WHERE artistasxcancion.FKIDCancion IS NULL ORDER BY Nombre ASC"; 

                                    //$id es el id del album en este fragmento
                                    //-----BUSCADOR------
                                    if(isset($_POST['busqueda']) && isset($_POST['buscar']) && isset($_GET['id'])){
                                        $busqueda = $_POST['busqueda'];
                                        $id_cancion = $_GET['id'];
                                        if(strlen($busqueda)>0){$query = "SELECT * FROM artistas WHERE Nombre LIKE '$busqueda' AND NOT EXISTS (
                                            SELECT 1
                                            FROM artistasxcancion
                                            WHERE artistasxcancion.FKIDArtista = artistas.ID
                                            AND artistasxcancion.FKIDCancion = $id_cancion
                                        )"; }//que no este vacio
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

                                                //query para obtener pais
                                                $q_pais = "SELECT * FROM pais WHERE ID = '$id_pais'";
                                                if ($res_pais = $enlace->query($q_pais)){
                                                    while($rp = $res_pais->fetch_assoc()){
                                                        $pais = $rp['Nombre'];
                                                    }//fin while pais
                                                }//fin if pais
    
                                            echo '<tr>';
                                            echo '<th scope="row">',$nombre,'</th>';
                                            echo '<td>',$nDia,'/',$nMes,'/',$nAno,'</td>';
                                            echo '<td>',$pais,'</td>';
                                            echo '<td>';
                                                    //al momento de dirigirse a la pagina siempre este disponible el id de la cancion
                                                    if(isset($_GET['id'])){
                                                        $id_cancion = $_GET['id'];
                                                        echo "<form action='modCanciones.php?id=$id_cancion' method='post'>";
                                                    }
                                                echo "<input type='hidden' name='id' value='",$r['ID'],"'>";
                                                echo "<input class='btn btn-primary ms-3' type='submit' name='anadir' value='Añadir'>";
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
</body>
</html>



<!--Modificar cancion-->
<?php
  $enlace = mysqli_connect("localhost", "root", "", "proyectobd");

  if (!$enlace) {
      echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
      echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
      exit;
  }
  
  if (isset($_GET['id']) && isset($_POST['modificar']) && isset($_POST['nombre']) && isset($_POST['d_min']) && isset($_POST['d_seg']) && isset($_POST['letra'])) {
    $id = $_GET['id'];
    $nombre = $_POST['nombre'];
    $dMin = $_POST['d_min'];
    $dSeg = $_POST['d_seg'];
    $letra = $_POST['letra'];

      $sql = "UPDATE canciones SET Nombre = '$nombre', DuracionMin = '$dMin', DuracionSeg = '$dSeg', Letra = '$letra' WHERE ID = $id";
  
      if (!$resultado = $enlace->query($sql)) {
          echo "Lo sentimos, este sitio web está experimentando problemas.";
          exit;
      }
  
      echo "<script>window.location.href = 'modCanciones.php?id=$id';</script>";
  
  }
  
  mysqli_close($enlace);
?>

<!--Insertar artista en canciones-->
<?php

$enlace = mysqli_connect("localhost", "root", "", "proyectobd");

    if (!$enlace) {
        echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
        echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
        exit;
    }

    if (isset($_POST['anadir']) && isset($_GET['id'])) {
        $id = $_POST['id']; //id del artista
        $id_cancion = $_GET['id']; //id del artista

        $sql = "INSERT INTO artistasxcancion (FKIDArtista,FKIDCancion) VALUES ('$id','$id_cancion')";

        if (!$resultado = $enlace->query($sql)) {
            echo "Lo sentimos, este sitio web está experimentando problemas.";
            exit;
        }

        echo "<script>window.location.href = 'modCanciones.php?id=$id_cancion';</script>";
    }
    mysqli_close($enlace);
?>

<!-- Quitar artista de cancion -->
<?php
  $enlace = mysqli_connect("localhost", "root", "", "proyectobd");

  if (!$enlace) {
      echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
      echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
      exit;
  }

  if (isset($_POST['eliminar'])) {
      $id = $_POST['id'];
      $sql = "DELETE FROM artistasxcancion WHERE FKIDArtista = $id";

      if (!$resultado = $enlace->query($sql)) {
          echo "Lo sentimos, este sitio web está experimentando problemas.";
          exit;
      }

      echo "<script>window.location.href = 'modCanciones.php?id=$id_cancion';</script>";
  }

  mysqli_close($enlace);

?>