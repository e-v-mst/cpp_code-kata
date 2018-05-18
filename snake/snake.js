$(function() {
    console.log("hello");
    updateSize();

    $(window).resize(function() 
	{
		updateSize();
	});

    /*var canvas = document.getElementById("snake"),

	ctx    = canvas.getContext('2d');*/

	
	
});

var snakeL = 3;

function updateSize(){
	var hp = window.innerHeight|| document.documentElement.clientHeight || document.body.clientHeight;
	var h = hp-200;

	var canvas = document.getElementById("snake"),
	ctx     = canvas.getContext('2d');
	

	if (h<600)
	{
		canvas.height = h;
		canvas.width  = h;
		$('.playable-canvas').css('height',h);
		$('.playable-canvas').css('width',h);
		$('.playable-canvas').css('margin',(hp-h)/2);
	}
	else
	{
		canvas.height = 500;
		canvas.width  = 500;
		$('.playable-canvas').css('height', '500px');
		$('.playable-canvas').css('width', '500px');
		$('.playable-canvas').css('margin','50px');
	}

	

    draw_net(h);
    draw_body(h, );
}

function draw_net(h){
	var cell_num = 16;
	var count = h/cell_num ;
	var canvas = document.getElementById("snake"),
	ctx     = canvas.getContext('2d');
	ctx.strokeStyle =  "white";

	var x=0, y=count;

	for (var i=0; i<cell_num; i++)
	{
		ctx.beginPath();
		ctx.moveTo(x, y);
	    ctx.lineTo(500, y);
	    ctx.stroke();
	    y+=count;

	}

	x=count; y=0;

	for (var i=0; i<cell_num; i++)
	{
		ctx.beginPath();
		ctx.moveTo(x, y);
	    ctx.lineTo(x, 500);
	    ctx.stroke();
	    x+=count;

	}
	
}

function draw_body(h, x, y){
	var cell_num = 16;
	var count = h/cell_num ;
	var canvas = document.getElementById("snake"),
	ctx     = canvas.getContext('2d');
	ctx.strokeStyle =  "white";

	var x=0, y=count;

	for (var i=0; i<cell_num; i++)
	{
		ctx.beginPath();
		ctx.moveTo(x, y);
	    ctx.lineTo(500, y);
	    ctx.stroke();
	    y+=count;

	}

	x=count; y=0;

	for (var i=0; i<cell_num; i++)
	{
		ctx.beginPath();
		ctx.moveTo(x, y);
	    ctx.lineTo(x, 500);
	    ctx.stroke();
	    x+=count;

	}
	
}