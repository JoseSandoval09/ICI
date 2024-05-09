<?php include "Templates/gestionarPersonas.html"?>


<div class="container">
        <table class="table table-hover table-wrapper-scroll-y">
            <thead>
              <tr>
                <th scope="col">#</th>
                <th scope="col">Nombre</th>
                <th scope="col">Celular</th>
                <th scope="col">Correo</th>
                <th scope="col"></th>
              </tr>
            </thead>
            <tbody>

<!--Muestra registros Persona-->
<?php 
    $enlace = mysqli_connect("localhost", "root", "", "accesosbd");

    if (!$enlace) {
        echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
        echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
        exit;
    }

    $query = "SELECT * FROM persona";

    if ($result = $enlace->query($query)){
        while($r = $result->fetch_assoc()){
            $id = $r['ID'];
            $nombre = $r['Nombre'];
            $telefono = $r['Telefono'];
            $correo = $r['Correo'];

            echo '<tr>';
            echo '<th scope="row">',$id,'</th>';
            echo '<td>',$nombre,'</td>';
            echo '<td>',$telefono,'</td>';
            echo '<td>',$correo,'</td>';

            echo '<td>';
            echo "<form action='gPersona.php' method='delete'>";
            echo "<input type='hidden' name='id' value='",$r['ID'],"'>";
            echo "<input class='btn btn-danger ms-3' type='submit' name='delete' value='Eliminar'>";
            echo "</form>";
            echo'</td>';

            echo '<td>';
            echo "<form action='gPersona.php' method='update'>";
            echo "<input type='hidden' name='id' value='",$r['ID'],"'>";
            echo "<input class='btn btn-secondary ms-3' type='button'  name='update' value='Modificar' data-bs-toggle='modal' data-bs-target='#Modificarpersona'>";
            echo "</form>";
            echo'</td>';

            echo '</tr>';
        }//fin while filas
    }
    mysqli_close($enlace);
?>

                    </tbody>
                </table>
            </div>

<div class="container text-center">
<!-- Button  modal -->
  <button type="button" class="btn btn-primary" data-bs-toggle="modal" data-bs-target="#AgregarPersona">
    Agregar Persona Nueva
  </button>
</div>





<!-- Modal -->
<div class="modal fade" id="AgregarPersona" tabindex="-1" aria-labelledby="exampleModalLabel" aria-hidden="true">
  <div class="modal-dialog">
    <div class="modal-content">
      <div class="modal-header">
        <h1 class="modal-title fs-5" id="exampleModalLabel">Nueva Persona</h1>
        <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
      </div>
      <div class="modal-body">
            <!--Form persona-->
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
                      <button type="submit" class="btn btn-primary mt-3">Crear</button>
                    </div>
                  </form>

      </div>
      <div class="modal-footer">
        <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Close</button>
      </div>
    </div>
  </div>
</div>

<!-- Button  modal -->


<!-- Modal  update -->
<div class="modal fade" id="Modificarpersona" tabindex="-1" aria-labelledby="exampleModalLabel" aria-hidden="true">
  <div class="modal-dialog">
    <div class="modal-content">
      <div class="modal-header">
        <h1 class="modal-title fs-5" id="exampleModalLabel">Modificar Persona</h1>
        <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
      </div>
      <div class="modal-body">
            <!--Form persona-->

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
                      <button type="submit" class="btn btn-primary mt-3">Modificar</button>
                    </div>
                  </form>

      </div>
      <div class="modal-footer">
        <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Close</button>
      </div>
    </div>
  </div>
</div>


<!--Borrar persona-->
<?php
  $enlace = mysqli_connect("localhost", "root", "", "accesosbd");

  if (!$enlace) {
      echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
      echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
      exit;
  }

  if (isset($_GET['delete'])) {
      $id = $_GET['id'];
      $sql = "DELETE FROM persona WHERE id = $id";

      if (!$resultado = $enlace->query($sql)) {
          echo "Lo sentimos, este sitio web está experimentando problemas.";
          exit;
      }

      echo "<script>window.location.href = 'gPersona.php';</script>";
  }

  mysqli_close($enlace);

?>