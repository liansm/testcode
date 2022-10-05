<?php

function is_conflict($r, $r_val, $j, $j_val)
{
    if($r_val == $j_val){
        return true;
    }
    if($j -$r == $j_val - $r_val || $j - $r == $r_val - $j_val){
        return true;
    }
    return false;
}


function can_put($row, $value, $cur_queens)
{
    $queen_size = count($cur_queens);
    for($i = 0; $i < $queen_size; ++$i){
        if(is_conflict($row, $value, $i+1,  $cur_queens[$i])){
            return false;
        }
    }
    return true;
}


function print_queens($cur_queens)
{
    $queen_size = count($cur_queens);
    echo "[" . $total_solution . "]";

    for($i = 0; $i < $queen_size; ++$i){
        echo $cur_queens[i] . "\t";
    }
    echo "\n";
}

function backtrace($cur_queens, $max_queen_size)
{
    $queen_size = count($cur_queens);
    for($i = 1; $i <= $max_queen_size; ++$i){
        if(can_put($queen_size +1, $i, $cur_queens)){
            array_push($cur_queens, $i);
        }

        if(count($cur_queens) == $max_queen_size) {
            ++$total_solution;
            print_queens($cur_queens);        
        }
        backtrace($cur_queens, $max_queen_size);
    }

    if(count($cur_queens) != 0){
        array_pop($cur_queens);
    }
}


$max_queen_size = 8;
$total_solution = 0;
$cur_queens = [];

backtrace($cur_queens, $max_queen_size);

echo "total solutions: $total_solution \n";


?>
