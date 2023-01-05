const char webpage[] PROGMEM = R"=====(
<!doctypehtml><html lang=hu><meta charset=utf-8><meta content="width=device-width,initial-scale=1"name=viewport><title>Smart Home</title><link href=https://uxwing.com/wp-content/themes/uxwing/download/06-buildings-architecture-real-estate/home.png rel=icon><link href=https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css rel=stylesheet crossorigin=anonymous integrity=sha384-JcKb8q3iqJ61gNV9KGb8thSsNjpSL0n8PARn9HuZOnIxN0hoP+VmmDGMN5t9UJ0Z><style>body{text-align:center}table,td,th{margin-left:auto;margin-right:auto;border-collapse:collapse}td,th{padding:3px;width:25px;height:25px}th{background:#000}td{background-color:transparent}.btn-success{margin:auto;display:block}.btn-danger{margin:auto;display:block}.btn-warning{margin:auto;display:block}.onoffswitch{position:relative;width:90px;user-select:none;-webkit-user-select:none;-moz-user-select:none;-ms-user-select:none}.onoffswitch-checkbox{position:absolute;opacity:0;pointer-events:none}.onoffswitch-label{display:block;overflow:hidden;cursor:pointer;border:2px solid #999;border-radius:20px}.onoffswitch-inner{display:block;width:200%;margin-left:-100%;transition:margin .3s ease-in 0s}.onoffswitch-inner:after,.onoffswitch-inner:before{display:block;float:left;width:50%;height:30px;padding:0;line-height:30px;font-size:14px;color:#fff;font-family:Trebuchet,Arial,sans-serif;font-weight:700;box-sizing:border-box}.onoffswitch-inner:before{content:"ON";padding-left:10px;background-color:#34a7c1;color:#fff}.onoffswitch-inner:after{content:"OFF";padding-right:10px;background-color:#eee;color:#999;text-align:right}.onoffswitch-switch{display:block;width:18px;margin:6px;background:#fff;position:absolute;top:0;bottom:0;right:56px;border:2px solid #999;border-radius:20px;transition:all .3s ease-in 0s}.onoffswitch-checkbox:checked+.onoffswitch-label .onoffswitch-inner{margin-left:0}.onoffswitch-checkbox:checked+.onoffswitch-label .onoffswitch-switch{right:0}.table-bordered{width:40%}</style><div class=jumbotron><p class=lead><table><tr><th colspan=15><td id=cellAblakFurdo><th colspan=3><td id=cellAblakSpajz><th colspan=10><tr><th rowspan=13><td><td><td><td><td><td><td><th rowspan=10><td><td><td><td><th rowspan=7><td><td><td><th rowspan=5><td><td><td><th rowspan=7><td><td><td><td><td><td><td><th rowspan=3><tr><td><td><td><td><td><td><td><td><td><td><td><td id=cellSzellozo colspan=3><td><td><td><td><td><td><td><td><td><td><tr><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><tr><td><td><td id=cellMuhely colspan=3><td><td><td><td id=cellKonyha colspan=2><td><td id=cellFurdo colspan=3><td id=cellSpajz colspan=3><td><td><td id=cellHalo colspan=3><td><td><td id=cellAblakHalo rowspan=5><tr><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><tr><td><td><td><td><td><td><td><td><td><td><td><th><td><th colspan=3><td><th><td><td><td><td><td><td><td><tr><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><tr><td><td><td><td><td><td><td><td><td><td><td><td rowspan=2><td><td><td id=cellKisFolyoso colspan=3><td><td><td rowspan=2><td><td><td><td><td><td><td><tr><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><th rowspan=6><tr><td><td><td><td><td><td><td><td><td><td><td><th><td><td><td><td><td><td><td><th rowspan=3><td><td><td><td><td><td><td><tr><td><td><td><td><td><td><td><th colspan=2><td colspan=2><th colspan=9><td><td><td><td><td><td><td><tr><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><th colspan=2><td colspan=2><th colspan=3><tr><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td id=cellNagyFolyoso colspan=3><td><td><th rowspan=5><td><td><td><td><td><td><td><tr><th><th><td id=cellAblakMuhely colspan=2><th><td id=cellAjtoMuhely colspan=2><th colspan=2><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><tr><td><td><td><td><td><td><td><td><th colspan=2><td id=cellAblakFolyoso1 colspan=2><th><th colspan=4><th rowspan=3><td><td><td><td><td><td><td><td><td><td><td id=cellAblakNappali rowspan=5><tr><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td id=cellNappali colspan=3><td><td><tr><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><tr><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td id=cellAjtoBejarat rowspan=2><td><td><td><td rowspan=2><td><td><td><td><td><td><td><tr><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><tr><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><th rowspan=2><td><td><td><th rowspan=2><td><td><td><td><td><td><td><th rowspan=6><tr><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><th colspan=7><tr><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td id=cellAblakFolyoso2 rowspan=2><td><td><td><td><td><td><td><td><tr><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><tr><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><th><td><td><td><td><td><td><td><td><td><td><td><tr><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><td><th colspan=2><td id=cellAblakFolyoso3 colspan=2><th colspan=10></table><hr class=my-4><p class=lead><table class="table table-bordered"><tr><td><b><u>Position:</u></b><td><b><u>State:</u></b><tr><td>Kinti világítás<td id=tableKintiVilagitas><tr><td>Álló lámpák<td id=tableAlloLampak><tr><td>Fészer világítás<td id=tableFeszerVilagitas><tr><td>Padlás világítás<td id=tablePadlasVilagitas><tr><td>Postaláda<td id=tablePostalada></table></div>
<script>
	var cellMuhely = document.getElementById("cellMuhely");
	var cellKonyha = document.getElementById("cellKonyha");
	var cellSzellozo = document.getElementById("cellSzellozo");
	var cellFurdo = document.getElementById("cellFurdo");
	var cellSpajz = document.getElementById("cellSpajz");
	var cellHalo = document.getElementById("cellHalo");
	var cellKisFolyoso = document.getElementById("cellKisFolyoso");
	var cellNagyFolyoso = document.getElementById("cellNagyFolyoso");
	var cellNappali = document.getElementById("cellNappali");
	var cellAblakFurdo = document.getElementById("cellAblakFurdo");
	var cellAblakSpajz = document.getElementById("cellAblakSpajz");
	var cellAblakHalo = document.getElementById("cellAblakHalo");
	var cellAblakNappali = document.getElementById("cellAblakNappali");
	var cellAblakFolyoso1 = document.getElementById("cellAblakFolyoso1");
	var cellAblakFolyoso2 = document.getElementById("cellAblakFolyoso2");
  var cellAblakFolyoso3 = document.getElementById("cellAblakFolyoso3");
	var cellAblakMuhely = document.getElementById("cellAblakMuhely");
	var cellAjtoBejarat = document.getElementById("cellAjtoBejarat");
	var cellAjtoMuhely = document.getElementById("cellAjtoMuhely");
	var tableKintiVilagitas = document.getElementById("tableKintiVilagitas");
	var tableAlloLampak = document.getElementById("tableAlloLampak");
	var tableFeszerVilagitas = document.getElementById("tableFeszerVilagitas");
	var tablePadlasVilagitas = document.getElementById("tablePadlasVilagitas");
	var tablePostalada = document.getElementById("tablePostalada");

	setInterval(function() { getStates(); }, 1000); 

	function getStates()
	{
		var xhttp = new XMLHttpRequest();
		
		xhttp.onreadystatechange = function()
		{
			if (this.readyState == 4 && this.status == 200)
			{
				const json = JSON.parse(this.responseText);
				// Térképen gombok
				if      (json.d01 == false)	cellMuhely.innerHTML = "<button onclick='btnPressed(\"d01\")' class='btn-secondary'>OFF</button>";
				else if (json.d01 == true)	cellMuhely.innerHTML = "<button onclick='btnPressed(\"d01\")' class='btn-success'>ON</button>";
				if      (json.d02 == false)	cellKonyha.innerHTML = "<button onclick='btnPressed(\"d02\")' class='btn-secondary'>OFF</button>";
				else if (json.d02 == true)	cellKonyha.innerHTML = "<button onclick='btnPressed(\"d02\")' class='btn-success'>ON</button>";
				if      (json.d03 == false)	cellFurdo.innerHTML = "<button onclick='btnPressed(\"d03\")' class='btn-secondary'>OFF</button>";
				else if (json.d03 == true)	cellFurdo.innerHTML = "<button onclick='btnPressed(\"d03\")' class='btn-success'>ON</button>";				
				if      (json.d05 == false)	cellHalo.innerHTML = "<button onclick='btnPressed(\"d05\")' class='btn-secondary'>OFF</button>";
				else if (json.d05 == true)	cellHalo.innerHTML = "<button onclick='btnPressed(\"d05\")' class='btn-success'>ON</button>";
				if      (json.d06 == false)	cellKisFolyoso.innerHTML = "<button onclick='btnPressed(\"d06\")' class='btn-secondary'>OFF</button>";
				else if (json.d06 == true)	cellKisFolyoso.innerHTML = "<button onclick='btnPressed(\"d06\")' class='btn-success'>ON</button>";
				if      (json.d07 == false)	cellNagyFolyoso.innerHTML = "<button onclick='btnPressed(\"d07\")' class='btn-secondary'>OFF</button>";
				else if (json.d07 == true)	cellNagyFolyoso.innerHTML = "<button onclick='btnPressed(\"d07\")' class='btn-success'>ON</button>";
				if      (json.d08 == false)	cellNappali.innerHTML = "<button onclick='btnPressed(\"d08\")' class='btn-secondary'>OFF</button>";
				else if (json.d08 == true)	cellNappali.innerHTML = "<button onclick='btnPressed(\"d08\")' class='btn-success'>ON</button>";
				// Táblázatban gombok
				if      (json.d09 == false)	tableKintiVilagitas.innerHTML = "<button onclick='btnPressed(\"d09\")' class='btn btn-secondary'>OFF</button>";
				else if (json.d09 == true)	tableKintiVilagitas.innerHTML = "<button onclick='btnPressed(\"d09\")' class='btn btn-success'>ON</button>";
				if      (json.d10 == false)	tableAlloLampak.innerHTML = "<button onclick='btnPressed(\"d10\")' class='btn btn-secondary'>OFF</button>";
				else if (json.d10 == true)	tableAlloLampak.innerHTML = "<button onclick='btnPressed(\"d10\")' class='btn btn-success'>ON</button>";
				if      (json.d11 == false)	tableFeszerVilagitas.innerHTML = "<button onclick='btnPressed(\"d11\")' class='btn btn-secondary'>OFF</button>";
				else if (json.d11 == true)	tableFeszerVilagitas.innerHTML = "<button onclick='btnPressed(\"d11\")' class='btn btn-success'>ON</button>";
				if      (json.d12 == false)	tablePadlasVilagitas.innerHTML = "<button onclick='btnPressed(\"d12\")' class='btn btn-secondary'>OFF</button>";
				else if (json.d12 == true)	tablePadlasVilagitas.innerHTML = "<button onclick='btnPressed(\"d12\")' class='btn btn-success'>ON</button>";
				if      (json.d14 == false) cellSpajz.innerHTML = "<button onclick='btnPressed(\"d14\")' class='btn-secondary'>OFF</button>";
        else if (json.d14 == true)  cellSpajz.innerHTML = "<button onclick='btnPressed(\"d14\")' class='btn-success'>ON</button>";
				if      (json.n10 == false)	tablePostalada.innerHTML = "<button class='btn btn-success disabled'>EMPTY</button>";
				else if (json.n10 == true)	tablePostalada.innerHTML = "<button onclick='btnPressed(\"n10\")' class='btn btn-warning'>CHECK</button>";
				/* Nem használt kimenetek
				if      (json.d13 == false)	
				else if (json.d13 == true)	
				if      (json.d15 == false)	
				else if (json.d15 == true)	
				if      (json.d16 == false)	
				else if (json.d16 == true)	
				if      (json.d17 == false)	
				else if (json.d17 == true)	
				if      (json.d18 == false)	
				else if (json.d18 == true)	
				if      (json.d19 == false)	
				else if (json.d19 == true)	
				*/
				if      (json.d20 == false)	cellSzellozo.innerHTML = "<button onclick='btnPressed(\"d20\")' class='btn-secondary bi bi-fan'><svg xmlns=\"http://www.w3.org/2000/svg\" width=\"20\" height=\"20\" fill=\"currentColor\" class=\"bi bi-fan\" viewBox=\"0 0 17 20\">  <path d=\"M10 3c0 1.313-.304 2.508-.8 3.4a1.991 1.991 0 0 0-1.484-.38c-.28-.982-.91-2.04-1.838-2.969a8.368 8.368 0 0 0-.491-.454A5.976 5.976 0 0 1 8 2c.691 0 1.355.117 1.973.332.018.219.027.442.027.668Zm0 5c0 .073-.004.146-.012.217 1.018-.019 2.2-.353 3.331-1.006a8.39 8.39 0 0 0 .57-.361 6.004 6.004 0 0 0-2.53-3.823 9.02 9.02 0 0 1-.145.64c-.34 1.269-.944 2.346-1.656 3.079.277.343.442.78.442 1.254Zm-.137.728a2.007 2.007 0 0 1-1.07 1.109c.525.87 1.405 1.725 2.535 2.377.2.116.402.222.605.317a5.986 5.986 0 0 0 2.053-4.111c-.208.073-.421.14-.641.199-1.264.339-2.493.356-3.482.11ZM8 10c-.45 0-.866-.149-1.2-.4-.494.89-.796 2.082-.796 3.391 0 .23.01.457.027.678A5.99 5.99 0 0 0 8 14c.94 0 1.83-.216 2.623-.602a8.359 8.359 0 0 1-.497-.458c-.925-.926-1.555-1.981-1.836-2.96-.094.013-.191.02-.29.02ZM6 8c0-.08.005-.16.014-.239-1.02.017-2.205.351-3.34 1.007a8.366 8.366 0 0 0-.568.359 6.003 6.003 0 0 0 2.525 3.839 8.37 8.37 0 0 1 .148-.653c.34-1.267.94-2.342 1.65-3.075A1.988 1.988 0 0 1 6 8Zm-3.347-.632c1.267-.34 2.498-.355 3.488-.107.196-.494.583-.89 1.07-1.1-.524-.874-1.406-1.733-2.541-2.388a8.363 8.363 0 0 0-.594-.312 5.987 5.987 0 0 0-2.06 4.106c.206-.074.418-.14.637-.199ZM8 9a1 1 0 1 0 0-2 1 1 0 0 0 0 2Z\"/>  <path d=\"M8 15A7 7 0 1 1 8 1a7 7 0 0 1 0 14Zm0 1A8 8 0 1 0 8 0a8 8 0 0 0 0 16Z\"/></svg></button>";
				else if (json.d20 == true)	cellSzellozo.innerHTML = "<button onclick='btnPressed(\"d20\")' class='btn-success bi bi-fan'><svg xmlns=\"http://www.w3.org/2000/svg\" width=\"20\" height=\"20\" fill=\"currentColor\" class=\"bi bi-fan\" viewBox=\"0 0 17 20\">  <path d=\"M10 3c0 1.313-.304 2.508-.8 3.4a1.991 1.991 0 0 0-1.484-.38c-.28-.982-.91-2.04-1.838-2.969a8.368 8.368 0 0 0-.491-.454A5.976 5.976 0 0 1 8 2c.691 0 1.355.117 1.973.332.018.219.027.442.027.668Zm0 5c0 .073-.004.146-.012.217 1.018-.019 2.2-.353 3.331-1.006a8.39 8.39 0 0 0 .57-.361 6.004 6.004 0 0 0-2.53-3.823 9.02 9.02 0 0 1-.145.64c-.34 1.269-.944 2.346-1.656 3.079.277.343.442.78.442 1.254Zm-.137.728a2.007 2.007 0 0 1-1.07 1.109c.525.87 1.405 1.725 2.535 2.377.2.116.402.222.605.317a5.986 5.986 0 0 0 2.053-4.111c-.208.073-.421.14-.641.199-1.264.339-2.493.356-3.482.11ZM8 10c-.45 0-.866-.149-1.2-.4-.494.89-.796 2.082-.796 3.391 0 .23.01.457.027.678A5.99 5.99 0 0 0 8 14c.94 0 1.83-.216 2.623-.602a8.359 8.359 0 0 1-.497-.458c-.925-.926-1.555-1.981-1.836-2.96-.094.013-.191.02-.29.02ZM6 8c0-.08.005-.16.014-.239-1.02.017-2.205.351-3.34 1.007a8.366 8.366 0 0 0-.568.359 6.003 6.003 0 0 0 2.525 3.839 8.37 8.37 0 0 1 .148-.653c.34-1.267.94-2.342 1.65-3.075A1.988 1.988 0 0 1 6 8Zm-3.347-.632c1.267-.34 2.498-.355 3.488-.107.196-.494.583-.89 1.07-1.1-.524-.874-1.406-1.733-2.541-2.388a8.363 8.363 0 0 0-.594-.312 5.987 5.987 0 0 0-2.06 4.106c.206-.074.418-.14.637-.199ZM8 9a1 1 0 1 0 0-2 1 1 0 0 0 0 2Z\"/>  <path d=\"M8 15A7 7 0 1 1 8 1a7 7 0 0 1 0 14Zm0 1A8 8 0 1 0 8 0a8 8 0 0 0 0 16Z\"/></svg></button>";
				/*
				if      (json.d21 == false)	
				else if (json.d21 == true)	
				if      (json.d22 == false)	
				else if (json.d22 == true)	
				*/
				// Ablakok
				if      (json.n01 == false)	cellAblakFurdo.style.backgroundColor = "lightgreen";
				else if (json.n01 == true)	cellAblakFurdo.style.backgroundColor = "red";
				if      (json.n02 == false)	cellAblakSpajz.style.backgroundColor = "lightgreen";
				else if (json.n02 == true)	cellAblakSpajz.style.backgroundColor = "red";
				if      (json.n03 == false)	cellAblakHalo.style.backgroundColor = "lightgreen";
				else if (json.n03 == true)	cellAblakHalo.style.backgroundColor = "red";
				if      (json.n04 == false)	cellAblakNappali.style.backgroundColor = "lightgreen";
				else if (json.n04 == true)	cellAblakNappali.style.backgroundColor = "red";
				if      (json.n05 == false)	cellAblakFolyoso1.style.backgroundColor = "lightgreen";
				else if (json.n05 == true)	cellAblakFolyoso1.style.backgroundColor = "red";
				if      (json.n06 == false)	cellAblakFolyoso2.style.backgroundColor = "lightgreen";
				else if (json.n06 == true)	cellAblakFolyoso2.style.backgroundColor = "red";
				if      (json.n11 == false) cellAblakFolyoso3.style.backgroundColor = "lightgreen";
        else if (json.n11 == true)  cellAblakFolyoso3.style.backgroundColor = "red";
				if      (json.n07 == false)	cellAblakMuhely.style.backgroundColor = "lightgreen";
				else if (json.n07 == true)	cellAblakMuhely.style.backgroundColor = "red";        
				// Ajtók
				if      (json.n08 == false)	cellAjtoBejarat.style.backgroundColor = "lightgreen";
				else if (json.n08 == true)	cellAjtoBejarat.style.backgroundColor = "red";
				if      (json.n09 == false)	cellAjtoMuhely.style.backgroundColor = "lightgreen";
				else if (json.n09 == true)	cellAjtoMuhely.style.backgroundColor = "red";
			}
		};
		
		xhttp.open("GET", "getStates", true);
		xhttp.send();
	}
	
	function btnPressed(_btn)
	{	
		var xhttp = new XMLHttpRequest();
		
		xhttp.onreadystatechange = function()
		{
			if (this.readyState == 4 && this.status == 200)
			{
				console.log(this.responseText);
			}
		};
		xhttp.open("GET", "btnPressed?btn=" + _btn, true);
		xhttp.send();
	}
	
</script>
</body>
</html>
)=====";
