<html>
<br>
<head>
<link href="site.css" rel="stylesheet">
<div align="center"> <h1>Beaverhawk Base Station</h1> 
</div>
</head>
<?php
if (isset($_POST['Left']))
{
exec("sudo python /home/motor.py");
}
if (isset($_POST['Right']))
{
exec("sudo python /home/motor.py");
}
if (isset($_POST['Up']))
{
exec("sudo python /home/motor.py");
}
if (isset($_POST['Down']))
{
exec("sudo python /home/motor.py");
}
if (isset($_POST['Auto']))
{
exec("sudo python /home/motor.py");
}
if (isset($_POST['Manual']))
{
exec("sudo python /home/motor.py");
}
if (isset($_POST['Take off']))
{
exec("sudo python /home/motor.py");
}
if (isset($_POST['Cut off']))
{
exec("sudo python /home/motor.py");
}
if (isset($_POST['Camera']))
{
exec("sudo python /home/motor.py");
}

?>
<br>

<body>
<div align="center">
<form method="post">
<h3>Manual Mode:</h3> <button id="search" class="btn" name="Left"><h3>Left</h3></button>
<button id="search" class="btn" name="Right"><h3>Right</h3></button>
<button id="search" class="btn" name="Up"><h3>Up</h3></button>
<button id="search" class="btn" name="Down"><h3>Down</h3></button>
<br>
<h3></h3>

<h3>Switch Mode:</h3> <button id="search" class="btn" name="Auto"><h3>Auto Mode</h3></button>
<button id="search" class="btn" name="Manual"><h3>Manual Mode</h3></button>


<h3>Start:</h3> <button id="search" class="btn" name="Take off"><h3>Take off</h3></button>
<button id="search" class="btn" name="Cut off"><h3> Cut off</h3></button>

<h3>Function:</h3> <button id="search" class="btn" name="Camera"><h3>Camera</h3></button>

</form>
<div>
</body>
</html>
