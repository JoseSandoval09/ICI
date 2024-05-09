<?php include "../Templates/headerUser.html" ?>

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
                            echo "<h1>$nombre</h1>";
                            echo "<p>Duracion: $dMin:$dSeg</p>";
                            echo "<h2>Letra</h2>";
                            echo '<p>',$letra,'</p>';
                    echo "</div>";
                }//fin info cancion
            }
        }//din if id cancion      
            mysqli_close($enlace);
        ?>
    </div><!-- FIN CONTAINER INFO CANCION-->



</body>
</html>