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
                <h2>Registrarse</h2>
                <form action="registrarse.php" method="post" >
                    <input class="form-control" type="text" name="correo" placeholder="Correo">
                    <br>
                    <input class="form-control" type="password" name="contrasena" placeholder="Contraseña">
                    <br>
                    <input class="form-control" type="text" name="usuario" placeholder="Usuario">
                    <br>
                    <input class="form-control" type="text" name="telefono" placeholder="Telefono">
                    <br>
                    <input class="btn btn-primary" type="submit">
                </form>
            
            <p>¿Quieres iniciar sesion? <a href="index.php">Iniciar Sesion</a></p>
            <div class="text-center mt-3">
                <img src="Source/logo_black.png" class="rounded w-25" alt="...">
            </div>
        </div>
        <div class="col lado-form">x</div>
    </div>
    
</div>

</body>
</html>


<!-- Registrar Usuario -->
<?php

    $enlace = mysqli_connect("localhost", "root", "", "proyectobd");

    if (!$enlace) {
        echo "Error: No se pudo conectar a MySQL." . PHP_EOL;
        echo "errno de depuración: " . mysqli_connect_errno() . PHP_EOL;
        exit;
    }

    if(isset($_POST['correo']) && isset($_POST['contrasena']) && isset($_POST['usuario']) && isset($_POST['telefono'])){
        $correo = $_POST['correo'];
        $contrasena = $_POST['contrasena']; 
        $usuario = $_POST['usuario'];
        $telefono = $_POST['telefono'];
        $registrado = false;

        //comprueba si no hay usuario ya registrado

        $query = "SELECT * FROM usuarios";

        if ($result = $enlace->query($query)){
            while($r = $result->fetch_assoc()){
                //tomado de la base de datos
                $id = $r['ID'];
                $usuario_bd = $r['Nombre'];
                $correo_bd = $r['Correo'];

                if($usuario_bd == $usuario || $correo == $correo_bd){
                    echo '<p>El correo o nombre de usuario ya esta registrado. Pruebe con uno diferente.</p>';
                    $registrado = true;
                }

            }//fin while

            if($registrado == false){
                
                $sql = "INSERT INTO usuarios (Correo,Contrasena,Nombre,Telefono) VALUES ('$correo', '$contrasena', '$usuario','$telefono')";

                if (!$resultado = $enlace->query($sql)) {
                    echo "Lo sentimos, este sitio web está experimentando problemas.";
                    exit;
                }

                echo '<p>El registro ha sido exitoso. Pruebe iniciar sesion.</p>';
            }//fin if correcto
        }//fin if

    }

    mysqli_close($enlace);
?>