<?php

    // configuration
    require("../includes/config.php");

    // if form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $data = lookup($_POST["stock"]);
        if ($data === false)
        {
            apologize("Lookup unsuccessful. Please re-enter symbol.");
        }        
        else
        {
            $symbol = $data[0];
            $name = $data[1];
            $price = number_format($data[2], 2);
            render("quote_display.php", ["title" => $symbol, "symbol" => $symbol, "name" +> $name, "price" => $price]);
        }                    
    }
    else
    {
        // else render form
        render("quote_form.php", ["title" => "Register"]);
    }

?>
