<?php include "newTemplates/header.html"?>

<!--mostrar tabla-->

<div class="container mt-4 text-center text-primary">
        <div class="container">
            <h2>Accesos Semana</h2>
        </div>
        <table class="table table-hover table-wrapper-scroll-y">
            <thead>
              <tr>
                <th scope="col">#</th>
                <th scope="col">Dia</th>
                <th scope="col">Hora Inicial</th>
                <th scope="col">Minuto Inicial</th>
                <th scope="col">Hora Final</th>
                <th scope="col">Minuto Final</th>
                <th scope="col">Grupo Persona</th>
                <th scope="col">Grupo Puerta</th>
                <th></th>
              </tr>
            </thead>
            <tbody>

<!--Muestra registros para Acessos -->
<?php 
    $enlace = mysqli_connect("localhost", "root", "", "accesosbd");

    if (!$enlace) {
        echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
        echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
        exit;
    }

    $query = "SELECT * FROM accesosemana";

    if ($result = $enlace->query($query)){
        while($r = $result->fetch_assoc()){
            $id = $r['ID'];
            $dia = $r['DiaSemana'];
            $hi = $r['HoraInicio'];
            $mi = $r['MinutoInicio'];
            $hf = $r['HoraFin'];
            $mf = $r['MinutoFin'];
            $grupopersona = $r['FKIDGrupoPersona'];
            $grupopuerta = $r['FKIDGrupoPuerta'];


            echo '<tr>';

            //campos
            echo '<th scope="row">',$id,'</th>';
            echo '<td>',$dia,'</td>';
            echo '<td>',$hi,'</td>';
            echo '<td>',$mi,'</td>';
            echo '<td>',$hf,'</td>';
            echo '<td>',$mf,'</td>';
            echo '<td>',$grupopersona,'</td>';
            echo '<td>',$grupopuerta,'</td>';
            echo '<td>';

            //botones
            echo "<form action='crearDA.php' method='delete'>";
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
  <button type="button" class="btn btn-primary" data-bs-toggle="modal" data-bs-target="#AgregarAcceso">
    Agregar Nuevo Acceso
  </button>
  <button type="button" class="btn btn-primary" data-bs-toggle="modal" data-bs-target="#ModificarAcceso">
    Modificar Acceso
  </button>
</div>

<!-- Modal agregar-->
<div class="modal fade" id="AgregarAcceso" tabindex="-1" aria-labelledby="exampleModalLabel" aria-hidden="true">
  <div class="modal-dialog">
    <div class="modal-content">
      <div class="modal-header">
        <h1 class="modal-title fs-5" id="exampleModalLabel">Nueva Puerta</h1>
        <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
      </div>
      <div class="modal-body">
            <!--Form Acceso-->

            <form class="row g-3" action="crearDA.php" method="post">
                    <div class="col-md-9">
                      <label class="form-label">Dia Semana</label>
                      <input name="diasem" type="text" class="form-control" id="Dia">
                    </div>
                    
                    <div class="col-6">
                      <label class="form-label">Hora de inicio</label>
                      <input name="horaini" type="text" class="form-control" id="HoraInicial">
                    </div>

                    <div class="col-6">
                      <label class="form-label">Minuto de inicio</label>
                      <input name="minuini" type="text" class="form-control" id="MinutoInicial">
                    </div>

                    <div class="col-6">
                      <label class="form-label">Hora de fin</label>
                      <input name="horafin" type="text" class="form-control" id="HoraFinal">
                    </div>

                    <div class="col-6">
                      <label class="form-label">Minuto de fin</label>
                      <input name="minufin" type="text" class="form-control" id="MinutoFinal">
                    </div>

                    <div class="col-6">
                      <label class="form-label">ID de grupo persona</label>
                      <input name="grupopersonaId" type="text" class="form-control" id="IDGrupoPersona">
                    </div>

                    <div class="col-6">
                      <label class="form-label">ID de grupo puerta</label>
                      <input name="grupopuertaId" type="text" class="form-control" id="IDGrupoPuerta">
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


<!-- Modal modificar -->

<div class="modal fade" id="ModificarAcceso" tabindex="-1" aria-labelledby="exampleModalLabel" aria-hidden="true">
  <div class="modal-dialog">
    <div class="modal-content">
      <div class="modal-header">
        <h1 class="modal-title fs-5" id="exampleModalLabel">Modificar Acceso</h1>
        <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
      </div>
      <div class="modal-body">
            <!--Form Acceso-->

            <form class="row g-3" action="crearDA.php" method="post">
                    <div class="col-md-3">
                      <label class="form-label">ID</label>
                      <input name="id-actualizar" type="text" class="form-control" id="Dia">
                    </div>
                    <div class="col-md-9">
                      <label class="form-label">Dia Semana</label>
                      <input name="diasem-actualizar" type="text" class="form-control" id="Dia">
                    </div>
                    
                    <div class="col-6">
                      <label class="form-label">Hora de inicio</label>
                      <input name="horaini-actualizar" type="text" class="form-control" id="HoraInicial">
                    </div>

                    <div class="col-6">
                      <label class="form-label">Minuto de inicio</label>
                      <input name="minuini-actualizar" type="text" class="form-control" id="MinutoInicial">
                    </div>

                    <div class="col-6">
                      <label class="form-label">Hora de fin</label>
                      <input name="horafin-actualizar" type="text" class="form-control" id="HoraFinal">
                    </div>

                    <div class="col-6">
                      <label class="form-label">Minuto de fin</label>
                      <input name="minufin-actualizar" type="text" class="form-control" id="MinutoFinal">
                    </div>

                    <div class="col-6">
                      <label class="form-label">ID de grupo persona</label>
                      <input name="grupopersonaId-actualizar" type="text" class="form-control" id="IDGrupoPersona">
                    </div>

                    <div class="col-6">
                      <label class="form-label">ID de grupo puerta</label>
                      <input name="grupopuertaId-actualizar" type="text" class="form-control" id="IDGrupoPuerta">
                    </div>

                    <div class="col-12 mt-4">
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


<!--Borrar Acceso-->
<?php
  $enlace = mysqli_connect("localhost", "root", "", "accesosbd");

  if (!$enlace) {
      echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
      echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
      exit;
  }

  if (isset($_GET['delete'])) {
      $id = $_GET['id'];
      $sql = "DELETE FROM accesosemana WHERE id = $id";

      if (!$resultado = $enlace->query($sql)) {
          echo "Lo sentimos, este sitio web está experimentando problemas.";
          exit;
      }

      echo "<script>window.location.href = 'crearDA.php';</script>";
  }

  mysqli_close($enlace);

?>


<!--Anadir Acceso-->
<?php 

$enlace = mysqli_connect("localhost", "root", "", "accesosbd");

    if (!$enlace) {
        echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
        echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
        exit;
    }

    if (isset($_POST['diasem']) && isset($_POST['horaini']) && isset($_POST['minuini']) && isset($_POST['horafin']) && isset($_POST['minufin']) && isset($_POST['grupopersonaId']) && isset($_POST['grupopuertaId'])) {
        $dia = $_POST['diasem'];
        $hi = $_POST['horaini'];
        $mi = $_POST['minuini'];
        $hf = $_POST['horafin'];
        $mf = $_POST['minufin'];
        $grupopersonaID = $_POST['grupopersonaId'];
        $grupopuertaID = $_POST['grupopuertaId'];

        $sql = "INSERT INTO accesosemana (DiaSemana,HoraInicio,MinutoInicio,HoraFin,MinutoFin,FKIDGrupoPersona,FKIDGrupoPuerta) VALUES ('$dia', '$hi', '$mi', '$hf', '$mf', '$grupopersonaID', '$grupopuertaID')";

        if (!$resultado = $enlace->query($sql)) {
            echo "Lo sentimos, este sitio web está experimentando problemas.";
            exit;
        }

        echo "<script>window.location.href = 'crearDA.php';</script>";
    }
    mysqli_close($enlace);
?>

<!--Modificar Acceso-->
<?php
  $enlace = mysqli_connect("localhost", "root", "", "accesosbd");

  if (!$enlace) {
      echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
      echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
      exit;
  }
  
  if (isset($_POST['id-actualizar']) && isset($_POST['diasem-actualizar']) && isset($_POST['horaini-actualizar']) && isset($_POST['minuini-actualizar']) && isset($_POST['horafin-actualizar']) && isset($_POST['minufin-actualizar']) && isset($_POST['grupopersonaId-actualizar']) && isset($_POST['grupopuertaId-actualizar'])) {
    $id = $_POST['id-actualizar'];
    $dia = $_POST['diasem-actualizar'];
    $hi = $_POST['horaini-actualizar'];
    $mi = $_POST['minuini-actualizar'];
    $hf = $_POST['horafin-actualizar'];
    $mf = $_POST['minufin-actualizar'];
    $grupopersonaID = $_POST['grupopersonaId-actualizar'];
    $grupopuertaID = $_POST['grupopuertaId-actualizar'];

      $sql = "UPDATE accesosemana SET DiaSemana = '$dia', HoraInicio = '$hi', MinutoInicio = '$mi', HoraFin = '$hf', MinutoFin = '$mf', FKIdGrupoPersona = '$grupopersonaID', FKIdGrupoPuerta = '$grupopuertaID' WHERE id = $id";
  
      if (!$resultado = $enlace->query($sql)) {
          echo "Lo sentimos, este sitio web está experimentando problemas.";
          exit;
      }
  
      echo "<script>window.location.href = 'crearDA.php';</script>";
  
  }
  
  mysqli_close($enlace);
?>


