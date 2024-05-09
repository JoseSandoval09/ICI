<?php include "newTemplates/header.html"?>


<div class="container text-center text-primary mt-4">
        <div class="container">
          <h2>Gestionar Grupo de Personas</h2>
        </div>
        <table class="table table-hover table-wrapper-scroll-y">
            <thead>
              <tr>
                <th scope="col">ID</th>
                <th scope="col">Nombre</th>
                <th scope="col">Descripcion</th>>
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

    $query = "SELECT * FROM grupopersona";

    if ($result = $enlace->query($query)){
        while($r = $result->fetch_assoc()){
            $id = $r['ID'];
            $nombre = $r['Nombre'];
            $descripcion = $r['Descripcion'];

            echo '<tr>';
            echo '<th scope="row">',$id,'</th>';
            echo '<td>',$nombre,'</td>';
            echo '<td>',$descripcion,'</td>';

            echo '<td>';
            echo "<form action='ggPersonas.php' method='delete'>";
            echo "<input type='hidden' name='id' value='",$r['ID'],"'>";
            echo "<input class='btn btn-danger ms-3' type='submit' name='delete' value='Eliminar'>";
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
  <button type="button" class="btn btn-primary" data-bs-toggle="modal" data-bs-target="#AgregarGrupoPersona">
    Agregar Grupo Nuevo
  </button>
  <a href="personasagrupos.php"><button type="button" class="btn btn-primary" data-bs-toggle="modal" data-bs-target="#AgregarPersona">
    Asignar Personas a Grupos
  </button></a>
  <button type="button" class="btn btn-secondary" data-bs-toggle="modal" data-bs-target="#ModificargPersonas">
    Modificar Grupo de Personas
  </button>
</div>


<!-- Modal agregar-->
<div class="modal fade" id="AgregarGrupoPersona" tabindex="-1" aria-labelledby="exampleModalLabel" aria-hidden="true">
  <div class="modal-dialog">
    <div class="modal-content">
      <div class="modal-header">
        <h1 class="modal-title fs-5" id="exampleModalLabel">Nueva Grupo de Persona</h1>
        <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
      </div>
      <div class="modal-body">
            <!--Form persona-->

            <form class="row g-3" action="ggPersonas.php" method="post">   
                    <div class="col-md-6">
                      <label class="form-label">Nombre</label>
                      <input name="nombre" type="text" class="form-control" id="Nombre">
                    </div>
                    
                    <div class="col-12">
                      <label class="form-label">Descripcion</label>
                      <input name="descripcion" type="text" class="form-control" id="Nombre">
                    
                    </div>
                    <div class="col-12">
                      <button type="submit" class="btn btn-primary">Crear</button>
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


<!-- Modal -->
<div class="modal fade" id="ModificargPersonas" tabindex="-1" aria-labelledby="exampleModalLabel" aria-hidden="true">
  <div class="modal-dialog">
    <div class="modal-content">
      <div class="modal-header">
        <h1 class="modal-title fs-5" id="exampleModalLabel">Modificar Grupo </h1>
        <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
      </div>
      <div class="modal-body">
            <!--Form persona-->

            <form class="row g-3" action="ggPersonas.php" method="post">
                    <div class="col-md-3">
                      <label class="form-label">ID</label>
                      <input name="id-actualizar" type="text" class="form-control" id="ID">
                    </div>
                    
                    <div class="col-md-9">
                      <label class="form-label">Nombre</label>
                      <input name="nombre-actualizar" type="text" class="form-control" id="Nombre">
                    </div>
                    
                    <div class="col-12">
                      <label class="form-label">Descripcion</label>
                      <input name="descripcion-actualizar" type="text" class="form-control" id="Desc">
                    
                    </div>
                    <div class="col-12">
                      <button type="submit" class="btn btn-primary">Modificar</button>
                    </div>   
            </form>

      </div>
      <div class="modal-footer">
        <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Close</button>
      </div>
    </div>
  </div>
</div>
  </body>
  </html>


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
      $sql = "DELETE FROM grupopersona WHERE id = $id";

      if (!$resultado = $enlace->query($sql)) {
          echo "Lo sentimos, este sitio web está experimentando problemas.";
          exit;
      }

      echo "<script>window.location.href = 'ggpersonas.php';</script>";
  }

  mysqli_close($enlace);

?>

<!--Anadir Grupo Puertas-->
<?php 

    $enlace = mysqli_connect("localhost", "root", "", "accesosbd");

    if (!$enlace) {
        echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
        echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
        exit;
    }

    if (isset($_POST['nombre']) && isset($_POST['descripcion'])) {
        $nombre = $_POST['nombre'];
        $descripcion = $_POST['descripcion'];

        $sql = "INSERT INTO grupopersona (Nombre,Descripcion) VALUES ('$nombre', '$descripcion')";

        if (!$resultado = $enlace->query($sql)) {
            echo "Lo sentimos, este sitio web está experimentando problemas.";
            exit;
        }

        echo "<script>window.location.href = 'ggPersonas.php';</script>";
    }
    mysqli_close($enlace);
?>

<!--Modificar Grupo de Personas-->
<?php
  $enlace = mysqli_connect("localhost", "root", "", "accesosbd");

  if (!$enlace) {
      echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
      echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
      exit;
  }
  
  if (isset($_POST['id-actualizar']) && isset($_POST['nombre-actualizar']) && isset($_POST['descripcion-actualizar'])) {
      $id = $_POST['id-actualizar'];
      $nombre = $_POST['nombre-actualizar'];
      $descripcion = $_POST['descripcion-actualizar'];
      ;
      $sql = "UPDATE grupopersona SET Nombre = '$nombre', Descripcion = '$descripcion' WHERE id = $id";
  
      if (!$resultado = $enlace->query($sql)) {
          echo "Lo sentimos, este sitio web está experimentando problemas.";
          exit;
      }
  
      echo "<script>window.location.href = 'ggPersonas.php';</script>";
  
  }
  
  mysqli_close($enlace);
?>