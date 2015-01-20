<div>
    <tr>
        <td><a href = "/"> Portfolio</a></td>
        <td><a href = "/buy.php"> Buy</a></td>
        <td><a href = "/sell.php"> Sell</a></td>  
        <td><a href = "/history.php"> History</a></td>     
    </tr>
</div>


<div>
    <?php foreach ($history as $trade): ?>

    <tr>
        <td><?= $trade["action"] ?></td>
        <td><?= $trade["symbol"] ?></td>
        <td><?= $trade["shares"] ?></td>
        <td><?="$" . $trade["price"] ?></td>
        <td><?= $trade["time"] ?></td>
    </tr>
    </br>
    <?php endforeach ?>    
</div>

<div>
    <a href="logout.php">Log Out</a>
</div>
