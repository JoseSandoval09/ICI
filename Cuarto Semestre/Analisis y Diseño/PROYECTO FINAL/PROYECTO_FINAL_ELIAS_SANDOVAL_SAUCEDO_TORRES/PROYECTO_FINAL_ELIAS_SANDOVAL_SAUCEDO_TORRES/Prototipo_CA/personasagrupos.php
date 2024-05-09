<?php include "newTemplates/header.html"?>

    <!--Acordeon para mostrar personas de cada grupo-->
    <div class="container text-center text-primary mt-4">
        <h1>Asignar Personas a Grupos</h1>
    </div>

<div class="container col-md-8 mt-4">


    <!--Ingresar las tablas en acordeones-->
    <?php
            $enlace = mysqli_connect("localhost", "root", "", "accesosbd");

            if (!$enlace) {
                echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
                echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
                exit;
            }
        
            $query = "SELECT * FROM personasengrupo";
        
            echo '<div class="container col-md-8">
            <table class="table table-striped">
                    <thead>
                      <tr>
                        <th scope="col">Nombre</th>
                        <th scope="col">Grupo</th>
                      </tr>
                    </thead>
                    <tbody>';

            if ($result = $enlace->query($query)){
                while($r = $result->fetch_assoc()){
                    $persona = $r['FKIDPersona'];
                    $grupo = $r['FKIDGrupoPersona'];
                    $id = $r['ID'];

                echo '<tr>';
                    $querypersona = "SELECT * FROM persona WHERE ID=$persona";
                    if($res = $enlace->query($querypersona)){
                        while($rp = $res->fetch_assoc()){
                            $nombrepersona = $rp['Nombre'];
                            echo '<th scope="row">',$nombrepersona,'</th>';
                        }
                    }//hay resultado de persona

                    $querygrupo = "SELECT * FROM grupopersona WHERE ID=$grupo";
                    if($res = $enlace->query($querygrupo)){
                        while($rg = $res->fetch_assoc()){
                            $nombregrupo = $rg['Nombre'];
                            echo '<td>',$nombregrupo,'</td>';
                        }
                    }//hay resultado de grupo

                    echo '<td><form action="personasagrupos.php" method="delete">
                            <input type="hidden" name="id" value="',$r['ID'],'">
                            <input class="btn btn-danger ms-3" type="submit" name="delete" value="Eliminar">
                        </form>
                        </td>
                    </tr>';
                }//fin while elegir grupo y persona
                    echo '</tbody>
                    </table>
                    </div>';//fin tabla
            }
            mysqli_close($enlace);
    ?><!--fin php ingresar informacion grupos y personas-->

</div><!--div container-->

<div class="container text-center">
<!-- Button  modal -->
  <button type="button" class="btn btn-primary" data-bs-toggle="modal" data-bs-target="#AsignarPaG">
        Asignar
  </button>
</div>

<div class="modal fade" id="AsignarPaG" tabindex="-1" aria-labelledby="exampleModalLabel" aria-hidden="true">
  <div class="modal-dialog">
    <div class="modal-content">
      <div class="modal-header">
        <h1 class="modal-title fs-5" id="exampleModalLabel">Asignacion</h1>
        <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
      </div>
      <div class="modal-body">
            <!--Form Asiganr-->

            <form class="row g-3" action="personasagrupos.php" method="post">

                    <div class="col-md-6">
                      <label class="form-label">ID Persona</label>
                      <input name="persona" type="text" class="form-control" id="ID">
                    </div>

                    <div class="col-md-6">
                      <label class="form-label">ID Grupo</label>
                      <input name="grupo"type="text" class="form-control" id="Zona">
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

</body>
</html>

<!--Borrar asignacion-->
<?php
  $enlace = mysqli_connect("localhost", "root", "", "accesosbd");

  if (!$enlace) {
      echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
      echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
      exit;
  }

  if (isset($_GET['delete'])) {
      $id = $_GET['id'];
      $sql = "DELETE FROM personasengrupo WHERE id = $id";

      if (!$resultado = $enlace->query($sql)) {
          echo "Lo sentimos, este sitio web está experimentando problemas.";
          exit;
      }

      echo "<script>window.location.href = 'personasagrupos.php';</script>";
  }

  mysqli_close($enlace);

?>

<!--Anadir persona a grupo-->

<?php 

$enlace = mysqli_connect("localhost", "root", "", "accesosbd");

    if (!$enlace) {
        echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
        echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
        exit;
    }

    if (isset($_POST['persona']) && isset($_POST['grupo'])) {
        $persona = $_POST['persona'];
        $grupo = $_POST['grupo'];

        $sql = "INSERT INTO personasengrupo (FKIDPersona,FKIDGrupoPersona) VALUES ('$persona', '$grupo')";

        if (!$resultado = $enlace->query($sql)) {
            echo "Lo sentimos, este sitio web está experimentando problemas.";
            exit;
        }

        echo "<script>window.location.href = 'personasagrupos.php';</script>";
    }
    mysqli_close($enlace);
?>