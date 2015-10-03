////////////////////////////////////////////////////////////////////////////////
// Fixing Incorrect JavaScript exercise
////////////////////////////////////////////////////////////////////////////////
// Your task is to find the syntax errors in this Javacript
// until it shows the the Gold Cube!
// WebGL is not supported in Internet Explorer
// There are 3 syntax errors in this code
////////////////////////////////////////////////////////////////////////////////
/*global THREE, Coordinates, $, document, window*/

var camera, scene, renderer;
var windowScale;
var cameraControls;
var clock = new THREE.Clock();

function drawGoldCube() {

	var cube;
	var cubeSizeLength = 100;
	var goldColor = "#FFDF00";
	var showFrame = true;
	var wireMaterial = new THREE.MeshBasicMaterial( { color: goldColor, wireframe: showFrame } ) ;

	var cubeGeometry = new THREE.CubeGeometry(cubeSizeLength, cubeSizeLength, cubeSizeLength);

	cube = new THREE.Mesh( cubeGeometry, wireMaterial );
	cube.position.x = 0;	// centered at origin
	cube.position.y = 0;	// centered at origin
	cube.position.z = 0;	// centered at origin
	scene.add( cube) ;

}

function init() {
	var canvasWidth = 846;
	var canvasHeight = 494;
	// For grading the window is fixed in size; here's general code:
	//var canvasWidth = window.innerWidth;
	//var canvasHeight = window.innerHeight;
	var canvasRatio = canvasWidth / canvasHeight;
	// SCENE
	scene = new THREE.Scene();
	scene.fog = new THREE.Fog( 0x808080, 2000, 4000 );
	// LIGHTS
	scene.add( new THREE.AmbientLight( 0x222222 ) );

	// RENDERER
	renderer = new THREE.WebGLRenderer( { antialias: true } );
	renderer.gammaInput = true;
	renderer.gammaOutput = true;
	renderer.setSize(canvasWidth, canvasHeight);
	renderer.setClearColor( scene.fog.color, 1 );

	var container = document.getElementById('container');
	container.appendChild( renderer.domElement );


	// CAMERA
	camera = new THREE.PerspectiveCamera( 45, canvasRatio, 1, 4000 );
	camera.position.set( -200, 200, -150 );
	// CONTROLS
	cameraControls = new THREE.OrbitAndPanControls(camera, renderer.domElement);
	cameraControls.target.set(0,0,0);

	// draw the coordinate grid
	Coordinates.drawGrid({size:1000,scale:0.01});
    Coordinates.drawGrid({size:1000,scale:0.01, orientation:"y"});
	Coordinates.drawGrid({size:1000,scale:0.01, orientation:"z"});
}

function animate() {
	requestAnimationFrame(animate);
	render();
}

function render() {
	var delta = clock.getDelta();
	cameraControls.update(delta);
	renderer.render(scene, camera);
}

init();
drawGoldCube();
animate();
