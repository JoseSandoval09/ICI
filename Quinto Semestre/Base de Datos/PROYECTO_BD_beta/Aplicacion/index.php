<?php include "Templates/index.html" ?>

<div class="container text-center">
    <div class="row mt-3">
        <div class="col">
            <h1>ShaggyShuffle.mx</h1>
        </div>
    </div>
    <div class="row mt-5">
        <div class="col lado-form">x</div>
        <div class="col ">
            <h2>Iniciar Sesion</h2>
            <form action="index.php" method="post" >
                <input type="text" class="form-control" name="usuario" placeholder="Usuario">
                <br>
                <input type="password" class="form-control" name="contrasena" placeholder="Contraseña">
                <br>
                <input type="submit" class="btn btn-primary">
            </form>
            <br>
            <p>¿Aun no te has registrado? <a href="registrarse.php">Registrate Ahora</a></p>
            <div class="text-center mt-3">
                <img src="Source/logo_black.png" class="rounded w-25" alt="...">
            </div>
        </div>
        <div class="col lado-form">x</div>
    </div>
    
</div>
    
</body>
</html>

<!-- Verificar usuario -->
<?php 
    $enlace = mysqli_connect("localhost", "root", "", "proyectobd");

    if (!$enlace) {
        echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
        echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
        exit;
    }

    if(isset($_POST['usuario']) && isset($_POST['contrasena'])){
        
        //tomado del form
        $usuario = $_POST['usuario'];
        $contrasena = $_POST['contrasena'];
        $correcto = false;

        $query = "SELECT * FROM usuarios";

        if ($result = $enlace->query($query)){
            while($r = $result->fetch_assoc()){
                //tomado de la base de datos
                $id = $r['ID'];
                $usuario_bd = $r['Nombre'];
                $contrasena_bd = $r['Contrasena'];
                $administrador_bd = $r['Administrador'];

                if($usuario_bd == $usuario && $contrasena == $contrasena_bd){

                    if($administrador_bd == 1){
                        echo "<script>window.location.href = 'Admin/adminHUB.php';</script>";
                    }//fin if administrador
                    else{
                        echo "<script>window.location.href = 'Usuario/home.php?usuario=$id';</script>";
                    }//fin else usuario
                    $correcto = true;
                }

            }//fin while

            if($correcto == false){
                echo '<p>Usuario o contraseña incorrectos</p>';
            }//fin if correcto
        }//fin if

    }

mysqli_close($enlace);
?>