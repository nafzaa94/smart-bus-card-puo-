<?php

$servername = "localhost";
$nameDB = "project_poli";
$username = "root";
$password = "";

$conn = mysqli_connect($servername, $username, $password, $nameDB);

if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}
