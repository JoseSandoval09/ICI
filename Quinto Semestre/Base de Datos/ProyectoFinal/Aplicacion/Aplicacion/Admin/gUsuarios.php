<?php include "../Templates/headerAdmin.html" ?>

<div class="container">
    <div class="row">
        <div class="col-lg-1  ">
            <br>
           <!-- Button trigger modal -->
            <button type="button" class="btn btn-primary" data-bs-toggle="modal" data-bs-target="#nuevoAdmin">
                Crear nuevo administrador
            </button> 
            <br>
            <!-- Modal para nuevo administrador-->
            <div class="modal fade" id="nuevoAdmin" tabindex="-1" aria-labelledby="exampleModalLabel" aria-hidden="true">
                <div class="modal-dialog">
                  <div class="modal-content">
                    <div class="modal-header">
                      <h1 class="modal-title fs-5" id="exampleModalLabel">Registrar a un nuevo administrador</h1>
                      <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
                    </div>
                    <div class="modal-body">
                      
                        <!--form para nuevo administrador-->
                        <form action="adminHUB.php" method="post" >
                            <input type="text" name="correo" placeholder="correo">
                            <input type="password" name="contrasena" placeholder="contraseña">
                            <input type="text" name="usuario" placeholder="usuario">
                            <input type="text" name="telefono" placeholder="telefono">
                            <input type="hidden" name="valAdmin" value="1">
                            <input type="submit" name="registrarAdmin" value="nuevoAdmin">
                        </form>

                    </div>
                    <div class="modal-footer">
                      <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Cerrar</button>
                    </div>
                  </div>
                </div>
              </div><!-- fin modal -->
        </div>
    </div>  
    <div class="row">
        <div class="col-lg-12">
            <br>
            <h2>Usuarios Registrados</h2>
            <div class="container-lg-8 overflow-y-auto align-items-center">
            <table class="table">
                <thead>
                    <tr>
                        <th scope="col">Usuario</th>
                        <th scope="col">Correo</th>
                        <th scope="col">Telefono</th>
                    </tr>
                </thead>
                <tbody>
                    <!--Muestra canciones en el album-->
                    <?php 
                        $enlace = mysqli_connect("localhost", "root", "", "proyectobd");

                        if (!$enlace) {
                            echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
                            echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
                            exit;
                        }

                        $query = "SELECT * FROM usuarios ORDER BY Nombre ASC";

                        if ($result = $enlace->query($query)){
                            while($r = $result->fetch_assoc()){
                                $id = $r['ID'];
                                $nombre = $r['Nombre'];
                                $correo = $r['Correo'];
                                $telefono = $r['Telefono'];
                                $admin = $r['Administrador'];
                                    
                                echo '<tr>';
                                        echo '<th scope="row">',$nombre,'</th>';
                                        echo '<td>',$correo,'</td>';
                                        echo '<td>',$telefono,'</td>';
                                        echo '<td>';
                                        echo "<form action='gUsuarios.php' method='post'>";
                                        echo "<input type='hidden' name='id' value='",$r['ID'],"'>";
                                        echo "<input type='hidden' name='admin' value='",$admin,"'>";
                                        if($admin==0){ echo "<input class='btn btn-secondary ms-3' type='submit' name='c_admin' value='Usuario'>"; }
                                        else{ echo "<input class='btn btn-info ms-3' type='submit' name='c_admin' value='Administrador'>";}
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


        </div>
    </div>       
</div>

</body>
</html>


<!--Modificar permisos de administrador-->
<?php
  $enlace = mysqli_connect("localhost", "root", "", "proyectobd");

  if (!$enlace) {
      echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
      echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
      exit;
  }
  
  if (isset($_POST['id']) && isset($_POST['c_admin'])) {
    $id = $_POST['id'];
    $admin = $_POST['admin'];

    if($admin==0){ $admin=1; }
    else{ $admin=0; }

      $sql = "UPDATE usuarios SET Administrador = '$admin' WHERE ID = $id";
  
      if (!$resultado = $enlace->query($sql)) {
          echo "Lo sentimos, este sitio web está experimentando problemas.";
          exit;
      }
  
      echo "<script>window.location.href = 'gUsuarios.php';</script>";
  
  }
  
  mysqli_close($enlace);
?>
