<?php include "newTemplates/header.html"?>

<div class="container position-relative mt-5 align-items-center">
    <div class="row align-items-center ms-5">
        <div class="col-lg-6 col-sm-6">
            <div class="card cards   border-4">
                <div class="card-header fw-bold">
                  CREAR DERECHOS DE ACCESO
                </div>
                <div class="card-body">
                  <h5 class="card-title">Creacion Derechos de acceso</h5>
                  <p class="card-text">Crear accesos para personas </p>
                  <a href="crearDA.php" class="btn btn-primary">CREAR</a>
                </div>
            </div>
        </div>
        <div class="col-lg-6 col-sm-">
            <div class="card border-4" >
                <div class="card-header fw-bold">
                  CONSULTAR ACCESO
                </div>
                <div class="card-body">
                  <h5 class="card-title">Consulta acceso</h5>
                  <p class="card-text">Permite la consulta de un acceso de usuario</p>
                  <button class="btn btn-primary" data-bs-toggle="modal" data-bs-target="#consultarAcceso">
                    CREAR
                  </button>
                </div>
            </div>
        </div>
      </div>
      <div class="row mt-3 alingn-items-center ms-5">
        <div class="col-lg-6 col-sm-12 ">
            <div class="card cards border-4">
                <div class="card-header fw-bold">
                  GESTIONAR GRUPOS DE PUERTAS
                </div>
                <div class="card-body">
                  <h5 class="card-title">GESTIONAR PUERTAS</h5>
                  <p class="card-text">Cambio de grupo permitido de acceso</p>
                  <a href="ggPuertas.php" class="btn btn-primary">Gestionar</a>
                </div>
              </div>
        </div>
        <div class="col-lg-6 col-sm-12">
            <div class="card cards border-4">
                <div class="card-header fw-bold">
                  GESTIONAR GRUPOS DE PERSONAS
                </div>
                <div class="card-body">
                  <h5 class="card-title">GESTIONAR PERSONAS</h5>
                  <p class="card-text">Cambio de accesos permitidos</p>
                  <a href="ggPersonas.php" class="btn btn-primary">Gestionar</a>
                </div>
              </div>
        </div>
      </div> 
   </div>    
</body>
</html>

<!--MODAL CONSULTAR-->
<div class="modal fade" id="consultarAcceso" tabindex="-1" aria-labelledby="exampleModalLabel" aria-hidden="true">
  <div class="modal-dialog">
    <div class="modal-content">
      <div class="modal-header">
        <h1 class="modal-title fs-5" id="exampleModalLabel">Consultar Acceso</h1>
        <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
      </div>
      <div class="modal-body">
        <!--form-->
        <form class="row g-3" action="supUI.php" method="post">
                    <div class="col-md-6">
                      <label class="form-label">ID de Persona</label>
                      <input name="personaId" type="text" class="form-control" id="IDPersona">
                    </div>
                    
                    <div class="col-6">
                      <label class="form-label">ID de la puerta</label>
                      <input name="puertaId" type="text" class="form-control" id="IDGrupoP">
                    </div>

                    <div class="col-6">
                        <label class="form-label">Horario de entrada </label>
                        <input name="hora" type="text" class="form-control" id="Descripcion">
                    </div>

                    <div class="col-6">
                        <label class="form-label">Minuto de entrada </label>
                        <input name="minuto" type="text" class="form-control" id="Descripcion">
                    </div>

                    <div class="col-12">
                        <button type="submit" class="btn btn-primary mt-3">Consultar</button>
                    </div>


          </form>

      </div>
      <div class="modal-footer">
        <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Close</button>
      </div>
    </div>
  </div>
</div>

<!--CONSULTAR-->
<?php
  $enlace = mysqli_connect("localhost", "root", "", "accesosbd");

  if (!$enlace) {
      echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
      echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
      exit;
  }

//Consultar si existe un usuario con id, puerta y horario que coincidan a los que dio el usuario
if (isset($_POST['personaId']) && isset($_POST['puertaId']) && isset($_POST['hora']) && isset($_POST['minuto'])) {
  $personaId = $_POST['personaId'];
  $puertaId = $_POST['puertaId'];
  $hora = intval($_POST['hora']);
  $minuto = intval($_POST['minuto']);

  $query = "SELECT accesosemana.HoraInicio,accesosemana.MinutoInicio,accesosemana.HoraFin,accesosemana.MinutoFin
  FROM persona INNER JOIN ((grupopuerta INNER JOIN puerta ON grupopuerta.ID = puerta.FKIdGrupoPuerta) INNER JOIN ((grupopersona INNER JOIN personasengrupo ON grupopersona.ID = personasengrupo.FKIdGrupoPersona) INNER JOIN accesosemana ON grupopersona.ID = accesosemana.FKIdGrupoPersona) ON grupopuerta.ID = accesosemana.FKIdGrupoPuerta) ON persona.ID = personasengrupo.FKIdPersona
  WHERE persona.ID=$personaId AND puerta.ID = $puertaId";

  if($resultado = $enlace->query($query)){ 
    $PuertaMatchPersona = false;
    $HorarioCorrecto = true;
    while($horario = $resultado->fetch_assoc()){
      $Hi = intval($horario['HoraInicio']);
      $Mi = intval($horario['MinutoInicio']);
      $Hf = intval($horario['HoraFin']);
      $Mf = intval($horario['MinutoFin']);

      if($hora>=$Hi && $hora<=$Hf){
        if($hora==$Hi && $minuto<$Mi){
          $HorarioCorrecto = false;
        }
        if($hora==$Hf && $minuto>$Mf){
          $HorarioCorrecto = false;
        }
      }
      else{ $HorarioCorrecto = false;}
      $PuertaMatchPersona = true;
    } 

    if($HorarioCorrecto && $PuertaMatchPersona){ 
      echo '<script>alert("Acceso Permitido");</script>';
    }
    else{
      echo '<script>alert("Acceso Denegado");</script>';
    }

  }

  
}
  

?>