<?php include "Templates/formPuerta.html"?>

<div class="container mt-5 d-flex justify-content-center">
        <div class="card" style="width: 40rem;">
            <div class="card-body">
                <form class="row g-3" action="formPuerta.php" method="post">
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