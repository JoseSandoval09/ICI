<?php include "Templates/formPersona.html" ?>

<div class="container mt-5 d-flex justify-content-center">
        <div class="card" style="width: 40rem;">
            <div class="card-body">
            <form class="row g-3" action="formPersona.php" method="post">
                    <div class="col-12">
                      <label class="form-label">Nombre</label>
                      <input name="nombre" type="text" class="form-control" id="Nombre" placeholder="Nombre">
                    </div>
                    <div class="col-12">
                      <label class="form-label">Telefono</label>
                      <input name="telefono" type="text" class="form-control" id="Celular" placeholder="555-555-5555">
                    </div>
                    <div class="col-12">
                      <label class="form-label">Correo</label>
                      <input name ="correo" type="text" class="form-control" id="correo" placeholder="Nombre@gmail.com">
                    </div>
                    <div class="col-12">
                      <label class="form-label">Contraseña</label>
                      <input name="contrasena" type="text" class="form-control" id="Contraseña" placeholder="Contraseña">
                    </div>
                    <div class="col-12">
                      <button type="submit" class="btn btn-primary">Crear</button>
                    </div>
            </form>
            </div>
        </div>
    </div>
<!--ANADIR UNA PERSONA-->
<?php 

$enlace = mysqli_connect("localhost", "root", "", "accesosbd");

    if (!$enlace) {
        echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
        echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
        exit;
    }

    if (isset($_POST['nombre']) && isset($_POST['telefono']) && isset($_POST['correo']) && isset($_POST['contrasena'])) {
        $nombre = $_POST['nombre'];
        $telefono = $_POST['telefono'];
        $correo = $_POST['correo'];
        $contrasena = $_POST['contrasena'];

        if(empty($nombre) || empty($telefono) || empty($correo) || empty($contrasena)){
          echo '
          <div class="container mt-5 d-flex justify-content-center">
                <div class=" col-6 alert alert-danger" role="alert">
                  Verifique que no existen campos vacios!
                </div>
          </div>';
          exit;
        }//si tiene un campo vacio

        $sql = "INSERT INTO persona (Nombre,Telefono,Correo,Contrasena) VALUES ('$nombre', '$telefono', '$correo','$contrasena')";

        if (!$resultado = $enlace->query($sql)) {
            echo "Lo sentimos, este sitio web está experimentando problemas.";
            exit;
        }

        echo "<script>window.location.href = 'gPersona.php';</script>";
    }
    mysqli_close($enlace);
?>