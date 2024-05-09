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

<!--CONSULTAR-->
<?php
  $enlace = mysqli_connect("localhost", "root", "", "accesosbd");

  if (!$enlace) {
      echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
      echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
      exit;
  }



?>