<?php include "../Templates/headerUser.html" ?>

<!--Modal para registrar nueva playlist-->   
<!-- Modal -->
<div class="modal fade" id="nuevaPlaylist" tabindex="-1" aria-labelledby="exampleModalLabel" aria-hidden="true">
        <div class="modal-dialog">
            <div class="modal-content">
                <div class="modal-header">
                    <h1 class="modal-title fs-5" id="exampleModalLabel">Nueva Playlist</h1>
                    <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Cerrar"></button>
                </div>
                <div class="modal-body">
                    
                    <!--form para artista-->
                    <?php
                        //que siempre este disponible el id del usuario
                        if(isset($_GET['usuario'])){
                            $usuario = $_GET['usuario'];
                            echo '<form class="form-control form-control-lg" action="home.php?usuario=',$usuario,'" method="post" >';
                        }
                    ?>
                          <input class="form-control" type="text" name="nombre" placeholder="Nombre">
                          <textarea class="form-control" name="descripcion" rows="8" placeholder="Descripcion"></textarea>
                          <input class="btn btn-primary"  type="submit" name="registrarPlaylist" value="Crear">

                </div>
                    <div class="modal-footer">
                    <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Cerrar</button>
                </div>
            </div>
        </div>
</div><!--Fin modal-->

<div class="container text-center">
    <div class="row mt-4">
        <div class="col-lg-3">
            <h2>Mis Playlist</h2>
            <table class="table table-hover">
                <thead>
                    <tr>
                        <th scope="col">Nombre</th>
                    </tr>
                </thead>
                <tbody>
                    <!--Muestra playlist del usuario-->
                        <?php 
                            $enlace = mysqli_connect("localhost", "root", "", "proyectobd");

                            if (!$enlace) {
                                    echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
                                    echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
                                    exit;
                            }
                            if(isset($_GET['usuario'])){
                                $id_usuario = $_GET['usuario'];

                                $query = "SELECT * FROM playlist WHERE FKIDUsuario = $id_usuario";

                                    if ($result = $enlace->query($query)){
                                        while($r = $result->fetch_assoc()){
                                            $id = $r['ID'];
                                            $nombre = $r['Nombre'];
                                            echo '<tr>';
                                            echo '<th scope="row"><a href="modPlaylist.php?pl=',$id,'">',$nombre,'</a></th>';
                                            echo '</tr>';
                                        }//fin while filas
                                    }
                            }

                                
                            mysqli_close($enlace);
                    ?>
                </tbody>
            </table>
            <button type="button" class="btn btn-primary" data-bs-toggle="modal" data-bs-target="#nuevaPlaylist">
                Nueva Playlist
            </button>
        </div><!--fin playlist-->

        <div class="col-lg-6">
            <div class="row">
                <!--Carrusel-->
                <div id="carouselExampleAutoplaying" class="carousel slide" data-bs-ride="carousel">
                <div class="carousel-inner">
                    <div class="carousel-item active ">
                    <img src="../Source/carrusel_default.png" class="d-block w-100" alt="...">
                    </div>
                    <div class="carousel-item ">
                    <img src="../Source/carrusel_default.png" class="d-block w-100" alt="...">
                    </div>
                    <div class="carousel-item ">
                    <img src="../Source/carrusel_default.png" class="d-block w-100" alt="...">
                    </div>
                </div>
                <button class="carousel-control-prev" type="button" data-bs-target="#carouselExampleAutoplaying" data-bs-slide="prev">
                    <span class="carousel-control-prev-icon" aria-hidden="true"></span>
                    <span class="visually-hidden">Previous</span>
                </button>
                <button class="carousel-control-next" type="button" data-bs-target="#carouselExampleAutoplaying" data-bs-slide="next">
                    <span class="carousel-control-next-icon" aria-hidden="true"></span>
                    <span class="visually-hidden">Next</span>
                </button>
                </div><!--fin carrusel-->
            </div>
            <div class="row mt-2">
                <div class="col-lg-6">
                    <div class="card w-75 mb-3">
                        <div class="card-body">
                            <h5 class="card-title">La Cancion</h5>
                            <p class="card-text">Descubre la cancion del dia.</p>
                            <a href="../Juegos/lacancion.php" class="btn btn-primary">Ir</a>
                        </div>
                    </div>
                </div>
            </div>

       </div><!--fin col carrusel-->
       <div class="col"><!--nuevas canciones-->
            <h3>Nuevas Canciones</h3>
            <table class="table table-hover">
                <thead>
                    <tr>
                        <th scope="col">Canciones</th>
                    </tr>
                </thead>
                <tbody>
                    <!--Muestra playlist del usuario-->
                        <?php 
                            $enlace = mysqli_connect("localhost", "root", "", "proyectobd");

                            if (!$enlace) {
                                    echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
                                    echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
                                    exit;
                            }
                                $query = "SELECT * FROM canciones ORDER BY ID DESC LIMIT 5";

                                    if ($result = $enlace->query($query)){
                                        while($r = $result->fetch_assoc()){
                                            $id = $r['ID'];
                                            $nombre = $r['Nombre'];
                                            echo '<tr>';
                                            echo '<th scope="row"><a href="verCancion.php?id=',$id,'">',$nombre,'</a></th>';
                                            echo '</tr>';
                                        }//fin while filas
                                    }

                                
                            mysqli_close($enlace);
                    ?>
                </tbody>
            </table>
       </div>
    </div><!--fin row-->

    
</div>

</body>
</html>

<!-- Registrar nueva playlist-->
<?php 
  $enlace = mysqli_connect("localhost", "root", "", "proyectobd");

  if (!$enlace) {
      echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
      echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
      exit;
  }

  if(isset($_POST['nombre']) && isset($_GET['usuario']) && isset($_POST['descripcion']) && isset($_POST['registrarPlaylist'])){
      $nombre = $_POST['nombre'];
      $descripcion = $_POST['descripcion'];
      $id_usuario = $_GET['usuario']; 

      $sql = "INSERT INTO playlist (Nombre,Descripcion,FKIDUsuario) VALUES ('$nombre','$descripcion','$id_usuario')";

      if (!$resultado = $enlace->query($sql)) {
          echo "Lo sentimos, este sitio web está experimentando problemas.";
          exit;
      }

          echo "<script>window.location.href = 'home.php?usuario=$id_usuario';</script>";
  }//fin if

  mysqli_close($enlace);

?>