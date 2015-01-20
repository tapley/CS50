<div>
    <tr>
        <td><a href = "/"> Portfolio</a></td>
        <td><a href = "/buy.php"> Buy</a></td>
        <td><a href = "/sell.php"> Sell</a></td>  
        <td><a href = "/history.php"> History</a></td>     
    </tr>
</div>

<form action="sell.php" method="post">
    <fieldset>
        <div class="form-group">
            <input autofocus class="form-control" name="sell_symbol" placeholder="Ex: GOOG" type="text"/>
        </div>
        <div class="form-group">
            <input autofocus class="form-control" name="sell_shares" placeholder="Ex: 1000" type="text"/>
        </div> 
        <div class="form-group">
            <button type="submit" class="btn btn-default">Sell</button>
        </div>
    </fieldset>
</form>
<div>
    or <a href="register.php">register</a> for an account
</div>
