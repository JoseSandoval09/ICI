//creating scene
var scene = new THREE.Scene();
scene.background = new THREE.Color(0x0d1e28);

//add camera // lo que se ve desde primera persona
var camera = new THREE.PerspectiveCamera(
    75,
    window.innerWidth/window.innerHeight, 
    0.1,
    2000
);

//add new camera // camara que vermos en pantalla 
var newcamera = new THREE.PerspectiveCamera(
    30,
    window.innerWidth/window.innerHeight,
    3, //near
    50 //far
);

//This helps with visualizing what a camera contains in its frustum.
//It visualizes the frustum of a camera using a LineSegments.
//Frustum: porción resultante de un sólido
var helper = new THREE.CameraHelper(newcamera); //muestra aristas del codigo
scene.add(helper);

//renderer
var renderer = new THREE.WebGLRenderer();
renderer.setSize(window.innerWidth,window.innerHeight);
document.body.appendChild(renderer.domElement);

//crear cubo de nuevo

var geometry = new THREE.BoxGeometry();
var material = new THREE.MeshBasicMaterial({
    color: 0xfbb845,
    //wireframe: true
});
var cube = new THREE.Mesh(geometry, material);
cube.position.z = -10;

scene.add(cube);


var i = 0;
var animate = function(){
    requestAnimationFrame(animate);

    camera.lookAt(newcamera.position);//la camara original vera a la camara nueva
    
    camera.position.x = Math.cos(i) * 10; //posicion de la camara exterior//giro
    camera.position.z = Math.sin(i) * 10; //posicion de la camra exterior//giro

    i += 0.01; //velocidad de rotacion de camara y rotacion

    cube.rotation.x += 0.15;
    cube.rotation.y += 0.05;
    cube.rotation.z += 0.01;

    renderer.render(scene, camera);

}

animate();