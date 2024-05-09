<?php include "../Templates/headerAdmin.html" ?>
<div class="container">
  <br>
  <h1>Bienvenido Administrador</h1>
  <br>
</div>

<div class="container">
  <div class="row">

<!-- Gestionar administrador -->
  <div class="col-lg-5">
    <div class="card">
      <div class="card-body">
        <h5 class="card-title">Gestionar usuarios</h5>
        <p class="card-text">Gestionar administradores y usuarios</p>
        <a class='btn btn-primary' href="gUsuarios.php">Ir</a>
      </div>
    </div>
  </div>

    <!-- Crear album -->
    <div class="col-lg-5">
      <div class="card">
        <div class="card-body">
          <h5 class="card-title">Gestionar albums</h5>
          <p class="card-text">Inserte,modificar o eliminar albums.</p>
          <a class='btn btn-primary' href="gAlbum.php">Ir</a>
        </div>
      </div>
    </div>
  </div><!--fin row-->

  <div class="row">
    <!-- Registrar artista -->
    <div class="col-lg-5">
      <div class="card">
        <div class="card-body">
            <h5 class="card-title">Gestionar artista</h5>
            <p class="card-text">Agregar informacion sobre un artista.</p>
            <a class='btn btn-primary' href="gArtistas.php">Ir</a>
        </div>
      </div>
    </div>


    <!-- Registrar cancion -->
    <div class="col-lg-5">
      <div class="card">
        <div class="card-body">
          <h5 class="card-title">Gestionar canciones</h5>
          <p class="card-text">Administre las canciones de la biblioteca.</p>
          <a class='btn btn-primary' href="gCanciones.php">Ir</a>
        </div>
      </div>
    </div>
  </div><!--fin row-->
</div>


</body>
</html>


<!-- Registrar un nuevo administrador -->
<?php 
  $enlace = mysqli_connect("localhost", "root", "", "proyectobd");

  if (!$enlace) {
      echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
      echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
      exit;
  }

  if(isset($_POST['correo']) && isset($_POST['contrasena']) && isset($_POST['usuario']) && isset($_POST['telefono']) && isset($_POST['valAdmin']) && isset($_POST['registrarAdmin'])){
      $correo = $_POST['correo'];
      $contrasena = $_POST['contrasena']; 
      $usuario = $_POST['usuario'];
      $telefono = $_POST['telefono'];
      $valorAdmin = $_POST['valAdmin'];
      $registrado = false;

      //comprueba si no hay usuario ya registrado

      $query = "SELECT * FROM usuarios";

      if ($result = $enlace->query($query)){
          while($r = $result->fetch_assoc()){
              //tomado de la base de datos
              $id = $r['ID'];
              $usuario_bd = $r['Nombre'];
              $correo_bd = $r['Correo'];

              if($usuario_bd == $usuario || $correo == $correo_bd){
                  echo '<p>El correo o nombre de usuario ya esta registrado. Pruebe con uno diferente.</p>';
                  $registrado = true;
              }

          }//fin while

          if($registrado == false){
              
              $sql = "INSERT INTO usuarios (Correo,Contrasena,Nombre,Telefono,Administrador) VALUES ('$correo', '$contrasena', '$usuario','$telefono',$valorAdmin)";

              if (!$resultado = $enlace->query($sql)) {
                  echo "Lo sentimos, este sitio web está experimentando problemas.";
                  exit;
              }

              echo '<p>Administrador registrado.</p>';
          }//fin if correcto
      }//fin if

  }

  mysqli_close($enlace);

?>





