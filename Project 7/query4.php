<?php
/*ASSIGNMENT 10
NAME: SAHITHI KAMIREDDY
SECTION 2: DUE DATE: MONDAY, NOVEMBER 20 COURSE : CSCI 566
--------------------------HOW TO USE THE PAGE-----------------------------
1. FIRST GO TO THE GIVEN URL PAGE http://http://students.cs.niu.edu/~z1831177/query4.php
2. IN THIS PAGE  WE HAVE DROP DOWN BUTTON TO ACQUIRE HORSE DETAILS
3. AFTER CHOOSING THE NAME IF YOU CHOOSE ANY HORSE NAME THEN BY CLICKING GET DETAILS WE GET DETAILS OF THE REQUIRED HORSE
 */
?>

<!DOCTYPE html>
<html>
<head>
<title>Assignment - 10</title>
<style>
table {
    font-family: arial, sans-serif;
    border-collapse: collapse;
    width: 100%;
}

td, th {
    border: 1px solid #dddddd;
    text-align: left;
    padding: 8px;
}

tr:nth-child(even) {
    background-color: #dddddd;
}
</style>
</head>
<body>
<?php
require("connection.php");      // establishing database coonection
    $sql = "select name from horse";
    echo "<form method='post' action='query4.php'>";
	echo '<label for="horse">Choose a horse:</label>';
        echo '<select name="horse">';
            foreach($conn->query($sql) as $row)
            {
                echo '<option>';
                echo $row['name'];
                echo '</option>';
            }
        echo '</select>';
        echo '<input type="submit" value="Get details">';  // dropdown button for choosing 
    echo "</form>";
    /****************************************/
    if ($_SERVER['REQUEST_METHOD'] == 'POST')
    {
        $horse = $_POST['horse'];
        $sqlhorse = "select r.name,ri.finish,ri.tm from race r, runsin ri,horse h where h.horse_id=ri.hid and r.race_id = ri.rid and h.name = ?";// query for displaying name finish and time from race runsin and horse tables
	$stmt = $conn->prepare($sqlhorse);
	$stmt->execute(array($horse));
 	$cnt = $stmt->rowCount();
	$row = $stmt->fetchAll(PDO::FETCH_ASSOC);
        echo "<table><tr><th>Race name</th><th>Position</th><th>Time</th></tr>";
	if ($cnt > 0)
        {
            foreach($row as $r)                            // retreiving data from executed query
            {
                echo "<tr><td>".$r['name']."</td><td>".$r['finish']."</td><td>".$r['tm']."</td></tr>";
            }
        }
        else
        {
            echo "There is no race details for $horse.  // this is to display error message
            Please try again.<br>";
        }
	echo "</table>";
    }
    
    
?>
</body>
</html>