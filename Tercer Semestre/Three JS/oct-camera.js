//creating scene
var scene = new THREE.Scene();
scene.background = new THREE.Color(0x0d1e28);

//add camera
var camera = new THREE.PerspectiveCamera(
    75,
    window.innerWidth/window.innerHeight,
    0.1,
    2000
);

//add new camera
var newcamera = new THREE.OrthographicCamera(
    5, //ver hacia izq
    -5, //ver hacia der
    5, //ver hacia arriba
    -5, //ver hacia abajo
    3, //near
    10 //far
);

//This helps with visualizing what a camera contains in its frustum.
//It visualizes the frustum of a camera using a LineSegments.
//Frustum: porción resultante de un sólido
var helper = new THREE.CameraHelper(newcamera);
scene.add(helper);

//renderer
var renderer = new THREE.WebGLRenderer();
renderer.setSize(window.innerWidth,window.innerHeight);
document.body.appendChild(renderer.domElement);

var geometry = new THREE.BoxGeometry();
var material = new THREE.MeshBasicMaterial({
    color: 0xfbb845,
    wireframe: true
});
var cube = new THREE.Mesh(geometry, material);
cube.position.z = -5;

scene.add(cube);


var i = 0;
var animate = function(){
    requestAnimationFrame(animate);

    camera.lookAt(newcamera.position);
    
    camera.position.x = Math.cos(i) * 30;
    camera.position.z = Math.sin(i) * 30;

    i += 0.01;

    cube.rotation.x += 0.01;
    cube.rotation.y += 0.01;

    renderer.render(scene, camera);

}

animate();