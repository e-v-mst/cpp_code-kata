$(function() 
{
	updateSize();

	$(window).resize(function() 
	{
		updateSize();
	});	


	var timerId = setTimeout(
		function tick() 
		{
			moveSnake();
			timerId = setTimeout(tick, 500);
		}, 
		500);
});

var cell_num = 16;
var curSnakeL = 0;

var vertical = 0,
	horizontal = 0,
	xh = 0, yh = 0,
	xl = 0, yl = 0,
	count = 0,
	step = 0,

	direction = 1, 		// Направление змейки 1 - право, 2 - вниз 3 - влево, 4 - вверх
	apple = null; 	// Яблоко, массив, 0 элемент - x, 1 элемент - y

function updateSize()
{
	var hp = window.innerHeight|| document.documentElement.clientHeight || document.body.clientHeight;
	var h = hp-200;

	var canvas = document.getElementById('snake');

	if (h < 600)
	{
		canvas.height = h;
		canvas.width  = h;
		$('.playable-canvas').css('height',h);
		$('.playable-canvas').css('width',h);
		$('.playable-canvas').css('margin',(hp-h)/2);
	}
	else
	{
		canvas.height = 520;
		canvas.width  = 520;
		$('.playable-canvas').css('height', '520px');
		$('.playable-canvas').css('width', '520px');
		$('.playable-canvas').css('margin','50px');
	}

	

	draw_net(h);
	draw_body(h);
}

function draw_net(h)
{
	var count = h/cell_num;
	var canvas = document.getElementById('snake');
	var ctx = canvas.getContext('2d');
	ctx.strokeStyle = 'white';

	var x = 0, y = count;

	for (var i = 0; i < cell_num; i++)
	{
		ctx.beginPath();
		ctx.moveTo(x, y);
		ctx.lineTo(520, y);
		ctx.stroke();
		y += count;

	}

	x = count; y = 0;

	for (var i = 0; i < cell_num; i++)
	{
		ctx.beginPath();
		ctx.moveTo(x, y);
		ctx.lineTo(x, 520);
		ctx.stroke();
		x += count;

	}
}

function draw_body(h)
{	
	count = h/cell_num ;
	xh = -count;
	yh = 6*count;
	horizontal = count;
	step = count;
}

function moveSnake()
{
	var canvas = document.getElementById('snake');
	var ctx = canvas.getContext('2d');

	var x=xh, y=yh;

	xh += horizontal;
	yh += vertical;	

	if (xh >= canvas.width)
		xh = 0;

	if (xh <= 0-step)
		xh = canvas.width-step;

	if (yh <= 0-step)
		yh = canvas.height-step;

	if (yh >= canvas.height)
		yh = 0;


	ctx.fillStyle = '#00e700';
	ctx.strokeRect(xh, yh, count, count);
	ctx.fillRect(xh, yh, count, count);

	ctx.strokeRect(x, y, count, count);
	ctx.fillStyle = '#b8b8b8';
	ctx.fillRect(x, y, count, count);


}

var xTail=xh, yTail=yh;

$(document).ready(function(){
	document.onkeydown = function(event){
		xTail = xh; 
		yTail = yh;

		if(event.keyCode == '38') {
			//console.log('Up');
			vertical = -step;
			horizontal = 0;
		}
		

		else if(event.keyCode == '40'){
			//console.log('Down');
			vertical = step;
			horizontal = 0;
		}

		else if(event.keyCode == '37'){
			//console.log('Left');
			vertical = 0;
			horizontal = -step;
		}

		else if(event.keyCode == '39'){
			//console.log('Right');
			vertical = 0;
			horizontal = step;
		}
	};		
});