<?php include "Templates/index.html" ?>

<div class="card position-absolute top-50 start-50 translate-middle align-items-center back-gradient"id="login" style="width: 28rem;">
    <div class="card-body mt-4">
      <form class="align-items-center">
        <div class="mb-3">
          <label for="InputUser" class="form-label fw-bold ">USER</label>
          <input name="usuario" type="User" class="form-control" id="UserImput" aria-describedby="emailHelp">
          <div id="sugerenciaUser" class="form-text" style="color: white;">Sugerencia: Carlos Aregelio</div>
        </div>
        <div class="mb-3">
          <label for="Password" class="form-label fw-bold">CONTRASEÑA</label>
          <input name="contrasena" type="password" class="form-control" id="Password">
          <div id="sugerenciaPass" class="form-text" style="color: white;">Sugerencia: EntidadRelacion</div>
        </div>
        <div class="mb-3">
          <label for="Invitado" class="form-label">¿Eres Invitado?</label>
        </div>
        <button type="submit" class="btn btn-primary" id="btnprimary">Iniciar Sesion</button>
      </form>
    </div>
  </div>