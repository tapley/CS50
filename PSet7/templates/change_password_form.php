<div>
    <tr>
        <td><a href = "/"> Portfolio</a></td>
        <td><a href = "/buy.php"> Buy</a></td>
        <td><a href = "/sell.php"> Sell</a></td>  
        <td><a href = "/history.php"> History</a></td>     
    </tr>
</div>

<form action="change_password.php" method="post">
    <fieldset>
        <div class="form-group">
            <input class="form-control" name="current_password" placeholder="Current Password" type="password"/>
        </div>
        <div class="form-group">
            <input class="form-control" name="new_password_original" placeholder="New Password" type="password"/>
        </div> 
        <div class="form-group">
            <input class="form-control" name="new_password_confirm" placeholder="Confirm New Password" type="password"/>
        </div>       
        <div class="form-group">
            <button type="submit" class="btn btn-default">Update Password</button>
        </div>
    </fieldset>
</form>

<div>
    <a href="logout.php">Log Out</a>
</div>
