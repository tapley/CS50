<div>
    <tr>
        <td><a href = "/"> Portfolio</a></td>
        <td><a href = "/buy.php"> Buy</a></td>
        <td><a href = "/sell.php"> Sell</a></td>  
        <td><a href = "/history.php"> History</a></td>     
    </tr>
</div>

<div>
    <?php foreach ($positions as $position): ?>

    <tr>
        <td><?= $position["name"] ?></td>
        <td><?= $position["symbol"] ?></td>
        <td><?= $position["shares"] ?></td>
        <td><?="$" . $position["price"] ?></td>
        <td><?="$" . $position["position_value"] ?></td>
    </tr>
    </br>

    <?php endforeach ?>    
</div>
<div>
    <?php    
    print("Remaining cash: $" . $portfolio_cash);       
    ?>
</div>
<div>
    <tr>
        <td><a href="logout.php">Log Out</a></td>
        <td><a href="change_password.php">Change Password</a></td>
    </tr>
</div>
