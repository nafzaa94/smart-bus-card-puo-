<?php

include "./connect.php";

$name = $_POST["name"];
$email = $_POST["email"];
$phone = $_POST["phone"];
$id_card = $_POST["id_card"];
$destinationFrom = $_POST["destinationFrom"];
$destinationTo = $_POST["destinationTo"];
$status = "No data";

$sql = "INSERT INTO `smart-bus-card`(`Name`, `Email`, `Phone`, `Id_card`, `DestinationFrom`, `DestinationTo`, `Status`) VALUES ('$name','$email','$phone','$id_card','$destinationFrom','$destinationTo','$status')";

if (mysqli_query($conn, $sql)) {
    echo "New record created successfully";
} else {
    echo "Error: " . $sql . "<br>" . mysqli_error($conn);
}

mysqli_close($conn);
