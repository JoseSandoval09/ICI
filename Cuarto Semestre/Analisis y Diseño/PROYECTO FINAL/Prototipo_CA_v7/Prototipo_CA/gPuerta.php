<?php include "newTemplates/header.html"?>

<div class="container mt-4 text-center text-primary">
        <div class="container">
            <h2>Gestionar Puertas</h2>
        </div>
        <table class="table table-hover table-wrapper-scroll-y">
            <thead>
              <tr>
                <th scope="col">#</th>
                <th scope="col">Zona</th>
                <th scope="col">Descripcion</th>
                <th scope="col">Grupo</th>
                <th></th>
              </tr>
            </thead>
            <tbody>

<!--Muestra registros para Puertas-->
<?php 
    $enlace = mysqli_connect("localhost", "root", "", "accesosbd");

    if (!$enlace) {
        echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
        echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
        exit;
    }

    $query = "SELECT * FROM puerta";

    if ($result = $enlace->query($query)){
        while($r = $result->fetch_assoc()){
            $id = $r['ID'];
            $zona = $r['Zona'];
            $descripcion = $r['Descripcion'];
            $grupo = $r['FKIdGrupoPuerta'];

            echo '<tr>';
            echo '<th scope="row">',$id,'</th>';
            echo '<td>',$zona,'</td>';
            echo '<td>',$descripcion,'</td>';
            echo '<td>',$grupo,'</td>';
            echo '<td>';

            echo "<form action='gPuerta.php' method='delete'>";
            echo "<input type='hidden' name='id' value='",$r['ID'],"'>";
            echo "<input class='btn btn-danger ms-3' type='submit' name='delete' value='Eliminar'>";
            echo "</form>";
            echo '</td>';

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
  <button type="button" class="btn btn-primary" data-bs-toggle="modal" data-bs-target="#AgregarPuerta">
    Agregar Puerta Nueva
  </button>
  <button type="button" class="btn btn-secondary" data-bs-toggle="modal" data-bs-target="#ModificarPuerta">
    Modificar Puerta
  </button>
</div>

<!-- Modal agregar-->
<div class="modal fade" id="AgregarPuerta" tabindex="-1" aria-labelledby="exampleModalLabel" aria-hidden="true">
  <div class="modal-dialog">
    <div class="modal-content">
      <div class="modal-header">
        <h1 class="modal-title fs-5" id="exampleModalLabel">Nueva Puerta</h1>
        <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
      </div>
      <div class="modal-body">
            <!--Form puerta-->

            <form class="row g-3" action="gPuerta.php" method="post">
                    <div class="col-md-6">
                      <label class="form-label">Zona</label>
                      <input name="zona"type="text" class="form-control" id="Nombre">
                    </div>
                    
                    <div class="col-12">
                      <label class="form-label">ID de grupo</label>
                      <input name="grupoId" type="text" class="form-control" id="IDGrupoP">
                    </div>

                    <div class="col-12">
                        <label class="form-label">Descripcion</label>
                        <input name="descripcion" type="text" class="form-control" id="Descripcion">
                    </div>

                    <div class="col-12 mt-2">
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


<!-- Modal modificar-->
<div class="modal fade" id="ModificarPuerta" tabindex="-1" aria-labelledby="exampleModalLabel" aria-hidden="true">
  <div class="modal-dialog">
    <div class="modal-content">
      <div class="modal-header">
        <h1 class="modal-title fs-5" id="exampleModalLabel">Modificar Puerta</h1>
        <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
      </div>
      <div class="modal-body">
            <!--Form puerta-->

            <form class="row g-3" action="gPuerta.php" method="post">

                    <div class="col-md-3">
                      <label class="form-label">ID de Puerta</label>
                      <input name="id-actualizar" type="text" class="form-control" id="ID">
                    </div>

                    <div class="col-md-9">
                      <label class="form-label">Zona</label>
                      <input name="zona-actualizar"type="text" class="form-control" id="Zona">
                    </div>
                    
                    <div class="col-12">
                      <label class="form-label">ID de grupo</label>
                      <input name="grupo-actualizar" type="text" class="form-control" id="IDGrupoP">
                    </div>

                    <div class="col-12">
                        <label class="form-label">Descripcion</label>
                        <input name="descripcion-actualizar" type="text" class="form-control" id="Descripcion">
                    </div>

                    <div class="col-12 mt-2">
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

<!--Borrar puerta-->
<?php
  $enlace = mysqli_connect("localhost", "root", "", "accesosbd");

  if (!$enlace) {
      echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
      echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
      exit;
  }

  if (isset($_GET['delete'])) {
      $id = $_GET['id'];
      $sql = "DELETE FROM puerta WHERE id = $id";

      if (!$resultado = $enlace->query($sql)) {
          echo "Lo sentimos, este sitio web está experimentando problemas.";
          exit;
      }

      echo "<script>window.location.href = 'gPuerta.php';</script>";
  }

  mysqli_close($enlace);

?>

<!--Anadir Persona-->
<?php 

$enlace = mysqli_connect("localhost", "root", "", "accesosbd");

    if (!$enlace) {
        echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
        echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
        exit;
    }

    if (isset($_POST['zona']) && isset($_POST['grupoId']) && isset($_POST['descripcion'])) {
        $zona = $_POST['zona'];
        $descripcion = $_POST['descripcion'];
        $grupoID = $_POST['grupoId'];

        $sql = "INSERT INTO puerta (Zona,Descripcion,FKIdGrupoPuerta) VALUES ('$zona', '$descripcion', '$grupoID')";

        if (!$resultado = $enlace->query($sql)) {
            echo "Lo sentimos, este sitio web está experimentando problemas.";
            exit;
        }

        echo "<script>window.location.href = 'gPuerta.php';</script>";
    }
    mysqli_close($enlace);
?>

<!--Modificar Puerta-->
<?php
  $enlace = mysqli_connect("localhost", "root", "", "accesosbd");

  if (!$enlace) {
      echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
      echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
      exit;
  }
  
  if (isset($_POST['id-actualizar']) && isset($_POST['zona-actualizar']) && isset($_POST['descripcion-actualizar']) && isset($_POST['grupo-actualizar'])) {
      $id = $_POST['id-actualizar'];
      $zona = $_POST['zona-actualizar'];
      $descripcion = $_POST['descripcion-actualizar'];
      $grupo = $_POST['grupo-actualizar'];
      $sql = "UPDATE puerta SET Zona = '$zona', Descripcion = '$descripcion', FKIdGrupoPuerta = '$grupo' WHERE id = $id";
  
      if (!$resultado = $enlace->query($sql)) {
          echo "Lo sentimos, este sitio web está experimentando problemas.";
          exit;
      }
  
      echo "<script>window.location.href = 'gPuerta.php';</script>";
  
  }
  
  mysqli_close($enlace);
?>