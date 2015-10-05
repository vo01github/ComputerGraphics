////////////////////////////////////////////////////////////////////////////////
// Polygon Radius Exercise
// Your task is to write a function that will take 3 arguments:
//   sides - how many edges the polygon has.
//   location - location of the center of the polygon as a THREE.Vector3.
//   radius - radius of the polygon.
// Return the mesh that defines the minimum number of triangles necessary
// to draw the polygon.
////////////////////////////////////////////////////////////////////////////////
/*global, THREE, Coordinates, $, document, window*/

var camera, scene, renderer;
var windowScale;

function PolygonGeometry(sides, location, radius) {
	var geo = new THREE.Geometry();
	
	// generate vertices
	for ( var pt = 0 ; pt < sides; pt++ )
	{
		// Add 90 degrees so we start at +Y axis, rotate counterclockwise around
		var angle = (Math.PI/2) + (pt / sides) * 2 * Math.PI;

		var x = radius*Math.cos(angle) + location.x;
		var y = radius*Math.sin(angle) + location.y;
		
		// Save the vertex location
		geo.vertices.push( new THREE.Vector3( x, y, 0.0 ) );
	}

	// generate faces
	for ( var face = 0 ; face < sides-2; face++ )
	{
		// this makes a triangle fan, from the first +Y point around
		geo.faces.push( new THREE.Face3( 0, face+1, face+2 ) );
	}	
	// done: return it.
	return geo;
}

function init() {
	//  Setting up some parameters
	var canvasWidth = 846;
	var canvasHeight = 494;
	var canvasRatio = canvasWidth / canvasHeight;
	// scene
	scene = new THREE.Scene();

	// Camera: Y up, X right, Z up
	windowScale = 12;
	var windowWidth = windowScale * canvasRatio;
	var windowHeight = windowScale;

	camera = new THREE.OrthographicCamera( windowWidth / - 2, windowWidth / 2, windowHeight / 2, windowHeight / - 2, 0, 40 );
	
	var focus = new THREE.Vector3( 5,5,0 );
	camera.position.x = focus.x;
	camera.position.y = focus.y;
	camera.position.z = 10;
	camera.lookAt(focus);


	renderer = new THREE.WebGLRenderer({ antialias: false, preserveDrawingBuffer: true});
	renderer.gammaInput = true;
	renderer.gammaOutput = true;
	renderer.setSize(canvasWidth, canvasHeight);
	renderer.setClearColorHex( 0xffffff, 1.0 );
	
}
function showGrids() {
  	// Background grid and axes. Grid step size is 1, axes cross at 0, 0
	Coordinates.drawGrid({size:100,scale:1,orientation:"z"});
	Coordinates.drawAxes({axisLength:4,axisOrientation:"x",axisRadius:0.02});
	Coordinates.drawAxes({axisLength:3,axisOrientation:"y",axisRadius:0.02});
}
function addToDOM() {
    var container = document.getElementById('container');
    var canvas = container.getElementsByTagName('canvas');
    if (canvas.length>0) {
        container.removeChild(canvas[0]);
    }
    container.appendChild( renderer.domElement );
}
function render() {
	renderer.render( scene, camera );
}

// Main body of the script
try {
  init();
  showGrids();
  var geo = PolygonGeometry(9, new THREE.Vector3( 5, 5, 0 ), 4);
  var material = new THREE.MeshBasicMaterial( { color: 0xff0000, side: THREE.FrontSide } );
  var mesh = new THREE.Mesh( geo, material );
  scene.add( mesh );
  addToDOM();
  render();
} catch(e) {
    var errorReport = "Your program encountered an unrecoverable error, can not draw on canvas. Error was:<br/><br/>";
    $('#container').append(errorReport+e);
}