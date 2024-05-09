<?php include "../Templates/headerAdmin.html" ?>

    <div class="container position-relative mt-5 align-items-center">
        <div class="row">

            <!--Imprime los datos del artista seleccionado-->
            <?php

                $enlace = mysqli_connect("localhost", "root", "", "proyectobd");

                if (!$enlace) {
                    echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
                    echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
                    exit;
                }

                if(isset($_GET['id'])){
                    $id_artista = $_GET['id'];
                    $query = "SELECT * FROM artistas WHERE ID LIKE $id_artista"; 

                    if ($result = $enlace->query($query)){
                        while($r = $result->fetch_assoc()){
                            $nombre = $r['Nombre'];
                            $foto = $r['Foto'];
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

                            //imprime toda la informacion del artista

                                echo "<div class='col-lg-2'><img src='$foto' class='card-img-top' alt='music'></div>";
                                echo "<div class='col-lg-10'>";
                                    echo "<form class='form-control form-control-lg' action='modArtista.php?id=$id_artista' method='post'>";
                                    echo "<input class='form-control' type='text' name='nombre' placeholder='Nombre' value='$nombre'>";
                                    echo '<div class="w-50 input-group mb-3">';
                                        echo '<span class="input-group-text">Nacimiento</span>';
                                        echo "<input class='form-control' type='text' name='nac_dia' placeholder='DD' value='$nDia'>";
                                        echo '<span class="input-group-text">/</span>';
                                        echo "<input class ='form-control'type='text' name='nac_mes' placeholder='MM' value='$nMes'>";
                                        echo '<span class="input-group-text">/</span>';
                                        echo "<input class='form-control' type='text' name='nac_ano' placeholder='YYYY' value='$nAno'>";
                                    echo "</div>";

                                    echo '<div class="input-group">
                                        <input type="file" class="form-control" id="formFile" aria-describedby="inputGroupFileAddon04" aria-label="Upload" value="',$foto,'" name="modFoto">
                                    </div>';

                                    //modificar pais
                                    echo '<select class="form-select" aria-label="Default select example" name="pais">';
                                    echo '<div class="overflow-y-auto">';
                                    
                                        $query = "SELECT * FROM pais";
                                    
                                        if ($result = $enlace->query($query)){
                                            while($r = $result->fetch_assoc()){
                                                $id_lista_pais = $r['ID'];
                                                $nombre = $r['Nombre'];
                                                echo '<option value=',$id_lista_pais;
                                                if($id_lista_pais == $id_pais){
                                                    echo ' selected';
                                                }
                                                echo '>',$nombre,'</option>';
                                            }//fin while opciones
                                        }
                                    echo "</div>";
                                    echo "</select>";

                                    echo "<input class='btn btn-primary' type='submit' name='modificar' value='Modificar'>";
                                    echo "</form>";
                                echo "</div>";
                                
                        }//fin while filas
                    }//fin if result
                    mysqli_close($enlace);

                }//fin isset id
                
            ?>
        </div>
    </div>

    <!-- Canciones del artista -->
    <div class="container position-relative mt-5 align-items-center">
        <h2>Canciones en las que aparece</h2>
        <div class="container-lg-8 overflow-y-auto align-items-center">
            <table class="table">
                <thead>
                    <tr>
                        <th scope="col">Titulo</th>
                        <th scope="col">Duracion</th>
                    </tr>
                </thead>
                <tbody>
                <!--Muestra canciones del artista-->
                    <?php 
                        $enlace = mysqli_connect("localhost", "root", "", "proyectobd");

                        if (!$enlace) {
                            echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
                            echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
                            exit;
                        }

                        if(isset($_GET['id'])){
                            $id_artista = $_GET['id'];

                            $query = "SELECT canciones.*
                                    FROM canciones
                                    JOIN artistasxcancion ON canciones.ID = artistasxcancion.FKIDCancion
                                    WHERE artistasxcancion.FKIDArtista = '$id_artista' ORDER BY Nombre ASC";

                            if ($result = $enlace->query($query)){
                                while($r = $result->fetch_assoc()){
                                    $id = $r['ID'];
                                    $nombre = $r['Nombre'];
                                    $dMin = $r['DuracionMin'];
                                    $dSeg = $r['DuracionSeg'];
    
                                    echo '<tr>';
                                    echo '<th scope="row">',$nombre,'</th>';
                                    echo '<td>',$dMin,':',$dSeg,'</td>';
    
                                    echo '<td>';
                                    //al momento de dirigirse a la pagina siempre este disponible el id del album
                                        if(isset($_GET['id'])){
                                            $id_artista = $_GET['id'];
                                            echo "<form action='modArtista.php?id=$id_artista' method='post'>";
                                        }
                                            echo "<input type='hidden' name='id' value='",$r['ID'],"'>";
                                            echo "<input class='btn btn-danger ms-3' type='submit' name='quitar' value='Quitar'>";
                                            echo "</form>";
                                            echo '</td>';
                                            echo '</tr>';
                                }//fin while filas
                            }//fin result
                        }//fin if get id
                        mysqli_close($enlace);
                    ?>
                </tbody>
            </table>
        </div>
    </div>

</body>
</html>


<!--Modificar artista-->
<?php
  $enlace = mysqli_connect("localhost", "root", "", "proyectobd");

  if (!$enlace) {
      echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
      echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
      exit;
  }
  
  if (isset($_GET['id']) && isset($_POST['modificar']) && isset($_POST['nombre']) && isset($_POST['nac_ano']) && isset($_POST['nac_mes']) && isset($_POST['nac_dia']) && isset($_POST['pais'])) {
    $id = $_GET['id'];
    $nombre = $_POST['nombre'];
    $nAno = $_POST['nac_ano'];
    $nMes = $_POST['nac_mes'];
    $nDia = $_POST['nac_dia'];
    $foto = $_POST['modFoto'];
    $pais = $_POST['pais'];

    //agregamos la extension de Source
    if(strlen($foto)==0){ 
        $q_portada = "SELECT * FROM artistas WHERE ID LIKE $id";
        if ($result = $enlace->query($q_portada)){
            while($rp = $result->fetch_assoc()){
                $foto = $rp['Foto'];
            }//fin while
        }//fin if consulta portada
    }//si no se elige otro archivo
    else{ $foto = '../Source/Artistas/'.$foto; }

      $sql = "UPDATE artistas SET Nombre = '$nombre', Foto = '$foto', NacAno = '$nAno', NacMes = '$nMes', NacDia = '$nDia', FKIDPais = '$pais' WHERE ID = $id";
  
      if (!$resultado = $enlace->query($sql)) {
          echo "Lo sentimos, este sitio web está experimentando problemas.";
          exit;
      }
  
      echo "<script>window.location.href = 'modArtista.php?id=$id';</script>";
  
  }
  
  mysqli_close($enlace);
?>

<!--Quitar artista de cancion-->
<?php
  $enlace = mysqli_connect("localhost", "root", "", "proyectobd");

  if (!$enlace) {
      echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
      echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
      exit;
  }

  if (isset($_POST['quitar']) && isset($_GET['id'])) {
      $id_cancion = $_POST['id'];
      $id_artista = $_GET['id'];
      $sql = "DELETE FROM artistasxcancion WHERE FKIDArtista = $id_artista AND FKIDCancion = $id_cancion";

      if (!$resultado = $enlace->query($sql)) {
          echo "Lo sentimos, este sitio web está experimentando problemas.";
          exit;
      }

      echo "<script>window.location.href = 'modArtista.php?id=$id_artista';</script>";
  }

  mysqli_close($enlace);

?>