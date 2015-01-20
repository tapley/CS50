<?php

    // configuration
    require("../includes/config.php");
    
    $portfolio_cash = query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);

    
    $rows = query("SELECT symbol, shares FROM portfolios WHERE id = ?", $_SESSION["id"]);
    
    $positions = [];
    
    // takes row-by-row output from query and places values for each row into an associative array
    foreach ($rows as $row)
    {
        $stock = lookup($row["symbol"]);
        if ($stock !== false)
        {
            $positions[] = [
                "name" => $stock["name"],
                "price" => $stock["price"],
                "shares" => $row["shares"],
                "symbol" => $row["symbol"],
                "position_value" => ($row["shares"] * $stock["price"])
            ];
        }
    };
    
    // render portfolio
    render("portfolio.php", ["title" => "Portfolio", "positions" => $positions, "portfolio_cash" => number_format($portfolio_cash[0]["cash"], 2)]);
?>
