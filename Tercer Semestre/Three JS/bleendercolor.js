let scene, camera, renderer;

scene = new THREE.Scene();
scene.background = new THREE.Color(0x000001);

//let background = new THREE.TextureLoader();
//background.load('src/img/fondo.png', (texture)=>{
//    scene.background = texture;
//});

camera = new THREE.PerspectiveCamera(
	20,
	window.innerWidth/window.innerHeight,
	1,
	5000
);




camera.position.x = 2100; //elementos demasiado cerca

light = new THREE.PointLight(0x7469EF, 10); //luces hacia todos lados
light.position.set(100, 10, 10); //posicion de las luces
light.intensity = 2;
//scene.add(light);

light2 = new THREE.PointLight(0x7469EF, 50);
light2.position.set(10, 5, 0);
light2.intensity = 1;
//scene.add(light2);

light3 = new THREE.PointLight(0x7469EF, 10);
light3.position.set(50, 0, 100);
light3.intensity =3;
scene.add(light3);

light4 = new THREE.PointLight(0xFA5DB8, 10);
light4.position.set(0, 0, 100);
light4.intensity = 3;
//scene.add(light4);

renderer = new THREE.WebGLRenderer({antialias: true});
renderer.setSize(window.innerWidth, window.innerHeight);
document.body.appendChild(renderer.domElement);

let loader = new THREE.GLTFLoader(); //creando objeto loader que viene de libreria
loader.load('fantasmas_color3.glb', (gltf)=>{
	scene.add(gltf.scene);
	let i = 0;
    var animate = function(){
        requestAnimationFrame(animate);

        camera.lookAt(gltf.scene.position);
        
        camera.position.x = Math.cos(i) * 30;
        camera.position.z = Math.sin(i) * 50;

        i += 0.03;

        renderer.render(scene, camera);

    }

    animate();
});


//addEventListener: attaches an event handler to the specified element.
window.addEventListener('resize', ()=>{
	camera.aspect = window.innerWidth/window.innerHeight;
	camera.updateProjectionMatrix();
	renderer.setSize(window.innerWidth, window.innerHeight);
	renderer.render(scene, camera);
});