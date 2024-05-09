<?php include "../Templates/headerUser.html" ?>

    <div class="container">
        <div class="row">
            <div class="col-lg-6">
                <form action="lacancion.php" class="form-control form-control-lg" method="post">
                    <input class="btn btn-primary" type="submit" name="jugar" value="Jugar">
                </form> 
            </div>
        </div>
        <div class="row">
            <div class="col-lg-6">
                <?php
                    if(isset($_GET['q'])){
                        $id_q = $_GET['q'];
                        echo '<form class="form-control form-control-lg" action="lacancion.php?q=',$id_q,'" class="form-control form-control-lg" method="post">';
                    }//siempre este disponible id de la cancion 
                ?>
                            <input class="form-control" type="text" name="cancion" placeholder="Ingrese nombre de cancion">
                            <input class="btn btn-primary" type="submit" name="validar" value="Aceptar">
                        </form> 
            </div>
        </div>
    </div>



</body>
</html>

<!--elegir cancion al azar para el juego-->
<?php

$enlace = mysqli_connect("localhost", "root", "", "proyectobd");

if (!$enlace) {
    echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
    echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
    exit;
}

    $id_cancion_juego;
    $id_artista;
    $nombre_artista;
    if(isset($_POST['jugar'])){

        $query = "SELECT * FROM artistas ORDER BY RAND() LIMIT 1";
        if ($result = $enlace->query($query)){
            while($r = $result->fetch_assoc()){
                $id_artista = $r['ID'];
                $nombre_artista = $r['Nombre'];
            }//fin info cancion
        }

        $query = "SELECT * FROM artistasxcancion WHERE FKIDArtista = $id_artista ORDER BY RAND() LIMIT 1 ";
        if ($result = $enlace->query($query)){
            while($r = $result->fetch_assoc()){
                $id_cancion_juego = $r['ID'];
            }//fin info cancion
        }   

        echo "<script>window.location.href = 'lacancion.php?q=$id_cancion_juego';</script>";
    }//fin se presiona jugar
  
mysqli_close($enlace);
?>

<!--Validar la cancion-->
<?php

    $enlace = mysqli_connect("localhost", "root", "", "proyectobd");

    if (!$enlace) {
        echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
        echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
        exit;
    }

    if(isset($_GET['q']) && isset($_POST['cancion'])){

        $nombre_cancion_usuario = $_POST['cancion'];
        $id_artistasxcancion= $_GET['q'];


        //INFO DE CANCION DE JUEGO
        $id_artista_juego;

        $id_cancion_juego;
        $nombre_cancion_juego;
        $dMin_cancion_juego;
        $dSeg_cancion_juego;
        $id_album_cancion_juego;
        $nombre_album_cancion_juego;


        $query = "SELECT * FROM artistasxcancion WHERE ID = $id_artistasxcancion";

        if ($result = $enlace->query($query)){
            while($r = $result->fetch_assoc()){
                $id_artista_juego = $r['FKIDArtista'];
                $id_cancion_juego = $r['FKIDCancion'];

                $q2 = "SELECT * FROM artistas WHERE ID = $id_artista_juego";
                if ($res = $enlace->query($q2)){
                    while($rq2 = $res->fetch_assoc()){
                        $nombre_artista_juego = $rq2['Nombre'];
                        echo "<p>El artista de hoy es $nombre_artista_juego</p>";
                    }
                }//fin if artista

                $q2 = "SELECT * FROM canciones WHERE ID = $id_cancion_juego";
                if ($res = $enlace->query($q2)){
                    while($rq2 = $res->fetch_assoc()){
                        $nombre_cancion_juego = $rq2['Nombre'];
                        $dMin_cancion_juego = $rq2['DuracionMin'];
                        $dSeg_cancion_juego = $rq2['DuracionSeg'];
                        $id_album_cancion_juego;
                        $nombre_album_cancion_juego='SIN ALBUM';

                        $q3 = "SELECT album.* FROM album
                        JOIN cancionesxalbum ON album.ID = cancionesxalbum.FKIDAlbum
                        WHERE cancionesxalbum.FKIDCancion = $id_cancion_juego";

                        if ($res3 = $enlace->query($q3)){
                            while($rq3 = $res3->fetch_assoc()){
                                $id_album_cancion_juego = $rq3['ID'];
                                $nombre_album_cancion_juego = $rq3['Nombre'];
                            }
                        }//fin if album de la cancion del juego
                    }
                }//fin if cancion juego


            }//fin while artistasxcancion
        }//fin if artistasxcancion  ya se tienen los datos de la cancion a adivinar

        //ADIVINAR DEL USUARIO

        $query = "SELECT * FROM canciones WHERE Nombre = '$nombre_cancion_usuario' LIMIT 1";

        if ($result = $enlace->query($query)){
            while($r = $result->fetch_assoc()){
                $id_cancion_usuario = $r['ID'];
                $dMin_cancion_usuario = $r['DuracionMin'];
                $dSeg_cancion_usuario = $r['DuracionSeg'];
                $id_album_cancion_usuario;
                $nombre_album_cancion_usuario;

                $q3 = "SELECT album.* FROM album
                        JOIN cancionesxalbum ON album.ID = cancionesxalbum.FKIDAlbum
                        WHERE cancionesxalbum.FKIDCancion = $id_cancion_usuario";

                if ($res3 = $enlace->query($q3)){
                    while($rq3 = $res3->fetch_assoc()){
                        $id_album_cancion_usuario = $rq3['ID'];
                        $nombre_album_cancion_usuario = $rq3['Nombre'];
                    }
                }//fin if album de la cancion del juego


                if($id_cancion_juego == $id_cancion_usuario){
                    echo "<p>Has descubierto la cancion del dia!!!</p>";
                }
                else{
                    //duracion de la cancion
                    $duracion_cancion_usuario = $dMin_cancion_usuario*60 + $dSeg_cancion_usuario;
                    $duracion_cancion_juego = $dMin_cancion_juego*60 + $dSeg_cancion_juego;

                    if($duracion_cancion_juego>$duracion_cancion_usuario){
                        echo "<p>Dura mas de $dMin_cancion_usuario:$dSeg_cancion_usuario</p>";
                    }
                    else{
                        echo "<p>Dura menos de $dMin_cancion_usuario:$dSeg_cancion_usuario</p>";
                    }//si es menor duracion
                    //album 
                    if($id_album_cancion_usuario!=$id_album_cancion_juego){
                        echo "<p>La cancion no se encuentra en el album $nombre_album_cancion_usuario</p>";
                    }
                }

            }//fin while respuesta usuario
        }else{
            echo "<p>No se encontro la cancion ingresada</p>";
        }



    }//fin cancion a adivinar y cancion


    mysqli_close($enlace);
?>
