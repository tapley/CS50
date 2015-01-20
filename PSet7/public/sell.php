<?php

    // configuration
    require("../includes/config.php"); 

    // if form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["sell_symbol"]) || empty($_POST["sell_shares"]))
        {
            apologize("Missing inputs. You must provide a stock and number of shares to sell.");
        
        }
        else if (preg_match("/^\d+$/", $_POST["sell_shares"]) === true)
        {
            apologize("Invalid number of shares. You must provide a positive integer.");          
        }   
        else
        {
            // set variable for formatted stock input
            $sell_symbol_upper = strtoupper ($_POST["sell_symbol"]);
            
            // set variable for stock
            $stock = lookup($sell_symbol_upper);

            //set variable for shares of stock remaining in user's account
            $shares_remaining = query("SELECT shares FROM portfolios WHERE id = ? AND symbol = ?" , $_SESSION["id"], $sell_symbol_upper);
            $shares_remaining = $shares_remaining[0]["shares"]; 
            
            // check stock lookup validity
            if ($stock === false)
            {
                apologize("Invalid symbol. You must provide a valid stock to sell.");          
            }
            // check user's portfolio has enough stocks to complete sale
            else if ($shares_remaining < $_POST["sell_shares"])
            {            
                apologize("Not enough shares in portfolio. Please enter a different amount to sell.");                      
            }                        
            else
            {                                                                                          
                //set cash gained from sale
                $cash_from_sale = $_POST["sell_shares"] * $stock["price"];
                
                query("UPDATE users SET cash = cash + ? WHERE id = ?", $cash_from_sale, $_SESSION["id"]);
                
                query("UPDATE portfolios SET shares = shares - ? WHERE id = ? AND symbol = ?", $_POST["sell_shares"], $_SESSION["id"], $sell_symbol_upper);
                
                // update history
                query("INSERT INTO history (id, action, symbol, shares, price) VALUES(?, ?, ?, ?, ?)",
                     $_SESSION["id"],
                     "Sell",
                     $sell_symbol_upper,
                     $_POST["sell_shares"],
                     $stock["price"]
                 );
                
                // redirect to portfolio
                redirect("/");
            };
        };

    }            
    else
    {
        // else render form
        render("sell_form.php", ["title" => "Sell"]);
    };
             
                
?>
